#include "mainwindow.h"
#include "ui_mainwindow.h"

QString number_1, number_2, sign; // для того, чтобы запомнить первое введенное число
double result;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // соединяем нажатие на кнопку с методом
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits()));

    connect(ui->pushButton_plus_minus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_reverse,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_sqrt,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_degree,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_factorial,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(actions()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(actions()));
    connect(ui->pushButton_multiply,SIGNAL(clicked()),this,SLOT(actions()));
    connect(ui->pushButton_divide,SIGNAL(clicked()),this,SLOT(actions()));
    connect(ui->pushButton_ravno,SIGNAL(clicked()),this,SLOT(actions()));
}


MainWindow::~MainWindow()
{
    delete ui;
}


//считываем введенное значение
void MainWindow::digits() {
    QPushButton *button = (QPushButton *)sender(); //возвращает нажатое значение

    // организуем ввод чисел и исключаем возможность ввода нескольких 0 подряд
    QString all_numbers;

    if (ui->last_result->text().contains('=')) {
            ui->result->setText("0");
            ui->last_result->setText("");
    }

    if (!(ui->result->text().toDouble() == 0) || ui->result->text().contains('.')) {
        all_numbers = ui->result->text() + button->text();
        ui->result->setText(all_numbers);
    } else
         ui->result->setText(button->text());
}

// подключаем точку (для чисел с дробной частью)
void MainWindow::on_pushButton_dot_clicked()
{
    if (!(ui->result->text().contains('.'))) { // проверяем, не было ли точки ранее, чтобы исключить ввод нескольких точек в одном числе
         ui->result->setText(ui->result->text() + ".");
    }
}


//смена знака, поиск обратного числа, корня, квадрата числа и факториала
void MainWindow::operations() {
    QPushButton *button = (QPushButton *)sender();

    double number;
    QString new_number;
    number = (ui->result->text().toDouble());
    if (button == ui->pushButton_plus_minus) {
        number *= -1; // меняем знак текущему
        new_number = QString::number(number);

    } else if (button == ui->pushButton_reverse) {
        if (number != 0) {
            number = 1/number ; // находим обратное
            new_number = QString::number(number);
        } else
            new_number = "Error";

    } else if (button == ui->pushButton_sqrt) {
        if (number > 0) {
            number = sqrt(number) ; // ищем корень
            new_number = QString::number(number);
        } else
            new_number = "Error";

    } else if (button == ui->pushButton_degree) {
        number *= number; // возводим в квадрат
        new_number = QString::number(number);

    } else if (button == ui->pushButton_factorial) {
        long int factorial = 1;
        if (number >= 0) {
            for (int i = 1; i <= number; i++) // ищем факториал
                factorial *= i;
            new_number = QString::number(factorial);
        } else
            new_number = "Error";
    } 
    ui->result->setText(new_number); //выводим полученное значение на экран
}


// действия с числами
void MainWindow::actions() {
    QPushButton *button = (QPushButton *)sender();
    QString str_result;

    number_2 = ui->result->text();
    if (ui->result->text().toDouble() != 0) { // исключаем вероятность появления + и - в начале строки
        if (sign != 0) { // если в строке уже есть знак
            if (sign == '+')
                result = number_1.toDouble(NULL) + number_2.toDouble(NULL);
            else if (sign == '-')
                result = number_1.toDouble(NULL) - number_2.toDouble(NULL);
            else if (sign == '*')
                result = number_1.toDouble(NULL) * number_2.toDouble(NULL);
            else if (sign == '/') {
                if (number_2 != 0) {
                    result = number_1.toDouble(NULL) / number_2.toDouble(NULL);
                } else
                    ui->result->setText("Error");
            }

            if (button->text() == "=") {
                str_result = QString::number(result, 'g', 15);
                ui->result->setText(str_result);
                ui->last_result->setText(number_1 + sign + number_2 + "=");
                result = 0;
                number_1 = QString();
                number_2 = QString();
                sign = QString();
            } else {
                number_1 = QString::number(result);
                number_2 = QString();
                result = 0;
                sign = button->text();
                ui->last_result->setText(number_1 + sign);
                ui->result->setText("");
            }
        }
        else {
            sign = button->text();
            number_1 = number_2;
            number_2 = QString();
            ui->last_result->setText(number_1 + sign);
            ui->result->setText("");
        }
    }
}


void MainWindow::on_pushButton_discharge_all_clicked()
{

    ui->result->setText(0);
    ui->last_result->setText(0);

    ui->result->setText("0");

    result = 0;
    number_1 = QString();
    number_2 = QString();
    sign = QString();
}


void MainWindow::on_pushButton_discharge_clicked()
{

    QString number_for_del_1, number_for_del_2;
    number_for_del_1 = ui->result->text();
    number_for_del_2 = ui->last_result->text();

    if (ui->result->text().toDouble() < 10)
        ui->result->setText("0");
    else {
        number_for_del_1.chop(1);
        ui->result->setText(number_for_del_1);
    }
}

