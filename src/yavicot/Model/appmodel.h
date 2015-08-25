#ifndef APPMODEL_H
#define APPMODEL_H

#include <QObject>
#include <QString>
#include <QList>
#include <QMimeType>
#include <QMimeDatabase>
#include "Types/mediaitem.h"
#include "Types/project.h"

#include <QDebug>

class AppModel: public QObject
{
    Q_OBJECT
private:
    QString _activeProjectFilename;
    Project _project;
    static AppModel *_instance;


    AppModel();
    //~AppModel();
public:
    //explicit AppModel(QWidget *parent = 0);
    static AppModel* Instance();

    /* Filesystem */
    int AddFileToProject(QString filename);
    void RemoveFileFromProject(int itemId);
    void LoadProject(QString filename);
    void SaveProject(QString filename = NULL);
    void RenderProject(QString filename);
};

extern AppModel *App;

#endif // APPMODEL_H
