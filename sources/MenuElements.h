/* 
 * File:   MenuElements.h
 * Author: setes
 *
 * Created on 1. Februar 2011, 11:23
 */

#ifndef MENUELEMENTS_H
#define	MENUELEMENTS_H

#include <string>
#include <iostream>
#include "Sprite.h"

using namespace std;

class CMenuElements{

protected:
    CSprite *m_pBackground; // Hintergrundgrafik
    int m_iXPos; // X Koordinate des Menü Hintergrundes
    int m_iYPos; // y Koordinate des Menü Hintergrundes
    int m_iWeight; // Breite der Grafik
    int m_iHight;  // Höhe der Grafik
    int m_iAnim;   // Anzahl der Animationen
    string m_sFileName; // Pfad zur Grafik
public:
    CMenuElements();
    CMenuElements(string , int, int, int, int, int);
    CMenuElements(const CMenuElements &);
    ~CMenuElements();
    void copy(const CMenuElements &);
    virtual void destroy();
    CMenuElements &operator=(const CMenuElements &);
    inline void setXPos(const int XPos){m_iXPos = XPos;}
    inline void setYPos(const int YPos){m_iYPos = YPos;}
    //inline void setYPos(const CSprite *Back){m_pBackground = Back;}
    inline const int getXPos()const{return m_iXPos;}
    inline const int getYPos()const{return m_iYPos;}
    virtual void Init();
    virtual void Render();
    virtual void Render(float);
};


#endif	/* MENUELEMENTS_H */

