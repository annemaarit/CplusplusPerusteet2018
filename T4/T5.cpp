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
  	int nimittaja;    					//nimittäjä

public:   
	Murtoluku(int o, int n);			//konstruktori
	void naytaMurtoluku();				//tulostaa murtoluvun näytölle
	void vaihdaOsoittaja(int o);		//vaihtaa osoittajaksi parametrin arvon
	void vaihdaNimittaja(int n);		//vaihtaa nimittäjäksi parametrin arvon
	int palautaOsoittaja();				//palauttaa osoittajan arvon
	int palautaNimittaja();				//palauttaa nimittäjän arvon
	double desimaalilukuna();			//palauttaa murtoluvun desimaalilukuna
	~Murtoluku();						//tuhoaja
};

//konstruktori, alustaa parametreilla luokan attribuutit
Murtoluku::Murtoluku(int o, int n) {
	osoittaja=o;     						//olion arvojen alustus parametreilla   
    nimittaja=n;      
	//cout<<"Loin uuden murtoluvun"<<endl; 
}

//tulostaa murtoluku -olion tiedot näytölle murtolukumuodossa
void Murtoluku::naytaMurtoluku(){
	cout<<osoittaja<<"/"<<nimittaja<<endl;
}  

//vaihtaa olion osoittajaksi parametrin arvon
void Murtoluku::vaihdaOsoittaja(int o){
	cout<<"\nVaihdan osoittajan"<<endl;
	osoittaja=o;
}

//vaihtaa olion nimittäjäksi parametrin arvon
void Murtoluku::vaihdaNimittaja(int n){
	cout<<"\nVaihdan nimittäjän"<<endl;
	nimittaja=n;
}

//palauttaa olion osoittajan arvon
int Murtoluku::palautaOsoittaja() {
	return osoittaja; 
}  

//palauttaa olion nimittäjän arvon
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
//pääluokka
int main ()
{
	//murtoluku -olioiden luonti
	Murtoluku luku1(1,6);
	Murtoluku luku2(56,160);
	
	//murtolukujen tulostus näytölle
	cout<<"Murtoluku1: ";
	luku1.naytaMurtoluku();
	cout<<"Murtoluku2: ";
	luku2.naytaMurtoluku();	
	
	//luku1 -olion osoittajan arvon muuttaminen
	luku1.vaihdaOsoittaja(5);
	cout<<"Murtoluku1: ";
	luku1.naytaMurtoluku();

	//luku2 -olion nimittäjän arvon muuttaminen	
	luku2.vaihdaNimittaja(100);
	cout<<"Murtoluku2: ";
	luku2.naytaMurtoluku();	
	
	//olioiden yksittäisen attribuutin arvon tulostus näytölle
	cout<<"\nMurtoluku1:n osoittaja on "<<luku1.palautaOsoittaja()<<endl;
	cout<<"Murtoluku2:n nimittäjä on "<<luku2.palautaNimittaja()<<endl<<endl;	
	
	//murtoluku -olion arvoista lasketun desimaaliluvun tulostus näytölle
	cout<<"Murtoluvun1 desimaaliluku on: "<<luku1.desimaalilukuna()<<endl;
	cout<<"Murtoluvun2 desimaaliluku on: "<<luku2.desimaalilukuna()<<endl<<endl;
	
	//olioiden tuhoaminen
	luku1.~Murtoluku();
	luku2.~Murtoluku();
	
  cin.get();
  return 0;
}
