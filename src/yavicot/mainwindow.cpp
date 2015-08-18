#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ImportVideoTrackSlot()
{

}

void MainWindow::ImportAudioTrackSlot()
{

}

void MainWindow::ImportSubtitlesSlot()
{

}

void MainWindow::RenderSlot()
{

}

void MainWindow::QuitSlot()
{

}

void MainWindow::on_mFileImportVideo_triggered()
{

}
