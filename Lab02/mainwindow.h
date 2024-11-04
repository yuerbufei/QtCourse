#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QGraphicsOpacityEffect>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_actionExit_triggered();

    void on_textEdit_textChanged();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionCopy_triggered();
    void on_actionCut_triggered();
    void on_actionPaste_triggered();
    void on_actionFind_triggered();
    void on_actionReplace_triggered();
    void on_actionSelectAll_triggered();

    void on_actionWrap_triggered();

    void on_actionFont_triggered();
    void on_actionFontColor_triggered();
    void on_actionFontBackScenery_triggered();
    void on_actionEditorBackScenery_triggered();
    void openImageFileDialog();

    void on_actionToolBar_triggered();
    void on_actionStatus_triggered();
    void on_actionStatus_visibleChanged();

    void on_actionAbout_triggered();



protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::MainWindow *ui;
    QGraphicsOpacityEffect *opacityEffect;

    QString filePath;
    bool userEditConfirmed();
    void updateStatusBar();

    // 定义一些常量颜色
    static const QColor DefaultBackgroundColor;
    static const QColor LightYellow;
    static const QColor LightGreen;
    static const QColor LightBlue;

    void applyBackgroundColor(const QColor &color, double opacity);
    void setBackgroundImage(const QString &path, double opacity);
    void applyOpacity(double opacity);


    // 状态栏
    bool statusBarVisible;  // 跟踪状态栏是否可见
    QWidget statusBarWidget;  // 状态栏小部件
    QLabel docLabel, cursorLabel;  // 标签
    bool textChanged;  // 标记文本是否有更改

    // 工具栏
    QToolBar *toolBar;

    void setStatusLabel(QLabel &label, const QString &text);
    QWidget* createSeparator();

    // 缩放文本
    void wheelEvent(QWheelEvent *event);
};

#endif // MAINWINDOW_H

