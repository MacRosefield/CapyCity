#pragma once

#include <string>
#include "Building.h"
#include "Blueprint.h"

class CapCitySim {
	// ########################## DEKLARIEREN #################
public:

	int choice1 = 0; // Menu 1 switcher
	int choice2 = 0; // Menu 2 switcher
	int choice3 = 0; // Menu 3 switcher

	int i, j, n, m;
	int gebIndex;
	int buildSizeX, buildSizeY;
	int setX, setY;
	int errorState = 0;


	int soBasePrice;
	int waBasePrice;
	int wiBasePrice;



	// ########################## PROTOTYPS #####################################
	void runin();

	void menu();
	void mainMenu();

	void subMenu();
	void subMenuOption();

	void bluePrintMenu();
	void bluePrintMenuOption();

	int proof(Building** arr, int i, int j, int x, int y);

	void loeschen();



	int loadingAnimation();


	void errorScreenOut();
	void errorScreenFull();


	void setzen(int i, int j, int id, int x, int y);
	void build();




};