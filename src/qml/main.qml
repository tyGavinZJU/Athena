import QtQuick 2.7
import QtQuick.Window 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.0
import Client.Component 1.0 as Client
import Graph 1.0
Window {
    id:root;
    visible: true;
    width: 1140;
    height: 740;
    minimumHeight: height;
    minimumWidth: width;
    maximumHeight: height;
    maximumWidth: width;
    color:"#e8e8e8";
    //flags:Qt.FramelessWindowHint


    Timer {
        id: ballspeedtimer
        interval: 50
        repeat: true
        running: true
        onTriggered: {
            graph.removeFirstSample();
            graph.appendSample(graph.newSample(++graph.offset));
        }

    }

    Timer{
        id:fpsTimer;
        interval:1000;
        running:true;
        repeat:true;
        onTriggered: {
            fps.text = (interaction.getFPS()).toString();
        }
    }

    Client.Interaction{ id : interaction; }

    Row {
        spacing: 0;

        TabView{
            id:fields;
            width:960;
            height:740;
            currentIndex:1;
            Repeater{
                model:["Origin","Filtered"];
                Tab{
                    anchors.fill: parent;
                    title:modelData;
                    Client.Field{
                        type:index+1;
                    }
                }
            }
            style: TabViewStyle {
                frameOverlap: 0
                tabOverlap: 0
                tab: Rectangle {
                    color: styleData.selected ? "grey" : "lightgrey"
                    implicitWidth: fields.width/fields.count;
                    implicitHeight: 20
                    Text {
                        id: text
                        anchors.centerIn: parent
                        text: styleData.title
                        color: styleData.selected ? "black" : "grey"
                    }
                }
            }
            Text{
               id : fpsWord;
               text : qsTr("FPS");
               x:parent.width - 70;
               y:5;
               color:"white";
               font.pointSize: (Qt.platform.os == "windows") ? 10 : 14;
               font.weight:  Font.Bold;
           }
           Text{
               id : fps;
               text : "";
               anchors.top: parent.top;
               anchors.topMargin: 5;
               anchors.right: parent.right;
               anchors.rightMargin: 10;
               color:"white";
               font.pointSize: (Qt.platform.os == "windows") ? 10 : 14;
               font.weight:  Font.Bold;
           }
           Graph {
               id: graph
               anchors.fill: parent
               anchors.leftMargin: 600
               anchors.rightMargin: 50
               anchors.topMargin: 500
               anchors.bottomMargin: 50

               //非常奇怪，这里的区间是0-1，而且0在上方。
               function newSample(i) {
                   return (-(interaction.getBallVelocity())/8000+1);//(Math.sin(i / 100.0 * Math.PI * 2) + 1) * 0.4 + Math.random() * 0.05;
               }

               Component.onCompleted: {
                   for (var i=0; i<100; ++i)
                       appendSample(newSample(i));
               }

               property int offset: 100;
                scale:1
           }
           Rectangle{
               id:areaRectangle;
               width:parent.width - 20;
               height:parent.height - 20;
               x:10;
               y:10;
               color:"#33ffffff";
           }
           MouseArea{
               property int startX : 0;
               property int startY : 0;
               anchors.fill: parent;
               onPressed: {
                   startX = mouseX;
                   startY = mouseY;
                   areaRectangle.width = 0;
                   areaRectangle.height = 0;
                   areaRectangle.x = startX;
                   areaRectangle.y = startY;
               }
               onPositionChanged: {
                   areaRectangle.x = Math.min(mouseX,startX);
                   areaRectangle.y = Math.min(mouseY,startY);
                   areaRectangle.width = Math.abs(mouseX - startX);
                   areaRectangle.height = Math.abs(mouseY - startY);
               }
               onReleased: {
                   if(areaRectangle.width < 100 && areaRectangle.height < 100){
                       areaRectangle.x = areaRectangle.y = 10;
                       areaRectangle.width = areaRectangle.parent.width - 20;
                       areaRectangle.height = areaRectangle.parent.height - 20;
                   }
                   interaction.setArea(areaRectangle.x,areaRectangle.width + areaRectangle.x,areaRectangle.height + areaRectangle.y,areaRectangle.y);
               }
           }
        }
        Column{
            width:180;
            height:parent.height;
            spacing: 0;

            Grid{
                id:cameraControls;
                width:parent.width;
                columns:1;
                columnSpacing: 0;
                rowSpacing: 0;
                anchors.horizontalCenter: parent.horizontalCenter;
                horizontalItemAlignment: Grid.AlignHCenter;
                verticalItemAlignment: Grid.AlignVCenter;
                property int itemWidth : (width - (columns-1) * columnSpacing)/columns;
                Repeater{
                    model:interaction.getCameraNumber();
                    Rectangle{
                        property int itemIndex : index;
                        property bool itemChecked : true;
                        color: itemChecked ? "#2baade" : "#e58a5c";
                        width:cameraControls.itemWidth;
                        height:20;
                        MouseArea{
                            anchors.fill: parent;
                            onClicked: {
                                parent.itemChecked = !parent.itemChecked;
                                interaction.controlCamera(itemIndex,itemChecked);
                            }
                        }
                    }
                }
            }
            Rectangle{
                property bool ifConnected : false;
                width:parent.width;
                height:40;
                color:ifConnected ? "#2bc88f" : "#e55a5c";
                MouseArea{
                    anchors.fill: parent;
                    onClicked: {
                        parent.ifConnected = !parent.ifConnected;
                        interaction.setVision(parent.ifConnected);
                    }
                }
            }

            Grid{
                id:processControl
                width:parent.width;
                columns:1;
                columnSpacing: 0;
                rowSpacing: 0;
                anchors.horizontalCenter: parent.horizontalCenter;
                horizontalItemAlignment: Grid.AlignHCenter;
                verticalItemAlignment: Grid.AlignVCenter;
                property int itemWidth : (width - (columns-1) * columnSpacing)/columns;
                Repeater{
                    model:["Origin","Filtered"];
                    Rectangle{
                        property int itemIndex : index;
                        property bool itemChecked : true;
                        color: itemChecked ? "#7b99ff" : "#e52a9c";
                        width:processControl.itemWidth;
                        height:20;
                        MouseArea{
                            anchors.fill: parent;
                            onClicked: {
                                parent.itemChecked = !parent.itemChecked;
                                interaction.controlProcess(itemIndex,itemChecked);
                            }
                        }
                    }
                }

            }

        }
    }
}
