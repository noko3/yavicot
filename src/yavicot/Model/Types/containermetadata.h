#ifndef CONTAINERMETADATA_H
#define CONTAINERMETADATA_H

#include <QList>
#include <QString>
#include "metadata.h"

class ContainerMetadata : public Metadata
{
public:
    ContainerMetadata();

    QString MuxerName;
    int nChildren;
    QList<Metadata> childrenMeta;
};

#endif // CONTAINERMETADATA_H
