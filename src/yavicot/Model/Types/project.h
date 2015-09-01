#ifndef PROJECT_H
#define PROJECT_H

#include <QList>
#include <QString>
#include <map>
#include <stdexcept>
#include "../Interfaces/idomserializable.h"
#include "mediaitem.h"
#include "renderoptions.h"

class Project : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString Name READ Name WRITE setName NOTIFY NameChanged)
    Q_PROPERTY(QString Comment
               READ Comment
               WRITE setComment
               NOTIFY CommentChanged)
//    Q_PROPERTY(QList<MediaItem*> MediaItems
//               READ MediaItems
//               WRITE setMediaItems
//               NOTIFY MediaItemsChanged)
//    Q_PROPERTY(QList<RenderOptions*> Renderers
//               READ Renderers
//               WRITE setRenderers
//               NOTIFY RenderersChanged)
  private:
    enum ElementType {
        eUnknownElement,
        eYaviProject,
        eComment,
        eMediaItems,
        eMedia,
        eRenderers,
        eRenderer,
    };
    static std::map<QString, ElementType> _elementName;

    QString m_Name;
    QString m_Comment;
//    QList<MediaItem*> m_MediaItems;
//    QList<RenderOptions*> m_Renderers;

public:
    explicit Project(QObject *parent = 0);
    Project *Empty() {
        Project *tmp = new Project();
        tmp->setName(tr("New project"));
        tmp->setComment("");
        return tmp;
    }
    QString Name() const
    {
        return m_Name;
    }
    QString Comment() const
    {
        return m_Comment;
    }

//    QList<MediaItem*> MediaItems() const
//    {
//        return m_MediaItems;
//    }

//    QList<RenderOptions*> Renderers() const
//    {
//        return m_Renderers;
//    }

public slots:
    void setName(QString Name)
    {
        if (m_Name == Name)
            return;

        m_Name = Name;
        emit NameChanged(Name);
    }
    void setComment(QString Comment)
    {
        if (m_Comment == Comment)
            return;

        m_Comment = Comment;
        emit CommentChanged(Comment);
    }

//    void setMediaItems(QList<MediaItem*> MediaItems)
//    {
//        if (m_MediaItems == MediaItems)
//            return;

//        m_MediaItems = MediaItems;
//        emit MediaItemsChanged(MediaItems);
//    }

//    void setRenderers(QList<RenderOptions*> Renderers)
//    {
//        if (m_Renderers == Renderers)
//            return;

//        m_Renderers = Renderers;
//        emit RenderersChanged(Renderers);
//    }

signals:
    void NameChanged(QString Name);
    void CommentChanged(QString Comment);
//    void MediaItemsChanged(QList<MediaItem*> MediaItems);
//    void RenderersChanged(QList<RenderOptions*> Renderers);
};

#endif // PROJECT_H

