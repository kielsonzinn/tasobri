import QtQuick 2.15
import TopicControl 1.0

Item {
    required property TopicControl topicControl

    anchors.fill: parent
    anchors.margins: 24

    Item {
        anchors.fill: parent

        Column {
            spacing: 16
            width: parent.width

            Repeater {
                id: repeater

                model: topicControl.topics

                Rectangle {
                    color: Qt.rgba(Math.random(255), Math.random(255), Math.random(255))
                    height: 64
                    width: parent.width

                    Column {
                        anchors.left: parent.left
                        anchors.leftMargin: 24
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 8

                        Text {
                            text: modelData.name
                        }

                        Text {
                            text: modelData.currentStreak + " dias"
                        }
                    }
                }
            }
        }
    }
}
