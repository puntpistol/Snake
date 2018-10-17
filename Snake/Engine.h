#ifndef SNAKE_ENGINE
#define SNAKE_ENGINE



#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")

#include <iostream>

class Engine
{
public:
	
	static int SCREEN_HEIGHT;
	static int SCREEN_WIDTH;

	Engine();
	~Engine();

	bool Initialize();
	void Update();
	void BeginRender();
	void EndRender();

private:
	static GLFWwindow* window;
};

#endif // !SNAKE_ENGINE