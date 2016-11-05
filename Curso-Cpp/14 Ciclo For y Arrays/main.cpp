#include <iostream>
#include <conio.h>
using namespace std;

int main(){
	char c[5];//Tañamo de array
	c[0] = 'H';
	c[1] = 'o';
	c[2] = 'l';
	c[3] = 'a';
	c[4] = '.';
	
	for(int i=0; i<(sizeof(c)); i++){
		cout << c[i];
	}
	cout << endl;//endl, se usa para terminar la línea
	
	getch();
	return 0;
}

