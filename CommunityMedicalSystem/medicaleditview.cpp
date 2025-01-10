#include "medicaleditview.h"
#include "ui_medicaleditview.h"
#include "databaseconnection.h"
#include <QSqlTableModel>

MedicalEditView::MedicalEditView(QWidget *parent,int index)
    : QWidget(parent)
    , ui(new Ui::MedicalEditView)
{
    ui->setupUi(this);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = DatabaseConnection::getInstance().medicationsTableModel;
    dataMapper->setModel(DatabaseConnection::getInstance().medicationsTableModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->drugId,tabModel->fieldIndex("id"));
    dataMapper->addMapping(ui->drugName,tabModel->fieldIndex("name"));
    dataMapper->addMapping(ui->description,tabModel->fieldIndex("description"));
    dataMapper->addMapping(ui->dosage,tabModel->fieldIndex("dosage"));
    dataMapper->addMapping(ui->stockQuantity,tabModel->fieldIndex("stock_quantity"));
    dataMapper->addMapping(ui->threshold,tabModel->fieldIndex("threshold"));

    dataMapper->setCurrentIndex(index);
}

MedicalEditView::~MedicalEditView()
{
    delete ui;
}


void MedicalEditView::on_btnSaveMedicalEdit_clicked()
{
    DatabaseConnection::getInstance().submitMedicationsEdit();
    emit goPreviousView();
}


void MedicalEditView::on_btnCancelMedicalEdit_clicked()
{
    DatabaseConnection::getInstance().revertMedicationsEdit();
    emit goPreviousView();
}
