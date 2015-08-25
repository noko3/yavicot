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
    openFileDialog.setNameFilter(tr( Y_PROJ_FTYPES ));
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
	// no need to
}

void MainWindow::AddSubtitlesSlot()
{
	// no need to
}

void MainWindow::RenderSlot()
{

}

void MainWindow::AboutSlot()
{

}

void MainWindow::SaveProjectSlot()
{
	QFileDialog openFileDialog(this);
    openFileDialog.setFileMode(QFileDialog::AnyFile);
    openFileDialog.setNameFilter(tr( Y_YPRO_FTYPE ));
    openFileDialog.setViewMode(QFileDialog::Detail);
    QStringList filenames, errors;
    if (openFileDialog.exec())
        filenames = openFileDialog.selectedFiles();
}

void MainWindow::LoadProjectSlot()
{
	QFileDialog openFileDialog(this);
    openFileDialog.setFileMode(QFileDialog::ExistingFile);
    openFileDialog.setNameFilter(tr( Y_YPRO_FTYPE ));
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
}

void MainWindow::QuitSlot()
{
	// no need to
}
