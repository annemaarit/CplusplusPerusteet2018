/*file: T7.cpp
  desc: C++, osa6, T7
        "Luo Pelikortti-luokka ja toteuta korttipinkkataulukko, jossa on 52 pelikorttia. 
		Jaa Pelaaja-oliolle viisi korttia. Sovella mielesi mukaan..."
		"Pisteet -peli, jossa suuremman arvoisen pelikäden saanut pelaaja voittaa.
			- korttien numeropisteet painotetaan maakohtaisella arvolla 
			- pelaajina käyttäjä ja konevastustaja"
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <string.h>	
#include <stdlib.h>     // srand, rand
#include <stdio.h>      // NULL
#include <time.h>       // time
	
using namespace std;

//maa vakiot
const unsigned short RUUTU=1;
const unsigned short RISTI=2;
const unsigned short PATA=3;
const unsigned short HERTTA=4;


//Pelikortti -luokka
class Pelikortti{
	private:
	unsigned short maa;						//maa: ruutu 1, risti 2, pata 3 ja hertta 4
	unsigned short arvo;					//numeroarvo: 1-13 (ässä=1, 2-10, jätkä=11, akka=12, kunkku=13)
	unsigned short pisteet;					//pistearvo: maa arvo x numeroarvo
	
	public:
	Pelikortti(){}							//konstruktori
	void alustaPelikortti(int m, int a){maa=m;arvo=a;pisteet=this->laskePisteet();} //pelikortin tietojen alustus
	void tulostaKortti();					//pelikortin tietojen tulostus
	int laskePisteet(){if (arvo==1) return (14*maa); else return (arvo*maa);}		//pelikortin pistearvon laskenta, palauttaa tuloksen
	int kerroPisteet(){return pisteet;}		//palauttaa pelikortin pistearvon
};

//yksittäisen pelikortin tietojen tulostus
void Pelikortti::tulostaKortti(){
	switch (maa){							//maan nimi
		case RUUTU:cout<<"Ruutu\t";break;
		case RISTI:cout<<"Risti\t";break;
		case PATA:cout<<"Pata\t";break;
		case HERTTA:cout<<"Hertta\t";break;
	}
	if ((arvo!=1)&&(arvo<=10))			    //numeroarvot 2-10 numerona
		cout<<arvo;
	else if (arvo==1)						//Ässä
		cout<<"ASSA";
	else if (arvo==11)						//sotilas
		cout<<"SOTILAS";	
	else if (arvo==12)
		cout<<"AKKA";						//akka
	else if (arvo==13)
		cout<<"KUNKKU";						//kunkku
	cout<<"\tpisteet: "<<pisteet;			//kortin pistearvo
	cout<<endl;
}

//Korttipakka -luokka
class Korttipakka{
	private:
	Pelikortti * pakka;						//osoitin korttipakkataulukkoon
	int jaettu;								//jaettujen korttien määrä
	
	public:
	Korttipakka();							//konstruktori
	void tulostaPakka(){for(int i=0;i<52;i++) pakka[i].tulostaKortti();} 			//koko pakan korttien tulostus
	void sekoitaPakka();					//pakan korttien sekoittaminen satunnaiseen järjestykseen
	Pelikortti jaaKortti();					//palauttaa vuorossa olevan kortin
	~Korttipakka(){delete [] pakka;} 		//tuhoaja
};

//konstruktori, joka luo pelikorteista taulukon ja pyytää alustamaan taulukon pelikorteille arvot
Korttipakka::Korttipakka(){
	pakka=new Pelikortti[52];				//pelikorttitaulukko
	int i,j;								//i=maa, j=numeroarvo
	int index=0;							//sijainti taulukossa
	for(i=1;i<=4;i++)						//maiden läpikäynti
		for(j=1;j<=13;j++){					//numeroarvojen läpikäynti
			pakka[index].alustaPelikortti(i,j); //yksittäisen pelikortin alustus
			index++;						//seuraava taulukon indeksipaikka
		}
	jaettu=0;								//jaettuja kortteja on nolla
}

//sekoittaa pakan kortit vaihtamalla kahden satunnaisen kortin paikkaa 1000 kertaa
void Korttipakka::sekoitaPakka(){
	int index1,index2;
	int i=0;
	Pelikortti apukortti;					//vaihtamisen apumuuttuja
 	srand (time(NULL));						//satunnaisluvun alustus järjestelmän kellosta
	do{
		index1=rand() % 52;					//arvotaan 1.satunnaisindeksi
		index2=rand() % 52;					//arvotaan 2.satunnaisindeksi
		apukortti=pakka[index1];			//otetaan kortti talteen 1.satunnaisindeksistä
		pakka[index1]=pakka[index2];		//vaihdetaan korttien paikkaa
		pakka[index2]=apukortti;
		i++;
	}while(i<1000);							//toistetaan 1000 kertaa
	jaettu=0;								//nollataan jaettujen korttien määrä
}

//palauttaa pakasta vuorossa olevan kortin
Pelikortti Korttipakka::jaaKortti(){
	//cout<<"jakokohta "<<jaettu<<endl;
	jaettu=jaettu+1;						//lisää jaettujen korttien määrää
	return pakka[jaettu-1];					//palauttaa kortin
}

//Pelaaja -luokka
class Pelaaja{
	private:
	string nimi;							//pelaajan nimi
	Pelikortti * kasi;						//pelikäsi eli pelaajan kortit
	
	public:
	Pelaaja(string n){nimi=n;kasi=NULL;}			//konstruktori
	void otaKortti(Pelikortti kortti, int index);	//sijoittaa uuden kortin pelikäteen
	void tulostaKortit();							//tulostaa pelikäden
	int laskeYhteisPisteet();						//laskee koko käden arvon
	~Pelaaja(){}									//tuhoaja
};

//sijoittaa parametrina saadun kortin pelikäteen eli taulukkoon tiettyyn index kohtaan
void Pelaaja::otaKortti(Pelikortti kortti, int index){
	if (index==0){							//jos käden eka kortti
		if (kasi!=NULL)						//jos käsi ei tyhjä
			delete [] kasi;					//tyhjennetään käsi (tuhotaan taulukko)
		kasi=new Pelikortti[5];				//varataan uusi taulukko
	}
	kasi[index]=kortti;						//sijoitetaan korttiolio taulukkoon
}

//tulostaa pelaajan pelikäden kortit
void Pelaaja::tulostaKortit(){
	cout<<"\n** "<<nimi<<" kortit:\n"; 
	for (int i=0;i<5;i++)					//läpikäy pelaajan kortit
		kasi[i].tulostaKortti();			//pyytää Pelikortti oliolta tulostusta
	cout<<"*******************************************************************\n";
}

//laskee pelaajan korttien yhteispisteet ja tulostaa sekä palauttaa summan
int Pelaaja::laskeYhteisPisteet(){
	unsigned int summa=0;
	for (int i=0;i<5;i++)					//läpikäy pelaajan kortit
		summa=summa+kasi[i].kerroPisteet();	//lisää yksittäisen kortin pistearvon summaan
	cout<<"Yhteispisteet: "<<summa<<endl;	//tulostaa summan
	return summa;							//palauttaa summan
}


//pääluokka
int main ()
{
	unsigned int i;
	unsigned int tulos1, tulos2;			//pelaajien korttien summa
	int vastaus=0;							//kysymykseen jatketaanko pelaamista
	
	cout<<"***PISTEET -peli *****************************************************\n";
	cout<<"** Tervetuloa pelaamaan pisteet pelia, jossa\n";
	cout<<"** viiden kortin yhteispistearvo ratkaisee voittajan.\n";
	cout<<"**\n";
	cout<<"** Yhden kortin pisteet lasketaan seuraavasti:\n";	
	cout<<"** \t- maan arvo * kortin numeroarvo \n";
	cout<<"** \t- maan arvo: RUUTU 1, RISTI 2, PATA 3 ja HERTTA 4\n";
	cout<<"** \t- numeroarvo: 2-10, soturi 11, akka 12, kuningas 13 ja assa 14\n";	
	cout<<"**********************************************************************\n";
	
		
	Korttipakka pelipakka;					//luodaan uusi pakka
	//pelipakka.tulostaPakka(); 			//testausta varten

	string pelinimi;						//pelaajan nimi
 	cout<<"\nKirjoita pelinimesi: ";  
	cin>>pelinimi;
	
	Pelaaja pelaaja1(pelinimi);				//pelaajan olio
	Pelaaja pelaaja2("Vastustaja");			//konevastustajan olio
	
	do{
	  pelipakka.sekoitaPakka();		
	  //pelipakka.tulostaPakka();
	  
	  for (i=0;i<5;i++)						//pelaajille omat korttikädet
		pelaaja1.otaKortti(pelipakka.jaaKortti(),i);
	  for (i=0;i<5;i++)
		pelaaja2.otaKortti(pelipakka.jaaKortti(),i);
	
	  pelaaja1.tulostaKortit();				//käsien tulostus ja pisteiden laskenta
	  tulos1=pelaaja1.laskeYhteisPisteet();
	  pelaaja2.tulostaKortit();
	  tulos2=pelaaja2.laskeYhteisPisteet();
	
	  cout<<endl;
	  if (tulos1>tulos2)					//voittajan julistus
		cout<<"ONNEA, voitit pelin!\n";
  	  else if (tulos2>tulos1)
		cout<<"PAHOITTELEN, vastustaja voitti.\n";
	  else
		cout<<"Tasapeli!\n";
		
	  cout<<"\nHaluatko jatkaa: 1 vai lopetatko pelaamisen: 2?\n";
	  cin>>vastaus;
	}while (vastaus!=2);					//pelataan, kunnes käyttäjä haluaa lopettaa
	
	pelipakka.~Korttipakka();				//tuhotaan oliot
	pelaaja1.~Pelaaja();
	pelaaja2.~Pelaaja();	
  	cin.get();
  	return 0;
}
