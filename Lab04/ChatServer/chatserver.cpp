#include "chatserver.h"
#include "serverworker.h"
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

ChatServer::ChatServer(QObject *parent):
    QTcpServer(parent)
{

}

void ChatServer::incomingConnection(qintptr socketDescriptor)
{
    ServerWorker *worker = new ServerWorker(this);
    if(!worker->setSocketDescriptor(socketDescriptor)){
        worker->deleteLater();
        return;
    }

    connect(worker,&ServerWorker::logMessage,this,&ChatServer::logMessage);
    connect(worker,&ServerWorker::jsonReceived,this,&ChatServer::jsonReceived);
    connect(worker,&ServerWorker::disconnectedFromClient,this,std::bind(&ChatServer::userDisconnected,this,worker));

    m_clients.append(worker);
    emit logMessage("新的用户连接上了");
}

void ChatServer::broadcast(const QJsonObject &message, ServerWorker *exclude)
{
    for (ServerWorker *worker : m_clients) {
        if (worker != exclude) {  // 排除特定的客户端
            qDebug() << "Sending to" << worker->userName() << ":" << message;  // 添加日志以调试
            worker->sendJson(message);
        }
    }
}

void ChatServer::stopServer()
{
    close();
}

void ChatServer::jsonReceived(ServerWorker *sender, const QJsonObject &docObj)
{
    const QJsonValue typeVal = docObj.value("type");
    if (typeVal.isNull() || !typeVal.isString())
        return;

    if (typeVal.toString().compare("message", Qt::CaseInsensitive) == 0) {
        const QJsonValue textVal = docObj.value("text");
        if (textVal.isNull() || !textVal.isString())
            return;

        const QString text = textVal.toString().trimmed();
        if (text.isEmpty())
            return;

        QJsonObject message;
        message["type"] = "message";
        message["text"] = text;
        message["sender"] = sender->userName();  // 确保这里正确设置了 sender

        qDebug() << "Broadcasting message:" << message;  // 添加日志以调试
        broadcast(message, sender);  // 广播消息，排除发送者
    }
    else if (typeVal.toString().compare("login", Qt::CaseInsensitive) == 0) {
        const QJsonValue usernameVal = docObj.value("username");
        if (usernameVal.isNull() || !usernameVal.isString())
            return;

        sender->setUserName(usernameVal.toString());  // 确保这里正确设置了用户名
        qDebug() << "User logged in:" << usernameVal.toString();  // 添加日志以调试

        QJsonObject connectedMessage;
        connectedMessage["type"] = "newuser";
        connectedMessage["username"] = usernameVal.toString();
        broadcast(connectedMessage, sender);

        // 发送用户列表给新登录的用户
        QJsonObject userListMessage;
        userListMessage["type"] = "userlist";
        QJsonArray userList;

        for (ServerWorker *worker : m_clients) {
            if (worker == sender)
                userList.append(worker->userName() + "*");
            else
                userList.append(worker->userName());
        }

        userListMessage["userlist"] = userList;
        sender->sendJson(userListMessage);
    }
}

void ChatServer::userDisconnected(ServerWorker *sender)
{
    m_clients.removeAll(sender);
    const QString userName = sender->userName();
    if (!userName.isEmpty()) {
        QJsonObject disconnectedMessage;
        disconnectedMessage["type"] = "userdisconnected";
        disconnectedMessage["username"] = userName;
        broadcast(disconnectedMessage, nullptr);
        emit logMessage(userName + " disconnected");
    }
    sender->deleteLater();
}
