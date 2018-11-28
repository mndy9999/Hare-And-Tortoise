#pragma once
#include "Player.h"

class Hare : public Player {
private:
public:
	Hare();
	~Hare();

	void initSettings();		//scan the text file and initialise settings
	void move();				//move character
};

