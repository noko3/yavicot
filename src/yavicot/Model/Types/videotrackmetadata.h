#ifndef VIDEOTRACKMETADATA_H
#define VIDEOTRACKMETADATA_H

#include <QSize>
#include "metadata.h"

class VideoTrackMetadata : public Metadata
{
public:
    VideoTrackMetadata();
    double framerate;
    double bitrate;
    double duration;
    QSize resolution;
};

#endif // VIDEOTRACKMETADATA_H
