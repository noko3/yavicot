#ifndef VIDEOTRACKMETADATA_H
#define VIDEOTRACKMETADATA_H

#include <QSize>
#include "metadata.h"

class VideoTrackMetadata : public Metadata
{
    Q_PROPERTY(double Framerate READ Framerate WRITE setFramerate NOTIFY FramerateChanged)
    Q_PROPERTY(double Bitrate READ Bitrate WRITE setBitrate NOTIFY BitrateChanged)
    Q_PROPERTY(double Duration READ Duration WRITE setDuration NOTIFY DurationChanged)
    Q_PROPERTY(QSize Resolution READ Resolution WRITE setResolution NOTIFY ResolutionChanged)

public:
    VideoTrackMetadata();
    double Framerate() const
    {
        return m_Framerate;
    }
    double Bitrate() const
    {
        return m_Bitrate;
    }

    double Duration() const
    {
        return m_Duration;
    }

    QSize Resolution() const
    {
        return m_Resolution;
    }

public slots:
    void setFramerate(double Framerate)
    {
        if (m_Framerate == Framerate)
            return;

        m_Framerate = Framerate;
        emit FramerateChanged(Framerate);
    }
    void setBitrate(double Bitrate)
    {
        if (m_Bitrate == Bitrate)
            return;

        m_Bitrate = Bitrate;
        emit BitrateChanged(Bitrate);
    }

    void setDuration(double Duration)
    {
        if (m_Duration == Duration)
            return;

        m_Duration = Duration;
        emit DurationChanged(Duration);
    }

    void setResolution(QSize Resolution)
    {
        if (m_Resolution == Resolution)
            return;

        m_Resolution = Resolution;
        emit ResolutionChanged(Resolution);
    }

signals:
    void FramerateChanged(double Framerate);
    void BitrateChanged(double Bitrate);

    void DurationChanged(double Duration);

    void ResolutionChanged(QSize Resolution);

private:
    double m_Framerate;
    double m_Bitrate;
    double m_Duration;
    QSize m_Resolution;
};

#endif // VIDEOTRACKMETADATA_H
