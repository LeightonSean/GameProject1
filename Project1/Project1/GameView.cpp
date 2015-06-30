#include "GameView.h"




GameView::GameView(){
	gameMap = new Map();

}

void GameView::draw(){
	// Draw Map
	gameMap->drawTestMap();
	// Draw players

	// ect..
}

void GameView::processNormalKeys(unsigned char key, int x, int y){
	if (key == 27){
		// Check Exit
		keysPressed.push_back(key);
	}


}

char GameView::GetNextKeyPressed(){
	char tmp = keysPressed.back();
	keysPressed.pop_back();
	return tmp;
}

void GameView::updateNPC(){

}