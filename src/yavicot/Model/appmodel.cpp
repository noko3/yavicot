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
    return 0;
}

void AppModel::RemoveFileFromProject(int itemId)
{

}

void AppModel::LoadProject(QString filename)
{

}

void AppModel::SaveProject(QString filename)
{

}

void AppModel::RenderProject(QString filename)
{

}

