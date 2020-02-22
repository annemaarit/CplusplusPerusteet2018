/*file: T8.cpp
  desc: C++, osa2, T8
  date: 9.6.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
	
using namespace std;

const short MAX=100;	//merkkien max=99 + \0

int main ()
{
  char mjono[MAX];
  char merkki;
  short i=0, paikka=0;
  
  cout<<"Kirjoita merkkijono: "<<endl;
  cin.get(mjono,MAX).get();					//ottaa mukaan myös välilyönnit ja lukee pois rivinvaihdon
  
  cout<<"Anna etsitt\x84v\x84 merkki: "<<endl;
  cin>>merkki;
  
  while (mjono[i]!='\0'){
  	if (merkki==mjono[i]){
  		paikka=i+1;
  		break;
	  }
  	i++;
  }
  	
  if (paikka!=0)
  	cout<<endl<<"Merkki "<<merkki<<" l\x94ytyi, paikkanro: "<<paikka<<endl;
  else
  	cout<<endl<<"Merkkijonosta ei l\x94ytynyt merkki\x84 "<<merkki<<endl;
  
  cin.get();
  return 0;
}
