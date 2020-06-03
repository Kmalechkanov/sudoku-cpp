#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>  
#include "manager.h"
#include "globalconstants.h"

void Manager::shuffle(std::vector<int>* numbers, int times)
{
	for (int i = 0; i < times; i++)
	{
		std::random_shuffle(numbers->begin(), numbers->end());
	}
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
		int shuffleTimes = seedForUse % 10;
		this->refill(&numbers);

		while (true)
		{
			this->shuffle(&numbers, shuffleTimes);
			int h = numbers.back()-1;
			this->shuffle(&numbers, shuffleTimes / (h+1));
			int w = numbers.front()-1;

			if (matrix[h][w] != 0)
			{
				matrix[h][w] = 0;
				break;
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
