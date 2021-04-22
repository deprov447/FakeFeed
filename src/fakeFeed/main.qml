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
            id : botton3
            enabled: false
            text: "Start fake cam feed"
            onClicked: {
                module.manageDevice( "v4l2loopback" , false )
                ffmpeg.textFileGenerator( "~/vtextfile.txt" , 10 )
                ffmpeg.stream()
            }
        }
    }
}
