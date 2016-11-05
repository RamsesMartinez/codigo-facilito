#include <iostream>
#include <conio.h>

using namespace std;

/*
Funciones normales que retornan
Funciones constructoras que tienen mismo nombre que la estructura
Funciones Destructoras ***Empiezan con ~***
*/

int main(){
	struct Hogar{
		int numeroDireccion;
		int numeroTel;
		//Funcion dentro de estrucutras ***Solo para C++***
		Hogar(){ //Fucnion constructora
			numeroDireccion = 0; 
			numeroTel = 2;
		}
		
		int verDir(){ //Funcion entera
			return numeroDireccion;
		}
		int guardarDir(int a){ //Almacena datos en el struct
			numeroDireccion = a; 
		}
		
	}Fernandez,Gonzalez,Perez;
	
	Fernandez.numeroTel = 1023;
	Fernandez.numeroDireccion = 325;
	
	Gonzalez = Fernandez;
	cout << Gonzalez.numeroDireccion << endl;
	cout << Gonzalez.numeroTel << endl;
	cout << Perez.numeroTel << endl;
	
	Perez.guardarDir(156);
	cout << Perez.verDir();
	getch();
	return 0;
}


