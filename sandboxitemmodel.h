#ifndef SANDBOXITEMMODEL_H
#define SANDBOXITEMMODEL_H

#include <QStandardItemModel>
#include <QStandardItem>

class SandBoxItemModel : public QStandardItemModel
{

public:
    SandBoxItemModel(QObject* parent = 0);
    ~SandBoxItemModel();

    void setSandBoxDetails(QString names);
    void populateSandBoxes(const QStringList &names);
    void createDirectoryItem(QString dirName, QStandardItem *parentItem = NULL);

private:
    QStandardItem *rootItem;
    QIcon dirIcon;
    QIcon fileIcon;
};

#endif // SANDBOXITEMMODEL_H
