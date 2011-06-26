#include "SaveMenu.h"

// Konstruktor
//
CSaveMenu::CSaveMenu(){

}// Konstruktor

// Überladene Konstruktor
//
CSaveMenu::CSaveMenu(string File, int Weight = 200, int Hight = 787,
        int Anim = 0, int XPos = 1700, int YPos = 170):
CMenu(File,Weight,Hight,Anim,XPos,YPos){
}// Überladener Konstruktor


CSaveMenu::~CSaveMenu(){

}

void CSaveMenu::Init(){

    m_pBackground ->Load(m_sFileName, m_iAnim, m_iWeight, m_iHight);
    m_pBackground ->SetColorKey(0, 0, 0);

}// Init

// BuildSelected
//
// Aufgabe: Führt verschiedene Optionen aus
//
void CSaveMenu::Save(CPlayer *other, const int XPos, const int YPos,
        const int Weight, const int Hight, bool &SaveAktiv, CField* field){

    char *File = new char;
    switch(getButtonID(XPos,YPos,Weight,Hight)){

        case(1):
            strcpy(File,"content/saves/save1.sav");
            other->Save(1,File,field);
            break;
        case(2):
            strcpy(File,"content/saves/save2.sav");
            other->Save(2,File,field);
            break;
        case(3):
            strcpy(File,"content/saves/save3.sav");
            other->Save(3,File,field);
            break;
        case(4):
            strcpy(File,"content/saves/save4.sav");
            other->Save(4,File,field);
            break;
        case(5):
            strcpy(File,"content/saves/save5.sav");
            other->Save(5,File,field);
            break;
        default:
            break;
    }//switch

    // Speichermenü wird ausgeschlatet
    SaveAktiv = false;


}// BuildSelected
