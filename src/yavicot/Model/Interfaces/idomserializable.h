#ifndef IDOMSERIALIZABLE
#define IDOMSERIALIZABLE

#include <QDomDocument>

/*!
 * \brief IDomSerializable interface
 * Descendants must override Serialize() and Deserialize()
 */
class IDomSerializable
{
public:
    /*!
     * \brief Serialize virtual method
     * Meant to serialize a descendant object to XML
     * \param doc Root document
     * \return Link to a serialized DOM element
     */
    virtual QDomElement& Serialize(QDomDocument& doc) = 0;

    /*!
     * \brief Deserialize virtual method
     * Meant to create an object from XML
     * \param self Node to deserialize
     * \return Link to a newly created object
     */
    virtual IDomSerializable& Deserialize(QDomElement& self) = 0;
};

#endif // IDOMSERIALIZABLE

