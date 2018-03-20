import QtQuick 2.0

Item {

Row {//line 2
    anchors.fill: parent
            id:line_2
            spacing: 0
            Repeater {
                id: repeaterLabel
                model:staticFields
                Item{
                    height: parent.height
                    width: parent.width/repeaterLabel.count;
//                    Rectangle {
//                        height: 1
//                        width: parent.width
//                        color: colorTwo
//                        anchors.bottom: parent.bottom

//                    }
                    Text {
                        color: colorGreyA
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        anchors.fill: parent
                        font.pixelSize:fontSize
                        text: staticFields[index]
                    }
                }
            }
        }
}
