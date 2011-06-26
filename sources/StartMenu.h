#ifndef STARTMENU_H
#define STARTMENU_H

#include <string.h>
#include "Menu.h"
#include "Player.h"

class CStartMenu : public CMenu{

public:
    CStartMenu();
    CStartMenu(string, int, int, int, int, int);
    ~CStartMenu();
    void Init();
    void Option(CPlayer *, const int ,const int , int &, bool &, bool &, bool &,
    const int, const int, CSprite *, CField*);

};

#endif