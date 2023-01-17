
#include <iostream>
#include <string>
#include <limits> // notwendig f�r die Abfrage console input
#include <chrono> // notwendig f�r load animation sleep
#include <thread> // notwendig f�r load animation sleep
#include <typeinfo>

#include "CapCitySim.h"
#include "Building.h"
#include "Material.h"
#include "MaterialDB.h"
//#include "Blueprint.h"


using namespace std;

// ############################ DEKLARIEREN #################################



Blueprint singleMap = Blueprint();
Blueprint allMaps = Blueprint(0);

void CapCitySim::runin() {


	cout << "Herzlich Wilkommen im Baumaster 7000" << endl;
	cout << "Ihr Tool fuer die unnoetige Landschaftsplanung" << endl;

	// Eingabe der Dimension fuer den 2D Array

	do
	{
		cout << "Anzahl der Zeilen eingeben: " << endl;
		if (cin >> n && n > 0 && n < 41)		// Abfrage ob cin was in die konsole bekommt
			break;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bitte nur ganze Zahlen eingeben: [1 - 40]" << endl;

	} while (true);

	do
	{
		cout << "Anzahl der Spalten eingeben: " << endl;
		if (cin >> m && m > 0 && m < 41)
			break;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bitte nur ganze Zahlen eingeben: [1 - 40]" << endl;
		// loadingAnimation();
	} while (true);

	// Speicherplatzreservierung notwendig, da wir hier einen dynamischen Array erstellen wollen        spalte    spalte
	// Array a  double * bestimmt sozusagen die Anzahl der Zeilen                               row ||  [0]        [0]    [0]   [0]
	// Innerhalb der Zeilen wird jeweils ein Array mit "m" Spalten erzeugt                      row ||  [0]        [0]    [0]   [0]

	singleMap.createCity(n, m);
	singleMap.initialMap(n, m);


	/*allMaps.saveCity(singleMap.city);*/

	CapCitySim::menu();

	// ########################################### SPEICHER FREIGEBEN #################################################

	singleMap.deleteCity(n, m);

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
			cout << "Option [1] wurde ausgew�hlt!" << endl;
			cout << "BAUPLAN WIRD GELADEN" << endl;
			loadingAnimation();

			singleMap.plottMap(n, m);

			subMenuOption();

			break;

		case 2:
			cout << "Option [2] wurde ausgew�hlt!" << endl;
			cout << "Baumen� wird geladen" << endl;
			//loadingAnimation();


			build();

			break;

		case 3:
			cout << "Option [3] wurde ausgew�hlt!" << endl;
			cout << "Abriss sequenz gestartet" << endl;
			//loadingAnimation();

			//loeschen();

			break;
		case 4:
			cout << "Option [4] wurde ausgew�hlt!" << endl;
			cout << "Blueprint menue wird aufgerufen " << endl;
			bluePrintMenuOption();

			break;
		case 5:
			cout << "Programm wird beendet!" << endl;
			break;
		default:
			break;
		}
	} while (choice1 > 5);
}
void CapCitySim::mainMenu()
{
	cout << "========   MAIN MENU   ============" << endl;
	cout << " Bauplan anzeigen   - - - -  [1]   " << endl;
	cout << " Baumodus starten   - - - -  [2]   " << endl;
	cout << " Bauplatz freigeben - - - -  [3]   " << endl;
	cout << " Bauplan verwalten  - - - -  [4]   " << endl;
	cout << " ==  EXIT  ==       - - - -  [5]   " << endl;
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

	cout << "========    SUB MENU   ============" << endl;
	cout << " ==  MAP speichern  - - - -  [1]   " << endl;
	cout << " ==  MAP laden      - - - -  [2]   " << endl;
	cout << " ==  NEUE MAP anlegen    - - [3]   " << endl;
	cout << " ==  MAP vergleichen  - - -  [4]   " << endl;
	cout << "                                   " << endl;
	cout << " ==  ZURUECK                 [5]   " << endl;
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
			cout << "MAP wird gespeichert" << endl;
			//loadingAnimation();
			allMaps.saveCity(singleMap.city, n, m);
			menu();
			break;
		case 2:
			cout << "Option [2] wurde ausgewaehlt!" << endl;
			cout << "MAP wird geladen" << endl;

			allMaps.loadCity(singleMap.city, 0, n, m);
			loadingAnimation();
			menu();
			break;

		case 3:
			cout << "Option [3] wurde ausgewaehlt!" << endl;
			cout << "Neue Map erstellt" << endl;
			singleMap.initialMap(n, m);
			menu();
			break;

		case 4:
			cout << "Option [4] wurde ausgewaehlt!" << endl;
			cout << "wird noch eingef�gt" << endl;

			menu();
			break;

		case 5:
			cout << "Option [5] wurde ausgewaehlt!" << endl;
			loadingAnimation();

			menu();
			break;

		default:
			break;
		}
	} while (choice3 > 5);
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
		cout << "Bitte geben Sie Geb�udetyp an, den Sie platzieren wollen" << endl;
		cout << "1 = SOLAR, 2 = WINDKRAFT, 3 = WASSERKRAFT" << endl;

		if (cin >> gebIndex && gebIndex > 0 && gebIndex < 4)		// Abfrage ob cin was in die konsole bekommt
			break;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bitte auf Auswahl achten: [1 - 3]" << endl;

	} while (true);


	do
	{
		errorState = 0;
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
		proof(singleMap.city, setX, setY, buildSizeX, buildSizeY);
		switch (errorState)
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

	} while (errorState > 0);

	//loadingAnimation();

	setzen(setX, setY, gebIndex, buildSizeX, buildSizeY);

	cout << "Prozess beendet" << endl;

	subMenuOption();
}


void CapCitySim::setzen(int i, int j, int id, int x, int y)
{
	int row = i + y;
	int col = j + x;
	// Eingabe der Matrixelemente
	// Hier besteht die M�glichkeit jeden einzelnen Wert der Matrix zu bestimmen.
	for (int o = i; o < row; o++)
	{
		for (int p = j; p < col; p++)
		{
			switch (id)
			{
			case 1: singleMap.city[o][p] = Solarpanel();
				break;
			case 2: singleMap.city[o][p] = Windkraft();
				break;
			case 3: singleMap.city[o][p] = Wasserkraft();
				break;
			default:
				break;
			}
		}
	}
}
void CapCitySim::loeschen()
{
	int x, y;
	cout << "Bitte X koordinate eingeben:" << endl;
	cin >> x;
	cout << "Bitte Y koordinate eingeben:" << endl;
	cin >> y;

	singleMap.city[x][y] = Leer();

	subMenuOption();
}

int CapCitySim::proof(Building** arr, int i, int j, int x, int y)
{

	int row = i + y;
	int col = j + x;

	errorState = 0;

	if (row > n || col > m)
	{
		errorState = 1;
	}
	else
	{
		for (int o = i; o < row; o++)
		{
			for (int p = j; p < col; p++)
			{

				if (arr[o][p].getName() != "Leer")
				{
					errorState = 2;
				}
			}
		}
	}
	return errorState;
}
