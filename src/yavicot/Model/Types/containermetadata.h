#ifndef CONTAINERMETADATA_H
#define CONTAINERMETADATA_H

#include <QList>
#include "metadata.h"

class ContainerMetadata : public Metadata
{
public:
    ContainerMetadata();

    int nChildren;
    QList<Metadata> childrenMeta;
};

#endif // CONTAINERMETADATA_H
