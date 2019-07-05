import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    id: windows
    visible: true
    width: 480
    height: 480
    title: qsTr("Find Multiple Entries")
    signal qmlSignal(string msg)

    function showResults(num){
        btnResult.text = num
    }

    Item{
        id:itemInput
        width: parent.width; height: parent.height
        //signal qmlSignal(string msg)

        ScrollView{
            id:textScroll
            width: parent.width; height: parent.height
            ScrollBar.vertical.width : 20
            ScrollBar.horizontal.height : 20

            TextArea{
                id:textInput
                width: parent.width; height: parent.height
                text : "Enter your text here"
                selectByMouse: true
                onTextChanged: windows.qmlSignal(textInput.text)
            }
        }
    }

    Rectangle{
        id:btnBox
        width:60 ; height: 60
        anchors.right : itemInput.right
        anchors.top: windows.top
        color: "#00000000"
        RoundButton{
            id: btnResult
            width: 40; height: 40
            text: "10"
            padding: 10
            contentItem: Text {
                    text: btnResult.text
                    font: btnResult.font
                    opacity: enabled ? 1.0 : 0.3
                    color: "white"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }

                background: Rectangle {
                    implicitWidth: btnResult.width
                    implicitHeight: btnResult.height
                    opacity: enabled ? 1 : 0.3
                    color: "#FF6847"
                    border.width: 0
                    radius: 20
                }
        }
    }


}
