#include "noted.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication EditorApp(argc, argv);
    Noted Editor;
    Editor.show();
    return EditorApp.exec();
}
