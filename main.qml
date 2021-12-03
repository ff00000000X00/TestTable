import QtQuick 2.12
import QtQuick.Controls 1.4

    TableView
    {
        anchors.fill: parent //Якорь заполнения нужен, т.к. при объявлении TableView корневым элементом
        id:table             //окно Window создается неявно. А т.к. TableViewColumn расчитываются из
        width: 800           //размера TableView, если якорь убрать, внешний вид будет битым
        height: 600
        visible: true;
        model:myModel;
        TableViewColumn {role: "user_id"; title: "User id";width: parent.width/3}
        TableViewColumn {role: "user_name"; title: "User name";width: parent.width/3}
        TableViewColumn {role: "phone_number"; title: "Phone number";width: parent.width/3}
//        delegate:
//        Rectangle {
//           Text {text: modelData} Не получилось через делегата. Но я и не хотел ¯\_(ツ)_/¯
//                }
}

