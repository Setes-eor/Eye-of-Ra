#ifndef GAME_H
#define GAME_H

#include "BuildMenu.h"
#include "StartMenu.h"
#include "OptionMenu.h"
#include "SaveMenu.h"
#include "LoadMenu.h"
#include "GrafikMenu.h"
#include "Menu.h"
#include "Player.h"
#include "Field.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class CGame {
public:
    CGame();
    void SetResolution(int,int);
    void Init();
    void InitBuildElements();
    void SetMoveResolution(int, int);
    void CheckPositions();
    void Run();
    void Quit();
    void Menu();

private:
    void EventHandler();

    CPlayer *m_pPlayer; // Spieler-Instanz
    CSprite *m_pStartBackground; // Sprite des Starthintergrundes
    CSprite *m_pSpriteBackground; // Sprite für den Hintergrund
    CSprite *m_pCredits; // Sprite für die Credits
    CBuildMenu *m_pBuildMenu;
    COptionMenu *m_pOptionMenu;
    CSaveMenu *m_pSaveMenu;
    CLoadMenu *m_pLoadMenu;
    CStartMenu *m_pStartMenu;
    CField *m_pField;

    int m_iMoveResolutionX;
    int m_iMoveResolutionY;
    int m_iMouseCorX, m_iMouseCorY;
    int m_iBMResolutionX; // build menu resolution
    int m_iBMResolutionY; // build menu resolution
    int m_iSBResolutionX; // background resolution
    int m_iSBResolutionY; // background resolution
    int m_iMResolutionX;  // menu resolutions
    int m_iMResolutionY;  // menu resolutions
    int m_iButtonResolutionX; // menu buttons resolutions
    int m_iButtonResolutionY; // menu buttons resolutions
    int m_iButtonResolutionADDY; // menu buttons resolutions
    int m_iButtonW;              // menu buttons weight
    int m_iButtonH;              // menu buttons hight
    int m_iScreenWright; // Bildschirm Weite
    int m_iScreenHight; // Bildschirm Höhe
    int m_iScreenFramen; // Bildschrim Frame
    bool m_bGameRun; // Läuft das Spiel noch?
    bool m_bMenueGRun; // Ist Baumenü geöffnet
    bool m_bBuild; // Kann Gebäude plaziert werden
    bool m_bOption; // Variable für aktiviertes Optionsmenü
    bool m_bShowRes; // Variable für das aktivieren des Lager Fensters
    bool m_bSaveaktiv; // Save Menü Variable
    bool m_bSetSaveaktiv;
    bool m_bLoadaktiv; // Load Menü Variable
    bool m_bSetLoadaktiv;
    bool m_bCreditsaktiv;
    bool m_bDestroyaktiv; // Bei true ist abreißen möglich
    bool m_bDestroisaktiv;
    bool m_bBuildElements_1;
    bool m_bStopBuild;
    int m_iMenuRun; // Menü laufvariable
    int m_iMenuGo; // Menü Variable
    Uint8 buttons; // Mausbuttons
    int m_bmausX; // X Position Maus
    int m_bmausY; // Y Position Maus
    int m_bXSc; // X für Map Scrolling
    int m_bYSc; // Y für Map Scrolling
    string m_sBackgroundfile;
    string m_sSMenu;
    string m_sLoadMenu;
    string m_sSaveMenu;
    string m_sOptionMenu;
    string m_sCredits;
    string m_sNewGame;
    string m_sLoad;
    string m_sCreditsb;
    string m_sClose;
    string m_sSave;
    string m_SSave1;
    string m_SSave2;
    string m_SSave3;
    string m_SSave4;
    string m_SSave5;

    time_t m_oldtime;
    time_t m_currenttime;
    double m_fFPS;
    

    int mtest;

};

#endif