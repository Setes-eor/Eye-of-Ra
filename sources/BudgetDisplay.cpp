#include "BudgetDisplay.h"

// Konstruktor
//
CBudgetDisplay::CBudgetDisplay(int RX, int RY){

    m_iSMoney = 4;
    m_iMoneyX = 130;
    m_iInhabsX = 130;
    m_iInhabsY = 59;
    m_iWoodX = 280;
    m_iBrickX = 430;
    m_iRY = 14;

     //Budget Leiste (Sprite) laden
    m_pSpriteBList = new CSprite;
    m_pSpriteBList->Load("content/data/Anzeigen/Ressourcenleiste.bmp");
    m_pSpriteBList->SetColorKey(0, 0, 0);
    m_pSpriteBshortList = new CSprite;
    m_pSpriteBshortList->Load("content/data/Anzeigen/Ressourcenleistes.bmp");
    m_pSpriteBshortList->SetColorKey(0, 0, 0);

   // Zahlen-Sprites erstellen
    m_pSpriteCounter = new CSprite;
    m_pSpriteCounter->Load("content/data/Anzeigen/Zahlen.bmp", 10, 20, 28);
    m_pSpriteCounterW = new CSprite;
    m_pSpriteCounterW->Load("content/data/Anzeigen/Zahlen.bmp", 10, 20, 28);
    m_pSpriteCounterB = new CSprite;
    m_pSpriteCounterB->Load("content/data/Anzeigen/Zahlen.bmp", 10, 20, 28);
    m_pSpriteCounterI = new CSprite;
    m_pSpriteCounterI->Load("content/data/Anzeigen/Zahlen.bmp", 10, 20, 28);

    // Elemente der Lager Anzeige
    PanelElementCounter = 1;
    m_pResourcesPanel = new CMenu("content/data/Anzeigen/RA_Panel.bmp", 200, 787,  0, 1700-RX, 170-RY);
    m_pResourcesPanel->Init();
    m_pPanelWood = new CPanelRes("content/data/Anzeigen/RA_Holz.bmp",65,62,0,1734 -RX,380-RY,0,"content/data/Anzeigen/RA_Zahlen.bmp",11,14,10,1749-RX,420-RY);
    m_pPanelWood->Init();
    m_pPanelBrick = new CPanelRes("content/data/Anzeigen/RA_Ziegeln.bmp",65,62,0,1807 -RX,380-RY,1,"content/data/Anzeigen/RA_Zahlen.bmp",11,14,10,1822-RX,420-RY);
    m_pPanelBrick->Init();
    m_pPanelFish = new CPanelRes("content/data/Anzeigen/RA_Fisch.bmp",65,62,0,1734 -RX,459-RY,2,"content/data/Anzeigen/RA_Zahlen.bmp",11,14,10,1749-RX,499-RY);
    m_pPanelFish->Init();
    m_pPanelMilk = new CPanelRes("content/data/Anzeigen/RA_Milch.bmp",65,62,0,1807 -RX,459-RY,3,"content/data/Anzeigen/RA_Zahlen.bmp",11,14,10,1822-RX,499-RY);
    m_pPanelMilk->Init();
    m_pPanelSlime = new CPanelRes("content/data/Anzeigen/RA_Schlamm.bmp",65,62,0,1734-RX,538-RY,4,"content/data/Anzeigen/RA_Zahlen.bmp",11,14,10,1749-RX,578-RY);
    m_pPanelSlime->Init();

    for (int i = 0; i < m_iSMoney; i++) {
        // Neuen Zahl erzeugen und initialisieren
        CBudcounter Counter;
        CBudcounter CounterW;
        CBudcounter CounterB;
        CBudcounter CounterI;


        Counter.Init(m_pSpriteCounter, m_iMoneyX, m_iRY);
        CounterW.Init(m_pSpriteCounterW, m_iWoodX, m_iRY);
        CounterB.Init(m_pSpriteCounterB, m_iBrickX, m_iRY);
        CounterI.Init(m_pSpriteCounterI,m_iInhabsX, m_iInhabsY);

        //in Liste einfügen
        m_BColist.push_back(Counter);
        m_BCoWlist.push_back(CounterW);
        m_BCoBlist.push_back( CounterB);
        m_BCoIlist.push_back(CounterI);

        m_iMoneyX -= 20;
        m_iWoodX -= 20;
        m_iBrickX -= 20;
        m_iInhabsX -= 20;
    }

}// Konstruktor

// Destruktor
//
CBudgetDisplay::~CBudgetDisplay(){
    delete m_pSpriteBList;
    delete m_pSpriteBshortList;
    delete m_pSpriteCounter;
    delete m_pSpriteCounterW;
    delete m_pSpriteCounterB;
    delete m_pSpriteCounterI;
    delete m_pPanelWood;
    delete m_pPanelBrick;
    delete m_pPanelFish;
    delete m_pPanelMilk;
    delete m_pPanelSlime;
    delete m_pResourcesPanel;
}// Destruktor

// Render
//
// Aufgabe: Budget Anzeige rendern
//
void CBudgetDisplay::Render(unsigned int inhabs_1 = 0, unsigned int inhabs_2 = 0,
        int money = 0, unsigned int wood = 0, unsigned int brick = 0) {
    // Budget Leiste setzen und rendern
    m_pSpriteBList->SetPos(5, 5);
    m_pSpriteBList->Render();

    m_pSpriteBshortList->SetPos(5, 50);
    m_pSpriteBshortList->Render();


    // Iterator für Zahlenliste
    list<CBudcounter>::iterator it = m_BColist.begin();
    list<CBudcounter>::iterator itW = m_BCoWlist.begin();
    list<CBudcounter>::iterator itB = m_BCoBlist.begin();
    list<CBudcounter>::iterator itI = m_BCoIlist.begin();

    // Zahlenleiste Geld durchlaufen
    int i = 0;

    while (it != m_BColist.end()) {

        switch (i) {

            case (0):
                m_fCoAnf = money % 10;
                m_iCoWo = wood % 10;
                m_iCoBr = brick % 10;
                m_iCoIn = (inhabs_1 + inhabs_2) % 10;
                break;
            case (1):
                m_fCoAnf = (money % 100) / 10;
                m_iCoWo = (wood % 100) / 10;
                m_iCoBr = (brick % 100) / 10;
                m_iCoIn = ((inhabs_1 + inhabs_2) % 100) / 10;
                break;
            case (2):
                m_fCoAnf = (money % 1000) / 100;
                m_iCoWo = (wood % 1000) / 100;
                m_iCoBr = (brick % 1000) / 100;
                m_iCoIn = ((inhabs_1 + inhabs_2) % 1000) / 100;
                break;
            case (3):
                m_fCoAnf = (money % 10000) / 1000;
                m_iCoWo = (wood % 10000) / 1000;
                m_iCoBr = (brick % 10000) / 1000;
                m_iCoIn = ((inhabs_1 + inhabs_2) % 10000) / 1000;
                break;
            default:
                break;
        }

        // Einzenlne Ziffer rendern
        it->Render(m_fCoAnf);
        itW->Render(m_iCoWo);
        itB->Render(m_iCoBr);
        itI->Render(m_iCoIn);
        it++;
        itW++;
        itB++;
        itI++;
        i++;

    }
}// Render

// RenderRessourcePanel()
//
// Aufgabe:
//
void CBudgetDisplay::RenderRessourcePanel(unsigned int Wood = 0,
        unsigned int Brick = 0, unsigned int Fish = 0, unsigned int Milk = 0,
        unsigned int Slime = 0){

    m_pResourcesPanel->Render();
    m_pPanelWood->Render();
    m_pPanelWood->RenderCounter((Wood % 1000) / 100,(Wood % 100) / 10,Wood % 10);
    m_pPanelBrick->Render();
    m_pPanelBrick->RenderCounter((Brick % 1000) / 100,(Brick % 100) / 10,Brick % 10);
    m_pPanelFish->Render();
    m_pPanelFish->RenderCounter((Fish % 1000) / 100,(Fish % 100) / 10,Fish % 10);
    m_pPanelMilk->Render();
    m_pPanelMilk->RenderCounter((Milk % 1000) / 100,(Milk % 100) / 10,Milk % 10);
    m_pPanelSlime->Render();
    m_pPanelSlime->RenderCounter((Slime % 1000) / 100,(Slime % 100) / 10,Slime % 10);


}// RenderRessourcePanel
