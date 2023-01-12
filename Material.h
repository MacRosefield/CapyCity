#pragma once

#include <iostream>

using namespace std;


class Material {


public:
	string name;
	int price;
	// Public member variables
	// Public member functions
	string getName();
	int getPrice();

	bool operator<(const Material& rhs) const {
		if (this->name < rhs.name)
			return true;
		else if (this->name == rhs.name)
			return (this->price < rhs.price);
		else
			return false;
	};

};

class Holz : public Material {
public:
	// Constructor
	Holz();
};

class Metall : public Material {
public:
	// Constructor
	Metall();
};

class Kunststoff : public Material {
public:
	// Constructor
	Kunststoff();

};