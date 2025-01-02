import QtQuick 2.15
import QtQuick.Controls 2.15
import TopicControl 1.0

Dialog {
    id: root

    required property TopicControl topicControl

    anchors.centerIn: parent
    dim: true
    height: 250
    title: "Criar"
    visible: false
    width: 300

    Column {
        anchors.centerIn: parent
        spacing: 16

        TextField {
            id: name

            placeholderText: "Nome"
            width: parent.width
        }

        TextField {
            id: date

            placeholderText: "Data"
            width: parent.width
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10

            Button {
                text: "Cancelar"

                onClicked: {
                    root.close();
                }
            }

            Button {
                text: "Salvar"

                onClicked: {
                    topicControl.doSave(name.text, date.text);
                    root.close();
                }
            }
        }
    }
}
