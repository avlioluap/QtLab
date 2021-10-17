import QtQuick 2.4
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
//import Threads 1.0

Page {

    title: qsTr("Threads")

//    IntroThreadWorker {
//        id: introThreadWorker
//    }

    Column {
        id: column


        Button {
            id: intro_button
            text: qsTr("Intro")
            Layout.fillWidth: true
            onClicked: cThreads.on_intro()
        }

        Button {
            id: communicating_button
            text: qsTr("Communicating between threads")
            Layout.fillWidth: true
        }

        Button {
            id: pools_button
            text: qsTr("Thread pools")
            Layout.fillWidth: true
        }
    }

}
