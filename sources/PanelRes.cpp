#include "PanelRes.h"

#include "Button.h"

CPanelRes::CPanelRes(string PFile, int PWeight, int PHight, int PAnim, int PXPos,
        int PYPos, int PID, string CoFile, int CoWeight, int CoHight,
        int CoAnim, int CoXPos=0, int CoYPos=0):
CMenuElements(PFile,PWeight,PHight,PAnim,PXPos,PYPos){

    m_iCounterX = CoXPos;
    m_iCounterY = CoYPos;
    m_pCounter1 = new CSprite;
    m_pCounter1 ->Load(CoFile, CoAnim, CoWeight, CoHight);
    m_pCounter2 = new CSprite;
    m_pCounter2 ->Load(CoFile, CoAnim, CoWeight, CoHight);
    m_pCounter3 = new CSprite;
    m_pCounter3 ->Load(CoFile, CoAnim, CoWeight, CoHight);

}// Überladener Konstruktor

CPanelRes::~CPanelRes(){

    delete m_pCounter1;
    delete m_pCounter2;
    delete m_pCounter3;

}

// Render
//
// Aufgabe: Rendert das Menü inkl. Buttons mit Animation
//
void CPanelRes::RenderCounter(float Animp1, float Animp2, float Animp3 ){

    m_pCounter1->SetPos(m_iCounterX, m_iCounterY);
    m_pCounter1->Render(Animp1);
    m_pCounter2->SetPos(m_iCounterX + 10, m_iCounterY);
    m_pCounter2->Render(Animp2);
    m_pCounter3->SetPos(m_iCounterX + 20, m_iCounterY);
    m_pCounter3->Render(Animp3);

}// Render