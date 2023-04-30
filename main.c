#include "vodogEngine.c"
#include "paddle.c"

#include <stdio.h>
#include <math.h>
#include <time.h>

#define SCREENWIDTH 140
#define SCREENHEIGHT 60
#define SCREENSIZE SCREENHEIGHT*SCREENWIDTH

int main(){

    // Random bullshit to create a new Screen

    COORD screensize;
    screensize.X = SCREENWIDTH;
    screensize.Y = SCREENHEIGHT;

    //Actually make new Screen

    HANDLE screen = createScreen(screensize,"Pong");

    //Create FrameBuffer to write to console every frame
    unsigned char frameBuffer[SCREENSIZE];
    for (size_t i = 0; i < SCREENSIZE; i++)
    {
        frameBuffer[i] = 0;
    }
    clock_t fps;
    clock_t delta_ticks = 0;
    paddle player1;
    player1.x = 0;
    player1.y = 5;
    player1.height = 6;
    player1.width = 1;
    player1.is_Ai = 0;


	INPUT_RECORD inputs[128];
    while(1){
        //Clear Screen
        for (size_t i = 0; i < SCREENSIZE; i++)
        {
            frameBuffer[i] = 0;
        }
        

        clock_t current_ticks = clock();

        // gets all inputs from this frame
        inputhandle(inputs);

        for (size_t i = 0; i < sizeof(inputs) / sizeof(INPUT_RECORD); i++)
        {
            switch (inputs[i].EventType)
            {
            case KEY_EVENT:
                    if(inputs[i].Event.KeyEvent.uChar.AsciiChar == 119){
                        player1.y -= 1;
                    }                    
                    if(inputs[i].Event.KeyEvent.uChar.AsciiChar == 115){
                        player1.y += 1;
                    }                
                    break;
            
            default:
                break;
            }
        }
        
        //Add player 1 to be renderde
        for (size_t i = 0; i < roundf(player1.height); i++)
        {
            int player1YAbs = roundf(player1.y+i);
            int player1XAbs = roundf(player1.x);
            int index = (player1YAbs * SCREENWIDTH + player1XAbs);
            frameBuffer[index]= 35;
            
        }

        

        drawScreen(screen,frameBuffer,screensize,fps);

        // I think this does FPS?
        delta_ticks = clock() - current_ticks;
        if(delta_ticks > 0){
            fps = CLOCKS_PER_SEC / delta_ticks;
        }
    }

    return 0;
}
