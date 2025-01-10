#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <QDataWidgetMapper>

class DatabaseConnection : public QObject
{
    Q_OBJECT
public:
    static DatabaseConnection &getInstance()
    {
        static DatabaseConnection instance;
        return instance;
    }

    QString userLogin(QString username, QString password);
    bool initDoctorsModel();
    bool initPatientsModel();
    bool initMedicationsModel();
    bool initVisitsModel();

    QSqlTableModel *doctorsTableModel; // 数据模型
    QSqlTableModel *patientsTableModel; // 数据模型
    QSqlTableModel *medicationsTableModel; // 数据模型
    QSqlTableModel *visitsTableModel; // 数据模型

    QItemSelectionModel *doctorsSelectionModel; // 选择模型
    QItemSelectionModel *patientsSelectionModel; // 选择模型
    QItemSelectionModel *medicationsSelectionModel; // 选择模型
    QItemSelectionModel *visitsSelectionModel; // 选择模型

private:
    explicit DatabaseConnection(QObject *parent = nullptr);
    DatabaseConnection(DatabaseConnection const &) = delete;
    void operator=(DatabaseConnection const &) = delete;

    QSqlDatabase database;

    void initDatabase();
};

#endif // DATABASECONNECTION_H
