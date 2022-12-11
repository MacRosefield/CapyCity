//######################## MY HAEEEEDER BABEEEDER ######################
//
//
//	AUTOR:		MacRosefield
//	DATE:		20.11.2022
//  VERS:		00.001
//				|	|___ minor index
//				|_______ major index
// 
//######################## MY HAEEEEDER BABEEEDER ######################

#include <iostream>
#include <string>
#include <chrono>		//notwendig für load animation sleep
#include <thread>		//notwendig für load animation sleep

using namespace std;

void initialMap(int** arr, int row, int col);
void plottMap(int** arr, int row, int col);
void setzen(int** arr, int i, int j, int id, int x, int y);
void menu();
void mainMenu();
void subMenu();
void subMenuOption();
void build();
int loadingAnimation();
int proof(int** arr, int i, int j, int x, int y);
void errorScreenOut();
void errorScreenFull();



int choice1 = 0;		//Menu 1 switcher
int choice2 = 0;		//Menu 2 switcher
int** city;				// City array 2D
int i, j, n, m;
int gebIndex;
int buildSizeX, buildSizeY;
int setX, setY;
int errorState = 0;	//Hilfsvariable zum prüfen ob bauauftrag illegal

int main(void)
{
	enum gebaude
	{
		LEER,
		SOLARPANEL,
		WINDKRAFTWERK,
		WASSERKRAFTWERK
	};

	cout << "Herzlich Wilkommen im Baumaster 7000" << endl;
	cout << "Ihr Tool für den unnoetigen Landschaftsplaner" << endl;

	// Eingabe der Dimension fuer den 2D Array
	cout << "Anzahl der Zeilen: ";
	cin >> n;
	cout << endl;

	cout << "Anzahl der Spalten: ";
	cin >> m;
	cout << endl;

	if (n <= 0 || m <= 0 || n > 50 || m > 50)
	{
		cerr << "Ungueltige Dimension!" << endl;
		return -1;
	}

	// Speicherplatzreservierung notwendig, da wir hier einen dynamischen Array erstellen wollen        spalte      spalte
	// Array a  double * bestimmt sozusagen die Anzahl der Zeilen                               row ||  a[0]        a[0]    a[0]    a[0]
	// Innerhalb der Zeilen wird jeweils ein Array mit "m" Spalten erzeugt                      row ||  a[0]        a[0]    a[0]    a[0]
	city = new int* [n];
	for (i = 0; i < n; i++)
		city[i] = new int[m];

	initialMap(city, n, m);

	menu();

	//########################################### SPEICHER FREIGEBEN #################################################

	for (i = 0; i < n; i++)
		delete[] city[i];
	delete[] city;

	return 0;
}

void initialMap(int** arr, int row, int col)
{
	// Fuellen die Matrix wieder mit 0 auf
	int v = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = v;
		}
	}
}

void plottMap(int** arr, int row, int col)
{
	// Ausgabe der Matrix auf der Konsole
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "a[" << arr[i][j] << "]";
		}
		cout << endl;
	}
	cout << "Energie niveau = 0" << endl;
}

void menu() {

	do {
		choice1 = 0;
		mainMenu();


		switch (choice1) {
		case 1:
			cout << "Option [1] wurde ausgewählt!" << endl;
			cout << "BAUPLAN WIRD GELADEN" << endl;
			loadingAnimation();

			plottMap(city, n, m);

			system("pause");

			subMenuOption();

			break;

		case 2: cout << "Option [2] wurde ausgewählt!" << endl;
			cout << "Baumenü wird geladen" << endl;
			loadingAnimation();

			cout << "Wilkommen im Baumodus - dem Kernfeature vom Bauplaner 7000" << endl;
			cout << "Bitte geben Sie Gebäudetyp an, den Sie platzieren wollen" << endl;
			cout << "1 = SOLAR, 2 = WINDKRAFT, 3 = WASSERKRAFT" << endl;

			build();

			break;

		case 3: cout << "Option [3] wurde ausgewählt!" << endl;
			break;
		case 4: cout << "Option [4] wurde ausgewählt!" << endl;
			break;
		case 5:
			cout << "Programm wird beendet!" << endl;
			break;
		default: break;
		}
	} while (choice1 > 5);


}

void mainMenu()
{
	cout << "========   MAIN MENU   ============" << endl;
	cout << " Bauplan anzeigen   - - - -  [1]   " << endl;
	cout << " Baumodus starten   - - - -  [2]   " << endl;
	cout << " Option 3           - - - -  [3]   " << endl;
	cout << " Option 4           - - - -  [4]   " << endl;
	cout << " ==  EXIT  ==       - - - -  [5]   " << endl;
	cout << "                                   " << endl;
	cout << "======== SELECT UR OPTION =========" << endl;
	cin >> choice1;
}

void subMenu() {
	cout << "========    SUB MENU   ============" << endl;
	cout << " ==  BACK  ==       - - - -  [1]   " << endl;
	cout << " ==  EXIT  ==       - - - -  [2]   " << endl;
	cout << "======== SELECT UR OPTION =========" << endl;
	cin >> choice2;
}

void subMenuOption() {

	do {

		choice2 = 0;
		subMenu();

		switch (choice2) {
		case 1:
			cout << "Option [1] wurde ausgewaehlt!" << endl;
			cout << "ZURUECK" << endl;
			loadingAnimation();



			system("pause");

			menu();


			break;

		case 2: cout << "Option [2] wurde ausgewaehlt!" << endl;
			cout << "PROGRAMM WIRD BEENDET" << endl;
			cout << "VIELEN DANK DAS SIE MIT DEM BAUMASTER 7000 GEARBEITET HABEN" << endl;
			loadingAnimation();
			system("exit");

			break;


		default: break;
		}
	} while (choice2 > 2);



}

int loadingAnimation()
{
	string loading = "................";
	cout << "LOADING ";
	for (int i = 0; i < size(loading); i++)
	{
		cout << loading[i];
		//this_thread::sleep_for(chrono::milliseconds(150));
	}
	cout << endl;
	return 0;
}

void errorScreenOut() {
	cout << "========     ERROR     ============" << endl;
	cout << "    AUSSERHALB DES BAUBEREICHS     " << endl;
	cout << "==== BITTE EINGABE KORRIGIEREN ====" << endl;

}

void errorScreenFull() {
	cout << "========     ERROR     ============" << endl;
	cout << "       FELD BEREITS BELEGT         " << endl;
	cout << "==== BITTE EINGABE KORRIGIEREN ====" << endl;

}


void build() {
	gebIndex = 0;
	cin >> gebIndex;

	do {
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

		loadingAnimation();

		proof(city, setX, setY, buildSizeX, buildSizeY);

		switch (errorState) {
		case 1: errorScreenOut(); break;
		case 2: errorScreenFull(); break;
		default: break;
		}

	} while (errorState > 0);

	loadingAnimation();





	setzen(city, setX, setY, gebIndex, buildSizeX, buildSizeY);

	cout << "Prozess beendet" << endl;

	subMenuOption();


}

void setzen(int** arr, int i, int j, int id, int x, int y)
{
	int row = i + y;
	int col = j + x;
	// Eingabe der Matrixelemente
	// Hier besteht die Möglichkeit jeden einzelnen Wert der Matrix zu bestimmen.
	for (int o = i; o < row; o++) {
		for (int p = j; p < col; p++) {

			arr[o][p] = id;

		}

	}
}

int proof(int** arr, int i, int j, int x, int y) {

	int row = i + y;
	int col = j + x;

	errorState = 0;

	if (row > n || col > m) {
		errorState = 1;
	}
	else {
		for (int o = i; o < row; o++) {
			for (int p = j; p < col; p++) {

				if (arr[o][p] > 0) {
					errorState = 2;

				}

			}
		}
	}
	// Eingabe der Matrixelemente
	// Hier wird geprüft ob die felder schon bebaut sind oder wir uns ausserhlab der stadt befinden.
	/*

	}*/
	return errorState;
}