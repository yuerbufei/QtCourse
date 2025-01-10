#include "medicalview.h"
#include "ui_medicalview.h"
#include "databaseconnection.h"
#include "QMessageBox"

MedicalView::MedicalView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MedicalView)
{
    ui->setupUi(this);

    // 设置 QTableView 的行为
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    // 获取数据库连接实例并初始化患者模型
    DatabaseConnection &databaseConnection = DatabaseConnection::getInstance();
    if (databaseConnection.initMedicationsModel()) {
        ui->tableView->setModel(databaseConnection.medicationsTableModel);
        ui->tableView->setSelectionModel(databaseConnection.medicationsSelectionModel);
    } else {
        QMessageBox::critical(nullptr, "错误", "无法初始化患者模型");
    }
}

MedicalView::~MedicalView()
{
    delete ui;
}

void MedicalView::on_btnDelete_clicked()
{
    DatabaseConnection::getInstance().deleteCurrentMedications();
}


void MedicalView::on_btnFind_clicked()
{
    QString filter = QString("name like '%%1%'").arg(ui->textSearch->text());
    DatabaseConnection::getInstance().searchMedications(filter);
}


void MedicalView::on_btnIncrease_clicked()
{
    int curRow = DatabaseConnection::getInstance().addNewMedication();
    emit goMedicalEditView(curRow);
}


void MedicalView::on_btnModify_clicked()
{
    QModelIndex curIndex = DatabaseConnection::getInstance().medicationsSelectionModel->currentIndex();    // 获取当前选择单元格的模型索引
    emit goMedicalEditView(curIndex.row());
}

