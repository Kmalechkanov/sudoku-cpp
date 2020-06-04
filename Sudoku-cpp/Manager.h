#pragma once
#include <vector>
#include <string>

class Manager
{
private:
	void saveFile(std::vector<std::vector<int>>, std::string, std::string);

	std::vector<std::vector<int>> readFile(std::string);
public:
	void shuffle(std::vector<int>*, int);
	void refill(std::vector<int>*);

	void saveSolution(std::vector<std::vector<int>>, std::string);
	void saveSudoku(std::vector<std::vector<int>>, std::string);

	void makeSudoku(std::vector<std::vector<int>>, std::string, int, int);

	void clearConsole();
	void drawMatrix(std::vector<std::vector<int>>);

	std::vector<std::string> getAllSolutions();
	std::vector<std::string> getAllSudokus();

	std::vector<std::vector<int>> getSolution(std::string);
	std::vector<std::vector<int>> getSudoku(std::string);
};