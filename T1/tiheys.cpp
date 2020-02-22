/*file: tiheys.cpp
  desc: C++, osa1, T10, T11, T12
  date: 19.5.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
using namespace std;
#include <cmath>

const int PAINO=100000;		//kg
const short ALA=300;		//m^3
const float HALKAISIJA=0.3;	//m
const short MATKA=20;		//km
const long double PII=3.141592653589793238L;

int main()
{
  float tiheys=(float)PAINO/ALA; 
  cout<<"AINEEN OMINAISUUDET:\n";
  cout<<"Paino:\t\t"<<PAINO<<" kg\n";
  cout<<"Pinta-ala:\t"<<ALA<<" m^3\n";
  cout<<"Tiheys:\t\t"<<tiheys<<" kg/m^3\n";
  
  long double keha=HALKAISIJA*PII;
  int kierrokset=(MATKA*1000)/keha;
  cout<<"\nJUUSTOPALLO\n";
  cout<<"kehä:\t\t"<<keha<<" m\n";
  cout<<"matka: \t\t"<<MATKA<<" km\n";
  cout<<"kierrokset: \t"<<kierrokset<<" kpl\n";
  
  double tulos=4 + (5*20) - 33 + ((double)20/3);
  cout<<"Lasku: 4 + 5 * 20 - 33 + 20/3 = "<<tulos;
  
  cin.get();
  return 0;
}
