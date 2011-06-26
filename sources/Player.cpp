#include "Player.h"

// Konstruktor
//
// Aufgabe: Allgemeine Initialisierungen
//

CPlayer::CPlayer(int RX, int RY, CField *field) {
    // Bauauswahl-Curser
    m_pSpriteCurser = new CSprite;
    m_pSpriteCurser->Load("content/data/Curser.bmp", 0, 64, 64);
    m_pSpriteCurser->SetColorKey(255, 0, 255);

    m_bBudgetEn = false;
    m_iCostId = 99;
    
    
    m_PersonellBuildID = field->GetPID();
    //m_pField->Init ();

    InitBudget(500,0,0,45,0,0,0,50,0,0);
    m_pBudgetDisplay = new CBudgetDisplay(RX,RY);

    m_iBudgetSize = 5;

    m_bLoad = false;

    m_iBuildElements_1 = false;
    m_bRasterMouse = false;

} // Konstruktor


// Init
//
// Aufgabe: Sprites erzeugen und laden
//
void CPlayer::Init() {

    m_pSpriteCurser->Load("content/data/Curser.bmp", 0, 64, 64);
    m_pSpriteCurser->SetColorKey(255, 0, 255);


} // Init

// ChangeCurserPic
//
// Aufgabe: Curser als Haus setzen
//

void CPlayer::ChangeCurserPic() {

    // Crusersprit in Haussprit ändern
    switch (m_buildname) {
        case(house):
            m_pSpriteCurser->Load("content/data/Buildings/woodf.bmp", 1, 108, 108);
            break;
        case(street):
            m_pSpriteCurser->Load("content/data/Buildings/gerade_links.bmp", 1, 108, 108);
            break;
        case(market):
            m_pSpriteCurser->Load("content/data/Buildings/markt.bmp", 1, 108, 108);
            break;
       /* case(temple):
            m_pSpriteCurser->Load("content/data/Buildings/woodf.bmp", 1, 108, 108);
            break;*/
        case(storage):
            m_pSpriteCurser->Load("content/data/Buildings/warenhaus.bmp", 1, 108, 108);
            break;
        case(trader):
            m_pSpriteCurser->Load("content/data/Buildings/woodf.bmp", 1, 108, 108);
            break;
        case(lumberjack):
            m_pSpriteCurser->Load("content/data/Buildings/lumber.bmp", 1, 36, 36);
            break;
        case(tree):
            m_pSpriteCurser->Load("content/data/Buildings/palmen_raster.bmp", 1, 36, 36);
            break;
        case(slimegrave):
            m_pSpriteCurser->Load("content/data/Buildings/woodf.bmp", 1, 36, 36);
            break;
        case(brickmaker):
            m_pSpriteCurser->Load("content/data/Buildings/woodf.bmp", 1, 36, 36);
            break;
        case(fisher):
            m_pSpriteCurser->Load("content/data/Buildings/fischerhaus.bmp", 1, 36, 36);
            break;
        case(milkfarm):
            m_pSpriteCurser->Load("content/data/Buildings/farmhaus.bmp", 1, 36, 36);
            break;
        case(center):
            m_pSpriteCurser->Load("content/data/Buildings/center.bmp", 1, 36, 36);
            break;
        case(milkfield):
            m_pSpriteCurser->Load("content/data/Buildings/ziegenfarmfeld.bmp", 1, 36, 36);
            break;
        default:
            // Hier Logfile mit Wert von m_bID aufrufen
            cout << "!!!Fehler bei der Curser Gebäudeauswahl, m_bID ist: " << m_buildname << " !!!" << endl;
            break;
    }
    m_pSpriteCurser->SetColorKey(255, 0, 255);
        /*case(none):
            m_pSpriteCurser->Load("Data/Map/palme1.bmp", 1, 36, 36);
            break;
        case(none):
            m_pSpriteCurser->Load("Data/Map/palme2.bmp", 1, 36, 36);
            break;*/
        
        /*case(50):
            m_pSpriteCurser->Load("Data/Buildings/gerade_links.bmp", 1, 36, 36);
            break;
        case(51):
            m_pSpriteCurser->Load("Data/Map/wasser_ecke_oben_rechts.bmp", 1, 36, 36);
            break;
        case(52):
            m_pSpriteCurser->Load("Data/Map/wasser_ecke_unten_links.bmp", 1, 36, 36);
            break;
        case(53):
            m_pSpriteCurser->Load("Data/Map/wasser_ecke_unten_rechts.bmp", 1, 36, 36);
            break;
        case(54):
            m_pSpriteCurser->Load("Data/Map/wasser_endgerade_oben_links.bmp", 1, 36, 36);
            break;
        case(55):
            m_pSpriteCurser->Load("Data/Map/wasser_endgerade_oben_rechts.bmp", 1, 36, 36);
            break;
        case(56):
            m_pSpriteCurser->Load("Data/Map/wasser_endgerade_unten_links.bmp", 1, 36, 36);
            break;
        case(57):
            m_pSpriteCurser->Load("Data/Map/wasser_endgerade_unten_rechts.bmp", 1, 36, 36);
            break;
        case(58):
            m_pSpriteCurser->Load("Data/Map/wasser_gerade_links.bmp", 1, 36, 36);
            break;
        case(59):
            m_pSpriteCurser->Load("Data/Map/wasser_gerade_rechts.bmp", 1, 36, 36);
            break;
        case(60):
            m_pSpriteCurser->Load("Data/Map/wasser_kurve_links.bmp", 1, 36, 36);
            break;
        case(61):
            m_pSpriteCurser->Load("Data/Map/wasser_kurve_oben.bmp", 1, 36, 36);
            break;
        case(62):
            m_pSpriteCurser->Load("Data/Map/wasser_kurve_rechts.bmp", 1, 36, 36);
            break;
        case(63):
            m_pSpriteCurser->Load("Data/Map/wasser_kurve_unten.bmp", 1, 36, 36);
            break;
        case(64):
            m_pSpriteCurser->Load("Data/Map/wasser_mittelteil.bmp", 1, 36, 36);
            break;*/
       

} // ChangeCurserPic

// Quit
//
// Aufgabe: Sprites freigeben
//
void CPlayer::Quit() {

    delete (m_pBudgetDisplay);
    m_pBudgetDisplay = NULL;
    delete(m_pBudget);
    m_pBudget = NULL;
} // Quit

// Reset
//
// Aufgabe: Spielerwerte auf Standard setzen
//
void CPlayer::Reset() {
    // Es darf gebaut werden
    m_bBuildLock = false;
    // Menue darf geoeffnet werden
    m_bMenueGLock = true;
    // Gebäude darf plaziert werden
    m_bMenueGLock2 = false;
    // Gebäude ID auf 0 setzen
    m_buildname = none;
} // Reset

// Render
//
// Aufgabe: Spieler und Gebäude rendern
//
void CPlayer::Render(bool ResPanel, int mouseCorX, int mouseCorY, CField *field) {

    RenderBuilds(mouseCorX, mouseCorY, field);
     // Ressourcen erhöhen !!!!!!!!Im Moment nur zum testen an dieser Stelle!!!!!!!!!!!
    m_pBudget->countRessources();
    if(ResPanel)
        m_pBudgetDisplay->RenderRessourcePanel(m_pBudget->getWood(),
                m_pBudget->getBrick(), m_pBudget->getFish(), m_pBudget->getMilk(),
                m_pBudget->getSlime());

    m_pBudgetDisplay->Render(m_pBudget->getInhabs1(), m_pBudget->getInhabs2(),
            m_pBudget->getMoney(), m_pBudget->getWood(), m_pBudget->getMilk());

    // Nur rendern wenn ein Gebäude ausgewählt ist, anhand einer zu schreibeneden
    // File Variable erkennen
    // Position des Spielers setzen und Sprite rendern
    if(m_bRasterMouse){
        SDL_GetMouseState(&m_bmausX, &m_bmausY);
        setMausPos(m_bmausX, m_bmausY);
        field->Raster(m_bmausX, m_bmausY);
        //SDL_WarpMouse(m_pField->GetRasterX(), m_pField->GetRasterY());
        m_pSpriteCurser->SetPos(m_bmausX - 18, m_bmausY - 32);
        m_pSpriteCurser->Render();
    }
    
    

} // Render


// BuildsUpdate
//
// Aufgabe: Gebäude Position updaten
//
void CPlayer::BuildsUpdate(int mouseX, int mouseY) {
    // Iterator für Bauliste
    list<CBuilds>::iterator it = m_BuildsList.begin();


    // Bauliste durchlaufen
    while (it != m_BuildsList.end()) {
        // Gebäude updaten
        it->Update(mouseX, mouseY);

        // Ist der Gebäude noch aktiv?
        if (it->IsAlive()) {
            // Ja, dann rendern
            //it->Render ();
            it++;
        } else {
            // Nein, dann aus der Liste entfernen
            it = m_BuildsList.erase(it);
        }

    }


} // Render



// ChooseBuild
//
// Aufgabe: Läuft Gebäudelist durch und überprüft ob ein Gebäude von einem
//          Mausclick getroffen wurde
//
int CPlayer::ChooseBuild(float XPos, float YPos){

    int ID;
     // Iterator für Bauliste
    list<CBuilds>::iterator it = m_BuildsList.begin();

     //char *test = "test1.txt";
                  //m_pField->SaveField(1,test);

    SDL_GetMouseState(&m_bmausX, &m_bmausY);
    setMausPos(m_bmausX, m_bmausY);

    // Gebäude abreißen
    while (it != m_BuildsList.end()) {

              if(m_bmausX >= it->GetRect().x && m_bmausX  <= it->GetRect().x + it->GetRect().w &&
                    m_bmausY >= it->GetRect().y && m_bmausY <= it->GetRect().y + it->GetRect().h){
                  if(it->GetID() == 6){
                      cout << "Ja das ist der Händler" <<endl;
                      break;
                  }
              }// if
              it++;
              }




    return 1;
}// ChooseBuild

// ChooseBuild
//
// Aufgabe: Gebäude wird zerstört
//
void CPlayer::DestroyBuild(CField *field){

   int t,t2;
    int ID;
     // Iterator für Bauliste
    list<CBuilds>::iterator it = m_BuildsList.begin();

     //char *test = "test1.txt";
                  //m_pField->SaveField(1,test);

    SDL_GetMouseState(&m_bmausX, &m_bmausY);
    setMausPos(m_bmausX, m_bmausY);

    // Gebäude abreißen
    while (it != m_BuildsList.end()) {

              if(m_bmausX >= it->GetRect().x && m_bmausX  <= it->GetRect().x + it->GetRect().w &&
                    m_bmausY >= it->GetRect().y && m_bmausY <= it->GetRect().y + it->GetRect().h && it->GetID() != 13){

                  ID = it->GetID();
                  field->SetBuildings(it->GetXStart(),it->GetYStart(),it->GetID(),true);
                  it->destroy();
                  it = m_BuildsList.erase(it);
                  //char *test = "test2.txt";
                  //m_pField->SaveField(1,test);
              }// if
        it++;
    }// while


    // Baubereich der wegen überschneidung gelöscht wurde wird wiederhergestellt
    if (ID == 5) {
        list<CBuilds>::iterator it2 = m_BuildsList.begin();
        while (it2 != m_BuildsList.end()) {
            if ((t = it2->GetID()) == 5 || (t2 = it2->GetID()) == 13)
                field->SetBuildings(it2->GetXStart(), it2->GetYStart(), it2->GetID(), false);
            it2++;
        }// while

        //char *test = "test3.txt";
        //m_pField->SaveField(1,test);
        // Gebäude die im Baubereich eines abgerissenen Lagergebäudes gestanden haben
    // werden entfernt
    list<CBuilds>::iterator it3 = m_BuildsList.begin();
    while (it3 != m_BuildsList.end()){
        if(!(field->BuildCollison(it3->GetXStart(),it3->GetYStart(),it3->GetID()))
                && it3->GetID() != 5 && it3->GetID() != 13 && it3->GetID() != 1){

            field->SetBuildings(it3->GetXStart(),it3->GetYStart(),it3->GetID(),true);
            field->setFieldState(free, it3->GetXStart(),it3->GetYStart());

            it3->destroy();
            it3 = m_BuildsList.erase(it3);
        }// if
        it3++;
    }// while
    }//if

    if (ID == 3) {
        list<CBuilds>::iterator it5 = m_BuildsList.begin();
        while (it5 != m_BuildsList.end()) {
            if ((t = it5->GetID()) == 3)
                field->SetBuildings(it5->GetXStart(), it5->GetYStart(), it5->GetID(), false);
            it5++;
        }// while

        //char *test = "test3.txt";
        //m_pField->SaveField(1,test);
        // Gebäude die im Baubereich eines abgerissenen Lagergebäudes gestanden haben
    // werden entfernt
    list<CBuilds>::iterator it4 = m_BuildsList.begin();
    while (it4 != m_BuildsList.end()){
        if(!(field->BuildCollison(it4->GetXStart(),it4->GetYStart(),it4->GetID()))
                && it4->GetID() == 1){

            field->SetBuildings(it4->GetXStart(),it4->GetYStart(),it4->GetID(),true);
            field->setFieldState(free, it4->GetXStart(),it4->GetYStart());

            it4->destroy();
            it4 = m_BuildsList.erase(it4);
        }// if
        it4++;
    }
    }//if

}// DestroyBuild


// Save und Load in

// Save
//
// Aufgabe: Anlegen eines Speicherstandes
//
void CPlayer::Save(const int ID, char *File, CField *field) {
    field->SaveField(ID,File);
    m_pBudget->SaveBudget(ID,File);
    cout << "Spiel wurde gespeichert\n";

}// Save

// Load
//
// Aufgabe: Laden eines Speicherstandes
//
void CPlayer::Load(const int ID, char *File, CField *field) {

    field->LoadBuffer(File);
    field->LoadField(m_BuildsList,ID);
    m_pBudget->LoadBudget(ID,File);

    m_PersonellBuildID = field->GetPID();

}//Load