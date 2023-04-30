#include <Windows.h>

#include <stdio.h>

HANDLE createScreen(COORD size,char name[]){

	HANDLE buffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,NULL,CONSOLE_TEXTMODE_BUFFER,NULL);

	SetConsoleScreenBufferSize(buffer,size);

	SetConsoleActiveScreenBuffer(buffer);

	SetConsoleTitleA(name);

	return buffer;
}

void inputhandle( INPUT_RECORD inputbuff[]){;
	HANDLE inputbuffer = GetStdHandle(STD_INPUT_HANDLE);

	DWORD troll;
	ReadConsoleInputA(inputbuffer,inputbuff,128,&troll);
}




void drawScreen(HANDLE buffer, unsigned char frameBuffer[] ,COORD size,float dt){
	COORD zeropoint;

	zeropoint.X = 0;
	zeropoint.Y = 0;

	DWORD troll;

	//frameBuffer[100*50 - 1] = 0;

	//Create FPS Counter
	// int fps = dt * 1000;
	// char fpsstring[9];
	// sprintf(fpsstring,"%d",fps);

	// for (size_t i = 0; i < 10; i++)
	// {
	// 	frameBuffer[i] = fpsstring[i];
	// }


	WriteConsoleOutputCharacterA(buffer,frameBuffer,size.X*size.Y,zeropoint,&troll);

}
