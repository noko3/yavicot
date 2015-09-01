#ifndef CONTAINERMETADATA_H
#define CONTAINERMETADATA_H

#include <QList>
#include <QString>
#include "metadata.h"

class ContainerMetadata : public Metadata
{
    Q_OBJECT
    Q_PROPERTY(QString MuxerName READ MuxerName WRITE setMuxerName)
    QString m_MuxerName;

public:
    ContainerMetadata() : Metadata() {};
    QString MuxerName() const
    {
        return m_MuxerName;
    }
public slots:
    void setMuxerName(QString MuxerName)
    {
        m_MuxerName = MuxerName;
    }
};

#endif // CONTAINERMETADATA_H
