#include <iostream>
#include <conio.h>

int num1 = 2;
int num2 = 4;
int suma;

using namespace std;


void funcion(){
	cout << "Funcion sin valor de retorno" << endl;
}

int sumar(int a, int b){
	return	 (a + b);
}

int main(){
	suma = sumar(num1,num2);
	cout << "resultado: " << suma << endl;
	funcion();
	getch();
	return 0;
}
