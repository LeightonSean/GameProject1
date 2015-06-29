#include "PlayerLogic.h"

PlayerLogic::PlayerLogic(){
	initialize();

}

PlayerLogic::PlayerLogic(Object obj){
	person = obj;
}

void PlayerLogic::attachPerson(Object obj){
	person = obj;

}

void PlayerLogic::initialize(){
	// Initialize new command list with nothing in it, set command
	// to wait for incoming commands.
	commandList = new node();
	commandList->next = 0;
	commandList->prev = 0;
	commandList->cmd = WAIT;


}

void PlayerLogic::addCommand(commands addCmd){
	node* root = commandList;
	node* newCmd = new node;
	newCmd->cmd = addCmd;
	newCmd->next = 0;
	if (root != 0){
		while (root->next != 0)
			root = root->next;
		newCmd->prev = root;
		root->next = newCmd;

	}
	else{
		newCmd->prev = 0;
		root = newCmd;
	}

}

void PlayerLogic::insertCommand(node* root, commands addCommand){
	node* tmp = root->next;
	node *newAdd = new node();
	newAdd->cmd = addCommand;
	newAdd->prev = root;
	newAdd->next = tmp;
	root->next = newAdd;
	tmp->prev = newAdd;
}

bool PlayerLogic::checkCollision(Object obj){
	if (person == NULL)
		return false;//Error no person attached to this logic
	bool collide = true;
	//check if the person's area intersects the object's area
	for (std::vector<Object>::iterator o = person.parts.begin(); o != person.parts.end(); o++;){
		for (std::vector::iterator n = obj.parts.begin(); n != obj.parts.end(); n++;){
			if (o.Right < n.Left){ collide = false; }
			if (o.Left > n.Right){ collide = false; }
			if (o.Bottom > n.Top){ collide = false; }
			if (o.Top < n.Bottom){ collide = false; }
		}
	}

	return collide;
}

void PlayerLogic::logicLoop(){
	for (commands c in commandList){
		switch (c){
		case MOVE_ANIMATION:
			break;
		case ATTACK_ANIMATION:
			break;
		case WAIT:
			break;
		case ANIMATE:
			break;
		default:
			break;
		}



	}


}

