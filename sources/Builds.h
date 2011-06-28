#ifndef BUILDS_H
#define BUILDS_H

#include <time.h>
#include "MenuElements.h"
#include "Sprite.h"
#include "Budget.h"
#include "BuildsEnum.h"

using namespace std;

class CBuilds : public CMenuElements{
public:
    CBuilds();
    void Init(string, float , float , Buildtyp , int, int, int, int);
    void Update(float XPos, float YPos);
    void Render();
    void destroy();

    inline bool const IsAlive()const {return m_bIsAlive;}
    inline void SetAlive(bool const bIsAlive) {m_bIsAlive = bIsAlive;}
    inline Buildtyp const GetID()const {return m_buildname;}
    inline int const GetPID()const {return m_iPersonellID;}
    inline float const GetX()const{return (m_fXPos + m_fXPosv);}
    inline float const GetY()const {return (m_fYPos + m_fYPosv);}
    inline float const GetXStart()const {return m_fXPos;}
    inline float const GetYStart()const {return m_fYPos;}
    inline SDL_Rect const GetRect()const {return m_Rect;}
    inline void SetValue(int Value){m_iProductValue = Value;}
    inline void BetterTime (const int Time){m_iProTime += Time;}
    inline const float GetYRender()const{return m_fYRenderPos;}
    void CountRessources(CBudget *);
protected:
    CSprite *m_pSpriteBuilds; // Zeiger auf Gebäude-Sprite
    Buildtyp m_buildname;
    int m_iPersonellID; // Spezielle ID für das Gebäude
    float m_fXPos; // X-Position des Gebäudes
    float m_fYPos; // Y-Position des Gebäudes
    float m_fXPosv;
    float m_fYPosv;
    float m_fYRenderPos;
    int m_iProductValue; // produzierte Güter
    int m_iMoney;
    int m_iProTime;  // Zeit in der die Güter produziert werden
    bool m_bIsAlive; // Gebäude noch nicht abgerissen
    string m_sFile;
    SDL_Rect m_Rect; // Rect des Gebäudes

    // Timer
    CTimer *m_pTimer;

    time_t m_oldtime;
    time_t m_currenttime;

};

#endif

