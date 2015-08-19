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

// TODO exception handling
void MainWindow::AddVideoTrackSlot()
{
    QFileDialog openFileDialog(this);
    openFileDialog.setFileMode(QFileDialog::ExistingFiles);
    openFileDialog.setNameFilter(tr(
        "Video files (*.mp4, *.m4v, *.mov);;"
        "Audio files (*.wav, *.pcm, *.aac, *.flac);;"
        "Subtitles (*.srt, *.ass);;"
        "All files (*.*)"
        ));
    openFileDialog.setViewMode(QFileDialog::Detail);
    QStringList filenames, errors;
    if (openFileDialog.exec())
        filenames = openFileDialog.selectedFiles();

    foreach (QString fname, filenames) {
        //try {
            App->AddFileToProject(fname);
        //} catch () {
        //    errors.append(fname);
        //    continue;
        //}
    }

    if (errors.count())
        QMessageBox::information(this, tr("Yavicot"), errors.join("\n"),
                                 QMessageBox::Ok);
}

void MainWindow::AddAudioTrackSlot()
{

}

void MainWindow::AddSubtitlesSlot()
{

}

void MainWindow::RenderSlot()
{

}

void MainWindow::AboutSlot()
{

}

void MainWindow::QuitSlot()
{

}
