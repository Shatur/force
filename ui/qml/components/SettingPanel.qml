import QtQuick 2.9
import QtQuick.Controls 2.2


Item {
    property bool onoff: false
    id: switchMenu
    anchors.fill: parent

    onYChanged: {
        console.log(y)
        list.height = y
    }

    Item{
        id: switchMenuButton
        z:2
        width: fontSize*2.5
        height: fontSize*2.5
        anchors.left: parent.left
        anchors.leftMargin:  1
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 1
        Rectangle{
            color: onoff?colorFour:colorThree
            anchors.fill: parent
            //opacity: 0.3
            radius: onoff? 0: 5
        }

        Image {
            id: name
            height: parent.height*0.8
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width*0.8

            source: "qrc:/ui/art/cogwheel.png"
        }
        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: {
                onoff = !onoff
                //toolsLine.enabled = onoff
                //toolsLine.visible = onoff
                showHideToolsLine.start()
            }
        }
    }

    Row{
        id: toolsLine
        x: -parent.width -1
        y: switchMenuButton.y
        height: fontSize*2.5
        width: parent.width
        spacing: 0
        Repeater{
            id: idSettingButtonModel
            model: settingButtonsModel
            Rectangle {
                height: parent.height
                width: (parent.width-switchMenuButton.width-4-(toolsLine.spacing*(idSettingButtonModel.count-1))-(toolsLine.spacing*2))/idSettingButtonModel.count
                color: colorThree


                Text{
                    anchors.fill: parent
                    text: model.text
                    color: colorOne
                    wrapMode: Text.WordWrap
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        clickedCurent(index)
                    }

                    onPressed:  {
                        parent.color = colorFour
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

    function clickedCurent(index){
        console.log(index)
    }

    ListModel{
        id: settingButtonsModel
        ListElement{text:"Клавіатура цифрова";source:""}
        ListElement{text:"Клавіатура звичайна";source:""}
        ListElement{text:"Ромір шрифту менше";source:""}
        ListElement{text:"Розмір шрифту більше";source:""}
        //ListElement{text:"5";source:""}
    }
}
