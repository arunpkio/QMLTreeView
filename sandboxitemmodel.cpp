#include <QDir>
#include <QDirIterator>

#include "sandboxitemmodel.h"

SandBoxItemModel::SandBoxItemModel(QObject *parent)
    :QStandardItemModel(parent)
{
    rootItem = this->invisibleRootItem();
}

SandBoxItemModel::~SandBoxItemModel()
{

}

/*
 Folder locations are parsed from the file which are seperated by new lines.
*/
void SandBoxItemModel::setSandBoxDetails(QString names)
{
    populateSandBoxes(names.split("\n"));
}

/*
 method to populate the contents of the sandboxes parsed from the file.
*/
void SandBoxItemModel::populateSandBoxes(const QStringList &names)
{
    QString name;
    QStandardItem* parent;

    foreach (name, names) {
        if(!name.isEmpty())
        {
            name.remove("\r");
            parent = new QStandardItem(dirIcon ,name);  //create the parent directory item
            parent->setAccessibleDescription(name);     //set actual path to item
            rootItem->appendRow(parent);                //add the parent item to root item
            createDirectoryItem(name, parent);          //Iterate and populate the contents
        }
    }
}

/*
  Method to populate the contents of the given directory in recursive manner.
  Each found child will be appended to its parent item.
  Files & folders will be using its own standard icons  from current style.
  child->setAccessibleDescription() is used to set the actual path of the item
  which will be useful.

*/
void SandBoxItemModel::createDirectoryItem(QString dirName, QStandardItem *parentItem)
{
    QDir dir(dirName);
    QFileInfoList subFolders;
    QFileInfo folderName;
    QStandardItem* child;
    subFolders = dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);    //get all the sub folders
    foreach (folderName, subFolders)
    {
        if(folderName.isFile())
        {
            child = new QStandardItem(fileIcon, folderName.fileName());                 //Append a file
            child->setAccessibleDescription(folderName.filePath());                     //set actual path to item
        }
        else
        {
            child = new QStandardItem(dirIcon, folderName.fileName());                  //Append a folder
            child->setAccessibleDescription(folderName.filePath());                     //set actual path to item
        }
        parentItem->appendRow(child);
        createDirectoryItem(folderName.filePath(), child);                              //Recurse its subdirectories
    }
}
