#pragma once
#include "Global.hpp"
#include <vector>
#include <iostream>
#include <random>


class Calculations
{
public: // check
	static bool checkCol(const std::vector<std::vector<unsigned short>>& board, const unsigned short& row, const unsigned short& col, const unsigned short& currNum);
	static bool checkRow(const std::vector<std::vector<unsigned short>>& board, const unsigned short& row, const unsigned short& col, const unsigned short& currNum);
	static bool check_3by3_grid(const std::vector<std::vector<unsigned short>>& board, const unsigned short& row, const unsigned short& col, const unsigned short& currNum);


	static bool isSafe(const std::vector<std::vector<unsigned short>>& board, const unsigned short& row, const unsigned short& col, const unsigned short& currNum);

	
	static void printBoard(const std::vector<std::vector<unsigned short>>& board);
	static void initPermanentNumbers();
	static void genNumsSolutions(std::vector <std::pair<unsigned short, unsigned short>>& savePos);
public:
	
	static unsigned int count;
	static bool solveSudoku(std::vector<std::vector<unsigned short>>& board, unsigned short row, unsigned short col);
	static bool solveSudoku(const std::vector <std::pair<unsigned short, unsigned short>>& savedPos,std::vector<std::vector<unsigned short>>& board, unsigned short row, unsigned short col);

public:
	~Calculations() = default;
	explicit Calculations();
};
