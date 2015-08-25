#include "metadata.h"

Metadata::Metadata() {

}

Metadata::~Metadata() {

}

bool Metadata::IsContainer() {
    return false;
}


QDomElement &Metadata::Serialize(QDomDocument &doc)
{
}

IDomSerializable &Metadata::Deserialize(QDomElement &self)
{
}