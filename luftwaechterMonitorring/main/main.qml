import QtQuick 2.15
import QtQuick.Window 2.15
import LuftwaechterApi 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    MyTest {
        id: myTest
    }

    Component.onCompleted: {
        myTest.test( "here comes the output" )
    }
}