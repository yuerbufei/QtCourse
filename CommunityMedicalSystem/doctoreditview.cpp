#include "doctoreditview.h"
#include "ui_doctoreditview.h"
#include "databaseconnection.h"
#include <QSqlTableModel>

DoctorEditView::DoctorEditView(QWidget *parent,int index)
    : QWidget(parent)
    , ui(new Ui::DoctorEditView)
{
    ui->setupUi(this);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = DatabaseConnection::getInstance().doctorsTableModel;
    dataMapper->setModel(DatabaseConnection::getInstance().doctorsTableModel);
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

DoctorEditView::~DoctorEditView()
{
    delete ui;
}

void DoctorEditView::on_btnCancelDoctorEdit_clicked()
{
    DatabaseConnection::getInstance().submitDoctorsEdit();
    emit goPreviousView();
}


void DoctorEditView::on_btnSaveDoctorEdit_clicked()
{
    DatabaseConnection::getInstance().revertDoctorsEdit();
    emit goPreviousView();
}

