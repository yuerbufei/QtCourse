#include "medicaleditview.h"
#include "ui_medicaleditview.h"

MedicalEditView::MedicalEditView(QWidget *parent,int index)
    : QWidget(parent)
    , ui(new Ui::MedicalEditView)
{
    ui->setupUi(this);
}

MedicalEditView::~MedicalEditView()
{
    delete ui;
}
