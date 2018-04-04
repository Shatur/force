import QtQuick 2.0
import QtQuick.Controls 2.2


Item {
    property bool onOff: false
    z:9
    visible: onOff
    enabled: onOff
    Rectangle{
        id: background
        anchors.fill: parent
        color: colorGreyC
    }
    Column{
        anchors.fill: parent
        Column{
            width: parent.width
            height: parent.height*0.38
            Item {
                width: parent.width
                height: parent.height*0.38
                Row{
                    height: parent.height
                    width: parent.width
                    Rectangle{
                        color: colorGreyC
                        height: parent.height
                        width: parent.width*0.62
                        Image{
                            width: parent.height*0.38
                            height: width
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            anchors.leftMargin: fontSize
                            source: "qrc:/ui/art/comment.svg"
                        }
                        Text{
                            color: colorThree
                            anchors.fill: parent
                            text: "Залишити комментар"
                            font.bold: true
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                        }
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                if(textTypeHere.text == "")
                                    return;
                                Comment.setCommentTextValue(textTypeHere.text)
                                qmlSignal("Comment::add")
                                textTypeHere.text = ""
                            }
                        }
                    }
                    Rectangle{
                        color:colorGreyC
                        height: parent.height
                        width: parent.width*0.38
                        Text{
                            color: colorThree
                            anchors.fill: parent
                            text: "Закрити"
                            font.bold: true
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            MouseArea{
                                anchors.fill: parent
                                onClicked: {
                                    onOff = !onOff
                                }
                            }
                        }
                    }
                }
            }

            TextArea{
                id: textTypeHere
                scale: 0.98
                width: parent.width
                height: parent.height*0.62
                wrapMode: Text.WordWrap
                font.pixelSize: fontSize
                placeholderText: "Тут сформулюйте свій комментар"
                background:  Rectangle{
                    anchors.fill: parent
                    color: colorOne
                    border.color: colorThree
                    border.width: 1
                    radius: fontSize/3
                }
            }
        }

        ListView{
            width: parent.width
            height: parent.height*0.62
            spacing: 2
            model:Comment

            delegate: Dlg{height: textTypeHere.height*0.68}
        }
    }
}
