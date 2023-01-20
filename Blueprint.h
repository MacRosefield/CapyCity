#pragma once


#include <iostream>
#include "Building.h"
#include "CapCitySim.h"
#include <string>



static int buildPriceAll;
static int buildPriceSo;
static int buildPriceWa;
static int buildPriceWi;
static int materialPriceAll;

static int saved_Maps = 0;

static int wasCounter;
static int winCounter;


class Blueprint {

public:

	map <int, double> cityVersionsCoefficients;

	const int MAX_VERSIONS = 5;
	const int MAX_ROWS = 40;
	const int MAX_COLS = 40;


	int solCounter;
	//string saveGameTemp;
	//string saveGame_1 = " - - - - ";
	//string saveGame_2 = " - - - - ";
	//string saveGame_3 = " - - - - ";
	//string saveGame_4 = " - - - - ";
	//string saveGame_5 = " - - - - ";

	int versionIndex;
	//int saveGameIndex;




	int errorState;


	int row, col, i, j, k, index;

	int cityPower;
	double coefficient;



	Building** city;
	// member variable that holds the different city versions
	Building*** cityVersions;

	Blueprint();
	Blueprint(int index);

	void createCity();
	void deleteCity();

	void initialMap();
	void plottMap(Building** city);
	void calcPrice(Building** arr);

	void saveCity(Building** city, int index, int rows, int cols);
	void loadCity(Building** city, int index, int rows, int cols);
	//void compareCity();
	double calcCoefficientMap(Building** city);
	bool operator()(Building*** cityA, Building*** cityB);

	void loeschen();
	void setzen(int i, int j, int id, int x, int y);

	int proof(Building** arr, int i, int j, int x, int y);

	void sortedMapOutput();

	/*void nameSaveGame();*/
};

