// Budget
//
#ifndef BUDGET_H
#define BUDGET_H

#include <list>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include "BuildsEnum.h"
#include "Sprite.h"
#include "MenuElements.h"
#include "PanelRes.h"
#include "Budcounter.h"
#include "Timer.h"
#include "Menu.h"

using namespace std;

class CBudget {
public:
    CBudget();
    ~CBudget();
    void InitResources(int, unsigned int, unsigned int, unsigned int,
    unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
    unsigned int);
    bool EnaughResources(const int, const int, const int, const int);
    void Costs(const int,const int,const int,const int);
    void setFactor(int const,  int const,  const Buildtyp);
    void countRessources();
    void CountRessources(int,int,int);
    void SaveBudget(int const, char *File);
    void LoadBudget(int const, char *File);
    inline void ADDSize(const int Size){m_iSize += Size;}
    inline void ResetWoodFactor(){m_iWoodFactor = 0;}
    inline const bool getBuildElement_1()const{return m_bBuildElements_1;}
    inline int getMoney()const{return m_iMoney;}
    inline unsigned int getInhabs1()const{return m_iInhabitans_1;}
    inline unsigned int getInhabs2()const{return m_iInhabitans_2;}
    inline unsigned int getWood()const{return m_iWood;}
    inline unsigned int getBrick()const{return m_iBrick;}
    inline unsigned int getFish()const{return m_iFishes;}
    inline unsigned int getMilk()const{return m_iMilk;}
    inline unsigned int getSlime()const{return m_iSlime;}

private:
    int m_iMoney; // Spieler Geld
    int m_iWood; // Spieler Holz
    int m_iBrick; // Spieler Ziegeln
    int m_iStones; // Steine
    int m_iTools; // Spieler Werkzeuge
    int m_iFishes; // Spieler Fische
    int m_iMilk; // Spieler Milch
    int m_iSlime; // Spieler Nilschlamm
    int m_iInhabitans_1; // Einwohner Stufe 1
    int m_iInhabitans_2; // Einwohner Stufe 2
    int m_iApartments_1; // Anzahl Wohnhäuser Stufe 1
    int m_iApartments_2; // Anzahl Wohnhäuser Stufe 2
    
    int m_iMaxApartInhabs_1_1; // Maximal Einwohner Zahl pro Wohnhaus Stufe 1
    int m_iMaxApartInhabs_1_2; // Maximal Einwohner Zahl pro Wohnhaus Stufe 1
    int m_iMaxApartInhabs_2_1; // Maximal Einwohner Zahl pro Wohnhaus Stufe 2
    int m_iMaxApartInhabs_2_2; // Maximal Einwohner Zahl pro Wohnhaus Stufe 2
    int m_iSize; // Variable für Speicherkapazität


    //Variablen zum Abspeichern
    FILE *m_Fsave;
    FILE *m_Fload;
    int m_iLoadBuffer;

    double m_iMoneyCosts;
   
    // Berechnungsfakotren der Ressourcen
    int m_iWoodFactor; // Faktor der Holzberechnung
    int m_iBrickFactor; // Faktor der Ziegelberechnung
    int m_iMoneyFactor; // Faktor der Geldberechnung
    int m_iToolsFactor; // Faktor der Werkzeugberechung
    int m_iFishFactor; // Faktor der Fischberechnung
    int m_iMilkFactor; // Faktor der Milchberechnung
    int m_iSlimeFactor; // Faktor der Schlammberechnung
    int m_iStoneFactor; // Faktor der Steinberechnung

    CTimer *m_pTimer;

    time_t m_oldtime;
    time_t m_currenttime;
    time_t m_oldtime_2;
    time_t m_currenttime_2;
    time_t m_oldtime_3;
    time_t m_currenttime_3;
    bool test;
    bool m_bBuildElements_1; // aktiviert nach einer bestimmten Einwohnerzahl
                             // weitere Gebäude
    bool m_bADDInhaMax_1;


};

#endif