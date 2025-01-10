#include "databaseconnection.h"
#include <QSqlError>
#include <QDebug>

DatabaseConnection::DatabaseConnection(QObject *parent)
    : QObject(parent), database(QSqlDatabase::addDatabase("QSQLITE"))
{
    // 初始化数据库连接
    initdataBase();
}

void DatabaseConnection::initdataBase()
{
    QString dbFilePath = "C:/Program-C++/QtCourse/Lab03/Lab03.db";
    database.setDatabaseName(dbFilePath);

    if (!database.open()) {
        qDebug() << "Failed to open database:" << database.lastError().text();
    } else {
        qDebug() << "Database opened successfully.";
    }
}

bool DatabaseConnection::initPatientModel()
{
    // 创建一个新的 QSqlTableModel 对象，并设置数据库
    patientTableModel = new QSqlTableModel(this, database);

    // 设置表名为 "patient"
    patientTableModel->setTable("patient");

    // 设置编辑策略为手动提交
    patientTableModel->setEditStrategy(
        QSqlTableModel::OnManualSubmit); // 数据保存方式，OnManualSubmit, OnRowChange

    // 设置排序方式，按 "name" 字段升序排序
    patientTableModel->setSort(patientTableModel->fieldIndex("name"), Qt::AscendingOrder);

    // 查询数据
    if (!patientTableModel->select()) {
        qDebug() << "Failed to select from table:" << patientTableModel->lastError().text();
        return false; // 如果查询失败，返回 false
    }

    // 创建一个新的 QItemSelectionModel 对象，并关联到 QSqlTableModel
    selectionModel = new QItemSelectionModel(patientTableModel, this); // 关联到 patientTableModel

    return true;
}

QString DatabaseConnection::userLogin(QString username, QString password)
{
    qDebug() << "Attempting login with username:" << username;

    QSqlQuery query(database);

    if (!query.prepare("SELECT username, password FROM user WHERE username = :USER")) {
        qDebug() << "Prepare failed:" << query.lastError().text();
        return "query prepare failed";
    }

    query.bindValue(":USER", username);
    qDebug() << "Executing query:" << query.lastQuery();

    if (!query.exec()) {
        qDebug() << "Execution failed:" << query.lastError().text();
        return "query execution failed";
    }

    if (query.first()) {
        QString storedUsername = query.value(0).toString();
        QString storedPassword = query.value(1).toString().trimmed(); // 去除可能存在的多余空格

        qDebug() << "Found user:" << storedUsername;
        qDebug() << "Stored password:" << storedPassword; // 调试用，之后删除
        qDebug() << "Input password:" << password.trimmed(); // 调试用，之后删除

        if (storedPassword == password.trimmed()) { // 同样去除输入密码的多余空格
            qDebug() << "login ok";
            return "loginOK";
        } else {
            qDebug() << "wrong password";
            return "wrong password";
        }
    } else {
        qDebug() << "No such user.";
        return "wrong username";
    }
}
