import QtQuick 2.7
import QtQuick.Controls 1.5

ApplicationWindow {
    visible: true
    width: 480
    height: 480
    title: qsTr("QML TreeView")

    TreeView {
        anchors.fill: parent
        TableViewColumn {
            role: "display"
        }
        model: sandBoxModel
    }
}
