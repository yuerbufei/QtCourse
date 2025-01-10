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
    int addNewPatient();
    bool searchDoctors(QString filter);
    bool deleteCurrentDoctors();
    bool submitDoctorsEdit();
    bool revertDoctorsEdit();

    bool initPatientsModel();
    bool searchPatients(QString filter);
    bool deleteCurrentPatients();
    bool submitPatientsEdit();
    bool revertPatientsEdit();

    bool initMedicationsModel();
    bool searchMedications(QString filter);
    bool deleteCurrentMedications();
    bool submitMedicationsEdit();
    bool revertMedicationsEdit();

    bool initVisitsModel();
    bool searchVisits(QString filter);
    bool deleteCurrentVisits();
    bool submitVisitsEdit();
    bool revertVisitsEdit();

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
