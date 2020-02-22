/*file: T20.cpp
  desc: C++, osa2, T20
  date: 10.6.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
#include <math.h>  //pow
	
using namespace std;

const int MAX=3;

void kymmenkertaista(float *x);

int main ()
{
  float luvut[MAX];
  int i;

  cout<<"Anna "<<MAX<<" lukua: "<<endl;
  for (i=0;i<MAX;i++)
  	cin>>luvut[i];
  
  //taulukkomuuttujan alkuperäiset arvot
  cout<<endl<<"1.Luvut: ";
  for (i=0;i<MAX;i++){
  	cout<<luvut[i]<<"\t\t"; 
    kymmenkertaista(&luvut[i]);
  }

  ///taulukkomuuttujan kerrotut arvot
  cout<<endl<<"2.Luvut: ";
  for (i=0;i<MAX;i++) 
  	cout<<luvut[i]<<"\t\t";  
  
  cin.get();
  return 0;
}

void kymmenkertaista(float *x){
	*x*=10;
}
