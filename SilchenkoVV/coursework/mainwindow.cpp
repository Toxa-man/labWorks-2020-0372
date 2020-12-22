#include "mainwindow.h"
#include "calculator.h"
#include "functions.cpp"
#include "cmath"
#include "QString"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIcon icon = QIcon("calcul.png");
    this->setWindowIcon(icon);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_binaryBtnGroup_buttonClicked(QAbstractButton * button){
    if (ui->label->text() == "error") on_clearButton_clicked();

    if (ui->label->text().contains(".") && ! sqrtPressed && ! reversePressed && ! sqrPressed && ! f){  // converting QString->Double->QString to exclude float value with zero or empty value after dot
        ui->label->setText(QString::number(ui->label->text().toDouble()));
        expression = ui->optLabel->text() + ui->label->text();
    }

    if (resPressed) {
        ui->optLabel->setText(ui->label->text());
        sign = "";
        expression = ui->label->text();
        resPressed = false;
    }

    if (ui->label->text().toDouble() < 0 && ! resPressed) expression = ui->optLabel->text() + "(" + ui->label->text() + ")";

    if (ui->label->text() == "0" && expression == "") expression = "0";

    ui->optLabel->setText(expression + button->text());

    if (sign == "") sum = ui->label->text().toDouble();  // checking that only one value entered before sign
    else if (! f){
        if (! (sqrtPressed || sqrPressed || reversePressed)) {
            if (sign == "÷" && ui->label->text() == "0") {  // checking dividing by zero
                on_clearButton_clicked();
                ui->label->setText("error");
            } else sum = simpleFunctions(sign, sum, ui->label->text().toDouble());
        }
        if (!(ui->label->text() == "error")) ui->label->setText(QString::number(sum));  // setting sum if not error
    }

    // setting to zero all flags except "f" that indicates binaryBitton clicked

    sqrtPressed = false;
    sqrPressed = false;
    reversePressed = false;
    f = true;
}

void MainWindow::on_digitsBtnGroup_buttonClicked(QAbstractButton * button){
    if (resPressed || sqrtPressed || sqrPressed || reversePressed || ui->label->text() == "error") on_clearButton_clicked();

    if (expression == "" || ui->label->text() == "0") ui->label->clear();  // checking that entering value is first
    else  if (f)  {  // checking that binaryButton was clicked
        ui->label->clear();
        sign = ui->optLabel->text()[ui->optLabel->text().length() - 1];
        f = false;
    }

    ui->label->setText(ui->label->text() + button->text());  // adding new digit to label

    expression = ui->optLabel->text() + ui->label->text();  // adding new label number to expression  variable
}

void MainWindow::on_clearButton_clicked(){
    ui->label->clear();
    ui->label->setText("0");
    ui->optLabel->clear();
    sign = "";
    f = false;
    resPressed = false;
    sqrtPressed = false;
    sqrPressed = false;
    reversePressed = false;
    sum = 0;
    expression = "";
}

void MainWindow::on_delLastSymbBtn_clicked(){
    if (ui->label->text() == "error") on_clearButton_clicked();

    if (! resPressed && ! sqrtPressed && ! sqrPressed && ! reversePressed){
        if (ui->label->text() != "0"){
            int lenght = ui->label->text().length();
            QString new_str = "";  // variable with new string
            int i = 0;
            while (i < lenght - 1) {
                new_str += ui->label->text()[i];
                i++;
            }
            if (new_str != "") ui->label->setText(new_str);
            else ui->label->setText("0");  // if full string was deleted
            expression = ui->optLabel->text() + new_str;
        }
    }
}

void MainWindow::on_resultButton_clicked()
{
    bool tempF = false;
    ui->label->setText(QString::number(ui->label->text().toDouble()));  // converting QString->double->QString to exclude

    if (! resPressed && ui->optLabel->text() != "") {  // checking that expression exist

        if (sign == "" && ! sqrtPressed && ! reversePressed && ! sqrPressed && !("0" <= ui->optLabel->text()[ui->optLabel->text().length() - 1] && ui->optLabel->text()[ui->optLabel->text().length() - 1] <= "9")) {  // getting last entered sign if it's not in variable
            sign = ui->optLabel->text()[ui->optLabel->text().length() - 1];
            expression = ui->optLabel->text() + ui->label->text();
        }

        if (ui->label->text().toDouble() < 0) expression = ui->optLabel->text() + "(" + ui->label->text() + ")";  // setting braces for numbers < 0
        ui->optLabel->setText(expression);

        if (! (sqrtPressed || sqrPressed || reversePressed))
            if (sign == "÷" && ui->label->text() == "0") {  // checking for dividing by zero
                on_clearButton_clicked();
                ui->label->setText("error");
            } else sum = simpleFunctions(sign, sum, ui->label->text().toDouble());
        else {
            tempF = true;
        }

        if (!(ui->label->text() == "error")) {
            if (sign == "" && !(sqrtPressed) && !(sqrPressed) && !(reversePressed))  ui->optLabel->setText(ui->optLabel->text() +ui->label->text());

            ui->optLabel->setText(ui->optLabel->text() + "=");
            ui->label->setText(QString::number(sum));
        }
    }
    if (tempF) {
        sqrtPressed = false;
        sqrPressed = false;
        reversePressed = false;
    }
    resPressed = true;
}

void MainWindow::on_negativeButton_clicked()
{
    if (ui->label->text() == "error") on_clearButton_clicked();

    if (f) {
        ui->label->setText("0");
        f = false;
    }  else {
        if (sqrPressed || sqrtPressed || reversePressed) ui->optLabel->clear();

        if (resPressed) {
            double tempRes = sum;
            on_clearButton_clicked();
            resPressed = true;
            sum = -tempRes;
            ui->label->setText(QString::number(sum));
        }
        else ui->label->setText(QString::number(-ui->label->text().toDouble()));

        if (ui->label->text() != "0") expression = ui->optLabel->text() + ui->label->text();
    }
}

void MainWindow::on_floatButton_clicked()
{
    if (resPressed || sqrtPressed || sqrPressed || reversePressed || ui->label->text() == "error") on_clearButton_clicked();

    if (f) {
        if (expression != "") sign = ui->optLabel->text()[ui->optLabel->text().length() - 1];
        ui->label->setText("0");  // checking for binary button clicked
    }

    if (!(ui->label->text().contains("."))) {
        ui->label->setText(ui->label->text() + ".");
        f = false;
        expression += ui->label->text();
    }
}

void MainWindow::on_sqrtButton_clicked()
{
    if (ui->label->text() == "error") on_clearButton_clicked();

    if (resPressed) {
        ui->optLabel->clear();
        sign = "";
        f = false;
        resPressed = false;
        expression = ui->label->text();
    }

    if (sqrtPressed || sqrPressed || reversePressed) {
        double tempRes = ui->label->text().toDouble();
        on_clearButton_clicked();
        ui->label->setText(QString::number(tempRes));
        expression = ui->label->text();
    }

    if (ui->optLabel->text() != "")  // getting sugn if it's not in variable
        if (!("0" <= ui->optLabel->text()[ui->optLabel->text().length() - 1] && ui->optLabel->text()[ui->optLabel->text().length() - 1] <= "9")) {
            sign = ui->optLabel->text()[ui->optLabel->text().length() - 1];
            expression = ui->optLabel->text() + ui->label->text();
        }

    if (!(ui->label->text()[0] == "-")) {  // checking for a negaive number in sqrt
        if (sign == "") sum = sqrt(ui->label->text().toDouble());
        else {
            sign = ui->optLabel->text()[ui->optLabel->text().length() - 1];
            sum = simpleFunctions(sign, sum, sqrt(ui->label->text().toDouble()));
        }

        // setting sqrt sign and braces around number
        if (ui->label->text() == "0" && expression != "0") expression += ui->sqrtButton->text() + "(0)";
        else {
            expression.insert(expression.length() - ui->label->text().length(), ui->sqrtButton->text());
            expression.insert(expression.length() - ui->label->text().length(), "(");
            expression += ")";
        }
        ui->label->setText(QString::number(sqrt(ui->label->text().toDouble())));
        ui->optLabel->setText(expression);
        sqrtPressed = true;
    } else {
        on_clearButton_clicked();
        ui->label->setText("error");  // setting error text if negative number in sqrt
    }
}

void MainWindow::on_sqrButton_clicked()
{
    if (ui->label->text() == "error") on_clearButton_clicked();

    if (resPressed) {
        ui->optLabel->clear();
        sign = "";
        f = false;
        resPressed = false;
        expression = ui->label->text();
    }

    if (sqrPressed || sqrtPressed || reversePressed) {
        double tempRes = ui->label->text().toDouble();
        on_clearButton_clicked();
        ui->label->setText(QString::number(tempRes));
        expression = ui->label->text();
    }

    if (ui->optLabel->text() != "")
        if (!("0" <= ui->optLabel->text()[ui->optLabel->text().length() - 1] && ui->optLabel->text()[ui->optLabel->text().length() - 1] <= "9")) {
            sign = ui->optLabel->text()[ui->optLabel->text().length() - 1];
            expression = ui->optLabel->text() + ui->label->text();
        }

    if (sign == "") sum = pow(ui->label->text().toDouble(), 2);  // checking that only one number entered
    else {  // esle getting last entered sign
        sign = ui->optLabel->text()[ui->optLabel->text().length() - 1];
        sum = simpleFunctions(sign, sum, pow(ui->label->text().toDouble(), 2));
    }

    if (expression == "") expression = "0";  // if nothing entered setting 0 in expression

    expression = ui->optLabel->text() + "sqr(" + ui->label->text();
    expression += ")";
    ui->label->setText(QString::number(pow(ui->label->text().toDouble(), 2)));
    ui->optLabel->setText(expression);
    sqrPressed = true;
}

void MainWindow::on_reverseButton_clicked()
{
    if (ui->label->text() == "error") on_clearButton_clicked();

    if (resPressed) {
        ui->optLabel->clear();
        sign = "";
        f = false;
        resPressed = false;
        expression = ui->label->text();
    }

    if (reversePressed || sqrPressed || sqrtPressed) {
        double tempRes = ui->label->text().toDouble();
        on_clearButton_clicked();
        ui->label->setText(QString::number(tempRes));
        expression = ui->label->text();
    }

        if (ui->label->text() != "0"){  // checking for divide by zero
            if (ui->optLabel->text() != "")
                if (!("0" <= ui->optLabel->text()[ui->optLabel->text().length() - 1] && ui->optLabel->text()[ui->optLabel->text().length() - 1] <= "9")) {
                    sign = ui->optLabel->text()[ui->optLabel->text().length() - 1];
                    expression = ui->optLabel->text() + ui->label->text();
                }

            if (sign == "") sum = 1 / ui->label->text().toDouble();
            else sum = simpleFunctions(sign, sum, 1 / ui->label->text().toDouble());

            expression = ui->optLabel->text() + "1/(" + ui->label->text();
            expression += ")";
            ui->label->setText(QString::number(1 / ui->label->text().toDouble()));
            ui->optLabel->setText(expression);
            reversePressed = true;
        } else {
            on_clearButton_clicked();
            ui->label->setText("error");  // setting error text in label if try divide by zero
    }
}

void MainWindow::on_pushButton_switch_clicked(){  // switch to matrix calculator
    ui->stackedWidget->setCurrentIndex(1);
    this->setMinimumSize(770, 340);
    this->resize(770, 340);
    this->setMaximumSize(770, 340);
}

void MainWindow::on_plus_radioButton_clicked()
{
    if(ui->plus_radioButton->isChecked()) {
        ui->text_action->setText("+");

        int y1 = ui->line1_1->text().toInt()+ui->line2_1->text().toInt();
        ui->line3_1->setText(QString::number(y1));

        int y2 =  ui->line1_2->text().toInt()+ui->line2_2->text().toInt();
        ui->line3_2->setText(QString::number(y2));

        int y3 = ui->line1_3->text().toInt()+ ui->line2_3->text().toInt();
        ui->line3_3->setText(QString::number(y3));

        int y4 = ui->line1_4->text().toInt()+ui->line2_4->text().toInt();
        ui->line3_4->setText(QString::number(y4));

        int y5 = ui->line1_5->text().toInt()+ui->line2_5->text().toInt();
        ui->line3_5->setText(QString::number(y5));

        int y6 = ui->line1_6->text().toInt()+ui->line2_6->text().toInt();
        ui->line3_6->setText(QString::number(y6));

        int y7 = ui->line1_7->text().toInt()+ui->line2_7->text().toInt();
        ui->line3_7->setText(QString::number(y7));

        int y8 = ui->line1_8->text().toInt()+ui->line2_8->text().toInt();
        ui->line3_8->setText(QString::number(y8));

        int y9 = ui->line1_9->text().toInt()+ui->line2_9->text().toInt();
        ui->line3_9->setText(QString::number(y9));
    }
    on_pushButton_clicked();
}

void MainWindow::on_multi_radioButton_clicked()
{
    if(ui->multi_radioButton->isChecked()) {
        ui->text_action->setText("*");
        int c1 = ui->line1_1->text().toInt();
        int c2 = ui->line1_2->text().toInt();
        int c3 = ui->line1_3->text().toInt();
        int c4 = ui->line1_4->text().toInt();
        int c5 = ui->line1_5->text().toInt();
        int c6 = ui->line1_6->text().toInt();
        int c7 = ui->line1_7->text().toInt();
        int c8 = ui->line1_8->text().toInt();
        int c9 = ui->line1_9->text().toInt();

        int q1 = ui->line2_1->text().toInt();
        int q2 = ui->line2_2->text().toInt();
        int q3 = ui->line2_3->text().toInt();
        int q4 = ui->line2_4->text().toInt();
        int q5 = ui->line2_5->text().toInt();
        int q6 = ui->line2_6->text().toInt();
        int q7 = ui->line2_7->text().toInt();
        int q8 = ui->line2_8->text().toInt();
        int q9 = ui->line2_9->text().toInt();

        ui->line3_1->setText(QString::number(c1*q1+c2*q4+c3*q7));
        ui->line3_2->setText(QString::number(c1*q2+c2*q5+c3*q8));
        ui->line3_3->setText(QString::number(c1*q3+c2*q6+c3*q9));
        ui->line3_4->setText(QString::number(c4*q1+c5*q4+c6*q7));
        ui->line3_5->setText(QString::number(c4*q2+c5*q5+c6*q8));
        ui->line3_6->setText(QString::number(c4*q3+c5*q6+c6*q9));
        ui->line3_7->setText(QString::number(c7*q1+c8*q4+c9*q7));
        ui->line3_8->setText(QString::number(c7*q2+c8*q5+c9*q8));
        ui->line3_9->setText(QString::number(c7*q3+c8*q6+c9*q9));
    }
    on_pushButton_clicked();
}

void MainWindow::on_pushButton_clicked()  // calculating det
{
        int deta = ui->line1_1->text().toInt()*ui->line1_5->text().toInt()*ui->line1_9->text().toInt() +
                ui->line1_2->text().toInt()*ui->line1_6->text().toInt()*ui->line1_7->text().toInt() +
                ui->line1_3->text().toInt() * ui->line1_4->text().toInt() * ui->line1_8->text().toInt() -
                ui->line1_7->text().toInt()*ui->line1_5->text().toInt()*ui->line1_3->text().toInt() -
                ui->line1_8->text().toInt()*ui->line1_6->text().toInt()*ui->line1_1->text().toInt() -
                ui->line1_9->text().toInt()*ui->line1_4->text().toInt()*ui->line1_2->text().toInt();

        int detb = ui->line2_1->text().toInt()*ui->line2_5->text().toInt()*ui->line2_9->text().toInt() +
                ui->line2_2->text().toInt()*ui->line2_6->text().toInt()*ui->line2_7->text().toInt() +
                ui->line2_3->text().toInt() * ui->line2_4->text().toInt() * ui->line2_8->text().toInt() -
                ui->line2_7->text().toInt()*ui->line2_5->text().toInt()*ui->line2_3->text().toInt() -
                ui->line2_8->text().toInt()*ui->line2_6->text().toInt()*ui->line2_1->text().toInt() -
                ui->line2_9->text().toInt()*ui->line2_4->text().toInt()*ui->line2_2->text().toInt();

        int detc = ui->line3_1->text().toInt()*ui->line3_5->text().toInt()*ui->line3_9->text().toInt() +
                ui->line3_2->text().toInt()*ui->line3_6->text().toInt()*ui->line3_7->text().toInt() +
                ui->line3_3->text().toInt() * ui->line3_4->text().toInt() * ui->line3_8->text().toInt() -
                ui->line3_7->text().toInt()*ui->line3_5->text().toInt()*ui->line3_3->text().toInt() -
                ui->line3_8->text().toInt()*ui->line3_6->text().toInt()*ui->line3_1->text().toInt() -
                ui->line3_9->text().toInt()*ui->line3_4->text().toInt()*ui->line3_2->text().toInt();

        ui->det_a_label->setText(QString::number(deta));
        ui->det_b_label->setText(QString::number(detb));
        ui->det_c_label->setText(QString::number(detc));
}

void MainWindow::on_pushButton_switchToMain_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
    this->setMinimumSize(287, 530);
    this->resize( 287, 530);
    this->setMaximumSize(16777215, 16777215);
}
