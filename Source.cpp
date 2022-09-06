#include "Header.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <time.h> 
#include <string>
#include <chrono>
#include <conio.h>
#include <algorithm>
#include <random>
using namespace std;
using namespace std::chrono_literals;


int macierzfun[1000][1000];


template <typename T> class zbiordanych {

public:
	vector<T> dane;
	vector<int> iteracje;


	zbiordanych(string cfilename, char cdelimiter) :delimiter(cdelimiter), filename(cfilename) {}
		
	void pobierzdane(string instancjestring) {

		string linia;
		int liniat;
		stringstream instance(instancjestring);
		while (getline(instance, linia, ',')) {

			iteracje.push_back(stoi(linia));



		}
		fstream filewords;
		filewords.open(filename, ios::in);
		filewords.seekg(0);
		T tmp;
		for (int i = 0; i < iteracje.back(); i++) {


			getline(filewords, linia, delimiter);

			if (linia.size() > 0) {
				stringstream liniastream(linia);
				liniastream >> tmp;
				dane.push_back(tmp);
			}

		}





	}


private:
	 char delimiter;
	string filename;
	
};




int main() {


	fstream config;
	string infile_name;
	string infilematrix_name;
	string infile_words;
	string outfile_name;
	string instancesize;
	string matrixsize;
	string buffer;
	int liczit = 0;
	int liczitnum = 0;
	int liczitmat = 0;
	int powt;
	double sredniaczas = 0;
	string conftab[6];
	string conftab2[6];
	using std::chrono::high_resolution_clock;
	using std::chrono::duration_cast;
	using std::chrono::duration;
	using std::chrono::milliseconds;
	
	config.open("config.ini", ios::in);

	int i = 0;
	int j = 0;
	while (config.peek() != EOF) {

		getline(config, conftab[i], '=');

		getline(config, conftab2[i]);

		i++;

	}


/*fstream myfile;
int* danegenerowane = new int[numbersgenerated];
myfile.open("wejsciowy2.csv", ios::out | ios::app);
for (int i = 0; i < numbersgenerated; i++) {


	danegenerowane[i] = rand() % 9;
	myfile << danegenerowane[i] << '\n';




}
*/




infile_name = conftab2[0];
infilematrix_name = conftab2[1];
infile_words = conftab2[2];
outfile_name = conftab2[3];
instancesize = conftab2[4];
matrixsize = conftab2[5];


zbiordanych<int> liczbydomacierzy(conftab2[1],'\n');
zbiordanych<string> slowa(conftab2[2],'\n');
zbiordanych<int> liczby(conftab2[0],',');

liczbydomacierzy.pobierzdane(matrixsize);
liczby.pobierzdane(instancesize);
slowa.pobierzdane(instancesize);
int indeks=0;

for (auto i:liczbydomacierzy.dane) {
	indeks++;
	
}

while (true)
{
	system("CLS");
	cout << "Funkcje:\n1.Srednia arytmetyczna\n2.Wartosc maksymalna\n3.Wartosc minimalna\n4.Mediana\n5.Quicksort\n6.Insertsort\n7.Sortowanie bąbelkowe\n8.Sortowanie kubełkowe\n9.Sortowanie przez kopcowanie\n10.Szukanie MST algorytmem Prima-Jarnika\n11.Szukanie Najkrótrszej drogi algorytmem Dijkstry\n12.Usuwanie 20% węzłów z BST\n13.Budowanie drzewa BST \n14.Usuwanie węzeł po węzeł BST\n15.Budowanie tablicy hashowej\n16.Szukanie słowa w hasztablicy \nQ-Wyjdz z programu\n";
	cin >> buffer;

	cout << "Liczba powtórzeń:\n";
	cin >> powt;
	
	
	if (buffer == "10" || buffer == "11"){
		liczit = liczbydomacierzy.iteracje.size();
	}
	else {
		liczit = liczby.iteracje.size();
	}
	
	vector <double> czaswyk;
		for (int j = 0; j < liczit; j++)
		{
			vector <double> czaswykpoj;
			
			int iloscdanych = liczby.iteracje[j];

			int iloscdanychmac = liczbydomacierzy.iteracje[j];
			
			for (int k = 0; k < powt; k++)
			{

				
				vector<int> danewej = { liczby.dane.begin() , liczby.dane.end() - (400000 - iloscdanych) };

				srand(time(NULL));

				
				
			
				/*Tworzenie macierzy sąsiedztwa*/
				/*int g=0;
				for (int i = 0; i < iloscdanychmac; i++) {
					for (int j = 0; j < iloscdanychmac; j++) {
						macierzfun[i][j] = liczbydomacierzy.dane[g];
						g++;
						if (i == j) {
							macierzfun[i][j] = 0;
						}
					
						if (i > j) {


							macierzfun[j][i] = macierzfun[i][j];
						}
					
					
					
					
					}
				
				}
				
				*/

				if (buffer == "1")
				{

					auto t1 = high_resolution_clock::now();
					fsrednia(danewej, iloscdanych);
					auto t2 = high_resolution_clock::now();
					duration<double, std::milli> ms_double = t2 - t1;
					
					
					czaswykpoj.push_back(ms_double.count());
				}

				else if (buffer == "2")
				{
					auto t1 = high_resolution_clock::now();
					funmax(danewej, iloscdanych);
					auto t2 = high_resolution_clock::now();
					duration<double, std::milli> ms_double = t2 - t1;
					czaswykpoj.push_back(ms_double.count());
					
				}

				else if (buffer == "3")
				{
					auto t1 = high_resolution_clock::now();
					funmin(danewej, iloscdanych);
					auto t2 = high_resolution_clock::now();
					duration<double, std::milli> ms_double = t2 - t1;
					
					
					czaswykpoj.push_back(ms_double.count());
				}

				else if (buffer == "4")
				{
					auto t1 = high_resolution_clock::now();
					fmediana(danewej, iloscdanych);
					auto t2 = high_resolution_clock::now();
					duration<double, std::milli> ms_double = t2 - t1;
					
					
					czaswykpoj.push_back(ms_double.count());

				}

				else if (buffer == "5")
				{
					auto t1 = high_resolution_clock::now();
					quicksort(danewej,0,iloscdanych-1);
					auto t2 = high_resolution_clock::now();
					duration<double, std::milli> ms_double = t2 - t1;


					czaswykpoj.push_back(ms_double.count());

				}
				else if (buffer == "6")
				{
					auto t1 = high_resolution_clock::now();
					insertsort(liczby.dane, iloscdanych);
					auto t2 = high_resolution_clock::now();

					duration<double, std::milli> ms_double = t2 - t1;


					czaswykpoj.push_back(ms_double.count());

				}






				else if (buffer == "7")
				{
				auto t1 = high_resolution_clock::now();
				fsortbabelkowe(liczby.dane, iloscdanych);
				auto t2 = high_resolution_clock::now();

				duration<double, std::milli> ms_double = t2 - t1;


				czaswykpoj.push_back(ms_double.count());

				}

				else if (buffer == "8")
				{
				auto t1 = high_resolution_clock::now();
				fsortkubelkowe(liczby.dane, iloscdanych);
				auto t2 = high_resolution_clock::now();

				duration<double, std::milli> ms_double = t2 - t1;


				czaswykpoj.push_back(ms_double.count());

				}


				else if (buffer == "9")
				{
				auto t1 = high_resolution_clock::now();
				fsortkopcowanie(liczby.dane, iloscdanych);
				auto t2 = high_resolution_clock::now();

				duration<double, std::milli> ms_double = t2 - t1;


				czaswykpoj.push_back(ms_double.count());

				}


				else if (buffer == "10")
				{
				auto t1 = high_resolution_clock::now();
				fjarnikaprima(macierzfun, iloscdanychmac);
				auto t2 = high_resolution_clock::now();

				duration<double, std::milli> ms_double = t2 - t1;


				czaswykpoj.push_back(ms_double.count());

				}

				else if (buffer == "11")
				{
				auto t1 = high_resolution_clock::now();
				fdijkstra(macierzfun, iloscdanychmac);
				auto t2 = high_resolution_clock::now();

				duration<double, std::milli> ms_double = t2 - t1;


				czaswykpoj.push_back(ms_double.count());

				}

				else if (buffer == "12")
				{
				auto t1 = high_resolution_clock::now();
				fdijkstra(macierzfun, iloscdanychmac);
				auto t2 = high_resolution_clock::now();

				duration<double, std::milli> ms_double = t2 - t1;

				
				czaswykpoj.push_back(ms_double.count());

				}
				

				
				


				else if (buffer == "Q" || "q")
				{
					exit(0);
				}

			}



			sredniaczas = 0;
			for (int i = 0; i < powt; i++) {

				sredniaczas = czaswykpoj[i] + sredniaczas;




			}
			sredniaczas = sredniaczas / powt;
			
			czaswyk.push_back(sredniaczas);
			if (buffer == "10" || buffer == "11") {
				cout << "Czas wykonania dla macierzy o wielkości " << liczbydomacierzy.iteracje[j] << "x" << liczbydomacierzy.iteracje[j] <<"  ";
				cout << czaswyk[j] << '\n';
			}
			else {
				cout << "Czas wykonania dla " << liczby.iteracje[j] << " iteracji: ";
				cout << czaswyk[j] << '\n';
			}
			/*Liczenie średniego czasu*/




		}
		ofstream plikwyjsciowy(outfile_name);
		plikwyjsciowy << "Dane z pliku:\n" << infile_name << '\n';
		plikwyjsciowy << "Wielkość instacji:\n";
		for (int j = 0; j < liczit; j++)
		{
			if(buffer == "10" || buffer == "11"){
			
				plikwyjsciowy << liczbydomacierzy.iteracje[j];
			}
			else {

				plikwyjsciowy << liczby.iteracje[j];
			}
			
			if (j < liczit - 1)
			{
				plikwyjsciowy << ",";

			}




		}
		plikwyjsciowy << "\nCzas:\n";
		for (int j = 0; j < liczit; j++)
		{

			plikwyjsciowy << czaswyk[j];
			if (j < liczit - 1)
			{
				plikwyjsciowy << ",";

			}
		}
		plikwyjsciowy <<"\nLiczba powtórzen: \n" << powt;
		system("pause");
	


	}



		
	/*fstream myfile;
	int* danegenerowane = new int[numbersgenerated];
	myfile.open("wejsciowy2.csv", ios::out | ios::app);
	for (int i = 0; i < numbersgenerated; i++) {


		danegenerowane[i] = rand() % 65000 + 1;
		myfile << danegenerowane[i] << '\n';




	}
	


	*/




}


