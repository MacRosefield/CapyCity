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

int Building::getPower() {
	return power;
}





Leer::Leer() {
	name = "Leer";
	label = " ";
	price = 0;
	power = 0;
}


Solarpanel::Solarpanel() {

	name = "Solarpanel";
	label = "S";
	price = solarBasePrice;
	power = solBasePower;


	MaterialDB::addMaterial(Metall(), 1);
	MaterialDB::addMaterial(Kunststoff(), 1);

}

Wasserkraft::Wasserkraft() {

	name = "Wasserkraft";
	label = "A";
	price = wasserBasePrice;
	power = wasBasePower;


	MaterialDB::addMaterial(Holz(), 2);


}

Windkraft::Windkraft() {

	name = "Windkraft";
	label = "W";
	price = windBasePrice;
	power = winBasePower;


	MaterialDB::addMaterial(Metall(), 1);
	MaterialDB::addMaterial(Holz(), 1);
}

