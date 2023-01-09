#include <iostream>
#include "Building.h"

string Building::getName() {
	return name;
}

string Building::getLabel() {
	return label;
}

int Building::getPrice() {
	return price;
}

vector<Material> Building::getMaterial() {
	return needs;
}


Leer::Leer() {

	name = "Leer";
	label = " ";
	price = 0;
	needs = {};
}


Solarpanel::Solarpanel() {

	name = "Solarpanel";
	label = "S";
	price = 200;
	needs = { Metall(), Kunststoff() };
}

Wasserkraft::Wasserkraft() {

	name = "Wasserkraft";
	label = "A";
	price = 100;
	needs = { Holz(), Holz() };
}

Windkraft::Windkraft() {

	name = "Windkraft";
	label = "W";
	price = 50;
	needs = { Holz(), Metall() };
}

