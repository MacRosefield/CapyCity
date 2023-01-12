#include <iostream>
#include "Building.h"
#include "MaterialDB.h"





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
	this->price = solarBasePrice;
	needs = { Metall(), Kunststoff() };

	MaterialDB::addMaterial(Metall(), 1);
	MaterialDB::addMaterial(Kunststoff(), 1);
	
}

Wasserkraft::Wasserkraft() {

	name = "Wasserkraft";
	label = "A";
	this->price = wasserBasePrice;
	needs = { Holz(), Holz() };
	
	MaterialDB::addMaterial(Holz(), 2);
	

}

Windkraft::Windkraft() {

	name = "Windkraft";
	label = "W";
	this->price = windBasePrice;
	needs = { Holz(), Metall() };

	MaterialDB::addMaterial(Metall(), 1);
	MaterialDB::addMaterial(Holz(), 1);
}

