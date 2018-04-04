import QtQuick 2.0

Item {
    z: parent.z+1
Rectangle{
        height: 2
        width: parent.width
        color:colorGreyB
        anchors.top: parent.top
        z: parent.z+1


    }
    Row{
        id: buttonsRow
        anchors.fill: parent
        Repeater{
            id: rowRepeater
            model: omodel
            Item{
                width: parent.width/rowRepeater.count
                height: buttonsRow.height
                Rectangle{
                    enabled: model.rightAccess?!isReadOnly:true
                    anchors.fill: parent
                    color: colorGreyC
                    Text{
                        anchors.fill: parent
                        font.pixelSize: fontSize
                        color: enabled?colorThree:colorGreyA
                        font.bold: true
                        text: model.text
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                           qmlSignal("Action::"+model.action)
                        }
                        onPressed: {
                            parent.color = colorGreyB
                        }
                        onReleased: {
                            parent.color = colorGreyC
                        }

                    }
                }
            }
        }
    }
    ListModel{
                id: omodel
                ListElement{text:"Назад";action:"back";rightAccess:false}
                ListElement{text:"Фото";action:"photo";rightAccess:true}
                ListElement{text:"Здати звіт";action:"push";rightAccess:true}
            }

}
