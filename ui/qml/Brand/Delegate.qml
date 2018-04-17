import QtQuick 2.0

Item {

    height: 50
    width: parent.width

    Rectangle{
        color: "blue"
        height: parent.height
        width: parent.width

        Component.onCompleted:{
                          console.log(width,height,2222)
                      }
    }
    Text {
        anchors.fill: parent
        text: modelData
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 15//fontSize
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            console.log(1001)
        }
    }


}
