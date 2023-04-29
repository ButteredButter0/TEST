// SDL Winow and Renderer.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Window.h"
#include "Input.h"
#include "Update.h"
#include "Render.h"
#include "Timer.h"
#include "Player.h"
#include "GameManager.h"
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("Error: SDL could not initalise. SDL error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() < 0) {
        cout << ("Error: TTF could not initialise. SDL error: ") << TTF_GetError() << "\n";
    }


    //Creates a non-fullscreen window with shown name and dimensions
    string WINDOW_NAME = "Name: Jamie Critchley, Module: Game Programming(CGP2015M), ID: 25719572, Title: Night of the Squid";
    int windowWidth = 802;
    int windowHight = 600;
    Window window(WINDOW_NAME, 10, 30, windowWidth, windowHight, SDL_WINDOW_SHOWN);

    //Black window
    window.setWindowColour(0, 0, 0, 255);

    //Game Loop
    bool running = true;


    //Run at 60 fps
    Timer timer(60);

    //Create objects for game
    Player* player = nullptr;
    GameManager gameManager;
    gameManager.gameSetup(windowHight, windowWidth, &player, &window);


    //Establish gameloop objects
    Input input(player);
    Update update(windowHight, windowWidth, player);
    Render render(window, player, &timer);
    int gameTime = 0;

    while (running) {

        timer.startTimer();


        input.getInput();
        update.getUpdate();
        render.getRender();

        timer.endTimer();

        //Checks if game should end
        timer.getGameTimer(gameTime);
        if (gameTime > 45000)
        {
            running = false;
        }

    }
    
    





    return 0;
}
