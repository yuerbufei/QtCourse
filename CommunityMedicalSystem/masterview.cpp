#include "masterview.h"
#include "ui_masterview.h"
#include <QDebug>
#include "databaseconnection.h"

MasterView::MasterView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MasterView)
{
    ui->setupUi(this);

    // this->setWindowFlag(Qt::FramelessWindowHint);

    goLoginView();

    DatabaseConnection::getInstance();
}

MasterView::~MasterView()
{
    delete ui;
}

void MasterView::goLoginView()
{
    qDebug() << "goLoginView";
    loginView = new LoginView(this);
    pushWidgetToStackView(loginView);

    connect(loginView,SIGNAL(loginSuccess()),this,SLOT(goWelcomeView()));
}

void MasterView::goWelcomeView()
{
    qDebug() << "goWelcomeView";
    welcomeView = new WelcomeView(this);
    pushWidgetToStackView(welcomeView);

    // 当 welcomeView 对象发出 goDoctorView 信号时，MasterView 对象中的 goDoctorView 槽函数将被调用
    connect(welcomeView,SIGNAL(goDoctorView()),this,SLOT(goDoctorView()));
    connect(welcomeView,SIGNAL(goPatientView()),this,SLOT(goPatientView()));
    connect(welcomeView,SIGNAL(goMedicalView()),this,SLOT(goMedicalView()));
    connect(welcomeView,SIGNAL(goRecordView()),this,SLOT(goRecordView()));
    // connect(welcomeView,SIGNAL(goDepartmentView()),this,SLOT(goDepartmentView()));
}

void MasterView::goDoctorView()
{
    qDebug() << "goDoctorView";
    doctorView = new DoctorView(this);
    pushWidgetToStackView(doctorView);
}

void MasterView::goMedicalView()
{
    qDebug() << "goMedicalView";
    medicalView = new MedicalView(this);
    pushWidgetToStackView(medicalView);

    connect(medicalView,SIGNAL(goMedicalEditView()),this,SLOT(goMedicalView()));
}

void MasterView::goMedicalEditView()
{
    qDebug() << "goMedicalEditView";
    medicalEditView = new MedicalEditView(this);
    pushWidgetToStackView(medicalEditView);
}

void MasterView::goRecordView()
{
    qDebug() << "goRecordView";
    recordView = new RecordView(this);
    pushWidgetToStackView(recordView);

    connect(recordView,SIGNAL(goRecordEditView()),this,SLOT(goRecordView()));
}

void MasterView::goRecordEditView()
{
    qDebug() << "goRecordEditView";
    recordEditView = new RecordEditView(this);
    pushWidgetToStackView(recordEditView);
}

// void MasterView::goDepartmentView()
// {
//     qDebug() << "goDepartmentView";
//     departmentView = new DepartmentView(this);
//     pushWidgetToStackView(departmentView);
// }

void MasterView::goPatientView()
{
    qDebug() << "goPatientView";
    patientView = new PatientView(this);
    pushWidgetToStackView(patientView);

    connect(patientView,SIGNAL(goPatientEditView()),this,SLOT(goPatientView()));
}

void MasterView::goPatientEditView()
{
    qDebug() << "goPatientEditView";
    patientEditView = new PatientEditView(this);
    pushWidgetToStackView(patientEditView);
}

void MasterView::goPreviousView()
{
    int count = ui->stackedWidget->count();

    if (count > 1) {
        // 获取当前显示的视图
        QWidget *currentWidget = ui->stackedWidget->currentWidget();

        // 检查当前视图是否为空
        if (currentWidget) {
            // 切换到前一个视图
            ui->stackedWidget->setCurrentIndex(count - 2);
            ui->labelTitle->setText(ui->stackedWidget->currentWidget()->windowTitle());

            // 移除当前视图
            ui->stackedWidget->removeWidget(currentWidget);
            currentWidget->deleteLater(); // 使用 deleteLater 以避免潜在的崩溃
        }
    }
}

void MasterView::pushWidgetToStackView(QWidget *widget)
{
    ui->stackedWidget->addWidget(widget);
    int count = ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(count-1); // 总是显示最新加入的View
    ui->labelTitle->setText(widget->windowTitle());
}

void MasterView::on_stackedWidget_currentChanged(int arg1)
{
    int count = ui->stackedWidget->count();

    if(count>1)
        ui->btnBack->setEnabled(true);
    else
        ui->btnBack->setEnabled(false);

    QString title = ui->stackedWidget->currentWidget()->windowTitle();

    if(title == "欢迎"){
        ui->btnLogOut->setEnabled(true);
        ui->btnBack->setEnabled(false);
    }else
        ui->btnLogOut->setEnabled(false);
}

void MasterView::on_btnBack_clicked()
{
    goPreviousView();
}
void MasterView::on_btnLogOut_clicked()
{
    goPreviousView();
}

