/*file: T23.cpp
  desc: C++, osa2, T23
  date: 10.6.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
	
using namespace std;

const int MAX=3;

void puolita(float *x);
float keskiarvo(float *os);
string minmax(float *os);

int main ()
{
  float luvut[MAX]={-0.67,15.7,15369.455};
  int i;

  //taulukkomuuttujan alkuperäiset arvot
  cout<<endl<<"Alkuper\x84iset luvut:\t";
  for (i=0;i<MAX;i++){
  	cout<<luvut[i]<<"\t\t"; 
    puolita(&luvut[i]);
  }

  ///taulukkomuuttujan puolitetut arvot
  cout<<endl<<"Puolitetut luvut:\t";
  for (i=0;i<MAX;i++) 
  	cout<<luvut[i]<<"\t\t";  
    
  cout<<endl<<endl<<"Puolitettujen lukujen keskiarvo: "<<keskiarvo(luvut);
  
  cout<<endl<<endl<<"Puolitettujen lukujen vaihteluv\x84li: "<<minmax(luvut);
  
  cin.get();
  return 0;
}

void puolita(float *x){
	*x/=2;
}

float keskiarvo(float *os){
	int i=0;
	int summa=0;
	while (i<MAX){
		summa=summa+*(os+i);
		i++;
	}
	return ((float)summa/3);
}

//etsii taulukon suurimman ja pienimmän arvon
//palauttaa tiedon stringinä
string minmax(float *os){
	float nrot[MAX];
	float maxi, mini, luku;
	int i=0;
	
	//luetaan paikalliseen taulukkoon
 	while (i<MAX){
		nrot[i]=*(os+i);
		i++;
	} 	
	
  	maxi=nrot[0];
  	mini=nrot[0];	
  	
  	//etsitään minimi ja maksimi
 	for (i=1; i<3;i++){
  	 luku=nrot[i];
 	 //maximin etsiminen
 	 if (luku<mini) 
 	 	mini=luku;
 	 //minimin etsiminen
 	 else if (luku>maxi) 
 	 	maxi=luku;
	}
	
	//numerotiedon muutos merkeiksi
	char min[50];
	char max[50];
    sprintf(min, "%f", mini);
    sprintf(max, "%f", maxi);
    string t1=min;
    string t2=max;
    return t1+" - "+t2;	
}
