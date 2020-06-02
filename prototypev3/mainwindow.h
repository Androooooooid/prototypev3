#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QAction>
#include <QSettings>
#include <QMessageBox>
#include <QTranslator>
#include <QEvent>

#define ORGANIZATION_NAME "ФНПЦ АО НПО Марс"
#define ORGANIZATION_DOMAIN "www.npomars.com"
#define APPLICATION_NAME "prototypev3"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void readSettings();
    void changeEvent(QEvent * event) override;

protected:
    void closeEvent(QCloseEvent * event);

private slots:
    void on_battleMode_clicked();

    void on_testMode_clicked();

    void on_pushButton_clicked();

    void on_selectTranslate_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QTranslator qtLanguageTranslator;
};

#endif // MAINWINDOW_H
