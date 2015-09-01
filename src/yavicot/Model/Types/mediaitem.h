#ifndef MEDIAITEM_H
#define MEDIAITEM_H

#include <QString>
#include <QObject>
#include <QMimeType>
#include <QList>
#include "../Interfaces/idomserializable.h"
#include "metadata.h"
#include "itemtype.h"

class MediaItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(MediaItemType Type READ Type WRITE setType)
    Q_PROPERTY(QString Filename READ Filename WRITE setFilename)
    Q_PROPERTY(QMimeType MimeType READ MimeType WRITE setMimeType)
    Q_PROPERTY(Metadata* Meta READ Meta WRITE setMeta)
    Q_PROPERTY(QList<MediaItem*> ContainedItems
               READ ContainedItems
               WRITE setContainedItems)
public:
    explicit MediaItem(QObject *parent=0);

    MediaItemType Type() const
    {
        return m_Type;
    }

    QString Filename() const
    {
        return m_Filename;
    }

    QMimeType MimeType() const
    {
        return m_MimeType;
    }

    Metadata *Meta() const
    {
        return m_Meta;
    }

    QList<MediaItem*> ContainedItems() const
    {
        return m_ContainedItems;
    }

public slots:
    void setType(const MediaItemType value)
    {
        m_Type = value;
    }

    void setFilename(QString Filename)
    {
        m_Filename = Filename;
    }

    void setMimeType(QMimeType MimeType)
    {
        m_MimeType = MimeType;
    }

    void setMeta(Metadata *Meta)
    {
        m_Meta = Meta;
    }

    void setContainedItems(QList<MediaItem*> ContainedItems)
    {
        m_ContainedItems = ContainedItems;
    }

private:
    MediaItemType m_Type;
    QString m_Filename;
    QMimeType m_MimeType;
    Metadata *m_Meta;
    QList<MediaItem*> m_ContainedItems;
};

#endif // MEDIAITEM_H

