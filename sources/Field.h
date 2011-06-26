#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <stdio.h>
#include <list>
#include "Builds.h"
#include "Budget.h"
#include "FieldInfo.h"
#include "FieldElements.h"

using namespace std;

class CField : public CFieldInfo{
private:
    CFieldElements m_Buildings[120][160]; // Spielfeld für Gebäude Vegetation etc. mit festen Größen
    int m_iBuffer[120][160];
    int m_iFieldX; // Länge des Feldes
    int m_iFieldY; // Breite des Feldes
    int m_iSetX; // X Position zum Gebäude platzieren
    int m_iSetY; // Y Position zum Gebäude platzieren

    // Variablen zur Rasterberechnung
    int m_iRasterBigX, m_iRasterBigY;
    int m_iRasterSmallX, m_iRasterSmallY;
    int m_iRasterSetX, m_iRasterSetY;

    FILE *m_Fsave; // Zeiger zum Abspeichern aus Datei
    FILE *m_Fload; // Zeiger zum Laden aus Datei
    int m_iYLoad; // yKoordinate für Buffer laden
    int m_iXLoad; // xKoordinate für Buffer laden
    bool m_bLoadAktiv; // Steht auf true solange geladen wird

    int m_PersonellBuildID; // Spezielle ID für Gebäude


public:
    CField();
    ~CField();
    void Init();
    void SetBuildings(int, int, Buildtyp, bool);
    bool BuildCollison(int, int, Buildtyp);
    bool Raster(int, int, Buildtyp);
    void Raster(int X_Mouse, int Y_Mouse);
    void CoutField();
    void SaveField(const int, char *File);
    void LoadBuffer(char *);
    void LoadField(list<CBuilds> & , const int);
    int NextStreet(int y, int x);
    int CountArea(int, int, Buildtyp);

    inline const int GetRasterX()const{return m_iRasterSetX;}
    inline const int GetRasterY()const{return m_iRasterSetY;}
    inline const int GetLoadY()const {return m_iYLoad;}
    inline const int GetLoadX()const {return m_iXLoad;}
    inline void SetPID(const int PID) {m_PersonellBuildID = PID;}
    inline const int GetPID()const {return m_PersonellBuildID;}
    inline void setFieldState(const FieldState state, const int x, const int y){m_Buildings[y][x].setFieldstate(state);}

};

#endif