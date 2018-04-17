import QtQuick 2.9
import QtQuick.Controls 2.3
import "../components"
import "../Comment"
Item{
    id: catalog
    property real fontSize: Setting.getSetting("fontSize")
    property bool isReadOnly: Catalog.getReadOnlyFlag()

    property string colorFour: "#2980b9"
    property string keyboardType: "general"//for SettingPanel
    property int indexCurrentItem: 0//активний ітем у каталозі на даний час

    property string colorThree:"#002366"
    property string colorOne:"#eee"
    property string colorTwo:"#333"
    property string colorGreyA: "#666666"
    property string colorGreyB: "#999999"
    property string colorGreyC: "#cccccc"

    signal qmlSignal(string message)

    Rectangle
    {
        id: bakcground
        width: 1
        anchors.fill: parent
        color: colorGreyC
    }
    PickList{
        id: pickList

    }
    Loader{
        id:loader
        height:  parent.height-pickList.height
        y: pickList.height
        width: parent.width
    }

    Component{
        id:comp2
        Rectangle{}
    }

    Component{
        id: comp

        ListView {
            id: list
            width: parent.width
            height:  parent.height
            spacing: fontSize/4
            header: Header{z:6}
            headerPositioning: ListView.OverlayHeader
            model: Catalog
            delegate: Delegate{}
        }
    }
    BottomNavigation{
        id: navigationLine
        width: parent.width
        height: parent.height*0.066
        anchors.bottom:   loader.bottom
    }
   SettingPanel{
        height: parent.height*0.066
        anchors.bottom:    navigationLine.top
    }

  CommentView{
      id: commentView
        height: parent.height
        width: parent.width
    }
    Component.onCompleted: {
        listPick()
       // console.log(300)
    }

    //DoubleEdit{id: doubleEditRoot}
    function listPick(){
        Catalog.changeCatalogList()
        loader.sourceComponent = comp2
        loader.sourceComponent = comp
        pickList.stackStatus ="   " + Catalog.getStackStatus()
        pickList.namelist =   Catalog.getListName()
    }
}

