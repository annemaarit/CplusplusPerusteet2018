/*file: T5.cpp
  desc: C++, osa4, T5
        "Toteuta murtoluku -luokka"
  date: 2.7.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <string.h>	
	
using namespace std;

//Murtoluku -luokka
class Murtoluku { 
private:
	int osoittaja;    					// osoittaja
  	int nimittaja;    					//nimitt�j�

public:   
	Murtoluku(int o, int n);			//konstruktori
	void naytaMurtoluku();				//tulostaa murtoluvun n�yt�lle
	void vaihdaOsoittaja(int o);		//vaihtaa osoittajaksi parametrin arvon
	void vaihdaNimittaja(int n);		//vaihtaa nimitt�j�ksi parametrin arvon
	int palautaOsoittaja();				//palauttaa osoittajan arvon
	int palautaNimittaja();				//palauttaa nimitt�j�n arvon
	double desimaalilukuna();			//palauttaa murtoluvun desimaalilukuna
	~Murtoluku();						//tuhoaja
};

//konstruktori, alustaa parametreilla luokan attribuutit
Murtoluku::Murtoluku(int o, int n) {
	osoittaja=o;     						//olion arvojen alustus parametreilla   
    nimittaja=n;      
	//cout<<"Loin uuden murtoluvun"<<endl; 
}

//tulostaa murtoluku -olion tiedot n�yt�lle murtolukumuodossa
void Murtoluku::naytaMurtoluku(){
	cout<<osoittaja<<"/"<<nimittaja<<endl;
}  

//vaihtaa olion osoittajaksi parametrin arvon
void Murtoluku::vaihdaOsoittaja(int o){
	cout<<"\nVaihdan osoittajan"<<endl;
	osoittaja=o;
}

//vaihtaa olion nimitt�j�ksi parametrin arvon
void Murtoluku::vaihdaNimittaja(int n){
	cout<<"\nVaihdan nimitt�j�n"<<endl;
	nimittaja=n;
}

//palauttaa olion osoittajan arvon
int Murtoluku::palautaOsoittaja() {
	return osoittaja; 
}  

//palauttaa olion nimitt�j�n arvon
int Murtoluku::palautaNimittaja() {
	return nimittaja; 
}     

//palauttaa murtoluku -olion arvoista lasketun desimaaliluvun      
double Murtoluku::desimaalilukuna() { 
	return (double) osoittaja/nimittaja; 
	} 

//tuhoaa murtoluku -olion
Murtoluku::~Murtoluku(){
	cout<<"Tuhoan murtoluvun: ";
	naytaMurtoluku();
}
//p��luokka
int main ()
{
	//murtoluku -olioiden luonti
	Murtoluku luku1(1,6);
	Murtoluku luku2(56,160);
	
	//murtolukujen tulostus n�yt�lle
	cout<<"Murtoluku1: ";
	luku1.naytaMurtoluku();
	cout<<"Murtoluku2: ";
	luku2.naytaMurtoluku();	
	
	//luku1 -olion osoittajan arvon muuttaminen
	luku1.vaihdaOsoittaja(5);
	cout<<"Murtoluku1: ";
	luku1.naytaMurtoluku();

	//luku2 -olion nimitt�j�n arvon muuttaminen	
	luku2.vaihdaNimittaja(100);
	cout<<"Murtoluku2: ";
	luku2.naytaMurtoluku();	
	
	//olioiden yksitt�isen attribuutin arvon tulostus n�yt�lle
	cout<<"\nMurtoluku1:n osoittaja on "<<luku1.palautaOsoittaja()<<endl;
	cout<<"Murtoluku2:n nimitt�j� on "<<luku2.palautaNimittaja()<<endl<<endl;	
	
	//murtoluku -olion arvoista lasketun desimaaliluvun tulostus n�yt�lle
	cout<<"Murtoluvun1 desimaaliluku on: "<<luku1.desimaalilukuna()<<endl;
	cout<<"Murtoluvun2 desimaaliluku on: "<<luku2.desimaalilukuna()<<endl<<endl;
	
	//olioiden tuhoaminen
	luku1.~Murtoluku();
	luku2.~Murtoluku();
	
  cin.get();
  return 0;
}
