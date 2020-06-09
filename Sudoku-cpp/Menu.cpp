#include "menu.h"

#include <iostream>
#include <string>

#include "manager.h"
#include "generator.h"

Manager manager;
Generator generator;

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
			<< "|2| Delete Game (In development)\n"
			<< "| |\n"
			<< "|3| Back\n"
			<< "| |\n"
			<< "[X] Select Game: ";

		int input = -1;

		std::cin >> input;

		if (input == 0)
		{
			this->NewGame();
			break;
		}
		else if (input == 1)
		{
			this->LoadGame();
			break;
		}
		else if (input == 2)
		{
			// TODO possability to delete solutions and levels
			this->Main();
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

void Menu::NewGame() {
	manager.clearConsole();
	
	int seed;
	int difficulty;
	std::string name;

	std::cout << std::endl
		<< "[X] New Game\n"
		<< "| | \n"
		<< "| | / Shouldn't contain zeroes! \\\n"
		<< "| | \\ Example seed - 4739225125 /\n";
		
	while (true)
	{
		std::cout << "[X] Insert seed: ";
		std::cin >> seed;
		std::string seedStr = std::to_string(seed);

		size_t substring_length;
		if (!((substring_length = seedStr.find('0')) != std::string::npos)) {
			break;
		}

		std::cout << "| | Invalid seed!\n";
	}

	std::cout << "| | \n"
		<< "[X] Difficulty\n"
		<< "| | \n"
		<< "|0| Easy\n"
		<< "|1| Normal\n"
		<< "|2| Hard\n"
		<< "|3| Expert\n"
		<< "| | \n";

	while (true)
	{
		std::cout << "[X] Select Difficulty: ";
		std::cin >> difficulty;

		if (difficulty >= 0 && difficulty <= 3)
		{
			break;
		}

		std::cout << "| | Invalid input!\n";
	}

	std::cout << "| | \n" 
		<< "[X] Insert Sudoku name: ";
	std::cin >> name;

	std::vector<std::vector<int>> sudoku = generator.generate(seed);
	manager.saveSolution(sudoku, name);

	std::string path = manager.makeSudoku(sudoku, name, difficulty + 2, seed);

	std::cout << "| | \n"
		<< "[X] Succesfully created \"" << name << "\" with seed " << seed << " and difficulty " << difficulty << "!\n";

	std::cout << path << std::endl;

	manager.startGame(sudoku, sudoku);
}

void Menu::LoadGame() {
	manager.clearConsole();

	std::vector<std::string> sudokus = manager.getAllSaves();
	int input = -1;

	while (true)
	{
		std::cout << std::endl
			<< "[X] Sudokus\n"
			<< "| |\n";

		for (int i = 0; i < sudokus.size(); i++)
		{
			std::cout << "|" << i << "| " << sudokus[i] << "\n";
		}

		std::cout << "| |\n"
			<< "|" << sudokus.size() << "|" << " Back\n"
			<< "| |\n"
			<< "[X] Select Game: ";

		std::cin >> input;

		if (input >= 0 && input < sudokus.size())
		{
			std::vector<std::vector<int>> sudoku = manager.getSudoku(sudokus[input]);
			std::string initSudokuPath = "Sudokus" + sudokus[input].substr(5);
			
			std::cout << initSudokuPath << std::endl;

			std::vector<std::vector<int>> sudokuInit = manager.getSudoku(initSudokuPath);

			manager.startGame(sudoku,sudokuInit);
			break;
		}
		else if (input == sudokus.size())
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
			std::vector<std::vector<int>> matrix = manager.getSolution(solutions[input]);

			manager.clearConsole();
			manager.drawMatrix(matrix);

			std::cout << "\n[X] Press any key to back: ";
			std::cin.ignore();
			std::cin.get();

			this->Main();
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