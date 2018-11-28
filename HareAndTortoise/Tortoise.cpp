#include "Tortoise.h"
#include <fstream>
#include "console.h"

Tortoise::Tortoise() 
{

}


Tortoise::~Tortoise() 
{

}

//scan the text file
void Tortoise::initSettings() {
	ifstream file;								//create a variable used to input from a text file
	int cumulativeProbability = 0;				//variable used to add the probability
	int prob;									//variable used to store the probability
	file.open("tortoise.txt");					//open the already existing tortoise.txt file

	//check if the file is open
	if (!file)	
	{							
		cout << "Error while oppening the file!" << endl;			//if not, display error message
		exit(1);													//and end program
	}

	int index = 0;			//index represents the text line
	//while loop to read the text file 
	while (!file.eof()) 
	{
		file >> possibleMoves[index].moveName;		//get the first string as moveName (stops at space)
		file >> prob;								//get the first int as probability
		cumulativeProbability += prob;				//add the probability each line
		possibleMoves[index].probability = cumulativeProbability;		//store cumulativeProbability as probability
		file >> possibleMoves[index].actualMoveTaken;					//get last integer as actualMoveTaken
		index++;				//go to the next line
	}
	setLen = index;				//set file lenght to number of lines
	file.close();				//closefile to avoid memory leaks
}

//move the tortoise
void Tortoise::move()
{
	int pick = rand() % 100;			//generate a number between 0 and 99
	int indexOfPicked;

	//check each line of text
	for (int i = 0; i < setLen; i++) 
	{
		if (pick < possibleMoves[i].probability)		//if the random number is less than the line's specific probability
		{
			indexOfPicked = i;			//save the line number in a variable
			break;						//and end the loop
		}
	}

	//set the cursout position to second row and output the move name
	Console::setCursorPosition(1, 0);
	cout << "Tortoise does a " << possibleMoves[indexOfPicked].moveName << "      " << endl;

	//delete last position from map
	Console::setCursorPosition(5, position);
	cout << ".";
	//update new position
	position += possibleMoves[indexOfPicked].actualMoveTaken;

	//check if the player can move left
	if (position < 0)
	{
		position = 0;		//if not, set position to 0 (start of map)
	}
	//check if the player can move right
	if (position > 50)
	{
		position = 50;		//if not, set position to 50 (end of map)
	}

	//draw new position on map
	Console::setCursorPosition(5, position);
	cout << "T";
}
