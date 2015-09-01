#include "idomserializable.h"

// TODO: add recursion
bool XMLSerializer::Serialize(QObject *o, QTextStream *ds,
                                 QDomElement *pRoot)
{
    if (ds == NULL || o == NULL)
        return false;

    QDomDocument doc;
    QDomElement root = doc.createElement(o->metaObject()->className());
    if (pRoot != NULL)
        ((QDomElement)*pRoot).appendChild(root);
    else
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



    doc.save(*ds, 2);

    return true;
}


