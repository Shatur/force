import QtQuick 2.0

Item {
    id: pressBoxRoot
    property bool press: false
    property real sizeFactor: 0.75

    Rectangle{
        id: outer
        height: parent.height
        width: parent.width
        border.color: press?"royalblue":"black"
        border.width: press?2:1
        radius: 5
        color: inner.visible?"white":"transparent"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                pressBoxRoot.enabled = false
                press = !press
                anm.start()
                glowStart(press)
            }
        }
    }
    Rectangle{
        id: inner
        anchors.centerIn: outer
        height: 0
        width: 0
        color: "royalblue"
        radius: 5

        Text {
            anchors.centerIn: parent
            text: "+"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: inner.height*sizeFactor
            color: "white"
        }
    }
    Rectangle{
        id: innerGlow
        anchors.centerIn: outer
        height: 0
        width: 0
        color: "royalblue"
        radius: 5

        Text {
            anchors.centerIn: parent
            text: "+"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: innerGlow.height*sizeFactor
            color: "white"
        }
    }


    PropertyAnimation{
        id: anm
        target: inner
        properties: "height,width"
        easing.type: Easing.OutBack
        duration: 350
        from: !press?pressBoxRoot.height:0
        to: !press?0:pressBoxRoot.height*sizeFactor
        onStopped: {
            pressBoxRoot.enabled = true
        }
    }
    PropertyAnimation{
        id: anmGlow
        target: innerGlow
        properties: "height,width"
        easing.type: Easing.Linear
        duration: 300
        from: inner.height
        to: inner.height*1.4
    }
    PropertyAnimation{
        id: anmGlowOpacity
        target: innerGlow
        property: "opacity"
        easing.type: Easing.Linear
        duration: 300
        from: 1
        to: 0
    }

    function glowStart(val){
        //console.log(val)
        if (!val){
            anmGlow.start()
            anmGlowOpacity.start()
        }
    }
}
