/*
 *  GameProject.cp
 *  GameProject
 *
 *  Created by Sean Leighton on 6/5/15.
 *  Copyright (c) 2015 Sean Leighton. All rights reserved.
 *
 */

#include "GameProject.h"
#include "GameProjectPriv.h"

CFStringRef GameProjectUUID(void)
{
	CGameProject* theObj = new CGameProject;
	return theObj->UUID();
}

CFStringRef CGameProject::UUID()
{
	return CFSTR("0001020304050607");
}
