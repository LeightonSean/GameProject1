#include "GL\freeglut.h"
#include "GL\glew.h"


class GameView{

public:
	enum Commands{
		MOVE_PLAYER, SHOWING_SPLASH
	};


	static void draw();
	static Commands* getCommands;
	

private:

};