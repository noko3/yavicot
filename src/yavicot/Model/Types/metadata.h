#ifndef METADATA_H
#define METADATA_H

#include <QString>
#include "../Interfaces/idomserializable.h"

class Metadata : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int ItemsCount READ ItemsCount WRITE setItemsCount)
    Q_PROPERTY(bool IsContainer READ IsContainer WRITE setIsContainer)
    Q_PROPERTY(QString ProbeInfo READ ProbeInfo WRITE setProbeInfo)

    int m_ItemsCount;
    bool m_IsContainer;
    QString m_ProbeInfo;

public:
    explicit Metadata(QObject *parent = 0);

    int ItemsCount() const
    {
        return m_ItemsCount;
    }
    bool IsContainer() const
    {
        return m_IsContainer;
    }

    QString ProbeInfo() const
    {
        return m_ProbeInfo;
    }

public slots:
    void setItemsCount(int ItemsCount)
    {
        m_ItemsCount = ItemsCount;
    }
    void setIsContainer(bool IsContainer)
    {
        m_IsContainer = IsContainer;
    }
    void setProbeInfo(QString ProbeInfo)
    {
        m_ProbeInfo = ProbeInfo;
    }
};

#endif // METADATA_H
