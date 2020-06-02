/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *selectmodeBox;
    QRadioButton *testMode;
    QRadioButton *battleMode;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QComboBox *selectTranslate;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(860, 409);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        selectmodeBox = new QGroupBox(centralWidget);
        selectmodeBox->setObjectName(QStringLiteral("selectmodeBox"));
        selectmodeBox->setGeometry(QRect(690, 230, 161, 81));
        testMode = new QRadioButton(selectmodeBox);
        testMode->setObjectName(QStringLiteral("testMode"));
        testMode->setGeometry(QRect(10, 50, 131, 24));
        testMode->setAcceptDrops(false);
        battleMode = new QRadioButton(selectmodeBox);
        battleMode->setObjectName(QStringLiteral("battleMode"));
        battleMode->setGeometry(QRect(10, 20, 131, 24));
        battleMode->setCheckable(true);
        battleMode->setChecked(true);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(740, 160, 85, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 63, 18));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 80, 321, 111));
        selectTranslate = new QComboBox(centralWidget);
        selectTranslate->setObjectName(QStringLiteral("selectTranslate"));
        selectTranslate->setGeometry(QRect(740, 20, 86, 26));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 860, 23));
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
        selectmodeBox->setTitle(QApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274\321\213", 0));
        testMode->setText(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\320\276\320\262\321\213\320\271 \321\200\320\265\320\266\320\270\320\274", 0));
        battleMode->setText(QApplication::translate("MainWindow", "\320\221\320\276\320\265\320\262\320\276\320\271 \321\200\320\265\320\266\320\270\320\274", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\273\320\260\320\264\320\272\320\260", 0));
        label->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\320\260\320\272\321\202\321\213", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
