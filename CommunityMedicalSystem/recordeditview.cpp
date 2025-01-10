#include "recordeditview.h"
#include "ui_recordeditview.h"

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
