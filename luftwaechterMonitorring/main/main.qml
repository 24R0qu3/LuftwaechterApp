import QtQuick 2.15
import QtQuick.Window 2.15
import LuftwaechterApi 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property string defURL: "http://192.168.2.121/"

    SensorRequester {
        id: rquestCo2

        baseUrl: defURL + "co2"

        onSensorValueChanged: {
            console.log( sensorValue, sensorUnit )
        }

        Component.onCompleted: {
            vRequest();
        }
    }

    SensorRequester {
        id: rquestTemp

        baseUrl: defURL + "temperature"

        onSensorValueChanged: {
            console.log( sensorValue, sensorUnit )
        }

        Component.onCompleted: {
            vRequest();
        }
    }

    SensorRequester {
        id: rquestHumidity

        baseUrl: defURL + "humidity"

        onSensorValueChanged: {
            console.log( sensorValue, sensorUnit )
        }

        Component.onCompleted: {
            vRequest();
        }
    }

    Column {
        id: displayAll

        anchors.centerIn: parent

        SensorDisplay {
            id: displayCo2

            sensorName: "Co2"
            sensorValue: rquestCo2.sensorValue
            sensorUnit: rquestCo2.sensorUnit
        }

        SensorDisplay {
            id: displayTemp

            sensorName: "Temperature"
            sensorValue: rquestTemp.sensorValue
            sensorUnit: rquestTemp.sensorUnit
        }

        SensorDisplay {
            id: displayHumidity

            sensorName: "Humidity"
            sensorValue: rquestHumidity.sensorValue
            sensorUnit: rquestHumidity.sensorUnit
        }
    }
}
