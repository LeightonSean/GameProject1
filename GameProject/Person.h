//
//  Person.h
//  GameProject
//
//  Created by Sean Leighton on 6/5/15.
//  Copyright (c) 2015 Sean Leighton. All rights reserved.
//

#ifndef __GameProject__Person__
#define __GameProject__Person__

#include <stdio.h>
//#include <OpenCL/OpenCL.h>
//#include <OpenGL/OpenGL.h>
//#include "GL\glut.h"
#include "GL\glew.h"

#include "GL\freeglut.h"

#include "Item.h"
#include <string>
using namespace std;

class Person{
    
public:
    virtual void movePlayer(float, float);
    virtual void draw();
    virtual void addItem(Item*);
    
    Person();
    void setName(string);
    float getMovementSpeed();
    float getAttackDamage();
    float getHealth();
private:
    float attackDamage = 0.0;
    float movementSpeed = 0.0;
    float health = 0.0;
    string name = "";
    Item *currentItem;
};


#endif /* defined(__GameProject__Person__) */
