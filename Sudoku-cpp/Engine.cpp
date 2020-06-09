#include "engine.h"

#include <iostream>

#include "manager.h"

Engine::Engine(std::vector<std::vector<int>> saved, std::vector<std::vector<int>> original) {
	this->matrix = saved;
	this->initialMatrix = original;
}

void Engine::Start() {
	Manager manager;

	while (true)
	{
		manager.clearConsole();
		manager.drawMatrix(this->matrix);

		std::cin.ignore();
		std::cin.get();

	}
}