#include "GameLogic.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int main(int argc, char** argv){
	GameLogic *game = new GameLogic();
	return 0;
}