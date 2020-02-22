#include <iostream>

using namespace std;

int main()

{

unsigned char a = 170;

unsigned char b = 255;

cout << "a on nyt " << (int)a << endl;

cout << "b on nyt " << (int)b << endl;

a = a << 1;

b = b >> 2;

cout << "a on nyt " << (int)a << endl;

cout << "b on nyt " << (int)b << endl;

cin.get();

}
