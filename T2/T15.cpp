/*file: T15.cpp
  desc: C++, osa2, T15
  date: 10.6.2018
  auth: Maarit Parkkonen
*/

#include <iostream>
	
using namespace std;

float keskiarvo(int x, int y);

int main ()
{
  int luku1, luku2;

  cout<<"Anna kaksi lukua: "<<endl;
  cin>>luku1;
  cin>>luku2;
  
  cout << "Lukujen keskiarvo on: "<<keskiarvo(luku1,luku2)<<endl; 

  cin.get();
  return 0;
}

float keskiarvo(int x, int y){
	float tulos = (float)(x+y)/2;
	return tulos;
}
