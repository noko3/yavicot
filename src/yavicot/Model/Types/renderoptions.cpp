#include "renderoptions.h"

QDomElement& RenderOptions::Serialize() {
    QDomElement *el = new QDomElement();
    el->setAttribute("Command", Command);
    return *el;
}

RenderOptions& RenderOptions::Deserialize(QDomElement& el) {
    RenderOptions *tmp = new RenderOptions();
    tmp->Command = el.attribute("Command", "true");
    return *tmp;
}
