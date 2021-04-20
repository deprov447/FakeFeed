import org.kde.kirigami 2.13 as Kirigami
import QtQuick 2.9
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import org.deprov447.example 1.0

Kirigami.ApplicationWindow {
    id: root
    title : "Fake Feed"

    Drawer {
        id: drawer
    }
    globalDrawer: drawer

    ChoicePage {
        id: choicePage
    }

    RowLayout {
        Button {
            text: "Choose a video file"
            onClicked: choicePage.open()
        }
        Button {
            text: "Disable current Camera feed"
            onClicked: {
                console.log(  FFMPEG.hello )
            }
        }
        Button {
            text: "Start fake cam feed"
//            onClicked: model.revert()
        }
    }
}
