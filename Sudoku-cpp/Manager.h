#pragma once
#include <vector>
#include <string>

class Manager
{
private:
public:
	void shuffle(std::vector<int>*, int);
	void refill(std::vector<int>*);
	void saveFile(std::vector<std::vector<int>>, std::string, std::string);

	void saveSolution(std::vector<std::vector<int>>, std::string);
	void saveSudoku(std::vector<std::vector<int>>, std::string);

	void makeSudoku(std::vector<std::vector<int>>, std::string, int, int);

	void clearConsole();

	std::vector<std::string> getAllSolutions();
	std::vector<std::string> getAllSudokus();

	std::vector<std::vector<int>> getSolution(std::string);
	std::vector<std::vector<int>> getSudoku(std::string);
	
	std::vector<std::vector<int>> openFile(std::string);

};