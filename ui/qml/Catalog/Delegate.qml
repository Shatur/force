import QtQuick 2.0
import QtQuick.Controls 2.0
import "../components"

Item {

    property int indexItem: model.index

    property real wd:parent.width-2
    property real hg
    property bool rdOnly: false

    property variant placeHolderList: modelCatalog.getLegendListReport()
    signal onChange(int index, string value);
    signal fieldTextEdited(variant text)




    id: thisRootItem
    x:1
    y:1

    width: parent.width-2
    height: (fontSize*15)
    //height: width*0.38
    Rectangle{
        id: backRect
        color:colorOne
        anchors.fill: parent

        MouseArea{
            anchors.fill: parent
            z:4
            onClicked: {
                indexCurrentItem = indexItem
            }
        }
    }

    Column{
        id: mainColumn
        anchors.fill: parent
        spacing: 1
        //padding: 2

        Item{//line 1
            id: lineOne
            height: (parent.height-(mainColumn.spacing*2)-(mainColumn.padding*2))/3
            width: parent.width-(parent.padding*2)

            Rectangle {
                height: (indexItem === indexCurrentItem)?3:1
                width: parent.width
                color: (indexItem === indexCurrentItem)?colorThree:colorTwo
                anchors.bottom: parent.bottom
            }
            Text{
                color: colorTwo
                font.pixelSize: fontSize
                font.bold: (indexItem === indexCurrentItem)?true:false
                anchors.fill: parent
                text: " "+id +" "+ name
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: (indexItem === indexCurrentItem)?Text.AlignLeft:Text.AlignLeft
            }
            Text{
                color: "red"
                font.pixelSize: fontSize*1.17
                font.bold: true
                anchors.right: parent.right
                text: " !!! "
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.Center
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
            spacing: 2
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
                        focus: (indexCurrentItem === indexItem)?true:false
                        readOnly: rdOnly
                        inputMethodHints: (keyboardType === "decimal")?Qt.ImhPreferNumbers:Qt.ImhNone
                        onTextEdited:{
                            fieldTextEdited(text)
                        }
                        Item{
                            id:checkBox
                            height: parent.height-1
                            width: parent.height-1
                            z:2
                            anchors.left: parent.left
                            enabled: t7(index)
                            visible:   t7(index)
                            PressBox{z:3;anchors.fill: parent;anchors.bottomMargin: 1}

                        }
                        background:
                            Item{
                            anchors.fill: parent
                            Rectangle{
                                height: editField.focus?2:1
                                width: parent.width
                                color: editField.focus ?(editField.text==="")?"red":"royalblue" :(editField.text==="")?"red":colorTwo
                                anchors.bottom: parent.bottom

                            }
                        }

                        height: parent.height
                        width: parent.width
                        color: editField.focus?colorThree:colorTwo
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
                        onPressed:
                        {
                            indexCurrentItem = indexItem
                        }
                        onAccepted:  {
                            modelCatalog.editReportField(indexItem,index,text)
                        }
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
