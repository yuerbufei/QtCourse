#include "patientview.h"
#include "ui_patientview.h"
#include "databaseconnection.h"
#include "QMessageBox"

PatientView::PatientView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PatientView)
{
    ui->setupUi(this);

    // 设置 QTableView 的行为
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    // 获取数据库连接实例并初始化患者模型
    DatabaseConnection &databaseConnection = DatabaseConnection::getInstance();
    if (databaseConnection.initPatientsModel()) {
        ui->tableView->setModel(databaseConnection.patientsTableModel);
        ui->tableView->setSelectionModel(databaseConnection.patientsSelectionModel);
    } else {
        QMessageBox::critical(nullptr, "错误", "无法初始化患者模型");
    }
}

PatientView::~PatientView()
{
    delete ui;
}

void PatientView::on_btnFind_clicked()
{

}


void PatientView::on_btnIncrease_clicked()
{
    emit goPatientEditView();
}


void PatientView::on_btnDelete_clicked()
{

}


void PatientView::on_btnModify_clicked()
{

}

