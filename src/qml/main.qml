import QtQuick 2.7
import QtQuick.Window 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.0
import ZSS 1.0 as ZSS
import Graph 1.0
Window {
    id:root;
    visible: true;
    width: 1300;
    height: 740;
    minimumHeight: height;
    minimumWidth: width;
    maximumHeight: height;
    maximumWidth: width;
    color:"#e8e8e8";
    //flags:Qt.FramelessWindowHint

    Timer{
        id:fpsTimer;
        interval:1000;
        running:true;
        repeat:true;
        onTriggered: {
            fps.text = (interaction.getFPS()).toString();
        }
    }

    ZSS.Interaction4Field { id : interaction }

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
                    Rectangle{
                        border.color: "#555";
                        border.width: 1;
                        color: "transparent";
                        anchors.fill: parent;
                        ZSS.Field{
                            type:index+1;
                        }
                    }


                }
            }
            style: TabViewStyle {
                frameOverlap: 0
                tabOverlap: 0
                tab: Rectangle {
                    color: styleData.selected ? "#303030" : "grey"
                    implicitWidth: fields.width/fields.count;
                    implicitHeight: 20
                    Text {
                        id: text
                        anchors.centerIn: parent
                        text: styleData.title
                        color: styleData.selected ? "#dddddd" : "black"
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

           Rectangle{
               id:areaRectangle;
               width:parent.width - 20;
               height:parent.height - 20;
               x:10;
               y:10;
               color:"#11ffffff";
           }
           MouseArea{
               property int startX : 0;
               property int startY : 0;
               anchors.fill: parent;
               acceptedButtons: Qt.RightButton
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
        ControlBoard{
            id:controlBoard;
            width:340;
            height:parent.height;
        }
    }
}
