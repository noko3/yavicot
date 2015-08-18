#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void ImportVideoTrackSlot();
    void ImportAudioTrackSlot();
    void ImportSubtitlesSlot();
    void RenderSlot();
    void QuitSlot();
    void on_mFileImportVideo_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
