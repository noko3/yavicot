#include "project.h"
#include "../../strings.h"

Project::Project(QObject *parent)
{
    setName("Untitled project");
    setComment("This is a comment for your project");
    return;
}
