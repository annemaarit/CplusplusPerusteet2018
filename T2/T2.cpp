/*file: T2.cpp
  desc: C++, osa2, T2
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
  short luku,maxi,mini;
  short i=0;
  short luvut[KPL];	

  //satunnaisluvun alustus järjestelmän kellosta
  srand (time(NULL));	

  for (i=0;i<KPL;i++){
 	 //satunnaisluvun muodostus
 	 luvut[i] = rand() % (MAX+1);
 	 cout<<luvut[i]<<" ";
	}
  cout<<endl<<endl;

  maxi=luvut[0];
  mini=luvut[0];
  for (i=1; i<KPL;i++){
  	luku=luvut[i];
 	 //maximin etsiminen
 	 if (luku<mini) 
 	 	mini=luku;
 	 //minimin etsiminen
 	 else if (luku>maxi) 
 	 	maxi=luku;
	}
  cout<<"Vaihteluv\x84li: "<<mini<<"-"<<maxi<<endl;
 	
  return 0;
}
