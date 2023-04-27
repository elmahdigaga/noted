#include "noted.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication EditorApp(argc, argv);
    Noted Editor;
    // Editor.show();
    Editor.showMaximized();
    return EditorApp.exec();
}
