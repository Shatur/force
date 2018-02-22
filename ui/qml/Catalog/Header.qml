import QtQuick 2.7
import QtQuick.Controls 2.2


Item {

    x:1
    y:1

    width: parent.width-2
    height: (fontSize*8)
    Rectangle{
        id: backRect
        color:colorOne
        anchors.fill: parent
    }

    Column{
        id: mainColumn
        anchors.fill: parent
        spacing: 1
        padding: 2

        Item{//line 1
            height: (parent.height-(mainColumn.spacing*2)-(mainColumn.padding*2))/3
            width: parent.width-(parent.padding*2)

            Rectangle {
                height: 1
                width: parent.width
                color: colorTwo
                anchors.bottom: parent.bottom
            }
            Text{
                color: colorTwo
                font.pixelSize: fontSize
                font.bold: true
                anchors.fill: parent
                text: modelCatalog.getLegendFirstStatic()
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
            }
        }


        Row {//line 2
            id:line_2
            spacing: 0
            width: parent.width-(parent.padding*2)-(spacing*repeaterLabel.count-1)
            height: (parent.height-(mainColumn.spacing*2)-(mainColumn.padding*2))/3
            Repeater {
                id: repeaterLabel
                model:modelCatalog.getLegendListStatic()
                Item{
                    height: parent.height
                    width: parent.width/repeaterLabel.count;
                    Rectangle {

                        height: 1
                        width: parent.width
                        color: colorTwo
                        anchors.bottom: parent.bottom

                    }
                    Text {
                        color: colorTwo
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
            height: (parent.height-(mainColumn.spacing*2)-(mainColumn.padding*2))/3
            Repeater {
                id: repeaterEditLine
                model: modelCatalog.getLegendListReport()
                Item{
                    height: parent.height
                    width: parent.width/repeaterEditLine.count
                    Rectangle {
                        color:colorOne
                        anchors.fill: parent
                    }
                    Text{
                        color: colorTwo
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        anchors.fill: parent
                        font.pixelSize: textFactor(modelData)
                        text: modelData
                        wrapMode: Text.WordWrap
                    }
                }
            }
        }
    Rectangle{
        x:-2
        height: 3
        width: parent.width+2
        color: colorThree

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
        console.log(text,l)
        if (l>1)
            return fontSize
        else
            return fontSize*(l+(l/2))
    }
}
