#include "PlayerBasic.h"

// Konstruktor
//
CPlayerBasic::CPlayerBasic(){
    m_pBudget = new CBudget();

}// Konstruktor

// Destruktor
//
CPlayerBasic::~CPlayerBasic(){

    delete m_pBudget;
}// Destruktor

// InitBudget
//
// Aufgabe: Legt die Startressourcen fest
//
void CPlayerBasic::InitBudget(int money = 0, unsigned int inhabs1 = 0,
        unsigned int inhabs2 = 0, unsigned int wood = 0, unsigned int brick = 0,
        unsigned int slime = 0, unsigned int tools = 0, unsigned int fish = 0,
        unsigned int milk = 0, unsigned int stone = 0){

    m_pBudget->InitResources(money, inhabs1, inhabs2, wood, brick, slime, tools,
            fish, milk, stone);
}// InitBudget

// AddBuild
//
// Aufgabe: Fügt ein Gebäude in der Gebäudeliste der KI ein
//
void CPlayerBasic::AddBuild(CBuilds build){
    list<CBuilds>::iterator it = m_BuildsList.begin();

   if(m_BuildsList.empty())
                        m_BuildsList.push_back(build);
                    else{
                        while(it != m_BuildsList.end()){
                            if(build.GetYRender() <= it->GetYRender() && it->GetID() != 14 && it->GetID() != 15){
                                m_BuildsList.insert(it, build);
                                break;
                            }// if
                              it++;
                        }// while
                    }// else
}// AddBuild

// ProcessBuild
//
// Aufgabe: Gebäude wird platziert und angelegt
//
void CPlayerBasic::ProcessBuild(int mouseCorX, int mouseCorY, int mouseX, int mouseY, CField* field) {


    string path = "";
    int money = 0;
    int wood = 0;
    int brick = 0;
    int stones = 0;
    int pValue = 0;
    int pMoney = 0;
    int pTime = 0;
    int mfactor = 0;
    int pfactor = 0;

        switch (m_buildname) {
            case(house): // Wohnhaus
                path = "content/data/Buildings/woodf.bmp";
                wood = 5;
                pfactor = 1;
                break;
            case(street): // Straße
                path = "content/data/Buildings/gerade_links.bmp";
                money = 2;
                break;
            case(market): // Markt
                path = "content/data/Buildings/markt.bmp";
                money = 75;
                wood = 15;
                pTime = 10;
                pMoney = 2;
                break;
            case(temple): // Tempel I
                path = "content/data/Buildings/woodf.bmp";
                money = 65;
                wood = 10;
                brick = 5;
                pTime = 10;
                pMoney = 10;
                break;
            case(storage): // Lager
                path = "content/data/Buildings/warenhaus.bmp";
                money = 75;
                wood = 10;
                pTime = 10;
                pMoney = 2;
                break;
            case(trader): // Handelszentrum
                path = "content/data/Buildings/woodf.bmp";
                money = 65;
                wood = 10;
                pTime = 10;
                pMoney = 2;
                break;
            case(lumberjack): // Holzfäller
                path = "content/data/Buildings/lumber.bmp";
                money = 50;
                wood = 2;
                pTime = 20;
                pMoney = 5;
                break;
           case(tree): // Palmen
                path = "content/data/Buildings/palmen_raster.bmp";
                money = 10;
                break;
            case(slimegrave): // Nilschlammgrube
                path = "content/data/Buildings/woodf.bmp";
                money = 20;
                wood = 5;
                pValue = 5;
                pTime = 10;
                pMoney = 5;
                break;
            case(brickmaker):// Ziegelei --> Erst produzieren wenn genug Schlamm da!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                path = "content/data/Buildings/woodf.bmp";
                money = 50;
                wood = 10;
                pValue = 5;
                pTime = 10;
                pMoney = 10;
                break;
            case(fisher): // Fischer
                path = "content/data/Buildings/fischerhaus.bmp";
                money = 50;
                wood = 10;
                pValue = 5;
                pTime = 10;
                pMoney = 5;
                break;
            case(milkfarm): // Ziegenfarm
                path = "content/data/Buildings/farmhaus.bmp";
                money = 75;
                wood = 10;
                pTime = 10;
                pMoney = 10;
                break;
            case(milkfield): // Ziegenfarmfeld
                path = "content/data/Buildings/ziegenfarmfeld.bmp";
                money = 10;
                break;
            case(center): // Zentrum kann vom Spieler nicht erichtet werden
                path = "content/data/Buildings/center.bmp";
                break;
            default:
            //Init();
                    // Fehler behandeln
                    cout << "Gebäude kann nicht gebaut werden; Gebäude ID: " << m_buildname <<
                    " ist ungültig" << endl;
            break;
    }// switch

    SetBuild(mouseCorX,mouseCorY,mouseX,mouseY,m_buildname,path,field,money,wood,brick,
            stones,pValue,pTime,pMoney,mfactor,pfactor);

   
            //Init();
            //  // Bamenü kann wieder verwendet werden
            //m_bMenueGLock = true;
            //m_bMenueGLock2 = false;
            //}// if
    if (g_pFramework->KeyDown(SDLK_b)) {
        //Init();
                m_bMenueGLock = true;
                m_bMenueGLock2 = false;
    }
           
} // ProcessBuild

// SetBuild
//
// Aufgabe: Gebäude bauen
//
void CPlayerBasic::SetBuild(int mouseCorX, int mouseCorY, int mouseX, int mouseY,
        Buildtyp name, string path, CField *field, int money, int wood, int brick, int stones,
        int pValue, int pTime, int pMoney, int mfactor, int pfactor){

    int numArea = 0;
    bool isbuild = false; // Dient zur Überprüfung, ob ein Gebäude in die Gebäudeliste eingeträgen wird
        // Gebäudeobjekt wird angelegt
        CBuilds Builds;
        // Iterator für Bauliste
        list<CBuilds>::iterator it = m_BuildsList.begin();

                if(m_pBudget->EnaughResources(money,wood,brick,stones) &&
                        field->Raster(mouseX - mouseCorX - 18, mouseY - mouseCorY - 32, name)){
                    m_PersonellBuildID++;

                    if(name != lumberjack && name != milkfarm){
                         Builds.Init(path, field->GetRasterX(), field->GetRasterY(),
                         m_buildname,m_PersonellBuildID,pValue,pTime,pMoney);
                    }// if
                    else{
                        // Ziegenfelder im Umkreis des Holfällers berechnen
                    numArea = field->CountArea((field->GetRasterY()) / 18, (field->GetRasterX()) / 18, m_buildname);

                     // Ressourcen Faktor anpassen
                    if(numArea > 100)
                       Builds.Init(path,field->GetRasterX(), field->GetRasterY(),
                               m_buildname,m_PersonellBuildID,5,pTime,pMoney);
                    else if(numArea > 50)
                        Builds.Init(path,field->GetRasterX(), field->GetRasterY(),
                                m_buildname,m_PersonellBuildID,3,pTime,pMoney);
                    else if(numArea > 25)
                        Builds.Init(path,field->GetRasterX(), field->GetRasterY(),
                                m_buildname, m_PersonellBuildID,2,pTime,pMoney);
                    else if(numArea > 1)
                        Builds.Init(path,field->GetRasterX(), field->GetRasterY(),
                                m_buildname,m_PersonellBuildID,1,pTime,pMoney);
                    else if(numArea <= 0)
                        Builds.Init(path,field->GetRasterX(), field->GetRasterY(),
                                m_buildname,m_PersonellBuildID,0,pTime,pMoney);
                    }//else
                   
                    // Ressourcen Faktor anpassen
                    m_pBudget->setFactor(mfactor, pfactor, name);

                    isbuild = true;

                    m_pBudget->Costs(money,wood,brick,stones);
                }// if

 // Gebäude in Liste einfügen
    if (isbuild == true) {
        if (m_BuildsList.empty())
                m_BuildsList.push_back(Builds);
        else {
            while (it != m_BuildsList.end()) {
                if (Builds.GetYRender() <= it->GetYRender() && it->GetID() != 14 && it->GetID() != 15) {
                    m_BuildsList.insert(it, Builds);
                    break;
                }// if
                it++;
            }// while
        }// else
    }// if


    field->SetPID(m_PersonellBuildID);

}// SetBuild

// RenderBuilds
//
// Aufgabe: Rendern der Gebäude
//
void CPlayerBasic::RenderBuilds(int mouseX, int mouxeY, CField *field){

    int numArea;
    // Iterator für Bauliste
    list<CBuilds>::iterator it = m_BuildsList.begin();

    // Bauliste durchlaufen
    while (it != m_BuildsList.end()) {
        // Gebäude updaten
        it->Update(mouseX, mouxeY);

        // Ist der Gebäude noch aktiv?
        if (it->IsAlive()) {
            // Ja, dann rendern
            if(it->GetID() == 7 || it->GetID() == 12){
                 // Ressourcen im Bereich des Produzenten berechnen
                     numArea = field->CountArea(it->GetYStart(), it->GetXStart(),it->GetID());

                     // Ressourcen Faktor anpassen
                    if(numArea > 100)
                        it->SetValue(5);
                    else if(numArea > 50)
                        it->SetValue(3);
                    else if(numArea > 25)
                        it->SetValue(2);
                    else if(numArea > 1)
                        it->SetValue(1);
                    else if(numArea <= 0)
                        it->SetValue(0);

            }// if
            it->CountRessources(m_pBudget);
            it->Render();
            it++;
        } else {
            // Nein, dann aus der Liste entfernen
            it->destroy();
            it = m_BuildsList.erase(it);
        }
    }
}// RenderBuilds
