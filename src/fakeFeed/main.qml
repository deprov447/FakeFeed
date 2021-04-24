import org.kde.kirigami 2.13 as Kirigami
import QtQuick 2.9
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import com.fakefeed.ffmpeg 1.0
import com.fakefeed.module 1.0

Kirigami.ApplicationWindow {
    id: root
    title : "Fake Feed"
    width: 500
    height: 500

    Drawer {
        id: drawer
    }
    globalDrawer: drawer

    ChoicePage {
        id: choicePage
    }

    FFMPEG {
      id : ffmpeg
    }

    MODULE {
       id: module
    }

    VDeviceSettingSheet {
        id: vDeviceSettingSheet
    }

    function getfileurl ( reqString )
    {
        ffmpeg.fileInput( reqString );
    }

    function manageFeed ( start )
    {
        module.manageDevice( "v4l2loopback" , !start )
        if (start)
        {
            ffmpeg.textFileGenerator( "vtextfile.txt" , 100000 )
            console.log( "textFileGenerator called" )
            ffmpeg.stream()
            console.log( "Stream started" )
        }
        else
        {
                console.log("ToDo : rm textfile and stop stream")
        }
    }

    ColumnLayout {
        anchors{
            verticalCenter: parent.verticalCenter
            horizontalCenter: parent.horizontalCenter
        }
        Button {
            id : botton1
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Choose a file"
            onClicked: {
                module.manageDevice( "v4l2loopback", true );
                console.log ("Removed any stray virtual devices")
                choicePage.open()
                botton2.enabled = true
            }
        }
        Button {
            id : botton2
            anchors.horizontalCenter: parent.horizontalCenter
            enabled: false
            text: "Disable current Camera feed"
            onClicked: {
                module.getOriginalCam( "uvcvideo" )
                console.log("uvcvideo module removed")
                botton3.enabled = true
                advanceSettingBtn.enabled = true
            }
        }
        Button {
            id : advanceSettingBtn
            anchors.horizontalCenter: parent.horizontalCenter
            enabled: false
            text: "Advanced Settings"
            onClicked: {
                vDeviceSettingSheet.open()
                console.log("Advanced Settings");
           }
        }
        Button {
            property var startMode : true;
            id : botton3
            anchors.horizontalCenter: parent.horizontalCenter
            enabled: false
            text : startMode ? "Start Cam feed" : "Stop Cam feed"
            onClicked: {
                manageFeed( startMode )
                startMode =! startMode
                botton4.enabled = true
            }
        }
        Button {
            id : botton4
            anchors.horizontalCenter: parent.horizontalCenter
            enabled: false && botton4.startMode===true
            text: "Enable original cam feed"
            onClicked: {
                module.manageDevice( "v4l2loopback" , true )
                console.log("Virtual device removed")
                module.manageDevice( "uvcvideo" , false )
                console.log("Real device reloaded")
            }
        }
    }
}
