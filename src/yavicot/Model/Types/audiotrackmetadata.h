#ifndef AUDIOTRACKMETADATA_H
#define AUDIOTRACKMETADATA_H

#include <QString>
#include "metadata.h"

class AudioTrackMetadata : public Metadata
{
    Q_OBJECT
    Q_PROPERTY(qint32 Samplerate READ Samplerate WRITE setSamplerate NOTIFY SamplerateChanged)
    Q_PROPERTY(double Bitrate READ Bitrate WRITE setBitrate NOTIFY BitrateChanged)
    Q_PROPERTY(double Duration READ Duration WRITE setDuration NOTIFY DurationChanged)

    qint32 m_Samplerate;
    double m_Bitrate;
    double m_Duration;

public:
AudioTrackMetadata();
qint32 Samplerate() const
{
    return m_Samplerate;
}
double Bitrate() const
{
    return m_Bitrate;
}

double Duration() const
{
    return m_Duration;
}

public slots:
void setSamplerate(qint32 Samplerate)
{
    if (m_Samplerate == Samplerate)
        return;

    m_Samplerate = Samplerate;
    emit SamplerateChanged(Samplerate);
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

signals:
void SamplerateChanged(qint32 Samplerate);
void BitrateChanged(double Bitrate);
void DurationChanged(double Duration);
};

#endif // AUDIOTRACKMETADATA_H
