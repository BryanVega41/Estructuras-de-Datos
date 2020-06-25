#include <stdio.h>
#include <stdlib.h>

struct Lista {
 int dato;
 struct Lista *siguiente;
}; 

struct Lista * crear (int dato){
	struct Lista *nuevo = NULL;
	
	nuevo = (struct Lista *)malloc(sizeof(struct Lista));
	if(nuevo == NULL) {
	return NULL;
	}
	nuevo -> dato = dato;
	nuevo -> siguiente = NULL;
	return nuevo;
} 

struct Lista * insertar (struct Lista * lista, int dato){
 struct Lista * nueva = crear(dato);

 nueva -> siguiente = lista;
 return nueva;
} 
 
void mostrar (struct Lista * lista ){
 while(lista!=NULL){
  printf("%d, ",lista -> dato);
  lista = lista -> siguiente;
 }
 printf("\n"); 
}
 
int main (void){

 struct Lista * milista = crear(10);

 if(milista == NULL){
 	printf("No se pudo crear la lista por falta de memoria\n");
 	return -1;
 }

 milista = insertar (milista,12);
 milista = insertar (milista,27);
 milista = insertar (milista,2020);
 milista = insertar (milista,1);

 mostrar (milista);
 return 0;
}
