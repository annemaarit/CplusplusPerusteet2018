/*file: T1.cpp
  desc: C++, osa1, T1
  date: 8.6.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
using namespace std;

#include <stdio.h>      // NULL
#include <stdlib.h>     // srand, rand
#include <time.h>       // time

const short KPL=20;		
const short MAX=100;

int main ()
{
  short luku,maxi;
  short i=0;
  short luvut[KPL];
  
  //satunnaisluvun alustus järjestelmän kellosta
  srand (time(NULL));	

  for (i=0;i<KPL;i++){
 	 //satunnaisluvun muodostus väliltä 0-100
 	 luku = rand() % (MAX+1);
 	 luvut[i]=luku;	 
 	 cout<<luku<<" ";
	}
  cout<<endl<<endl;
  
  i=0;
  cout<<endl<<endl;
  
  maxi=luvut[0];
  for (i=1; i<KPL;i++){
 	 //maximin etsiminen
 	 if (luvut[i]>maxi) 
 	 	maxi=luvut[i];
	}
  cout<<"MAKSIMIARVO: "<<maxi<<endl;
 	
  return 0;
}
