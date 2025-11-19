#include "principal.h"


rPalabra palabra;
int opc,max,dificultad;

void menu();

int main(){
	
	menu();	
	return 0;
}

void menu(){
	int i;
	inicializarHistorial();
	while(opc!=9){
		printf("\n******************************************");
		printf("\n* \t    JUEGO AHORCADO               *");
		printf("\n******************************************");
		printf("\n  	  QUE DESEA HACER?");
		printf("\n[1] AGREGAR REGISTRO DE PALABRA" );
		printf("\n[2] VER REGISTROS CARGADOS" );
		printf("\n[3] SELECCIONAR PALABRA" );	
		printf("\n[4] JUGAR ");	
		printf("\n[5] BORRAR" );
		printf("\n[6] VER TABLA DE PUNTAJES" );	
		printf("\n[7] APLICACION DE TEMA: ORDENAMIENTO" );		
		printf("\n[8] APLICACION DE TEMA: ARBOLES" );	
		printf("\n[9] SALIR" );	
		
		printf("\n******************************************");
		printf("\nINGRESAR OPCION:  ");

		scanf("%d",&opc);
		switch(opc){
			case 1:
					system("cls");
					printf("******************************************\n");
					printf("	QUE PALABRA QUIERE AGREGAR?\n");
					printf("******************************************\n");
					scanf("%d",&max);
					inicioBinario();
					for(i=1;i<=max;i++){
						cargarPalabras();
						printf("Total de %d \n",i);
					}
					finBinario();
					break;
			case 2:
					system("cls");
					printf("******************************************\n");
					printf("	LAS PALABRAS QUE ESTAN AGREGADAS SON:\n");
					printf("******************************************\n");
					leerBinario();
					break;	
			case 3:
					system("cls");
					printf("******************************************\n");
					printf("DIFICULTADES:\n");
					printf("[1]FACIL\n");
					printf("[2]MEDIO\n");
					printf("[3]DIFICIL\n");
					printf("******************************************\n");
					printf("INGRESE UNA DIFICULTAD:");
					scanf("%d",&dificultad);
					printf("******************************************\n");
					buscarPalabra(&palabra,dificultad);
					printf("\n %s \n\n",palabra.palabra);
					break;
			case 4:
					system("cls");
					arrancar();
					verHistorial();
					break;
		
			case 5:
					system("cls");
					eliminarPartida();
					verHistorial();
					break;
			case 6:
					system("cls");
					verHistorial();
				break;
			case 7:
					system("cls");
					ordenamientoAhorcado1();
				break; 	
			case 8:
					system("cls");
						arbolesAhorcado();
					break; 	
			case 9:
					system("cls");
					printf("******************************************\n");
					printf("	MUCHAS GRACIAS POR JUGAR!");
					printf("\n******************************************");
					break; 	
		}
		
	}	
	
}
