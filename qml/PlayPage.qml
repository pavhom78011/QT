import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Page
{
    function compare()
    {
        if(task.getAnswer() === playerAnswer.text && taskstr.text !== "Tap next to start")
        {
            task.incScore()
            score.text = task.getScore()
            task.playSoundYes()
        }
        else if(taskstr.text !== "Tap next to start")
        {
            task.playSoundNo()
        }
    }
    function deleteLetter()
    {
        if(playerAnswer.text.length > 0)
        {
            taskstr.text = taskstr.text.slice(0,-1)
            playerAnswer.text = playerAnswer.text.slice(0,-1)
        }
    }
    function timerNotZero()
    {
        if(time.text === "0")
        {
            popPage()
            task.setScoreInRecord()
            checkRecord()
            task.returnValues()
        }
    }
    Text
    {
        id: taskstr
        text: qsTr("Tap next to start");
        anchors.centerIn: parent
        font.pointSize: 20
    }
    Text
    {
        id: score
        text: qsTr("0")
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 40
    }
    Text
    {
        id:playerAnswer
        text: qsTr("")
        visible: false
    }
    Text
    {
        id: time
        font.pointSize: 30
        text: qsTr("60")
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 10
    }
    Button
    {
        id: back
        width: 100
        height: 50
        text: qsTr("back")
        anchors.bottom: parent.bottom
        onClicked: {popPage();task.setScoreInRecord();checkRecord();task.returnValues();task.saveRecord()}
    }
    Button
    {
        id: next
        width: 100
        height: 50
        text: qsTr("next")
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        onClicked: {compare();playerAnswer.text = qsTr("");taskstr.text = task.getTask();timer.running = true}
    }
    Repeater
    {
        id: repeater
        model: 10
        Button
        {
            width: 70
            height: 70
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.margins: 10
            anchors.leftMargin: 25 + 70 * (index % 5)
            anchors.bottomMargin: 140 - 70 * Math.floor(index / 5)
            text: index % 10
            onClicked: {taskstr.text += index % 10;playerAnswer.text += index % 10}
        }
    }
    Button
    {
        width: 70
        height: 50
        text: qsTr("-")
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 20
        onClicked: {taskstr.text += "-";playerAnswer.text += "-"}
    }
    Button
    {
        width: 140
        height: 50
        text: qsTr("delete letter")
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        onClicked: deleteLetter()
    }
    Timer
    {
        id: timer
        interval: 1000
        repeat: true
        onTriggered: {task.decTime();time.text = task.getTime();timerNotZero()}
    }
}
