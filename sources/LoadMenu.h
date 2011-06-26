/* 
 * File:   LoadMenu.h
 * Author: setes
 *
 * Created on 15. Februar 2011, 10:47
 */

#ifndef LOADMENU_H
#define	LOADMENU_H

#include "Menu.h"
#include "Player.h"
#include <string.h>

class CLoadMenu : public CMenu{

public:
    CLoadMenu();
    CLoadMenu(string, int, int, int, int, int);
    ~CLoadMenu();
    void Init();
    void Load(CPlayer *, const int ,const int ,const int, const int, bool &,
    int &, CField*);

};

#endif	/* LOADMENU_H */

