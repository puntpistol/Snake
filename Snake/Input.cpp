#include "Input.h"


bool Input::keys[GLFW_KEY_LAST] = {};
bool Input::keysDown[GLFW_KEY_LAST] = {};
bool Input::keysUp[GLFW_KEY_LAST] = {};

void Input::KeyCallBack(GLFWwindow* window, int key, int scanCode, int action, int mods) {
	if (key < 0)
		return;
	if (action != GLFW_RELEASE && !keys[key]) {

		keysDown[key] = true;
		keysUp[key] = false;
	}

	if (action == GLFW_RELEASE && keys[key]) {

		keysDown[key] = false;
		keysUp[key] = true;
	}

	keys[key] = action != GLFW_RELEASE;


	
}

bool Input::KeyDown(int key) {
	bool x = keysDown[key];
	keysDown[key] = false;
	return x;
}

bool Input::KeyUp(int key) {
	bool x = keysUp[key];
	keysDown[key] = false;
	return x;
}

bool Input::Key(int key) {
	return keys[key];
}


