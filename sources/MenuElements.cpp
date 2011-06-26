#include "MenuElements.h"

// Konstruktor
//
CMenuElements::CMenuElements(){
    m_pBackground = new CSprite;

}// Konstruktor

// Überladene Konstruktor
//
CMenuElements::CMenuElements(string File , int Weight = 10, int Hight = 10,
        int Anim = 0, int XPos = 0, int YPos = 0){

    m_iXPos = XPos;
    m_iYPos = YPos;
    m_iWeight = Weight;
    m_iHight = Hight;
    m_iAnim = Anim;
    m_sFileName = File;
    m_pBackground = new CSprite;

}// Überladener Konstruktor

// Copy
//
// Aufgabe: Kopiert die Daten von other
//
void CMenuElements::copy(const CMenuElements &other){

    m_pBackground = other.m_pBackground;

}// Copy

// Destroy
//
// Aufgabe: Gibt Speicher frei
//
void CMenuElements::destroy(){

    delete m_pBackground;
}// destroy

// Kopierkonstruktor
//
CMenuElements::CMenuElements(const CMenuElements& other){

    // Daten von other kopieren
    copy(other);

}// Kopierkonstruktor

// Überladener Zuweisungsoperator
//
CMenuElements &CMenuElements::operator =(const CMenuElements& other){

    if(this != &other){
        destroy();
        copy(other);
    }

    return *this;
}
// Destruktor
//
CMenuElements::~CMenuElements(){

    // Speicher freigeben
    //destroy();
    //delete m_pBackground;
}// Destruktor

// Init
//
// Aufgabe: Initialisiert Sprite
//
void CMenuElements::Init(){

    m_pBackground ->Load(m_sFileName, m_iAnim, m_iWeight, m_iHight);
    m_pBackground ->SetColorKey(255, 0, 255);

}// Init

// Render
//
// Aufgabe: Rendert das Menü inkl. Buttons
//
void CMenuElements::Render(){

    // Position des Grafik setzen und Sprite rendern
    m_pBackground->SetPos(m_iXPos, m_iYPos);
    m_pBackground->Render();

}// Render

// Render
//
// Aufgabe: Rendert das Menü inkl. Buttons mit Animation
//
void CMenuElements::Render(float Animp){

    // Position des Grafik setzen und Sprite rendern
    m_pBackground->SetPos(m_iXPos, m_iYPos);
    m_pBackground->Render(Animp);

}// Render
