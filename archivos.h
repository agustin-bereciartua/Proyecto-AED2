#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
# define N 30
#define SEEK_SET 0

typedef char tPalabra [10];

typedef struct {
	int dificultad;
	tPalabra palabra;
}rPalabra;

rPalabra palabraReg;
rPalabra prueba;
int aux;
FILE * binario;
void inicioBinario(), grabarBinario(), finBinario();
void leerBinario(), cargarPalabras();
void inicializarCorte(),procesoCorte(rPalabra *,int);
void buscarPalabra(rPalabra *,int);


void inicioBinario(){
	binario = fopen("palabras.dat","wb");
	
}
void grabarBinario(){
	
	fwrite (&palabraReg,sizeof(rPalabra),1,binario);
}
void finBinario(){
	
	fclose(binario);
}

void cargarPalabras(){
	printf("Ingrese el tipo de dificultad: 1-2-3:\n");
	scanf("%d",&palabraReg.dificultad);
	printf(" \n Ingrese la palabra acorde a la dificultad:\n");
	scanf("%s",&palabraReg.palabra);
	fflush(stdin);
	grabarBinario();
	
}

void leerBinario(){
	binario = fopen("palabras.dat","rb");
	printf("\n\n-------\n");
	while (!feof(binario)){
		fread(&prueba,sizeof(rPalabra),1,binario);
		printf("%d %s\n",prueba.dificultad,prueba.palabra); 
		fflush(stdin);
	}
	fclose(binario);
}
void inicializarCorte(){
	binario = fopen ("palabras.dat","rb");
	aux=0;
	
}

void procesoCorte(rPalabra * pPalabra,int pDificultad){
	int num;
	while(!feof(binario)&& aux!=pDificultad){
		/* srand(time(NULL)); */ 
		num = rand() % (N+1);
		fseek(binario,(num*(sizeof(rPalabra))),SEEK_SET);
		fread(&palabraReg,sizeof(rPalabra),1,binario);
		/* printf("%s -- %d \n",palabraReg.palabra,palabraReg.dificultad); */
		aux= palabraReg.dificultad;
	}
	strcpy(pPalabra->palabra,palabraReg.palabra);
	pPalabra->dificultad= palabraReg.dificultad;
}

void buscarPalabra(rPalabra * pPalabra,int pDificultad){
	inicializarCorte();
	procesoCorte(pPalabra,pDificultad);
	finBinario();
	
}


