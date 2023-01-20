#include "Blueprint.h"
//#include "Building.h"

//#include "CapCitySim.h"
#include "MaterialDB.h"

Blueprint::Blueprint() {}

Blueprint::Blueprint(int index) {

	//this->versionIndex = index;

	cityVersions = new Building * *[MAX_VERSIONS];
	for (int i = 0; i < MAX_VERSIONS; i++) {
		cityVersions[i] = new Building * [MAX_ROWS];
		for (int j = 0; j < MAX_COLS; j++)
			cityVersions[i][j] = new Building[MAX_COLS];
	}
}

void Blueprint::createCity() {
	city = new Building * [rows];
	for (int i = 0; i < rows; i++)
		city[i] = new Building[cols];

}

void Blueprint::deleteCity() {
	for (int i = 0; i < rows; i++)
		delete[] city[i];
	delete[] city;
}

void Blueprint::initialMap()
{
	// Clear Matrix and fill up with empty buildings
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			city[i][j] = Leer();

		}
	}
}

void Blueprint::plottMap(Building** city)
{
	// Ausgabe der Matrix auf der Konsole
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			string type = city[i][j].getName();

			if (type == "Leer") {
				cout << "[    ]";
			}
			else if (type == "Solarpanel") {
				cout << "[ SO ]";
			}
			else if (type == "Wasserkraft") {
				cout << "[ WA ]";
			}
			else if (type == "Windkraft") {
				cout << "[ WI ]";
			}
		}
		cout << endl;
	}



	calcPrice(city);


	cout << "================   GEBAEUDE   ===================" << endl;
	cout << "                                   " << endl;
	cout << "     Solarpanele: " << solCounter << "x" << "     - Grundpreis: " << solarBasePrice << " - " << endl;
	cout << "     Wasserkraftwerke: " << wasCounter << "x" << "     - Grundpreis: " << wasserBasePrice << " - " << endl;
	cout << "     Windkraftwerke:  " << winCounter << "x" << "     - Grundpreis: " << windBasePrice << " - " << endl;
	cout << endl;
	cout << "================   KOSTEN   ===================" << endl;
	cout << "                                   " << endl;
	cout << "  Bauplatz:" << endl;
	cout << "         Solarpanele = " << buildPriceSo << " $" << endl;
	cout << "         Wasserkraftwerke = " << buildPriceWa << " $" << endl;
	cout << "         Windkraftwerke = " << buildPriceWi << " $" << endl;
	cout << "                                   " << endl;
	cout << "================   KOSTEN   ===================" << endl;
	cout << endl;
	cout << "  Material verbaut:" << endl;
	for (pair<Material, int> m : MaterialDB::materialUsed) {
		cout << "        " + m.first.getName() + " - Anzahl: " + to_string(m.second) << endl;
	}
	cout << endl;
	cout << "      Materialkosten gesamt = " << materialPriceAll << " $" << endl;
	cout << "      Overall kosten  = " << buildPriceAll << " $" << endl;
	cout << "      Kennzahl der Stadt = " << calcCoefficientMap(city) << endl;
	cout << "                                   " << endl;
	cout << "============== SELECT UR OPTION ===============" << endl;
}

void Blueprint::calcPrice(Building** arr) {

	buildPriceAll = 0;

	buildPriceSo = 0;
	buildPriceWa = 0;
	buildPriceWi = 0;

	solCounter = 0;
	wasCounter = 0;
	winCounter = 0;

	materialPriceAll = 0;



	for (pair<Material, int> m : MaterialDB::materialUsed) {
		materialPriceAll += (m.first.getPrice() * m.second);

	}


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{

			buildPriceAll += arr[i][j].getPrice();

			if (arr[i][j].getName() != "Leer") {

			}

			if (arr[i][j].getName() == "Solarpanel") {


				buildPriceSo += arr[i][j].getPrice();
				solCounter++;
			}

			if (arr[i][j].getName() == "Wasserkraft") {


				buildPriceWa += arr[i][j].getPrice();
				wasCounter++;
			}

			if (arr[i][j].getName() == "Windkraft") {


				buildPriceWi += arr[i][j].getPrice();
				winCounter++;
			}

		}
	}

	buildPriceAll += materialPriceAll;
}

void Blueprint::saveCity(Building** city, int index, int rows, int global_cols) {
	if (index < MAX_VERSIONS) {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < global_cols; j++)
				cityVersions[index][i][j] = city[i][j];

	}
	saved_Maps++;
}

void Blueprint::loadCity(Building** city, int index, int rows, int cols) {
	if (index >= 0 && index < MAX_VERSIONS) {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				city[i][j] = cityVersions[index][i][j];
	}
	else {
		cout << "Kein Plan mit diesem Index vorhanden!" << endl;
	}
}

double Blueprint::calcCoefficientMap(Building** city) {

	cityPower = 0;
	coefficient = 0.0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cityPower += city[i][j].getPower();
		}
	}

	calcPrice(city);


	if (buildPriceAll == 0) {
		coefficient = 0.0;
	}
	else {

		coefficient = (double)cityPower / (double)(buildPriceAll * (rows * cols));
	}


	/*cout << coefficient << endl;*/
	return coefficient;

}

bool Blueprint::operator()(Building*** cityA, Building*** cityB) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			if (cityA[i][j]->getLabel() != cityB[i][j]->getLabel()) {
				return false;
			}
		}
	}

	return true;
}

void Blueprint::loeschen()
{
	int x, y;
	cout << "Bitte X koordinate eingeben:" << endl;
	cin >> x;
	cout << "Bitte Y koordinate eingeben:" << endl;
	cin >> y;

	city[x][y] = Leer();
}

void Blueprint::setzen(int i, int j, int id, int x, int y)
{
	int row = i + y;
	int col = j + x;
	// Eingabe der Matrixelemente
	// Hier besteht die Möglichkeit jeden einzelnen Wert der Matrix zu bestimmen.
	for (int o = i; o < row; o++)
	{
		for (int p = j; p < col; p++)
		{
			switch (id)
			{
			case 1: city[o][p] = Solarpanel();
				break;
			case 2: city[o][p] = Windkraft();
				break;
			case 3: city[o][p] = Wasserkraft();
				break;
			default:
				break;
			}
		}
	}
}

int Blueprint::proof(Building** arr, int i, int j, int x, int y)
{

	int row = i + y;
	int col = j + x;

	errorState = 0;

	if (row > rows || col > cols)
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

void Blueprint::sortedMapOutput() {

	// Fill the map with the coefficients of each city version
	for (int i = 0; i < saved_Maps; i++) {
		for (int j = 1; j < saved_Maps; j++) {




			if (calcCoefficientMap(cityVersions[i]) < calcCoefficientMap(cityVersions[j]));
			Building** temp = cityVersions[i];
			cityVersions[i] = cityVersions[j];
			cityVersions[j] = temp;
		}
	}

	for (int i = 0; i < saved_Maps; i++) {

		plottMap(cityVersions[i]);
	}
}
