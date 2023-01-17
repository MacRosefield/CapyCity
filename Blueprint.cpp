#include "Blueprint.h"
#include "Building.h"

#include "CapCitySim.h"
#include "MaterialDB.h"


Blueprint::Blueprint() {}


Blueprint::Blueprint(int index) {

	this->versionIndex = index;

	cityVersions = new Building * *[MAX_VERSIONS];
	for (int i = 0; i < MAX_VERSIONS; i++) {
		cityVersions[i] = new Building * [MAX_ROWS];
		for (int j = 0; j < MAX_COLS; j++)
			cityVersions[i][j] = new Building[MAX_COLS];
	}

	//for (int j = 0; j < MAX_ROWS; j++)
	//for (int k = 0; k < MAX_COLS; k++)
	//cityVersions[i][j][k] = nullptr;

}


void Blueprint::createCity(int n, int m) {
	city = new Building * [n];
	for (int i = 0; i < n; i++)
		city[i] = new Building[m];

}

void Blueprint::deleteCity(int n, int m) {
	for (int i = 0; i < n; i++)
		delete[] city[i];
	delete[] city;
}

void Blueprint::initialMap(int row, int col)
{

	// Fuell die Matrix wieder mit LEER auf
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			city[i][j] = Leer();

		}
	}
}

void Blueprint::plottMap(int row, int col)
{
	// Ausgabe der Matrix auf der Konsole
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
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



	calcPrice(city, row, col);
	calcCoefficientMap(city, row, col);

	cout << "================   GEBAEUDE   ===================" << endl;
	cout << "                                   " << endl;
	cout << "     Solarpanele: " << solCounter << "x" << "     - Grundpreis: " << solarBasePrice << " - " << endl;
	cout << endl;
	cout << "     Wasserkraftwerke: " << wasCounter << "x" << "     - Grundpreis: " << wasserBasePrice << " - " << endl;
	cout << endl;
	cout << "     Windkraftwerke:  " << winCounter << "x" << "     - Grundpreis: " << windBasePrice << " - " << endl;
	cout << endl;
	cout << "                                   " << endl;
	cout << "================   KOSTEN   ===================" << endl;
	cout << "                                   " << endl;
	cout << "      Bauplatz:" << endl;
	cout << "         Solarpanele = " << buildPriceSo << " $" << endl;
	cout << "         Wasserkraftwerke = " << buildPriceWa << " $" << endl;
	cout << "         Windkraftwerke = " << buildPriceWi << " $" << endl;
	cout << "                                   " << endl;
	cout << "================   KOSTEN   ===================" << endl;
	cout << endl;
	cout << "      Material verbaut:" << endl;
	for (pair<Material, int> m : MaterialDB::materialUsed) {
		cout << "        " + m.first.getName() + " - Anzahl: " + to_string(m.second) << endl;
	}
	cout << endl;
	cout << "      Materialkosten gesamt = " << materialPriceAll << " $" << endl;
	cout << endl;
	cout << "      Overall kosten  = " << buildPriceAll << " $" << endl;
	cout << "                                   " << endl;
	cout << "      Kennzahl der Stadt = " << coefficient << endl;
	cout << "                                   " << endl;
	cout << "============== SELECT UR OPTION ===============" << endl;
}

void Blueprint::calcPrice(Building** arr, int row, int col) {

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


	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
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


void Blueprint::saveCity(Building** city, int rows, int cols) {
	if (versionIndex < MAX_VERSIONS) {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				cityVersions[versionIndex][i][j] = city[i][j];
		versionIndex++;
	}
}


void Blueprint::loadCity(Building** city, int index, int rows, int cols) {
	if (index >= 0 && index < versionIndex) {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				city[i][j] = cityVersions[index][i][j];
	}
	else {
		cout << "Kein Plan mit diesem Index vorhanden!" << endl;
	}
}

void Blueprint::calcCoefficientMap(Building** city, int rows, int cols) {

	cityPower = 0;
	coefficient = 0.0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cityPower += city[i][j].getPower();
		}
	}

	calcPrice(city, n, m);


	if (buildPriceAll == 0) {
		coefficient = 0.0;
	}
	else {

		coefficient = (double)cityPower / (double)(buildPriceAll * (rows * cols));
	}


	cout << coefficient << endl;

}