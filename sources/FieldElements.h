/* 
 * File:   FieldElements.h
 * Author: setes
 *
 * Created on April 16, 2011, 10:52 AM
 */

#ifndef FIELDELEMENTS_H
#define	FIELDELEMENTS_H

#include "FieldInfo.h"

class CFieldElements : public CFieldInfo{
private:
    FieldState m_State;      // Feld blockiert oder nicht
    Buildtyp m_Build;
    Terraintyp m_tTerrain;
public:
    CFieldElements();
    CFieldElements(FieldState, Buildtyp, Terraintyp);
    //~CFieldElements();
    bool isFreeToBuild(FieldState);
    inline void setFieldstate(const FieldState block){m_State = block;}
    inline const FieldState getFieldstate()const{return m_State;}
    void setBuildtyp(const Buildtyp build, const bool destroy);
    inline const Buildtyp getBuildtyp()const{return m_Build;}
    void setTerraintyp(const Terraintyp terrain);
    inline const Terraintyp getTerraintyp()const{return m_tTerrain;}

};


#endif	/* FIELDELEMENTS_H */

