#include "patientview.h"
#include "ui_patientview.h"
#include "databaseconnection.h"

PatientView::PatientView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PatientView)
{
    ui->setupUi(this);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    DatabaseConnection &databaseConection = DatabaseConnection::getInstance();
    if (databaseConection.initPatientModel()) {
        ui->tableView->setModel(databaseConection.patientTableModel);
        ui->tableView->setSelectionModel(databaseConection.selectionModel);
    }
}

PatientView::~PatientView()
{
    delete ui;
}

void PatientView::on_btnFind_clicked()
{

}


void PatientView::on_btnIncrease_clicked()
{
    emit goPatientEditview();
}


void PatientView::on_btnDelete_clicked()
{

}


void PatientView::on_btnModify_clicked()
{

}

