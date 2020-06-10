#pragma once
namespace GlobalConstants
{
    const int SudokuWidth = 9;
    const int SudokuHeight = 9;

    const enum class Difficulty
    {
        Expert = 5,
        Hard = 4,
        Normal = 3,
        Easy = 2,
    };

    const enum class Colors
    {
        Green = 32,
        Yellow = 33,
        White = 37,
        Red = 91,
    };
}
