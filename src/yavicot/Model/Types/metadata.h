#ifndef METADATA_H
#define METADATA_H

#include <QString>

class Metadata
{
  private:
    int _nPackedItems;
  public:
    bool IsContainer();
    QString ProbeInfo;

    Metadata();
    ~Metadata();
};

#endif // METADATA_H
