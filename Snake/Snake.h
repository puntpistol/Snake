#ifndef SNAKE_SNAKE
#define SNAKE_SNAKE

#include <iostream>
#include "GLFW/glfw3.h"
#include "Input.h"
#include "Engine.h"
#include <random>
#include <list>
#include <vector>

#define MAX_Y_POS 600-20
#define MAX_X_POS 900-20


class Snake
{
public:

	Snake();
	void Update();
	void Input();

private:
	void DrawSquare(float xPos, float yPos);
	

	int tailLength=49;
	uint8_t speed = 20;
	int xBody[50];
	int yBody[50];
	//float xBody[50]{ 0 };
	//float yBody[50]{ 0 };
	enum eDirection
	 {
		 STOP = 0, NORTH, EAST, SOUTH, WEST
	 };
	eDirection dir = STOP;

	



};

#endif // !SNAKE_SNAKE