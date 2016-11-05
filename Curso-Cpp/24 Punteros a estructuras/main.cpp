#include <iostream>

using namespace std;

struct miestructura{ //En C++ se puede o no poner esta declaracion
	int a;
}miEstructura,*puntero;

int main(){
	miEstructura.a = 12;
	puntero = &miEstructura;
	
	cout << puntero << endl; //Retorna direccion de puntero
	cout << &miEstructura.a << endl;
	cout << puntero->a << endl; //Retorna valor variable a
	
	cin.get();
	return 0;
}
