import QtQuick 2.0

    Item{//line 1
        id: lineOne

//        Rectangle {
//            height: (indexItem === indexCurrentItem)?3:0
//            width: parent.width
//            color: (indexItem === indexCurrentItem)?colorThree:colorTwo
//            anchors.bottom: parent.bottom
//        }
        Text{
            color: colorTwo
            font.pixelSize: fontSize*2
            font.bold: (indexItem === indexCurrentItem)?true:false
            anchors.fill: parent
            text: ""+id +". "+ name
            wrapMode: Text.WordWrap
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment:Text.AlignHCenter
        }

    }
