#include "SelectGameMode.h"
#include <QVBoxLayout>//垂直布局

SelectGameMode::SelectGameMode(QWidget *parent): QDialog(parent)
{
    QVBoxLayout* lay = new QVBoxLayout(this);

   /* lay->addWidget(m_buttons[0] = new QPushButton("单人对弈模式"));*/
    lay->addWidget(m_buttons[0] = new QPushButton("单机对弈"));
    lay->addWidget(m_buttons[1] = new QPushButton("匹配 AI"));
    lay->addWidget(m_buttons[2] = new QPushButton("匹配玩家"));
    m_buttons[0]->setStyleSheet("QPushButton{font-family:'宋体';font-size:32px;color:rgb(255,255,255,255);}\
    QPushButton{background-color:rgb(0,0,0)}QPushButton:hover{background-color:rgb(255,0,0)}");
    m_buttons[1]->setStyleSheet("QPushButton{font-family:'宋体';font-size:32px;color:rgb(255,255,255,255);}\
    QPushButton{background-color:rgb(0,0,0)}QPushButton:hover{background-color:rgb(255,0,255)}");
    m_buttons[2]->setStyleSheet("QPushButton{font-family:'宋体';font-size:32px;color:rgb(255,255,255,255);}\
    QPushButton{background-color:rgb(0,0,0)}QPushButton:hover{background-color:rgb(0,255,0)}");
    for(int i=0; i<3; i++)
        connect(m_buttons[i], SIGNAL(clicked()), this, SLOT(slotClicked()));
}

SelectGameMode::~SelectGameMode()
{
}

void SelectGameMode::slotClicked()
{
    QObject* s = sender();
    for(int i=0; i<3; ++i)
    {
        if(m_buttons[i] == s)
        {
            this->m_nSelect = i;
            break;
        }
    }
    /*if(m_buttons[0] == s)
         this->m_nSelect = 0;
    else if(m_buttons[1] == s)
        this->m_nSelect = 2;*/

    accept();
}
