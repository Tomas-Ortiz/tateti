#include <iostream>
#include <string.h>
void titulo();
void limpiar(char x[], char o[], int aux1[]);
void jugada(int *n, char x[], char o[], int aux1[], int *jugador, int *empate);
void condicion1(int n, int aux1[]);
void tablero(int n, char x[], char o[], int aux1[]);
void ganapierde(char x[], char o[], int empate, int *ganado);

using namespace std;

int main()
{

int n , aux1[100], jugador , empate, ganado, opcion = 0, i;
char x[100], o[100];


do{
	
limpiar(x, o, aux1);
n=0;
jugador=1;
empate=0;
ganado=0;
		
while(ganado!=1 || empate!=9)
{
	
titulo();
tablero(n, x, o, aux1);
jugada(&n, x, o, aux1, &jugador, &empate);	
ganapierde(x, o, empate, &ganado);	

	if(ganado==1 || empate==9)		//si jugador X-O gana ó hay empate entonces se muestra el tablero y termina el juego
	{
		tablero(n, x, o, aux1);
		
		break;
	}
		
}

	cout<<"\n"<<"\n"<<"  Pulse 1 para seguir jugando, pulse 2 para salir."<<endl;
	cout<<"Opcion: ";
	cin>>opcion;
	
	while(!cin)
	{
		cin.clear();
		cin.ignore();
		cout<<"Ingrese una opcion valida: ";
		cin>>opcion;
	}
	
	system("cls");
	
}while(opcion!=2);

	return 0;
}

void titulo()
{
	
cout<<"                           XOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXO"<<endl;	
cout<<"\n"<<"                                        TA - TE - TI "<<endl;
cout<<"\n"<<"                           XOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXO"<<endl;	
cout<<"\n";
		
}

void limpiar(char x[], char o[], int aux1[])
{
	int i;
	
	memset(x, '\0', 100);
	memset(o, '\0', 100);		//convierte los primeros n caracteres de las dos cadenas en valores nulos (\0)

		
		for(i=0; i<20; i++)
		{
			aux1[i] = 0;		//reincia arreglo
		}
	
}

void jugada(int *n, char x[], char o[], int aux1[], int *jugador, int *empate)
{
cout<<"\n"<<endl;

cout<<"----------------------------------"<<endl;	
cout<<"             JUGADA "<<endl;

	if(*jugador==1)			//variable que se encarga de alternar de jugador, es decir, una vez cada uno
	{

cout<<"----------------------------------"<<endl;	
cout<<"  Turno de X, ingrese la casilla: "<<endl;
cout<<"----------------------------------"<<endl;	
cout<<"\n"<<"  Casilla: ";

do{
	
cin>>*n;

	while(!cin)	
	{
		cin.clear();
		cin.ignore();
		cout<<"\n"<<" Ingrese una casilla valida: ";		//condicion para que no ingrese simbolos
		cin>>*n;
	}
	
condicion1(*n, aux1);		//corrobora que la letra no haya sido ingresada ya
	
}while(*n<1 || *n>9 || aux1[*n]==1);	//repite si ingresa un numero fuera del tablero o si la letra ya ha sido ingresada

	aux1[*n] = 1;		//se marca la posicion como ocupada (1)
	x[*n] = 'X';	//se guarda el caracter X en dicha posicion para luego mostrarlo
	*empate = *empate + 1;	//se lleva la cuenta de las jugadas para saber cuando empatan
	*jugador = 2;	//la variable toma el valor 2 para que el otro jugador juegue
}

		else
		{

cout<<"----------------------------------"<<endl;	
cout<<"  Turno de O, ingrese la casilla: "<<endl;
cout<<"----------------------------------"<<endl;	
cout<<"\n"<<"  Casilla: ";

do{
	
cin>>*n;

	while(!cin)	
	{
		cin.clear();
		cin.ignore();
		cout<<"\n"<<" Ingrese una casilla valida: ";
		cin>>*n;
	}
	
condicion1(*n, aux1);
	
}while(*n<1 || *n>9 || aux1[*n]==1);

	aux1[*n] = 1;
	o[*n] = 'O';
	*empate = *empate + 1;
	*jugador = 1;
	
		}

	system("cls");
}

void condicion1(int n, int aux1[])
{
		if(n<1 || n>9)
	{
		cout<<"\n"<<" Ingrese una casilla del 1 al 9 : ";
	}
	
		else if(aux1[n]==1)
		{
		cout<<"\n"<<" Esa casilla ya ha sido seleccionada, ingrese otra: ";
		}	
		
}

void tablero(int n, char x[], char o[], int aux1[])
{
	
	int i;
			cout<<"\n"<<"---------------------------"<<endl;
			cout<<"         TABLERO "<<endl;
			cout<<"---------------------------"<<endl;
	
	cout<<" "<<endl;
	
	for(i=1; i<10; i++)
	{
		if(aux1[i]==1)		//si la posicion ya ha sido marcada entonces se muestra
		{
			
			if(x[i]=='X')
			{	
				cout<<"  | "<<x[i]<<" | ";
			}									//si la posicion marcada es X o O se muestra
			
				else if(o[i]=='O')
				{
				cout<<"  | "<<o[i]<<" | ";				
				}
				
		}
		
			else
			{	
				cout<<"  | "<<i<<" | ";		
			}
			
		if(i==3)
		{
			cout<<endl<<"  ---------------------"<<endl;		//Saltos de linea para dibujar tablero
		}
		
		if(i==6)
		{
			cout<<endl<<"  ---------------------"<<endl;
		}
						
	}	
			
}

void ganapierde(char x[], char o[], int empate, int *ganado)
{
			
	if((x[1]=='X' && x[2]=='X' && x[3]=='X') || (x[4]=='X' && x[5]=='X' && x[6]=='X') || (x[7]=='X' && x[8]=='X' && x[9]=='X') || 
	(x[1]=='X' && x[5]=='X' && x[9]=='X') || (x[1]=='X' && x[4]=='X' && x[7]=='X') || (x[2]=='X' && x[5]=='X' && x[8]=='X') || 
	(x[3]=='X' && x[6]=='X' && x[9]=='X') || (x[3]=='X' && x[5]=='X' && x[7]=='X'))		//verifica si hay tres X en vertical, horizontal y diagonal
	{
		*ganado = 1;
		
		cout<<"\n"<<"   X O X O X O X O X O X O X O X O X O X O X O"<<endl;
		cout<<"\n"<<"     HA GANADO EL JUGADOR X, FELICIDADES!"<<endl;
		cout<<"\n"<<"   X O X O X O X O X O X O X O X O X O X O X O"<<endl;
		
	}
	
		else if((o[1]=='O' && o[2]=='O' && o[3]=='O') || (o[4]=='O' && o[5]=='O' && o[6]=='O') || (o[7]=='O' && o[8]=='O' && o[9]=='O') || 
	(o[1]=='O' && o[5]=='O' && o[9]=='O') || (o[1]=='O' && o[4]=='O' && o[7]=='O') || (o[2]=='O' && o[5]=='O' && o[8]=='O') ||    
	(o[3]=='O' && o[6]=='O' && o[9]=='O') || (o[3]=='O' && o[5]=='O' && o[7]=='O'))	  //verifica si hay tres O en vertical, horizontal o diagonal	
	{
		*ganado = 1;
		
		cout<<"\n"<<"   X O X O X O X O X O X O X O X O X O X O X O"<<endl;
		cout<<"\n"<<"     HA GANADO EL JUGADOR O, FELICIDADES!"<<endl;
		cout<<"\n"<<"   X O X O X O X O X O X O X O X O X O X O X O"<<endl;
		
	}
	
	else if(empate==9)		//Si la cantidad de jugadas es igual a 9 y ninguno gana entonces es empate
	{		
		cout<<"\n"<<"   X O X O X O X O X O X O X O X O X O X O X O"<<endl;
		cout<<"\n"<<"             HA HABIDO UN EMPATE!"<<endl;
		cout<<"\n"<<"   X O X O X O X O X O X O X O X O X O X O X O"<<endl;				
	}
	
	
}
