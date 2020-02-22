/*file: T6.cpp
  desc: C++, osa6, T6
        "Luo ty�ntekij�� kuvaava luokka. Ty�ntekij� voi ottaa vuodeksi kerrallaan haltuunsa yhden yrityksen autoista. Toteuta toimiva ohjelma"
        "auto -> pvm = sis�ltymis-suhde"
        "tyontekija -> auto = assosiatiivinen-suhde"
  date: 3.8.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <string.h>	
#include <time.h> 
	
using namespace std;

//p�iv�m��r� luokka
class Pvm{
	private:														//yksityiset attribuutit
	unsigned int paiva;
	unsigned int kuukausi;
	unsigned int vuosi;
	
	public:															//julkiset metodit
	Pvm(){};														//konstruktori
	void asetaPvm();												//p�iv�m��r�n asetus nykyhetken mukaan
	void asetaPvm(int p, int k, int v){paiva=p;kuukausi=k,vuosi=v;} //p�iv�m��r�n asetus parametrien mukaan
	void tulostaPvm(){cout<<paiva<<"."<<kuukausi<<"."<<vuosi;}		//p�iv�yksen tulostus
	~Pvm(){cout<<"Palautuspaivays ";tulostaPvm();cout<<" on tuhottu.\n";}	//tuhoaja
};

//sijoittaa pvm olion attribuutteihin nykyp�iv�+1vuosi -arvot (vuosi lis�t��n sekuntteina)
void Pvm::asetaPvm(){
    time_t nyt;             										//sekunttiluku
    struct tm *aika;        										//p�iv�m��r�tietue
    nyt=time(&nyt)+31536000;    									//haetaan t�m�nhetkinen p�iv�m��r� ja lis�t��n yhden vuoden sekunnit
    aika = localtime(&nyt); 										//muutetaan p�iv�m��r� j�rkev��n muotoon
    paiva=aika->tm_mday;											
	kuukausi=aika->tm_mon + 1;										//kuukaudet alkavat nollasta
    vuosi=1900 + aika->tm_year; 
}

//Auto -luokka
class Auto{
	private:														//yksityiset attribuutit
	string rekisteri; 												//rekisterinumero
	string malli;	  												//mallinimi
	Pvm palautus;	 												//palautusp�iv�m��r� olio
	
	public:															//julkiset metodit
	Auto(string r, string m){rekisteri=r;malli=m;cout<<malli<<" "<<rekisteri<<" on luotu.\n";}	//konstruktori
	void merkitsePalautusPvm(){palautus.asetaPvm();}											//alustaa palautusp�iv�m��r�n nykyhetken perusteella
	void merkitsePalautusPvm(int p,int k,int v){palautus.asetaPvm(p,k,v);}						//alustaa palautusp�iv�m��r�n parametrien perusteella
	void tulostaTiedot(){cout<<"Auton "<<malli<<" "<<rekisteri<<" palautuspaivamaara on ";palautus.tulostaPvm();cout<<endl;}	//tulostaa auton tiedot
	~Auto(){cout<<"\nAuto "<<rekisteri<<" on tuhottu.\n";}			//tuhoaja
};

//Ty�ntekij� -luokka
class Tyontekija{
	private:														//yksityiset attribuutit
	string nimi;													//henkil�n nimi
	Auto* osAuto;													//osoitin k�yt�ss� olevaan autoon
	
	public:
	Tyontekija(string n){nimi=n;cout<<"Tyontekija "<<nimi<<" on luotu\n";}										//konstruktori
	void otaAutoKayttoon(Auto* osCar, int p, int k, int v){osAuto=osCar;osAuto->merkitsePalautusPvm(p,k,v);}	//osoitetaan ty�ntekij�lle auto ja alustetaan palautus parametreilla
	void otaAutoKayttoon(Auto* osCar){osAuto=osCar;osAuto->merkitsePalautusPvm();}								//osoitetaan ty�ntekij�lle auto ja alustetaan nykyhetken perusteella
	void tulostaTyontekijanAutoTiedot(){cout<<nimi<<": ";osAuto->tulostaTiedot();}							    //tulostetaan ty�ntekij�n ja auton tiedot
	~Tyontekija(){cout<<"Tyontekija "<<nimi<<" on tuhottu\n";}													//tuhoaja
};

//p��luokka
int main ()
{
  	//autojen luonti	
  	Auto auto1("BRJ-753","BMV");
  	Auto auto2("XHE-159","Peugeot");  
  	cout<<endl;
	  
	//ty�ntekij�iden luonti
	Tyontekija hlo1("Minni Hiiri");
	Tyontekija hlo2("Pelle Peloton");  	
  	cout<<endl;
	
	//osoitetaan auto ty�ntekij�n k�ytt��n ja alustetaan palautusp�iv�
    hlo1.otaAutoKayttoon(&auto1);					//ottaa auton k�ytt��n heti
    hlo2.otaAutoKayttoon(&auto2,14,9,2019);			//ottaa auton k�ytt��n 14.9.2018 eli parametreina vastaava palautuspvm
	
	//tulostetaan ty�ntekij�n ja h�nen autonsa tiedot
	hlo1.tulostaTyontekijanAutoTiedot();
	hlo2.tulostaTyontekijanAutoTiedot(); 
	cout<<endl; 	
	
	//tuhotaan luodut oliot
    hlo1.~Tyontekija();
    hlo2.~Tyontekija();  
    auto1.~Auto();
    auto2.~Auto();
    
  	cin.get();
  	return 0;
}
