import org.kde.kirigami 2.13 as Kirigami
import QtQuick 2.9
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.0

FileDialog {
      id: fileDialog
      title: "Please choose a file"
      folder: shortcuts.home
      onAccepted: {
          console.log("You chose: " + fileDialog.fileUrls)
      }
      onRejected: {
          console.log("Canceled")
      }
}
