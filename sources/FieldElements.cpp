#include "FieldElements.h"

// Konstruktor
//
CFieldElements::CFieldElements(){
    m_State = free;
    m_Build = none;
    m_tTerrain = sand;
}// Konstruktor

// Überladener Konstruktor
//
CFieldElements::CFieldElements(FieldState state , Buildtyp build , Terraintyp terrain){
    m_State = state;
    m_Build = build;
    m_tTerrain = terrain;
}// Überladener Konstruktor

// IsFreeforBuild
//
// Aufgabe: Ermittelt ein Feld frei für ein Gebäude ist
//
bool CFieldElements::isFreeToBuild(FieldState field){
    if(m_State == field || m_State == freeforboth)
        return true;
    else
        return false;
}// isFreeToBuild

// setBuild
//
// Aufgabe: Setzt ein Feldelement auf den entsprechenen Gebäudetypen
//
void CFieldElements::setBuildtyp(const Buildtyp build, bool const destroy){

    m_Build = build;

    if(!destroy)
        m_State = blocked;
    else if(m_Build == house && destroy)
        m_State = freeforhouses;
    else if (m_Build != house && destroy && build != none)
        m_State = freeforbuilds;
    
}// setBuildtyp

void CFieldElements::setTerraintyp(const Terraintyp terrain){
    if(terrain == water)
        m_State = blocked;
    m_tTerrain = terrain;
}