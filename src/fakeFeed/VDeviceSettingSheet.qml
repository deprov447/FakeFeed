import QtQuick 2.9
import org.kde.kirigami 2.13 as Kirigami
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Kirigami.OverlaySheet {
    id: vDeviceSettingSheet

    RowLayout {
        TextField {
            id: customLoopbackDevicename
            placeholderText: i18n("Device Name")
        }
        TextField {
            id: customLoopbackDeviceID
            placeholderText: i18n("Device ID (number <= 10)")
        }
        Button {
            id: customLoopbackDevicenameSubmit
            enabled: customLoopbackDeviceID.text<=10 && customLoopbackDeviceID.text>=1
            text: "Apply"
            onClicked: {
                module.setvDeviceName(customLoopbackDevicename.text)
                console.log("vDeviceName set to " +customLoopbackDevicename.text)
                module.setvDeviceID(customLoopbackDeviceID.text)
                console.log("vDeviceID set to " +customLoopbackDeviceID.text)
                vDeviceSettingSheet.close()
            }
        }
    }
}
