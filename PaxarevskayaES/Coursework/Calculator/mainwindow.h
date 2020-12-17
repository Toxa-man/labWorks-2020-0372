#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digits(); // цифры чисел
    void on_pushButton_dot_clicked(); // точка
    void operations(); // операции над числом
    void actions(); // действия с числами
    void on_pushButton_discharge_all_clicked(); // стереть все
    void on_pushButton_discharge_clicked(); // стереть цифру/знак
};
#endif // MAINWINDOW_H
