#pragma once


#include <iostream>
#include "Building.h"


#include "CapCitySim.h"


static int buildPriceAll;
static int buildPriceSo;
static int buildPriceWa;
static int buildPriceWi;
static int materialPriceAll;

static int solCounter;
static int wasCounter;
static int winCounter;


class Blueprint {

public:

	int row, col, n, m;



	static void initialMap(Building** arr, int row, int col);
	static void plottMap(Building** arr, int row, int col);
	static void calcPrice(Building** arr, int row, int col);

};

