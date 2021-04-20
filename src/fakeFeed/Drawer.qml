import QtQuick 2.0
import org.kde.kirigami 2.13 as Kirigami

Kirigami.GlobalDrawer {
    id: drawer;

    isMenu: true
        actions: [
            Kirigami.Action {
                text: i18n("About")
                icon.name: "about"
                onTriggered: showPassiveNotification(i18n("Global drawer clicked"))
            }
        ]
}
