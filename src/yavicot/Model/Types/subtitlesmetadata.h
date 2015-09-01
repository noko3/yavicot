#ifndef SUBTITLESMETADATA_H
#define SUBTITLESMETADATA_H

#include "metadata.h"

class SubtitlesMetadata : public Metadata
{
    Q_OBJECT
public:
    explicit SubtitlesMetadata(QObject *parent=0);
};

#endif // SUBTITLESMETADATA_H
