
#include <iostream>
#include <string>
#include <limits> // notwendig für die Abfrage console input
#include <chrono> // notwendig für load animation sleep
#include <thread> // notwendig für load animation sleep
#include <typeinfo>

#include "CapCitySim.h"
#include "Building.h"
#include "Material.h"
#include "MaterialDB.h"
#include "Blueprint.h"


using namespace std;

// ############################ KONSTRUKTOR #################################
int rows = 0;
int cols = 0;

Blueprint singleMap = Blueprint();
Blueprint allMaps = Blueprint(0);

// ############################ DEKLARIEREN #################################

void CapCitySim::runin() {


	cout << "Herzlich Wilkommen im Baumaster 7000" << endl;
	cout << "Ihr Tool fuer die unnoetige Landschaftsplanung" << endl;

	// Eingabe der Dimension fuer den 2D Array

	do
	{
		cout << "Anzahl der Zeilen eingeben: " << endl;
		if (cin >> n && n > 0 && n < 41)// Abfrage ob cin was in die konsole bekommt
		{
			rows = n;
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bitte nur ganze Zahlen eingeben: [1 - 40]" << endl;

	} while (true);
	do
	{
		cout << "Anzahl der Spalten eingeben: " << endl;
		if (cin >> m && m > 0 && m < 41)
		{
			cols = m;
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bitte nur ganze Zahlen eingeben: [1 - 40]" << endl;
		// loadingAnimation();
	} while (true);

	// Speicherplatzreservierung notwendig, da wir hier einen dynamischen Array erstellen wollen        spalte    spalte
	// Array a  double * bestimmt sozusagen die Anzahl der Zeilen                               row ||  [0]        [0]    [0]   [0]
	// Innerhalb der Zeilen wird jeweils ein Array mit "m" Spalten erzeugt                      row ||  [0]        [0]    [0]   [0]

	singleMap.createCity();
	singleMap.initialMap();


	/*allMaps.saveCity(singleMap.city);*/

	CapCitySim::menu();

	// ########################################### SPEICHER FREIGEBEN #################################################

	singleMap.deleteCity();

}


void CapCitySim::menu()
{

	do
	{
		choice1 = 0;
		mainMenu();

		switch (choice1)
		{
		case 1:
			cout << "Option [1] wurde ausgewählt!" << endl;
			cout << "BAUPLAN WIRD GELADEN" << endl;
			loadingAnimation();

			singleMap.plottMap(singleMap.city);

			subMenuOption();

			break;

		case 2:
			cout << "Option [2] wurde ausgewählt!" << endl;
			cout << "Baumenü wird geladen" << endl;
			loadingAnimation();


			build();

			break;

		case 3:
			cout << "Option [3] wurde ausgewählt!" << endl;
			cout << "Abriss sequenz gestartet" << endl;


			singleMap.loeschen();
			menu();

			break;
		case 4:
			cout << "Option [4] wurde ausgewählt!" << endl;
			cout << "Blueprint menue wird aufgerufen " << endl;
			bluePrintMenuOption();

			break;
		case 5:
			cout << "Option [5] wurde ausgewählt!" << endl;
			cout << "Kennzahl der aktuellen Map: " << endl;
			cout << singleMap.calcCoefficientMap(singleMap.city) << endl;
			menu();
			break;
		case 6:
			cout << "Programm wird beendet!" << endl;
			break;
		default:
			break;
		}
	} while (choice1 > 6);
}
void CapCitySim::mainMenu()
{
	cout << "========   MAIN MENU   ============" << endl;
	cout << " Bauplan anzeigen   - - - -  [1]   " << endl;
	cout << " Baumodus starten   - - - -  [2]   " << endl;
	cout << " Bauplatz freigeben - - - -  [3]   " << endl;
	cout << " Bauplan verwalten  - - - -  [4]   " << endl;
	cout << " Kennzahl ausgeben  - - - -  [5]   " << endl;
	cout << " ==  EXIT  ==       - - - -  [6]   " << endl;
	cout << "                                   " << endl;
	cout << "======== SELECT UR OPTION =========" << endl;
	cin >> choice1;
}

void CapCitySim::subMenu()
{
	cout << "========    SUB MENU   ============" << endl;
	cout << " ==  BACK  ==       - - - -  [1]   " << endl;
	cout << " ==  EXIT  ==       - - - -  [2]   " << endl;
	cout << "======== SELECT UR OPTION =========" << endl;
	cin >> choice2;
}
void CapCitySim::subMenuOption()
{
	do
	{
		choice2 = 0;
		subMenu();
		switch (choice2)
		{
		case 1:
			cout << "Option [1] wurde ausgewaehlt!" << endl;
			cout << "ZURUECK" << endl;
			//loadingAnimation();
			menu();
			break;
		case 2:
			cout << "Option [2] wurde ausgewaehlt!" << endl;
			cout << "PROGRAMM WIRD BEENDET" << endl;
			cout << "VIELEN DANK DAS SIE MIT DEM BAUMASTER 7000 GEARBEITET HABEN" << endl;
			//loadingAnimation();
			system("exit");
			break;
		default:
			break;
		}
	} while (choice2 > 2);
}

void CapCitySim::bluePrintMenu() {

	cout << "======  BLUEPRINT MENU   ==========" << endl;
	cout << " ==  MAP speichern  - - - -  [1]   " << endl;
	cout << " ==  MAP laden      - - - -  [2]   " << endl;
	cout << " ==  NEUE MAP anlegen    - - [3]   " << endl;
	cout << " ==  MAP vergleichen  - - -  [4]   " << endl;
	cout << " ---  PLOTT SORTED MAPS - -  [5]   " << endl;
	cout << " ==  ZURUECK                 [6]   " << endl;
	cout << "======== SELECT UR OPTION =========" << endl;
	cin >> choice3;
}

void CapCitySim::bluePrintMenuOption() {
	do
	{
		choice3 = 0;
		bluePrintMenu();
		switch (choice3)
		{
		case 1:
			cout << "Option [1] wurde ausgewaehlt!" << endl;

			nameSaveGame();

			menu();
			break;
		case 2:
			cout << "Option [2] wurde ausgewaehlt!" << endl;

			loadSaveGame();

			menu();
			break;

		case 3:
			cout << "Option [3] wurde ausgewaehlt!" << endl;
			cout << "Neue Map erstellt" << endl;
			singleMap.initialMap();
			menu();
			break;

		case 4:
			cout << "Option [4] wurde ausgewaehlt!" << endl;
			cout << "wird noch eingefügt" << endl;

			menu();
			break;

		case 5:
			cout << "Option [5] wurde ausgewaehlt!" << endl;
			cout << "wird noch eingefügt" << endl;
			allMaps.sortedMapOutput();

			break;

		case 6:
			cout << "Option [6] wurde ausgewaehlt!" << endl;
			loadingAnimation();

			menu();
			break;

		default:
			break;
		}
	} while (choice3 > 7);
}


void CapCitySim::saveStateMenu() {

	cout << "=========  SAVE MENU   ===========" << endl;
	cout << " 1.  " << saveGame_1 << "[1]" << endl;
	cout << " 2.  " << saveGame_2 << "[2]" << endl;
	cout << " 3.  " << saveGame_3 << "[3]" << endl;
	cout << " 4.  " << saveGame_4 << "[4]" << endl;
	cout << " 5.  " << saveGame_5 << "[5]" << endl;
	cout << " ==  ZURUECK                 [6]   " << endl;
	cout << "======== SELECT UR OPTION =========" << endl;


	do
	{

		if (cin >> choice4 && choice4 > 0 && choice4 < 7)		// Abfrage ob cin was in die konsole bekommt
			break;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bitte nur ganze Zahlen eingeben: [1 - 6]" << endl;

	} while (true);
}

void CapCitySim::loadStateMenu() {

	cout << "=========  LOAD MENU   ===========" << endl;
	cout << " 1.  " << saveGame_1 << "[1]" << endl;
	cout << " 2.  " << saveGame_2 << "[2]" << endl;
	cout << " 3.  " << saveGame_3 << "[3]" << endl;
	cout << " 4.  " << saveGame_4 << "[4]" << endl;
	cout << " 5.  " << saveGame_5 << "[5]" << endl;
	cout << "                            " << endl;
	cout << " ==  ZURUECK             [6]" << endl;
	cout << "======== SELECT UR OPTION =========" << endl;


	do
	{

		if (cin >> choice4 && choice4 > 0 && choice4 < 8)		// Abfrage ob cin was in die konsole bekommt
			break;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bitte nur ganze Zahlen eingeben: [1 - 7]" << endl;

	} while (true);
}

void CapCitySim::nameSaveGame() {

	do
	{
		choice4 = 0;
		saveStateMenu();

		cout << "Bitte Name fuer Speicherstand eingeben:" << endl;
		cin >> saveGameTemp;

		//loadingAnimation();

		switch (choice4)
		{
		case 1:
			saveGame_1 = saveGameTemp;
			allMaps.saveCity(singleMap.city, choice4 - 1, n, m);
			break;
		case 2:
			saveGame_2 = saveGameTemp;
			allMaps.saveCity(singleMap.city, choice4 - 1, n, m);
			break;
		case 3:
			saveGame_3 = saveGameTemp;
			allMaps.saveCity(singleMap.city, choice4 - 1, n, m);
			break;
		case 4:
			saveGame_4 = saveGameTemp;
			allMaps.saveCity(singleMap.city, choice4 - 1, n, m);
			break;
		case 5:
			saveGame_5 = saveGameTemp;
			allMaps.saveCity(singleMap.city, choice4 - 1, n, m);
			break;
		default:
			break;
		}

	} while (choice4 > 5);



}

void CapCitySim::loadSaveGame() {

	do
	{
		choice4 = 0;
		loadStateMenu();




		switch (choice4)
		{
		case 1:

			allMaps.loadCity(singleMap.city, choice4 - 1, n, m);
			break;
		case 2:

			allMaps.loadCity(singleMap.city, choice4 - 1, n, m);
			break;
		case 3:

			allMaps.loadCity(singleMap.city, choice4 - 1, n, m);
			break;
		case 4:

			allMaps.loadCity(singleMap.city, choice4 - 1, n, m);
			break;
		case 5:

			allMaps.loadCity(singleMap.city, choice4 - 1, n, m);
			break;
		case 6:

			menu();
			break;

		default:
			break;
		}

	} while (choice4 > 6);

	loadingAnimation();


}

int CapCitySim::loadingAnimation()
{
	string loading = "................";
	cout << "LOADING ";
	for (int i = 0; i < size(loading); i++)
	{
		cout << loading[i];
		this_thread::sleep_for(chrono::milliseconds(150));
	}
	cout << endl;
	return 0;
}

void CapCitySim::errorScreenOut()
{
	cout << "========     ERROR     ============" << endl;
	cout << "    AUSSERHALB DES BAUBEREICHS     " << endl;
	cout << "==== BITTE EINGABE KORRIGIEREN ====" << endl;
}
void CapCitySim::errorScreenFull()
{
	cout << "========     ERROR     ============" << endl;
	cout << "       FELD BEREITS BELEGT         " << endl;
	cout << "==== BITTE EINGABE KORRIGIEREN ====" << endl;
}

void CapCitySim::build()
{
	gebIndex = 0;

	do
	{
		cout << "Wilkommen im Baumodus - dem Kernfeature vom Bauplaner 7000" << endl;
		cout << "Bitte geben Sie Gebäudetyp an, den Sie platzieren wollen" << endl;
		cout << "1 = SOLAR, 2 = WINDKRAFT, 3 = WASSERKRAFT" << endl;

		if (cin >> gebIndex && gebIndex > 0 && gebIndex < 4)		// Abfrage ob cin was in die konsole bekommt
			break;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bitte auf Auswahl achten: [1 - 3]" << endl;

	} while (true);


	do
	{
		accessible = 0;
		cout << "Bitte gib noch die breite des zu planenden Gebaeudes ein." << endl;

		cin >> buildSizeX;
		cout << "Nun die Hoehe." << endl;
		cin >> buildSizeY;
		cout << "Nun fehlt nicht mehr viel" << endl;
		cout << "Lediglich die Position des Gebaeudes" << endl;
		cout << endl;
		cout << "Bitte gib zuerst die X Koordinate des linken oberen Eckpunktes ein" << endl;
		cin >> setX;
		cout << "Und nun die Y Koordinate" << endl;
		cin >> setY;
		cout << "DANKE, Deine Eingaben werden nun verarbeitet" << endl;
		//loadingAnimation();
		accessible = singleMap.proof(singleMap.city, setX, setY, buildSizeX, buildSizeY);
		switch (accessible)
		{
		case 1:
			errorScreenOut();
			break;
		case 2:
			errorScreenFull();
			break;
		default:
			break;
		}

	} while (accessible > 0);



	singleMap.setzen(setX, setY, gebIndex, buildSizeX, buildSizeY);

	cout << "Prozess beendet" << endl;

	subMenuOption();
}

