#include <iostream>
#include <conio.h>
/*Namespace nos permite tenener varias variables del mismo nombre
	pero dentro que esten en diferentes namespace's*/

namespace ciudad{
	int calle;
}
namespace pueblito{
	int calle = 10;
}

using namespace ciudad;

int main(){
	calle = 12;
	std::cout << pueblito::calle << std::endl; //Imprime calle de publito
	std::cout << calle << std::endl; //Imprime calle de ciudad
	getch();
	return 0;
}
