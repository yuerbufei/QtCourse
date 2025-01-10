#include "recordeditview.h"
#include "ui_recordeditview.h"
#include "databaseconnection.h"
#include <QSqlTableModel>

RecordEditView::RecordEditView(QWidget *parent,int index)
    : QWidget(parent)
    , ui(new Ui::RecordEditView)
{
    ui->setupUi(this);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = DatabaseConnection::getInstance().visitsTableModel;
    dataMapper->setModel(DatabaseConnection::getInstance().visitsTableModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->recordId,tabModel->fieldIndex("id"));
    dataMapper->addMapping(ui->patientId,tabModel->fieldIndex("patient_id"));
    dataMapper->addMapping(ui->doctorId,tabModel->fieldIndex("doctor_id"));
    dataMapper->addMapping(ui->date,tabModel->fieldIndex("visit_date"));
    dataMapper->addMapping(ui->result,tabModel->fieldIndex("diagnosis_result"));
    dataMapper->addMapping(ui->medicines,tabModel->fieldIndex("prescribed_medicines"));

    dataMapper->setCurrentIndex(index);
}

RecordEditView::~RecordEditView()
{
    delete ui;


}

void RecordEditView::on_btnSaveRecordEdit_clicked()
{
    DatabaseConnection::getInstance().submitVisitsEdit();
    emit goPreviousView();
}

void RecordEditView::on_btnCancelRecordEdit_clicked()
{
    DatabaseConnection::getInstance().revertVisitsEdit();
    emit goPreviousView();
}





