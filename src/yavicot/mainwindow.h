#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QMessageBox>
#include <QFileDialog>

#include "Model/appmodel.h"

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
    void AddVideoTrackSlot();
    void AddAudioTrackSlot();
    void AddSubtitlesSlot();
    void RenderSlot();
    void AboutSlot();
    void QuitSlot();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
