/*file: T6.cpp
  desc: C++, osa2, T6
  date: 9.6.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
	
using namespace std;

const short MAX=100;	//merkkien max=99 + \0

int main ()
{
  char mjono[MAX];
  short i=0;
  
  cout<<"Kirjoita merkkijono: "<<endl;
  cin.get(mjono,MAX).get();					//ottaa mukaan myös välilyönnit ja lukee pois rivinvaihdon
  
  while (mjono[i]!='\0')
  	i++;

  cout<<endl<<"Merkkijonon pituus: "<<i<<endl;

  cin.get();
  return 0;
}
