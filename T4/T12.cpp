/*file: T12.cpp
  desc: C++, osa4, T12
        "Toteuta kopiomuodostin Henkilo-luokkaan; henkil�n ominaisuuksia ovat syntym�-aika ja nimi."
  date: 3.7.2018
  auth: Maarit Parkkonen
  
  Lis�ys: Kokeilin my�s toteutusta: Henkilo.cpp, Henkilo.h ja Henkilo_main.cpp, hyvin toimi.
*/

//luokkakirjastot
#include <iostream>
#include <string.h>	
	
using namespace std;

//Henkilo -luokka
class 	Henkilo{
	private:								//attribuutit, yksityisi�
	int* syntymapaiva;						//syntym�-aika, indeksit 0=pp 1=kk 2=vvvvv, osoitin
	char* nimi;								//henkil�n nimi, osoitin
	
	public:									//metodit, julkisia
	Henkilo(){};							//konstruktori ja sen "tyhj�" toteutus
	Henkilo(const Henkilo &h);				//kopiomuodostin
	void naytaHenkilotiedot();				//tulostaa pisteen sijaintitiedot n�yt�lle
	void annaHenkilotiedot(char *n, int pp, int kk, int vvvvv);	//henkil�tietojen anto olion attribuutteille
	void annaNimi(char *n);					//nimimerkkijonon luonti ja alkuosoitteen sijoitus osoittimeen	
	void muutaNimi(char *n);				//aiemman merkkijonon vapautus ja uuden nimen ohjaus merkkijonon luontiin
	~Henkilo();								//tuhoaja
};

//kopiomuodostin
Henkilo::Henkilo(const Henkilo &h){
	annaNimi(h.nimi);			//siirt�� nimen k�sittelyn annaNimi -metodille	
	syntymapaiva=h.syntymapaiva;
	cout << "\tHenkilon "<<h.nimi<<" tiedot kopioitu"<<endl; 	
}

//henkil�tietojen anto olion attribuutteille
void Henkilo::annaHenkilotiedot(char *n, int pp, int kk, int vvvv){
	annaNimi(n);				//siirt�� nimen k�sittelyn annaNimi -metodille
	syntymapaiva=new int[3];	//osoitin uuteen kokonaislukutaulukkoon
	*(syntymapaiva)=pp;			//tiedot taulukkoon: [0]=p�iv�
	*(syntymapaiva+1)=kk;		//[1]=kuukausi
	*(syntymapaiva+2)=vvvv;		//[2]=vuosi
}

//muuttaa henkil� -olion nimen
void Henkilo::muutaNimi(char *n){
	delete nimi;				//aiemman merkkijonon tilanvapautus
	annaNimi(n);				//siirt�� nimen k�sittelyn annaNimi -metodille
}

//luo merkkijonotaulukon johon osoittaa henkil� -olion nimi -osoittimella
void Henkilo::annaNimi(char *n){
	int pituus = strlen(n);		//nimen pituus
	nimi = new char[pituus];	//osoitin uuteen merkkijonoon
	strcpy(nimi, n);			//merkkien kopiointi
}

//tulostaa henkil�tiedot n�yt�lle
void Henkilo::naytaHenkilotiedot(){
	cout<<"\tnimi: "<<nimi<<endl;
	cout<<"\tSyntynyt: "<<*(syntymapaiva)<<"."<<*(syntymapaiva+1)<<"."<<*(syntymapaiva+2)<<endl;
}


//tuhoaja, poistaa henkil�n
Henkilo::~Henkilo(){
	cout<<"Poistan henkilon"<<endl;	
}

//p��luokka
int main ()
{
  //henkil�n luonti
  cout<<"Luodaan henkilo1 "<<endl;   
  Henkilo henkilo1;
  henkilo1.annaHenkilotiedot("Matti",12,5,2004);
  henkilo1.naytaHenkilotiedot();
  
  //henkil�n luonti kopioimallla
  cout<<"Kopioidaan henkilo1 henkilo2 -olioksi "<<endl; 
  Henkilo henkilo2(henkilo1);
  cout<<"Henkilo2 tiedot:"<<endl;
  henkilo2.naytaHenkilotiedot();
  
  cout<<"Muutetaan henkilo2:n nimi"<<endl;  
  henkilo2.muutaNimi("katti");
  cout<<"Henkilo2 tiedot:"<<endl;
  henkilo2.naytaHenkilotiedot();
  cout<<"Henkilo1 tiedot sailyy (koska eri olio) "<<endl; 
  cout<<"Henkilo1 tiedot:"<<endl;
  henkilo1.naytaHenkilotiedot();
  
  //henkil�iden poistaminen
  henkilo1.~Henkilo();
  henkilo2.~Henkilo();
  
  cin.get();
  return 0;
}
