import QtQuick 2.0

Row {
    id: sensorDisplay

    property string sensorName: ""
    property string sensorValue: ""
    property string sensorUnit: ""

    spacing: 2

    Text {
        id: sensorNameText
        text: qsTr( sensorDisplay.sensorName + ": " )
    }

    Text {
        id: sensorValueText
        text: qsTr( sensorDisplay.sensorValue + " " )
    }

    Text {
        id: sensorUnitText
        text: qsTr( sensorDisplay.sensorUnit )
    }
}

