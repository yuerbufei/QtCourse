#include "doctorview.h"
#include "ui_doctorview.h"
#include "databaseconnection.h"
#include "QMessageBox"

DoctorView::DoctorView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DoctorView)
{
    ui->setupUi(this);

    // 设置 QTableView 的行为
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    // 获取数据库连接实例并初始化患者模型
    DatabaseConnection &databaseConnection = DatabaseConnection::getInstance();
    if (databaseConnection.initDoctorsModel()) {
        ui->tableView->setModel(databaseConnection.doctorsTableModel);
        ui->tableView->setSelectionModel(databaseConnection.doctorsSelectionModel);
    } else {
        QMessageBox::critical(nullptr, "错误", "无法初始化患者模型");
    }
}

DoctorView::~DoctorView()
{
    delete ui;
}



void DoctorView::on_btnDelete_clicked()
{
    DatabaseConnection::getInstance().deleteCurrentDoctors();
}


void DoctorView::on_btnFind_clicked()
{
    QString filter = QString("name like '%%1%'").arg(ui->textSearch->text());
    DatabaseConnection::getInstance().searchDoctors(filter);
}


void DoctorView::on_btnIncrease_clicked()
{
    int curRow = DatabaseConnection::getInstance().addNewDoctor();
    emit goDoctorEditView(curRow);
}


void DoctorView::on_btnModify_clicked()
{
    QModelIndex curIndex = DatabaseConnection::getInstance().doctorsSelectionModel->currentIndex();    // 获取当前选择单元格的模型索引
    emit goDoctorEditView(curIndex.row());
}

