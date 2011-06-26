#include"Field.h"

// Konstruktor
//

CField::CField() {
    m_Fsave = NULL;
    m_Fload = NULL;

    // Länge und Höhe des Feldes setzen
    m_iFieldY = 120; //48;
    m_iFieldX = 160; //64;
    // Feld initialisieren
    for (int i = 0; i < m_iFieldY; i++)
        for (int j = 0; j < m_iFieldX; j++) {
			m_Buildings[i][j].setTerraintyp(sand);
			m_Buildings[i][j].setFieldstate(free);
            m_iBuffer[i][j] = 0;
        }

    //m_iYLoad = 0;
   // m_iXLoad = 0;

    m_bLoadAktiv = false;
    m_PersonellBuildID = 0;

}// Konstruktor

// Destruktor
//

CField::~CField() {
    if (m_Fload != NULL)
        fclose(m_Fload);

}// Destruktor
// SetBuildings
//
// Aufgabe: Gebäude im Spielfeld platzieren
//

void CField::SetBuildings(int xPos, int yPos, Buildtyp buildname, bool Destroy) {
    
    Buildtyp build = none;
    Terraintyp terrain = sand;
    //FieldState field = free;

    // Feldpositionen berechnen
    m_iSetX = xPos / 18;
    m_iSetY = yPos / 18;

    switch (buildname) {
        case(house):// Wohnhaus
            build = house;
            break;
        case(street):// Straße
            terrain = tstreet;
            break;
        case(market):// Marktplatz
            // Wohnbereich erzeugen
            for(int i = m_iSetY - 25; i < m_iSetY + 35; i++)
                for(int j = m_iSetX -25; j < m_iSetX + 35; j++)
                    if(i > 0 && j > 0 && i < 120 && j < 160){

                        if(!Destroy){
                            if(m_Buildings[i][j].getFieldstate() == freeforbuilds)
                                m_Buildings[i][j].setFieldstate(freeforboth);
                            else
                                m_Buildings[i][j].setFieldstate(freeforhouses);
                        }
                        else
                            m_Buildings[i][j].setFieldstate(free);
                    }
            build = market;
            break;
        case(temple):// Tempel
            build = temple;
        case(storage):// Lager
            // Baubreich erzeugen
            for(int i = m_iSetY - 30; i < m_iSetY + 40; i++)
                for(int j = m_iSetX -30; j < m_iSetX + 40; j++)
                    if(i > 0 && j > 0 && i < 120 && j < 160){

                        if(!Destroy){
                            if(m_Buildings[i][j].getFieldstate() == freeforhouses)
                                m_Buildings[i][j].setFieldstate(freeforboth);
                            else
                                m_Buildings[i][j].setFieldstate(freeforbuilds);
                        }
                        else
                            m_Buildings[i][j].setFieldstate(free);
                    }
            build = storage;
            break;
       case(trader):// Händler
            build = trader;
            break;
        case(lumberjack):// holzfäller
            build = lumberjack;
            break;
        case(tree):
        /*case(14):
        case(15):*/
            terrain = ttree;
            break;
         case(slimegrave):
            build = slimegrave;
            break;
         case(brickmaker):
            build = brickmaker;
            break;
         case(fisher):
            build = fisher;
            break;
         case(milkfarm):
            build = milkfarm;
            break;
         case(milkfield):
            build = milkfield;
            break;
         case(center):
            // Baubreich erzeugen
            for(int i = m_iSetY - 40; i < m_iSetY + 45; i++)
                for(int j = m_iSetX -40; j < m_iSetX + 45; j++)
                    if(i > 0 && j > 0 && i < 120 && j < 160) {

                         if(!Destroy){
                            if(m_Buildings[i][j].getFieldstate() == freeforhouses)
                                m_Buildings[i][j].setFieldstate(freeforboth);
                            else
                                m_Buildings[i][j].setFieldstate(freeforbuilds);
                        }
                        else
                            m_Buildings[i][j].setFieldstate(free);
                    }
                build = center;
            break;
        default:
            // Fehler
            break;
    }
   /* if(buildname >= 50 && buildname <= 64)
        m_Buildings[m_iSetY + 1][m_iSetX + 3].setTerraintyp(water);*/
    
        


    // Baubereich für Gebäude Größe 2 wird gesetzt
    if(buildname == house || buildname == storage || buildname == trader || buildname == lumberjack || buildname == brickmaker
            || buildname == fisher || buildname == milkfarm || buildname == milkfield) {
        m_Buildings[m_iSetY + 1][m_iSetX + 3].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 2][m_iSetX + 2].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 2][m_iSetX + 3].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 2][m_iSetX + 4].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 3][m_iSetX + 1].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 3][m_iSetX + 2].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 3][m_iSetX + 3].setBuildtyp(build,Destroy); m_Buildings[m_iSetY + 3][m_iSetX + 4].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 3][m_iSetX + 5].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 4][m_iSetX + 2].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 4][m_iSetX + 3].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 4][m_iSetX + 4].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 5][m_iSetX + 3].setBuildtyp(build,Destroy);
    }
    // Baubereich für Gebäude Größe 1 wird gesetzt
    if(buildname == street /*||buildname >= 50 && buildname <= 64*/){
        m_Buildings[m_iSetY + 1][m_iSetX + 1].setBuildtyp(build,Destroy);
    }
    // Baubreich für Gebäude Größe 3 wird gesetzt
    if(buildname == market|| buildname == temple){
        m_Buildings[m_iSetY + 1][m_iSetX + 3].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 2][m_iSetX + 2].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 2][m_iSetX + 3].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 2][m_iSetX + 4].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 3][m_iSetX + 1].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 3][m_iSetX + 2].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 3][m_iSetX + 3].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 3][m_iSetX + 4].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 3][m_iSetX + 5].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 4][m_iSetX + 2].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 4][m_iSetX + 3].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 4][m_iSetX + 4].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 4][m_iSetX + 5].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 5][m_iSetX + 3].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 5][m_iSetX + 4].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 5][m_iSetX + 5].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 5][m_iSetX + 6].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 6][m_iSetX + 3].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 6][m_iSetX + 4].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 6][m_iSetX + 5].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 6][m_iSetX +6].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 6][m_iSetX + 7].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 7][m_iSetX + 4].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 7][m_iSetX + 5].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 7][m_iSetX + 6].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 8][m_iSetX + 5].setBuildtyp(build,Destroy);
    }
    // Waldfläche wird gesetzt
    if(buildname == tree){
        m_Buildings[m_iSetY + 1][m_iSetX + 3].setTerraintyp(terrain);m_Buildings[m_iSetY + 2][m_iSetX + 2].setTerraintyp(terrain);
        m_Buildings[m_iSetY + 2][m_iSetX + 3].setTerraintyp(terrain);m_Buildings[m_iSetY + 2][m_iSetX + 4].setTerraintyp(terrain);
        m_Buildings[m_iSetY + 3][m_iSetX + 1].setTerraintyp(terrain);m_Buildings[m_iSetY + 3][m_iSetX + 2].setTerraintyp(terrain);
        m_Buildings[m_iSetY + 3][m_iSetX + 3].setTerraintyp(terrain); m_Buildings[m_iSetY + 3][m_iSetX + 4].setTerraintyp(terrain);
        m_Buildings[m_iSetY + 3][m_iSetX + 5].setTerraintyp(terrain);m_Buildings[m_iSetY + 4][m_iSetX + 2].setTerraintyp(terrain);
        m_Buildings[m_iSetY + 4][m_iSetX + 3].setTerraintyp(terrain);m_Buildings[m_iSetY + 4][m_iSetX + 4].setTerraintyp(terrain);
        m_Buildings[m_iSetY + 5][m_iSetX + 3].setTerraintyp(terrain);
    }
    /*if(ID == 14 || ID == 15 ){
        m_Buildings[m_iSetY + 1][m_iSetX + 1].setTerraintyp(terrain);
    }*/


    // Baubreich für Gebäude Größe 4 wird gesetzt
    if(buildname == center){
        m_Buildings[m_iSetY + 1][m_iSetX + 5].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 2][m_iSetX + 4].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 2][m_iSetX + 5].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 2][m_iSetX + 6].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 3][m_iSetX + 3].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 3][m_iSetX + 4].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 3][m_iSetX + 5].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 3][m_iSetX + 6].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 3][m_iSetX + 7].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 4][m_iSetX + 3].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 4][m_iSetX + 4].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 4][m_iSetX + 5].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 4][m_iSetX + 6].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 4][m_iSetX + 7].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 4][m_iSetX + 8].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 5][m_iSetX + 2].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 5][m_iSetX + 3].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 5][m_iSetX + 4].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 5][m_iSetX + 5].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 5][m_iSetX + 6].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 5][m_iSetX + 7].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 5][m_iSetX + 8].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 5][m_iSetX + 9].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 6][m_iSetX + 1].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 6][m_iSetX + 2].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 6][m_iSetX + 3].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 6][m_iSetX + 4].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 6][m_iSetX + 5].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 6][m_iSetX + 6].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 6][m_iSetX + 7].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 6][m_iSetX + 8].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 6][m_iSetX + 9].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 6][m_iSetX + 10].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 7][m_iSetX + 2].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 7][m_iSetX + 3].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 7][m_iSetX + 4].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 7][m_iSetX + 5].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 7][m_iSetX + 6].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 7][m_iSetX + 7].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 7][m_iSetX + 8].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 7][m_iSetX + 9].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 8][m_iSetX + 4].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 8][m_iSetX + 5].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 8][m_iSetX + 6].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 8][m_iSetX + 7].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 8][m_iSetX + 8].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 9][m_iSetX + 4].setBuildtyp(build,Destroy);m_Buildings[m_iSetY + 9][m_iSetX + 5].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 9][m_iSetX + 6].setBuildtyp(build,Destroy);
        m_Buildings[m_iSetY + 10][m_iSetX + 5].setBuildtyp(build,Destroy);

    }
    if(!m_bLoadAktiv){
         m_iBuffer[m_iSetY][m_iSetX] = buildname;
    }
  
    //Werte zurücksetzen
    m_iSetX = 0;
    m_iSetY = 0;

   // CoutField();
}// SetBuildings

// BuildCollision
//
// Aufgabe: Überprüfen ob Feld Element schon belegt ist
//
bool CField::BuildCollison(int xPos, int yPos, Buildtyp buildname) {
    // Feldpositionen berechnen
    // Diese stelle noch in lokale Variablen umändern !!!!!!!!!!!!!!!!!!!!!!!!!!
    m_iSetX = xPos / 18;
    m_iSetY = yPos / 18;

    FieldState field;

    if(buildname == house)
        field = freeforhouses;
    else
        field = freeforbuilds;

     // Sind die zu belegenden Felder leer?
    if (buildname != street && m_Buildings[m_iSetY + 1][m_iSetX + 3].isFreeToBuild(field) && m_Buildings[m_iSetY + 2][m_iSetX + 2].isFreeToBuild(field) && m_Buildings[m_iSetY + 2][m_iSetX + 4].isFreeToBuild(field)
            && m_Buildings[m_iSetY + 3][m_iSetX + 1].isFreeToBuild(field) && m_Buildings[m_iSetY + 3][m_iSetX + 3].isFreeToBuild(field) && m_Buildings[m_iSetY + 3][m_iSetX + 5].isFreeToBuild(field)
            && m_Buildings[m_iSetY + 4][m_iSetX + 2].isFreeToBuild(field) && m_Buildings[m_iSetY + 4][m_iSetX + 4].isFreeToBuild(field) && m_Buildings[m_iSetY + 5][m_iSetX + 3].isFreeToBuild(field)
            ){

        if(buildname == fisher){
            if(m_Buildings[m_iSetY + 0][m_iSetX + 3].getTerraintyp() != water && m_Buildings[m_iSetY + 1][m_iSetX + 2].getTerraintyp() != water && m_Buildings[m_iSetY + 1][m_iSetX + 4].getTerraintyp() != water
            && m_Buildings[m_iSetY + 2][m_iSetX + 1].getTerraintyp() != water && m_Buildings[m_iSetY + 2][m_iSetX + 5].getTerraintyp() != water && m_Buildings[m_iSetY + 3][m_iSetX + 0].getTerraintyp() != water
            && m_Buildings[m_iSetY + 4][m_iSetX + 1].getTerraintyp() != water && m_Buildings[m_iSetY + 4][m_iSetX + 5].getTerraintyp() != water && m_Buildings[m_iSetY + 5][m_iSetX + 2].getTerraintyp() != water
                    && m_Buildings[m_iSetY + 5][m_iSetX + 4].getTerraintyp() != water && m_Buildings[m_iSetY + 6][m_iSetX + 3].getTerraintyp() != water &&
                    m_Buildings[m_iSetY - 1][m_iSetX + 3].getTerraintyp() != water
                    && m_Buildings[m_iSetY + 0][m_iSetX + 2].getTerraintyp() != water && m_Buildings[m_iSetY + 0][m_iSetX + 2].getTerraintyp() != water && m_Buildings[m_iSetY + 1][m_iSetX + 1].getTerraintyp() != water
            && m_Buildings[m_iSetY + 1][m_iSetX + 5].getTerraintyp() != water  && m_Buildings[m_iSetY + 2][m_iSetX + 0].getTerraintyp() != water && m_Buildings[m_iSetY + 2][m_iSetX + 6].getTerraintyp() != water
           && m_Buildings[m_iSetY + 3][m_iSetX - 1].getTerraintyp() != water&& m_Buildings[m_iSetY + 3][m_iSetX + 7].getTerraintyp() != water && m_Buildings[m_iSetY + 4][m_iSetX + 0].getTerraintyp() != water
                    && m_Buildings[m_iSetY + 4][m_iSetX + 6].getTerraintyp() != water && m_Buildings[m_iSetY + 5][m_iSetX + 1].getTerraintyp() != water && m_Buildings[m_iSetY + 5][m_iSetX + 5].getTerraintyp() != water
            && m_Buildings[m_iSetY + 6][m_iSetX + 2].getTerraintyp() != water  && m_Buildings[m_iSetY + 6][m_iSetX + 4].getTerraintyp() != water && m_Buildings[m_iSetY + 7][m_iSetX + 3].getTerraintyp() != water)

                return false;
            else
                return true;
		}// if
        else
            return true;

    }
    else if (buildname == street && m_Buildings[m_iSetY + 1][m_iSetX + 1].isFreeToBuild(field))
        return true;

    else if(buildname == temple && m_Buildings[m_iSetY + 1][m_iSetX + 3].isFreeToBuild(field) &&m_Buildings[m_iSetY + 2][m_iSetX + 2].isFreeToBuild(field) && m_Buildings[m_iSetY + 2][m_iSetX + 3].isFreeToBuild(field) &&
            m_Buildings[m_iSetY + 2][m_iSetX + 4].isFreeToBuild(field)&&m_Buildings[m_iSetY + 3][m_iSetX + 1].isFreeToBuild(field) &&m_Buildings[m_iSetY + 3][m_iSetX + 2].isFreeToBuild(field) &&
            m_Buildings[m_iSetY + 3][m_iSetX + 3].isFreeToBuild(field)&&m_Buildings[m_iSetY + 3][m_iSetX + 4].isFreeToBuild(field) &&m_Buildings[m_iSetY + 3][m_iSetX + 5].isFreeToBuild(field) &&
            m_Buildings[m_iSetY + 4][m_iSetX + 2].isFreeToBuild(field)&&m_Buildings[m_iSetY + 4][m_iSetX + 3].isFreeToBuild(field) &&m_Buildings[m_iSetY + 4][m_iSetX + 4].isFreeToBuild(field)&&
            m_Buildings[m_iSetY + 4][m_iSetX + 5].isFreeToBuild(field)&&m_Buildings[m_iSetY + 5][m_iSetX + 3].isFreeToBuild(field) &&m_Buildings[m_iSetY + 5][m_iSetX + 4].isFreeToBuild(field)&&
            m_Buildings[m_iSetY + 5][m_iSetX + 5].isFreeToBuild(field)&&m_Buildings[m_iSetY + 5][m_iSetX + 6].isFreeToBuild(field) &&m_Buildings[m_iSetY + 6][m_iSetX + 3].isFreeToBuild(field) &&
            m_Buildings[m_iSetY + 6][m_iSetX + 4].isFreeToBuild(field)&&m_Buildings[m_iSetY + 6][m_iSetX + 5].isFreeToBuild(field) &&m_Buildings[m_iSetY + 6][m_iSetX + 6].isFreeToBuild(field)&&
            m_Buildings[m_iSetY + 6][m_iSetX + 7].isFreeToBuild(field)&&m_Buildings[m_iSetY + 7][m_iSetX + 4].isFreeToBuild(field) &&m_Buildings[m_iSetY + 7][m_iSetX + 5].isFreeToBuild(field)&&
            m_Buildings[m_iSetY + 7][m_iSetX + 6].isFreeToBuild(field)&&m_Buildings[m_iSetY + 8][m_iSetX + 5].isFreeToBuild(field) )
        return true;

    else if(buildname == center)
        return true;

    else
        return false;

}// BuildCollison

// Raster
//
// Aufgabe: Erechnet das Raster in das ein zu bauendes Gebäude plaziert werden
//          soll und setzt bei freiem Raster das Gebäude ins Spielfeld
//
bool  CField::Raster(int X_Mouse, int Y_Mouse, Buildtyp Buildname){

    // Raster Setzung
    m_iRasterBigX = 0;
    m_iRasterSmallX = 0;
    m_iRasterBigY = 0;
    m_iRasterSmallY = 0;
    m_iRasterSetX = X_Mouse;
    m_iRasterSetY = Y_Mouse;

    while (m_iRasterSetX > m_iRasterBigX) {

        m_iRasterSmallX = m_iRasterBigX;
        m_iRasterBigX += 18; // Nur bei jetziger Auflösung und Zoom
        if (m_iRasterBigX > 2880 /*Größer als Spielfeld Länge*/) {
            cout << "Auserhalb des Spielfeldes" << endl;
            Buildname = none;
            break;
        }// if Auserhalb Spielfeld
    }// while RasterBerechnung

    if (m_iRasterSetX - m_iRasterSmallX <= m_iRasterBigX - m_iRasterSetX)
        m_iRasterSetX = m_iRasterSmallX;
    else
        m_iRasterSetX = m_iRasterBigX;

    // Raster Berechnung für Y
    while (m_iRasterSetY > m_iRasterBigY) {

        m_iRasterSmallY = m_iRasterBigY;
        m_iRasterBigY += 18; // Nur bei jetziger Auflösung und Zoom
        if (m_iRasterBigY > 2160 /*Größer als Spielfeld Länge*/) {
            cout << "Auserhalb des Spielfeldes" << endl;
            return false;
        }// if Y auserhalb Spielfeld
    }// while RasterBerechnung Y

    if (m_iRasterSetY - m_iRasterSmallY <= m_iRasterBigY - m_iRasterSetY)
        m_iRasterSetY = m_iRasterSmallY;
    else
        m_iRasterSetY = m_iRasterBigY;

    // Überprüfung ob Rasterfelder schon belegt sind
    if (BuildCollison(m_iRasterSetX, m_iRasterSetY, Buildname) ){
        // Gebäude in Feld einfügen
        SetBuildings(m_iRasterSetX, m_iRasterSetY,Buildname,false);
        return true;
   }
   // else
       // return false;
    //CoutField();
}

void  CField::Raster(int X_Mouse, int Y_Mouse){

    // Raster Setzung
    m_iRasterBigX = 0;
    m_iRasterSmallX = 0;
    m_iRasterBigY = 0;
    m_iRasterSmallY = 0;
    m_iRasterSetX = X_Mouse;
    m_iRasterSetY = Y_Mouse;

    while (m_iRasterSetX > m_iRasterBigX) {

        m_iRasterSmallX = m_iRasterBigX;
        m_iRasterBigX += 18; // Nur bei jetziger Auflösung und Zoom
        if (m_iRasterBigX > 2880 /*Größer als Spielfeld Länge*/) {
            cout << "Auserhalb des Spielfeldes" << endl;
            
            break;
        }// if Auserhalb Spielfeld
    }// while RasterBerechnung

    if (m_iRasterSetX - m_iRasterSmallX <= m_iRasterBigX - m_iRasterSetX)
        m_iRasterSetX = m_iRasterSmallX;
    else
        m_iRasterSetX = m_iRasterBigX;

    // Raster Berechnung für Y
    while (m_iRasterSetY > m_iRasterBigY) {

        m_iRasterSmallY = m_iRasterBigY;
        m_iRasterBigY += 18; // Nur bei jetziger Auflösung und Zoom
        if (m_iRasterBigY > 2160 /*Größer als Spielfeld Länge*/) {
            cout << "Auserhalb des Spielfeldes" << endl;
            
        }// if Y auserhalb Spielfeld
    }// while RasterBerechnung Y

    if (m_iRasterSetY - m_iRasterSmallY <= m_iRasterBigY - m_iRasterSetY)
        m_iRasterSetY = m_iRasterSmallY;
    else
        m_iRasterSetY = m_iRasterBigY;

}

void CField::CoutField() {
    for (int i = 0; i < m_iFieldY; i++) {
        for (int j = 0; j < m_iFieldX; j++) {
            //cout << m_iBuildingsBuffer[i][j];
        }
        cout << endl;
    }
}// CoutField

// CountTrees
//
// Aufgabe: Zählt die Bäume in der Umgebung eines Holzfällers
//
int CField::CountArea(int y, int x, Buildtyp name){

    Terraintyp terrain;
    Buildtyp build;

    int Field;
    int numArea = 0;

    int xPos = x/18, yPos = y/18;

    switch(name){
        case(lumberjack):
            terrain = ttree;
            Field = 2;
            break;
        case(milkfarm):
            build = milkfield;
            Field = 0;
            break;
    }
    
    
    for(int i = yPos - 4 ; i < yPos + 9; i++){
        for(int j = xPos - 4; j < xPos + 9; j++){
            if(name == lumberjack && m_Buildings[i][j].getTerraintyp() == terrain)
                numArea++;
            else if(name == milkfarm && m_Buildings[i][j].getBuildtyp() == build)
                numArea++;
        }
    }

    return numArea;
           
}// CountTrees


// SaveField
//
// Aufgabe: Speichert das Spielfeld in der Speicherdatei
//
void CField::SaveField(const int SaveID, char *File) {
    // Öffnen der Speicherdatei
    if ((m_Fsave = fopen(File, "w")) == NULL) {
        cout << "Feld konnte nicht gespeichert werden!!!" << endl;
        return;
    } // if

    // Speichern des Feldes in Datei
    for (int m_y = 0; m_y < 120; m_y++) {
        for (int m_x = 0; m_x < 160; m_x++) {
            //fprintf(m_Fsave, "%c", m_cBuildings[m_y][m_x][1]);
            fprintf(m_Fsave, "%i\n", m_iBuffer[m_y][m_x]);

        }
        //fprintf(m_Fsave, "\n");

    } // for

    cout << File << endl;
    // Datei schließen
    fclose(m_Fsave);


}// SaveField

// LoadBuffer
//
// Aufgabe: Öffnen der Speicherdatei
//

void CField::LoadBuffer(char * File) {
    // Öffnen der Speicherdatei
    m_Fload = fopen(File, "r");
    
   
}// LoadBuffer

// LoadField
//
// Aufgabe: Lädt das Spieldfeld
//
void CField::LoadField(list<CBuilds> &List, const int LoadID) {

    m_bLoadAktiv = true;
    int i = 1;
    list<CBuilds>::iterator it = List.begin();
    
    // Laden des Feldes aus Datei
    for (int m_iYLoad = 0; m_iYLoad < 120; m_iYLoad++) {
        for (int m_iXLoad = 0; m_iXLoad < 160; m_iXLoad++){
           fscanf(m_Fload,"%i",&m_iBuffer[m_iYLoad][m_iXLoad]);
      
           if (m_iBuffer[m_iYLoad][m_iXLoad] != 0) {
                CBuilds Build;
                switch (m_iBuffer[m_iYLoad][m_iXLoad]) {

                    case(1):
                        m_PersonellBuildID++;
                        SetBuildings(m_iXLoad * 18, m_iYLoad * 18, house,false);
                        Build.Init("content/data/Buildings/woodf.bmp", m_iXLoad * 18,
                                m_iYLoad * 18, house,m_PersonellBuildID,0,0,0);
                        List.push_back(Build);
                        break;
                    case(2):
                        m_PersonellBuildID++;
                        SetBuildings(m_iXLoad * 18, m_iYLoad * 18, street,false);
                        Build.Init("content/data/Buildings/gerade_links.bmp", m_iXLoad * 18,
                                m_iYLoad * 18, street,m_PersonellBuildID,0,0,0);
                        List.push_back(Build);
                        break;
                    case(3):
                        m_PersonellBuildID++;
                        SetBuildings(m_iXLoad * 18, m_iYLoad * 18, market,false);
                        Build.Init("content/data/Buildings/markt.bmp", m_iXLoad * 18,
                                m_iYLoad * 18, market,m_PersonellBuildID,0,10,2);
                        List.push_back(Build);
                        break;
                    case(4):
                        m_PersonellBuildID++;
                        SetBuildings(m_iXLoad * 18, m_iYLoad * 18, temple,false);
                        Build.Init("content/data/Buildings/woodf.bmp", m_iXLoad * 18,
                                m_iYLoad * 18, temple,m_PersonellBuildID,0,10,10);
                        List.push_back(Build);
                        break;
                    case(5):
                        m_PersonellBuildID++;
                        SetBuildings(m_iXLoad * 18, m_iYLoad * 18, storage,false);
                        Build.Init("content/data/Buildings/warenhaus.bmp", m_iXLoad * 18,
                                m_iYLoad * 18, storage,m_PersonellBuildID,0,10,2);
                        List.push_back(Build);
                        break;
                    case(6):
                        m_PersonellBuildID++;
                        SetBuildings(m_iXLoad * 18, m_iYLoad * 18, trader,false);
                        Build.Init("content/data/Buildings/woodf.bmp", m_iXLoad * 18, 
                                m_iYLoad * 18, trader,m_PersonellBuildID,0,10,2);
                        List.push_back(Build);
                        break;
                    case(7): // Holzfäller
                        m_PersonellBuildID++;
                        SetBuildings(m_iXLoad * 18, m_iYLoad * 18, lumberjack,false);
                        Build.Init("content/data/Buildings/lumber.bmp", m_iXLoad * 18,
                                m_iYLoad * 18, lumberjack,m_PersonellBuildID,0,10,5);
                        List.push_back(Build);
                        break;
                    case(8): // Palmen
                        m_PersonellBuildID++;
                        SetBuildings(m_iXLoad * 18, m_iYLoad * 18, tree,false);
                        Build.Init("content/data/Buildings/palmen_raster.bmp", m_iXLoad * 18,
                                m_iYLoad * 18, tree,m_PersonellBuildID,0,0,0);
                        List.push_back(Build);
                        break;
                    case(9):
                        m_PersonellBuildID++;
                        SetBuildings(m_iXLoad * 18, m_iYLoad * 18, slimegrave,false);
                        Build.Init("content/data/Buildings/woodf.bmp", m_iXLoad * 18,
                                m_iYLoad * 18, slimegrave,m_PersonellBuildID,5,10,5);
                        List.push_back(Build);
                        break;
                    case(10):
                        m_PersonellBuildID++;
                        SetBuildings(m_iXLoad * 18, m_iYLoad * 18, brickmaker,false);
                        Build.Init("content/data/Buildings/woodf.bmp", m_iXLoad * 18,
                                m_iYLoad * 18, brickmaker,m_PersonellBuildID,5,10,5);
                        List.push_back(Build);
                        break;
                    case(11):// Fischer
                        m_PersonellBuildID++;
                        SetBuildings(m_iXLoad * 18, m_iYLoad * 18, fisher,false);
                        Build.Init("content/data/Buildings/fischerhaus.bmp", m_iXLoad * 18,
                                m_iYLoad * 18, fisher,m_PersonellBuildID,5,10,5);
                        List.push_back(Build);
                        break;
                    case(12)://Ziegenfarm
                        m_PersonellBuildID++;
                        SetBuildings(m_iXLoad * 18, m_iYLoad * 18, milkfarm,false);
                        Build.Init("content/data/Buildings/farmhaus.bmp", m_iXLoad * 18,
                                m_iYLoad * 18, milkfarm,m_PersonellBuildID,2,10,10);
                        List.push_back(Build);
                        break;
                    case(13)://Haupthaus
                        m_PersonellBuildID++;
                        SetBuildings(m_iXLoad * 18, m_iYLoad * 18, center,false);
                        Build.Init("content/data/Buildings/haupthaus_raster.bmp", m_iXLoad * 18,
                                m_iYLoad * 18, center,m_PersonellBuildID,0,0,0);
                        List.push_back(Build);
                        break;
                   /* case(14):
                        m_PersonellBuildID++;
                        SetBuildings(m_iXLoad * 18, m_iYLoad * 18, 14,false);
                        Build.Init("Data/Map/palme1.bmp", m_iXLoad * 18,
                                m_iYLoad * 18, 14,m_PersonellBuildID,0,0,0);
                        List.push_back(Build);
                        break;
                    case(15):
                        m_PersonellBuildID++;
                        SetBuildings(m_iXLoad * 18, m_iYLoad * 18, 15, false);
                        Build.Init("Data/Map/palme1.bmp", m_iXLoad * 18,
                                m_iYLoad * 18, 15, m_PersonellBuildID,0,0,0);
                        List.push_back(Build);
                        break;*/
                    case(16):// Z-feld
                        m_PersonellBuildID++;
                        SetBuildings(m_iXLoad * 18, m_iYLoad * 18, milkfield, false);
                        Build.Init("content/data/Buildings/ziegenfarmfeld.bmp", m_iXLoad * 18,
                                m_iYLoad * 18, milkfield, m_PersonellBuildID,0,0,0);
                        List.push_back(Build);
                        break;
					case(50):
					case(51):
					case(52):
					case(53):
					case(54):
					case(55):
					case(56):
					case(57):
					case(58):
					case(59):
                    case(60):
                    case(61):
					case(62):
				    case(63):
                    case(64):
						m_Buildings[m_iXLoad][m_iYLoad].setTerraintyp(water);
                        break;
                    default:
                        // Fehler
                        break;
                }//switch
                // Gebäude in Liste einfügen
                    if(List.empty())
                        List.push_back(Build);
                    else{
                        while(it != List.end()){
                            if(Build.GetYRender() < it->GetYRender()){
                                List.insert(it, Build);
                                it = List.begin();
                                i = 1;
                                break;
                            }// if
                            else{
                                i++;
                            }// else
                              it++;
                        }// while
                    }// if
            }// if

           
           
        }
    }
        m_bLoadAktiv = false;
        //CoutField();
        fclose(m_Fload);

}// LoadField
