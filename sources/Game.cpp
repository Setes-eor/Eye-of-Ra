#include "Game.h"

// Konstruktor
//
// Aufgabe: Allgemeine Initialisierungen
//
CGame::CGame() {
    m_pPlayer = NULL;
    m_pSpriteBackground = NULL;
    m_pBuildMenu = NULL;
    m_pOptionMenu = NULL;

    m_fFPS = 1.0f/60.0f;
    mtest = 0;

    // Neue Field Instanz
    m_pField = new CField;
} // Konstruktor

// SetResolution
//
// task: set the resolution of the menus
//
void CGame::SetResolution(int X, int Y){

    switch(X){
        case(1920):
            m_iBMResolutionX = 0;
            m_iSBResolutionX = 0;
            m_iMResolutionX = 650;
            break;
        case(1680):
            m_iBMResolutionX = 240;
            m_iSBResolutionX = 328;
            m_iMResolutionX = 617;
            break;
        case(1440):
            m_iBMResolutionX = 480;
            m_iSBResolutionX = 208;
            m_iMResolutionX = 497;
            break;
        case(1280):
            m_iBMResolutionX = 640;
            m_iSBResolutionX = 128;
            m_iMResolutionX = 417;
            break;
        case(1240):
            m_iBMResolutionX = 680;
            m_iSBResolutionX = 108;
            m_iMResolutionX = 397;
            break;
        case(1024):
        default:
            m_iBMResolutionX = 896;
            m_iSBResolutionX = 0;
            m_iMResolutionX = 289;
            break;
    }// switch X

    switch(Y){
        case(1080):
            m_iBMResolutionY = 0;
            m_iSBResolutionY = 0;
            m_iMResolutionY = 50;
            break;
        case(900):
            m_iBMResolutionY = 124;
            m_iSBResolutionY = 50;
            m_iMResolutionY = 100;
            break;
        case(800):
        default:
            m_iBMResolutionY = 163;
            m_iSBResolutionY = 0;
            m_iMResolutionY = 50;
            break;
    }// switch X

    // new player object
    m_pPlayer = new CPlayer(m_iBMResolutionX,m_iBMResolutionY, m_pField);
    SetMoveResolution(X,Y);

    if(X != 1920){
        m_iButtonResolutionX = m_iMResolutionX + 55;
        m_iButtonResolutionY = m_iMResolutionY + 96;
        m_iButtonResolutionADDY = 97;
        m_iButtonW = 335;
        m_iButtonH = 78;
        m_sBackgroundfile = "content/data/Anzeigen/BackgroundSmall.bmp";
        m_sSMenu = "content/data/Menu/Small/SM_Menu_Small.bmp";
        m_sLoadMenu = "content/data/Menu/Small/SlM_Menu_Small.bmp";
        m_sSaveMenu = "content/data/Menu/Small/SpM_Menu_Small.bmp";
        m_sOptionMenu = "content/data/Menu/Small/OM_Menu_Small.bmp";
        m_sCredits = "content/data/Anzeigen/Small/Credits_Small.bmp";
        m_sNewGame = "content/data/Menu/Small/SM_NewGame_Small.bmp";
        m_sLoad = "content/data/Menu/Small/SM_Spielladen_Small.bmp";
        m_sCreditsb = "content/data/Menu/Small/SM_Credits_Small.bmp";
        m_sClose = "content/data/Menu/Small/SM_Spielbeenden_Small.bmp";
        m_sSave = "content/data/Menu/Small/OM_Spielspeichern_Small.bmp";
        m_SSave1 = "content/data/Menu/Small/SpM_1_Small.bmp";
        m_SSave2 = "content/data/Menu/Small/SpM_2_Small.bmp";
        m_SSave3 = "content/data/Menu/Small/SpM_3_Small.bmp";
        m_SSave4 = "content/data/Menu/Small/SpM_4_Small.bmp";
        m_SSave5 = "content/data/Menu/Small/SpM_5_Small.bmp";

    }
    else{
        m_iButtonResolutionX = m_iMResolutionX + 76;
        m_iButtonResolutionY = m_iMResolutionY + 133;
        m_iButtonResolutionADDY = 130;
        m_iButtonW = 461;
        m_iButtonH = 106;
        m_sBackgroundfile = "content/data/Anzeigen/StartBackground.bmp";
        m_sSMenu = "content/data/Menu/SM_Menu.bmp";
        m_sLoadMenu = "content/data/Menu/SlM_Menu.bmp";
        m_sSaveMenu = "content/data/Menu/SpM_Menu.bmp";
        m_sOptionMenu = "content/data/Menu/OM_Menu.bmp";
        m_sCredits = "content/data/Anzeigen/Credits.bmp";
        m_sNewGame = "content/data/Menu/SM_NeuesSpiel.bmp";
        m_sLoad = "content/data/Menu/SM_SpielLaden.bmp";
        m_sCreditsb = "content/data/Menu/SM_Credits.bmp";
        m_sClose = "content/data/Menu/SM_SpielBeenden.bmp";
        m_sSave = "content/data/Menu/OM_SpielSpeichern.bmp";
        m_SSave1 = "content/data/Menu/SpM_SpSt1.bmp";
        m_SSave2 = "content/data/Menu/SpM_SpSt2.bmp";
        m_SSave3 = "content/data/Menu/SpM_SpSt3.bmp";
        m_SSave4 = "content/data/Menu/SpM_SpSt4.bmp";
        m_SSave5 = "content/data/Menu/SpM_SpSt5.bmp";
    }
        

}// SetResoltion

// Init
//
// Aufgabe: Initialisieren
//
void CGame::Init() {
    // Eigene Funktion InitMenus!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
    m_pPlayer->Init();
    m_pPlayer->Reset();
    m_iMouseCorX = 0;
    m_iMouseCorY = 0;

    // Neue Baumenü Instanz initialisieren
    m_pBuildMenu = new CBuildMenu("content/data/Menu/BM_Menu.bmp", 200, 787,  0, 1700 - m_iBMResolutionX, 170 - m_iBMResolutionY);
    m_pBuildMenu->Init();
    // Baumenü Buttons initialisieren
    m_pBuildMenu->SetButton("content/data/Menu/BM_Stufe1.bmp",65,62,0,1733 -m_iBMResolutionX,280 - m_iBMResolutionY,-1);
    //m_pBuildMenu->SetButton("content/data/Menu/BM_Stufe2.bmp",65,62,0,1805,280 - m_iBMResolutionY,0);
    m_pBuildMenu->SetButton("content/data/Menu/BM_Haus.bmp",65,62,0,1733 - m_iBMResolutionX,410 - m_iBMResolutionY,1);
    m_pBuildMenu->SetButton("content/data/Menu/BM_Strasse.bmp",65,62,0,1805 - m_iBMResolutionX,410 - m_iBMResolutionY,2);
    m_pBuildMenu->SetButton("content/data/Menu/BM_Markt.bmp",65,62,0,1733 - m_iBMResolutionX,478 - m_iBMResolutionY,3);
    //m_pBuildMenu->SetButton("content/data/Menu/BM_Tempel.bmp",65,62,0,1805 - m_iBMResolutionX,478 - m_iBMResolutionY,4);
    m_pBuildMenu->SetButton("content/data/Menu/BM_Lager.bmp",65,62,0,1733 - m_iBMResolutionX,546 - m_iBMResolutionY,5);
    m_pBuildMenu->SetButton("content/data/Menu/BM_Haendler.bmp",65,62,0,1805 - m_iBMResolutionX,546,6);
    m_pBuildMenu->SetButton("content/data/Menu/BM_Holz.bmp",65,62,0,1733 - m_iBMResolutionX,614 - m_iBMResolutionY,7);
    m_pBuildMenu->SetButton("content/data/Menu/BM_Palme.bmp",65,62,0,1805 - m_iBMResolutionX,614 - m_iBMResolutionY,8);
    //m_pBuildMenu->SetButton("content/data/Menu/BM_Grube.bmp",65,62,0,1733 - m_iBMResolutionX,682 - m_iBMResolutionY,9);
    //m_pBuildMenu->SetButton("content/data/Menu/BM_Ziegelei.bmp",65,62,0,1805 - m_iBMResolutionX,682 - m_iBMResolutionY,10);
    m_pBuildMenu->SetButton("content/data/Menu/BM_Fischer.bmp",32,31,0,1733 - m_iBMResolutionX,750 - m_iBMResolutionY,11);
    
    //m_pBuildMenu->SetButton("content/data/Map/wasser_ecke_oben_links.bmp",65,62,0,1669,280,50);
    //m_pBuildMenu->SetButton("content/data/Map/wasser_ecke_oben_rechts.bmp",65,62,0,1705,280,51);
    //m_pBuildMenu->SetButton("content/data/Map/wasser_ecke_unten_links.bmp",65,62,0,1669,410,52);
   // m_pBuildMenu->SetButton("content/data/Map/wasser_ecke_unten_rechts.bmp",65,62,0,1705,410,53);
    //m_pBuildMenu->SetButton("content/data/Map/wasser_endgerade_oben_links.bmp",65,62,0,1669,478,54);
   // m_pBuildMenu->SetButton("content/data/Map/wasser_endgerade_oben_rechts.bmp",65,62,0,1705,478,55);
    //m_pBuildMenu->SetButton("content/data/Map/wasser_endgerade_unten_links.bmp",65,62,0,1669,546,56);
    //m_pBuildMenu->SetButton("content/data/Map/wasser_endgerade_unten_rechts.bmp",65,62,0,1705,546,57);
    //m_pBuildMenu->SetButton("content/data/Map/wasser_gerade_links.bmp",65,62,0,1669,614,58);
    //m_pBuildMenu->SetButton("content/data/Map/wasser_gerade_rechts.bmp",65,62,0,1705,614,59);
    //m_pBuildMenu->SetButton("Data/Map/wasser_kurve_links.bmp",65,62,0,1669,682,60);
    //m_pBuildMenu->SetButton("content/data/Map/wasser_kurve_oben.bmp",65,62,0,1705,682,61);
    //m_pBuildMenu->SetButton("content/data/Map/wasser_kurve_rechts.bmp",65,62,0,1669,750,62);
    //m_pBuildMenu->SetButton("content/data/Map/wasser_kurve_unten.bmp",65,62,0,1705,750,63);
    //m_pBuildMenu->SetButton("content/data/Map/wasser_mittelteil.bmp",65,62,0,1669,818,64);
    m_pBuildMenu->SetButton("content/data/Menu/BM_AR.bmp",65,62,0,1784 - m_iBMResolutionX,886 - m_iBMResolutionY,98);
   // m_pBuildMenu->SetButton("content/data/Menu/BM_Blank.bmp",65,62,0,1733,900,14);
    //m_pBuildMenu->SetButton("content/data/Menu/BM_Blank.bmp",65,62,0,1805,900,15);

    // Neue Optionmenü Instanz initialisieren
    m_pOptionMenu = new COptionMenu(m_sOptionMenu, 688, 962,  0, m_iMResolutionX, m_iMResolutionY);
    m_pOptionMenu->Init();
    // OptionMenü Buttons initialisieren
    //m_pOptionMenu->SetButton("Data/Menu/OM_SpielNeustarten.bmp",m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY,1);
    m_pOptionMenu->SetButton(m_sSave,m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY,2);
    // m_pOptionMenu->SetButton("Data/Menu/SM_SpielLaden.bmp",m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY*2,3);
    //m_pOptionMenu->SetButton("Data/Menu/SM_Einstellungen.bmp",m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY*3,4);
    //m_pOptionMenu->SetButton("Data/Menu/Menu_Element_Blank.bmp",m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY*4,5);
    m_pOptionMenu->SetButton(m_sClose,m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY*5,6);

    // Neue Startmenü Instanz initialisieren
    m_pStartMenu = new CStartMenu(m_sSMenu, 688, 962,  0, m_iMResolutionX, m_iMResolutionY);
    m_pStartMenu->Init();
    m_pStartMenu->SetButton(m_sNewGame,m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY,1);
    // m_pStartMenu->SetButton("Data/Menu/SM_Tutorial.bmp",m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY,2);
    m_pStartMenu->SetButton(m_sLoad,m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY*2,3);
    //m_pStartMenu->SetButton("Data/Menu/SM_Einstellungen.bmp",m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY*3,4);
    m_pStartMenu->SetButton(m_sCreditsb,m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,/*715*/m_iButtonResolutionY + m_iButtonResolutionADDY*4,5);
    m_pStartMenu->SetButton(m_sClose,m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,/*845*/ m_iButtonResolutionY + m_iButtonResolutionADDY*5,6);

    // Neue Savemenü Intstanz initialisieren
    m_pSaveMenu = new CSaveMenu(m_sSaveMenu, 688, 962,  0, m_iMResolutionX, m_iMResolutionY);
    m_pSaveMenu->Init();
    m_pSaveMenu->SetButton(m_SSave1,m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY,1);
    m_pSaveMenu->SetButton(m_SSave2,m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY*2,2);
    m_pSaveMenu->SetButton(m_SSave3,m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY*3,3);
    m_pSaveMenu->SetButton(m_SSave4,m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY*4,4);
    m_pSaveMenu->SetButton(m_SSave5,m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY*5,5);

    // Neue Loadmenü Intstanz initialisieren
    m_pLoadMenu = new CLoadMenu(m_sLoadMenu, 688, 962,  0, m_iMResolutionX, m_iMResolutionY);
    m_pLoadMenu->Init();
    m_pLoadMenu->SetButton(m_SSave1,m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY,1);
    m_pLoadMenu->SetButton(m_SSave2,m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY*2,2);
    m_pLoadMenu->SetButton(m_SSave3,m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY*3,3);
    m_pLoadMenu->SetButton(m_SSave4,m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY*4,4);
    m_pLoadMenu->SetButton(m_SSave5,m_iButtonW,m_iButtonH,0,m_iButtonResolutionX,m_iButtonResolutionY + m_iButtonResolutionADDY*5,5);
    
    // Bildschirm Auflösung und Framses setzen
    m_iScreenWright = 1920;
    m_iScreenHight = 1080;
    m_iScreenFramen = 4;

    // Start Hingergrund Sprite laden
    m_pStartBackground = new CSprite;
    m_pStartBackground->Load(m_sBackgroundfile);
    m_pStartBackground->SetPos(m_iSBResolutionX,m_iSBResolutionY);

    // Credits Sprite laden
    m_pCredits = new CSprite;
    m_pCredits->Load(m_sCredits);
    m_pCredits->SetPos(m_iMResolutionX, m_iMResolutionY);
    m_pCredits->SetColorKey(0,0,0);

    // Map (Sprite) laden
    m_pSpriteBackground = new CSprite;
    m_pSpriteBackground->Load("content/data/Map/testmap1.bmp", m_iScreenFramen, m_iScreenWright, m_iScreenHight);


    m_pPlayer->Init();
    
    // Spiel läuft
    m_bGameRun = true;
    // Baumenü ist geschlossen
    m_bMenueGRun = false;
    // Gebäude kann nicht plaziert werden
    m_bBuild = false;
    m_bOption = false;
    m_bShowRes = false;
    m_bSaveaktiv = false;
    m_bSetSaveaktiv = false;
    m_bLoadaktiv = false;
    m_bSetLoadaktiv = false;
    m_bCreditsaktiv = false;
    m_bDestroyaktiv = false;
    m_bDestroisaktiv = false;
    m_bBuildElements_1 = true;
    m_bStopBuild = false;

    m_iMenuRun = 1;
    m_iMenuGo = 0;

    m_bXSc = 50;
    m_bYSc = 50;

    
    
} // Init

// InitBuildElements
//
// Aufgabe: Init. Bauauswahl nach Einwohnerzahl
//
void CGame::InitBuildElements(){

    if(m_pPlayer->getBuildElement_1() && m_bBuildElements_1){
        m_pBuildMenu->SetButton("content/data/Menu/BM_ZFarm.bmp",65,62,0,1805 - m_iBMResolutionX,750 - m_iBMResolutionY,12);
        m_pBuildMenu->SetButton("content/data/Menu/BM_Zfeld.bmp",65,62,0,1733 - m_iBMResolutionX,818 - m_iBMResolutionY,16);
        m_bBuildElements_1 = false;
    }

}// InitBuildElements

// SetResolution
//
// task: set the resolution of the movement
//
void CGame::SetMoveResolution(int X, int Y){

    switch(X){
        case(1920):
            m_iMoveResolutionX = 0;
            break;
        case(1680):
            m_iMoveResolutionX = 240;
            break;
        case(1440):
            m_iMoveResolutionX = 480;
            break;
        case(1280):
            m_iMoveResolutionX = 640;
            break;
        case(1240):
            m_iMoveResolutionX = 680;
            break;
        case(1024):
        default:
            m_iMoveResolutionX = 896;
            break;
    }// switch X

    switch(Y){
        case(1080):
            m_iMoveResolutionY = 0;
            break;
        case(900):
            m_iMoveResolutionY = 150;
            break;
        case(800):
        default:
            m_iMoveResolutionY = 250;
            break;
    }// switch X

}// SetResoltion

// Quit
//
// Aufgabe: Instanzen freigeben
//
void CGame::Quit() {
    // Spieler freigeben
    if (m_pPlayer != NULL) {
        m_pPlayer->Quit();
        delete (m_pPlayer);
        m_pPlayer = NULL;
    }
    delete m_pField;

    // Hintergrundsprite freigeben
    if (m_pSpriteBackground != NULL) {
        delete (m_pSpriteBackground);
        m_pSpriteBackground = NULL;
    }

    delete (m_pOptionMenu);
    delete (m_pBuildMenu);
    delete m_pSaveMenu;
    delete m_pLoadMenu;
    delete m_pCredits;
    //delete m_pStartMenu;

} // Quit

// Run
//
// Aufgabe: Hauptschleife des Spiels
//
void CGame::Run() {

    //cout << "FPS" << m_fFPS << endl;
    m_oldtime = time(NULL) / 1000;
    

    // Hauptschleife des Spiels durchlaufen
    //
    while (m_bGameRun == true) {

        // Events bearbeiten
        EventHandler();

        // Framework updaten und Buffer löschen
        g_pFramework->Update();
        g_pFramework->Clear();

      
        // Mausposition abfragen
        // g_pFramework->GetMousePosition(m_bmausX, m_bmausY);
        SDL_GetMouseState(&m_bmausX, &m_bmausY);
        m_pPlayer->setMausPos(m_bmausX, m_bmausY);

        // Ausführen des Menüs
        if (m_iMenuRun == 1 && (m_currenttime = (time(NULL) - m_oldtime)) >= m_fFPS){
            //cout << "current: " << m_currenttime << endl;
            m_pStartBackground->Render();
            m_pStartMenu->Render();
            m_pStartMenu->RenderButtons();
        }
        if(m_bSetLoadaktiv){
            if(m_currenttime = (time(NULL) - m_oldtime)>= m_fFPS)
                m_pStartBackground->Render();
            m_bLoadaktiv = true;
            m_bSetLoadaktiv = false;
        }
        if(m_bLoadaktiv && (m_currenttime = (time(NULL) - m_oldtime)) >= m_fFPS){
            m_pStartBackground->Render();
            m_pLoadMenu->Render();
            m_pLoadMenu->RenderButtons();
        }
        if(m_bCreditsaktiv && (m_currenttime = (time(NULL) - m_oldtime)) >= m_fFPS){
            m_pStartBackground->Render();
            m_pCredits->Render();
        }
        else if (m_iMenuRun == 0) {

        
            // Hintergrund setzen und rendern
            if((m_currenttime = (time(NULL) - m_oldtime)) >= m_fFPS){
                 m_pSpriteBackground->SetPos(m_bXSc + m_iMouseCorX, m_bYSc + m_iMouseCorY);
                 m_pSpriteBackground->Render();
                 m_pPlayer->Render(m_bShowRes, m_iMouseCorX, m_iMouseCorY, m_pField);
            }
           
            // Events bearbeiten
            EventHandler();

            // Bei Drücken der Taste 'l' Lager Fenster öffnen
            // Gebäude kann plaziert werden
            if (m_bBuild == true && (m_currenttime = (time(NULL) - m_oldtime)) >= m_fFPS) {
                m_pPlayer->Render(m_bShowRes, m_iMouseCorX, m_iMouseCorY, m_pField);

            }
            
            // Bei Drücken der Taste 'o' Optionsmenü öffnen
            if (m_bOption == true && (m_currenttime = (time(NULL) - m_oldtime)) >= m_fFPS){
                m_pOptionMenu->Render();
                m_pOptionMenu->RenderButtons();
            }
            if(m_bSetSaveaktiv){
                m_bSaveaktiv = true;
                m_bSetSaveaktiv = false;
            }
                
            // Bei Auswahl des Speichermenüs
            if(m_bSaveaktiv && (m_currenttime = (time(NULL) - m_oldtime)) >= m_fFPS){
                m_pSaveMenu->Render();
                m_pSaveMenu->RenderButtons();
            }

            InitBuildElements();
            //  Bei Drücken der 'b' Taste wird Baumenü geöffnet und Auswahl kann
            // getroffen werden
            if (m_bMenueGRun == true) {
                if((m_currenttime = (time(NULL) - m_oldtime)) >= m_fFPS){
                    m_pBuildMenu->Render();
                    m_pBuildMenu->RenderButtons();
                }
                m_bMenueGRun = m_pPlayer->GetBuildclose();
                m_bBuild = m_pPlayer->GetBuild();
            }
            
            if(m_bDestroyaktiv){
                m_bDestroisaktiv = true;
                m_bDestroyaktiv = false;
            }

            CheckPositions();
            
         }
        // Events bearbeiten
        EventHandler();
        m_oldtime = time(NULL) / 1000;
        // Buffer flippen
        g_pFramework->Flip();

          // Events bearbeiten
        EventHandler();
   
    }


} // Run

// CheckPosition
//
// Aufgabe: Position und Animationsphase prüfen
//
void CGame::CheckPositions() {

    /*cout << "mousecorx" << m_iMouseCorX << endl;
    cout << "mousecory" << m_iMouseCorY << endl;
    cout << "mouseX" << m_bmausX << endl;
    cout << "mouseY" << m_bmausY << endl;*/

    if(m_iMouseCorX > -10.0f)
        m_iMouseCorX = -8.0f;

    if(m_iMouseCorY > -10.0f)
        m_iMouseCorY = -8.0f;

    if(m_iMouseCorX < -1050.0f)
        m_iMouseCorX = -1048.0f;

    if(m_iMouseCorY < -1150.0f)
        m_iMouseCorY = -1148.0f;

    // Linker und rechter Rand
    if (m_bmausX < 10.0 || g_pFramework->KeyDown(SDLK_LEFT)  )
        m_iMouseCorX += 300.0f * g_pTimer->GetElapsed();
    else if (m_bmausX > 1900.0 - m_iMoveResolutionX|| g_pFramework->KeyDown(SDLK_RIGHT) )
        m_iMouseCorX -= 500.0f * g_pTimer->GetElapsed();

    // Oberer und unterer Rand
    else if(m_bmausY < 10.0 || g_pFramework->KeyDown(SDLK_UP) )
        m_iMouseCorY += 300.0f * g_pTimer->GetElapsed();
    else if (m_bmausY > 1000.0 -m_iMoveResolutionY || g_pFramework->KeyDown(SDLK_DOWN) )
        m_iMouseCorY -= 500.0f * g_pTimer->GetElapsed();

    // links oben
    if ((m_bmausX < 10.0 && m_bmausY < 10.0) || (g_pFramework->KeyDown(SDLK_LEFT)  && g_pFramework->KeyDown(SDLK_UP))){
        m_iMouseCorX += 300.0f * g_pTimer->GetElapsed();
        m_iMouseCorY += 300.0f * g_pTimer->GetElapsed();
    }// links oben
    // links unten
    if ((m_bmausX < 10.0 && m_bmausY > 1000.0 -m_iMoveResolutionY) ||
            (g_pFramework->KeyDown(SDLK_LEFT)  && g_pFramework->KeyDown(SDLK_DOWN))){
        m_iMouseCorX += 300.0f * g_pTimer->GetElapsed();
        m_iMouseCorY -= 500.0f * g_pTimer->GetElapsed();
    }// links unten

    //rechts oben
    if ((m_bmausX > 1900.0 - m_iMoveResolutionX && m_bmausY < 10.0) ||
            (g_pFramework->KeyDown(SDLK_RIGHT)  && g_pFramework->KeyDown(SDLK_UP))){
        m_iMouseCorX -= 500.0f * g_pTimer->GetElapsed();
        m_iMouseCorY += 300.0f * g_pTimer->GetElapsed();
    }// rechts oben
    // rechts unten
    if ((m_bmausX > 1900.0 - m_iMoveResolutionX && m_bmausY > 1000.0 -m_iMoveResolutionY) ||
            (g_pFramework->KeyDown(SDLK_RIGHT)  && g_pFramework->KeyDown(SDLK_DOWN))){
        m_iMouseCorX -= 500.0f * g_pTimer->GetElapsed();
        m_iMouseCorY -= 500.0f * g_pTimer->GetElapsed();
    }// rechts unten

} // CheckPosition

// EventHandler
//
// Aufgabe: Events bearbeiten
//
void CGame::EventHandler() {
    SDL_Event Event;

    // Gab es ein Event?
    if (SDL_PollEvent(&Event)) {
        // Ja, also schauen welches
        switch (Event.type) {
                // Beenden?
            case (SDL_QUIT):
            {
                m_bGameRun = false;

            }
            break;


                // Wurde eine Taste gedrückt?
            case (SDL_KEYDOWN):
            {
                switch (Event.key.keysym.sym) {
                    case (SDLK_ESCAPE):
                        // ESC wurde gedrück also Menüs beenden
                         m_bMenueGRun = false;
                         m_bOption = false;
                         m_bSaveaktiv = false;
                         m_bCreditsaktiv = false;
                         m_bDestroyaktiv = false;
                         if(m_bLoadaktiv){
                             m_bLoadaktiv = false;
                             m_bMenueGRun = true;
                         }
                        break;
                    case (SDLK_o):
                        // o wurde gedrückt also Optionsmenü aktivieren
                        if(m_bOption == true || m_iMenuRun == 1)
                            m_bOption = false;
                        else
                            m_bOption = true;
                        break;
                    case (SDLK_b):
                        // b wurde gedrückt also Baummenü aktivieren
                        if( m_bMenueGRun == true && m_bBuild == false ||
                                m_iMenuRun == 1)
                             m_bMenueGRun = false;
                        else if(m_bMenueGRun == false && m_bBuild == false)
                             m_bMenueGRun = true;
                        break;
                    case(SDLK_l):
                        // l wurde gedrückt also Lager Fenster aktivieren
                        if(m_bShowRes == true || m_iMenuRun == 1)
                            m_bShowRes = false;
                        else
                            m_bShowRes = true;
                        break;
                }

            }
            break;

            // Wurde eine Maustaste gedrückt?
            case(SDL_MOUSEBUTTONDOWN):
                switch (Event.button.button){
                    case(SDL_BUTTON_LEFT):
                        // Mausposition abfragen
                        // g_pFramework->GetMousePosition(m_bmausX, m_bmausY);
                        SDL_GetMouseState(&m_bmausX, &m_bmausY);
                        m_pPlayer->setMausPos(m_bmausX, m_bmausY);
                        if(!m_bMenueGRun && !m_bOption && !m_bSaveaktiv && !m_bLoadaktiv && !m_bDestroisaktiv)
                            m_pPlayer->ChooseBuild(m_bmausX,m_bmausY);
                        if(m_bMenueGRun){
                            m_pBuildMenu->BuildSelected(m_pPlayer,m_bmausX,m_bmausY,
                                    65,62,m_bDestroyaktiv,m_bStopBuild);
                        }
                        if(m_bOption){
                            m_pOptionMenu->Option(m_pPlayer,m_bmausX,m_bmausY,
                                    m_bGameRun, m_bSetSaveaktiv, m_bOption, 461,106);
                        }
                        if(m_iMenuRun == 1 && !m_bLoadaktiv){
                            m_pStartMenu->Option(m_pPlayer,m_bmausX,m_bmausY,
                                    m_iMenuRun, m_bSetLoadaktiv, m_bGameRun,
                                    m_bCreditsaktiv,461,106,m_pStartBackground, m_pField);
                        }
                        if(m_bSaveaktiv){
                            m_pSaveMenu->Save(m_pPlayer,m_bmausX,m_bmausY,
                                    461,106, m_bSaveaktiv, m_pField);
                        }
                        if(m_bLoadaktiv){
                            m_pLoadMenu->Load(m_pPlayer,m_bmausX,m_bmausY,
                                    461,106, m_bLoadaktiv, m_iMenuRun, m_pField);
                        }
                        if(!m_bOption && !m_bSaveaktiv &&
                                !m_bLoadaktiv && !m_bDestroisaktiv&& m_bBuild){
                            m_pPlayer->ProcessBuild(m_iMouseCorX, m_iMouseCorY, m_bmausX, m_bmausY, m_pField);
                            m_bBuild = m_pPlayer->GetBuild();
                        }
                        if(m_bDestroisaktiv && m_bMenueGRun && !m_bOption && !m_bSaveaktiv){
                            SDL_GetMouseState(&m_bmausX, &m_bmausY);
                            m_pPlayer->setMausPos(m_bmausX, m_bmausY);
                           //m_pCurser->DestroyBuild(m_pCurser->ChooseBuild(m_bmausX,m_bmausY));
                            m_pPlayer->DestroyBuild(m_pField);
                           m_bDestroisaktiv = m_pPlayer->GetBuild();
                        }
                    break;
                  case(SDL_BUTTON_RIGHT):
                      if(m_bStopBuild){
                          m_pPlayer->setMenuLock2(false);
                          m_pPlayer->Init();
                          m_bBuild = false;
                          m_bDestroisaktiv = false;
                          m_iMenuRun = false;
                          m_pPlayer->setRasterMouse(false);
                      }// if
                      break;
                }
                break;
        }
    }

} // ProcessEvents

