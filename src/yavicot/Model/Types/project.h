#ifndef PROJECT_H
#define PROJECT_H

#include <QList>
#include <QString>
#include "mediaitem.h"

//#include <libxml/encoding.h>
//#include <libxml/xmlwriter.h>

struct Project {
    QString Name;
    QString Comment;
    // ProjectSettings Settings;
    QList<MediaItem> AudioFiles;
    QList<MediaItem> VideoFiles;
    QList<MediaItem> Subtitles;

    Project& Empty() {
        Project *tmp = new Project();
        tmp->Name = "New project";
        tmp->Comment = "";
        return *tmp;
    }
    
    int Save(QString filename);
    static Project& Load(QString filename, int &err);
};

#endif // PROJECT_H

