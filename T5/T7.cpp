/*file: T7.cpp
  desc: C++, osa5, T7
        "Toteuta ohjelma, jossa Piste-taulukko viedään funktiolle; 
		siirrä funktion sisällä kunkin pisteen X-arvoa kymmenen yksikköä. 
		Tulosta pisteet ennen ja jälkeen funktion."
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
	Piste(const Piste &piste);				  //kopiomuodostin
	void naytaPisteenSijaintiTiedot();		  //tulostaa pisteen sijaintitiedot näytölle
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

//tulostaa pisteen sijaintitiedot näytölle
void Piste::naytaPisteenSijaintiTiedot(){
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

//funktio, joka siirtää taulukon olioiden X-koordinaatteja annetun yksikkömäärän verran
void siirraXKoordinaatteja(Piste *pp,int maara);

void tulostaTaulukosta(Piste *pp);

const short KPL=5;								//pisteiden lukumäärä

//pääluokka
int main ()
{
  	//piste -olioiden luonti
  	Piste * pisteet;							 //piste tyyppisen osoittimen esittely
  	pisteet=new Piste[KPL];						 //taulukon ja sen sisältämien pisteiden luonti vapaaseen muistiin, sijainti osoittimeen
  
  	cout<<"Taulukon pisteiden koordinaatit: "<<endl;	
 	tulostaTaulukosta(pisteet); 				//koordinaatit ennen siirtoa
	siirraXKoordinaatteja(pisteet,10);			//x-koordinaattien siirto
 	tulostaTaulukosta(pisteet);					//koordinaatit siirron jälkeen
  
  	delete[] pisteet;							//pisteiden poistaminen
  
  	cin.get();
  	return 0;
}

//funktio, joka siirtää taulukon olioiden X-koordinaatteja annetun yksikkömäärän verran
//-parametrina osoitin oliotaulukkoon ja siirron lukumäärä
void siirraXKoordinaatteja(Piste *pp,int maara){
	cout<<"Siirran X -koordinaatteja "<<maara<<" yksikkoa."<<endl;
	int x;
	for(int j=0;j<KPL;j++){
		x=pp[j].palautaX();						//olion x -koordinaatti
		pp[j].vaihdaX(x+maara);					//lisätään x -koordinaattiin yksikköjä
	}			
}

//tulostaa taulukon olioiden tiedot näytölle
void tulostaTaulukosta(Piste *pp){
  	for (int i=0;i<KPL;i++) 				    //taulukon läpikäynti
		pp[i].naytaPisteenSijaintiTiedot();     //pisteen tietojen tulostus näytölle 	
  	cout<<endl; 	
}
