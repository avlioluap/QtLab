import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
    width: 600
    height: 400

    title: qsTr("Threads")

    Column {
        id: column
        x: 0
        y: 0
        width: 595
        height: 400

        Button {
            id: intro_button
            text: qsTr("Intro")
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.topMargin: 1
        }

        Button {
            id: communicating_button
            text: qsTr("Communicating between threads")
            anchors.top: intro_button.bottom
            anchors.topMargin: 1
            anchors.leftMargin: 0
            anchors.left: parent.left
            anchors.right: parent.right
        }

        Button {
            id: pools_button
            text: qsTr("Thread pools")
            anchors.top: communicating_button.bottom
            anchors.topMargin: 1
            anchors.left: parent.left
            anchors.right: parent.right
        }
    }
}
