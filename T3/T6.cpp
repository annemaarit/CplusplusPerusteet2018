/*file: T5.cpp
  desc: C++, osa3, T5
  		- nimien shell -lajittelu 
  date: 21.6.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <stdio.h>    

using namespace std;

const short LKM=10;		//nimien lukumäärä

void shellLajittele(string tekstit[],int kpl);
void vaihda (string &a,string &b);
void tulostaNimet(string taulukko[], int kpl);


int main ()
{
  string nimet[LKM]={"Ville","Kaisa","Anne","Carita","Pilvi","Jooseppi","Aune","Yrjö","Tapani","Selja"};
  
  cout<<"Nimet ennen lajittelua:"<<endl;
  tulostaNimet(nimet,LKM);
  shellLajittele(nimet,LKM);  		
  cout<<"Nimet lajittelun jälkeen:"<<endl;
  tulostaNimet(nimet,LKM);
    		 
  cin.get();
  return 0;
} 

//tulostaa taulukon alkioiden nimiarvot
void tulostaNimet(string taulukko[], int kpl){
  for (int i=0;i<kpl;i++)
  	cout<<taulukko[i]<<" ";
  cout<<endl<<endl;
}

//vaihtaa taulukon kahden alkion arvot toisiinsa
void vaihda (string &a,string &b){
	string temp;
	temp=a;
	a=b;
	b=temp;
}

//taulukon lajittelu shell -lajittelualgoritmilla
//- taulukko, taulukon pituus
void shellLajittele(string tekstit[],int kpl){
	int k,valimatka;
	bool vaihto=true;
	valimatka=kpl/2;
	do{														//lajittelukierrokset
	  do{													//kierroksen sisäiset iteraatiot
		vaihto = false;
		for (k = 0; k < (kpl - valimatka); k++)
			if (tekstit[k] > tekstit[k + valimatka]){		//jos verrattava numero on pienempi
				vaihda(tekstit[k],tekstit[k + valimatka]);	//vaihdetaan numerojen paikkoja
				vaihto = true;
			}
	  }while (vaihto);
	}while ( (valimatka /= 2) > 0);
}


