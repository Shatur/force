import QtQuick 2.0
import QtQuick.Controls 2.2


Item {
    property bool onOff: false
    visible: onOff
    enabled: onOff

    Column{
        anchors.fill: parent
        Rectangle{
            width: parent.width
            height: parent.height*0.38
            color: "white"
            TextField{
                id: textTypeHere
                anchors.fill: parent
                font.pixelSize: fontSize
                onAccepted: {
                    textLookHere.text = textTypeHere.text
                }
            }
        }
        Rectangle{
            width: parent.width
            height: parent.height*0.62
            color: "white"
            TextArea{
                id: textLookHere
                font.pixelSize: fontSize
            }
        }
    }
}
