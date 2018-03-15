import QtQuick 2.0
import QtQuick.Controls 2.0
import "../Catalog/DelegateComponents"
import "../components"

Item {

    property int indexItem: model.index

    property real wd:parent.width-2
    property real hg
    property bool rdOnly: false
    property bool goodJob: modelCatalog.goodJobDot(indexItem)

    property variant placeHolderList: modelCatalog.getLegendListReport()
    signal onChange(int index, string value);
    signal fieldTextEdited(variant text)

    id: delegateRoot
    x:3
    y:1

    width: parent.width-6
    height: (fontSize*20)
    //height: width*0.38
    Rectangle{
        id: backRect
        color:"#ddd"
        opacity: goodJob?0.3:1
        radius: 5
        anchors.fill: parent
        border.color: colorThree

        MouseArea{
            anchors.fill: parent
            z:4
            onClicked: {
                indexCurrentItem = indexItem
            }
        }
    }
      Rectangle{
          id:goodJobRect
            height: fontSize/2
            width: fontSize/2
            radius: fontSize/2
            color: goodJob?"transparent":"red"
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.topMargin: fontSize/2
            anchors.rightMargin: fontSize/2
        }

    Column{
        id: mainColumn
        anchors.fill: parent

        Item{
            width: parent.width
            height: parent.height*0.62
            LineFirst{
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: -height
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
                height: fontSize*2
            }

            LineSecond{
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: height
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
                height: fontSize
            }
        }

        LineThree{
            width: parent.width
            height: parent.height*0.38
        }


    }
    function t7(index)
    {
        if(reportTypes[index] === "7")
            return  true;
        else
            return false;
    }
    function dbg(arg)
    {
        console.log(arg)
        return arg
    }
}
