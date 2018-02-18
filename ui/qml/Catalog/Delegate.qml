import QtQuick 2.0
import QtQuick.Controls 2.0
import "../components"

Item {

    property int indexItem: model.index;
    property real wd:parent.width-2
    property real hg
    property bool rdOnly: false

    property variant placeHolderList: modelCatalog.getLegendListReport()
    signal onChange(int index, string value);


    id: thisRootItem
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
        //padding: 2

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
                text: id +" "+ name
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
                model:staticFields
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
                        text: staticFields[index]
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
                model: reportFields
                Row{
                    height: parent.height
                    width: parent.width/repeaterEditLine.count
                    TextField {
                        id:editField
                        readOnly: rdOnly
                        inputMethodHints: Qt.ImhFormattedNumbersOnly
                        Item{
                            id:checkBox
                            height: parent.height-1
                            width: parent.height-1
                            z:2
                            anchors.left: parent.left
                            enabled: t7(index)
                            visible:   t7(index)
                            //CheckBox{z:3;anchors.fill: parent}
                            PressBox{z:3;anchors.fill: parent;anchors.bottomMargin: 1}

                        }
                        background:
                            Item{
                            anchors.fill: parent
                            Rectangle{
                                height: editField.focus?2:1
                                width: parent.width
                                color: editField.focus?"royalblue":colorTwo
                                anchors.bottom: parent.bottom

                            }
                        }


                        height: parent.height
                        width: parent.width
                        color: editField.focus?"royalblue":colorTwo
                        horizontalAlignment: TextInput.AlignRight
                        font.pixelSize: focus?fontSize*1.25:fontSize
                        font.italic: false
                        font.bold: editField.focus?true:false
                        font.family: "Verdana"
                        maximumLength: 6
                        placeholderText: placeHolderList[index]
                        text: reportFields[index]
                        rightPadding: 5
                        bottomPadding: 1
                        leftPadding: 1
                        topPadding: 1
                        onPressed: {list.height = 400}
                        //onPressed: {list.positionViewAtIndex(indexItem, ListView.End)}
                        //onEditingFinished: {
                        //    modelCatalog.editReportField(indexItem,index,text)}
                    }
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
    function dbg(arg)
    {
        console.log(arg)
        return arg
    }
}
