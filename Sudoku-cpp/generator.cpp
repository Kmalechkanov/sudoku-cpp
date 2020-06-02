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
        seed /=10;

        for (int w = 0; w < GlobalConstants::SudokuWidth; w++)
        {
            if (h == 0)
            {
                matrix[h][w] = numbers.back();
                numbers.pop_back();
                continue;
            }

            while (true)
            {
                bool alreadyUsed = false;
                for (int hBackwards = 0; hBackwards < h; hBackwards++)
                {
                    if (matrix[hBackwards][w] == numbers.back() && numbers.back())
                    {
                        //std::cout << "matrix[hBackwards][w] == numbers.back() | " << matrix[hBackwards][w] << " | " << numbers.back() << std::endl;
                        //std::cout << "Used!\n";
                        alreadyUsed = true;
                        break;
                    }
                }

                if (alreadyUsed)
                {
                    numbers.emplace(numbers.begin(), numbers.back());
                    numbers.pop_back();
                    continue;
                }

                break;
            }

            matrix[h][w] = numbers.back();
            numbers.pop_back();
        }

        for (int i = 0; i < 9; i++)
        {
            std::cout << matrix[h][i];
        }
        std::cout << std::endl;

        manager.refill(&numbers);
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    return matrix;
}