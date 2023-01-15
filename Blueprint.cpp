#include "Blueprint.h"
#include "Building.h"

#include "CapCitySim.h"
#include "MaterialDB.h"





void Blueprint::initialMap(Building** arr, int row, int col)
{
	// Fuell die Matrix wieder mit LEER auf
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = Leer();
		}
	}
}

void Blueprint::plottMap(Building** arr, int row, int col)
{
	// Ausgabe der Matrix auf der Konsole
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			string type = arr[i][j].getName();

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




	calcPrice(arr, row, col);
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