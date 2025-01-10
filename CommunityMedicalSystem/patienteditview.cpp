#include "patienteditview.h"
#include "ui_patienteditview.h"
#include "databaseconnection.h"
#include <QSqlTableModel>

PatientEditView::PatientEditView(QWidget *parent,int index)
    : QWidget(parent)
    , ui(new Ui::PatientEditView)
{
    ui->setupUi(this);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = DatabaseConnection::getInstance().patientsTableModel;
    dataMapper->setModel(DatabaseConnection::getInstance().patientsTableModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->id,tabModel->fieldIndex("id"));
    dataMapper->addMapping(ui->name,tabModel->fieldIndex("name"));
    dataMapper->addMapping(ui->gender,tabModel->fieldIndex("gender"));
    dataMapper->addMapping(ui->age,tabModel->fieldIndex("age"));
    dataMapper->addMapping(ui->phone,tabModel->fieldIndex("phone"));
    dataMapper->addMapping(ui->idCard,tabModel->fieldIndex("id_card"));
    dataMapper->addMapping(ui->height,tabModel->fieldIndex("height"));
    dataMapper->addMapping(ui->weight,tabModel->fieldIndex("weight"));

    dataMapper->setCurrentIndex(index);
}

PatientEditView::~PatientEditView()
{
    delete ui;
}

void PatientEditView::on_btnSave_clicked()
{
    DatabaseConnection::getInstance().submitPatientsEdit();
    emit goPreviousView();
}


void PatientEditView::on_btnCancel_clicked()
{
    DatabaseConnection::getInstance().revertPatientsEdit();
    emit goPreviousView();
}

