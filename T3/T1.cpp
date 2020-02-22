/*file: T1.cpp
  desc: C++, osa3, T1,
        - luvun lineaarinen haku
  date: 21.6.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <stdio.h>      // NULL
#include <stdlib.h>     // srand, rand
#include <time.h>       // time, clock_t, clock, CLOCKS_PER_SEC 

using namespace std;

const short LKM=3;		//alkioryhmien lukum‰‰r‰

int haeLukuLin(int nrot[], int nro, int kpl);
void teeLuvut(int *nrot, int kpl);

int main ()
{
  int k=0;				//alkioryhm‰n indeksi, 0-2
  int kpl,h;			//alkioiden m‰‰r‰
  int alkiot[LKM]={10000,50000,100000};
  float ajat[LKM];		//hakuajat
  int luku; 			//etsitt‰v‰ luku
  float kesto;			//haun kesto
  int paikka;			//haetun numeron paikkaindeksi (-1, jos ei lˆydy)
  int paikat[LKM];		//hakutulosten paikkataulukko
  clock_t aika;			//aikamuuttuja
  
  cout<<"Anna etsitt‰v‰ luku (0-32767): ";	//luku, jota haetaan kaikista alkioryhmist‰
  cin>>luku;    
  
  do{										//k‰yd‰‰n l‰pi kaikki alkioryhm‰t
  	kpl=alkiot[k];							//ryhm‰n alkioiden m‰‰r‰
  	int *luvut=new int[kpl];				//uusi taulukko alkioille
    teeLuvut(luvut,kpl);    				//satunnaislukujen muodostus taulukkoon
  	//for (h=0;h<kpl;h++)					//testausta varten
  	//	cout<<luvut[h]<<" ";    	
  	aika=clock();	 						//mittauksen aloitus arvo  
  	paikka=haeLukuLin(luvut,luku,kpl);		//annetun luvun haku
  	aika=clock()-aika;						//mittauksen kesto, lopetus arvo - aloitus
  	kesto=((float)aika/CLOCKS_PER_SEC);		//aika sekunneiksi  
  	if (paikka!=-1)							//jos luku lˆytyi
  		ajat[k]=kesto;						//ajan talletus
  	else									//lukua ei lˆytynyt
  		ajat[k]=paikka;						//-1 talletus
  	paikat[k]=paikka;						//haetun tuloksen paikan tallennus tai -1
 	//cout<<"paikka: "<<paikka<<endl;					
	delete [] luvut;						//taulukon tilanvapautus
  	k++;
  }while(k<LKM);
  
  cout<<"Alkioiden m‰‰r‰\t Lˆytyi indeksist‰\t Hakuaika (s)"<<endl;
  for (k=0;k<3;k++){						//tulostetaan suoritusajat
  	if (ajat[k]!=-1)						//jos luku lˆytyi
  		cout<<alkiot[k]<<"\t\t\t"<<paikat[k]<<"\t\t\t"<<ajat[k]<<endl; 
  	else									//lukua ei lˆytynyt
  		cout<<alkiot[k]<<"\t\t ei lˆytynyt"<<endl;
  }
  		 
  cin.get();
  return 0;
} 

//satunnaislukujen generointi taulukkoon
//- osoitin taulukkoon, taulukon koko
void teeLuvut(int *nrot, int kpl){
  int i;
  int nro;
  for (i=0; i<kpl;i++){
 	nro = rand();		//satunnaisluvun muodostus	 
 	 *(nrot+i)=nro;		//luku taulukkoon	 
	}	
	
}

//luvun lineaarinen hakeminen taulukosta
//- taulukko, haettava luku, taulukon koko
//- palauttaa luvun paikan indeksin tai jos lukua ei lˆydy -1
int haeLukuLin(int nrot[], int nro, int kpl){			
	int j;

	for (j=0; j<kpl; j++){
		cout<<"*";					//valitettavasti t‰m‰ k‰ytˆss‰, jotta sain edes jotain mittaus aikoja
		if (nrot[j] == nro){
			cout<<endl;
			return j;
		}	
	}	
	cout<<endl;	
	return -1;
}
