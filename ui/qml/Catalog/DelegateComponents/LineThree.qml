import QtQuick 2.0
import QtQuick.Controls 2.2
import "../../components"

Item {
    property var tts: reportFields

//   ListView{
//       anchors.fill: parent
//       orientation: ListView.Horizontal
//       model: reportFields
//       delegate: Rectangle{
//           height: fontSize*2
//           width: fontSize*4
//           TextField{
//               text: modelData
//               onTextEdited: {
//                   goodJobAccept(index,text)

//               }
//           }
//       }
//   }
//    Rectangle{
 Row {//line 3
            id: line_3
            anchors.fill:parent
            Repeater {
                id: repeaterEditLine
                model: reportFields
                Row{
                    property string _str: editField.text
                    height: parent.height
                    width: parent.width/repeaterEditLine.count
                    TextField {
                        id:editField
                        focus: (indexCurrentItem === indexItem)?true:false
                        readOnly: rdOnly
                        inputMethodHints: (keyboardType === "decimal")?Qt.ImhPreferNumbers:Qt.ImhNone
                        onTextEdited:{
                            goodJobAccept(index,text)
                            goodJob = modelCatalog.goodJobDot(indexItem)
                        }
                        Item{
                            id:checkBox
                            height: parent.height-1
                            width: parent.height-1
                            z:2
                            anchors.left: parent.left
                            enabled: t7(index)
                            visible:   t7(index)
                            PressBox{z:3;anchors.bottomMargin: 1;height: fontSize*2;width: fontSize*2}

                        }
                        background:
                            Item{
                            anchors.fill: parent
                            Rectangle{
                                height: editField.focus?3:0
                                width: parent.width-10
                                color: colorThree
                                anchors.bottom: parent.bottom
                                anchors.horizontalCenter: parent.horizontalCenter

                            }
                        }

                        height: parent.height
                        width: parent.width
                        color: colorThree
                        horizontalAlignment: TextInput.AlignHCenter
                        font.pixelSize: fontSize*3
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
                        }
                    }
                }
            }
        }
//}
 function goodJobAccept(index,text){
     tts[index] = text
     reportFields = tts
 }
}
