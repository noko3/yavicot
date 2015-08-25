#include "project.h"
#include "../../strings.h"

enum Project::ElementType : int {
    eUnknownElement,
    eYaviProject,
    eComment,
    eMediaItems,
    eMedia,
    eRenderers,
    eRenderer,
};

std::map<QString, Project::ElementType> _elementName = {
    {"YaviProject", eYaviProject},
    {"Comment",     eComment},
    {"MediaItems",  eMediaItems},
    {"Media",       eMedia},
    {"Renderers",   eRenderers},
    {"Renderer",    eRenderer}
};

QDomElement& Project::Serialize(QDomDocument& doc) {
    QDomElement pro = doc.createElement("YaviProject");
    pro.setAttribute("Name", Name);
    QDomElement com = doc.createElement("Comment");
    com.appendChild(doc.createTextNode(Comment));
    pro.appendChild(com);
    if (MediaItems.count()) {
        auto mItems = doc.createElement("MediaItems");
        foreach (auto media, MediaItems) {
            mItems.appendChild(media.Serialize(doc));
        }
        pro.appendChild(mItems);
    }
    if (Renderers.count()) {
        auto rSets = doc.createElement("Renderers");
        foreach (auto renderer, Renderers) {
            rSets.appendChild(renderer.Serialize(doc));
        }
        pro.appendChild(rSets);
    }
    return pro;
}

Project& Project::Deserialize(QDomElement& self) {
    if (self.tagName() != "YaviProject")
        return Empty();
    Project tmp = Empty();
    tmp.Name = self.attribute("Name", tr(Y_UNNAMED_PROJ));
    tmp.Comment = self.firstChildElement("Comment").firstChild().nodeValue();
    QDomElement mItems = self.firstChildElement("MediaItems");
    if (!mItems.isNull() && mItems.childNodes().count()) {
        foreach (QDomNode media, mItems.childNodes()) {
            if (media.nodeType() != QDomNode::ElementNode) continue;
            tmp.MediaItems.append(
                        MediaItem::Deserialize(media.toElement()));
        }
    }
    QDomElement rSets = self.firstChildElement("Renderers");
    if (!rSets.isNull() && rSets.childNodes().count()) {
        foreach (QDomNode renderer, rSets.childNodes()) {
            if (renderer.nodeType() != QDomNode::ElementNode) continue;
            tmp.Renderers.append(
                        RenderOptions::Deserialize(renderer.toElement()));
        }
    }
    return tmp;
}
