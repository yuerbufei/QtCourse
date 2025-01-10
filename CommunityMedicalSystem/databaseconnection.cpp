#include "databaseconnection.h"
#include <QSqlError>
#include <QDebug>
#include <QUuid>

DatabaseConnection::DatabaseConnection(QObject *parent)
    : QObject(parent), database(QSqlDatabase::addDatabase("QSQLITE"))
    // doctorsTableModel(nullptr), patientsTableModel(nullptr),
    // medicationsTableModel(nullptr), visitsTableModel(nullptr),
    // doctorsSelectionModel(nullptr), patientsSelectionModel(nullptr),
    // medicationsSelectionModel(nullptr), visitsSelectionModel(nullptr)
{
    // 初始化数据库连接
    initDatabase();
}

void DatabaseConnection::initDatabase()
{
    QString dbFilePath = "C:/Program-C++/QtCourse/CommunityMedicalSystem/community_medical_system.db";
    database.setDatabaseName(dbFilePath);

    if (!database.open()) {
        qDebug() << "Failed to open database:" << database.lastError().text();
    } else {
        qDebug() << "Database opened successfully.";
    }
}

QString DatabaseConnection::userLogin(QString username, QString password)
{
    qDebug() << "Attempting login with username:" << username;

    QSqlQuery query(database);

    if (!query.prepare("SELECT username, password FROM doctors WHERE username = :USER")) {
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

bool DatabaseConnection::initDoctorsModel()
{
    // 创建一个新的 QSqlTableModel 对象，并设置数据库
    doctorsTableModel = new QSqlTableModel(this, database);

    // 设置表名为 "doctors"
    doctorsTableModel->setTable("doctors");

    // 设置编辑策略为手动提交
    doctorsTableModel->setEditStrategy(
        QSqlTableModel::OnManualSubmit); // 数据保存方式，OnManualSubmit, OnRowChange

    // 设置排序方式，按 "name" 字段升序排序
    doctorsTableModel->setSort(doctorsTableModel->fieldIndex("name"), Qt::AscendingOrder);

    // 查询数据
    if (!doctorsTableModel->select()) {
        qDebug() << "Failed to select from table:" << doctorsTableModel->lastError().text();
        return false; // 如果查询失败，返回 false
    }

    // 创建一个新的 QItemSelectionModel 对象，并关联到 QSqlTableModel
    doctorsSelectionModel = new QItemSelectionModel(doctorsTableModel, this); // 关联到 doctorsTableModel

    return true;
}

int DatabaseConnection::addNewDoctor()
{
    doctorsTableModel->insertRow(doctorsTableModel->rowCount(),QModelIndex());    // 在末尾添加一条记录
    QModelIndex curIndex = doctorsTableModel->index(doctorsTableModel->rowCount()-1,1);   // 创建最后一行的ModelIndex
    return curIndex.row();
}

bool DatabaseConnection::searchDoctors(QString filter)
{
    doctorsTableModel->setFilter(filter);
    return doctorsTableModel->select();
}

bool DatabaseConnection::deleteCurrentDoctors()
{
    QModelIndex curIndex = doctorsSelectionModel->currentIndex();
    doctorsTableModel->removeRow(curIndex.row()); // 获取当前选择单元格的模型索引
    doctorsTableModel->submitAll();
    doctorsTableModel->select();
}

bool DatabaseConnection::submitDoctorsEdit()
{
    return doctorsTableModel->submitAll();
}

bool DatabaseConnection::revertDoctorsEdit()
{
    doctorsTableModel->revertAll();
}

bool DatabaseConnection::initPatientsModel()
{
    // 创建一个新的 QSqlTableModel 对象，并设置数据库
    patientsTableModel = new QSqlTableModel(this, database);

    // 设置表名为 "patients"
    patientsTableModel->setTable("patients");

    // 设置编辑策略为手动提交
    patientsTableModel->setEditStrategy(
        QSqlTableModel::OnManualSubmit); // 数据保存方式，OnManualSubmit, OnRowChange

    // 设置排序方式，按 "name" 字段升序排序
    patientsTableModel->setSort(patientsTableModel->fieldIndex("name"), Qt::AscendingOrder);

    // 查询数据
    if (!patientsTableModel->select()) {
        qDebug() << "Failed to select from table:" << patientsTableModel->lastError().text();
        return false; // 如果查询失败，返回 false
    }

    // 创建一个新的 QItemSelectionModel 对象，并关联到 QSqlTableModel
    patientsSelectionModel = new QItemSelectionModel(patientsTableModel, this); // 关联到 patientsTableModel

    return true;
}

int DatabaseConnection::addNewPatient()
{
    patientsTableModel->insertRow(patientsTableModel->rowCount(),QModelIndex());    // 在末尾添加一条记录
    QModelIndex curIndex = patientsTableModel->index(patientsTableModel->rowCount()-1,1);   // 创建最后一行的ModelIndex
    return curIndex.row();
}

bool DatabaseConnection::searchPatients(QString filter)
{
    patientsTableModel->setFilter(filter);
    return patientsTableModel->select();
}

bool DatabaseConnection::deleteCurrentPatients()
{
    QModelIndex curIndex = patientsSelectionModel->currentIndex();
    patientsTableModel->removeRow(curIndex.row()); // 获取当前选择单元格的模型索引
    patientsTableModel->submitAll();
    patientsTableModel->select();
}

bool DatabaseConnection::submitPatientsEdit()
{
    return patientsTableModel->submitAll();
}

bool DatabaseConnection::revertPatientsEdit()
{
    patientsTableModel->revertAll();
}


bool DatabaseConnection::initMedicationsModel()
{
    // 创建一个新的 QSqlTableModel 对象，并设置数据库
    medicationsTableModel = new QSqlTableModel(this, database);

    // 设置表名为 "medications"
    medicationsTableModel->setTable("medications");

    // 设置编辑策略为手动提交
    medicationsTableModel->setEditStrategy(
        QSqlTableModel::OnManualSubmit); // 数据保存方式，OnManualSubmit, OnRowChange

    // 设置排序方式，按 "name" 字段升序排序
    medicationsTableModel->setSort(medicationsTableModel->fieldIndex("name"), Qt::AscendingOrder);

    // 查询数据
    if (!medicationsTableModel->select()) {
        qDebug() << "Failed to select from table:" << medicationsTableModel->lastError().text();
        return false; // 如果查询失败，返回 false
    }

    // 创建一个新的 QItemSelectionModel 对象，并关联到 QSqlTableModel
    medicationsSelectionModel = new QItemSelectionModel(medicationsTableModel, this); // 关联到 medicationsTableModel

    return true;
}

int DatabaseConnection::addNewMedication()
{
    medicationsTableModel->insertRow(medicationsTableModel->rowCount(),QModelIndex());    // 在末尾添加一条记录
    QModelIndex curIndex = medicationsTableModel->index(medicationsTableModel->rowCount()-1,1);   // 创建最后一行的ModelIndex
    return curIndex.row();
}

bool DatabaseConnection::searchMedications(QString filter)
{
    medicationsTableModel->setFilter(filter);
    return medicationsTableModel->select();
}

bool DatabaseConnection::deleteCurrentMedications()
{
    QModelIndex curIndex = medicationsSelectionModel->currentIndex();
    medicationsTableModel->removeRow(curIndex.row()); // 获取当前选择单元格的模型索引
    medicationsTableModel->submitAll();
    medicationsTableModel->select();
}

bool DatabaseConnection::submitMedicationsEdit()
{
    return medicationsTableModel->submitAll();
}

bool DatabaseConnection::revertMedicationsEdit()
{
    medicationsTableModel->revertAll();
}

bool DatabaseConnection::initVisitsModel()
{
    // 创建一个新的 QSqlTableModel 对象，并设置数据库
    visitsTableModel = new QSqlTableModel(this, database);

    // 设置表名为 "visits"
    visitsTableModel->setTable("visits");

    // 设置编辑策略为手动提交
    visitsTableModel->setEditStrategy(
        QSqlTableModel::OnManualSubmit); // 数据保存方式，OnManualSubmit, OnRowChange

    // 设置排序方式，按 "visit_date" 字段升序排序
    visitsTableModel->setSort(visitsTableModel->fieldIndex("visit_date"), Qt::AscendingOrder);

    // 查询数据
    if (!visitsTableModel->select()) {
        qDebug() << "Failed to select from table:" << visitsTableModel->lastError().text();
        return false; // 如果查询失败，返回 false
    }

    // 创建一个新的 QItemSelectionModel 对象，并关联到 QSqlTableModel
    visitsSelectionModel = new QItemSelectionModel(visitsTableModel, this); // 关联到 visitsTableModel

    return true;
}

int DatabaseConnection::addNewVisit()
{
    visitsTableModel->insertRow(visitsTableModel->rowCount(),QModelIndex());    // 在末尾添加一条记录
    QModelIndex curIndex = visitsTableModel->index(visitsTableModel->rowCount()-1,1);   // 创建最后一行的ModelIndex
    return curIndex.row();
}

bool DatabaseConnection::searchVisits(QString filter)
{
    visitsTableModel->setFilter(filter);
    return visitsTableModel->select();
}

bool DatabaseConnection::deleteCurrentVisits()
{
    QModelIndex curIndex = visitsSelectionModel->currentIndex();
    visitsTableModel->removeRow(curIndex.row()); // 获取当前选择单元格的模型索引
    visitsTableModel->submitAll();
    visitsTableModel->select();
}

bool DatabaseConnection::submitVisitsEdit()
{
    return visitsTableModel->submitAll();
}

bool DatabaseConnection::revertVisitsEdit()
{
    visitsTableModel->revertAll();
}
