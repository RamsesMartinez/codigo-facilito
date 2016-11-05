#include <iostream>
#include <conio.h>
/*Punteros
	Variables que guardan la direccion de la memoria
*/
using namespace std;
int numero = 12;
int *puntero = &numero;
int main(){
	cout << puntero << endl; //Direccion de numero
	cout << *puntero << endl; //Indireccion la direccion de memoria en el valor almacenado
	getch();
	return 0;
}
