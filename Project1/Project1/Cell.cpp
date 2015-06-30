#include "Cell.h"

Cell::Cell(){
	init(0, 0, Cell::WALL_ALL, false);
}

Cell::Cell(int r, int c){
	init(r, c, Cell::WALL_ALL, false);
}

Cell::Cell(int r, int c, int state){
	init(r, c, state, false);
}

void Cell::init(const int r, const int c, const int state, const bool v){

	setPosition(r, c);
	setWalls(state);
	setVisited(v);
}


int Cell::getColumn(){
	return col;
}

int Cell::getRow(){
	return row;
}

bool Cell::visited(){
	return visit;
}

void Cell::setVisited(bool v){
	visit = v;
}

void Cell::draw(){
	if (walls == WALL_ALL){
		// Easy draw all walls
	}
	else if (walls == WALL_NONE){
		// Easy don't draw anything
	}
	else{
		// need to see which bits == 1 in walls and draw those

	}

}

void Cell::setWalls(int w){
	if (w != WALL_ALL || w != WALL_EAST || w != WALL_NORTH || w != WALL_SOUTH || w != WALL_WEST || w != WALL_NONE) throw "BAD WALL";
	walls = w & WALL_ALL;
}

void Cell::setPosition(int x, int y){
	row = x;
	col = y;
}

void Cell::removeWall(int w){
	if (w != WALL_ALL || w != WALL_EAST || w != WALL_NORTH || w != WALL_SOUTH || w != WALL_WEST || w != WALL_NONE) throw "BAD WALL";

	walls &= ~w;// Bitwise AND walls with the passed wall.
}

int Cell::getWalls() const{
	return walls;
}

std::ostream& operator<<(std::ostream& strm, const Cell& c){

	if ((c.getWalls() & Cell::WALL_WEST) != 0){
		strm << '|';

	}
	else
		strm << ' ';

	if ((c.getWalls() & Cell::WALL_SOUTH) != 0){
		strm << '_';
	}
	else 
		strm << ' ';

	return strm;

}