import QtQuick 2.9
import QtQuick.Controls 2.3
import "../components"

Item{
    id: catalog
    property real fontSize: 14
    property string keyboardType: "general"//for SettingPanel
    property int indexCurrentItem: 0//активний ітем у каталозі на даний час
    property string colorOne:"#eee"
    property string colorTwo:"#333"
    property string colorThree:"royalblue"
    property string colorFour: "#2980b9"
    property string colorGreyA: "#666666"
    property string colorGreyB: "#999999"
    property string colorGreyC: "#cccccc"

    Rectangle
    {
        id: bakcground
        width: 1
        anchors.fill: parent
        color: colorOne
    }
//Column{
//        anchors.fill: parent
//    PickList{
//        id: pickList

//    }
//    Loader{
//        id:loader
//    }
//}
//    Component{
//        id:comp2
//        Rectangle{}
//    }

//    Component{
//        id: comp

        ListView {
            id: list
            width: parent.width
            height:  parent.height
            spacing: fontSize/4
            header: Header{z:6}
            headerPositioning: ListView.OverlayHeader
            model: modelCatalog
            delegate: Delegate{}

        }
   // }
    Component.onCompleted: {
        console.log(height,width)
        listPick()
    }

    //SettingPanel{}
    //DoubleEdit{id: doubleEditRoot}
    function listPick(){
        modelCatalog.changeCatalogList()
        loader.sourceComponent = comp2
        loader.sourceComponent = comp
        pickList.stackStatus ="   " + modelCatalog.getStackStatus()
        pickList.namelist =   modelCatalog.getListName()
    }
}

