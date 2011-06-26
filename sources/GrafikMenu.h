/* 
 * File:   GrafikMenu.h
 * Author: setes
 *
 * Created on 16. Februar 2011, 11:49
 */

#ifndef GRAFIKMENU_H
#define	GRAFIKMENU_H

#include <string.h>
#include <stdio.h>
#include "Menu.h"
#include "Player.h"

class CGrafikMenu : public CMenu{

public:
    CGrafikMenu();
    CGrafikMenu(string, int, int, int, int, int);
    ~CGrafikMenu();
    void Init();
    void Option(const int ,const int ,bool&, const int, const int);

};

#endif	/* GRAFIKMENU_H */

