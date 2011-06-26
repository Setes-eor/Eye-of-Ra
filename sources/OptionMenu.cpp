#include "OptionMenu.h"

// Konstruktor
//
COptionMenu::COptionMenu(){

}// Konstruktor

// Überladene Konstruktor
//
COptionMenu::COptionMenu(string File, int Weight = 200, int Hight = 787,
        int Anim = 0, int XPos = 1700, int YPos = 170):
CMenu(File,Weight,Hight,Anim,XPos,YPos){
}// Überladener Konstruktor


COptionMenu::~COptionMenu(){

}

void COptionMenu::Init(){

    m_pBackground ->Load(m_sFileName, m_iAnim, m_iWeight, m_iHight);
    m_pBackground ->SetColorKey(0, 0, 0);

}// Init

// BuildSelected
//
// Aufgabe: Führt verschiedene Optionen aus
//
void COptionMenu::Option(CPlayer *other, const int XPos, const int YPos,
        bool &MenuRun, bool &SaveAktiv, bool &Option, const int Weight, const int Hight){

    switch(getButtonID(XPos,YPos,Weight,Hight)){

        case(2):
            Option = false;
            SaveAktiv = true;
            break;
        case(6):
            MenuRun = false;
            break;
        default:
            break;
    }//switch


}// BuildSelected