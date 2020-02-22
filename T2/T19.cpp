/*file: T19.cpp
  desc: C++, osa2, T19
  date: 10.6.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <math.h>  //pow
	
using namespace std;

double kaanteinen(int x);

int main ()
{
  int luku;

  cout<<"Anna kokonaisluku: "<<endl;
  cin>>luku;
  
  cout << "Luvun: "<<luku<<" k\x84\x84nteisluku on "<<kaanteinen(luku)<<endl; 

  cin.get();
  return 0;
}

//laskee ja palauttaa käänteisluvun parametrina saamalleen kokonaisluvulle
double kaanteinen(int x){
	double tulos = pow(x,-1);
	return tulos;
}
