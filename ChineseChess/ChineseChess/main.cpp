#include <QApplication>

#include "SelectGameMode.h"
#include "ChooseMainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SelectGameMode dlg;
    dlg.setWindowTitle("请选择游戏方式");
    dlg.setFixedSize(300,180);
    dlg.setWindowIcon(QIcon(":/images/chess.svg"));
    if(dlg.exec() != QDialog::Accepted)
        return 0;

    ChooseMainWindow wnd(dlg.m_nSelect);

    return a.exec();
}
