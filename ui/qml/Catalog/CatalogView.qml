import QtQuick 2.0
import "../components"

Item{
    id: catalog
    property string keyboardType: "general"
    property string colorOne:"#fff"
    property string colorTwo:"#000"
    property string colorThree:"#3498db"
    property string colorFour: "#2980b9"
    property real fontSize:13
    property bool shadowOn: false
    Rectangle
    {
        id: bakcground
        anchors.fill: parent
        color:"#eee"
    }


    ListView {
        id: list
        width: parent.width
        height:  parent.height
        spacing: 2
        // header: Header{z:6}
        //headerPositioning: ListView.OverlayHeader
        model: modelCatalog
        delegate: Delegate{}

    }
    SettingPanel{}
}
