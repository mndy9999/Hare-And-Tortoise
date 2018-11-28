#pragma once
#include "settings.h"
//Player is a parent class
//its children are Tortoise and Hare

class Player 
{
	//protected variables can be accessed by children classes
protected:
	int position = 0;
	Settings possibleMoves[10];
	int setLen;
public:
	Player();
	~Player();

	//virtual function that will be overwritten in children classes
	virtual void initSettings() = 0;
	virtual void move() = 0;

	//these functions are common for both children
	int getPosition();
	bool checkIfWon();

};

