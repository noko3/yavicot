#ifndef RENDEROPTIONS_H
#define RENDEROPTIONS_H

#include <QString>
#include "../Interfaces/idomserializable.h"

class RenderOptions : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Command READ Command WRITE setCommand NOTIFY CommandChanged)
    QString m_Command;

public:
    explicit RenderOptions(QObject *parent = 0);
    QString Command() const
    {
        return m_Command;
    }
public slots:
void setCommand(QString Command)
{
    if (m_Command == Command)
        return;

    m_Command = Command;
    emit CommandChanged(Command);
}
signals:
void CommandChanged(QString Command);
};

#endif // RENDEROPTIONS_H
