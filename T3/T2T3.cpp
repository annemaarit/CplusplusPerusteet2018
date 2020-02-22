/*file: T2T3.cpp
  desc: C++, osa3, T2T3
  		- lukujen vaihtolajittelu T3
        - luvun bin‰‰rinen haku T2
  date: 21.6.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <stdio.h>      // NULL
#include <stdlib.h>     // srand, rand
#include <time.h>       // time, clock_t, clock, CLOCKS_PER_SEC 

using namespace std;

const short LKM=3;		//alkioryhmien lukum‰‰r‰

int haeLukuBin(int nrot[],int nro, int kpl);
void teeLuvut(int *nrot, int kpl);
void vaihtolajittele(int taulu[],int kpl);
void vaihda (int &a,int &b);

int main ()
{
  int k=0;				//alkioryhm‰n indeksi, 0-2
  int kpl,h;				//alkioiden m‰‰r‰
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
  	//for (h=0;h<kpl;h++)						//testausta varten
  	//	cout<<luvut[h]<<" ";    	
  	cout<<"Aloitan "<<alkiot[k]<<" alkion vaihtolajittelun"<<endl;
	aika=clock();	 						//mittauksen aloitus arvo  
    vaihtolajittele(luvut,kpl);  			//lukujen lajittelu nousevaan j‰rjestykseen
  	paikka=haeLukuBin(luvut,luku,kpl);		//annetun luvun haku
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

//taulukon lajittelu vaihtolajittelualgoritmilla
//- taulukko, taulukon pituus
void vaihtolajittele(int taulu[],int kpl){
	for (int i=0;i<(kpl-1);i++) 
		for (int k=i+1;k<kpl;k++) 
			if (taulu[i]>taulu[k])		//jos alkion arvo on suurempi kuin verrattavana olevan alkion arvo
				vaihda(taulu[i],taulu[k]);	//vaihdetaan alkioiden arvojen paikkaa
}

//vaihtaa taulukon kahden alkion arvot toisiinsa
void vaihda (int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}

//luvun bin‰‰rinen haku taulukosta
//- taulukko, haettava luku, taulukon koko
//- palauttaa luvun paikan indeksin tai jos lukua ei lˆydy -1
int haeLukuBin(int nrot[],int nro, int kpl){
	int vasen=0;					
	int oikea=kpl-1;				
	int keskikohta;
	int arvokeski;					//keskikohdan alkion arvo
	while (vasen<=oikea){			//toistetaan kunnes hakup‰‰t kohtaavat
		keskikohta=(vasen+oikea)/2;	//keskikohdan laskenta
		arvokeski=nrot[keskikohta];
		if (nro>arvokeski)			//jos haettu luku on keskikohtaa isompi
			vasen=keskikohta+1;		//siirret‰‰n haku alkamaan keskikohdasta seuraavaan alkioon
		else if (nro<arvokeski)		//jos haettu luku on keskikohtaa pienempi
			oikea=keskikohta-1;		//siirret‰‰n haku loppumaan keskikohtaa edelt‰v‰‰n alkioon
		else
			return keskikohta;		//haettu luku on sama kuin keskikohdan arvo
	}
	return -1; //ei lˆytynyt;
}


