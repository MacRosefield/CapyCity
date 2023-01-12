
#include "Material.h"
#include "MaterialDB.h"

using namespace std;

string Material::getName() {
	return name;
}

int Material::getPrice() {
	return price;
}

bool operator<(const Material& lhs, const Material& rhs) {

	// Code to compare lhs and rhs and return true if lhs < rhs 
	if (lhs.name < rhs.name)
		return true;
	else if (lhs.name == rhs.name)
		return (lhs.price < rhs.price);
	else
		return false;
}



Holz::Holz() {
	name = "Holz";
	price = 10;
}

Metall::Metall() {
	name = "Metall";
	price = 20;
}

Kunststoff::Kunststoff() {
	name = "Kunststoff";
	price = 30;
}