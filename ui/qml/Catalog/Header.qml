import QtQuick 2.7
import QtQuick.Controls 2.2
import "../components"

Item {
    x:1
    y:1
    width: parent.width-2
    height: (fontSize*5)
    Rectangle{
        id: backRect
        color:colorOne
        anchors.fill: parent
    }
    Rectangle{
        height: 2
        width: parent.width+2
        color:colorGreyB
        anchors.top: mainColumn.top

    }
    Rectangle{
        height: 3
        width: parent.width+2
        color:colorGreyA
        anchors.bottom: mainColumn.bottom

    }
    Column{
        id: mainColumn
        anchors.fill: parent
        spacing: 1
        padding: 2


        Item{//line 1
            height: fontSize*1.5
            width: parent.width

            Rectangle {
                height: 1
                x: fontSize*2
                width: parent.width - (fontSize*4)
                color: colorGreyC
                anchors.bottom: parent.bottom
            }
            Text{
                color: colorGreyA
                font.pixelSize: fontSize
                anchors.fill: parent
                text: Catalog.getLegendFirstStatic()
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }


        Row {//line 2
            id:line_2
            spacing: 0
            width: parent.width-(parent.padding*2)-(spacing*repeaterLabel.count-1)
            height: fontSize*1.5
            Repeater {
                id: repeaterLabel
                model:Catalog.getLegendListStatic()
                Item{
                    height: parent.height
                    width: parent.width/repeaterLabel.count;
                    Rectangle {

                        height: 1
                        x: fontSize
                        width: parent.width - (fontSize*4)
                        color: colorGreyC
                        anchors.bottom: parent.bottom

                    }
                    Text {
                        color: colorGreyA
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        anchors.fill: parent
                        font.pixelSize:fontSize
                        text: modelData
                    }
                }
            }
        }

        Row {//line 3
            id: line_3
            spacing: 1
            width: parent.width-(parent.padding*2)-(spacing*repeaterLabel.count-1)
            height: fontSize*1.5
            Repeater {
                id: repeaterEditLine
                model: Catalog.getLegendListReport()

                Text{
                    height: parent.height
                    width: parent.width/repeaterEditLine.count
                    color: colorGreyA
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: textFactor(modelData)
                    text: modelData
                    wrapMode: Text.WordWrap
                }
            }
        }

    }

    function t7(index)
    {
        if(reportTypes[index] === "7")
            return  true;
        else
            return false;
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
