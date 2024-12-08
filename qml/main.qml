import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window
{
    signal checkRecord()
    id: window
    width: 400
    height: 500
    visible: true
    title: qsTr("Game")
    function addPage()
    {
        stack.push(playpage)
    }
    function popPage()
    {
        stack.pop();
    }
    Mainmenu
    {
        id: mainmenu
    }
    Component
    {
        id: playpage
        PlayPage {}
    }
    StackView
    {
        id: stack
        visible: true
        initialItem: mainmenu
        anchors.fill: parent
    }
}
