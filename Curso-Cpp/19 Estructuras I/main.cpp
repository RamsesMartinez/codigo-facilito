#include <iostream>
#include <conio.h>

using namespace std;

int main(){
	struct Persona{
		int edad;
		int tel;
	}Ramses;
	Ramses.edad = 18;
	Ramses.tel = 5530303030;
	cout << Ramses.edad << endl;
	getch();
	return 0;
}
