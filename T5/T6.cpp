/*file: T6.cpp
  desc: C++, osa5, T6
        "Toteuta funktio, joka siirt�� Piste-olion X-ja Y-koordinaattia yhden yksik�n."
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
	Piste(const Piste &piste);				  //kopiomuodostin
	void naytaPisteenSijaintiTiedot();		  //tulostaa pisteen sijaintitiedot n�yt�lle
	int palautaX();							  //palauttaa X-koordinaatin arvon	
	int palautaY();							  //palauttaa Y-koordinaatin arvon
	void vaihdaX(int x);					  //vaihtaa X-koordinaatin arvon
	void vaihdaY(int y);					  //vaihtaa Y-koordinaatin arvon
	~Piste();								  //tuhoaja					
};

//konstruktori, joka muodostaa ja alustaa origossa sijaitsevan pisteen
Piste::Piste(){
	koordinaattiX=pisteenArvo();
	koordinaattiY=pisteenArvo();
}

//kopiomuodostin
Piste::Piste(const Piste &piste){
	cout << "Kopioin Piste -olion\n";
	koordinaattiX=piste.koordinaattiX;
	koordinaattiY=piste.koordinaattiY;
}

int Piste::pisteenArvo(){
	return (rand()%100);
}

//tulostaa pisteen sijaintitiedot n�yt�lle
void Piste::naytaPisteenSijaintiTiedot(){
	cout<<"Piste: ";
	cout<<"X="<<koordinaattiX<<" ";
	cout<<"Y="<<koordinaattiY<<endl;
}

//palauttaa X-koordinaatin arvon
int Piste::palautaX(){
	return koordinaattiX;
}

//palauttaa Y-koordinaatin arvon
int Piste::palautaY(){
	return koordinaattiY;
}

//vaihtaa X-koordinaatin arvon
void Piste::vaihdaX(int x){
	koordinaattiX=x;
}

//vaihtaa Y-koordinaatin arvon
void Piste::vaihdaY(int y){
	koordinaattiY=y;
}

//tuhoaja, poistaa pisteen
Piste::~Piste(){
	cout<<"Poistan pisteen: ("<<koordinaattiX<<","<<koordinaattiY<<")"<<endl;	
}

//funktio, joka siirt�� olion koordinaatteja yhdell� yksik�ll�
void siirraYhdellaYksikolla(Piste *pp);

const short KPL=3;										//pisteiden lukum��r�

//p��luokka
int main ()
{
  Piste *pPiste;										//Piste tyyppisen osoittimen esittely 
  for (int i=0;i<KPL;i++){  								//testausta varten useampi olio
 	pPiste=new Piste;									//uusi piste vapaaseen muistiin, sijaintitieto osoittimeen
	pPiste->naytaPisteenSijaintiTiedot();			    //pisteen tietojen tulostus n�yt�lle 
	siirraYhdellaYksikolla(pPiste);						//kutsutaan koordinaateja siirt�v�� funktiota, parametrina osoitin olioon
	pPiste->naytaPisteenSijaintiTiedot();			    //pisteen tietojen tulostus n�yt�lle 	
	delete pPiste;										//muistin vapautus eli olion tuhoaminen
  	cout<<endl;	
  }
  cin.get();
  return 0;
}

//funktio, joka siirt�� olion koordinaatteja yhdell� yksik�ll�
//-parametrina osoitin olioon
void siirraYhdellaYksikolla(Piste *pp){
	cout<<"Siirto"<<endl;
	int x=pp->palautaX();			//olion x -koordinaatti
	int y=pp->palautaY();			//olion y -koordinaatti
	pp->vaihdaX(x+1);				//lis�t��n x -koordinaattiin yksi yksikk�
	pp->vaihdaY(y+1);				//lis�t��n y -koordinaattiin yksi yksikk�
}
