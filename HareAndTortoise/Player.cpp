#include "Player.h"



Player::Player() 
{

}


Player::~Player() 
{

}

//get position
int Player::getPosition()
{
	return position;
}
//if position is less than 50, return true
bool Player::checkIfWon()
{
	return position < 50;
 }
