#include <iostream>
#include <conio.h>

using namespace std;

void funcion1(int num1 = 2);
void funcion2(int num2);

int main(){
	funcion1();
	funcion1(12);
	funcion2(12);
	getch();
	return 0;
}

void funcion1(int num){
	cout << (num + 3) << endl;
}
void funcion2(int num){
	cout << num << endl;
}
