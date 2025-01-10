#include "recordeditview.h"
#include "ui_recordeditview.h"

RecordEditView::RecordEditView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecordEditView)
{
    ui->setupUi(this);
}

RecordEditView::~RecordEditView()
{
    delete ui;
}
