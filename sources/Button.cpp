#include "Button.h"

CButton::CButton(){
  
    
}// Überladener Konstruktor

CButton::~CButton(){
    
}

// Init
//
// Aufgabe: Buttons initialisieren
//
void CButton::Init(string File, float fXPos, float fYPos, int ID) {

    // Gebäude Sprite Initialisieren und ColorKey setzen
    m_pBackground->Load(File);
    m_pBackground->SetColorKey(255, 0, 255);

    m_fXPos = fXPos;
    m_fYPos = fYPos;
    //Koordinaten erechnen
    m_pBackground->SetPos(m_fXPos, m_fYPos);

    // ID setzen
    m_iButtonID = ID;

  

} // Init

void CButton::Rendern(){
    m_pBackground->Render();
}
