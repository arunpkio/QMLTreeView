# QMLTreeView
QMl TreeView with custom folder list model in C++

This application is to demonstrate the use of exposing custom model to QML to be used with the QML TreeView component.

Example Usage in QML:

 TreeView {
        anchors.fill: parent
        TableViewColumn {
            role: "display" //this will show the folder/file name from the model
        }
        model: sandBoxModel
    }


![alt tag](https://cloud.githubusercontent.com/assets/4667704/21970707/1be6c824-dbcf-11e6-9f62-a69aa8fcb369.png)
