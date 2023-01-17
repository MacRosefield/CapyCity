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
	const int MAX_VERSIONS = 10;
	const int MAX_ROWS = 40;
	const int MAX_COLS = 40;

	int versionIndex;
	int rows;
	int cols;

	int row, col, n, m, i, j, k, index;

	int cityPower;
	double coefficient;

	Building** city;
	// member variable that holds the different city versions
	Building*** cityVersions;


	Blueprint();
	Blueprint(int index);

	void createCity(int n, int m);
	void deleteCity(int n, int m);

	void initialMap(int row, int col);
	void plottMap(int row, int col);
	void calcPrice(Building** arr, int row, int col);

	void saveCity(Building** city, int rows, int cols);
	void loadCity(Building** city, int index, int rows, int cols);
	//void compareCity();
	void calcCoefficientMap(Building** city, int rows, int cols);
};

