#pragma once
#include <string>
#include <iostream>
#include "console.h"

using namespace std;

//a struct that intializes 3 variables and a function
//it will be used to store and output the information taken from the text file
struct Settings {

	string moveName;
	int probability;
	int actualMoveTaken;

	void print() {
		cout << moveName << endl;
		cout << probability << endl;
		cout << actualMoveTaken << endl;
	}
};