#pragma once

#include <iostream>
#include <vector>
#include "Material.h"

using namespace std;

class Building {


public:
	string name;
	string label;
	int price;
	// Public member variables
	// Public member functions;;
	string getName();
	string getLabel();
	int getPrice();

	vector<Material> needs; // Vector to store Material objects
	vector<Material> getMaterial();
};

class Leer : public Building {


public:
	// Constructor
	Leer();

};

class Solarpanel : public Building {
public:
	// Constructor
	Solarpanel();



};

class Wasserkraft : public Building {
public:
	// Constructor
	Wasserkraft();

};

class Windkraft : public Building {
public:
	// Constructor
	Windkraft();

};
