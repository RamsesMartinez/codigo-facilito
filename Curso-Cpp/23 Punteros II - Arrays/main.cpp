#include <iostream>

using namespace std;

//Los arrays se almacen uno al lado de otro
int array[5];
int *p;

int main(){
	p = array; //p = &array[0]
	cout << "direccion array[0] " << &array << endl;
	cout << "puntero " << p << endl;
	
	//Ahora el puntero apunta a array[1]
	p++;
	cout << "\npuntero " << p << endl;
	
	cin.get();
	return 0;
}
