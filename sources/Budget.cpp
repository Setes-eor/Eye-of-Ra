#include "Budget.h"

// Konstruktor
//
CBudget::CBudget() {

    m_Fsave = NULL;
    m_Fload = NULL;

    // Timer initialisieren
    m_pTimer = new CTimer;


    // Festsetzen des Starkapitals
    m_iInhabitans_1 = 0;
    m_iInhabitans_2 = 0;
    m_iApartments_1 = 0;
    m_iApartments_2 = 0;
    m_iMaxApartInhabs_1_1 = 3;
    m_iMaxApartInhabs_1_2 = 5;
    m_iMaxApartInhabs_2_1 = 7;
    m_iMaxApartInhabs_2_1 = 10;
    m_iMoney = 0;
    m_iWood = 0;
    m_iBrick = 0;
    m_iStones = 0;
    m_iTools = 0;
    m_iFishes = 0;
    m_iMilk = 0;
    m_iSlime = 0;
    m_iSize = 50;

    m_iMoneyFactor = 0;
    m_iWoodFactor = 0;
    m_iBrickFactor = 0;
    m_iToolsFactor = 0;
    m_iFishFactor = 0;
    m_iMilkFactor = 0;
    m_iSlimeFactor = 0;
    m_iStoneFactor = 0;

    m_oldtime = time(NULL);
    m_oldtime_2 =  time(NULL);
    m_oldtime_3 = time(NULL);

    test = true;
    m_bBuildElements_1 = false;

    m_bADDInhaMax_1 = false;
} // Konstruktor

// Destruktor
//

CBudget::~CBudget() {
    delete m_pTimer;
}// Destruktor

// InitResources
//
// Aufgabe: Legt die Startressourcen fest
//
void CBudget::InitResources(int money = 0, unsigned int inhabs1 = 0,
        unsigned int inhabs2 = 0, unsigned int wood = 0, unsigned int brick = 0,
        unsigned int slime = 0, unsigned int tools = 0, unsigned int fish = 0,
        unsigned int milk = 0, unsigned int stone = 0){
    m_iMoney = money;
    m_iInhabitans_1 = inhabs1;
    m_iInhabitans_2 = inhabs2;
    m_iWood = wood;
    m_iBrick = brick;
    m_iSlime = slime;
    m_iTools = tools;
    m_iFishes = fish;
    m_iMilk = milk;
    m_iStones = stone;
}// InitResources

// EnaughResources
//
// Aufgabe: Überprüft ob die Ressourecen aureichen um das ausgewählte Gebäude
//          zu bauen
//
bool CBudget::EnaughResources(const int Money,const int Wood,const int Brick,const int Stones){

            if (m_iMoney - Money >= 0 && m_iWood - Wood >= 0 && 
                    m_iBrick - Brick >= 0 && m_iStones - Stones >= 0)
                return true;
            return false;
}// EnaughRessourc

// Costs
//
// Aufgabe: Zieht die Baukosten ab
//
void CBudget::Costs(const int Money,const int Wood,const int Brick,const int Stones) {

    m_iMoney -= Money;
    m_iWood -= Wood;
    m_iBrick -= Brick;
    m_iStones -= Stones;

}// Costs

// setFactor
//
// Aufgabe: Faktor der Ressourcenberechnung erhöhen
//
void CBudget::setFactor(int const factorM, int const factorP,  const Buildtyp name) {

    m_iMoneyFactor += factorM;
    switch (name) {
        case(house):
            m_iApartments_1 += factorP;
            m_iInhabitans_1 += 2 * factorP;
            break;
        case(lumberjack):
            m_iWoodFactor += factorP;
            break;
        case(slimegrave):
            m_iSlimeFactor += factorP;
            break;
        case(brickmaker):
            m_iBrickFactor += factorP;
            break;
        case(fisher):
            m_iFishFactor += factorP;
            break;
        case(milkfarm):
            m_iMilkFactor += factorP;
            break;
        default:
            break;
    }

}// setFactor

// countRessources
//
// Aufgabe: Ressourcen aktualisieren
//

void CBudget::countRessources() {

    // Wurde das erste mal Milch prodzuiert wird die max Anzahl von Bewohner
    // pro Haus um 2 erhöt
    if(m_iMilk > 0 &&  !m_bADDInhaMax_1){
        m_iMaxApartInhabs_1_1 += 2;
        m_bADDInhaMax_1 = true;

    }

    // Berechung der Spieler Ressourcen nach jeweils 10 Sekunden
    if (m_currenttime = (time(NULL) - m_oldtime) >= 20) {
        m_oldtime = time(NULL);
        // Berechung des aktuellen Geld Standes in Abähingkeit der Anzahl von Einwohnern
        m_iMoney += ((3*m_iInhabitans_1) + (5*m_iInhabitans_2));
        

        if(m_iWood > m_iSize)
            m_iWood = m_iSize;
        if(m_iBrick > m_iSize)
                m_iBrick = m_iSize;
        if(m_iTools > m_iSize)
                m_iTools = m_iSize;
        // Fische berechnen und ggf. Einwohnerzahl berechnen
        if (m_currenttime_2 = (time(NULL) - m_oldtime_2) >= 20) {
            m_oldtime_2 = time(NULL);
            if(m_iInhabitans_1 + m_iInhabitans_2 == 1)
                m_iFishes--;
            if((m_iFishes -=  ((m_iInhabitans_1 + m_iInhabitans_2) / 2)) > m_iSize)
                m_iFishes = m_iSize;
        }// if Fish
        // Milch berechnen und ggf. Einwohnerzahl berechnen
        if (m_currenttime_3 = (time(NULL) - m_oldtime_3) >= 20) {
            m_oldtime_3 = time(NULL);
            if(m_iInhabitans_1 + m_iInhabitans_2 == 1)
                m_iMilk--;
            if((m_iMilk -=  (m_iInhabitans_1 + m_iInhabitans_2) / 2) > m_iSize)
                m_iMilk = m_iSize;
        }// if Milk
        
        if(m_iSlime > m_iSize)
                m_iSlime = m_iSize;

        if(m_iWood < 0)
            m_iWood = 0;
        if(m_iBrick < 0)
            m_iBrick = 0;
        if(m_iTools < 0)
            m_iTools = 0;
        if(m_iFishes < 0)
            m_iFishes = 0;
        if(m_iMilk < 0)
            m_iMilk = 0;
        if(m_iSlime < 0)
            m_iSlime = 0;

        
        // Erhöung der Einwohnerzahl Stufe 1, bei ausreichendem Fisch im Lager
        if(m_iFishes >= 2 && m_iInhabitans_1 <= (m_iMaxApartInhabs_1_1 * m_iApartments_1)
                && m_iInhabitans_1 > 0 && !m_bADDInhaMax_1)
            m_iInhabitans_1 += 2;
        // Oder veringern der Einwohenerzahl Stufe 1, bei zu wenig Fischen im Lager
        if(m_iFishes <= 1)
            m_iInhabitans_1 -= 1;
        if(m_iMilk <= 1 && m_iInhabitans_1 >= ((m_iMaxApartInhabs_1_1-2) * m_iApartments_1)
                && m_bADDInhaMax_1)
            m_iInhabitans_1 -= 1;

        // Erhöung der Einwohnerzahl Stufe 1, bei ausreichendem Fisch und Milch im Lager
        if(m_iFishes >= 2 && m_iMilk >=  7 && m_iInhabitans_1 < (m_iMaxApartInhabs_1_1 * m_iApartments_1)
                && m_iInhabitans_1 > 0 && m_bADDInhaMax_1)
            m_iInhabitans_1 += 2;

        // Gibt es mehr Einwohner als es Wohnplatzt gibt(z.B. wenn ein Haus abgerissen wurde
        // müssen die überschüssigen Einwohner ausziehen
        // noch ändern !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!111
        if(m_iInhabitans_1 > (m_iApartments_1 * m_iMaxApartInhabs_1_1))
                m_iInhabitans_1 = (m_iApartments_1 * m_iMaxApartInhabs_1_1);
        if(m_iInhabitans_1 < 0)
            m_iInhabitans_1 = 0;
        // Oder veringern der Einwohenerzahl Stufe 1, bei zu wenig Milch im Lager
        /*else if(m_iMilk < (m_iInhabitans_1 % 4) && m_iInhabitans_1 > 0 &&
                m_iInhabitans_1 > ((m_iMaxApartInhabs_1 - 2) * m_iApartments_1))
            m_iInhabitans_1 -= 1;
        // 
        // Also Fisch + Milch + Tempel*/

    }
    if(m_iInhabitans_1 >= 50 && !m_bBuildElements_1)
        m_bBuildElements_1 = true;


}// countRessources

// CountRessources
//
// Aufgabe: Erhört die Ressourcen
//
void CBudget::CountRessources(int ID, int Pro, int Money){
    switch(ID){
        case(7):
            m_iWood += Pro;
            break;
        case(9):
            m_iSlime += Pro;
            break;
        case(10):
            m_iBrick += Pro;
            break;
        case(11):
            m_iFishes += Pro;
            break;
        case(12):
            m_iMilk += Pro;
            //cout << "Pro: " << Pro << "Milk:" << m_iMilk;
            break;
        default:
            break;
    }// switch
    m_iMoney -= Money;

    if(m_iWood > m_iSize)
            m_iWood = m_iSize;
        if(m_iBrick > m_iSize)
                m_iBrick = m_iSize;
        if(m_iTools > m_iSize)
                m_iTools = m_iSize;
        if((m_iFishes /*-=  (m_iInhabitans_1 + m_iInhabitans_2)*/) > m_iSize)
                m_iFishes = m_iSize;
        if(m_iMilk > m_iSize)
                m_iMilk = m_iSize;
        if(m_iSlime > m_iSize)
                m_iSlime = m_iSize;

    if(m_iWood < 0)
            m_iWood = 0;
        if(m_iBrick < 0)
            m_iBrick = 0;
        if(m_iTools < 0)
            m_iTools = 0;
        if(m_iFishes < 0)
            m_iFishes = 0;
        if(m_iMilk < 0)
            m_iMilk = 0;
        if(m_iSlime < 0)
            m_iSlime = 0;
}
// SaveBudget
//
// Aufgabe: Speichert das Spielerbudget in einer Datei
//

void CBudget::SaveBudget(int const SaveID, char *File) {
    // Öffnen der Speicherdatei
    if ((m_Fsave = fopen(File, "a")) == NULL) {
        cout << "Es konnte nicht gespeichert werden!!!" << endl;
        return;
    } // if

    // Speichern des Spielerbudget und Berechnungsfaktoren
    fprintf(m_Fsave, "%i\n", m_iInhabitans_1);
    fprintf(m_Fsave, "%i\n", m_iInhabitans_2);
    fprintf(m_Fsave, "%i\n", m_iMoney);
    fprintf(m_Fsave, "%i\n", m_iWood);
    fprintf(m_Fsave, "%i\n", m_iSlime);
    fprintf(m_Fsave, "%i\n", m_iBrick);
    fprintf(m_Fsave, "%i\n", m_iStones);
    fprintf(m_Fsave, "%i\n", m_iFishes);
    fprintf(m_Fsave, "%i\n", m_iMilk);
    fprintf(m_Fsave, "%i\n", m_iTools);
    fprintf(m_Fsave, "%i\n", m_iMoneyFactor);
    fprintf(m_Fsave, "%i\n", m_iWoodFactor);
    fprintf(m_Fsave, "%i\n", m_iSlimeFactor);
    fprintf(m_Fsave, "%i\n", m_iBrickFactor);
    fprintf(m_Fsave, "%i\n", m_iStoneFactor);
    fprintf(m_Fsave, "%i\n", m_iFishFactor);
    fprintf(m_Fsave, "%i\n", m_iMilkFactor);
    fprintf(m_Fsave, "%i\n", m_iApartments_1 - 2);
    fprintf(m_Fsave, "%i\n", m_iSize);

    // Datei schließen
    fclose(m_Fsave);

    delete File;

}// SaveBudget

// LoadBudget
//
// Aufgabe: Lädt das Spielerbudget aus einer Datei
//

void CBudget::LoadBudget(int constSaveID, char *File) {

    m_Fload = fopen(File, "r");
    for (int i = 0; i < 19200; i++)
        fscanf(m_Fload, "%i", &m_iLoadBuffer);
    fscanf(m_Fload, "%i", &m_iInhabitans_1);
    fscanf(m_Fload, "%i", &m_iInhabitans_2);
    fscanf(m_Fload, "%i", &m_iMoney);
    fscanf(m_Fload, "%i", &m_iWood);
    fscanf(m_Fload, "%i", &m_iSlime);
    fscanf(m_Fload, "%i", &m_iBrick);
    fscanf(m_Fload, "%i", &m_iStones);
    fscanf(m_Fload, "%i", &m_iFishes);
    fscanf(m_Fload, "%i", &m_iMilk);
    fscanf(m_Fload, "%i", &m_iTools);
    fscanf(m_Fload, "%i", &m_iMoneyFactor);
    fscanf(m_Fload, "%i", &m_iWoodFactor);
    fscanf(m_Fload, "%i", &m_iSlimeFactor);
    fscanf(m_Fload, "%i", &m_iBrickFactor);
    fscanf(m_Fload, "%i", &m_iStoneFactor);
    fscanf(m_Fload, "%i", &m_iFishFactor);
    fscanf(m_Fload, "%i", &m_iMilkFactor);
    fscanf(m_Fload, "%i", &m_iApartments_1);
    fscanf(m_Fload, "%i", &m_iSize);
    // Datei schließen
    fclose(m_Fload);

}// LoadBudget

