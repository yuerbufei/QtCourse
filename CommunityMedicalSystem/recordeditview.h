#ifndef RECORDEDITVIEW_H
#define RECORDEDITVIEW_H

#include <QWidget>

namespace Ui {
class RecordEditView;
}

class RecordEditView : public QWidget
{
    Q_OBJECT

public:
    explicit RecordEditView(QWidget *parent = nullptr,int index = 0);
    ~RecordEditView();

private:
    Ui::RecordEditView *ui;
};

#endif // RECORDEDITVIEW_H
