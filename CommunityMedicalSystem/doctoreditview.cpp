#include "doctoreditview.h"
#include "ui_doctoreditview.h"

DoctorEditView::DoctorEditView(QWidget *parent,int index)
    : QWidget(parent)
    , ui(new Ui::DoctorEditView)
{
    ui->setupUi(this);
}

DoctorEditView::~DoctorEditView()
{
    delete ui;
}
