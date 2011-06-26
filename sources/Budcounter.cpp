#include "Budcounter.h"

// Init
//
// Aufgabe: Zahlen initialisieren
//

void CBudcounter::Init(CSprite *pSpriteCounter, float fXPos, float fYPos) {
    // Zeiger auf Sprite kopieren und Koordinaten setzen
    m_pSpriteCounter = pSpriteCounter;
    m_fXPos = fXPos;
    m_fYPos = fYPos;


} // Init

// Update
//
// Aufgabe: Zahlen aktualisieren
//

void CBudcounter::Update(float m_fAnimP) {
    //
    m_fAnimPhase = m_fAnimP;

} // Update

// Render
//
// Aufgabe: Zahlen rendern
//

void CBudcounter::Render(float m_fAnimP) {
    // Koordinaten setzen und rendern
    m_pSpriteCounter->SetPos(m_fXPos, m_fYPos);
    m_pSpriteCounter->Render(m_fAnimP);

} // Render
