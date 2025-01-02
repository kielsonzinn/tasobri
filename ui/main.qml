import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import TopicControl 1.0

Window {
    height: 480
    title: qsTr("Tásóbri")
    visible: true
    width: 640

    TopicControl {
        id: topicControl

    }

    //TODO CRIAR E RECRIAR O TOPICCREATE E TOPICLIST CONFORME NECESSIDADE
    TopicCreate {
        id: topicCreate

        topicControl: topicControl

        onClosed: {
            topicControl.refresh();
        }
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true

            TopicList {
                id: topicList

                topicControl: topicControl
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 64
            color: Qt.rgba(Math.random(255), Math.random(255), Math.random(255))

            Button {
                anchors.centerIn: parent
                text: "Abrir Modal"

                onClicked: {
                    topicCreate.open();
                }
            }
        }
    }
}
