#include "recordview.h"
#include "ui_recordview.h"
#include "databaseconnection.h"
#include "QMessageBox"

RecordView::RecordView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecordView)
{
    ui->setupUi(this);

    // 设置 QTableView 的行为
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    // 获取数据库连接实例并初始化患者模型
    DatabaseConnection &databaseConnection = DatabaseConnection::getInstance();
    if (databaseConnection.initVisitsModel()) {
        ui->tableView->setModel(databaseConnection.visitsTableModel);
        ui->tableView->setSelectionModel(databaseConnection.visitsSelectionModel);
    } else {
        QMessageBox::critical(nullptr, "错误", "无法初始化患者模型");
    }
}

RecordView::~RecordView()
{
    delete ui;
}

void RecordView::on_btnFind_clicked()
{
    QString filter = QString("name like '%%1%'").arg(ui->textSearch->text());
    DatabaseConnection::getInstance().searchVisits(filter);
}


void RecordView::on_btnIncrease_clicked()
{
    int curRow = DatabaseConnection::getInstance().addNewVisit();
    emit goRecordEditView(curRow);
}


void RecordView::on_btnDelete_clicked()
{
    DatabaseConnection::getInstance().deleteCurrentVisits();
}


void RecordView::on_btnModify_clicked()
{
    QModelIndex curIndex = DatabaseConnection::getInstance().visitsSelectionModel->currentIndex();    // 获取当前选择单元格的模型索引
    emit goRecordEditView(curIndex.row());
}

