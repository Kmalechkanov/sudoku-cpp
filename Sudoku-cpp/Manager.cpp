#include "manager.h"

#include <iostream>
#include <fstream>  
#include <filesystem>
#include <vector>
#include <string>
#include <random>
#include <cstdlib>

#include "globalconstants.h"

#ifdef __cplusplus__

void Manager::clearConsole()
{
	cout << string(100, '\n');
}

#else

#include <stdio.h>

void Manager::clearConsole()
{
	int n;
	for (n = 0; n < 10; n++)
		printf("\n\n\n\n\n\n\n\n\n\n");
}

#endif 

void Manager::shuffle(std::vector<int>* numbers, int seed)
{
	std::mt19937 g(seed);
	std::shuffle(numbers->begin(), numbers->end(), g);
}

void Manager::refill(std::vector<int>* numbers)
{
	numbers->clear();

	for (int i = 0; i < GlobalConstants::SudokuWidth; i++)
	{
		numbers->push_back(i + 1);
	}
}

void Manager::saveFile(std::vector<std::vector<int>> matrix, std::string folder, std::string name)
{
	std::ofstream fileStream(folder + "/" + name + ".txt");

	for (int i = 0; i < GlobalConstants::SudokuHeight; i++)
	{
		for (int j = 0; j < GlobalConstants::SudokuWidth; j++)
		{
			fileStream << std::to_string(matrix[i][j]);
		}

		fileStream << std::endl;
	}

	fileStream.close();
}

void Manager::saveSolution(std::vector<std::vector<int>> solution, std::string name)
{
	this->saveFile(solution, "Solutions", name);
}

void Manager::saveSudoku(std::vector<std::vector<int>> sudoku, std::string name)
{
	this->saveFile(sudoku, "Sudokus", name);
}

void Manager::makeSudoku(std::vector<std::vector<int>> matrix, std::string name, int difficulty, int seed)
{
	int allBoxes = GlobalConstants::SudokuHeight * GlobalConstants::SudokuHeight;
	int toBeRemoved = allBoxes / difficulty;
	std::vector<int> numbers;
	int seedForUse = seed;


	for (int i = 0; i < toBeRemoved; i++)
	{
		int shuffleSeed = seedForUse % 10;
		this->refill(&numbers);

		this->shuffle(&numbers, shuffleSeed);
		int h = numbers.back()-1;
		this->shuffle(&numbers, shuffleSeed);
		int w = numbers.front()-1;

		while (true)
		{
			if (matrix[h][w] != 0)
			{
				matrix[h][w] = 0;
				break;
			}

			if (true)
			{
				numbers.emplace(numbers.begin(), numbers.back());
				numbers.pop_back();
				h = numbers.back() - 1;
				w = numbers.front() - 1;
			}
		}

		seedForUse /= 10;
		if (seedForUse == 0)
		{
			seedForUse = seed;
		}
	}

	std::string sudokuName = name + "-" + std::to_string(difficulty) + "-" + std::to_string(seed) + ".txt";

	this->saveFile(matrix, "Sudokus", sudokuName);
}

std::vector<std::string> Manager::getAllSolutions()
{
	std::string path = "Solutions/";
	std::vector<std::string> solutions;

	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		solutions.push_back(entry.path().string());
	}

	return solutions;
}

std::vector<std::string> Manager::getAllSudokus()
{
	std::string path = "Sudokus/";
	std::vector<std::string> sudokus;

	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		sudokus.push_back(entry.path().string());
	}

	return sudokus;
}
