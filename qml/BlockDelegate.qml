import QtQuick 2.15

// BlockDelegate.qml
Item {
    property var blockData

    height: 120
    width: parent.width

    Rectangle {
        anchors.fill: parent
        radius: 12
        color: "#1E1E1E"

        layer.enabled: true
        layer.effect: DropShadow {
            radius: 12
            samples: 25
            color: "#30000000"
        }

        // Hover animation
        states: State {
            name: "hovered"
            when: mouseArea.containsMouse
            PropertyChanges { target: bg; color: "#252525" }
        }

        transitions: Transition {
            ColorAnimation { duration: 150 }
        }
    }

    // Content here...
}
