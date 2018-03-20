import QtQuick 2.0

Item {
    property string namelist: ""
    property string stackStatus: ""
    width: parent.width
    height: fontSize*5
    z:10
    Rectangle{
        anchors.fill:parent
        color: colorOne
        Text{
            anchors.fill: parent
            height: fontSize*1.5
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
        }

    }
}
