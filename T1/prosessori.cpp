/*file: prosessori.cpp
  desc: C++, osa1, T8
  date: 18.5.2018
  auth: Maarit Parkkonen
*/

#include <iostream>

using namespace std;

int main()

{
  struct Prosessori{
	float kellotaajuus; 			//GHz
	unsigned short rekisteri;		//bittisyys
	unsigned short ytimet;			//kpl
	unsigned short valimuisti;		//Mb
  };
	
  Prosessori prossa1;
  Prosessori prossa2;
  Prosessori prosessorit[2];
  prosessorit[0]=prossa1;
  prosessorit[1]=prossa2;
  
  int i;
  cout <<"Anna tiedot:\n";
  for (i = 0; i < 2; i++)
  {
	cout <<"\n"<<"Prosessori"<<(i+1);
  	cout <<"\n"<<"Kellotaajuus, GHz:";
	cin >>prosessorit[i].kellotaajuus;  	
  	cout <<"Rekisterin bittisyys:";
  	cin >>prosessorit[i].rekisteri; 
  	cout <<"Ytimien kpl:";
  	cin >>prosessorit[i].ytimet; 
  	cout <<"Valimuistin koko (MB):";  	
  	cin >>prosessorit[i].valimuisti; 
  }

  cout <<"\n"<<"PROSESSORIEN OMINAISUUDET:\n";
  
  
  for (i = 0; i < 2; i++)
  {
	cout <<"\n"<<"Prosessori"<<(i+1)<<"\n";
  	cout <<"Kellotaajuus:\t"<<prosessorit[i].kellotaajuus<<" GHz\n";  	
  	cout <<"Rekisteri:\t"<<prosessorit[i].rekisteri<<"-bittinen\n";  
  	cout <<"Ytimet:\t\t"<<prosessorit[i].ytimet<<" kpl\n"; 
  	cout <<"Valimuisti:\t"<<prosessorit[i].valimuisti<<" MB\n";  
  }

  cin.get();
  return 0;

}
