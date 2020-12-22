#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_digitsBtnGroup_buttonClicked(QAbstractButton * button);

    void on_clearButton_clicked();

    void on_delLastSymbBtn_clicked();

    void on_binaryBtnGroup_buttonClicked(QAbstractButton * button);

    void on_resultButton_clicked();

    void on_negativeButton_clicked();

    void on_floatButton_clicked();

    void on_sqrtButton_clicked();

    void on_sqrButton_clicked();

    void on_reverseButton_clicked();

    void on_pushButton_switch_clicked();

    void on_plus_radioButton_clicked();

    void on_multi_radioButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_switchToMain_clicked();

private:
    Ui::MainWindow *ui;
    QString sign = "";  // variable with sign value
    QString expression = "";  // variable with all actions before clicking on 'resultButton'
    bool f = false;  // flag that indicates any of 'binaryButtons' is clicked
    bool resPressed = false;  // flag that indicates 'resultButton' is clicked
    bool sqrtPressed = false;  // flag that indicates 'sqrtButton' is clicked
    bool sqrPressed = false;  // flag that indicates 'sqrButton' is clicked
    bool reversePressed = false;  // flag that indicates 'reverseButton' is clicked
    double sum = 0;  // sum of all values entered before 'resultButton' is clicked
};
#endif // MAINWINDOW_H
