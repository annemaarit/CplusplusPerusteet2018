/*file: T2.cpp
  desc: C++, osa6, T2
        "Toteuta Kuvio-luokka ja johda siitä Suorakaide- ja Ympyra-luokat"
  date: 3.8.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <cmath>
	
using namespace std;

//Kuvio -luokka
class Kuvio{
	private:
	int x;				//sijainti X-koordinaatti 
	int y;				//sijainti Y-koordinaatti

	public:
	Kuvio(int xSijainti, int ySijainti){x=xSijainti;y=ySijainti;}	//parametrisoitu konstruktori
	~Kuvio(){}														//tuhoaja
	float virtual pintaAla()=0;										//puhdas virtuaalinen pinta-alan laskenta metodi
	void siirraKuvio(int uusiX,int uusiY){x=uusiX;y=uusiY;}			//koordinaattien muuttaminen
	int kerroX(){return x;}											//palauttaa X-koordinaatin arvon
	int kerroY(){return y;}											//palauttaa Y-koordinaatin arvon
};

//Ympyrä -luokka
class Ympyra:public Kuvio{
	private:
	float sade;
	//perityt x,y vastaavat ympyrän keskipistettä

	public:											//metodit, julkisia
	Ympyra(float s,int xsijainti, int ysijainti):Kuvio(xsijainti,ysijainti),sade(s){sade=s;cout<<"Ympyra luotu\n";} //alustettu konstruktori
	~Ympyra(){cout<<"Ympyra tuhottu\n";}			//tuhoaja
	float pintaAla(){return M_PI*(pow(sade,2));}	//pinta-alan laskenta
	float kerroSade(){return sade;}					//palauttaa säteen arvon
};

//Suorakaide -luokka
class Suorakaide:public Kuvio{
	private:										//attribuutit, yksityisiä
	float korkeus;
	float leveys;
	//perityt x,y vastaavat suorakaiteen vasenta yläkulmaa

	public:						//metodit, julkisia
	Suorakaide(float k,float l, int xsijainti, int ysijainti):Kuvio(xsijainti, ysijainti),korkeus(k),leveys(l){korkeus=k;leveys=l;cout<<"Suorakaide luotu\n";} //alustettu konstruktori
	~Suorakaide(){cout<<"Suorakaide tuhottu\n";}	//tuhoaja
	float pintaAla(){return korkeus*leveys;}		//pinta-alan laskenta
	float kerroKorkeus(){return korkeus;}			//palauttaa korkeuden arvon
	float kerroLeveys(){return leveys;}				//palauttaa leveyden arvon
}; 

//pääluokka
int main ()
{
  	//olioiden luonti
  	Ympyra ympyra1(12,23,100);						//ympyrä (säde, sijaintiX, sijaintiY)
  	Ympyra ympyra2(2.5,0,10);
  	Suorakaide skaide1(12,20,22,80);				//suorakaide (korkeus, leveys, sijaintiX, sijaintiY);
  	Suorakaide skaide2(0.56,5.7,110,234);		
  	cout<<endl;

  	//pinta-alojen laskenta
  	cout<<"Ympyran (sade: "<<ympyra1.kerroSade()<<") pinta-ala on "<<ympyra1.pintaAla()<<endl;
  	cout<<"Ympyran (sade: "<<ympyra2.kerroSade()<<") pinta-ala on "<<ympyra2.pintaAla()<<endl;
  	cout<<"Suorakaiteen (k: "<<skaide1.kerroKorkeus()<<" l: "<<skaide1.kerroLeveys()<<") pinta-ala on "<<skaide1.pintaAla()<<endl;
 	cout<<"Suorakaiteen (k: "<<skaide2.kerroKorkeus()<<" l: "<<skaide2.kerroLeveys()<<") pinta-ala on "<<skaide2.pintaAla()<<endl;
 	cout<<endl;
	   
  	//olioiden tuhoaminen
  	ympyra1.~Ympyra();
  	ympyra2.~Ympyra();
  	skaide1.~Suorakaide();
  	skaide2.~Suorakaide();
  
  	cin.get();
  	return 0;
}


