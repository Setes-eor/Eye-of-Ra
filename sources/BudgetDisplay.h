/* 
 * File:   BudgetDisplay.h
 * Author: setes
 *
 * Created on May 13, 2011, 6:33 PM
 */

#ifndef BUDGETDISPLAY_H
#define	BUDGETDISPLAY_H

#include <list>
#include "Sprite.h"
#include "Budcounter.h"
#include "Menu.h"
#include "PanelRes.h"

class CBudgetDisplay{
private:
    CSprite *m_pSpriteBList; // Sprite Budgetleiste
    CSprite *m_pSpriteBshortList; // Sprite Budgetleiste kurz

    CMenu *m_pResourcesPanel; // Lager Fenster
    int PanelElementCounter; // Zählt die Elemente des Lager Festers
    int m_fCoAnf; // Ziffern Stellen Wert Geld
    int m_iCoWo; // Ziffern Stellen Wert
    int m_iCoBr; // Ziffern Stellen Wert
    int m_iCoIn; // Ziffern Stellen Wert
    int m_iMoneyX; // X Koordinate Ziffern Geld
    int m_iRY; // Y Kooridinate der Ressourcen Ziffern
    int m_iInhabsX; // X Koordinate der Ziffern Einwohner
    int m_iInhabsY; // Y Kooridinate der Ziffern Einwohner
    int m_iWoodX, m_iWoodY; // Koordinaten Ziffern Holz
    int m_iBrickX, m_iBrickY; // Koordinaten Ziffern Ziegeln
    int m_iSMoney;

    // Fenster der Jeweiligen Ressourcen Anzeige : Lager Fenster
    CPanelRes *m_pPanelWood;
    CPanelRes *m_pPanelBrick;
    CPanelRes *m_pPanelSlime;
    CPanelRes *m_pPanelFish;
    CPanelRes *m_pPanelMilk;

    CSprite *m_pSpriteCounter; // Sprite Geld Ziffern
    CSprite *m_pSpriteCounterW; // Sprite Holz Ziffern
    CSprite *m_pSpriteCounterB; // Sprite Ziegelen Ziffer
    CSprite *m_pSpriteCounterI; // Sprite Einwohner Ziffer
    list<CBudcounter> m_BColist; // Liste der Budget Zahlen Ausgabe
    list<CBudcounter> m_BCoWlist; // Liste der Budget Zahlen Ausgabe
    list<CBudcounter> m_BCoBlist; // Liste der Budget Zahlen Ausgabe
    list<CBudcounter> m_BCoIlist; // Liste der Budget Zahlen Ausgabe
    
public:
    CBudgetDisplay(int, int);
    ~CBudgetDisplay();
    void Render(unsigned int, unsigned int,int, unsigned int, unsigned int);
    void RenderRessourcePanel(unsigned int, unsigned int, unsigned int,
    unsigned int, unsigned int);

};


#endif	/* BUDGETDISPLAY_H */

