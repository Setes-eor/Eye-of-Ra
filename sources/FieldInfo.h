/* 
 * File:   FieldInfo.h
 * Author: setes
 *
 * Created on April 16, 2011, 11:10 AM
 */

#ifndef FIELDINFO_H
#define	FIELDINFO_H

#include "BuildsEnum.h"

class CFieldInfo{
public:
    enum Terraintyp{sand,water,stones,ttree,tstreet}; // Werte für Terraintyp
    enum FieldState{blocked,free,freeforhouses,freeforbuilds,freeforboth};
};

#endif	/* FIELDINFO_H */

