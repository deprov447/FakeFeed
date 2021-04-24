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
            ffmpeg.stream()
        }
        else
        {
                console.log("halleluah")
        }
    }

    ColumnLayout {
        anchors.centerIn: parent
        Button {
            id : botton1
            text: "Choose a file"
            onClicked: {
                choicePage.open()
                botton2.enabled = true
            }
        }
        Button {
            id : botton2
            enabled: false
            text: "Disable current Camera feed"
            onClicked: {
                module.getOriginalCam( "uvcvideo" )
                botton3.enabled = true
            }
        }
        Button {
            property var startMode : true;
            id : botton3
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
            enabled: false && botton4.startMode===true
            text: "Enable original cam feed"
            onClicked: {
                module.manageDevice( "v4l2loopback" , true )
                module.manageDevice( "uvcvideo" , false )
            }
        }
    }
}
