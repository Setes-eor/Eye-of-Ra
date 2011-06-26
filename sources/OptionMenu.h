/* 
 * File:   OptionMenu.h
 * Author: setes
 *
 * Created on 14. Februar 2011, 17:44
 */

#ifndef OPTIONMENU_H
#define	OPTIONMENU_H

#include "Menu.h"
#include "Player.h"

class COptionMenu : public CMenu{

public:
    COptionMenu();
    COptionMenu(string, int, int, int, int, int);
    ~COptionMenu();
    void Init();
    void Option(CPlayer*, const int, const int, bool &, bool &, bool &,
    const int, const int);

};

#endif	/* OPTIONMENU_H */

