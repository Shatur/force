import QtQuick 2.0

Item{


ListView {
    id: list
    width: 180;
    height: 200

    model: modelCatalog
    delegate: Text {
        text: "name" + ": " + "number"+ id + name
    }
}
}
