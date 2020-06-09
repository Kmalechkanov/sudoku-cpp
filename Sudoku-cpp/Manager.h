#pragma once
#include <vector>
#include <string>

#include "globalconstants.h"

class Manager
{
private:
	std::string saveFile(std::vector<std::vector<int>>, std::string, std::string);

	std::vector<std::string> getFilesNames(std::string);

	std::vector<std::vector<int>> readFile(std::string);
public:
	void shuffle(std::vector<int>*, int);
	void refill(std::vector<int>*);

	void clearConsole();
	void drawMatrix(std::vector<std::vector<int>>);
	void drawMatrix(std::vector<std::vector<int>>, std::vector<std::vector<int>>);
	void startGame(std::vector<std::vector<int>>, std::vector<std::vector<int>>);

	void setColor(GlobalConstants::Colors);

	std::string makeSudoku(std::vector<std::vector<int>>, std::string, int, int);

	std::string saveSolution(std::vector<std::vector<int>>, std::string);
	std::string saveSudoku(std::vector<std::vector<int>>, std::string);
	std::string saveGame(std::vector<std::vector<int>>, std::string);

	std::vector<std::string> getAllSolutions();
	std::vector<std::string> getAllSaves();

	std::vector<std::vector<int>> getSolution(std::string);
	std::vector<std::vector<int>> getSudoku(std::string);
};