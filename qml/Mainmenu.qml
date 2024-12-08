import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Page
{
    Image {
        id: backgroundimage
        source: "ToMainMenu.png"
        anchors.fill: parent
    }
    Button
    {
        id: playbutton
        width: 100
        height: 50
        text: qsTr("play")
        background: Rectangle {anchors.fill: parent; color: "green"}
        anchors.centerIn: parent
        onClicked: {task.playStartSound();addPage()}
    }
    Button
    {
        id: exitbutton
        width: 100
        height: 50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.margins: 150
        text: qsTr("exit")
        background: Rectangle {anchors.fill: parent; color: "orange"}
        onClicked: Qt.quit()
    }
    Text
    {
        id: welcome
        width: 300
        height: 100
        text : qsTr("Welcome")
        x: 100
        y: 100
        font.pointSize: 40
    }
    Text
    {
        id: record
        text: "record: " + task.getRecord()
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 30
        font.pointSize: 20
    }
    Connections
    {
        target: window
        onCheckRecord: {record.text = "record: " + task.getRecord()}
    }
}
