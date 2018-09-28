import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3


Item {
    property bool onoff: false
    id: switchMenu
    width: parent.width
    height: 100
    anchors.left: parent.left
    anchors.leftMargin:  1
    anchors.bottom: parent.bottom
    anchors.bottomMargin: 1


    Item{
        id: switchMenuButton
        z:2
        width: 100
        height: 100

        Rectangle{
            color: colorThree
            anchors.fill: parent
            //opacity: 0.3
            radius: onoff? 0: 5
        }

        Image {
            id: imageSwitchMenuButton
            height: parent.height*0.8
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width*0.8
            source: "qrc:/pics/cogwheel.png"

        }
        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: {
                onoff = !onoff
                //toolsLine.enabled = onoff
                //toolsLine.visible = onoff
                showHideToolsLine.start()
                rotationAnimation.start()
            }
        }
    }

    RowLayout{
        id: toolsLine
        x: parent.width -1
        y: switchMenuButton.y

        width: parent.width-switchMenuButton.width-2
        spacing: 0
        Repeater{
            id: idSettingButtonModel
            model: settingButtonsModel
            Rectangle {
                height: 100
                width: (toolsLine.width-switchMenuButton.width)/idSettingButtonModel.count
                color: colorThree
                Layout.fillWidth: true


                Text{
                    anchors.fill: parent
                    text:  model.text
                    color: colorOne
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

    PropertyAnimation{
        id: showHideToolsLine
        target: toolsLine
        properties: "x"
        easing.type: Easing.OutBack
        duration: 350
        from: onoff?switchMenuButton.x-parent.width:switchMenuButton.x+switchMenuButton.width+toolsLine.spacing
        to: onoff?switchMenuButton.x+switchMenuButton.width+toolsLine.spacing:switchMenuButton.x-parent.width
        onStopped: {

        }
    }
    RotationAnimator {
        id: rotationAnimation
        target: imageSwitchMenuButton;
        from: 0;
        to: 360;
        duration: 350
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
        console.log(keyboardType)
    }

    ListModel{
        id: settingButtonsModel
        ListElement{text:"Клавіатура цифрова";source:""}
        ListElement{text:"Клавіатура звичайна";source:""}
        ListElement{text:"Ромір шрифту менше";source:""}
        ListElement{text:"Розмір шрифту більше";source:""}
        //ListElement{text:"5";source:""}
    }

    function textFactor(text){
        var l

        l = text.length
        l = fontSize*(1/l)
        console.log(text,l)
        if (l>1)
            return fontSize
        else
            return fontSize*(l+(l/2))
    }
}
