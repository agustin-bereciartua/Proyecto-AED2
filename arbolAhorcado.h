#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef char tString [25];

typedef struct {
	int puntaje;
	tString descripcion;
} tDatosAhorcado;

typedef struct nodoArbol {
	tDatosAhorcado datosAhorcado;
	struct nodoArbol * hijoIzquierdo;
	struct nodoArbol * hijoDerecho;
}tArbolAhorcado;
void arbolesAhorcado();
bool arbolVacio( tArbolAhorcado * );
void insertarElemento( tArbolAhorcado **, tDatosAhorcado );
void recorrerEnInorden( tArbolAhorcado * );
void mostrarGrafico(tArbolAhorcado *);//pendiente





void arbolesAhorcado(){

	tDatosAhorcado datos;
	tArbolAhorcado * arbol;
	
	datos.puntaje = 80;
	strcpy(datos.descripcion, "[Si erras 2]");	
	insertarElemento( &arbol, datos);
	
	datos.puntaje = 50;
	strcpy(datos.descripcion, "[Si erras 5]");	
	insertarElemento( &arbol, datos);
		
	datos.puntaje = 0;
	strcpy(datos.descripcion, "[Si erras 6]");	
	insertarElemento( &arbol, datos);
	
	datos.puntaje = 60;
	strcpy(datos.descripcion, "[Si erras 3]");	
	insertarElemento( &arbol, datos);
	
	datos.puntaje = 90;
	strcpy(datos.descripcion, "[Si erras 1]");	
	insertarElemento( &arbol, datos);
		
	datos.puntaje = 100;
	strcpy(datos.descripcion, "[PUNTAJE PERFECTO]");	
	insertarElemento( &arbol, datos);
	
	printf("**MODALIDAD DE PUNTAJES**\n");
	recorrerEnInorden(arbol);
	
	mostrarGrafico(arbol);
	
	}
bool arbolVacio( tArbolAhorcado * pArbol ) {
	return pArbol == NULL;
}

void insertarElemento( tArbolAhorcado ** pArbol, tDatosAhorcado pDatos ) {
	if( arbolVacio( * pArbol ) ) {
		( *pArbol ) = ( tArbolAhorcado * ) malloc( sizeof( tArbolAhorcado ));
		if( *pArbol != NULL) {
			( *pArbol )->datosAhorcado = pDatos;
			( *pArbol )->hijoIzquierdo = NULL;
			( *pArbol )->hijoDerecho = NULL;
		} else {
		}						
	} else {
		if( pDatos.puntaje < (*pArbol)->datosAhorcado.puntaje ) {

			insertarElemento(  &((*pArbol)->hijoIzquierdo)  , pDatos  );
		} else {
			if( pDatos.puntaje > (*pArbol)->datosAhorcado.puntaje ) {
				insertarElemento(  &((*pArbol)->hijoDerecho)  , pDatos  );	
			}  else {
				printf("Elemento duplicado\n");
			}
		}
	}
}

void recorrerEnInorden( tArbolAhorcado * pArbol ) {
	if( pArbol != NULL ) {
		recorrerEnInorden( pArbol->hijoIzquierdo );
		printf("%d\t| %s \n", pArbol->datosAhorcado.puntaje, pArbol->datosAhorcado.descripcion );
		recorrerEnInorden( pArbol->hijoDerecho );
	}
	
}

bool buscarElemento( tArbolAhorcado * pArbol, int pPuntaje ) {
	if( arbolVacio(pArbol)) {
		return false;
	} else {
		if( pPuntaje < pArbol->datosAhorcado.puntaje ) {
			buscarElemento( pArbol->hijoIzquierdo,  pPuntaje);
		} else {
			if( pPuntaje > pArbol->datosAhorcado.puntaje ) {
				buscarElemento( pArbol->hijoDerecho,  pPuntaje);
			} else {
				return true;
			}
		}
	}
}


