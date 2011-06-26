#include"BuildMenu.h"

// Konstruktor
//
CBuildMenu::CBuildMenu(){

}// Konstruktor

// Überladene Konstruktor
//
CBuildMenu::CBuildMenu(string File, int Weight = 200, int Hight = 787,
        int Anim = 0, int XPos = 1700, int YPos = 170):
CMenu(File,Weight,Hight,Anim,XPos,YPos){
}// Überladener Konstruktor


CBuildMenu::~CBuildMenu(){
    
}

// BuildSelected
//
// Aufgabe: Setzt Bau ID und den passenen Curser zum Gebäude
//
void CBuildMenu::BuildSelected(CPlayer *other, const int XPos, const int YPos,
        const int Weight, const int Hight, bool &Destroyaktiv, bool &StopBuild){

    // Fehler abfangen fals es Probleme mit other gibt!!!!!!!!!!!!!!!!
    int ButtonID;

    ButtonID = getButtonID(XPos,YPos,Weight,Hight);
    if(ButtonID == 98){
        Destroyaktiv = true;
        other->setMenuLock2(true);
        StopBuild = true;
    }
        
    else if(ButtonID != 99 && ButtonID != 98){
        switch(ButtonID){
            case(1):
                buildname = house;
                break;
            case(2):
                buildname = street;
                break;
            case(3):
                buildname = market;
                break;
            case(4):
                buildname = temple;
                break;
            case(5):
                buildname = storage;
                break;
            case(6):
                buildname = trader;
                break;
            case(7):
                buildname = lumberjack;
                break;
            case(8):
                buildname = tree;
                break;
            case(9):
                buildname = slimegrave;
                break;
            case(10):
                buildname = brickmaker;
                break;
            case(11):
                buildname = fisher;
                break;
            case(12):
                buildname = milkfarm;
                break;
            case(13):
                buildname = center;
                break;
            case(16):
                buildname = milkfield;
                break;
            default:
                buildname = none;
                break;
        }
        
        other->setBuildID(buildname);
        other->ChangeCurserPic();
        other->setMenuLock2(true);
        StopBuild = true;
        other->setRasterMouse(true);
    }
    

}// BuildSelected

