/*file: T5.cpp
  desc: C++, osa2, T5
  date: 9.6.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <string.h>		//strlen
using namespace std;

const short MAX=40;
const char *SKANDI1a="\x84"; //ä
const char *SKANDI2o="\x94"; //ö
const char *SKANDI3A="\x8e"; //Ä
const char *SKANDI4O="\x99"; //Ö

int main ()
{
  char kaupunki[MAX];
  char vokaalit[]={'a','A','e','E','i','I','o','O','u','U','y','Y',*SKANDI1a,*SKANDI2o,*SKANDI3A,*SKANDI4O,'\0'};
  char merkki;
  short i,j;
  short kpl=0;
  short pituus1, pituus2;
  
  cout<<"Anna kaupungin nimi: "<<endl;
  cin.get(kaupunki,MAX);
  
  pituus1=strlen(kaupunki);
  pituus2=strlen(vokaalit);  
  
  for (i=0;i<pituus1;i++){			//kaupungin nimen merkkien läpikäynti
  	merkki=kaupunki[i];				//merkki kaupungin nimestä
  	for (j=0;j<pituus2;j++){		//vokaalien läpikäynti	
  		if (merkki==vokaalit[j]){	//jos merkki ja vokaali samoja
  			kpl++;
  			j=pituus2;
		  }	
	}   	
  }
  
  cout<<"Nimess"<<*SKANDI1a<<": "<<kaupunki<<" on "<<kpl<<" kpl vokaaleja"<<endl;
  
  cin.get();
  return 0;
}
