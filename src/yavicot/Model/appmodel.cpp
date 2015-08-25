#include "appmodel.h"

AppModel* AppModel::_instance = NULL;

AppModel::AppModel()
{
    //this->_project = Project::Empty();
    this->_activeProjectFilename = "";
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

    return 0;
}

void AppModel::RemoveFileFromProject(int itemId)
{

}

void AppModel::LoadProject(QString filename)
{
    qDebug() << __FILE__ << " at " << __LINE__;
    qDebug() << "---- LoadProject( " << filename << " );";
}

void AppModel::SaveProject(QString filename)
{
    qDebug() << __FILE__ << " at " << __LINE__;
    qDebug() << "---- SaveProject( " << filename << " );";
}

void AppModel::RenderProject(QString filename)
{
    qDebug() << __FILE__ << " at " << __LINE__;
    qDebug() << "---- RenderProject( " << filename << " );";
}

