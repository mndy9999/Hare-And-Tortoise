#include<iostream>
#include"console.h"
#include"Tortoise.h"
#include"Hare.h"
#include<io.h>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;

int printRound(int);		//header for the round count function

int main() 
{
	srand(static_cast<int>(time(NULL)));		//seed for the random number generator

	//setting up the console looks
	Console::setColour(Console::BLACK, Console::LIGHT_AQUA);		//set text colour to black and console colour to light aqua
	Console::clear();												//clear the console so the background colour applies
	Console::setWindowTitle("The Epic Race");						//set name of the window
	Console::setWindowSize(450, 460);								//set size of window
	Console::setWindowPosition(120, 430);							//set position of window
	Console::setCursorPosition(2, 0);								//set the line for the next output

	//drawing the map
	cout << "ROUND: " << endl << endl;
	cout << "H.................................................|" << endl;
	cout << "T.................................................|" << endl;
	
	//create class type variables
	Tortoise tortoise;
	Hare hare;

	//read the text files
	tortoise.initSettings();
	hare.initSettings();
	int movesNeeded = 1;
	int round = 0;			//initialize a round counter
	while (tortoise.checkIfWon() && hare.checkIfWon())				//while checkIfWon returns true
	{
		round++;				//increasing the round counter each time the loop occurs
		printRound(round);		//printing the round number

		//move the characters and update their position on map
		tortoise.move();		
		hare.move();
		

		//check each player's position and display an appropiate message
		//set cursor position so the message appears under the map
		//make each output 34 characters long so the new message covers the last one entirely
		if (tortoise.getPosition() > hare.getPosition())
		{
			Console::setCursorPosition(7, 0);
			cout << "The tortoise is ahead!           " << endl;
		}
		else if (tortoise.getPosition() < hare.getPosition())
		{
			Console::setCursorPosition(7, 0);
			cout << "The hare is ahead!               " << endl;
		}
		else
		{
			Console::setCursorPosition(7, 0);
			cout << "The players are on the same spot!" << endl;
		}
		Sleep(500);			//pause for 0.5 seconds between each round
	}

	Console::clear();						//clear the console
	Console::setCursorPosition(14, 20);		//set cursor position so the next message will be 
											//printed in the middle of the windows

	int endPoints;							//variable that will hold the points difference between players at the end
	ofstream file;							//create variable used to output to a file
	file.open("movesCount.txt");			//open (or create) text file
	if (!tortoise.checkIfWon())				//check who won and display an appropiate message
	{
		Console::pause("The tortoise won!!");
		endPoints = tortoise.getPosition() - hare.getPosition();				//calculate points difference
		file << "The tortoise won by " << endPoints << " points!!" << endl;		//output to text file
	}
	else if (!hare.checkIfWon())
	{
		Console::pause("The hare won!!");
		endPoints = hare.getPosition() - tortoise.getPosition();				//calculate points difference
		file << "The hare won by " << endPoints << " points!!" << endl;			//output to text file
	}
	else
	{
		Console::pause("It's a tie!!");
		file << "It's a tie!!" << endl;					//output to text file
	}
	file << "Number of moves needed: " << round;		//output number of rounds to text file
	file.close();

	return 0;
}


//function that prints the round count
int printRound(int round) 
{
	Console::setCursorPosition(2, 7);
	cout << round << endl;
	return round;
}