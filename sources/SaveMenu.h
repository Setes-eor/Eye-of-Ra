/* 
 * File:   SaveMenu.h
 * Author: setes
 *
 * Created on 14. Februar 2011, 21:21
 */

#ifndef SAVEMENU_H
#define	SAVEMENU_H

#include "Menu.h"
#include "Player.h"
#include <string.h>

class CSaveMenu : public CMenu{

public:
    CSaveMenu();
    CSaveMenu(string, int, int, int, int, int);
    ~CSaveMenu();
    void Init();
    void Save(CPlayer *, const int ,const int ,const int, const int, bool &,
    CField*);

};

#endif	/* SAVEMENU_H */

