import QtQuick 2.0

Item {
    property bool onoff: false
    property string mainText: "121"
    id: switchMenu
    width: parent.width
    height: fontSize*3
    anchors.left: parent.left
    anchors.leftMargin:  1
    anchors.bottom: parent.bottom
    anchors.bottomMargin: 1

    Text{
        anchors.fill:parent
        font.pixelSize: fontSize*2.5
        text: mainText
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        color: colorThree

    }
    function setText(text){
        mainText = text
    }

}
//Призначення: дублює вміст поля редагування в каталозі
