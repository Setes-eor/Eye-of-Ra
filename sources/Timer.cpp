#include "Timer.h"

// Konstruktor
//
// Aufgabe: Initialisierung
//

CTimer::CTimer() {
    // Initialisierung
    m_fCurTime = 0.0f;
    m_fLastTime = SDL_GetTicks() / 1000.0f;
    m_fElapsed = 0.0f;

}

// SetBack
//
// Aufgabe Timer wird zurückgesetzt
//

void CTimer::SetBack() {
    m_fCurTime = 0.0f;
    m_fLastTime = SDL_GetTicks() / 1000.0f;
    m_fElapsed = 0.0f;

}// SetBack

// Update
//
// Aufgabe: Timer updaten
//

void CTimer::Update() {
    // Vergangene Zeit seit dem letzten Frame berechnen
    m_fCurTime = SDL_GetTicks() / 1000.0f;

    m_fElapsed = m_fCurTime - m_fLastTime;
    m_fLastTime = m_fCurTime;

} // Update
