#include <stdlib.h>
#include "GL\glew.h"
#include "GL\freeglut.h"
#include "Map.h"

using namespace std;
class GameView{

public:
	char GetNextKeyPressed();
	void updateNPC();
	void draw();
	GameView();
private:

	void processNormalKeys(unsigned char key, int x, int y);
	Map *gameMap;
	vector<char>keysPressed;
};