#include<vector>
#include<string>

extern int macierzfun[1000][1000];

extern int  min;
extern  int  max;
extern int srednia;
extern float mediana;



void insertsort(std::vector<int>&, int);
void quicksort(std::vector<int>&, int, int);
int funmin(std::vector<int>&,int);
int funmax(std::vector<int>&,int);
void fmediana(std::vector<int>&, int);
void fsrednia(std::vector<int>&, int);
void fsortbabelkowe(std::vector<int>&, int);
void fsortkubelkowe(std::vector<int>&, int);
void fsortkopcowanie(std::vector<int>&, int);
void fjarnikaprima(int[1000][1000], int);
void fdijkstra(int[1000][1000], int);
int fhash(std::string, int);