/* 
 * File:   BuildMenu.h
 * Author: setes
 *
 * Created on 1. Februar 2011, 10:35
 */

#ifndef BUILDMENU_H
#define	BUILDMENU_H

#include "Menu.h"
#include "Player.h"
#include "BuildsEnum.h"

class CBuildMenu: public CMenu{
private:
    Buildtyp buildname;
public:
    CBuildMenu();
    CBuildMenu(string, int, int, int, int, int);
    ~CBuildMenu();
    void BuildSelected(CPlayer *, const int,const int,const int, const int, bool &,bool &);
    
};

#endif	/* BUILDMENU_H */

