import QtQuick 2.9
import QtQuick.Controls 2.2

Item {

    height: fontSize*6
    width: parent.width

scale: 0.98
    Column{
        height: parent.height
        width: parent.width
        spacing: 1

        Item{
            width: parent.width
            height: parent.height*0.32
            Rectangle{
                anchors.fill: parent
                color: colorGreyB
            }
            Text{
                font.pixelSize: fontSize
                anchors.fill: parent
                text: dateTime
                rightPadding: fontSize
                padding: 2
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
            }
        }

        Item{
            height: parent.height*0.68
            width: parent.width
            Rectangle{
                anchors.fill: parent
                color: colorOne
            }

            Text{
                font.pixelSize: fontSize
                anchors.fill: parent
                text: textValue
                padding: 2
                leftPadding: fontSize
                font.family: "Verdana"
                wrapMode: Text.WordWrap
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
}
