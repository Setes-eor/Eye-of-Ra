/* 
 * File:   Menu.h
 * Author: setes
 *
 * Created on 1. Februar 2011, 10:30
 */
#ifndef MENU_H
#define	MENU_H

#include <string>
#include <list>
//#include "Field.h"
#include "Sprite.h"
#include "MenuElements.h"
#include "Button.h"

class CMenu: public CMenuElements{

protected:
    list<CButton> m_ButtonList; // Liste der Buttons Elemente eines Menüs
    string m_sButtonFile;
    int m_iButtonW;
    int m_iButtonH;
    int m_iButtonA;
    int m_iButtonX;
    int m_iButtonY;
    int m_iButtonID;
    
public:
    CMenu();
    CMenu(const string,const int,const int,const int,const int,const int);
    /*CMenu(const CMenu &);
    ~CMenu();
    copy(const CMenu &);
    destroy();
    CMenu &operator=(const CMenu &);*/
    void RenderButtons();
    void SetButton(string, int, int, int, float, float, int);
    virtual const int getButtonID(const int,const int,const int,const int);
    

};

#endif	/* MENU_H */

