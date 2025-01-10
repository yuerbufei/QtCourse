#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include <QMainWindow>

#include "loginview.h"
// #include "departmentview.h"
#include "doctorview.h"
#include "medicalview.h"
#include "medicaleditview.h"
#include "recordview.h"
#include "recordeditview.h"
#include "patientview.h"
#include "patienteditview.h"
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
    void goMedicalView();
    void goMedicalEditView();
    void goRecordView();
    void goRecordEditView();
    // void goDepartmentView();
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
    // DepartmentView *departmentView;
    DoctorView *doctorView;
    // DoctorEditView *doctorEditView;
    MedicalView *medicalView;
    MedicalEditView *medicalEditView;
    RecordView *recordView;
    RecordEditView *recordEditView;
    PatientEditView *patientEditView;
    PatientView *patientView;
};

#endif // MASTERVIEW_H
