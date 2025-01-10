#include "recordview.h"
#include "ui_recordview.h"

RecordView::RecordView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecordView)
{
    ui->setupUi(this);
}

RecordView::~RecordView()
{
    delete ui;
}

void RecordView::on_btnFind_clicked()
{

}


void RecordView::on_btnIncrease_clicked()
{

}


void RecordView::on_btnDelete_clicked()
{

}


void RecordView::on_btnModify_clicked()
{

}

