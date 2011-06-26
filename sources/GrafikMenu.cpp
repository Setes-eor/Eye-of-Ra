#include "GrafikMenu.h"

// Konstruktor
//
CGrafikMenu::CGrafikMenu(){

}// Konstruktor

// Überladene Konstruktor
//
CGrafikMenu::CGrafikMenu(string File, int Weight = 200, int Hight = 787,
        int Anim = 0, int XPos = 1700, int YPos = 170):
CMenu(File,Weight,Hight,Anim,XPos,YPos){
}// Überladener Konstruktor


CGrafikMenu::~CGrafikMenu(){

}

void CGrafikMenu::Init(){

    m_pBackground ->Load(m_sFileName, m_iAnim, m_iWeight, m_iHight);
    m_pBackground ->SetColorKey(0, 0, 0);

}// Init

// BuildSelected
//
// Aufgabe: Führt verschiedene Optionen aus
//
void CGrafikMenu::Option(const int XPos, const int YPos, bool &GrafikAktiv,
        const int Weight, const int Hight){

    /*FILE *m_FConfig;
    char *File;


     if ((m_FConfig = fopen("Data/UserConfig/UserConfig.txt", "w")) == NULL) {
        cout << "Feld konnte nicht gespeichert werden!!!" << endl;
        return;
    } // if

    switch(getButtonID(XPos,YPos,Weight,Hight)){

        case(1):
            File = new char;
            File = "1920/n1080/n"
            fprintf(m_FConfig,"1920/n1080/n");
            break;
        case(2):
            File = "1920/n1080/n"
            fprintf(m_FConfig,"1920/n1080/n");
            break;
        case(3):
            File = "1920/n1080/n"
            fprintf(m_FConfig,"1440/n900/n");
            break;
        case(4):
            File = "1920/n1080/n"
            fprintf(m_FConfig,"1280/n800/n");
            break;
        case(5):
            File.append("1");
             break;
        case(6):

        default:
            break;
    }//switch
    fclose(m_FConfig);*/
    
}// BuildSelected