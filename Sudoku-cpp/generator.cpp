#include <iostream>
#include <vector>
#include <algorithm>
#include "Generator.h"
#include "GlobalConstants.h"
#include "Manager.h"

std::vector<std::vector<int>> Generator::generate(int seed)
{
	std::vector<std::vector<int>> matrix(GlobalConstants::SudokuHeight, std::vector<int>(GlobalConstants::SudokuWidth, 0));;
	std::vector<int> numbers;

	Manager manager;

	manager.refill(&numbers);

	for (int h = 0; h < GlobalConstants::SudokuHeight; h++)
	{
		manager.shuffle(&numbers, seed % 10);
		seed /= 10;

		for (int w = 0; w < GlobalConstants::SudokuWidth; w++)
		{
			if (h == 0)
			{
				matrix[h][w] = numbers.back();
				numbers.pop_back();
				continue;
			}

			int startedWith = numbers.back();
			bool isStuck = false;

			while (true)
			{
				bool alreadyUsed = false;

				for (int hBackwards = 0; hBackwards < h%3; hBackwards++)
				{
					for (int wBackwards = 0; wBackwards < 3; wBackwards++)
					{
						if (matrix[(h/3*3+ hBackwards)][w / 3 * 3 + wBackwards] == numbers.back())
						{
							alreadyUsed = true;
							break;	
						}
					}
				}

				for (int hBackwards = 0; hBackwards < h; hBackwards++)
				{

					if (matrix[hBackwards][w] == numbers.back())
					{
						alreadyUsed = true;
						break;
					}
				}

				if (alreadyUsed)
				{
					numbers.emplace(numbers.begin(), numbers.back());
					numbers.pop_back();

					if (startedWith == numbers.back())
					{
						isStuck = true;
						break;
					}

					continue;
				}

				break;
			}

			if (isStuck)
			{
				int seedDigit = numbers.back();
				for (int i = 0; i < 9; i++)
				{
					matrix[h][i] = 0;
					manager.refill(&numbers);
				}
				manager.shuffle(&numbers, seedDigit);
				w = -1;
				continue;
			}

			matrix[h][w] = numbers.back();
			numbers.pop_back();
		}

		manager.refill(&numbers);
	}

	return matrix;
}