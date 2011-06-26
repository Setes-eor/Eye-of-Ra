#include "Menu.h"

// Konstruktor
//
CMenu::CMenu(){
    m_iButtonID = 0;

}// Konstruktor

// Überladene Konstruktor
//
CMenu::CMenu(string File, int Weight, int Hight, int Anim, int XPos = 0, int YPos = 0):
CMenuElements(File,Weight,Hight,Anim,XPos,YPos){
    m_iButtonID = 0;

}// Überladener Konstruktor

// Copy
// 
// Aufgabe: Kopiert die Daten von other
//
/*void CMenu::copy(const CMenu &other){

  

}// Copy

// Destroy
//
// Aufgabe: Gibt Speicher frei
//
void CMenu::destroy(){

  
}// destroy

// Kopierkonstruktor
//
CMenu::CMenu(const CMenu& other){

    // Daten von other kopieren
    copy(other);

}// Kopierkonstruktor

// Überladener Zuweisungsoperator
//
CMenu &CMenu::operator =(const CMenu& other){

    if(this != &other){
        destroy();
        copy(other);
    }

    return *this;
}
// Destruktor
//
CMenu::~CMenu(){

    // Speicher freigeben
    destroy();
}// Destruktor*/

// RenderButtons
//
// Aufgabe: Rendert das Menü inkl. Buttons
//
void CMenu::RenderButtons(){
    list<CButton>::iterator it = m_ButtonList.begin();
    while(it != m_ButtonList.end()){
        it->Rendern();
        it++;
    }
}

// SetButton
//
//Aufgabe: Erzeugt ein Button und fügt ihn in die Liste ein
//
void CMenu::SetButton(const string File, const int Weigth, const int Hight,
        const int Anim, const float XPos, const float YPos,
        const int ID){

    CButton ButtonE;
    ButtonE.Init(File, XPos, YPos, ID);
    m_ButtonList.push_back(ButtonE);

}// SetButton

// getButtonID
//
// Aufgabe: Durchsucht die Buttonliste nach den passenden Koordinaten und
//          gibt die ID des Button zurück
//
const int CMenu::getButtonID(const int XPos,const int YPos, const int Weigth,
        const int Hight){
    list<CButton>::iterator it = m_ButtonList.begin();
    while(it != m_ButtonList.end()){
        if(XPos >= (it->getXPos()) && XPos <= ((it->getXPos()) + Weigth) &&
                YPos >= (it->getYPos()) && YPos <= ((it->getYPos()) +Hight))
            return it->getID();
        else
            it++;
    }
    return 99;


}// getButtonID