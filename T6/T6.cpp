/*file: T6.cpp
  desc: C++, osa6, T6
        "Luo työntekijää kuvaava luokka. Työntekijä voi ottaa vuodeksi kerrallaan haltuunsa yhden yrityksen autoista. Toteuta toimiva ohjelma"
        "auto -> pvm = sisältymis-suhde"
        "tyontekija -> auto = assosiatiivinen-suhde"
  date: 3.8.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <string.h>	
#include <time.h> 
	
using namespace std;

//päivämäärä luokka
class Pvm{
	private:														//yksityiset attribuutit
	unsigned int paiva;
	unsigned int kuukausi;
	unsigned int vuosi;
	
	public:															//julkiset metodit
	Pvm(){};														//konstruktori
	void asetaPvm();												//päivämäärän asetus nykyhetken mukaan
	void asetaPvm(int p, int k, int v){paiva=p;kuukausi=k,vuosi=v;} //päivämäärän asetus parametrien mukaan
	void tulostaPvm(){cout<<paiva<<"."<<kuukausi<<"."<<vuosi;}		//päiväyksen tulostus
	~Pvm(){cout<<"Palautuspaivays ";tulostaPvm();cout<<" on tuhottu.\n";}	//tuhoaja
};

//sijoittaa pvm olion attribuutteihin nykypäivä+1vuosi -arvot (vuosi lisätään sekuntteina)
void Pvm::asetaPvm(){
    time_t nyt;             										//sekunttiluku
    struct tm *aika;        										//päivämäärätietue
    nyt=time(&nyt)+31536000;    									//haetaan tämänhetkinen päivämäärä ja lisätään yhden vuoden sekunnit
    aika = localtime(&nyt); 										//muutetaan päivämäärä järkevään muotoon
    paiva=aika->tm_mday;											
	kuukausi=aika->tm_mon + 1;										//kuukaudet alkavat nollasta
    vuosi=1900 + aika->tm_year; 
}

//Auto -luokka
class Auto{
	private:														//yksityiset attribuutit
	string rekisteri; 												//rekisterinumero
	string malli;	  												//mallinimi
	Pvm palautus;	 												//palautuspäivämäärä olio
	
	public:															//julkiset metodit
	Auto(string r, string m){rekisteri=r;malli=m;cout<<malli<<" "<<rekisteri<<" on luotu.\n";}	//konstruktori
	void merkitsePalautusPvm(){palautus.asetaPvm();}											//alustaa palautuspäivämäärän nykyhetken perusteella
	void merkitsePalautusPvm(int p,int k,int v){palautus.asetaPvm(p,k,v);}						//alustaa palautuspäivämäärän parametrien perusteella
	void tulostaTiedot(){cout<<"Auton "<<malli<<" "<<rekisteri<<" palautuspaivamaara on ";palautus.tulostaPvm();cout<<endl;}	//tulostaa auton tiedot
	~Auto(){cout<<"\nAuto "<<rekisteri<<" on tuhottu.\n";}			//tuhoaja
};

//Työntekijä -luokka
class Tyontekija{
	private:														//yksityiset attribuutit
	string nimi;													//henkilön nimi
	Auto* osAuto;													//osoitin käytössä olevaan autoon
	
	public:
	Tyontekija(string n){nimi=n;cout<<"Tyontekija "<<nimi<<" on luotu\n";}										//konstruktori
	void otaAutoKayttoon(Auto* osCar, int p, int k, int v){osAuto=osCar;osAuto->merkitsePalautusPvm(p,k,v);}	//osoitetaan työntekijälle auto ja alustetaan palautus parametreilla
	void otaAutoKayttoon(Auto* osCar){osAuto=osCar;osAuto->merkitsePalautusPvm();}								//osoitetaan työntekijälle auto ja alustetaan nykyhetken perusteella
	void tulostaTyontekijanAutoTiedot(){cout<<nimi<<": ";osAuto->tulostaTiedot();}							    //tulostetaan työntekijän ja auton tiedot
	~Tyontekija(){cout<<"Tyontekija "<<nimi<<" on tuhottu\n";}													//tuhoaja
};

//pääluokka
int main ()
{
  	//autojen luonti	
  	Auto auto1("BRJ-753","BMV");
  	Auto auto2("XHE-159","Peugeot");  
  	cout<<endl;
	  
	//työntekijöiden luonti
	Tyontekija hlo1("Minni Hiiri");
	Tyontekija hlo2("Pelle Peloton");  	
  	cout<<endl;
	
	//osoitetaan auto työntekijän käyttöön ja alustetaan palautuspäivä
    hlo1.otaAutoKayttoon(&auto1);					//ottaa auton käyttöön heti
    hlo2.otaAutoKayttoon(&auto2,14,9,2019);			//ottaa auton käyttöön 14.9.2018 eli parametreina vastaava palautuspvm
	
	//tulostetaan työntekijän ja hänen autonsa tiedot
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
