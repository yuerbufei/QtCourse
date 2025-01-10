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

    QString userLogin(QString username,QString password);

private:
    explicit DatabaseConnection(QObject *parent = nullptr);
    DatabaseConnection(DatabaseConnection const &) = delete;
    void operator=(DatabaseConnection const &) = delete;

    QSqlDatabase database;

    void initdataBase();

signals:

public:
    bool initPatientModel();
    bool searchPatient(QString filter);
    bool deleteCurrentPatient();
    bool submitPatientEdit();
    bool revertPatientEdit();

    QSqlTableModel *patientTableModel; // 数据模型
    QItemSelectionModel *selectionModel; // 选择模型


};

#endif // DATABASECONNECTION_H
