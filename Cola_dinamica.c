#include <stdio.h>
#include <stdlib.h>

struct Nodo{
	int dato;
	struct Nodo * enfrente;
	struct Nodo * atras;
};

struct Nodo * crear(int dato){
	struct Nodo * nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
	if(nuevo == NULL){
		printf("\nNo hay espacio en la memoria\n");
		return NULL;
	}
	nuevo -> dato = dato;
	nuevo -> enfrente = NULL;
	nuevo -> atras = NULL;
}

struct Nodo * insertar (struct Nodo * cola , int dato){
	if(cola == NULL){
		return crear(dato);
	}else{
		struct Nodo * aux = cola;
		struct Nodo * nueva = crear(dato);
		while(cola -> atras != NULL){
			cola = cola -> atras;
		} 
		cola -> atras = nueva;
		nueva -> enfrente = cola;
		return aux;
	}
}

struct Nodo * eliminar(struct Nodo * cola){
	if(cola == NULL){
		printf("\nLa cola esta vacia\n");
		return NULL;
	}else if(cola -> atras == NULL && cola -> enfrente == NULL){
		free(cola);
		return NULL;
	}else{
		struct Nodo * nueva = cola -> atras;
		cola -> atras -> enfrente = NULL;
		free(cola);
		return nueva;
	}
}

void mostrar(struct Nodo * cola){
	if(cola == NULL){
		printf("\nNo hay cola que mostrar\n");
	}else{
		while(cola != NULL){
			printf("%d ", cola -> dato);
			cola = cola -> atras;
		}
	}
}

int main(void){
	struct Nodo * cola = NULL;
	int a = NULL;
	int b = NULL;
	
	do{
		printf("\nQue desea hacer con la cola?");
		printf("\n1.- Formar a alguien");
		printf("\n2.- Atender a alguien");
		printf("\n3.- Mostrar la cola");
		printf("\n4.- Salir\n");
		scanf("%d", &a);
		switch(a){
			case 1:
				printf("\nQue numero desea formar?\n");
				scanf("%d",&b);
				cola = insertar(cola,b);
				break;
			case 2:
				cola = eliminar(cola);
				break;
			case 3:
				mostrar(cola);
				break;
			case 4:
				exit(0);
				break;
		}
	}while(a!=4);
}
