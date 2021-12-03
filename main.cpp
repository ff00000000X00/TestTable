#include <QGuiApplication>
#include <QFile>
#include <QQuickView>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "ttablemodel.h"
#include <QStringListModel>


int main(int argc, char *argv[])
{
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QGuiApplication app(argc, argv);
    QQuickView *view = new QQuickView;

    QFile recource(":/book.txt");
    QStringList strngs;
    if(recource.exists())
    {
        if(recource.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream stream(&recource);
            QString text = stream.readAll();
            strngs = text.split("\n");
        }

        TableModel* model = new TableModel;
        model->setModel(strngs);

        QQmlContext *context = view->rootContext();
        context->setContextProperty("myModel",model);
        view->setSource(url);
        view->show();

    }
    return app.exec();

}
