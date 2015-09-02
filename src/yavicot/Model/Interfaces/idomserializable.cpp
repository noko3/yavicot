#include "idomserializable.h"

// TODO: add recursion
QString XMLSerializer::Serialize(QObject *o)
{
    if (o == NULL)
        return "";

    QDomDocument doc;
    QDomElement root = doc.createElement(o->metaObject()->className());
    doc.appendChild(root);

    for (int i=0; i<o->metaObject()->propertyCount(); i++)
    {
        QMetaProperty prop = o->metaObject()->property(i);
        QString propName = prop.name();
        if (propName == "objectName")
            continue;
        QDomElement el = doc.createElement(propName);
        QVariant value = o->property(prop.name());
        QDomText txt = doc.createTextNode(value.toString());
        el.appendChild(txt);
        root.appendChild(el);
    }

    QString tmp;
    QTextStream *str = new QTextStream(&tmp);
    doc.save(*str, 4);
    delete str;

    return tmp;
}


