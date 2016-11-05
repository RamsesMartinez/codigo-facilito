#include <iostream>
#include <conio.h>
using namespace std;

main(){
	char c;
	cout << "Escribe un letra: " << endl;
	cin >> c; //Lo que el usuario escriba se guardará aquí
	
	switch(c){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			cout << "Es una vocal \n"<<endl;
			break;
		default:
			cout << "No es vocal" << endl;
	}

	system("PAUSE");
	//getch();
	
}
