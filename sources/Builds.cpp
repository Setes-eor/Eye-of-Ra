#include "Builds.h"

//Konstruktor
//
CBuilds::CBuilds() {
    m_fXPosv = 0;
    m_fYPosv = 0;
    m_iProductValue = 0;
    m_buildname = none;
    m_iPersonellID = 0;
    m_fYRenderPos = 0;

    // Timer initialisieren
    m_pTimer = new CTimer;
    
    m_oldtime = time(NULL);
}

// destroy
//
// Aufgabe: Gibt Speicher für ein abgerissenens Gebäude wieder frei
//
void CBuilds::destroy(){
    delete m_pBackground;
    delete m_pTimer;
}
// Init
//
// Aufgabe: Gebäude initialisieren
//
void CBuilds::Init(string File, float fXPos, float fYPos, Buildtyp name, int PID, int Value,
        int ProTime, int Money) {

    // Gebäude Sprite Initialisieren und ColorKey setzen
    m_pBackground->Load(File);
    m_pBackground->SetColorKey(255, 0, 255);

    // Start Koordinaten erechnen
    m_fXPos = fXPos + m_fXPosv;
    m_fYPos = fYPos + m_fYPosv;

    m_fYRenderPos = m_fYPos + m_Rect.h;

    // ID setzen
    m_buildname = name;
    m_iPersonellID = PID;
    m_iProductValue = Value;
    m_iMoney = Money;
    m_iProTime = ProTime;

    // Rect initialisieren;
    m_Rect.x = static_cast<int>(fXPos + m_fXPosv);
    m_Rect.y = static_cast<int>(fYPos + m_fYPosv);
    m_Rect.w = m_pBackground->GetRect().w;
    m_Rect.h = m_pBackground->GetRect().h;

    m_fYRenderPos = m_fYPos + m_Rect.h;
    // Gebäude aktivieren
    m_bIsAlive = true;

} // Init

// Update
//
// Aufgabe: Gebäude Position prüfen
//
void CBuilds::Update(float XPos, float YPos) {
    // Gebäude Position updaten
    m_fXPosv = XPos;
    m_fYPosv = YPos;

} // Update

// Render
//
// Aufgabe: Schuss rendern
//
void CBuilds::Render() {
    if (m_bIsAlive == true) {
        // Koordinaten setzen und rendern
        m_pBackground->SetPos(m_fXPos + m_fXPosv, m_fYPos + m_fYPosv);
        m_pBackground->Render();
    }
    m_Rect.x = static_cast<int>(m_fXPos + m_fXPosv);
    m_Rect.y = static_cast<int>(m_fYPos + m_fYPosv);

} // Render

// CountRessources
//
// Aufgabe: Fügt die produzierten Güter zum Budget hinzu
//
void CBuilds::CountRessources(CBudget *other){

    // Berechung der Spieler Ressourcen nach jeweils 10 Sekunden
    if (m_currenttime = (time(NULL) - m_oldtime) >= m_iProTime) {
        m_oldtime = time(NULL);
        other->CountRessources(m_buildname,m_iProductValue,m_iMoney);
    }
}// CountRessources
