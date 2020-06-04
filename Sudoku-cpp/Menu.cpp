#include "menu.h"

#include <iostream>
#include <string>

#include "manager.h"

Manager manager;


void Menu::Main() {
	manager.clearConsole();

	while (true)
	{
		std::cout << std::endl
			<< "[X] Sudoku\n"
			<< "| |\n"
			<< "|0| Play\n"
			<< "|1| Solutions\n"
			<< "|2| Exit\n"
			<< "| |\n"
			<< "[X] Select: ";

		int input = -1;

		std::cin >> input;

		if (input == 0)
		{
			this->Play();
			break;
		}
		else if (input == 1)
		{
			this->Solutions();
			break;
		}
		else if (input == 2)
		{
			return;
		}

		manager.clearConsole();
		std::cout << "Invalid option!" << std::endl;
	}
}

void Menu::Play() {
	manager.clearConsole();

	while (true)
	{
		std::cout << std::endl
			<< "[X] Play\n"
			<< "| |\n"
			<< "|0| New Game\n"
			<< "|1| Load Game\n"
			<< "|2| Delete Game\n"
			<< "| |\n"
			<< "|3| Back\n"
			<< "| |\n"
			<< "[X] Select Game: ";

		int input = -1;

		std::cin >> input;

		if (input == 0)
		{
			// TODO
			break;
		}
		else if (input == 1)
		{
			// TODO
			break;
		}
		else if (input == 2)
		{
			// TODO
			break;
		}
		else if (input == 3)
		{
			this->Main();
			break;
		}

		manager.clearConsole();
		std::cout << "Invalid option!" << std::endl;
	}
}

void Menu::Solutions() {
	manager.clearConsole();

	std::vector<std::string> solutions = manager.getAllSolutions();
	int input = -1;

	while (true)
	{
		std::cout << std::endl
			<< "[X] Solutions\n"
			<< "| |\n";

		for (int i = 0; i < solutions.size(); i++)
		{
			std::cout << "|" << i << "| " << solutions[i] << "\n";
		}

		std::cout << "| |\n"
			<< "|" << solutions.size() << "|" << " Back\n"
			<< "| |\n"
			<< "[X] Select Game: ";

		std::cin >> input;

		if (input >= 0 && input < solutions.size())
		{
			// TODO
			break;
		}
		else if (input == solutions.size())
		{
			this->Main();
			break;
		}

		manager.clearConsole();
		std::cout << "Invalid option!" << std::endl;
	}
}