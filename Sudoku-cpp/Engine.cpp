#include "engine.h"

#include <iostream>

#include "manager.h"
#include "menu.h"

Engine::Engine(std::vector<std::vector<int>> saved,
	std::vector<std::vector<int>> original, 
	std::vector<std::vector<int>> solution,
	std::string name)
{
	this->matrix = saved;
	this->initialMatrix = original;
	this->solution = solution;
	this->name = name;
}

void Engine::Start() 
{
	Manager manager;
	Menu menu;

	int box = -1;
	int cell = -1;
	int value = -1;

	int x, y;

	bool resetInput = false;
	std::string invalidMsg;

	manager.clearConsole();
	while (true)
	{
		manager.drawMatrix(this->initialMatrix, this->matrix);

		if (box == -1)
		{
			std::cout << "\nInsert box: ";
			std::cin >> box;

			if (box == 0)
			{
				int response = menu.InGameMenu();
				
				//TODO take this part away
				if (response == 0)
				{
					manager.saveGame(this->matrix, this->name);
				}
				else if (response == 1)
				{
					manager.saveGame(this->matrix, this->name);
					break;
				}
				else if (response == 2)
				{
					break;
				}

				resetInput = true;
			}
			else if (box < 1 || box > 9)
			{
				invalidMsg = "Invlid box!\n";
				box = -1;
			}
		} 
		else if (cell == -1)
		{
			std::cout << "\nInsert cell: ";
			std::cin >> cell;

			if (cell == 0)
			{
				resetInput = true;
			} 
			else if (cell < 1 || cell > 9)
			{
				invalidMsg = "Invlid cell!\n";
				cell = -1;
			}
		}
		else if (value == -1)
		{
			x = (2 - (box - 1) / 3) * 3 + (2 - (cell - 1) / 3);
			y = 8 - ((2 - (box - 1) % 3) * 3 + (2 - (cell - 1) % 3));

			if (this->initialMatrix[x][y] != 0)
			{
				invalidMsg = "This cell cannot be modified!\n";
				resetInput = true;
			}
			else
			{
				std::cout << "Insert value: ";
				std::cin >> value;

				if (value < 0 || value > 9)
				{
					invalidMsg = "Invlid value!\n";
					value = -1;
				}
				else
				{
					this->matrix[x][y] = value;
					resetInput = true;
				}
			}
		}

		if (resetInput)
		{
			x = 0;
			y = 0;
			box = -1;
			cell = -1;
			value = -1;

			resetInput = false;
		}

		manager.clearConsole();

		if (invalidMsg != "")
		{
			manager.setColor(GlobalConstants::Colors::Red);
			std::cout << invalidMsg;
			invalidMsg = "";
		}

		if (manager.checkSolve(this->matrix,this->solution))
		{
			manager.drawMatrix(this->initialMatrix, this->matrix);

			manager.setColor(GlobalConstants::Colors::Green);
			std::cout << "Congratulations! You solve the sudoku!" << std::endl;
			manager.setColor(GlobalConstants::Colors::White);

			std::cout << "Press any key to continue: ";
			std::cin.ignore();
			std::cin.get();

			manager.saveGame(this->matrix, this->name);
			break;
		}
	}
}