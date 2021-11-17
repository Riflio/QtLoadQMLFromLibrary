import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("UI From library")

    ColumnLayout {
        id: uiWrapper
        anchors.fill: parent

        Rectangle {
            id: headerWrapper
            Layout.fillWidth: true
            Layout.preferredHeight: 40

            RowLayout {
                anchors.fill: parent

                Rectangle {
                    id: btn1
                    color: "red"
                    Layout.preferredWidth: 60
                    Layout.preferredHeight: 20
                    radius: 10

                    Text {
                        anchors.centerIn: parent
                        text: qsTr("Load UI")
                    }

                    FileDialog {
                        id: uiLibraryFileSelect
                        title: qsTr("Please choose a *.so ui library file")
                        folder: "~"
                        onAccepted: {
                            appCore.loadUILibrary(uiLibraryFileSelect.fileUrls[0]);
                        }
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            uiLibraryFileSelect.visible = true;
                        }
                    }
                }

            }
        }

        Loader { //-- Он будет прогружать UI qml из ресурсов
            id: uiMainLoader
            Layout.fillWidth: true
            Layout.fillHeight: true
            source: appCore.uiMainPath

        }

        Rectangle {
            id: footerWrapper
            Layout.fillWidth: true
            Layout.preferredHeight: 20
        }

    }

}
