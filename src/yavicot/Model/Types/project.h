#ifndef PROJECT_H
#define PROJECT_H

#include <QList>
#include <QString>
#include <map>
#include <stdexcept>
#include "../Interfaces/idomserializable.h"
#include "mediaitem.h"
#include "renderoptions.h"

class Project : public IDomSerializable {
  private:
    enum ElementType : int;
    static std::map<QString, ElementType> _elementName;
  public:
    QString Name;
    QString Comment;
    // ProjectSettings Settings;
    QList<MediaItem> MediaItems;
    QList<RenderOptions> Renderers;

    Project& Empty() {
        Project *tmp = new Project();
        tmp->Name = tr("New project");
        tmp->Comment = "";
        return *tmp;
    }
};

#endif // PROJECT_H

