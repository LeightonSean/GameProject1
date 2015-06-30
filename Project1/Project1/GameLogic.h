
#include <stdlib.h>
#include <errors.h>
#include <string>
#include "GL\glew.h"
#include "GL\freeglut.h"
#include "GameView.h"
#include "Map.h"
#include "PlayerLogic.h"

using namespace std;

class GameLogic{

public:
	
	GameLogic();
private:
	
	enum GameState{
		UNINITIALIZED = 2, 
		SHOWING_SPLASH = 3, 
		PAUSED = 0, 
		SHOWING_MENU = 4, 
		PLAYING = 1, 
		EXITING = -1
	};

	// Game Methods
	void Start();
	bool IsExiting();
	void GameLoop();
	void Initialize();
	GameState getEvent();
	void processNormalKeys(unsigned char key, int x, int y);
	// Game Objects
	GameView *gameView;
	PlayerLogic *playerBrain;
	// Game Variables	
	GameState gameState;
	vector<GameState> nextStates;
};