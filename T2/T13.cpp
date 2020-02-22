/*file: T13.cpp
  desc: C++, osa2, T13
  date: 10.6.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
	
using namespace std;

int main ()
{
  //merkkimuuttuja
  char merkki='a';
  //sijaismuuttuja
  char &sijaismerkki=merkki;
  
  cout << "Merkki on aluksi: "<<merkki<<endl;
  
  //sijoitus sijaismerkin kautta merkkimuuttujaan
  sijaismerkki='b';
  
  cout << "Merkki on lopuksi: "<<merkki<<endl; 

  cin.get();
  return 0;
}
