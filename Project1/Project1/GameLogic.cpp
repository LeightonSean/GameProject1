#include "GameLogic.h"

GameLogic::GameLogic(){
	Start();
}

void GameLogic::Start(){
	gameState = GameLogic::UNINITIALIZED;
	
	while (!IsExiting()){

		try{
			switch (gameState){
			case GameLogic::UNINITIALIZED:
				Initialize();
				nextStates.push_back(GameLogic::PLAYING);
				break;
			case GameLogic::PLAYING:
				GameLoop();
				break;
			case GameLogic::SHOWING_MENU:
				break;
			case GameLogic::SHOWING_SPLASH:
				break;
			case GameLogic::EXITING:
				nextStates.push_back(GameLogic::EXITING);
				break;
			case GameLogic::PAUSED:
				break;
			default:
				throw new exception("Bad Game State");
			}
		}
		catch (exception e){
			cout << "ERROR";
		}
		gameState = getEvent();
		nextStates.pop_back();
	}

}

bool GameLogic::IsExiting(){
	return gameState == GameLogic::EXITING;
}

void GameLogic::Initialize(){
	gameView = new GameView();
	playerBrain = new PlayerLogic();
}

void GameLogic::GameLoop(){
	char keyPressed = gameView->GetNextKeyPressed();
	switch (keyPressed){
	case 'EXIT':
		nextStates.push_back(GameState::EXITING);
		break;
	case 'NONE':
		break;
	}
	gameView->updateNPC();
	gameView->draw();
}

GameLogic::GameState GameLogic::getEvent(){
	return nextStates.back();
}