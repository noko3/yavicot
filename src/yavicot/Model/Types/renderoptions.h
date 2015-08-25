#ifndef RENDEROPTIONS_H
#define RENDEROPTIONS_H

#include <QString>
#include "../Interfaces/idomserializable.h"

class RenderOptions : public IDomSerializable
{
public:
    QString Command;
};

#endif // RENDEROPTIONS_H
