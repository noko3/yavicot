#ifndef METADATA_H
#define METADATA_H

#include <QString>
#include "../Interfaces/idomserializable.h"

class Metadata : public IDomSerializable
{
  private:
    int _nPackedItems;
  public:
    bool IsContainer();
    int ItemsCount();
    QString ProbeInfo;

    Metadata();
    ~Metadata();

    // IDomSerializable interface
    QDomElement &Serialize(QDomDocument &doc);
    Metadata &Deserialize(QDomElement &self);
};

#endif // METADATA_H
