#ifndef SNAKE_INPUT
#define SNAKE_INPUT


#include "GLFW/glfw3.h"
class Input
{
public:


	static void KeyCallBack(GLFWwindow* window, int key, int scanCode, int action, int mods);

	static bool KeyDown(int key);
	static bool KeyUp(int key);
	static bool Key(int key);

private:
	static bool keys[];
	static bool keysDown[];
	static bool keysUp[];

};

#endif