#pragma once
#include <vector>


inline std::vector<std::vector<unsigned short>> tileMap =
{
	{0, 0, 0,      0, 0, 0,      0, 0, 0},
	{0, 0, 0,      0, 0, 0,      0, 0, 0},
	{0, 0, 0,      0, 0, 0,      0, 0, 0},

	{0, 0, 0,      0, 0, 0,      0, 0, 0},
	{0, 0, 0,      0, 0, 0,      0, 0, 0},
	{0, 0, 0,      0, 0, 0,      0, 0, 0},

	{0, 0, 0,      0, 0, 0,      0, 0, 0},
	{0, 0, 0,      0, 0, 0,      0, 0, 0},
	{0, 0, 0,      0, 0, 0,      0, 0, 0}

};

inline std::vector<std::vector<unsigned short>> tileMapSolution =
{
	{0, 0, 0,      0, 0, 0,      0, 0, 0},
	{0, 0, 0,      0, 0, 0,      0, 0, 0},
	{0, 0, 0,      0, 0, 0,      0, 0, 0},

	{0, 0, 0,      0, 0, 0,      0, 0, 0},
	{0, 0, 0,      0, 0, 0,      0, 0, 0},
	{0, 0, 0,      0, 0, 0,      0, 0, 0},

	{0, 0, 0,      0, 0, 0,      0, 0, 0},
	{0, 0, 0,      0, 0, 0,      0, 0, 0},
	{0, 0, 0,      0, 0, 0,      0, 0, 0}


};
constexpr unsigned short tileHeight = 103; // or 104
constexpr unsigned short tileWidth = 103; // or 104
constexpr unsigned short startUpPos = 29; // or 29

constexpr unsigned char Row = 9;
constexpr unsigned char Col = 9;

constexpr unsigned short GridHeight = 1024;
constexpr unsigned short GridWidth = 1024;

constexpr unsigned char small_Gap = 4; // or 4
constexpr unsigned char big_Gap = 8; // or 8

