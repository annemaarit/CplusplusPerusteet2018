/*file: T39.cpp
  desc: C++, osa1, T39
  date: 19.5.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
using namespace std;

#include <stdio.h>      // NULL
#include <stdlib.h>     // srand, rand
#include <time.h>       // clock_t, clock, CLOCKS_PER_SEC 

const int KPL=10000;
const short MAX=1000;

int main ()
{
  short luku;
  clock_t aika;					//aikamuuttuja

  
  //srand (time(NULL));			//satunnaisluvun alustus järjestelmän kellosta

  cout<<"SATUNNAISLUVUT"<<endl;
  
  
  aika=clock();	 				//mittauksen aloitus arvo
  for (int i=0; i<KPL;i++){
 	 
 	 luku = rand() % MAX + 1;	//satunnaisluvun muodostus
 	 //cout<<luku<<" ";
	}
  aika=clock()-aika;			//mittauksen kesto, lopetus arvo - aloitus	
  
  cout<<"\n\nAikaa kului: "<<((float)aika/CLOCKS_PER_SEC);	//aika sekunneiksi

  cin.get();
  return 0;
}
