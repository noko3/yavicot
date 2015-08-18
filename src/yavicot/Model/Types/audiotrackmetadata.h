#ifndef AUDIOTRACKMETADATA_H
#define AUDIOTRACKMETADATA_H

#include <QString>
#include "metadata.h"

class AudioTrackMetadata : public Metadata
{
public:
    AudioTrackMetadata();
    long samplerate;
    double bitrate;
    double duration;
};

#endif // AUDIOTRACKMETADATA_H
