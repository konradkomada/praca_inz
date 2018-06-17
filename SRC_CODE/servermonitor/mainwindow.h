//Autor Konrad Komada
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <string>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QFileSystemWatcher>

extern QString hostname;
extern QString backup_server;
extern QString hdd_temp;
extern QString hdd_load;
extern QString hdd_usage;
extern QString cpu_temp;
extern QString cpu_load;
extern QString cpu_usage;
extern QString ram_usage;
extern QString swap_usage;
extern QString process_qty;

namespace Ui {
class MainWindow;
}

//Deklaracja klasy głównego okna (prototypy)
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void fileChangedSlot(QString Filename); //monitoring pliku
    void on_pushButton_reset_clicked();
    void on_lineEdit_limit_hdd_temp_returnPressed();
    void on_lineEdit_limit_hdd_load_editingFinished();
    void on_lineEdit_limit_hdd_usage_editingFinished();
    void on_lineEdit_limit_cpu_temp_returnPressed();
    void on_lineEdit_limit_cpu_load_returnPressed();
    void on_lineEdit_limit_cpu_usage_returnPressed();
    void on_lineEdit_limit_ram_usage_returnPressed();
    void on_lineEdit_limit_swap_usage_returnPressed();
    void on_lineEdit_limit_process_qty_returnPressed();
    void on_lineEdit_limit_hdd_temp_editingFinished();
    void on_lineEdit_limit_hdd_load_returnPressed();
    void on_lineEdit_limit_hdd_usage_returnPressed();
    void on_lineEdit_limit_cpu_temp_editingFinished();
    void on_lineEdit_limit_cpu_load_editingFinished();
    void on_lineEdit_limit_cpu_usage_editingFinished();
    void on_lineEdit_limit_ram_usage_editingFinished();
    void on_lineEdit_limit_swap_usage_editingFinished();
    void on_lineEdit_limit_process_qty_editingFinished();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void Write_file(QString Filename, double WData);
    QString Read_file(QString Filename);
    void Monitoruj_plik(QString Filename);
    void Clear_file(QString Filename);
    void Zero_file(QString Filename);
    void Ustaw_pole(QString Filename, QString Filename_limit);
    QFileSystemWatcher* fw;
    bool ok;
    double random_amount;
    char readed_amount_char;
    double readed_amount;
    double dData;
    double lData;
};

#endif // MAINWINDOW_H
