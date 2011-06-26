/* 
 * File:   Button.h
 * Author: setes
 *
 * Created on 1. Februar 2011, 11:20
 */

#ifndef BUTTON_H
#define	BUTTON_H

#include "MenuElements.h"

class CButton: public CMenuElements{
private:
    // Beide X und Y Variablen kommmen weg sobalt X und Y von MenuElements  auch
    // auf float gesetzt sind !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    float m_fXPos;
    float m_fYPos;
    int m_iButtonID;
public:
    CButton();
    ~CButton();
    void Init(string File, float fXPos, float fYPos, int ID);
    void Rendern();
    inline const float getID()const{return m_iButtonID;}
    inline const float getXPos()const{return m_fXPos;}
    inline const float getYPos()const{return m_fYPos;}
    //static int m_iUnitID;

};



#endif	/* BUTTON_H */

