#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QProcess>
#include "loggingcategories.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(APPLICATION_NAME);
    readSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
    settings.setValue("MainWindow/geometry", saveGeometry());
    settings.setValue("MainWindow/windowState", saveState());
    settings.setValue("MainWindow/battleMode", ui->battleMode->isChecked());
    settings.setValue("MainWindow/testMode", ui->testMode->isChecked());

    QMainWindow::closeEvent(event);
}

void MainWindow::readSettings()
{
    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
    restoreGeometry(settings.value("MainWindow/geometry").toByteArray());
    restoreState(settings.value("MainWindow/windowState").toByteArray());
    ui->battleMode->setChecked(settings.value("MainWindow/battleMode").toBool());
    ui->testMode->setChecked(settings.value("MainWindow/testMode").toBool());
}

void MainWindow::on_battleMode_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void MainWindow::on_testMode_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}
