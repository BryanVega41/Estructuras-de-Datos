#include <stdio.h>
#include <stdlib.h>

struct Listad {
 int dato;
 struct Listad *siguiente;
 struct Listad *anterior;
}; 


struct Listad * crear (int dato){
	struct Listad *nuevo = NULL;
	
	nuevo = (struct Listad *)malloc(sizeof(struct Listad));
	
	if(nuevo == NULL) {
		return NULL;
	}
	
	nuevo->dato=dato;
	nuevo->siguiente = NULL;
	nuevo->anterior = NULL;
	return nuevo;
} 


struct Listad * insertar (struct Listad * listad, int dato){
 	struct Listad *nueva = crear(dato);
 	nueva->siguiente=listad;
 	nueva->anterior=NULL;
 	listad->anterior=nueva;
 	return nueva;
} 


void mostrar (struct Listad *listad ){
	struct Listad * aux = NULL;
	do{
		aux = listad;
		printf("\n%d",listad->dato);
		if(listad->anterior==NULL){
			printf("\nNo tiene un antecesor");
		}else{
			printf("\nEl anterior a este es: %d",(aux->anterior->dato));
		}
		if(listad->siguiente==NULL){
			printf("\nNo tiene un siguiente");
		}else {
			printf("\nEl siguiente a este es: %d",(aux->siguiente->dato));	
		}
		listad = listad->siguiente;
	}while(listad!=NULL);
		printf("\n"); 
}

struct Listad * eliminar(struct Listad *listad, int posicion){

	if(listad==NULL){
		return NULL;
	}
	struct Listad * aux = listad->anterior;
	struct Listad * aux2 = listad->siguiente;
	int c = 1;
	
	/*for(int i = 0 ; i > c ; i++){
		listad = listad->siguiente;
		aux = listad->anterior;
		aux2 = listad->siguiente;
	}*/
	do{
		if(c==posicion){
			if(c==1){
				listad = listad -> siguiente;
				listad -> anterior = NULL;
				c=0;
			}else{
			listad -> siguiente-> anterior = aux;
			listad -> anterior -> siguiente= aux2;
			c=0;
			}
		}else{
			listad = listad -> siguiente;
			aux = listad->anterior;
			aux2 = listad->siguiente;
			c++;
		}	
	}while(c!=0);
	/*if(listad==NULL){
		return NULL;
	}else{
		listad->anterior=aux2;
		listad->siguiente=aux;
	}*/
}


int main (void) {
	
	struct Listad *milistad = crear(10);
	
	if(milistad==NULL){
 		printf("No se pudo crear la lista por falta de memoria\n");
 		return -1;
 	}
 	
	int a = 1;
	int b = NULL;
	int c = NULL;
	int d = NULL;
	while (a!=0){
		
		printf("\nQue desea hacer?\n1 para insertar\n2 para mostrar\n3 para eliminar un elemento en especifico\n4 para salir\n");
		scanf("%d",&b);
		switch (b){
			case 1:
				printf("\nIngrese el numero que desea agregar: ");
				scanf("%d",&c);
				milistad = insertar(milistad, c);
				break;
			case 2:
				mostrar(milistad);
				break;
			case 3:
				printf("\nIngrese la pocision del numero que desea eliminar: ");
				scanf("%d",&d);
				milistad = eliminar(milistad,d);
				break;
			case 4:
				a=0;
				break;
		}
		
	}
	
}
