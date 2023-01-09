
#include "Material.h"

using namespace std;

string Material::getName() {
	return name;
}

int Material::getPrice() {
	return price;
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