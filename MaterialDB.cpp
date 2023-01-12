
#include <iostream>
#include "MaterialDB.h"
#include "Material.h"



std::map<Material, int> MaterialDB::materialUsed{ {Holz(), 0},
			  {Metall(), 0},
			  {Kunststoff(), 0} };



void MaterialDB::addMaterial(Material mat, int count) {
	materialUsed[mat] += count;
}

void MaterialDB::removeMaterial(Material mat, int count) {
	materialUsed[mat] -= count;
}

int MaterialDB::getAmount(Material mat) {
	return materialUsed[mat];
}