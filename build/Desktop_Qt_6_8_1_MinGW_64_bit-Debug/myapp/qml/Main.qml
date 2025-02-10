// main.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    id: window
    visible: true
    width: 1200
    height: 600
    minimumWidth: 800
    minimumHeight: 600
    title: "ChainieBlockie"

    // Sidebar properties
    property int sidebarWidth: 240
    property int sidebarCollapsedWidth: 64
    property bool sidebarExpanded: true

    // Modern color scheme
    property color backgroundColor: "#f5f6fa"
    property color sidebarColor: "#2f3640"
    property color accentColor: "#40739e"
    property color textColor: "#f5f6fa"

    // Main container
    Rectangle {
        anchors.fill: parent
        color: backgroundColor
        // side bar
        Rectangle {
            id: sidebar
            width: sidebarExpanded ? sidebarWidth : sidebarCollapsedWidth
            height: parent.height
            color: sidebarColor
            radius: 8  // Added border radius
            clip: true

            Behavior on width {
                NumberAnimation { duration: 150; easing.type: Easing.InOutQuad }
            }

            // Logo and toggle button
            Column {
                width: parent.width
                spacing: 10
                // top title
                Item {
                    width: parent.width
                    height: 80

                    // Collapsed state logo
                    Rectangle {
                        anchors.centerIn: parent
                        width: 40
                        height: 40
                        radius: 8  // Rounded logo container
                        color: Qt.lighter(sidebarColor, 1.1)
                        visible: !sidebarExpanded

                        Image {
                            source: "logo.png"
                            width: 24
                            height: 24
                            anchors.centerIn: parent
                        }
                    }

                    // Expanded state logo
                    RowLayout {
                        anchors.centerIn: parent
                        spacing: 10
                        visible: sidebarExpanded

                        Rectangle {
                            width: 40
                            height: 40
                            radius: 8
                            color: Qt.lighter(sidebarColor, 1.1)

                            Image {
                                source: "logo.png"
                                width: 24
                                height: 24
                                anchors.centerIn: parent
                            }
                        }

                        Text {
                            text: "ChainieBlockie"
                            color: textColor
                            font.pixelSize: 20
                            font.bold: true
                        }
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: sidebarExpanded = !sidebarExpanded
                        cursorShape: Qt.PointingHandCursor
                    }
                }

                // Navigation tabs
                ColumnLayout {
                    width: parent.width
                    spacing: 4  // Reduced spacing between buttons

                    Repeater {
                        model: [
                            {icon: "🏠", title: "Home"},
                            {icon: "⭐", title: "Favorites"},
                            {icon: "⚙️", title: "Settings"},
                            {icon: "📁", title: "Documents"}
                        ]

                        Rectangle {
                            id: tabItem
                            Layout.fillWidth: true
                            Layout.preferredHeight: 50
                            Layout.leftMargin: 8
                            Layout.rightMargin: 8
                            color: tabMouse.containsMouse ? "#3e4753" : "transparent"
                            radius: 8

                            MouseArea {
                                id: tabMouse
                                anchors.fill: parent
                                hoverEnabled: true
                                cursorShape: Qt.PointingHandCursor
                                onClicked: currentTab = index
                            }

                            // Content container
                            Item {
                                anchors.fill: parent
                                anchors.leftMargin: 12
                                anchors.rightMargin: 12

                                // Expanded state layout
                                Row {
                                    visible: sidebarExpanded
                                    anchors.verticalCenter: parent.verticalCenter
                                    spacing: 15

                                    Text {
                                        id: iconText
                                        text: modelData.icon
                                        font.pixelSize: 20
                                        color: textColor
                                    }

                                    Text {
                                        id: titleText
                                        text: modelData.title
                                        color: textColor
                                        font.pixelSize: 14
                                        opacity: sidebarExpanded ? 1 : 0
                                        width: sidebarExpanded ? implicitWidth : 0
                                        Behavior on opacity { NumberAnimation { duration: 100 } }
                                        Behavior on width { NumberAnimation { duration: 150 } }
                                    }
                                }

                                // Collapsed state layout
                                Text {
                                    id: collapsedIcon
                                    visible: !sidebarExpanded
                                    text: modelData.icon
                                    font.pixelSize: 20
                                    color: textColor
                                    anchors.centerIn: parent
                                }
                            }
                        }
                    }
                }
            }
        }
        // Main content area
        Rectangle {
            id: contentArea
            anchors {
                left: sidebar.right
                right: parent.right
                top: parent.top
                bottom: parent.bottom
                margins: 20
            }
            color: "transparent"

            Text {
                text: "Main Content Area"
                font.pixelSize: 24
                color: "#2f3640"
                anchors.centerIn: parent
            }
        }
    }
}
