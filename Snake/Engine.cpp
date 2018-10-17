#include "Engine.h"
#include "Input.h"
#include "Snake.h"





int
Engine::SCREEN_HEIGHT = 600,
Engine::SCREEN_WIDTH = 900;

GLFWwindow*
Engine::window = NULL;

Engine::Engine()
{
}


Engine::~Engine()
{
}

bool Engine::Initialize() {
	if (!glfwInit()) {
		std::cout << "glfw failed to initialize \n";

		return false;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake", 0 , 0);
	if (window == NULL)
	{
		std::cout << "window failed to initialize \n";
		return false;
	}


	//GLFW setup

	glfwMakeContextCurrent(window);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1);

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int
		xPos = (mode->width - SCREEN_WIDTH) / 2,
		yPos = (mode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);

	
	//input

	glfwSetKeyCallback(window, Input::KeyCallBack);

	//Gl Setup
	//Viewport
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -10, 10);
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);

	

	//alpha blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glEnable(GL_SRC_ALPHA | GL_ONE_MINUS_SRC_ALPHA);

	return true;

};

void Engine::Update() {
	
		glfwPollEvents();
	
}



void Engine::BeginRender() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




}

void Engine::EndRender(){


	glfwSwapBuffers(window);

}


