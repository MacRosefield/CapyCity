#pragma once

#include <iostream>
#include <map>
#include "Material.h"

class MaterialDB {
public:
	static std::map<Material, int> materialUsed;
	static void addMaterial(Material, int);
	static void removeMaterial(Material, int);
	int getAmount(Material);
};

