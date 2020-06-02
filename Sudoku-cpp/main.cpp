#include <iostream>
#include <vector>
#include "Generator.h"
#include "GlobalConstants.h"

int main()
{
    Generator gen;
    std::vector<std::vector<int>> sudokuMatrix = gen.generate(123123123);

    for (int h = 0; h < GlobalConstants::SudokuHeight; h++)
    {
        for (int w = 0; w < GlobalConstants::SudokuWidth; w++)
        {
            std::cout << sudokuMatrix[h][w];
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}