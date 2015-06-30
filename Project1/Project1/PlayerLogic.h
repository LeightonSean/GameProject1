#include "Object.h"
#include <stdlib.h>

class PlayerLogic{


public:


	enum commands{
		MOVE_ANIMATION,
		ATTACK_ANIMATION,
		WAIT,
		DRAW,
		ANIMATE
	}cmds;

	struct node{
		node* next;
		node* prev;
		int cmd;
	};

	void addCommand(commands c);
	void attachPerson(Object obj);
	void logicLoop();
	PlayerLogic();
	PlayerLogic(Object obj);
private:

	node* commandList;
	//Object person;
	float xMovementSpeed = 0.0;
	float yMovementSpeed = 0.0;
	float zMovementSpeed = 0.0;
	void initialize();
	bool draw();
	void animate(commands c);
	bool movePlayer(float x, float y, float z);
	bool checkCollision(Object obj);
	void insertCommand(node* root, commands cmd);
};