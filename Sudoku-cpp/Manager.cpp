#include "manager.h"

#include <iostream>
#include <fstream>  
#include <filesystem>
#include <vector>
#include <string>

#include "globalconstants.h"
#include <random>

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

void Manager::saveSolution(std::vector<std::vector<int>> solution, std::string name)
{
	std::ofstream fileStream("Solutions/" + name + ".txt");

	for (int i = 0; i < GlobalConstants::SudokuHeight; i++)
	{
		for (int j = 0; j < GlobalConstants::SudokuWidth; j++)
		{
			fileStream << std::to_string(solution[i][j]);
		}

		fileStream << std::endl;
	}

	fileStream.close();
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

	std::ofstream fileStream("Sudokus/" + name + "-" + std::to_string(difficulty) + "-" + std::to_string(seed) + ".txt");

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

std::string* Manager::getAllSolutions()
{
	std::string path = "Solutions/";

	for (const auto& entry : std::filesystem::directory_iterator(path))
		std::cout << entry.path() << std::endl;
	std::string* asds = new std::string;

	return asds;
}

//std::string* getAllSudokus();
//
//std::vector<std::vector<int>> getSolution(std::string);
//std::vector<std::vector<int>> getSudoku(std::string);