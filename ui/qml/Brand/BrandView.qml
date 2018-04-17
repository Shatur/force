import QtQuick 2.0

Item {
    Rectangle{
        anchors.fill: parent
    color: "red"
    }

    ListView{
        id: lst
        spacing: 1
        height: parent.height
        width: parent.width
        model: Brand
        delegate: Delegate{}
        Component.onCompleted:{    console.log(height,width)        }
    }
}

