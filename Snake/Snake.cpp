#include "Snake.h"






Snake::Snake() {
	


	Update();
	DrawSquare(xBody[0], yBody[0]);

}

void Snake::DrawSquare(float x, float y) {
	
	
	glBegin(GL_POLYGON);

	glColor3f(1, 0, 1);

	glVertex3f(x, y, 0);
	glVertex3f(x + 20, y, 0);
	glVertex3f(x + 20, y + 20, 0);
	glVertex3f(x, y + 20, 0);



	glEnd();
}


void Snake::Input() {


	//std::cout << dir<<std::endl;

	if (Input::Key(GLFW_KEY_W) && dir != SOUTH)
	{
		dir = NORTH;
	}
	else if (Input::Key(GLFW_KEY_S) && dir != NORTH)
	{
		dir = SOUTH;
	}
	else if (Input::Key(GLFW_KEY_A) && dir != EAST)
	{
		dir = WEST;
	}

	else if (Input::Key(GLFW_KEY_D) && dir != WEST)
	{
		dir = EAST;
	}

}


void Snake::Update() {
	
	

	if (dir == NORTH)
	{
		yBody[0] += speed;
	}
	if (dir == EAST)
	{
		xBody[0] += speed;
	}
	if (dir == SOUTH)
	{
		yBody[0] -= speed;
	}
	if (dir == WEST)
	{
		xBody[0] -= speed;
	}
	
	


	if (xBody[0]> MAX_X_POS)
		xBody[0] = 0;
		
	if (yBody[0] > MAX_Y_POS)
		yBody[0] = 0;

	if (xBody[0]  < 0)
		xBody[0] = MAX_X_POS;

	if (yBody[0]  < 0)
		yBody[0] = MAX_Y_POS;


	//for (int i = 1; i < tailLength; i++)
	//{
	//	if (xBody[0] == xBody[i] && yBody[0] == yBody[i])
	//	{
	//		std::cout << "gameover";
	//	}
	//}

	
	DrawSquare(xBody[0], yBody[0]);
	
	for (int i = tailLength; i > 0; i--)
	{
		xBody[i] = xBody[i - 1];
		yBody[i] = yBody[i - 1];

		DrawSquare(xBody[i], yBody[i]);
	}
	


}





	




