#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include <QMainWindow>

#include "loginview.h"
#include "departmentview.h"
#include "doctorview.h"
#include "patienteditview.h"
#include "patientview.h"
#include "welcomeview.h"

namespace Ui {
class MasterView;
}

class MasterView : public QWidget
{
    Q_OBJECT

public:
    explicit MasterView(QWidget *parent = nullptr);
    ~MasterView();

public slots:
    void goLoginView();
    void goWelcomeView();
    void goDoctorView();
    void goDepartmentView();
    void goPatientView();
    void goPatientEditView();
    void goPreviousView();

private slots:
    void on_btnBack_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_btnLogOut_clicked();

private:
    void pushWidgetToStackView(QWidget *widget);

    Ui::MasterView *ui;

    WelcomeView *welcomeView;
    LoginView *loginView;
    DepartmentView *departmentView;
    DoctorView *doctorView;
    PatientEditView *patientEditView;
    PatientView *patientView;
};

#endif // MASTERVIEW_H
