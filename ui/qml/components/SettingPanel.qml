import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3


Item {
    property bool onoff: false
    id: switchMenu
    z:parent.z+1
    //height: 100
    width: parent.width

    Item{
        id: switchMenuButton
        height: parent.height
        width: height

        Rectangle{
            color: onoff?colorOne:"transparent"
            anchors.fill: parent

        }

        Image {
            id: imageSwitchMenuButton
            scale: 0.7
            anchors.fill: parent
            anchors.centerIn: parent
            source: "qrc:/ui/art/settings.svg"

        }
        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: {
                onoff = !onoff
                showHideToolsLineBottom.start()
                showHideToolsLineTop.start()
                showHideToolsLine.start()
                rotationAnimation.start()
            }
        }
    }

    Item{
        id: toolsLine
        x: parent.width -1
        y: switchMenuButton.y

        height: switchMenu.height
        width: parent.width-switchMenuButton.width
        Rectangle{
            id: topLine
            x: parent.width
            height: 2
            width: parent.width+switchMenuButton.width
            color:colorGreyA
            z: parent.z+1
            anchors.top: parent.top

        }
        Rectangle{
            id:bottomLine
            x: parent.width
            height: 2
            width: parent.width+switchMenuButton.width
            color:colorGreyA
            z: parent.z+1
            anchors.bottom:  parent.bottom
            anchors.bottomMargin: -height

        }

        Row{
            anchors.fill: parent
            Repeater{
                id: idSettingButtonModel
                model: settingButtonsModel
                Rectangle {
                    height: toolsLine.height
                    width: toolsLine.width/idSettingButtonModel.count
                    color: colorGreyC
                    Text{
                        anchors.fill: parent
                        text:  model.text
                        color: colorThree
                        wrapMode: Text.WordWrap
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: textFactor(model.text)
                    }
                    MouseArea{
                        anchors.fill:parent
                        onClicked: {
                            clickedCurent(index)
                        }
                        onPressed: {
                            parent.width = parent.width + 5
                            parent.height = parent.height +5
                        }
                        onReleased:  {
                            parent.width = parent.width - 5
                            parent.height = parent.height - 5
                        }
                    }
                }
            }
        }
    }
    PropertyAnimation{
        id: showHideToolsLineBottom
        target: bottomLine
        properties: "x"
        easing.type: Easing.Linear
        duration: 550
        from: onoff?parent.width:-switchMenuButton.width
        to:onoff?-switchMenuButton.width:parent.width
    }
    PropertyAnimation{
        id: showHideToolsLineTop
        target: topLine
        properties: "x"
        easing.type: Easing.Linear
        duration: 350
         from: onoff?parent.width:-switchMenuButton.width
        to:onoff?-switchMenuButton.width:parent.width
    }
    PropertyAnimation{
        id: showHideToolsLine
        target: toolsLine
        properties: "x"
        easing.type: Easing.OutBack
        duration: 450
         from: onoff?parent.width:switchMenuButton.width
        to:onoff?switchMenuButton.width:parent.width
    }
    RotationAnimator {
        id: rotationAnimation
        target: imageSwitchMenuButton;
        from: 0;
        to: 360;
        duration: 450
    }

    function clickedCurent(index){
        if (index === 0)
            keyboardType ="decimal"
        if (index === 1)
            keyboardType ="literal"
        if (index === 2)
            fontSize = fontSize-1
        if (index === 3)
            fontSize = fontSize+1
        Setting.setSetting("fontSize="+fontSize)

    }

    ListModel{
        id: settingButtonsModel
        ListElement{text:"Клавіатура Ц";source:""}
        ListElement{text:"Клавіатура Т";source:""}
        ListElement{text:"Шрифт -";source:""}
        ListElement{text:"Шрифт +";source:""}
        //ListElement{text:"5";source:""}
    }

    function textFactor(text){
        var l

        l = text.length
        l = fontSize*(1/l)
        //console.log(text,l)
        if (l>1)
            return fontSize
        else
            return fontSize*(l+(l/2))
    }
}
