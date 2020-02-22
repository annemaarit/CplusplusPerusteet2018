/*file: T8.cpp
  desc: C++, osa4, T8
        "Toteuta Piste-luokka, joka kuvaa XY-koordinaatiston pistettä.
		Lisää luokkaan muodostimet ja tuhoaja"
  date: 2.7.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <string.h>	
	
using namespace std;

//Piste -luokka
class 	Piste{
	private:								//attribuutit, yksityisiä
	int koordinaattiX;						//x-koordinaatti
	int koordinaattiY;						//y-koordinaatti
	int pisteenArvo();					    //yksityinen metodi, palauttaa satunnaisluvun
	
	public:									//metodit, julkisia
	Piste();								//konstruktori
	Piste(int x, int y);					//parametrisoitu konstrukstori
	void naytaPisteenSijaintiTiedot();		//tulostaa pisteen sijaintitiedot näytölle
	int palautaX();							//palauttaa X-koordinaatin arvon	
	int palautaY();							//palauttaa Y-koordinaatin arvon
	void vaihdaX(int x);					//vaihtaa X-koordinaatin arvon
	void vaihdaY(int y);					//vaihtaa Y-koordinaatin arvon
	~Piste();								//tuhoaja
};

//konstruktori, joka muodostaa ja alustaa origossa sijaitsevan pisteen
Piste::Piste(){
	koordinaattiX=0;
	koordinaattiY=0;
}

//konstruktori, muodostaa uuden piste -olion
//ja alustaa parametreina saamillaan arvoilla
Piste::Piste(int x, int y){
	koordinaattiX=x;				
	koordinaattiY=y;
}

//tulostaa pisteen sijaintitiedot näytölle
void Piste::naytaPisteenSijaintiTiedot(){
	cout<<"X-koordinaatti: "<<koordinaattiX<<endl;
	cout<<"\tY-koordinaatti: "<<koordinaattiY<<endl;
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

//pääluokka
int main ()
{
  //piste -olioiden luonti
  Piste piste1;
  Piste piste2(12,67);
  
  //pisteiden tietojen tulostus näytölle
  cout<<endl;
  cout<<"Piste1: ";
  piste1.naytaPisteenSijaintiTiedot(); 
  cout<<"Piste2: ";
  piste2.naytaPisteenSijaintiTiedot();  
  
  //vaihdetaan sijaintitietoja
  piste1.vaihdaX(32);
  piste2.vaihdaY(13);
  
  //pisteiden tietojen tulostus näytölle
  cout<<"\nMuokatut pisteet:"<<endl;
  cout<<"Piste1: ("<<piste1.palautaX()<<","<<piste1.palautaY()<<")"<<endl; 
  cout<<"Piste2: ("<<piste2.palautaX()<<","<<piste2.palautaY()<<")"<<endl<<endl; 
  
  //pisteiden poistaminen
  piste1.~Piste();
  piste2.~Piste();
  
  cin.get();
  return 0;
}
