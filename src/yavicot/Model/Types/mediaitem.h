#ifndef MEDIAITEM_H
#define MEDIAITEM_H

#include <QString>
#include <QMimeType>
#include <QList>
#include "../Interfaces/idomserializable.h"
#include "metadata.h"
#include "itemtype.h"

class MediaItem : public IDomSerializable {
public:
    MediaItemType type;
    QString filename;
    QMimeType mimetype;
    Metadata meta;
    QList<MediaItem> contents;

    // IDomSerializable interface
    QDomElement &Serialize(QDomDocument &doc);
    MediaItem &Deserialize(QDomElement &self);
};

#endif // MEDIAITEM_H

