#ifndef BUDCOUNTER_H
#define BUDCOUNTER_H

#include "Sprite.h"

class CBudcounter {
public:
    void Init(CSprite *pSpriteCounter, float fXPos, float fYPos);
    void Update(float m_fAnimP);
    void Render(float m_fAnimP);
private:
    CSprite *m_pSpriteCounter; // Zeiger auf Zahlen-Sprite
    float m_fXPos; // X-Position
    float m_fYPos; // Y-Position
    float m_fAnimPhase; // Animationsphase

};

#endif