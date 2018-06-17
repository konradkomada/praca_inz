//Autor Konrad Komada
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QtCore>
#include <QtGui>
#include <QString>
#include <QMessageBox>
#include <QGlobal.h>
#include <QTime>
#include <QFileSystemWatcher>

QString hostname = "hostname.txt";
QString backup_server = "backup-server.txt";
QString hdd_temp = "hdd-temp.txt";
QString hdd_load = "hdd-load.txt";
QString hdd_usage = "hdd-usage.txt";
QString cpu_temp = "cpu-temp.txt";
QString cpu_load = "cpu-load.txt";
QString cpu_usage = "cpu-usage.txt";
QString ram_usage = "ram-usage.txt";
QString swap_usage = "swap-usage.txt";
QString process_qty = "process-qty.txt";
QString limit_hdd_temp = "limit-hdd-temp.txt";
QString limit_hdd_load = "limit-hdd-load.txt";
QString limit_hdd_usage = "limit-hdd-usage.txt";
QString limit_cpu_temp = "limit-cpu-temp.txt";
QString limit_cpu_load = "limit-cpu-load.txt";
QString limit_cpu_usage = "limit-cpu-usage.txt";
QString limit_ram_usage = "limit-ram-usage.txt";
QString limit_swap_usage = "limit-swap-usage.txt";
QString limit_process_qty = "limit-process-qty.txt";

//Metoda monitorująca zmiany w plikach
void MainWindow::Monitoruj_plik(QString Filename) // <- konstruktor
{
    fw = new QFileSystemWatcher(this);
    connect( fw, SIGNAL(fileChanged(QString)), this, SLOT( fileChangedSlot(QString)) );
    fw->addPath(Filename);
    //qDebug() << fw->files() << fw->directories(); // outputs: () ("plik") in test ther are file
    //QMessageBox::information(this,"test","Zmiana pliku: "+Filename);
}

//SLOT podejmujący akcję na zmianę w pliku, jeśli nastąpiła zmiana pliku ale plik nie jest pusty to odpala metode  Read_clear_file
void MainWindow::fileChangedSlot(QString Filename)
{
    //#ifdef QT_DEBUG
    //qDebug() << "files watched: " << fw->files() << fw->directories();
    //#endif
    //QMessageBox::information(this,"test","Zmiana pliku2: "+Filename);
    QFile mFile(Filename);
    mFile.open( QIODevice::WriteOnly|QIODevice::Append);
    if (mFile.pos() != 0) {

        ui->lineEdit_hostname->setText(Read_file(hostname));
        ui->lineEdit_backup_server->setText(Read_file(backup_server));
        ui->lineEdit_hdd_temp->setText(Read_file(hdd_temp));
        ui->lineEdit_hdd_load->setText(Read_file(hdd_load));
        ui->lineEdit_hdd_usage->setText(Read_file(hdd_usage));
        ui->lineEdit_cpu_temp->setText(Read_file(cpu_temp));
        ui->lineEdit_cpu_load->setText(Read_file(cpu_load));
        ui->lineEdit_cpu_usage->setText(Read_file(cpu_usage));
        ui->lineEdit_ram_usage->setText(Read_file(ram_usage));
        ui->lineEdit_swap_usage->setText(Read_file(swap_usage));
        ui->lineEdit_process_qty->setText(Read_file(process_qty));
        ui->lineEdit_limit_hdd_temp->setText(Read_file(limit_hdd_temp));
        ui->lineEdit_limit_hdd_load->setText(Read_file(limit_hdd_load));
        ui->lineEdit_limit_hdd_usage->setText(Read_file(limit_hdd_usage));
        ui->lineEdit_limit_cpu_temp->setText(Read_file(limit_cpu_temp));
        ui->lineEdit_limit_cpu_load->setText(Read_file(limit_cpu_load));
        ui->lineEdit_limit_cpu_usage->setText(Read_file(limit_cpu_usage));
        ui->lineEdit_limit_ram_usage->setText(Read_file(limit_ram_usage));
        ui->lineEdit_limit_swap_usage->setText(Read_file(limit_swap_usage));
        ui->lineEdit_limit_process_qty->setText(Read_file(limit_process_qty));
        //ui->pushButton->hide();
        //ui->pushButton_3->show();

//        Ustaw_pole(hdd_temp,limit_hdd_temp);
//        Ustaw_pole(hdd_load,limit_hdd_load);
//        Ustaw_pole(hdd_load,limit_hdd_usage);
//        Ustaw_pole(cpu_temp,limit_cpu_temp);
//        Ustaw_pole(cpu_load,limit_cpu_load);
//        Ustaw_pole(cpu_usage,limit_cpu_usage);
//        Ustaw_pole(ram_usage,limit_ram_usage);
//        Ustaw_pole(swap_usage,limit_swap_usage);
//        Ustaw_pole(process_qty,limit_process_qty);
    }
}

//Metoda odczytująca z pliku
QString MainWindow::Read_file(QString Filename)
{
    QFile mFile(Filename);
    //    mFile.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!mFile.open(QFile::ReadOnly | QFile::Text))     //# Sprawdzenie czy czy można zapisywać do pliku
    {
        QMessageBox::information(this,"Debug: open file","5Nie mogę otworzyć pliku: "+Filename+" do odczytu");
    }
    QTextStream in(&mFile);
    QString mText = in.readAll();

    return mText;
    mFile.close();
}

//Metoda czyszcząca plik
void MainWindow::Clear_file(QString Filename)
{
    QFile mFile(Filename);
    //    mFile.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!mFile.open(QFile::WriteOnly | QFile::Text))             //# Sprawdzenie czy czy można zapisywać do pliku
    {
        QMessageBox::information(this,"Debug: write file","4Nie mogę otworzyć pliku: "+Filename+" do zapisu");
        return;
    }
    QTextStream out(&mFile);
    out <<  QString ("");
    mFile.flush();
    mFile.close();
}

//Metoda wypełniająca plik zerem
void MainWindow::Zero_file(QString Filename)
{
    QFile mFile(Filename);
    //    mFile.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!mFile.open(QFile::WriteOnly | QFile::Text))             //# Sprawdzenie czy czy można zapisywać do pliku
    {
        QMessageBox::information(this,"Debug: write file","4Nie mogę otworzyć pliku: "+Filename+" do zapisu");
        return;
    }
    QTextStream out(&mFile);
    out <<  QString ("90");
    mFile.flush();
    mFile.close();
}

//Metoda zapisująca do pliku
void MainWindow::Write_file(QString Filename, double WData)
{
    QFile mFile(Filename);
    //    mFile.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!mFile.open(QFile::WriteOnly | QFile::Text))             //# Sprawdzenie czy czy można zapisywać do pliku
    {
        QMessageBox::information(this,"Debug: write file","Nie mogę otworzyć pliku: "+Filename+" do zapisu");
        return;
    }
    QTextStream out(&mFile);
    out <<  QString::number(WData,'f', 2);
    mFile.flush();
    mFile.close();
}

//metoda służy do porównywania wartości zasoby z limitem i sygnalizowania stanu zgodności
void MainWindow::Ustaw_pole(QString Filename, QString Filename_limit)
{

    dData=Read_file(Filename).toDouble();
    lData=Read_file(Filename_limit).toDouble();

if (dData > lData) {
    ui->lineEdit_hostname->setStyleSheet("background-color: #00ffff;");
} else if (dData == lData) {
    ui->lineEdit_hostname->setStyleSheet("background-color: #ff00ff;");
} else {
    ui->lineEdit_hostname->setStyleSheet("background-color: #ffff00;");
}
}



//konstruktor głównego okna główna metoda ustawiająca zmienne
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #00ff00;");
    ui->lineEdit_hostname->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_backup_server->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_hdd_temp->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_hdd_load->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_hdd_usage->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_cpu_temp->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_cpu_load->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_cpu_usage->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_ram_usage->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_swap_usage->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_process_qty->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_limit_backup_server->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_limit_hdd_temp->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_limit_hdd_load->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_limit_hdd_usage->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_limit_cpu_temp->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_limit_cpu_load->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_limit_cpu_usage->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_limit_ram_usage->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_limit_swap_usage->setStyleSheet("background-color: #ffffff;");
    ui->lineEdit_limit_process_qty->setStyleSheet("background-color: #ffffff;");
    ui->pushButton_reset->setStyleSheet("background-color: #eeeeee;");
    ui->pushButton->setStyleSheet("background-color: #eeeeee;");
    //ui->pushButton_2->setVisible(false);

    Read_file(hostname);
    Read_file(backup_server);
    Read_file(hdd_temp);
    Read_file(hdd_load);
    Read_file(hdd_usage);
    Read_file(cpu_temp);
    Read_file(cpu_load);
    Read_file(cpu_usage);
    Read_file(ram_usage);
    Read_file(swap_usage);
    Read_file(process_qty);
    Monitoruj_plik(hostname);
    Monitoruj_plik(backup_server);
    Monitoruj_plik(hdd_temp);
    Monitoruj_plik(hdd_load);
    Monitoruj_plik(hdd_usage);
    Monitoruj_plik(cpu_temp);
    Monitoruj_plik(cpu_load);
    Monitoruj_plik(cpu_usage);
    Monitoruj_plik(ram_usage);
    Monitoruj_plik(swap_usage);
    Monitoruj_plik(process_qty);

    Read_file(limit_hdd_temp);
    Read_file(limit_hdd_load);
    Read_file(limit_hdd_usage);
    Read_file(limit_cpu_temp);
    Read_file(limit_cpu_load);
    Read_file(limit_cpu_usage);
    Read_file(limit_ram_usage);
    Read_file(limit_swap_usage);
    Read_file(limit_process_qty);
    Monitoruj_plik(limit_hdd_temp);
    Monitoruj_plik(limit_hdd_load);
    Monitoruj_plik(limit_hdd_usage);
    Monitoruj_plik(limit_cpu_temp);
    Monitoruj_plik(limit_cpu_load);
    Monitoruj_plik(limit_cpu_usage);
    Monitoruj_plik(limit_ram_usage);
    Monitoruj_plik(limit_swap_usage);
    Monitoruj_plik(limit_process_qty);


    Ustaw_pole(hdd_temp,limit_hdd_temp);
    Ustaw_pole(hdd_load,limit_hdd_load);
    Ustaw_pole(hdd_load,limit_hdd_usage);
    Ustaw_pole(cpu_temp,limit_cpu_temp);
    Ustaw_pole(cpu_load,limit_cpu_load);
    Ustaw_pole(cpu_usage,limit_cpu_usage);
    Ustaw_pole(ram_usage,limit_ram_usage);
    Ustaw_pole(swap_usage,limit_swap_usage);
    Ustaw_pole(process_qty,limit_process_qty);

}

//Destruktor
MainWindow::~MainWindow()
{
    delete ui;
}

//Metoda dla przycisku resetu limitów
void MainWindow::on_pushButton_reset_clicked()
{
    Zero_file(limit_hdd_temp);
    Zero_file(limit_hdd_load);
    Zero_file(limit_hdd_usage);
    Zero_file(limit_cpu_temp);
    Zero_file(limit_cpu_load);
    Zero_file(limit_cpu_usage);
    Zero_file(limit_ram_usage);
    Zero_file(limit_swap_usage);
    Zero_file(limit_process_qty);
    Monitoruj_plik(limit_hdd_temp);
    Monitoruj_plik(limit_hdd_load);
    Monitoruj_plik(limit_hdd_usage);
    Monitoruj_plik(limit_cpu_temp);
    Monitoruj_plik(limit_cpu_load);
    Monitoruj_plik(limit_cpu_usage);
    Monitoruj_plik(limit_ram_usage);
    Monitoruj_plik(limit_swap_usage);
    Monitoruj_plik(limit_process_qty);
}

//Enter w edycji
void MainWindow::on_lineEdit_limit_hdd_temp_returnPressed()
{
    QString readed_amount_char=ui->lineEdit_limit_hdd_temp->text();
    readed_amount=readed_amount_char.toDouble();
    //QMessageBox::information(this,"Debug4",ui->lineEdit_limit_hdd_temp->text());
    Write_file(limit_hdd_temp,readed_amount);
}

void MainWindow::on_lineEdit_limit_hdd_load_returnPressed()
{
    QString readed_amount_char=ui->lineEdit_limit_hdd_load->text();
    readed_amount=readed_amount_char.toDouble();
    Write_file(limit_hdd_load,readed_amount);
}

void MainWindow::on_lineEdit_limit_hdd_usage_returnPressed()
{
    QString readed_amount_char=ui->lineEdit_limit_hdd_usage->text();
    readed_amount=readed_amount_char.toDouble();
    Write_file(limit_hdd_usage,readed_amount);
}

void MainWindow::on_lineEdit_limit_cpu_temp_returnPressed()
{
    QString readed_amount_char=ui->lineEdit_limit_cpu_temp->text();
    readed_amount=readed_amount_char.toDouble();
    Write_file(limit_cpu_temp,readed_amount);
}

void MainWindow::on_lineEdit_limit_cpu_load_returnPressed()
{
    QString readed_amount_char=ui->lineEdit_limit_cpu_load->text();
    readed_amount=readed_amount_char.toDouble();
    Write_file(limit_cpu_load,readed_amount);
}

void MainWindow::on_lineEdit_limit_cpu_usage_returnPressed()
{
    QString readed_amount_char=ui->lineEdit_limit_cpu_usage->text();
    readed_amount=readed_amount_char.toDouble();
    Write_file(limit_cpu_usage,readed_amount);
}

void MainWindow::on_lineEdit_limit_ram_usage_returnPressed()
{
    QString readed_amount_char=ui->lineEdit_limit_ram_usage->text();
    readed_amount=readed_amount_char.toDouble();
    Write_file(limit_ram_usage,readed_amount);
}

void MainWindow::on_lineEdit_limit_swap_usage_returnPressed()
{
    QString readed_amount_char=ui->lineEdit_limit_swap_usage->text();
    readed_amount=readed_amount_char.toDouble();
    Write_file(limit_swap_usage,readed_amount);
}

void MainWindow::on_lineEdit_limit_process_qty_returnPressed()
{
    QString readed_amount_char=ui->lineEdit_limit_process_qty->text();
    readed_amount=readed_amount_char.toDouble();
    Write_file(limit_process_qty,readed_amount);
}

//Koniec edycji
void MainWindow::on_lineEdit_limit_hdd_temp_editingFinished()
{
    QString readed_amount_char=ui->lineEdit_limit_hdd_temp->text();
    readed_amount=readed_amount_char.toDouble();
    //QMessageBox::information(this,"Debug4",ui->lineEdit_limit_hdd_temp->text());
    Write_file(limit_hdd_temp,readed_amount);
}

void MainWindow::on_lineEdit_limit_hdd_load_editingFinished()
{
    QString readed_amount_char=ui->lineEdit_limit_hdd_load->text();
    readed_amount=readed_amount_char.toDouble();
    Write_file(limit_hdd_load,readed_amount);
}

void MainWindow::on_lineEdit_limit_hdd_usage_editingFinished()
{
    QString readed_amount_char=ui->lineEdit_limit_hdd_usage->text();
    readed_amount=readed_amount_char.toDouble();
    Write_file(limit_hdd_usage,readed_amount);
}

void MainWindow::on_lineEdit_limit_cpu_temp_editingFinished()
{
    QString readed_amount_char=ui->lineEdit_limit_cpu_temp->text();
    readed_amount=readed_amount_char.toDouble();
    Write_file(limit_cpu_temp,readed_amount);
}

void MainWindow::on_lineEdit_limit_cpu_load_editingFinished()
{
    QString readed_amount_char=ui->lineEdit_limit_cpu_load->text();
    readed_amount=readed_amount_char.toDouble();
    Write_file(limit_cpu_load,readed_amount);
}

void MainWindow::on_lineEdit_limit_cpu_usage_editingFinished()
{
    QString readed_amount_char=ui->lineEdit_limit_cpu_usage->text();
    readed_amount=readed_amount_char.toDouble();
    Write_file(limit_cpu_usage,readed_amount);
}

void MainWindow::on_lineEdit_limit_ram_usage_editingFinished()
{
    QString readed_amount_char=ui->lineEdit_limit_ram_usage->text();
    readed_amount=readed_amount_char.toDouble();
    Write_file(limit_ram_usage,readed_amount);
}

void MainWindow::on_lineEdit_limit_swap_usage_editingFinished()
{
    QString readed_amount_char=ui->lineEdit_limit_swap_usage->text();
    readed_amount=readed_amount_char.toDouble();
    Write_file(limit_swap_usage,readed_amount);
}

void MainWindow::on_lineEdit_limit_process_qty_editingFinished()
{
    QString readed_amount_char=ui->lineEdit_limit_process_qty->text();
    readed_amount=readed_amount_char.toDouble();
    Write_file(limit_process_qty,readed_amount);
}

void MainWindow::on_pushButton_clicked()
{
    Clear_file(hostname);
    Clear_file(backup_server);
    Clear_file(hdd_temp);
    Clear_file(hdd_load);
    Clear_file(hdd_usage);
    Clear_file(cpu_temp);
    Clear_file(cpu_load);
    Clear_file(cpu_usage);
    Clear_file(ram_usage);
    Clear_file(swap_usage);
    Clear_file(process_qty);

    Monitoruj_plik(hostname);
    Monitoruj_plik(backup_server);
    Monitoruj_plik(hdd_temp);
    Monitoruj_plik(hdd_load);
    Monitoruj_plik(hdd_usage);
    Monitoruj_plik(cpu_temp);
    Monitoruj_plik(cpu_load);
    Monitoruj_plik(cpu_usage);
    Monitoruj_plik(ram_usage);
    Monitoruj_plik(swap_usage);
    Monitoruj_plik(process_qty);
}
