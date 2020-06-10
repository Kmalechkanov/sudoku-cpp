#pragma once

#include <vector>
#include <string>

class Engine
{
private:
	std::vector<std::vector<int>> matrix;
	std::vector<std::vector<int>> initialMatrix;
	std::vector<std::vector<int>> solution;

	std::string name;
public:
	Engine(std::vector<std::vector<int>>, std::vector<std::vector<int>>, std::vector<std::vector<int>>, std::string);

	void Start();
};

