#include "vodogEngine.c"
#include "cube.c"


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

	INPUT_RECORD inputs[128];



    // Defining the Cube manually
    cube cube1;
         
    cube1.vertcies[0].x = 5;
    cube1.vertcies[0].y = 5;

    cube1.vertcies[1].x = 10;
    cube1.vertcies[1].y = 5;

    cube1.vertcies[2].x = 5;
    cube1.vertcies[2].y = 10;

    cube1.vertcies[3].x = 10;
    cube1.vertcies[3].y = 10;

    while(1){
        //Clear Screen
        for (size_t i = 0; i < SCREENSIZE; i++)
        {
            frameBuffer[i] = 0;
        }
        

        clock_t current_ticks = clock();

        // gets all inputs from this frame
        inputhandle(inputs);


        renderLines(cube1,frameBuffer);
        drawpoints(cube1,frameBuffer);
        

        drawScreen(screen,frameBuffer,screensize,fps);

        // I think this does FPS?
        delta_ticks = clock() - current_ticks;
        if(delta_ticks > 0){
            fps = CLOCKS_PER_SEC / delta_ticks;
        }
    }

    return 0;
}
