#ifndef Player_H
#define Player_H

#include <list>
#include "PlayerBasic.h"
#include "Sprite.h"
#include "Builds.h"
#include "Budget.h"
#include "BudgetDisplay.h"
#include "Field.h"
#include "FieldInfo.h"

//#include <windows.h>

class CPlayer : public CPlayerBasic{
public:
    void CheckPosition();
    CPlayer(int,int, CField*);
    //void SetMoveResolution(int,int);
    void Init();
    void ChangeCurserPic();
    void Quit();
    void Render(bool, int, int, CField*);
    void BuildsUpdate(int,int);
    void Reset();
    int ChooseBuild(float,float);
    void DestroyBuild(CField*);
    void Save(const int, char *, CField*);
    void Load(const int, char *, CField*);

    inline bool GetBuildElement(){return m_iBuildElements_1;}
    inline bool GetBuildclose() {return m_bMenueGLock;}
    inline bool GetBuild() {return m_bMenueGLock2;}
    inline int const SetID()const {return m_iCostId;}
    inline void setMausPos(int const x, int const y) {m_bmausX = x;m_bmausY = y;}
    inline void setBuildID(const Buildtyp ID){m_buildname = ID;}
    
    inline list<CBuilds> *GetBuildsList() {return &m_BuildsList;}
    inline void setRasterMouse(bool set){m_bRasterMouse = set;}
 
    void costs();
    bool m_bLoad;
        
private:
    // Sprite-Pointers
    CSprite *m_pSpriteCurser; // Sprite für Spieler

    // Instanzen anderer Klassen
    CBudgetDisplay *m_pBudgetDisplay;
    


    float m_fAnimPhase; // Aktuelle Animationsphase
    bool m_bBuildLock; // Darf das nächste Gebäude plaziert werden?
    
    bool m_bRasterMouse;
    bool m_bBudgetEn; // Genung Budget
    int m_iBuildID; // Gebäude ID für Wegfindung
    int m_iCostId; // Gebäude ID für Baukosten
    Uint8 buttons; // Mausbuttons
    // Kooridnaten Variablen
    float m_fXPos, m_fYPos; // Position des Spielers
    int m_bmausX, m_bmausY; // Maus Position
    
    int m_iBudgetSize; // Varibale für Lagerbestand
    bool m_iBuildElements_1;
    


};

#endif