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
        White = 37,
        Yellow = 33,
        Red = 91,
    };
}
