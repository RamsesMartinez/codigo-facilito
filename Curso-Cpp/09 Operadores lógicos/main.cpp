#include <iostream>
#include <conio.h>

using namespace std;

bool comprobador;
const int num1 = 1;
const int num2 = 2;
const int num3 = 3;
const int num4 = 4;

main(){
	comprobador = (num4 < num1 && num3 > num2); //True
	cout << comprobador << endl;
	
	comprobador = (num4 > num1 || num3 < num2); //True
	cout << comprobador << endl;
	
	//Antioperador
	comprobador = !(num4 > num1 || num3 < num2); //True -- pasa a ser False
	cout << comprobador << endl;
	
	//cin.get();//La pantalla no se cierra
	getch();
}
