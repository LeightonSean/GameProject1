
#include <string>
#include <iostream>

class Cell{
public:
	enum WALL
	{
		WALL_NORTH = 0x0008, // 1000
		WALL_EAST = 0x0004,  // 0100
		WALL_WEST = 0x002,   // 0010
		WALL_SOUTH = 0x0001, // 0001
		WALL_ALL = 0x000F,   // 1111
		WALL_NONE = 0x0000   // 0000
	};
	Cell();
	Cell(int r, int c);
	Cell(int r, int c, int state);
	bool visited();
	void setVisited(bool v);
	int getRow();
	int getColumn();
	void removeWall(int w);
	int getWalls() const;
	void setWalls(int w);
	void setPosition(int r, int c);
	void draw();
	friend std::ostream& operator<<(std::ostream& strm, const Cell& c);
private:
	int row, col, walls = 0x000F;
	bool visit;
	void init(const int r, const int c, const int state, const bool v);

};
