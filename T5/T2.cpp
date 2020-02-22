/*file: T2.cpp
  desc: C++, osa5, T2
        "Luo ohjelma, jossa kysyt‰‰n float-taulukon kokoa ja varataan sitten tila taulukolle."
  date: 13.7.2018
  auth: Maarit Parkkonen
*/

#include <iostream>	   //cout,cin
#include <stdlib.h>    //rand
	
using namespace std;


//p‰‰luokka
int main ()
{

float * ptaulukko;				//osoitin liukulukutaulukkoon	
int kpl;						//taulukon koko
int i;							//indeksi
cout<<"Anna taulukon koko: ";	
cin>>kpl;						//luetaan koko muuttujaan
ptaulukko=new float[kpl];		//tilan varaus vapaasta muistista taulukolle

//testataan
for (i=0;i<kpl;i++)				//taulukkoon liukulukuja
	ptaulukko[i] = ((float)rand())/10000;
for(i=0;i<kpl; i++)				//taulukon tulostus
	cout << ptaulukko[i] <<endl;

delete[] ptaulukko;				//vapautetaan muistivaraus (tuhotaan taulukko-olio)

cin.get();
return 0;
}
