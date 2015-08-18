#ifndef MEDIAITEM
#define MEDIAITEM

#include <QString>
#include <QMimeType>
#include <QList>
#include "metadata.h"

class MediaItem {
public:
    QString filename;
    QMimeType filetype;
    Metadata meta;
    QList<MediaItem> contents;

    MediaItem();
    ~MediaItem();
};

#endif // MEDIAITEM

