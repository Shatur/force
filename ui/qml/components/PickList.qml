import QtQuick 2.0

Item {
    property string namelist: ""
    property string stackStatus: ""
    width: parent.width
    height: fontSize*5
    z:7
    Rectangle{
        anchors.fill:parent
        color: colorGreyC
        Text{
            id: idStackStaus
            anchors.fill: parent
            height: fontSize*2
            color: colorGreyB
            font.pixelSize: fontSize
            text:  stackStatus
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
        }

        Text{
            anchors.fill: parent
            height: fontSize*1.5
            color: colorThree
            font.pixelSize: fontSize
            text:  namelist
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                listPick()
            }
            onPressed: {
                idStackStaus.color = colorGreyA
                parent.color = colorGreyB
            }
            onReleased: {
                idStackStaus.color = colorGreyB
                parent.color = colorGreyC
            }

        }
        Rectangle{
            enabled: !commentView.onOff
            height: parent.height
            width: parent.height*0.68
            anchors.right: parent.right
            color: "transparent"
            Image{
                width: parent.width
                height: width
                anchors.centerIn: parent
                source: "qrc:/ui/art/comment.svg"
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    commentView.onOff = !commentView.onOff
                }
            }
        }
    }
}
