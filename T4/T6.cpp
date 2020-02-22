/*file: T6.cpp
  desc: C++, osa4, T6
        "Toteuta Kello-luokka metodeineen."
        Digitaalikello: 0:00:00 - 23.59.59
        
        P‰‰luokka testaa Kello -luokan toimintaa
  date: 2.7.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <string.h>	
	
using namespace std;


//Kello -luokka
class Kello { 

private:									//yksityisi‰
	//vakiot
	static const int sekVRK=86400;
	static const int sekTUNTI=3600;
	static const int sekMINUUTTI=60;
	//attribuutit
	unsigned short tunti;    				//0-24
  	unsigned short minuutit;    			//0-60
    unsigned short sekunnit; 				//0-60

public:   									//julkisia
	Kello();								//konstruktori, aika alkaa nollasta 0:00:00
	Kello(short h, short min, short s);		//parametrisoitu konstruktori, aika alkaa parametrien mukaisesti
	void ajastaKello(short h, short min, short s);
	void naytaAika();						//tulostaa kellon ajan n‰ytˆlle
	void vaihdaTunti(short h);				//vaihtaa tunnnit
	void vaihdaMinuutit(short min);			//vaihtaa minuutit
	void vaihdaSekunnit(short s);			//vaihtaa sekunnit
	void siirraKelloaSekunneissa(int s);	//siirt‰‰ kellonaikaa sekunttim‰‰r‰n verran
	~Kello();								//tuhoaja
};

//konstruktori, aika alustetaan alkamaan nollasta
Kello::Kello() {
	tunti=0;     						
    minuutit=0;
	sekunnit=0; 
	//cout<<"Loin uuden kellon"<<endl; 
}

//parametrisoitu konstruktori
Kello::Kello(short h,short min, short s){
	ajastaKello(h,min,s);
}

//kello -oliolle uudet aikaparametrit
void Kello::ajastaKello(short h,short min, short s){
	tunti=h;     					  
    minuutit=min;
	sekunnit=s;	
	
}

//tulostaa kellon ajan n‰ytˆlle
void Kello::naytaAika(){
	unsigned short ajat[3] = {tunti,minuutit,sekunnit}; //aputaulukko
	for (int i=0;i<3;i++){								//k‰yd‰‰n l‰pi ajan osat
		if (ajat[i]<10)									//jos lukuarvo < 10
			cout<<"0"<<ajat[i];							//tulostetaan nolla eteen
		else
			cout<<ajat[i];
		if (i!=2)										
			cout<<":";									//kahden ensimm‰isen luvun v‰liin :
		else
			cout<<endl;									//lopuksi rivinvaihto	
	}
}

//vaihtaa tunnnit
void Kello::vaihdaTunti(short h){
	tunti=h;
}

//vaihtaa minuutit
void Kello::vaihdaMinuutit(short min){
	minuutit=min;
}

//vaihtaa sekunnit
void Kello::vaihdaSekunnit(short s){
	sekunnit=s;
}

//siirt‰‰ digitaalista kelloa (00:00:00-23:59:59) parametrina annetun sekunttim‰‰r‰n verran
//-siirto voi olla taakse tai eteenp‰in
//-keskiyˆn ylitykset huomioidaan
void  Kello::siirraKelloaSekunneissa(int s){
	int summa=(tunti*sekTUNTI)+(minuutit*sekMINUUTTI)+sekunnit;		//kellon aika sekunteina
	
	if ((s>(sekVRK))||(s<(-sekVRK)))					//poistetaan siirtoparametrista ylim‰‰r‰iset vuorokaudet
		s=s%(sekVRK);
	
	//lasketaan siirretyn ajan sekunttim‰‰r‰
	if ((s<0)&&(summa+s<0))								//jos aika siirtyy taaksep‰in yli keskiyˆn eli nollan
		summa=(sekVRK)+s;								//siirryt‰‰n edelt‰v‰‰n vuorokauteen (huom! s on negatiivinen!)
	else									
		summa=summa+s;
	
	//muutetaan sekunttim‰‰r‰ kellon ajaksi
	int tuntia=0, minuuttia=0, sekunttia=0;				//apumuuttujat 
	if (summa/sekTUNTI>0){								//jos sis‰lt‰‰ tunteja
		tuntia=(int)summa/sekTUNTI;
		summa=summa%sekTUNTI;
	}
	if ((summa!=0)&&(summa/sekMINUUTTI>0)){				//jos sis‰lt‰‰ minuutteja
		minuuttia=(int)summa/sekMINUUTTI;
		summa=summa%sekMINUUTTI;
	}
	sekunttia=summa;									//loppu osa on sekuntteja
	if (tuntia>=24)										//jos kellon keskiyˆ ylitet‰‰n
		tuntia=tuntia-24;								//siirryt‰‰n seuraavaan vuorokauteen
	ajastaKello(tuntia,minuuttia,sekunttia);			//ajastetaan kello uuteen aikaan
}

//tuhoaa murtoluku -olion
Kello::~Kello(){
	cout<<"Tuhoan kellon"<<endl;
}
//p‰‰luokka
int main ()
{
	//olioiden luonti
	Kello kello0;
	Kello kello1;
	Kello kello2(10,22,34);
	Kello kello3(22,00,56);
	Kello kello4(23,07,06);
	
	//tulostus n‰ytˆlle
	cout<<"Kellonajat:"<<endl;
	cout<<"Kello0 ";
	kello0.naytaAika();	
	cout<<"Kello1 ";
	kello1.naytaAika();
	cout<<"Kello2 ";
	kello2.naytaAika();
	cout<<"Kello3 ";
	kello3.naytaAika();
	cout<<"Kello4 ";
	kello4.naytaAika();

	//kellon aikojen siirrot
	kello0.siirraKelloaSekunneissa(86399);		//default: 23:59:59
	kello1.siirraKelloaSekunneissa(-86401);		//default  23:59:59
	kello2.siirraKelloaSekunneissa(-3700);		//default: 9:20:54
	kello3.siirraKelloaSekunneissa(5);			//default: 22:01:01
	kello4.siirraKelloaSekunneissa(7205);		//default: 01:07:11	
	
	cout<<"\nSiirretyt kellon ajat: "<<endl;
	cout<<"Kello0 ";
	kello1.naytaAika();
	cout<<"Kello1 ";
	kello1.naytaAika();
	cout<<"Kello2 ";
	kello2.naytaAika();
	cout<<"Kello3 ";
	kello3.naytaAika();
	cout<<"Kello4 ";
	kello4.naytaAika();
	
	//olioiden tuhoaminen
	cout<<"\n";
	kello0.~Kello();	
	kello1.~Kello();
	kello2.~Kello();
	kello3.~Kello();
	kello4.~Kello();

  cin.get();
  return 0;
}
