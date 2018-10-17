
#include "Engine.h"
#include "Input.h"
#include "Snake.h"
#include <Windows.h>

#include <iostream>

#include <chrono>

#define PERIOD_OF_FRAME_MS (128)

int main() {
	

	Engine engine;
	
	
	std::chrono::milliseconds periodOfFrame(PERIOD_OF_FRAME_MS);

	auto tStart = std::chrono::steady_clock::now();
	auto tEnd = tStart;

	std::cout << "Close console to exit";
	

	engine.Initialize();

	Snake snake;

	while (true)
	{
		
		snake.Input();
		engine.Update();

		if(tStart > tEnd + periodOfFrame){

			
			engine.BeginRender();
			snake.Update();
			engine.EndRender();
			tEnd = std::chrono::steady_clock::now();
			
		}

		tStart = std::chrono::steady_clock::now();

	}

	return 0;
}