#include <vector>
#include <string>
#include "globalconstants.h"
#pragma once
class Manager
{
private:
public:
	void shuffle(std::vector<int>*, int);
	void refill(std::vector<int>*);
	void saveSolution(std::vector<std::vector<int>>, std::string);
	void makeSudoku(std::vector<std::vector<int>>, std::string, int, int);

	std::vector<std::vector<int>> getSolution(std::string);
	std::vector<std::vector<int>> getSudoku(std::string);
};

