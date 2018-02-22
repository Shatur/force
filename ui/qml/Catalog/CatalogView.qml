import QtQuick 2.9
import "../components"

Item{
    id: catalog
    property string keyboardType: "general"//for SettingPanel
    property int indexCurrentItem: 0//активний ітем у каталозі на даний час
    property string colorOne:"#fff"
    property string colorTwo:"#000"
    property string colorThree:"royalblue"
    property string colorFour: "#2980b9"
    property real fontSize: 14


    Rectangle
    {
        id: bakcground
        anchors.fill: parent
        color: colorOne
    }


    ListView {
        id: list
        width: parent.width
        height:  parent.height
        spacing: 5
        header: Header{z:6}
        headerPositioning: ListView.OverlayHeader
        model: modelCatalog
        delegate: Delegate{}
        //delegate: Delegate{onFieldTextEdited: doubleEditRoot.setText(text)}

    }

    SettingPanel{}
    //DoubleEdit{id: doubleEditRoot}
}//
