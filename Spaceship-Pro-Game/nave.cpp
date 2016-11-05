/*
Juego de naves Spaceship Pro Game
Created By  Ramses Martinez Ortiz
~Ramses1221~
v1.0.3
Cambio automatico de color de pantalla


*/
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <list>
#include <string.h>
#include <time.h>
#include <iostream>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

    using namespace std;
    
    bool game_over = false;
    int puntaje = 0;
    int numeroAsteroides = 10;
    int velocidad = 50;
    int salud = 5; //Numero de corazones
    int vidas = 3;

void gotoxy(int x, int y);
void OcultarCursor();
void PintarLimites();
void imprimirGameOver();
void playGame();
void desplegarMenu();
void guardarPuntaje();

class NAVE{
    int x,y; //Coordenadas
    int corazones;
    int vidas;
public: //Metodos publicos
    NAVE(int _x, int _y,int _corazones,int _vidas): x(_x),y(_y),corazones(_corazones),vidas(_vidas){}//Construtor
    int X() { return x; }
    int Y() { return y; }
    int VIDAS(){ return vidas; }
    void quitarCorazon(){ corazones--;}
    void pintar();
    void borrar();
    void mover();
    void pintarCorazones();
    void morir();
    void desplegarMenu();
};

void NAVE::pintar(){ //Acede a metodo pintar de la clase NAVE
    gotoxy(x,y);    printf("  %c",30);
    gotoxy(x,y+1);  printf(" %c%c%c",40,207,41);
    gotoxy(x,y+2);  printf("%c%c %c%c",30,190,190,30);
}

void NAVE::borrar(){ //Metodo borrar de la clase NAVE
    gotoxy(x,y);    printf("        "); //5 espacios
    gotoxy(x,y+1);  printf("        ");
    gotoxy(x,y+2);  printf("        ");
}

void NAVE::mover(){
    if(kbhit()){
        char tecla = getch();
        borrar(); //Metodo borrar de clase NAVE
        if(tecla == IZQUIERDA && x > 3) x--;
        if(tecla == DERECHA && x+6 < 77)x++;
        if(tecla == ARRIBA && y > 4)    y--;
        if(tecla == ABAJO && y+3 < 33)  y++;
        if(tecla == 'e')  corazones--;
        pintar(); //Metodo pintar de clase NAVE   
        pintarCorazones(); 
    }
}

void NAVE::pintarCorazones(){ //Dibuja el estado de salud
    gotoxy(50,2);   printf("VIDAS %d",vidas);
    gotoxy(64,2);   printf("Salud: ");
    gotoxy(70,2);   printf("        ");
    for(int i=0; i<corazones; i++){
        gotoxy(70+i,2); 
        //printf("%c",3);
        //printf("\3");
        //putchar(3);
        putchar(176);
    }
}

void NAVE::morir(){
    if (corazones == 0)
    {
        borrar();
        gotoxy(x,y);    printf("   **   ");
        gotoxy(x,y+1);  printf("  ****  ");
        gotoxy(x,y+2);  printf("   **   ");
        Sleep(200);

        borrar();
        gotoxy(x,y);    printf(" * ** * ");
        gotoxy(x,y+1);  printf("  ****  ");
        gotoxy(x,y+2);  printf(" * ** * ");
        Sleep(200);
        borrar();
        vidas--;
        corazones = 3;
        pintarCorazones();
        pintar();
    }

}

class ASTEROIDE{
    int x,y;//Coordenadas
public:
    ASTEROIDE(int _x, int _y):x(_x),y(_y){}
    void pintar();
    void mover();
    void chocar(class NAVE &nave);
    int X(){ return x; }
    int Y(){ return y; }
};

void ASTEROIDE::pintar(){
    gotoxy(x,y);    
    //printf("%c",248);
    putchar(111);
}

void ASTEROIDE::mover(){
    gotoxy(x,y);    printf(" ");
    y++; //Efecto de caida
    if(y>32){
        x = rand()%71 + 4;//Numero aleatorio (entre 0 y 71)
        y = 4;
    }
    pintar();
}

void ASTEROIDE::chocar(class NAVE &nave){
    if(x >= nave.X() && x < nave.X()+6 && y >= nave.Y() && y <= nave.Y()+2){//Intervalo que ocupa la nube
        nave.quitarCorazon();
        nave.borrar();
        nave.pintar();
        nave.pintarCorazones();
        x = rand()%71+4;
    }
}

class BALA{
    int x,y; //Coordenadas
public:
    BALA(int _x, int _y): x(_x),y(_y){};//Constructor
    int X(){return x;}
    int Y(){return y;}
    void mover();
    bool fuera();
};

void BALA::mover(){
    gotoxy(x,y);    printf(" ");
    y--; //Permite que siga subiendo
    gotoxy(x,y);    printf("*");
}

bool BALA::fuera(){
    if(y==4) return true;
    return false;
}


void gotoxy(int x, int y){//
    HANDLE hCon; //Handle de la consola
    hCon = GetStdHandle (STD_OUTPUT_HANDLE); //Obtiene identificador de la consola
    COORD dwPos; //Coordenadas de las posiciones
    dwPos.X = x; 
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon,dwPos);
}

void OcultarCursor(){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci; //Permite modificar atributos del cursor
    cci.dwSize = 2; // 1-100 Estilo del cursor
    cci.bVisible = FALSE;
    
    SetConsoleCursorInfo(hCon,&cci);//Parametro Handle y Estructura de datos
}

void PintarLimites(){ 
    for(int i=2; i<78; i++){//Limites horizontales
        gotoxy(i,3);    printf("%c",205);
        gotoxy(i,33);   printf("%c",205);
    }
    
    for(int i=4; i<33; i++){ //Limites verticales
        gotoxy(2,i);    printf("%c",186);
        gotoxy(77,i);   printf("%c",186);   
    }

    gotoxy(2,3);    printf("%c",201);
    gotoxy(2,33);   printf("%c",200);
    gotoxy(77,3);   printf("%c",187);
    gotoxy(77,33);  printf("%c",188);
}

void imprimirGameOver(){
    system("CLS");  //Limpia pantalla
    gotoxy(10,5);
    printf("G A M E    O V E R");
    printf("\nPuntuacion final: %d",puntaje);
    printf("\n\n\n\n\n");
    kbhit();
    desplegarMenu();
};

void playGame(){
    system("CLS");  //Limpia pantalla
    OcultarCursor();
    PintarLimites();
    NAVE nave(37,30,salud,vidas);//x,y,salud,vidas
    nave.pintar();
    nave.pintarCorazones();

    list<ASTEROIDE*> asteroidesList;
    list<ASTEROIDE*>::iterator iteradorAsteroide;
    for(int i = 0; i<numeroAsteroides; i++){ //Crea los asteroides
        asteroidesList.push_back(new ASTEROIDE(rand()%75 + 3, rand()%5 + 4));
    }

    list <BALA*> balaList; //Lista de punteros para las balas
    list <BALA*>::iterator iteradorBala; //iterador de la lista
    while(!game_over){

        gotoxy(4,2);    printf("PUNTOS %d", puntaje);
        if(kbhit()){
            char tecla = getch();
            if(tecla == 'a')
                balaList.push_back(new BALA(nave.X() + 2, nave.Y() -1)); //Se crea una bala
        }
        
        for(iteradorBala = balaList.begin(); iteradorBala != balaList.end(); iteradorBala++){ //Recorremos la lista
            (*iteradorBala)->mover();
            if((*iteradorBala)-> fuera()){
                gotoxy((*iteradorBala)->X(),(*iteradorBala)->Y());  printf(" ");
                delete(*iteradorBala);//Borra el elemento de la lista que está fuera 
                iteradorBala = balaList.erase(iteradorBala); //Hacemos que el iterador recorra la posicion

            }
        }

        for(iteradorAsteroide = asteroidesList.begin(); iteradorAsteroide != asteroidesList.end(); iteradorAsteroide++){
            (*iteradorAsteroide)->mover();
            (*iteradorAsteroide)->chocar(nave);

        }

        for(iteradorAsteroide = asteroidesList.begin(); iteradorAsteroide !=asteroidesList.end(); iteradorAsteroide++){
            for(iteradorBala = balaList.begin(); iteradorBala != balaList.end(); iteradorBala++){
                if((*iteradorAsteroide)->X() == (*iteradorBala)->X() && ( (*iteradorAsteroide)->Y() +1 == (*iteradorBala)->Y() || (*iteradorAsteroide)->Y() == (*iteradorBala)->Y() )){
                    gotoxy((*iteradorBala)->X(),(*iteradorBala)->Y());  printf(" ");
                    delete(*iteradorBala);
                    iteradorBala = balaList.erase(iteradorBala);//Recorre para que no se pierda el "hilo"

                    asteroidesList.push_back(new ASTEROIDE(rand()%74 + 3, 4));
                    gotoxy((*iteradorAsteroide)->X(),(*iteradorAsteroide)->Y());  printf(" ");
                    delete(*iteradorAsteroide);
                    iteradorAsteroide = asteroidesList.erase(iteradorAsteroide);

                    puntaje += 5;
                }
            }
        }

        //Condicion de vidas
        if(nave.VIDAS() == 0) 
            game_over = true;   

        nave.morir();
        nave.mover();
        Sleep(velocidad);
    }
} 

void desplegarMenu(){
    /*char opcion[1];
    opcion[0]=0;

    system("CLS"); 
    printf("1.\tJugar \n");
    printf("2.\tPuntajes mayores \n");
    printf("3.\tSalir\n");

    kbhit();//Espera pulsacion
    opcion[0] = getchar();
    switch(opcion[0]){
        case '1':
            playGame();//Reproduce el juego    
            imprimirGameOver();//Al terminar el juego
            break;
        case '2':
            break;
        default:
            break;
    }*/
}
int obtenHora(char *formato, char **destino){
	*destino = NULL;
	time_t rawtime;
	struct tm *timeinfo;
	char buffer[80];
	
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), formato, timeinfo);
	*destino = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
	strcpy(*destino, buffer);
	return 0;
}
void guardarPuntaje(){
    FILE *archivo;
    char *hora = NULL;
  	obtenHora("%Y-%m-%d %H:%M:%S", &hora);
    
	archivo = fopen("puntaje.txt","a+t");
    fprintf(archivo,"Fecha: %s\n",hora);
    fprintf(archivo,"Puntaje: %d\n\n",puntaje);
    fclose(archivo);
}
int main(){
	system("color 1F"); //Cambiamos color de consola
    playGame();
    imprimirGameOver();
    guardarPuntaje();
    return 0;
}

