#pragma once
#include "Player.h"

class Tortoise : public Player {
public:
	Tortoise();
	~Tortoise();

	void initSettings();		//scan the text file and initilize settings
	void move();				//move character
};

