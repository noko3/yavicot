#ifndef MEDIAITEM
#define MEDIAITEM

#include <QString>
#include <QMimeType>
#include <QList>
#include "metadata.h"
#include "itemtype.h"

struct MediaItem {
    MediaItemType type;
    QString filename;
    QMimeType mimetype;
    Metadata meta;
    QList<MediaItem> contents;
};

#endif // MEDIAITEM

