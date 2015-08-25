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
void MainWindow::AddMediaSlot()
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

void MainWindow::RemoveMediaSlot()
{

}

void MainWindow::SelectMediaSlot()
{

}

void MainWindow::RenderSlot()
{

}

void MainWindow::AboutSlot()
{

}

void MainWindow::CreateNewProjectSlot()
{

}

void MainWindow::SaveProjectSlot()
{

}

void MainWindow::SaveProjectAsSlot()
{
    QFileDialog saveFileDialog(this);
    saveFileDialog.setFileMode(QFileDialog::AnyFile);
    saveFileDialog.setNameFilter(tr( Y_YPRO_FTYPE ));
    saveFileDialog.setViewMode(QFileDialog::Detail);
    QStringList filenames;
    if (saveFileDialog.exec())
        filenames = saveFileDialog.selectedFiles();
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
            App->LoadProject(fname);
        //} catch () {
        //    errors.append(fname);
        //    continue;
        //}
    }
}
