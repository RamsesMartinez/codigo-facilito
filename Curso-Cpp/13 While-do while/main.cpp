#include <iostream>
#include <conio.h>
using namespace std;

main(){
	int i = 0;
	//While comprueba y lueg oejecuta
	
	while (i <= 5){
		cout << i << endl;
		i++;
	}
	cout << "\nDo - While" << endl;
	//Do-While Ejecuta y luego comprueba
	i=0;
	do{
		cout << i << endl;
		i++;
	} while(i <= 5);
	getch();
	
}

