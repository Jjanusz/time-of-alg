#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h> 
#include <string>
#include "Header.h"
#include <vector>
using namespace std;
int maximum;
int minimum;
float mediana;
int srednia;

/*
Sortpwanie liczb calkowitych metoda QuickSort
Program zostal pobrany ze strony www.algorytm.org
Opracowal Michal Knasiecki
*/



void insertsort(vector<int>& danewej, int iloscdanych)
{
	int x, j;
	int* tab = new int[iloscdanych];

	for (int i = 1; i < iloscdanych; i++)
	{
		tab[i] = danewej[i];





	}

	for (int i = 1; i < iloscdanych; i++)
	{
		
		x = tab[i]; 
		j = i - 1;

		
		while (j >= 0 && tab[j] >x)
		{
			tab[j + 1] = tab[j];
			--j;
		}
		tab[j + 1] = x; 
	}
}






void quicksort(vector<int>& danewej,int x, int y)
{
	int i, j, v, temp;
	i = x;
	j = y;
	v = danewej[div(x + y, 2).quot];
	do
	{
		while (danewej[i] < v) i++;
		while (v < danewej[j]) j--;
		if (i <= j)
		{
			temp = danewej[i];
			danewej[i] = danewej[j];
			danewej[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
if (x < j) quicksort(danewej, x, j);
if (i < y) quicksort(danewej, i, y);
}



int funmin(vector<int>& danewej, int iloscdanych)
{



	minimum = danewej[0];
	for (int i = 0; i < iloscdanych; i++)
	{

		if (minimum > danewej[i])
			minimum = danewej[i];

	}
	return (minimum);



}

int funmax(vector<int>& danewej, int iloscdanych)
{


	maximum = danewej[0];
	for (int i = 0; i < iloscdanych; i++)
	{

		if (maximum < danewej[i])
			maximum = danewej[i];

	}

	return (maximum);

}




void fmediana(vector<int>& danewej, int iloscdanych)
{
	mediana = 0;
	quicksort(danewej, 0, iloscdanych - 1);

	if (iloscdanych % 2 == 0)
	{


		mediana = float((danewej[iloscdanych / 2] + danewej[iloscdanych / 2 - 1])) / 2;
	}
	else
	{
		mediana = danewej[iloscdanych / 2];


	}






}

void fsrednia(vector<int>& danewej, int iloscdanych)
{


	srednia = 0;
	for (int i = 0; i < iloscdanych; i++) {

		srednia = danewej[i] + srednia;




	}
	srednia = srednia / iloscdanych;
	cout << srednia;
}



void fsortbabelkowe(vector<int>& danewej, int iloscdanych)
{
	for(int i=0;i<iloscdanych;i++){
				for(int j=1;j<iloscdanych-i;j++){
					if (danewej[j - 1] > danewej[j])
						swap(danewej[j - 1], danewej[j]);
				}
	
	
	}

	for (int i = 0; i < iloscdanych; i++) {
		
	}
}

void fsortkubelkowe(vector<int>& danewej, int iloscdanych)
{
	int k = iloscdanych;

	int range;
	int max = funmax(danewej, iloscdanych);
	int min = funmin(danewej, iloscdanych);

	range = abs(max - min);
	int ilosckubelkow = range;
	int* kubelki = new int[ilosckubelkow];
	int* tabposort = new int[iloscdanych];
	for (int i = 0; i < ilosckubelkow; i++)
	{


		kubelki[i] = 0;
	}


	for (int i = 0; i < iloscdanych; i++)
	{
		/*wartości w kubelki przesuniete są do przodu o najmniejsza wartosc , nie działa dla dodatniego min z tego powodu (do poprawienia)*/
		kubelki[danewej[i] + abs(min)]++;




	}
	int indeks = 0;
	for (int i = 0; i < ilosckubelkow; i++)
	{

		int j;
		for (j = indeks; j < kubelki[i] + indeks; j++)

		{


			tabposort[j] = i - abs(min);

			/* cout << tabposort[indeks] << " ";*/

		}
		indeks = j;

	}

}
	 

void fsortkopcowanie(vector <int>& danewej, int iloscdanych)  
{
	int j;
	int k;
	int d;
	int x;
	int m;




	for (int i = 2; i <= iloscdanych; i++)
	{
		j = i; 
		k = j / 2;
		x = danewej[i];
		while ((k > 0) && (danewej[k] < x))
		{
			danewej[j] = danewej[k];
			j = k; k = j / 2;
		}
		danewej[j] = x;
	}

	// Rozbieramy kopiec

	for (int i = iloscdanych; i > 1; i--)
	{
		swap(danewej[1], danewej[i]);
		j = 1; k = 2;
		while (k < i)
		{
			if ((k + 1 < i) && (danewej[k + 1] > danewej[k]))
				m = k + 1;
			else
				m = k;
			if (danewej[m] <= danewej[j]) break;
			swap(danewej[j], danewej[m]);
			j = m; k = j + j;
		}
	}

	



}



void fjarnikaprima(int macierzfun[1000][1000], int iloscdanychmac) {

	//Wypisanie macierzy sąsiedztwa "macierzfun"
	/*int g = 0;
	for (int i = 0; i < iloscdanychmac; i++) {
		for (int j = 0; j < iloscdanychmac; j++) {
			
			cout << macierzfun[i][j] << ' ';
			g++;
			if (iloscdanychmac == j+1) {

				cout << '\n';


			}
		}
	}
	*/

	/*Funkcja na podstawie strony: https://www.programiz.com/dsa/prim-algorithm/ */
	int selected[1000];
	memset(selected, false, sizeof(selected));
	int edge_number = 0;
	selected[0] = true;

	int INF = INT_MAX;
	int x;
	int y;
	
	while (edge_number < iloscdanychmac - 1) {
	

		int min = INF;
		x = 0;
		y = 0;

		for (int i = 0; i < iloscdanychmac; i++) {
			if (selected[i]) {
				for (int j = 0; j < iloscdanychmac; j++) {
					if (!selected[j] && macierzfun[i][j]) {  
						if (min > macierzfun[i][j]) {
							min = macierzfun[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		/*cout << x << " - " << y << " :  " << macierzfun[x][y];*/
		/*cout << endl;*/
		selected[y] = true;
		edge_number++;
	}




}







void fdijkstra(int macierzfun[1000][1000], int iloscdanychmac) {


	/*Funkjca na podstawie strony:https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/ */


	int dist[1000];

	bool sptSet[1000];
	int src = 0;
	
	
	for (int i = 0; i < iloscdanychmac; i++) {
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	dist[src] = 0;


	for (int count = 0; count < iloscdanychmac; count++) {

		int min = INT_MAX, min_index;

		for (int v = 0; v < iloscdanychmac; v++)
			if (sptSet[v] == false && dist[v] <= min)
				min = dist[v], min_index = v;

		int u = min_index;
		

		sptSet[u] = true;


		for (int l = 0; l < iloscdanychmac; l++) {


			if (!sptSet[l] && macierzfun[u][l] && dist[u]!= INT_MAX && dist[u] + macierzfun[u][l] < dist[l])
				dist[l] = dist[u] + macierzfun[u][l];
			
		}


	}

	

}





