#ifndef IDOMSERIALIZABLE
#define IDOMSERIALIZABLE

#include <QDomDocument>
#include <QMetaProperty>
#include <QTextStream>
#include <QObject>

/*!
 * \brief IDomSerializable interface
 * Descendants must override Serialize() and Deserialize()
 */
class XMLSerializer {
public:
    /*!
     * \brief Serialize virtual method
     * Meant to serialize a descendant object to XML
     * \param doc Root document
     * \return Link to a serialized DOM element
     */
    static QString Serialize(QObject *o);

    /*!
     * \brief Deserialize virtual method
     * Meant to create an object from XML
     * \param self Node to deserialize
     * \return Link to a newly created object
     */
    template<typename T>
    static T* Deserialize(QString input);
};

template<typename T>
T* XMLSerializer::Deserialize(QString input)
{
    QDomDocument doc;
    if (!doc.setContent(input))
        return NULL;

    T* o = new T();

    QObject *object = dynamic_cast<QObject*>(o);
    if (object == NULL) {
        delete object;
        return NULL;
    }

    QDomElement root = doc.documentElement();
    for (int i=0; i<o->metaObject()->propertyCount(); i++) {
        QMetaProperty prop = o->metaObject()->property(i);
        QString propName = prop.name();
        if (propName == "objectName")
            continue;
        QDomNodeList nodes = root.elementsByTagName(propName);
        if (nodes.length() < 1)
            continue;
        QDomNode node = nodes.at(0);
        // QVariant value = this->property(prop.name());
        QString v = node.toElement().text();
        o->setProperty(prop.name(), QVariant(v));
    }
    return o;
}

#endif // IDOMSERIALIZABLE
