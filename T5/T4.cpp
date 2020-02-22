/*file: T4.cpp
  desc: C++, osa5, T4
        "Luo pisteitä sisältävä taulukko vapaaseen muistiin. Toteuta toimiva ohjelma."
  date: 12.7.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <stdlib.h>     // rand
	
using namespace std;

//Piste -luokka
class Piste{
	private:								  //attribuutit, yksityisiä
	int koordinaattiX;						  //x-koordinaatti
	int koordinaattiY;					      //y-koordinaatti
	int pisteenArvo();						  //yksityinen metodi, palauttaa satunnaisluvun
	
	public:									  //julkiset metodit
	Piste();								  //konstruktori
	void naytaPisteenSijaintiTiedot(int nro); //tulostaa pisteen sijaintitiedot näytölle
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

//tulostaa pisteen sijaintitiedot näytölle
void Piste::naytaPisteenSijaintiTiedot(int nro){
	cout<<"Piste"<<nro<<": ";
	cout<<"X="<<koordinaattiX<<" ";
	cout<<"Y="<<koordinaattiY<<endl;
}

//tuhoaja, poistaa pisteen
Piste::~Piste(){
	cout<<"Poistan pisteen: ("<<koordinaattiX<<","<<koordinaattiY<<")"<<endl;	
}

const short KPL=10;									//pisteiden lukumäärä

//pääluokka
int main ()
{
  	int i;
  	Piste * pisteet;								//piste tyyppisen osoittimen esittely
  	pisteet=new Piste[KPL];							//taulukon ja sen sisältämien pisteiden luonti vapaaseen muistiin, sijainti osoittimeen
  	for (i=0;i<KPL;i++)								//taulukon läpikäynti
		pisteet[i].naytaPisteenSijaintiTiedot(i+1);	//pisteen tietojen tulostus näytölle 	
   	cout<<endl;	
  	
	delete[] pisteet;  								//pisteiden poistaminen
  
  	cin.get();
  	return 0;
}
