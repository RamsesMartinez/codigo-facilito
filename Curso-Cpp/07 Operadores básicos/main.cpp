#include <iostream>
#include <conio.h>

using namespace std;

int numero1 = 12;
int numero2 = 10;

int suma;
int resta;
int multiplicacion;
int division;
int operacion;

main(){
	operacion = 2;
	suma = numero1+numero2;
	resta = numero1-numero2;
	multiplicacion = numero1*numero2;
	division = numero1/numero2;
	
	operacion += 3;
	
	cout << "suma: "<< suma << endl;
	cout << "resta: " << resta << endl;
	cout << "multiplicacion: " << multiplicacion << endl;
	cout << "division: " << division << endl;
	
	cout << "\noperacion: " << operacion << endl;
	getch();
}
