#include "Cell.h"
#include <stdlib.h>
#include <vector>
#include <time.h> 
#include <iostream>
class Map{

public:
	Map();
	void drawMap();
	void drawTestMap();
private:
	static const int ROWS = 50;
	static const int COLS = 50;
	static const int BASE_H = 10;
	static const int BASE_W = 10;
	int width, height, baseWidth, baseHeight;
	bool checkPathToBase(int sBase, int eBase); // 1, 2, 3, 4 represent the 4 corners of the map
	void openUpMap(); // removes random cell walls to make the map more open
	void placeMonsters(); // adds monsters to random cells
	Cell *map[ROWS][COLS]; // Cells are each tile of the map
	void createBase(int xStart, int yStart, Cell* tiles); // starting upper right hand corner of base
	bool generateMap();
	
};