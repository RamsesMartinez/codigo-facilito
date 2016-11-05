#include <iostream>
#include <conio.h>

using namespace std;
bool comprobador;// 1--> True --- 0-->False

const int numero1 = 1;
const int numero2 = 1;
const int numero3 = 12;

/* COMPROBADORES
	=	Igual
	<	Menor
	>	Mayor
	<=	Menor o igual
	>=	Mayor o igual
	!=	Diferente

*/

main(){
	comprobador = (numero1 == numero2); //Devuelve true
	cout << comprobador << endl;
	
	comprobador = (numero1 == numero3); //Devuelve false;
	cout << comprobador << endl;
	getch();
}
