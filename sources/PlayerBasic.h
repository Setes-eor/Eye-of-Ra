/* 
 * File:   PlayerBasic.h
 * Author: setes
 *
 * Created on May 15, 2011, 9:49 AM
 */

#ifndef PLAYERBASIC_H
#define	PLAYERBASIC_H

#include <list>
#include <string>
#include "Budget.h"
#include "Builds.h"
#include "Field.h"

class CPlayerBasic : public CFieldInfo{
protected:
    CBudget *m_pBudget;         // Ressourcen der KI
    list<CBuilds> m_BuildsList; // Liste der Gebäude(Grafik)
    Buildtyp m_buildname;


    int m_PersonellBuildID; // Spezielle ID der Gebäude
    
    bool m_bMenueGLock;
    bool m_bMenueGLock2;


public:
    CPlayerBasic();
    ~CPlayerBasic();
    void InitBudget(int, unsigned int, unsigned int, unsigned int,
    unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
    unsigned int);
    void ProcessBuild(int, int, int, int, CField*);
    void SetBuild(int, int, int, int, Buildtyp, string path, CField*, int, int,
    int , int, int, int, int,int, int);
    void AddBuild(CBuilds);
    void RenderBuilds(int,int,CField*);
    inline const bool getBuildElement_1()const{return m_pBudget->getBuildElement_1();}

    inline void setMenuLock1(bool Lock){m_bMenueGLock = Lock;}
    inline void setMenuLock2(bool Lock){m_bMenueGLock2 = Lock;}
};

#endif	/* PLAYERBASIC_H */

