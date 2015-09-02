#include "appmodel.h"

AppModel* AppModel::_instance = NULL;

AppModel::AppModel()
{
    //this->_project = Project::Empty();
    this->_activeProjectFilename = "";
    this->_project = new Project();
}

AppModel *AppModel::Instance()
{
    // #TODO thread safety
    if (!_instance)
        _instance = new AppModel();
    return _instance;
}

int AppModel::AddFileToProject(QString filename)
{
    QMimeDatabase db;
    QMimeType mime = db.mimeTypeForFile(filename);

    qDebug() << __FILE__ << " at " << __LINE__;
    qDebug() << "---- AddFileToProject( " << filename << " );";
    qDebug() << "---- Mime type: " << mime << "\n";

    MediaItem *media = new MediaItem();
    media->setFilename(filename);
    media->setMimeType(mime);
    this->_project->MediaItems().append(media);

    return this->_project->MediaItems().count() - 1;
}

void AppModel::RemoveFileFromProject(int itemId)
{

}

void AppModel::LoadProject(QString filename)
{
    qDebug() << __FILE__ << " at " << __LINE__;
    qDebug() << "---- LoadProject( " << filename << " );";

    QFile fp(filename);
    if (!fp.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "---- unable to open" << filename;
        return;
    }
    QString str = fp.readAll();

    _project = XMLSerializer::Deserialize<Project>(str);
    qDebug() << "---- Project.Name == \"" << _project->Name() << "\"";
    qDebug() << "---- Project.Comment == \"" << _project->Comment() << "\"";

    fp.close();
}

void AppModel::SaveProject(QString filename)
{
    qDebug() << __FILE__ << " at " << __LINE__;
    qDebug() << "---- SaveProject( " << filename << " );";

    QString str = XMLSerializer::Serialize(AppModel::Instance()->_project);
    QFile fp(filename);
    if (!fp.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "---- unable to open" << filename;
        return;
    }
    fp.write(str.toStdString().c_str());
    fp.close();
    qDebug() << "---- ::" << str;
    //delete str;
}

void AppModel::RenderProject(QString filename)
{
    qDebug() << __FILE__ << " at " << __LINE__;
    qDebug() << "---- RenderProject( " << filename << " );";
}

