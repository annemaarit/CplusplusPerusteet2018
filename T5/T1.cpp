/*file: T1.cpp
  desc: C++, osa5, T1
        "Toteuta Piste-luokka, joka kuvaa XY-koordinaatiston pistett�. Luo pisteet vapaaseen muistiin.
		 Luo silmukassa 10 pistett� antaen arvot satunnaislukuina."
  date: 12.7.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <stdlib.h>     // rand
	
using namespace std;

//Piste -luokka
class Piste{
	private:								  //attribuutit, yksityisi�
	int koordinaattiX;						  //x-koordinaatti
	int koordinaattiY;					      //y-koordinaatti
	int pisteenArvo();						  //yksityinen metodi, palauttaa satunnaisluvun
	
	public:									  //julkiset metodit
	Piste();								  //konstruktori
	void naytaPisteenSijaintiTiedot(int nro); //tulostaa pisteen sijaintitiedot n�yt�lle
	~Piste();								  //tuhoaja
};

//konstruktori, joka muodostaa ja alustaa origossa sijaitsevan pisteen
Piste::Piste(){
	koordinaattiX=pisteenArvo();
	koordinaattiY=pisteenArvo();
}

int Piste::pisteenArvo(){
	return (rand()%100);
}

//tulostaa pisteen sijaintitiedot n�yt�lle
void Piste::naytaPisteenSijaintiTiedot(int nro){
	cout<<"Piste"<<nro<<": ";
	cout<<"X="<<koordinaattiX<<" ";
	cout<<"Y="<<koordinaattiY<<endl;
}

//tuhoaja, poistaa pisteen
Piste::~Piste(){
	cout<<"Poistan pisteen: ("<<koordinaattiX<<","<<koordinaattiY<<")"<<endl;	
}

const short KPL=10;										//pisteiden lukum��r�

//p��luokka
int main ()
{
  Piste *pPiste;										//Piste tyyppisen osoittimen esittely 
  for (int i=0;i<KPL;i++){  								//piste -olioiden luonti
 	pPiste=new Piste;									//uusi piste vapaaseen muistiin, sijaintitieto osoittimeen
	pPiste->naytaPisteenSijaintiTiedot(i+1);			//pisteen tietojen tulostus n�yt�lle 
	delete pPiste;										//muistin vapautus eli olion tuhoaminen
  	cout<<endl;	
  }
  
  cin.get();
  return 0;
}
