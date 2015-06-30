#include "Map.h"

enum DIR { NORTH, SOUTH, EAST, WEST };

Map::Map(){
	//Cell tiles[w][h];
	//Initialize all cells
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLS; j++){
			map[i][j] = new Cell(i, j, false); // new cell is created with walls all around
		}
	}


	bool success = generateMap();
	if (success){
		//Map is ready to play!
	}
	else{
		//Fuck....
	}
}

bool Map::generateMap(){
	//Create Bases
	try
	{
		//createBase(1, 1, map);
		//createBase(width - baseWidth, 1, map);
		//createBase(1, height - baseHeight, map);
		//createBase(width - baseWidth, height - baseHeight, map);

		std::vector<DIR> live;
		std::vector<Cell*> stack;

		//srand(time(NULL));
		int curX = rand() % width;
		int curY = rand() % height;

		stack.push_back(map[curX][curY]);

		while (stack.empty() == false){

			live.clear();

			/** Loop through and check to see which neighbors have all walls **/
			// Check West
			if (curY){
				if (map[curX][curY - 1]->getWalls() == Cell::WALL_ALL){
					live.push_back(SOUTH);
				}
			}
			// Check East
			if (curY < width - 1){
				if (map[curX][curY + 1]->getWalls() == Cell::WALL_ALL){
					live.push_back(NORTH);
				}
			}

			if (curX){
				if (map[curX - 1][curY]->getWalls() == Cell::WALL_ALL){
					live.push_back(WEST);
				}
			}

			if (curX< width - 1){
				if (map[curX + 1][curY]->getWalls() == Cell::WALL_ALL){
					live.push_back(EAST);
				}
			}

			if (live.empty() == false){
				map[curX][curY]->setVisited(true);
				switch (live[rand() % live.size()]){
				case 0:
					map[curX][curY]->removeWall(Cell::WALL_NORTH);
					map[curX][--curY]->removeWall(Cell::WALL_SOUTH);
					break;
				case 1:
					map[curX][curY]->removeWall(Cell::WALL_SOUTH);
					map[curX][++curY]->removeWall(Cell::WALL_NORTH);
					break;
				case 2:
					map[curX][curY]->removeWall(Cell::WALL_EAST);
					map[--curX][curY]->removeWall(Cell::WALL_WEST);
					break;
				case 3:
					map[curX][curY]->removeWall(Cell::WALL_WEST);
					map[++curX][curY]->removeWall(Cell::WALL_EAST);
					break;
				}
				stack.push_back(map[curX][curY]);
			}
			else{
				stack.pop_back();
				if (stack.empty() == false){
					curX = stack[0]->getRow();
					curY = stack[0]->getColumn();
				}
			}
		}


	}
	catch (int e){ throw "Error code Number: " + e; }

	return true;

}

void Map::drawMap(){
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			map[i][j]->draw();
}

void Map::drawTestMap(){
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			std::cout << map[i][j];
		}
	}
}

