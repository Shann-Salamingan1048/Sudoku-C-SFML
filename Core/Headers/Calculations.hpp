#pragma once
#include "Global.hpp"
#include <vector>
#include <iostream>
#include <random>
#include <unordered_map>


class Calculations
{
private: // check
	static bool checkCol(const std::vector<std::vector<unsigned short>>& board, const unsigned short& row, const unsigned short& col, const unsigned short& currNum);
	static bool checkRow(const std::vector<std::vector<unsigned short>>& board, const unsigned short& row, const unsigned short& col, const unsigned short& currNum);
	static bool check_3by3_grid(const std::vector<std::vector<unsigned short>>& board, const unsigned short& row, const unsigned short& col, const unsigned short& currNum);


	static bool isSafe(const std::vector<std::vector<unsigned short>>& board, const unsigned short& row, const unsigned short& col, const unsigned short& currNum);


	static void printBoard(const std::vector<std::vector<unsigned short>>& board);
	static void initPermanentNumbers();
public:
	
	static unsigned int count;
	static bool solveSudoku(std::vector<std::vector<unsigned short>>& board, unsigned short row, unsigned short col);

public:
	~Calculations() = default;
	explicit Calculations();
};
