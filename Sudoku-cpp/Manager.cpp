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

void Manager::drawMatrix(std::vector<std::vector<int>> matrix) {
	for (int h = 0; h < GlobalConstants::SudokuHeight; h++)
	{
		if (h % 3 == 0)
		{
			std::cout << "+---+---+---+" << std::endl;
		}

		for (int w = 0; w < GlobalConstants::SudokuWidth; w++)
		{
			if (w % 3 == 0)
			{
				std::cout << "|";
			}
			std::cout << matrix[h][w];
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "+---+---+---+" << std::endl;
}

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
	int toBeRemoved = allBoxes / (7 - difficulty);
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
		
		int cycles = 0;
		while (true)
		{
			if (matrix[h][w] != 0)
			{
				matrix[h][w] = 0;
				break;
			}

			numbers.emplace(numbers.begin(), numbers.back());
			numbers.pop_back();
			h = numbers.back() - 1;
			w = numbers.front() - 1;
			cycles++;

			if (cycles == 8)
			{
				cycles = 0;
				this->shuffle(&numbers, shuffleSeed);
			}
		}

		seedForUse /= 10;
		if (seedForUse == 0)
		{
			seedForUse = seed;
		}
	}

	std::string sudokuName = name + "-" + std::to_string(difficulty-2) + "-" + std::to_string(seed);

	this->saveSudoku(matrix, sudokuName);
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

std::vector<std::vector<int>> Manager::getSolution(std::string path)
{
	return this->readFile(path);
}

std::vector<std::vector<int>> Manager::getSudoku(std::string path)
{
	return this->readFile(path);
}

std::vector<std::vector<int>> Manager::readFile(std::string path)
{
	std::ifstream myfile(path);
	char c;
	int counter = 0;
	std::vector<std::vector<int>> matrix;
	std::vector<int> line;

	while ((myfile.get(c), myfile.eof()) == false) {
		if (c < '0' || c > '9')
		{
			continue;
		}

		line.push_back(c - '0');

		if (counter == 8)
		{
			matrix.push_back(line);
			line.clear();
			counter = 0;
			continue;
		}
		counter++;
	}

	return matrix;
}
