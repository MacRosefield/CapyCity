#pragma once

#include <string>
#include "Building.h"

class CapCitySim {

public:

	Building** city;
	int choice1 = 0; // Menu 1 switcher
	int choice2 = 0; // Menu 2 switcher

	int i, j, n, m;
	int gebIndex;
	int buildSizeX, buildSizeY;
	int setX, setY;
	int errorState = 0;


	int buildPriceAll;
	int buildPriceSo;
	int buildPriceWa;
	int buildPriceWi;
	int materialPriceAll;

	int solCounter;
	int wasCounter;
	int winCounter;

	int soBasePrice;
	int waBasePrice;
	int wiBasePrice;

	// ########################## PROTOTYPS #####################################
	void runin();

	void initialMap(int row, int col);
	void plottMap(int row, int col);

	void menu();
	void mainMenu();

	int proof(Building** arr, int i, int j, int x, int y);

	void loeschen();

	void subMenu();
	void subMenuOption();

	int loadingAnimation();


	void errorScreenOut();
	void errorScreenFull();


	void setzen(int i, int j, int id, int x, int y);
	void build();

	void calcPrice();



};