/*file: T4.cpp
  desc: C++, osa4, T4
        "Muodosta Oppilas-luokka, jonka ominaisuuksia ovat oppilaskoodi ja sotu. 
		Toteuta myös metodit ja ohjelma, jossa luokkaa käytetään."
  date: 2.7.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <string.h>	
	
using namespace std;

//oppilas -luokka
class Oppilas{
	private:								//attribuutit, yksityisiä
	unsigned int koodi;						//oppilaskoodi
	string sotu;							//sosiaaliturvatunnus
	
	public:									//metodit, julkisia
	Oppilas(int k, string s);				//parametrisoitu konstrukstori
	~Oppilas();								//tuhoaja
	void naytaOppilaanTiedot();				//oppilaan tietojen tulostus näytölle
	string palautaSotu();					//oppilaskoodin mukaisen sotun arvon palautus		
};

//konstruktori, muodostaa uuden oppilas -olion
//parametreina saamillaan arvoilla
Oppilas::Oppilas(int k, string s){
	koodi=k;								//olion arvojen alustus parametreilla
	sotu=s;
	cout<<"Loin uuden oppilaan oppilaskoodilla: "<<koodi<<endl;
}

//tuhoaja, poistaa oppilaan
Oppilas::~Oppilas(){
	cout<<"Poistan oppilaan: "<<koodi<<endl;	
}

//tulostaa oppilaan tiedot näytölle
void Oppilas::naytaOppilaanTiedot(){
	cout<<"***OPPILAAN TIEDOT*****************************************"<<endl;
	cout<<"Oppilaskoodi: "<<koodi<<endl;
	cout<<"Sotu: "<<sotu<<endl;
}

//palauttaa oppilas -olion sotun arvon (tarkalleen osoittimen arvoon)
string Oppilas::palautaSotu(){
	return sotu;
}

//pääluokka
int main ()
{
  //oppilas -olioiden luonti
  Oppilas oppilas1(1236,"123456-1234");
  Oppilas oppilas2(45789,"290389-789S");  
  
  //oppilaiden tietojen tulostus näytölle
  cout<<endl;
  oppilas1.naytaOppilaanTiedot(); 
  oppilas2.naytaOppilaanTiedot();  
  
  //oppilaan sotun arvon palautus  
  cout<<"\nSotu -palautus: "<<oppilas1.palautaSotu()<<endl;
  cout<<"Sotu -palautus: "<<oppilas2.palautaSotu()<<endl<<endl;
  
  //oppilaan poistaminen
  oppilas1.~Oppilas();
  oppilas2.~Oppilas();
  
  cin.get();
  return 0;
}
