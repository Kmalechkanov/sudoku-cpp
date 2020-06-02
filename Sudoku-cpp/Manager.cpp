#include "Manager.h"
#include <Vector>
#include <Algorithm>
#include "GlobalConstants.h"

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