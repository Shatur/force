import QtQuick 2.9
import QtQuick.Controls 2.3
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

    width: 800
    height: 800
    Rectangle
    {
        id: bakcground
        width: 1
        anchors.fill: parent
        color: colorOne
    }

    Rectangle{
        x:10
        y:10
        z:10
        height: 50
        width: 50
        color: "red"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                modelCatalog.changeCatalogList()
                loader.sourceComponent = comp2
                loader.sourceComponent = comp
            }
        }

    }
    Loader{
        width: 800
        height: 800
        id:loader

    }
    Component{
        id:comp2
        Rectangle{}
    }

    Component{
        id: comp
        //width: parent.width
        //height:  parent.height

        ListView {
            id: list
            width: parent.width
            height:  parent.height
            spacing: 2
            footer: Rectangle{
                height: 100;
                width: parent.width
                color: "green"
                z:6}
            footerPositioning: ListView.OverlayFooter
            header: Header{z:6}
            headerPositioning: ListView.OverlayHeader
            model: modelCatalog
            delegate: Delegate{}
            //displayMarginEnd: 200
            //delegate: Delegate{onFieldTextEdited: doubleEditRoot.setText(text)}

        }
    }
    //SettingPanel{}
    //DoubleEdit{id: doubleEditRoot}
}

