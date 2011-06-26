#ifndef SPRITE_H
#define SPRITE_H

#include "Framework.h"

class CSprite {
public:
    CSprite();
    ~CSprite();

    void Load(const string sFilename);
    void Load(const string sFilename, int NumFrames,
            int FrameWidth, int FrameHeight);
    void SetColorKey(int R, int G, int B);
    void SetPos(float fXPos, float fYPos);
    void Render();
    void Render(float fFrameNumber);
    //void Render(int test);

    SDL_Rect GetRect() {
        return m_Rect;
    }

    inline int getXPos(){return m_Rect.x;}
    inline int getYPos(){return m_Rect.y;}

private:
    SDL_Surface *m_pScreen; // Zeiger auf den Screen des Frameworks
    SDL_Surface *m_pImage; // Das eigentliche Bild des Sprites
    SDL_Rect m_Rect; // Rect des Sprites
    SDL_Rect m_FrameRect; // Ausschnitt für Animationsphase
    int m_NumFrames; // Anzahl der Animationsphasen
    int m_FrameWidth; // Breite einer Animationsphase
    int m_FrameHeight; // Höhe einer Animationsphase
    int m_NumFramesX; // Wie viele Anim-Phasen in X-Richtung?

};

#endif