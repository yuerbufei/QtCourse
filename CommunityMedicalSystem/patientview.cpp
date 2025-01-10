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
    QString filter = QString("name like '%%1%'").arg(ui->textSearch->text());
    DatabaseConnection::getInstance().searchPatients(filter);
}


void PatientView::on_btnIncrease_clicked()
{
    int curRow = DatabaseConnection::getInstance().addNewPatient();
    emit goPatientEditView(curRow);
}


void PatientView::on_btnDelete_clicked()
{
    DatabaseConnection::getInstance().deleteCurrentPatients();
}


void PatientView::on_btnModify_clicked()
{
    QModelIndex curIndex = DatabaseConnection::getInstance().patientsSelectionModel->currentIndex();    // 获取当前选择单元格的模型索引
    emit goPatientEditView(curIndex.row());
}

