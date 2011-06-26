/*
 * File:   PanelRes.h
 * Author: setes
 *
 * Created on 10. Februar 2011, 21:33
 */

#ifndef PANELRES_H
#define	PANELRES_H

#include <list>
#include "MenuElements.h"
#include "Sprite.h"

class CPanelRes: public CMenuElements{

private:
    list<CSprite> m_Counterlist;
    CSprite *m_pCounter1;
    CSprite *m_pCounter2;
    CSprite *m_pCounter3;
    int m_iCounterX;
    int m_iCounterY;


public:
    CPanelRes(string, int, int, int, int, int, int, string, int, int, int, int, int);
    ~CPanelRes();
    void RenderCounter(float,float,float);

};


#endif	/* PANELRES_H */

