#include <QApplication>
#include "WidgetCzyPierwsza.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    WidgetCzyPierwsza window;
    window.show();
    
    return app.exec();
}
