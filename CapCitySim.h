#pragma once

#include <string>
#include "Building.h"
#include "Blueprint.h"

extern int rows;
extern int cols;

class CapCitySim {
	// ########################## DEKLARIEREN #################

public:
	int choice1 = 0; // Menu 1 switcher
	int choice2 = 0; // Menu 2 switcher
	int choice3 = 0; // Menu 3 switcher
	int choice4 = 0;



	int i, j, n, m;
	int gebIndex;
	int buildSizeX, buildSizeY;
	int setX, setY;
	int accessible = 0;


	int soBasePrice;
	int waBasePrice;
	int wiBasePrice;

	int saveGameIndex;

	string saveGameTemp;
	string saveGame_1 = " - - - - ";
	string saveGame_2 = " - - - - ";
	string saveGame_3 = " - - - - ";
	string saveGame_4 = " - - - - ";
	string saveGame_5 = " - - - - ";


	// ########################## PROTOTYPS #####################################
	void runin();

	void menu();
	void mainMenu();

	void subMenu();
	void subMenuOption();

	void bluePrintMenu();
	void bluePrintMenuOption();

	void saveStateMenu();
	void loadStateMenu();

	void nameSaveGame();
	void loadSaveGame();

	int loadingAnimation();

	void errorScreenOut();
	void errorScreenFull();

	void build();

};