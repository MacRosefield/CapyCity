#include <iostream>
#include <vector>


using namespace std;
using mapArray = vector<int>;
using city = vector<vector<int>>;

void initialize(city Arr) {
	int width = 51; // unsigned types cannot be negative
	int height = 51;
	int i, j, v;
	do {
		cout << "Bitte gib die Laenge der Stadt ein: " << endl;
		cin >> width;
		if (width > 50) {
			cout << "Invalid size, enter a value between 0 and 50" << endl;
		}
	} while (width > 50);

	do {
		cout << "Bitte gib die Hoehe der Stadt ein: " << endl;
		cin >> height;
		if (height > 50) {
			cout << "Invalid size, enter a value between 0 and 50" << endl;
		}
	} while (height > 50);


	for (int i = 0; i < height; i++) {
		vector<int> vTemp(1, width);
		Arr.push_back(vTemp);
		cout << endl;
	}

}

/*
for (int i = 0; i < Arr.size(); i++) {
	for (int j = 0; j < Arr[i].size(); j++)
		cout << Arr[i][j] << " ";
	cout << endl;
}
*/

void get_input(mapArray& Arr) { // gets input
	int sz = 51; // unsigned types cannot be negative
	do {
		cout << "Groesse eingeben: " << endl;
		cin >> sz;
		if (sz > 50) {
			cout << "Invalid size, enter a value between 0 and 50" << endl;
		}
	} while (sz > 50);

	
	for (int i = 0; i < sz; ++i) {
		int v = 0;
			Arr.push_back(v);
	}
	cout << endl;
}

void printArray(mapArray const& Arr) { // prints array elements
	for (size_t i = 0; i < Arr.size(); ++i) {
		cout << Arr[i] << " ";
		cout << " ";
	}
}

void printCity(city const& Arr) { // prints array elements
	for(int i = 0; i < Arr.size(); i++) {
		for (int j = 0; j < Arr[i].size(); j++) {
			cout << Arr[i][j] << " ";
		}
		cout << endl;
	}
}

//int main() {

		//Inititalisierung
	
	enum building { wasserkraftwerk, windkraftwerk, solarpanel };


	cout << "Herzlich wilkommen im Bauplatzplaner 7000" << endl;
	cout << "wir verplanen den Platz, ob Sie wollen oder nicht!" << endl;

	system("pause");


	//int main()	{

		int SIZE = 0;

		cin >> SIZE;

    int arr = new int[SIZE];

	for(int i = 0; i < SIZE; ++i) {
        arr[i] = 0;
    }

    for(int i = 0; i < SIZE; ++i) {
        arr[i] = chars[i];
        cout << arr[i] << "; ";
    }
    cout << endl;



    delete [] arr;


	
	// city(Arr);
	// initialize(Arr);
	// printCity(Arr);

	// mapArray(Arr);
	// get_input(Arr);
	// printArray(Arr);

	cout << "Datentyp des dings :" << typeid(mapArray).name() << endl;

	// vector<vector<int>> vect
	// {
	// 	{1, 2, 3},
	// 	{4, 5, 6},
	// 	{7, 8, 9}
	// };

	/*

	cout << "Bitte gib die Breite der Stadt in Feldern ein: ";
	cin >> width;
	cout << endl;

	cout << "Bitte gib die H�he der Stadt in Feldern ein: ";
	cin >> height;
	cout << endl;

	int stadtArray[width][height] = { 0 };

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			stadtArray[i][j] = 0;
		}
		cout << endl;
	}


	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
				cout << stadtArray[i][j] << "   ";
		}
		cout << endl;
	}
	*/
	

	return 0;

}


// int main() { 

// 	vector<vector<int>> v;     
	
// 		for (int i = 0; i < 5; i++) { 
// 			vector<int> v2(1, 5);         
			
// 			v.push_back(v2); } 
// }