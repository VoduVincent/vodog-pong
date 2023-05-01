#include <math.h>

typedef struct vertex
{
    float x;
    float y;
} vertex;

typedef struct edge
{
    vertex vertex1;
    vertex vertex2;
} edge;



typedef struct cube
{
    //Yes, this is terrible
    vertex vertcies[4];
    //So is this
    edge edges[4];


} cube;

void renderLines(cube cube,unsigned char input[]){
    for (size_t i = 0; i < 4; i++)
    {
        float m = (cube.vertcies[i+1].y - cube.vertcies[i].y) / (cube.vertcies[i+1].x - cube.vertcies[i].x);

        for (size_t x = cube.vertcies[i].x; x <= cube.vertcies[i+1].x; x++)
        {
            int y = roundf(m * x);

            int pos = y*2 * 140 + cube.vertcies[i].x;

            input[pos] = 35;
        }
    }
}



void drawpoints(cube cube,unsigned char input[]){
    for (size_t i = 0; i < sizeof(cube.vertcies) / sizeof(vertex); i++)
    {
        int pos = cube.vertcies[i].y * 140 + cube.vertcies[i].x;

        input[pos] = 35;
    }
    
}