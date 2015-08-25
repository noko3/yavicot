#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QMessageBox>
#include <QFileDialog>
#include "Model/appmodel.h"
#include "strings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void AddMediaSlot();
    void RemoveMediaSlot();
    void SelectMediaSlot();
    void RenderSlot();
    void AboutSlot();
    void CreateNewProjectSlot();
    void SaveProjectSlot();
    void LoadProjectSlot();
    void SaveProjectAsSlot();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
