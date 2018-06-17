/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_13;
    QLineEdit *lineEdit_hostname;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_backup_server;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_backup_server;
    QLineEdit *lineEdit_limit_backup_server;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_hdd_temp;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_hdd_temp;
    QLineEdit *lineEdit_limit_hdd_temp;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_hdd_load;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_hdd_load;
    QLineEdit *lineEdit_limit_hdd_load;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_hdd_usage;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit_hdd_usage;
    QLineEdit *lineEdit_limit_hdd_usage;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_cpu_temp;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_cpu_temp;
    QLineEdit *lineEdit_limit_cpu_temp;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_cpu_load;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lineEdit_cpu_load;
    QLineEdit *lineEdit_limit_cpu_load;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_cpu_usage;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *lineEdit_cpu_usage;
    QLineEdit *lineEdit_limit_cpu_usage;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_ram_usage;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *lineEdit_ram_usage;
    QLineEdit *lineEdit_limit_ram_usage;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_swap_usage;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *lineEdit_swap_usage;
    QLineEdit *lineEdit_limit_swap_usage;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_process_qty;
    QSpacerItem *horizontalSpacer_10;
    QLineEdit *lineEdit_process_qty;
    QLineEdit *lineEdit_limit_process_qty;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton_reset;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(427, 505);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 395, 434));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout_11->addWidget(label);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_11);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_15->addWidget(label_2);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_13);

        lineEdit_hostname = new QLineEdit(layoutWidget);
        lineEdit_hostname->setObjectName(QStringLiteral("lineEdit_hostname"));

        horizontalLayout_15->addWidget(lineEdit_hostname);


        verticalLayout->addLayout(horizontalLayout_15);


        verticalLayout_3->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_14->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_14->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_14->addWidget(label_5);


        verticalLayout_2->addLayout(horizontalLayout_14);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_backup_server = new QLabel(layoutWidget);
        label_backup_server->setObjectName(QStringLiteral("label_backup_server"));

        horizontalLayout->addWidget(label_backup_server);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lineEdit_backup_server = new QLineEdit(layoutWidget);
        lineEdit_backup_server->setObjectName(QStringLiteral("lineEdit_backup_server"));

        horizontalLayout->addWidget(lineEdit_backup_server);

        lineEdit_limit_backup_server = new QLineEdit(layoutWidget);
        lineEdit_limit_backup_server->setObjectName(QStringLiteral("lineEdit_limit_backup_server"));
        lineEdit_limit_backup_server->setEnabled(false);

        horizontalLayout->addWidget(lineEdit_limit_backup_server);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_hdd_temp = new QLabel(layoutWidget);
        label_hdd_temp->setObjectName(QStringLiteral("label_hdd_temp"));

        horizontalLayout_2->addWidget(label_hdd_temp);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lineEdit_hdd_temp = new QLineEdit(layoutWidget);
        lineEdit_hdd_temp->setObjectName(QStringLiteral("lineEdit_hdd_temp"));

        horizontalLayout_2->addWidget(lineEdit_hdd_temp);

        lineEdit_limit_hdd_temp = new QLineEdit(layoutWidget);
        lineEdit_limit_hdd_temp->setObjectName(QStringLiteral("lineEdit_limit_hdd_temp"));

        horizontalLayout_2->addWidget(lineEdit_limit_hdd_temp);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_hdd_load = new QLabel(layoutWidget);
        label_hdd_load->setObjectName(QStringLiteral("label_hdd_load"));

        horizontalLayout_3->addWidget(label_hdd_load);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        lineEdit_hdd_load = new QLineEdit(layoutWidget);
        lineEdit_hdd_load->setObjectName(QStringLiteral("lineEdit_hdd_load"));

        horizontalLayout_3->addWidget(lineEdit_hdd_load);

        lineEdit_limit_hdd_load = new QLineEdit(layoutWidget);
        lineEdit_limit_hdd_load->setObjectName(QStringLiteral("lineEdit_limit_hdd_load"));

        horizontalLayout_3->addWidget(lineEdit_limit_hdd_load);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_hdd_usage = new QLabel(layoutWidget);
        label_hdd_usage->setObjectName(QStringLiteral("label_hdd_usage"));

        horizontalLayout_4->addWidget(label_hdd_usage);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        lineEdit_hdd_usage = new QLineEdit(layoutWidget);
        lineEdit_hdd_usage->setObjectName(QStringLiteral("lineEdit_hdd_usage"));

        horizontalLayout_4->addWidget(lineEdit_hdd_usage);

        lineEdit_limit_hdd_usage = new QLineEdit(layoutWidget);
        lineEdit_limit_hdd_usage->setObjectName(QStringLiteral("lineEdit_limit_hdd_usage"));

        horizontalLayout_4->addWidget(lineEdit_limit_hdd_usage);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_cpu_temp = new QLabel(layoutWidget);
        label_cpu_temp->setObjectName(QStringLiteral("label_cpu_temp"));

        horizontalLayout_5->addWidget(label_cpu_temp);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        lineEdit_cpu_temp = new QLineEdit(layoutWidget);
        lineEdit_cpu_temp->setObjectName(QStringLiteral("lineEdit_cpu_temp"));

        horizontalLayout_5->addWidget(lineEdit_cpu_temp);

        lineEdit_limit_cpu_temp = new QLineEdit(layoutWidget);
        lineEdit_limit_cpu_temp->setObjectName(QStringLiteral("lineEdit_limit_cpu_temp"));

        horizontalLayout_5->addWidget(lineEdit_limit_cpu_temp);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_cpu_load = new QLabel(layoutWidget);
        label_cpu_load->setObjectName(QStringLiteral("label_cpu_load"));

        horizontalLayout_6->addWidget(label_cpu_load);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        lineEdit_cpu_load = new QLineEdit(layoutWidget);
        lineEdit_cpu_load->setObjectName(QStringLiteral("lineEdit_cpu_load"));

        horizontalLayout_6->addWidget(lineEdit_cpu_load);

        lineEdit_limit_cpu_load = new QLineEdit(layoutWidget);
        lineEdit_limit_cpu_load->setObjectName(QStringLiteral("lineEdit_limit_cpu_load"));

        horizontalLayout_6->addWidget(lineEdit_limit_cpu_load);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_cpu_usage = new QLabel(layoutWidget);
        label_cpu_usage->setObjectName(QStringLiteral("label_cpu_usage"));

        horizontalLayout_7->addWidget(label_cpu_usage);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        lineEdit_cpu_usage = new QLineEdit(layoutWidget);
        lineEdit_cpu_usage->setObjectName(QStringLiteral("lineEdit_cpu_usage"));

        horizontalLayout_7->addWidget(lineEdit_cpu_usage);

        lineEdit_limit_cpu_usage = new QLineEdit(layoutWidget);
        lineEdit_limit_cpu_usage->setObjectName(QStringLiteral("lineEdit_limit_cpu_usage"));

        horizontalLayout_7->addWidget(lineEdit_limit_cpu_usage);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_ram_usage = new QLabel(layoutWidget);
        label_ram_usage->setObjectName(QStringLiteral("label_ram_usage"));

        horizontalLayout_8->addWidget(label_ram_usage);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        lineEdit_ram_usage = new QLineEdit(layoutWidget);
        lineEdit_ram_usage->setObjectName(QStringLiteral("lineEdit_ram_usage"));

        horizontalLayout_8->addWidget(lineEdit_ram_usage);

        lineEdit_limit_ram_usage = new QLineEdit(layoutWidget);
        lineEdit_limit_ram_usage->setObjectName(QStringLiteral("lineEdit_limit_ram_usage"));

        horizontalLayout_8->addWidget(lineEdit_limit_ram_usage);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_swap_usage = new QLabel(layoutWidget);
        label_swap_usage->setObjectName(QStringLiteral("label_swap_usage"));

        horizontalLayout_9->addWidget(label_swap_usage);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);

        lineEdit_swap_usage = new QLineEdit(layoutWidget);
        lineEdit_swap_usage->setObjectName(QStringLiteral("lineEdit_swap_usage"));

        horizontalLayout_9->addWidget(lineEdit_swap_usage);

        lineEdit_limit_swap_usage = new QLineEdit(layoutWidget);
        lineEdit_limit_swap_usage->setObjectName(QStringLiteral("lineEdit_limit_swap_usage"));

        horizontalLayout_9->addWidget(lineEdit_limit_swap_usage);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_process_qty = new QLabel(layoutWidget);
        label_process_qty->setObjectName(QStringLiteral("label_process_qty"));

        horizontalLayout_10->addWidget(label_process_qty);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);

        lineEdit_process_qty = new QLineEdit(layoutWidget);
        lineEdit_process_qty->setObjectName(QStringLiteral("lineEdit_process_qty"));

        horizontalLayout_10->addWidget(lineEdit_process_qty);

        lineEdit_limit_process_qty = new QLineEdit(layoutWidget);
        lineEdit_limit_process_qty->setObjectName(QStringLiteral("lineEdit_limit_process_qty"));

        horizontalLayout_10->addWidget(lineEdit_limit_process_qty);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_14);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_13->addWidget(pushButton);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));

        horizontalLayout_13->addLayout(horizontalLayout_12);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_12);

        pushButton_reset = new QPushButton(layoutWidget);
        pushButton_reset->setObjectName(QStringLiteral("pushButton_reset"));

        horizontalLayout_13->addWidget(pushButton_reset);


        verticalLayout_2->addLayout(horizontalLayout_13);


        verticalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 427, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "ServerMonitor", 0));
        label_2->setText(QApplication::translate("MainWindow", "Hostname:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Resource", 0));
        label_4->setText(QApplication::translate("MainWindow", "Value (%)", 0));
        label_5->setText(QApplication::translate("MainWindow", "Limit (%)", 0));
        label_backup_server->setText(QApplication::translate("MainWindow", "Backup:", 0));
        label_hdd_temp->setText(QApplication::translate("MainWindow", "HDD temp:", 0));
        label_hdd_load->setText(QApplication::translate("MainWindow", "HDD load:", 0));
        label_hdd_usage->setText(QApplication::translate("MainWindow", "HDD usage:", 0));
        label_cpu_temp->setText(QApplication::translate("MainWindow", "CPU temp.:", 0));
        label_cpu_load->setText(QApplication::translate("MainWindow", "CPU load:", 0));
        label_cpu_usage->setText(QApplication::translate("MainWindow", "CPU usage:", 0));
        label_ram_usage->setText(QApplication::translate("MainWindow", "RAM usage:", 0));
        label_swap_usage->setText(QApplication::translate("MainWindow", "SWAP usage:", 0));
        label_process_qty->setText(QApplication::translate("MainWindow", "Process QTY:", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Resetuj odczyty", 0));
        pushButton_reset->setText(QApplication::translate("MainWindow", "Resetuj limity", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
