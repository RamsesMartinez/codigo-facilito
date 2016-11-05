#include <iostream>
#include <conio.h>

using namespace std;
int num1 = 3;
int num2 = 2;

bool booleana = true;
main(){
	if(num1<num2){
		cout << "Es menor"<<endl;
	}
	else if(num1==num2){
		cout << "Son iguales" <<endl;
	}
	else{
		cout << "No es menor"<<endl;
	}
	getch();
}
