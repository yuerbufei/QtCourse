#include "recordeditview.h"
#include "ui_recordeditview.h"
#include "databaseconnection.h"
#include <QSqlTableModel>

RecordEditView::RecordEditView(QWidget *parent,int index)
    : QWidget(parent)
    , ui(new Ui::RecordEditView)
{
    ui->setupUi(this);
}

RecordEditView::~RecordEditView()
{
    delete ui;
}

void RecordEditView::on_btnSaverecordEdit_clicked()
{
    DatabaseConnection::getInstance().submitRecordsEdit();
    emit goPreviousView();
}

void RecordEditView::on_btnCancelRecordEdit_clicked()
{
    DatabaseConnection::getInstance().revertRecordsEdit();
    emit goPreviousView();
}


