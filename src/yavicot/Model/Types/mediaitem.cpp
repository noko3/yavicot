#include "mediaitem.h"

//QDomElement &MediaItem::Serialize(QDomDocument &doc)
//{
//}

//MediaItem &MediaItem::Deserialize(QDomElement &self)
//{
//}


MediaItem::MediaItem(QObject *parent)
{
    m_Type = Unknown;
    m_Filename = "";
}
