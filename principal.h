#include "arbolAhorcado.h"
#include "colaDinamica.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>





void arrancar(),inicializarVariables(),seleccionarPalabra(),resultados(),mostrarAhorcado();
void puntaje(),inicializarHistorial(),eliminarPartida(),verHistorial();
void resetearVariables();
void verificarLetra(rPalabra*,tPalabra,char);
void modificarAhorcado(int);
void modificarCadenaError(int,char);
bool jugar(rPalabra *,tPalabra,int);
char ingresarLetra();

rPalabra palCompleta,palEncontrar;
tPalabra ahorcadoCompleto ={'O','|','/','\\','/','\\'}; 
tPalabra guiones;
tPalabra ahorcado,letrasError;
int cantError,dificultad;
bool result,juego,bandera;
tColaAhorcado historialPuntaje;

void arrancar(){
	seleccionarPalabra();
	result = jugar(&palEncontrar,palCompleta.palabra,cantError);
	resultados();
	resetearVariables();
	
}
void inicializarVariables(){
	int i,numLetras;
	cantError = 0;
	numLetras = strlen(palCompleta.palabra);
	for(i=0;i<numLetras;i++){
		guiones[i]= '_';
	}
	
}

void seleccionarPalabra(){
	printf("******************************************\n");
	printf("DIFICULTADES:\n");
	printf("[1]FACIL: 	6 LETRAS A ENCONTRAR\n");
	printf("[2]MEDIO:	7 LETRAS A ENCONTRAR\n");
	printf("[3]DIFICIL:	8 LETRAS A ENCONTRAR\n");
	printf("******************************************\n");
	printf("INGRESE UNA DIFICULTAD:");
	scanf("%d",&dificultad);
	buscarPalabra(&palCompleta,dificultad);
	inicializarVariables();
}

bool jugar(rPalabra * pPalEncontrar,tPalabra pPalCompleta,int pCantError){
	if(pCantError >=6 || strcmp(pPalEncontrar->palabra,pPalCompleta)==0){
		if(pCantError>=6){
			cantError= pCantError;
			return false;
		}else{
			cantError= pCantError;
			return true;
		}
	}
	/* printf("%s \n",pPalCompleta); */
	char letra = ingresarLetra();
	verificarLetra(pPalEncontrar,pPalCompleta,letra);
	if (bandera== false){
		pCantError= pCantError +1;
		modificarAhorcado(pCantError);
		modificarCadenaError(pCantError,letra);
	}
	mostrarAhorcado();
	juego= jugar(pPalEncontrar,pPalCompleta,pCantError);
}


char ingresarLetra(){
	char letra;
	printf("Ingrese una letra: ");
	fflush(stdin);
	scanf("%c",&letra);
	return letra;
}

void verificarLetra(rPalabra * pPalEncontrar,tPalabra pPalCompleta,char pLetra){
	bandera = false;
	int i, numLetras;
	numLetras = strlen(pPalCompleta);
	for(i=0;i<=numLetras;i++){
		if(pPalCompleta[i]==pLetra){
			pPalEncontrar->palabra[i]= pPalCompleta[i];
			bandera = true;
		}
	}
} 

void modificarAhorcado(int pCantError){
	
	ahorcado[pCantError-1]= ahorcadoCompleto[pCantError-1];
}
void modificarCadenaError(int pCantError,char pLetra){
	
	letrasError[pCantError-1]= pLetra;
}

void mostrarAhorcado(){
	system("cls");
	printf("_________\n");
	printf("|\t|\n");
	printf("|\t%c\n",ahorcado[0]);
	printf("|      %c%c%c\n",ahorcado[2],ahorcado[1],ahorcado[3]);
	printf("|      %c %c\n",ahorcado[4],ahorcado[5]);
	printf("|\n");
	fflush(stdin);
	printf("    %c %c %c %c %c %c %c %c \n",palEncontrar.palabra[0],palEncontrar.palabra[1],palEncontrar.palabra[2],palEncontrar.palabra[3],palEncontrar.palabra[4],palEncontrar.palabra[5],palEncontrar.palabra[6],palEncontrar.palabra[7]);
	fflush(stdin);
	printf("    %c %c %c %c %c %c %c %c \n\n",guiones[0],guiones[1],guiones[2],guiones[3],guiones[4],guiones[5],guiones[6],guiones[7]);
	printf(" %c %c %c %c %c %c\n",letrasError[0],letrasError[1],letrasError[2],letrasError[3],letrasError[4],letrasError[5]);
	printf(" _ _ _ _ _ _\n");

}

void resultados(){
	system("cls");
	if (result==true){
		printf("******************************************\n");
		printf("	FELICIDADES! GANASTE! :D\n");
		printf("******************************************\n");
	}else{
		printf("******************************************\n");
			printf("	NO PUDISTE GANAR :( \n");
		printf("******************************************\n");
	
	}
	puntaje();
}

void puntaje(){
	rPuntaje partida;
	printf("DEBE INGRESAR SU NOMBRE DE 3 CARACTERES:\n");
	scanf("%s",&partida.nombre);
	printf("******************************************\n");
	fflush(stdin);
	printf("\n");
	partida.dificultad= palCompleta.dificultad;
	if (result == true){
		partida.puntos= 100-(cantError*10);
	}else{
		partida.puntos=0;
	}
	printf("SU PUNTAJE FUE DE [%d] PUNTOS EN LA DIFICULTAD [%d] \n\n",partida.puntos,partida.dificultad);
	agregarElemCola(&historialPuntaje,partida);
}

void inicializarHistorial(){
	
	inicializarCola(&historialPuntaje);
}

void eliminarPartida(){
	
	eliminarElemCola(&historialPuntaje);
}

void verHistorial(){
	
	visualizarPuntajes(&historialPuntaje);
}

void resetearVariables(){
	
	int i,num;
	num = strlen(palCompleta.palabra);
	for (i=0;i<num;i++){
		palEncontrar.palabra[i]=' ';
		guiones[i]=' ';
		if (i>=0 && i<6){
			ahorcado[i]=' ';
			letrasError[i]=' ';
		}
	}
}

