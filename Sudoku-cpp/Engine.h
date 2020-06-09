#pragma once

#include <vector>

class Engine
{
private:
	std::vector<std::vector<int>> matrix;
	std::vector<std::vector<int>> initialMatrix;
public:
	Engine(std::vector<std::vector<int>>, std::vector<std::vector<int>>);

	void Start();
};

