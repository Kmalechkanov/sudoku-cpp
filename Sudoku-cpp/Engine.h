#pragma once

#include <vector>

class Engine
{
private:
	std::vector<std::vector<int>> matrix;
	std::vector<std::vector<int>> initialMatrix;
	std::vector<std::vector<int>> solution;
public:
	Engine(std::vector<std::vector<int>>, std::vector<std::vector<int>>, std::vector<std::vector<int>>);

	void Start();
};

