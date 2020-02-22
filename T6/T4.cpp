/*file: T4.cpp
  desc: C++, osa6, T4
        "Moottori kuuluu autoon. Toteuta tällainen ohjelma."
  date: 3.8.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <string.h>	
	
using namespace std;

//Moottori -luokka
class Moottori{
	private:												//attribuutit, yksityisiä
	string malli;											//mallinimi
	
	public:													//metodit, julkisia
	Moottori(){cout<<"Moottorin aihio on luotu.\n";}		//konstruktori
	void lisaaMallitieto(string model){malli=model;}		//annetaan moottorille sen mallin nimi 
	string kerroMalli(){return malli;}						//palauttaa moottorin mallin nimen
	~Moottori(){cout<<"Moottori "<<malli<<" on tuhottu\n";}	//tuhoaja
};

//Auto -luokka
class Auto{
	private:												//attribuutit, yksityisiä
	string rekisteri;										//rekisterinumero
	Moottori moottori;										//moottori -olio

	public:													//metodit, julkisia
	Auto(string r){rekisteri=r;cout<<"Auto "<<rekisteri<<" on luotu.\n\n";}		//parametrisoitu konstruktori
	void asennaMoottori(string model){moottori.lisaaMallitieto(model);}			//lisätään moottori -oliolle mallinimi
	string kerroRekisteri(){return rekisteri;}									//palauttaa rekisterinumeron
	void tulostaTiedot(){cout<<"Auton "<<rekisteri<<" moottorina on "<<moottori.kerroMalli()<<endl;}	//tulostaa auton ja sen moottorin tiedot
	~Auto(){cout<<"\nAuto "<<rekisteri<<" on tuhottu\n";}	//tuhoaja
};


//pääluokka
int main ()
{
  	//autojen luonti
	Auto auto1("XJR-556");
	Auto auto2("AKU-113");
	
	//asennetaan moottorit
	auto1.asennaMoottori("V8");
	auto2.asennaMoottori("PP100");
	
	//autojen tiedot
	auto1.tulostaTiedot();
	auto2.tulostaTiedot();
	
	//tuhotaan autot
	auto1.~Auto();
	auto2.~Auto();
  
  	cin.get();
  	return 0;
}
