// Eye of Ra - Arbeitsprobe
// Florian Blasius
// 2010-2011
//
#include <stdio.h>
#include "Framework.h"
#include "Game.h"


int main(int argc, char *argv[]) {

    // screen resolution
    int x, y, fullscreen;
    bool setfullscreen;
    // user-config file
    FILE *config;
    
    // open user-config file
    if ((config = fopen("content/user/config/config.txt", "r")) == NULL)
        printf("Die Datei UserConfig.txt konnte nicht geoeffnet werden\n");

    fscanf(config, "%i", &x);
    fscanf(config, "%i", &y);
    fscanf(config, "%i", &fullscreen);

    if (fullscreen)
        setfullscreen = true;
    else
        setfullscreen = false;

    // close user-config
    fclose(config);

    // Framework initialisieren
    if (g_pFramework->Init(x, y, 16, setfullscreen) == false)
        return (0);

    // new object of game
    CGame Game;

    // set resolution
    Game.SetResolution(x,y);
    
    // game initialize
    Game.Init();

    // run game
    Game.Run();

    // quit game
    Game.Quit();


    // close framework
    g_pFramework->Quit();
    g_pFramework->Del();

    return (0);

}