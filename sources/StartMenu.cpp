#include "StartMenu.h"

// Konstruktor
//
CStartMenu::CStartMenu(){

}// Konstruktor

// Überladene Konstruktor
//
CStartMenu::CStartMenu(string File, int Weight = 200, int Hight = 787,
        int Anim = 0, int XPos = 1700, int YPos = 170):
CMenu(File,Weight,Hight,Anim,XPos,YPos){
}// Überladener Konstruktor


CStartMenu::~CStartMenu(){

}

void CStartMenu::Init(){

    m_pBackground ->Load(m_sFileName, m_iAnim, m_iWeight, m_iHight);
    m_pBackground ->SetColorKey(0, 0, 0);

}// Init

// BuildSelected
//
// Aufgabe: Führt verschiedene Optionen aus
//
void CStartMenu::Option(CPlayer *other, const int XPos, const int YPos,
        int &MenuRun, bool &LoadAktiv, bool &GameRun, bool &Credits,
        const int Weight, const int Hight,CSprite *Background, CField* field){

    char *File = new char;

    switch(getButtonID(XPos,YPos,Weight,Hight)){

        case(1):
            strcpy(File,"content/data/Map/Map1.map");
            other->Load(1,File, field);
            MenuRun = 0;
            delete Background;
            break;
        case(3):
            LoadAktiv = true;
            delete Background;
            break;
        case(5):
            Credits = true;
            break;
        case(6):
            delete Background;
            GameRun = false;
            break;
        default:
            break;
    }//switch


}// BuildSelected
