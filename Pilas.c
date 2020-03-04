include <stdio.h>
include <stdlib.h>

struct Pila{
	int valor;
	struct lista *siguiente;
}

struct Pila * Invertir (struct Pila *pila){
	if(pila==NULL){ return -1;}
	aux = (struct Pila *) malloc (sizeof (struct Pila));
	while(pila->siguiente!=NULL){
	 
