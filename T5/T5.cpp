/*file: T5.cpp
  desc: C++, osa5, T5
        "Luo Piste-tyyppisiä osoittimia sisältävä taulukko pinoalueelle. Toteuta toimiva ohjelma."
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

const short KPL=10;										//pisteiden lukumäärä

//pääluokka
int main ()
{
  int i;
  Piste * pistetaulukko[KPL];								//osoitintaulukko pinoalueelle
  for (i=0;i<KPL;i++){										//osoittimien luonti
  	pistetaulukko[i]=new Piste;  							//uusi piste vapaaseen muistiin ja taulukkoon sen osoitin
	pistetaulukko[i]->naytaPisteenSijaintiTiedot(i+1);		//pisteen tietojen tulostus

  }
  cout<<endl;	  
  
  for (i=0;i<KPL;i++){										//pisteiden poistaminen taulukkoa läpikäymällä
  	delete pistetaulukko[i];
  }
  
  cin.get();
  return 0;
}
