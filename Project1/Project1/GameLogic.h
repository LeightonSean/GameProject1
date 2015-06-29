#include "GameView.h"


class GameLogic{

public:
	static void Start();
private:
	static bool IsExiting();
	static void GameLoop();
	
	enum GameState{
		UNINITIALIZED, SHOWING_SPLASH, PAUSED, SHOWING_MENU, PLAYING, EXITING
	};

	static GameState getEvent();
	static GameView gameView;


};