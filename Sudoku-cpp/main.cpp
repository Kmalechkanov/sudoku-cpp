#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "generator.h"
#include "manager.h"
#include "globalconstants.h"
#include "menu.h"

int main()
{
    Menu menu;

    menu.Main();

   /* Generator gen;
    Manager manager;
    
    int seed = 4234123;

    std::string seedString = std::to_string(seed);
    std::replace(seedString.begin(), seedString.end(), '0', '1');

    std::vector<std::vector<int>> sudokuMatrix = gen.generate(seed);

    for (int h = 0; h < GlobalConstants::SudokuHeight; h++)
    {
        for (int w = 0; w < GlobalConstants::SudokuWidth; w++)
        {
            std::cout << sudokuMatrix[h][w];
        }
        std::cout << std::endl;
    }

    manager.saveSolution(sudokuMatrix, seedString);
    manager.makeSudoku(sudokuMatrix, seedString, 3, 123456789);

    manager.getAllSolutions();

    std::cout << std::endl;*/
}