//Define--> sustitución (Macros)
#define suma(a,b) a+b
#define multiplicar(a,b) a*b
#define dividir(a,b) a/b

#include <iostream>
#include <conio.h>

using namespace std;

int num1 = 2;
int num2 = 4;

int suma;
int mult;
int div;

int main(){
	suma = suma(num1,num2);
	mult = multiplicar(num1,num2);
	div = dividir(num2,num1);
	
	cout << "La suma es: " << suma << endl;
	cout << "La multiplicacion es: " << mult << endl;
	cout << "La division es: " << div << endl;
	
	getch();
	return 0;
}

