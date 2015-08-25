#ifndef XMLSERIALIZABLE_H
#define XMLSERIALIZABLE_H

#include <QXmlStreamReader>
#include <QXmlStreamWriter>

class IXMLSerializable
{
public:
    virtual void Serialize(QXmlStreamWriter xw) = 0;
    virtual IXMLSerializable& Deserialize(QXmlStreamReader xr) = 0;
};

#endif // XMLSERIALIZABLE_H
