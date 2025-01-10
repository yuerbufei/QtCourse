#include "medicalview.h"
#include "ui_medicalview.h"
#include "databaseconnection.h"
#include "QMessageBox"

MedicalView::MedicalView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MedicalView)
{
    ui->setupUi(this);
}

MedicalView::~MedicalView()
{
    delete ui;
}

void MedicalView::on_btnDelete_clicked()
{

}


void MedicalView::on_btnFind_clicked()
{

}


void MedicalView::on_btnIncrease_clicked()
{
    emit goMedicalEditView();
}


void MedicalView::on_btnModify_clicked()
{

}

