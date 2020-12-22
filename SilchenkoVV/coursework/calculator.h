#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <QtWidgets/QStackedWidget>
#include <QtGui/QIcon>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *layoutWithMainBtns;
    QGridLayout *layoutWithSpecialBtns;
    QGridLayout *gridLayout_centralwidget;
    QGridLayout *gridLayout_scrollArea;
    QGridLayout *layoutWithSwitchBtn;
    QGridLayout *gridLayout_page1;
    QGridLayout *gridLayout_page2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *optLabel;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_switch;
    QPushButton *clearButton;
    QPushButton *delLastSymbBtn;
    QPushButton *reverseButton;
    QPushButton *sqrButton;
    QPushButton *sqrtButton;
    QPushButton *pushButton_div;
    QPushButton *negativeButton;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_mult;
    QPushButton *floatButton;
    QPushButton *resultButton;
    QPushButton *pushButton_0;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QButtonGroup *digitsBtnGroup;
    QButtonGroup *binaryBtnGroup;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QWidget *page2;

    QLineEdit *line1_1;
    QLineEdit *line1_2;
    QLineEdit *line1_3;
    QLineEdit *line1_5;
    QLineEdit *line1_4;
    QLineEdit *line1_6;
    QLineEdit *line1_8;
    QLineEdit *line1_7;
    QLineEdit *line1_9;
    QLineEdit *line2_9;
    QLineEdit *line2_8;
    QLineEdit *line2_2;
    QLineEdit *line2_6;
    QLineEdit *line2_4;
    QLineEdit *line2_7;
    QLineEdit *line2_1;
    QLineEdit *line2_3;
    QLineEdit *line2_5;
    QLineEdit *line3_9;
    QLineEdit *line3_8;
    QLineEdit *line3_2;
    QLineEdit *line3_6;
    QLineEdit *line3_4;
    QLineEdit *line3_7;
    QLineEdit *line3_1;
    QLineEdit *line3_3;
    QLineEdit *line3_5;
    QLabel *text_action;
    QLabel *text_ravno;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *multi_radioButton;
    QRadioButton *plus_radioButton;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *det_b_label;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLabel *det_c_label;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *det_a_label;
    QPushButton *pushButton;
    QPushButton *pushButton_switchToMain;

    void setupUi(QMainWindow *MainWindow)
    {
            if (MainWindow->objectName().isEmpty())
                MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
            MainWindow->resize(287, 530);
            MainWindow->setMinimumSize(QSize(287, 530));
            MainWindow->setStyleSheet(QString::fromUtf8(""));            
            centralwidget = new QWidget(MainWindow);
            centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
            gridLayout_centralwidget = new QGridLayout(centralwidget);
            gridLayout_centralwidget->setObjectName(QString::fromUtf8("gridLayout_centralwidget"));

            /* ///////////////////////////
              ////////////////////////////
              main calculator design
              /////////////////////////////
            /////////////////////////////*/

            stackedWidget = new QStackedWidget(centralwidget);
            stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
            page1 = new QWidget(stackedWidget);
            page1->setObjectName(QString::fromUtf8("page1"));
            page2 = new QWidget(stackedWidget);
            page2->setObjectName(QString::fromUtf8("page2"));
            gridLayout_page1 = new QGridLayout(page1);
            gridLayout_page1->setObjectName(QString::fromUtf8("gridLayout_page1"));
            gridLayout_page1->setContentsMargins(1, 1, 1, 1);

            layoutWithSwitchBtn = new QGridLayout();
            layoutWithSwitchBtn->setSpacing(0);
            layoutWithSwitchBtn->setObjectName(QString::fromUtf8("layoutWithSwitchBtn"));
            layoutWithSwitchBtn->setSizeConstraint(QLayout::SetNoConstraint);
            horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

            layoutWithSwitchBtn->addItem(horizontalSpacer, 0, 1, 1, 1);

            pushButton_switch = new QPushButton(page1);
            pushButton_switch->setObjectName(QString::fromUtf8("pushButton_switch"));
            QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
            sizePolicy.setHorizontalStretch(0);
            sizePolicy.setVerticalStretch(0);
            sizePolicy.setHeightForWidth(pushButton_switch->sizePolicy().hasHeightForWidth());
            pushButton_switch->setSizePolicy(sizePolicy);
            pushButton_switch->setMaximumSize(QSize(239, 59));

            layoutWithSwitchBtn->addWidget(pushButton_switch, 0, 0, 1, 1);

            gridLayout_page1->addLayout(layoutWithSwitchBtn, 0, 0, 1, 1);

            scrollArea = new QScrollArea(page1);
            scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
            scrollArea->setMinimumSize(QSize(261, 81));
            scrollArea->setMaximumHeight(150);
            scrollArea->setLayoutDirection(Qt::RightToLeft);
            scrollArea->setStyleSheet(QString::fromUtf8(""));
            scrollArea->setWidgetResizable(true);
            scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
            scrollAreaWidgetContents = new QWidget();
            scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
            scrollAreaWidgetContents->setGeometry(QRect(0, 0, 267, 107));
            gridLayout_scrollArea = new QGridLayout(scrollAreaWidgetContents);
            gridLayout_scrollArea->setObjectName(QString::fromUtf8("gridLayout_scrollArea"));
            optLabel = new QLabel(scrollAreaWidgetContents);
            optLabel->setObjectName(QString::fromUtf8("optLabel"));
            optLabel->setMaximumHeight(30);
            QFont font;
            font.setFamily(QString::fromUtf8("Microsoft Sans Serif"));
            font.setPointSize(14);
            optLabel->setFont(font);
            optLabel->setStyleSheet(QString::fromUtf8("color: rgb(109, 109, 109);"));
            optLabel->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

            gridLayout_scrollArea->addWidget(optLabel, 0, 0, 1, 1);

            label = new QLabel(scrollAreaWidgetContents);
            label->setObjectName(QString::fromUtf8("label"));
            QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
            sizePolicy1.setHorizontalStretch(0);
            sizePolicy1.setVerticalStretch(0);
            sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
            label->setSizePolicy(sizePolicy1);
            QFont font1;
            font1.setFamily(QString::fromUtf8("Microsoft Sans Serif"));
            font1.setPointSize(28);
            label->setFont(font1);
            label->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

            gridLayout_scrollArea->addWidget(label, 1, 0, 1, 1);

            verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

            gridLayout_scrollArea->addItem(verticalSpacer, 2, 0, 1, 1);

            scrollArea->setWidget(scrollAreaWidgetContents);

            gridLayout_page1->addWidget(scrollArea, 1, 0, 1, 1);

            layoutWithSpecialBtns = new QGridLayout();
            layoutWithSpecialBtns->setSpacing(0);
            layoutWithSpecialBtns->setObjectName(QString::fromUtf8("layoutWithSpecialBtns"));
            layoutWithSpecialBtns->setSizeConstraint(QLayout::SetMinAndMaxSize);
            sqrtButton = new QPushButton(page1);
            sqrtButton->setObjectName(QString::fromUtf8("sqrtButton"));
            sizePolicy.setHeightForWidth(sqrtButton->sizePolicy().hasHeightForWidth());
            sqrtButton->setSizePolicy(sizePolicy);
            sqrtButton->setMinimumSize(QSize(61, 61));
            sqrtButton->setMaximumHeight(90);
            QFont font2;
            font2.setFamily(QString::fromUtf8("Microsoft Sans Serif"));
            font2.setPointSize(17);
            sqrtButton->setFont(font2);
            sqrtButton->setStyleSheet(QString::fromUtf8("QPushButton {background-color: rgb(199, 199, 199);}\n"
                                                                                        "QPushButton:hover {background-color: rgb(181, 172, 222);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(173, 173, 173);}"));

            layoutWithSpecialBtns->addWidget(sqrtButton, 1, 3, 1, 1);

            sqrButton = new QPushButton(page1);
            sqrButton->setObjectName(QString::fromUtf8("sqrButton"));
            sizePolicy.setHeightForWidth(sqrButton->sizePolicy().hasHeightForWidth());
            sqrButton->setSizePolicy(sizePolicy);
            sqrButton->setMinimumSize(QSize(61, 61));
            sqrButton->setMaximumHeight(90);
            sqrButton->setFont(font);
            sqrButton->setStyleSheet(QString::fromUtf8("QPushButton {background-color: rgb(199, 199, 199);}\n"
                                                                                        "QPushButton:hover {background-color: rgb(181, 172, 222);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(173, 173, 173);}"));

            layoutWithSpecialBtns->addWidget(sqrButton, 1, 1, 1, 2);

            clearButton = new QPushButton(page1);
            clearButton->setObjectName(QString::fromUtf8("clearButton"));
            sizePolicy.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
            clearButton->setSizePolicy(sizePolicy);
            clearButton->setMinimumSize(QSize(111, 51));
            clearButton->setMaximumHeight(90);
            QFont font3;
            font3.setFamily(QString::fromUtf8("Microsoft Sans Serif"));
            font3.setPointSize(13);
            clearButton->setFont(font3);
            clearButton->setStyleSheet(QString::fromUtf8("QPushButton {background-color: rgb(199, 199, 199);}\n"
                                                                                        "QPushButton:hover {background-color: rgb(181, 172, 222);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(173, 173, 173);}\n"));

            layoutWithSpecialBtns->addWidget(clearButton, 0, 0, 1, 2);

            reverseButton = new QPushButton(page1);
            reverseButton->setObjectName(QString::fromUtf8("reverseButton"));
            sizePolicy.setHeightForWidth(reverseButton->sizePolicy().hasHeightForWidth());
            reverseButton->setSizePolicy(sizePolicy);
            reverseButton->setMinimumSize(QSize(61, 61));
            reverseButton->setMaximumHeight(90);
            reverseButton->setFont(font);
            reverseButton->setStyleSheet(QString::fromUtf8("QPushButton {background-color: rgb(199, 199, 199);}\n"
                                                                                        "QPushButton:hover {background-color: rgb(181, 172, 222);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(173, 173, 173);}"));

            layoutWithSpecialBtns->addWidget(reverseButton, 1, 0, 1, 1);

            pushButton_div = new QPushButton(page1);
            binaryBtnGroup = new QButtonGroup(MainWindow);
            binaryBtnGroup->setObjectName(QString::fromUtf8("binaryBtnGroup"));
            binaryBtnGroup->addButton(pushButton_div);
            pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
            sizePolicy.setHeightForWidth(pushButton_div->sizePolicy().hasHeightForWidth());
            pushButton_div->setSizePolicy(sizePolicy);
            pushButton_div->setMinimumSize(QSize(61, 61));
            pushButton_div->setMaximumHeight(90);
            QFont font4;
            font4.setFamily(QString::fromUtf8("Microsoft JhengHei UI Light"));
            font4.setPointSize(20);
            pushButton_div->setFont(font4);
            pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {background-color: rgb(199, 199, 199);}\n"
                                                                                        "QPushButton:hover {background-color: rgb(181, 172, 222);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(173, 173, 173);}"));

            layoutWithSpecialBtns->addWidget(pushButton_div, 1, 4, 1, 1);

            delLastSymbBtn = new QPushButton(page1);
            delLastSymbBtn->setObjectName(QString::fromUtf8("delLastSymbBtn"));
            sizePolicy.setHeightForWidth(delLastSymbBtn->sizePolicy().hasHeightForWidth());
            delLastSymbBtn->setSizePolicy(sizePolicy);
            delLastSymbBtn->setMinimumSize(QSize(131, 51));
            delLastSymbBtn->setMaximumHeight(90);
            QFont font5;
            font5.setFamily(QString::fromUtf8("Microsoft Sans Serif"));
            font5.setPointSize(12);
            delLastSymbBtn->setFont(font5);
            delLastSymbBtn->setStyleSheet(QString::fromUtf8("QPushButton {background-color: rgb(199, 199, 199);}\n"
                                                                                        "QPushButton:hover {background-color: rgb(181, 172, 222);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(173, 173, 173);}"));

            layoutWithSpecialBtns->addWidget(delLastSymbBtn, 0, 2, 1, 3);

            gridLayout_page1->addLayout(layoutWithSpecialBtns, 2, 0, 1, 1);

            layoutWithMainBtns = new QGridLayout();
            layoutWithMainBtns->setSpacing(0);
            layoutWithMainBtns->setObjectName(QString::fromUtf8("layoutWithMainBtns"));
            layoutWithMainBtns->setSizeConstraint(QLayout::SetNoConstraint);
            layoutWithMainBtns->setContentsMargins(0, -1, -1, -1);
            negativeButton = new QPushButton(page1);
            negativeButton->setObjectName(QString::fromUtf8("negativeButton"));
            sizePolicy.setHeightForWidth(negativeButton->sizePolicy().hasHeightForWidth());
            negativeButton->setSizePolicy(sizePolicy);
            negativeButton->setMinimumSize(QSize(61, 61));
            QFont font6;
            font6.setFamily(QString::fromUtf8("Microsoft JhengHei Light"));
            font6.setPointSize(14);
            negativeButton->setFont(font6);
            negativeButton->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(237, 228, 239);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(207, 207, 207);}"));

            layoutWithMainBtns->addWidget(negativeButton, 3, 0, 1, 1);

            pushButton_0 = new QPushButton(page1);
            digitsBtnGroup = new QButtonGroup(MainWindow);
            digitsBtnGroup->setObjectName(QString::fromUtf8("digitsBtnGroup"));
            digitsBtnGroup->addButton(pushButton_0);
            pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
            sizePolicy.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
            pushButton_0->setSizePolicy(sizePolicy);
            pushButton_0->setMinimumSize(QSize(61, 61));
            pushButton_0->setFont(font3);
            pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(237, 228, 239);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(207, 207, 207);}"));

            layoutWithMainBtns->addWidget(pushButton_0, 3, 1, 1, 1);

            pushButton_6 = new QPushButton(page1);
            digitsBtnGroup->addButton(pushButton_6);
            pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
            sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
            pushButton_6->setSizePolicy(sizePolicy);
            pushButton_6->setMinimumSize(QSize(61, 61));
            pushButton_6->setFont(font3);
            pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(237, 228, 239);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(207, 207, 207);}"));

            layoutWithMainBtns->addWidget(pushButton_6, 1, 2, 1, 1);

            pushButton_minus = new QPushButton(page1);
            binaryBtnGroup->addButton(pushButton_minus);
            pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
            sizePolicy.setHeightForWidth(pushButton_minus->sizePolicy().hasHeightForWidth());
            pushButton_minus->setSizePolicy(sizePolicy);
            pushButton_minus->setMinimumSize(QSize(61, 61));
            QFont font7;
            font7.setFamily(QString::fromUtf8("Microsoft JhengHei UI Light"));
            font7.setPointSize(17);
            pushButton_minus->setFont(font7);
            pushButton_minus->setStyleSheet(QString::fromUtf8("QPushButton {background-color: rgb(199, 199, 199);}\n"
                                                                                        "QPushButton:hover {background-color: rgb(181, 172, 222);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(173, 173, 173);}"));

            layoutWithMainBtns->addWidget(pushButton_minus, 1, 3, 1, 1);

            pushButton_7 = new QPushButton(page1);
            digitsBtnGroup->addButton(pushButton_7);
            pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
            sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
            pushButton_7->setSizePolicy(sizePolicy);
            pushButton_7->setMinimumSize(QSize(61, 61));
            pushButton_7->setFont(font3);
            pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(237, 228, 239);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(207, 207, 207);}"));

            layoutWithMainBtns->addWidget(pushButton_7, 2, 0, 1, 1);

            pushButton_plus = new QPushButton(page1);
            binaryBtnGroup->addButton(pushButton_plus);
            pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
            sizePolicy.setHeightForWidth(pushButton_plus->sizePolicy().hasHeightForWidth());
            pushButton_plus->setSizePolicy(sizePolicy);
            pushButton_plus->setMinimumSize(QSize(61, 61));
            pushButton_plus->setFont(font7);
            pushButton_plus->setStyleSheet(QString::fromUtf8("QPushButton {background-color: rgb(199, 199, 199);}\n"
                                                                                        "QPushButton:hover {background-color: rgb(181, 172, 222);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(173, 173, 173);}"));

            layoutWithMainBtns->addWidget(pushButton_plus, 2, 3, 1, 1);

            pushButton_3 = new QPushButton(page1);
            digitsBtnGroup->addButton(pushButton_3);
            pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
            sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
            pushButton_3->setSizePolicy(sizePolicy);
            pushButton_3->setMinimumSize(QSize(61, 61));
            pushButton_3->setFont(font3);
            pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(237, 228, 239);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(207, 207, 207);}"));

            layoutWithMainBtns->addWidget(pushButton_3, 0, 2, 1, 1);

            pushButton_8 = new QPushButton(page1);
            digitsBtnGroup->addButton(pushButton_8);
            pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
            sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
            pushButton_8->setSizePolicy(sizePolicy);
            pushButton_8->setMinimumSize(QSize(61, 61));
            pushButton_8->setFont(font3);
            pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(237, 228, 239);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(207, 207, 207);}"));

            layoutWithMainBtns->addWidget(pushButton_8, 2, 1, 1, 1);

            pushButton_5 = new QPushButton(page1);
            digitsBtnGroup->addButton(pushButton_5);
            pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
            sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
            pushButton_5->setSizePolicy(sizePolicy);
            pushButton_5->setMinimumSize(QSize(61, 61));
            pushButton_5->setFont(font3);
            pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(237, 228, 239);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(207, 207, 207);}"));

            layoutWithMainBtns->addWidget(pushButton_5, 1, 1, 1, 1);

            floatButton = new QPushButton(page1);
            floatButton->setObjectName(QString::fromUtf8("floatButton"));
            sizePolicy.setHeightForWidth(floatButton->sizePolicy().hasHeightForWidth());
            floatButton->setSizePolicy(sizePolicy);
            floatButton->setMinimumSize(QSize(61, 61));
            QFont font8;
            font8.setFamily(QString::fromUtf8("Segoe UI Semibold"));
            font8.setPointSize(15);
            floatButton->setFont(font8);
            floatButton->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(237, 228, 239);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(207, 207, 207);}"));

            layoutWithMainBtns->addWidget(floatButton, 3, 2, 1, 1);

            pushButton_mult = new QPushButton(page1);
            binaryBtnGroup->addButton(pushButton_mult);
            pushButton_mult->setObjectName(QString::fromUtf8("pushButton_mult"));
            sizePolicy.setHeightForWidth(pushButton_mult->sizePolicy().hasHeightForWidth());
            pushButton_mult->setSizePolicy(sizePolicy);
            pushButton_mult->setMinimumSize(QSize(61, 61));
            pushButton_mult->setFont(font7);
            pushButton_mult->setStyleSheet(QString::fromUtf8("QPushButton {background-color: rgb(199, 199, 199);}\n"
                                                                                        "QPushButton:hover {background-color: rgb(181, 172, 222);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(173, 173, 173);}"));

            layoutWithMainBtns->addWidget(pushButton_mult, 0, 3, 1, 1);

            pushButton_4 = new QPushButton(page1);
            digitsBtnGroup->addButton(pushButton_4);
            pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
            sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
            pushButton_4->setSizePolicy(sizePolicy);
            pushButton_4->setMinimumSize(QSize(61, 61));
            pushButton_4->setFont(font3);
            pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(237, 228, 239);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(207, 207, 207);}"));

            layoutWithMainBtns->addWidget(pushButton_4, 1, 0, 1, 1);

            pushButton_9 = new QPushButton(page1);
            digitsBtnGroup->addButton(pushButton_9);
            pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
            sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
            pushButton_9->setSizePolicy(sizePolicy);
            pushButton_9->setMinimumSize(QSize(61, 61));
            pushButton_9->setFont(font3);
            pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(237, 228, 239);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(207, 207, 207);}"));

            layoutWithMainBtns->addWidget(pushButton_9, 2, 2, 1, 1);

            resultButton = new QPushButton(page1);
            resultButton->setObjectName(QString::fromUtf8("resultButton"));
            sizePolicy.setHeightForWidth(resultButton->sizePolicy().hasHeightForWidth());
            resultButton->setSizePolicy(sizePolicy);
            resultButton->setMinimumSize(QSize(61, 61));
            resultButton->setFont(font7);
            resultButton->setStyleSheet(QString::fromUtf8("QPushButton {background-color: rgba(255, 106, 196, 180);}\n"
                                                                                        "QPushButton:hover {background-color: rgb(224, 136, 195);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(193, 112, 161);}"));

            layoutWithMainBtns->addWidget(resultButton, 3, 3, 1, 1);

            pushButton_2 = new QPushButton(page1);
            digitsBtnGroup->addButton(pushButton_2);
            pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
            sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
            pushButton_2->setSizePolicy(sizePolicy);
            pushButton_2->setMinimumSize(QSize(61, 61));
            pushButton_2->setFont(font3);
            pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(237, 228, 239);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(207, 207, 207);}"));

            layoutWithMainBtns->addWidget(pushButton_2, 0, 1, 1, 1);

            pushButton_1 = new QPushButton(page1);
            digitsBtnGroup->addButton(pushButton_1);
            pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
            sizePolicy.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
            pushButton_1->setSizePolicy(sizePolicy);
            pushButton_1->setMinimumSize(QSize(61, 61));
            pushButton_1->setFont(font3);
            pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(237, 228, 239);}\n"
                                                                                        "QPushButton:clicked {background-color: rgb(207, 207, 207);}"));

            layoutWithMainBtns->addWidget(pushButton_1, 0, 0, 1, 1);

            gridLayout_page1->addLayout(layoutWithMainBtns, 3, 0, 1, 1);

            stackedWidget->addWidget(page1);

            /* ///////////////////////////
              ///////////////////////////
              matrix calculator design
              /////////////////////////////
            /////////////////////////////*/

            line1_1 = new QLineEdit(page2);
            line1_1->setObjectName(QString::fromUtf8("line1_1"));
            line1_1->setGeometry(QRect(30, 40, 51, 51));
            line1_1->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line1_1->setAlignment(Qt::AlignCenter);
            line1_2 = new QLineEdit(page2);
            line1_2->setObjectName(QString::fromUtf8("line1_2"));
            line1_2->setGeometry(QRect(90, 40, 51, 51));
            line1_2->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line1_2->setAlignment(Qt::AlignCenter);
            line1_3 = new QLineEdit(page2);
            line1_3->setObjectName(QString::fromUtf8("line1_3"));
            line1_3->setGeometry(QRect(150, 40, 51, 51));
            line1_3->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line1_3->setAlignment(Qt::AlignCenter);
            line1_5 = new QLineEdit(page2);
            line1_5->setObjectName(QString::fromUtf8("line1_5"));
            line1_5->setGeometry(QRect(90, 100, 51, 51));
            line1_5->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line1_5->setAlignment(Qt::AlignCenter);
            line1_4 = new QLineEdit(page2);
            line1_4->setObjectName(QString::fromUtf8("line1_4"));
            line1_4->setGeometry(QRect(30, 100, 51, 51));
            line1_4->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line1_4->setAlignment(Qt::AlignCenter);
            line1_6 = new QLineEdit(page2);
            line1_6->setObjectName(QString::fromUtf8("line1_6"));
            line1_6->setGeometry(QRect(150, 100, 51, 51));
            line1_6->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line1_6->setAlignment(Qt::AlignCenter);
            line1_8 = new QLineEdit(page2);
            line1_8->setObjectName(QString::fromUtf8("line1_8"));
            line1_8->setGeometry(QRect(90, 160, 51, 51));
            line1_8->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line1_8->setAlignment(Qt::AlignCenter);
            line1_7 = new QLineEdit(page2);
            line1_7->setObjectName(QString::fromUtf8("line1_7"));
            line1_7->setGeometry(QRect(30, 160, 51, 51));
            line1_7->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line1_7->setAlignment(Qt::AlignCenter);
            line1_9 = new QLineEdit(page2);
            line1_9->setObjectName(QString::fromUtf8("line1_9"));
            line1_9->setGeometry(QRect(150, 160, 51, 51));
            line1_9->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line1_9->setAlignment(Qt::AlignCenter);
            line2_9 = new QLineEdit(page2);
            line2_9->setObjectName(QString::fromUtf8("line2_9"));
            line2_9->setGeometry(QRect(410, 160, 51, 51));
            line2_9->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line2_9->setAlignment(Qt::AlignCenter);
            line2_8 = new QLineEdit(page2);
            line2_8->setObjectName(QString::fromUtf8("line2_8"));
            line2_8->setGeometry(QRect(350, 160, 51, 51));
            line2_8->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line2_8->setAlignment(Qt::AlignCenter);
            line2_2 = new QLineEdit(page2);
            line2_2->setObjectName(QString::fromUtf8("line2_2"));
            line2_2->setGeometry(QRect(350, 40, 51, 51));
            line2_2->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line2_2->setAlignment(Qt::AlignCenter);
            line2_6 = new QLineEdit(page2);
            line2_6->setObjectName(QString::fromUtf8("line2_6"));
            line2_6->setGeometry(QRect(410, 100, 51, 51));
            line2_6->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line2_6->setAlignment(Qt::AlignCenter);
            line2_4 = new QLineEdit(page2);
            line2_4->setObjectName(QString::fromUtf8("line2_4"));
            line2_4->setGeometry(QRect(290, 100, 51, 51));
            line2_4->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line2_4->setAlignment(Qt::AlignCenter);
            line2_7 = new QLineEdit(page2);
            line2_7->setObjectName(QString::fromUtf8("line2_7"));
            line2_7->setGeometry(QRect(290, 160, 51, 51));
            line2_7->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line2_7->setAlignment(Qt::AlignCenter);
            line2_1 = new QLineEdit(page2);
            line2_1->setObjectName(QString::fromUtf8("line2_1"));
            line2_1->setGeometry(QRect(290, 40, 51, 51));
            line2_1->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line2_1->setAlignment(Qt::AlignCenter);
            line2_3 = new QLineEdit(page2);
            line2_3->setObjectName(QString::fromUtf8("line2_3"));
            line2_3->setGeometry(QRect(410, 40, 51, 51));
            line2_3->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line2_3->setAlignment(Qt::AlignCenter);
            line2_5 = new QLineEdit(page2);
            line2_5->setObjectName(QString::fromUtf8("line2_5"));
            line2_5->setGeometry(QRect(350, 100, 51, 51));
            line2_5->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line2_5->setAlignment(Qt::AlignCenter);
            line3_9 = new QLineEdit(page2);
            line3_9->setObjectName(QString::fromUtf8("line3_9"));
            line3_9->setGeometry(QRect(680, 160, 51, 51));
            line3_9->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line3_9->setAlignment(Qt::AlignCenter);
            line3_8 = new QLineEdit(page2);
            line3_8->setObjectName(QString::fromUtf8("line3_8"));
            line3_8->setGeometry(QRect(620, 160, 51, 51));
            line3_8->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line3_8->setAlignment(Qt::AlignCenter);
            line3_2 = new QLineEdit(page2);
            line3_2->setObjectName(QString::fromUtf8("line3_2"));
            line3_2->setGeometry(QRect(620, 40, 51, 51));
            line3_2->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line3_2->setAlignment(Qt::AlignCenter);
            line3_6 = new QLineEdit(page2);
            line3_6->setObjectName(QString::fromUtf8("line3_6"));
            line3_6->setGeometry(QRect(680, 100, 51, 51));
            line3_6->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line3_6->setAlignment(Qt::AlignCenter);
            line3_4 = new QLineEdit(page2);
            line3_4->setObjectName(QString::fromUtf8("line3_4"));
            line3_4->setGeometry(QRect(560, 100, 51, 51));
            line3_4->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line3_4->setAlignment(Qt::AlignCenter);
            line3_7 = new QLineEdit(page2);
            line3_7->setObjectName(QString::fromUtf8("line3_7"));
            line3_7->setGeometry(QRect(560, 160, 51, 51));
            line3_7->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line3_7->setAlignment(Qt::AlignCenter);
            line3_1 = new QLineEdit(page2);
            line3_1->setObjectName(QString::fromUtf8("line3_1"));
            line3_1->setGeometry(QRect(560, 40, 51, 51));
            line3_1->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line3_1->setAlignment(Qt::AlignCenter);
            line3_3 = new QLineEdit(page2);
            line3_3->setObjectName(QString::fromUtf8("line3_3"));
            line3_3->setGeometry(QRect(680, 40, 51, 51));
            line3_3->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line3_3->setAlignment(Qt::AlignCenter);
            line3_5 = new QLineEdit(page2);
            line3_5->setObjectName(QString::fromUtf8("line3_5"));
            line3_5->setGeometry(QRect(620, 100, 51, 51));
            line3_5->setStyleSheet(QString::fromUtf8("text-align: center;\n"
                                                                                    "\n"
                                                                                    "font-size: 25px;"));
            line3_5->setAlignment(Qt::AlignCenter);
            text_action = new QLabel(page2);
            text_action->setObjectName(QString::fromUtf8("text_action"));
            text_action->setGeometry(QRect(220, 110, 47, 31));
            text_action->setStyleSheet(QString::fromUtf8("font-size: 30px;"));
            text_action->setAlignment(Qt::AlignCenter);
            text_ravno = new QLabel(page2);
            text_ravno->setObjectName(QString::fromUtf8("text_ravno"));
            text_ravno->setGeometry(QRect(490, 110, 47, 31));
            text_ravno->setStyleSheet(QString::fromUtf8("font-size: 30px;"));
            text_ravno->setAlignment(Qt::AlignCenter);
            layoutWidget = new QWidget(page2);
            layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
            layoutWidget->setGeometry(QRect(30, 250, 162, 19));
            horizontalLayout = new QHBoxLayout(layoutWidget);
            horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
            horizontalLayout->setContentsMargins(0, 0, 0, 0);
            multi_radioButton = new QRadioButton(layoutWidget);
            multi_radioButton->setObjectName(QString::fromUtf8("multi_radioButton"));

            horizontalLayout->addWidget(multi_radioButton);

            plus_radioButton = new QRadioButton(layoutWidget);
            plus_radioButton->setObjectName(QString::fromUtf8("plus_radioButton"));

            horizontalLayout->addWidget(plus_radioButton);

            label_1 = new QLabel(page2);
            label_1->setObjectName(QString::fromUtf8("label"));
            label_1->setGeometry(QRect(30, 220, 41, 16));
            label_2 = new QLabel(page2);
            label_2->setObjectName(QString::fromUtf8("label_2"));
            label_2->setGeometry(QRect(290, 220, 41, 16));
            label_3 = new QLabel(page2);
            label_3->setObjectName(QString::fromUtf8("label_3"));
            label_3->setGeometry(QRect(560, 220, 41, 16));
            layoutWidget1 = new QWidget(page2);
            layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
            layoutWidget1->setGeometry(QRect(350, 220, 95, 15));
            horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
            horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
            horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
            label_5 = new QLabel(layoutWidget1);
            label_5->setObjectName(QString::fromUtf8("label_5"));

            horizontalLayout_3->addWidget(label_5);

            det_b_label = new QLabel(layoutWidget1);
            det_b_label->setObjectName(QString::fromUtf8("det_b_label"));

            horizontalLayout_3->addWidget(det_b_label);

            layoutWidget_2 = new QWidget(page2);
            layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
            layoutWidget_2->setGeometry(QRect(620, 220, 95, 15));
            horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
            horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
            horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
            label_6 = new QLabel(layoutWidget_2);
            label_6->setObjectName(QString::fromUtf8("label_6"));

            horizontalLayout_4->addWidget(label_6);

            det_c_label = new QLabel(layoutWidget_2);
            det_c_label->setObjectName(QString::fromUtf8("det_c_label"));

            horizontalLayout_4->addWidget(det_c_label);

            layoutWidget2 = new QWidget(page2);
            layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
            layoutWidget2->setGeometry(QRect(90, 220, 95, 15));
            horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
            horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
            horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
            label_4 = new QLabel(layoutWidget2);
            label_4->setObjectName(QString::fromUtf8("label_4"));

            horizontalLayout_2->addWidget(label_4);

            det_a_label = new QLabel(layoutWidget2);
            det_a_label->setObjectName(QString::fromUtf8("det_a_label"));

            horizontalLayout_2->addWidget(det_a_label);

            pushButton = new QPushButton(page2);
            pushButton->setObjectName(QString::fromUtf8("pushButton"));
            pushButton->setGeometry(QRect(200, 250, 75, 23));
            pushButton_switchToMain = new QPushButton(page2);
            pushButton_switchToMain->setObjectName(QString::fromUtf8("pushButton_switchToMain"));
            pushButton_switchToMain->setGeometry(QRect(0, 0, 121, 23));

            line3_1->setReadOnly(true);
            line3_2->setReadOnly(true);
            line3_3->setReadOnly(true);
            line3_4->setReadOnly(true);
            line3_5->setReadOnly(true);
            line3_6->setReadOnly(true);
            line3_7->setReadOnly(true);
            line3_8->setReadOnly(true);
            line3_9->setReadOnly(true);

            stackedWidget->addWidget(page2);

            gridLayout_centralwidget->addWidget(stackedWidget);

            MainWindow->setCentralWidget(centralwidget);

            retranslateUi(MainWindow);

            QMetaObject::connectSlotsByName(MainWindow);
        } // setupUi

        void retranslateUi(QMainWindow *MainWindow)
        {
            MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
            pushButton_switch->setText(QCoreApplication::translate("MainWindow", "Matrix calculator", nullptr));
            optLabel->setText(QString());
            label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
            sqrtButton->setText(QCoreApplication::translate("MainWindow", "\342\210\232", nullptr));
            sqrButton->setText(QCoreApplication::translate("MainWindow", "\360\235\221\245\302\262", nullptr));
            clearButton->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
            reverseButton->setText(QCoreApplication::translate("MainWindow", "\302\271/\360\235\221\245", nullptr));
            pushButton_div->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
            delLastSymbBtn->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
            negativeButton->setText(QCoreApplication::translate("MainWindow", "\302\261", nullptr));
            pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
            pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
            pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
            pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
            pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
            pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
            pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
            pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
            floatButton->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
            pushButton_mult->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
            pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
            pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
            resultButton->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
            pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
            pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
            line1_1->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            line1_2->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            line1_3->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            line1_5->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            line1_4->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            line1_6->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            line1_8->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            line1_7->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            line1_9->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            line2_9->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            line2_8->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            line2_2->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            line2_6->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            line2_4->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            line2_7->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            line2_1->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            line2_3->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            line2_5->setText(QCoreApplication::translate("MatrixWindow", "0", nullptr));
            text_action->setText(QString());
            text_ravno->setText(QCoreApplication::translate("MatrixWindow", "=", nullptr));
            multi_radioButton->setText(QCoreApplication::translate("MatrixWindow", "Multiplication", nullptr));
            plus_radioButton->setText(QCoreApplication::translate("MatrixWindow", "Addition", nullptr));
            label_1->setText(QCoreApplication::translate("MatrixWindow", "Matrix A", nullptr));
            label_2->setText(QCoreApplication::translate("MatrixWindow", "Matrix B", nullptr));
            label_3->setText(QCoreApplication::translate("MatrixWindow", "Matrix C", nullptr));
            label_5->setText(QCoreApplication::translate("MatrixWindow", "det B = ", nullptr));
            det_b_label->setText(QString());
            label_6->setText(QCoreApplication::translate("MatrixWindow", "det C = ", nullptr));
            det_c_label->setText(QString());
            label_4->setText(QCoreApplication::translate("MatrixWindow", "det A = ", nullptr));
            det_a_label->setText(QString());
            pushButton->setText(QCoreApplication::translate("MatrixWindow", "Calculate det", nullptr));
            pushButton_switchToMain->setText(QCoreApplication::translate("MatrixWindow", "Main calculator", nullptr));
        } // retranslateUi
};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CALCULATOR_H
