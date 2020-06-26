#include <stdio.h>
#include <stdlib.h>

struct LP{
	int dato;
	struct LP * anterior;
	struct LP * siguiente;
};

struct LP * crear (int dato){
	struct LP * nueva = NULL;
	nueva = (struct LP *)malloc(sizeof(struct LP));
	nueva -> dato = dato;
	nueva -> siguiente = NULL;
	nueva -> anterior = NULL;
	return nueva;
}

struct LP * push (struct LP * lp , int dato){
	if(lp == NULL){
		return crear(dato);
	}else {
		struct LP * nueva = crear(dato);
		lp -> siguiente = nueva;
		nueva -> anterior = lp;
		return nueva;
	}
}

void mostrar(struct LP * lp){
	if(lp == NULL){
		printf("\nNo hay pila que mostrar\n");
	}else{
		printf("\nTope: ");
		while(lp != NULL){
			printf("%d ", lp -> dato);
			lp = lp -> anterior;
		}
		printf(" Base\n");
	}
	printf("\n");
}

struct LP * pop_tope (struct LP * lp){
	if(lp == NULL){
		printf("\nNo hay pila que manejar\n");
	}else{
		struct LP * aux = lp;
		lp = lp -> anterior;
		lp -> siguiente = NULL;
		free(aux);
	}
	return lp;
}

int main(void){
	struct LP * lp = NULL;
	int a = NULL;
	int b = NULL;
	int c = NULL;
	
	do{
		printf("\nQue desea hacer?");
		printf("\n1.- Insertar un elemento");
		printf("\n2.- Eliminar el tope");
		printf("\n3.- Mostrar la pila");
		printf("\n4.- Salir\n");
		scanf("%d", &a);
		switch(a){
			case 1:
				printf("\nQue numero desea agregar?:\n");
				scanf("%d",&b);
				lp = push(lp,b);
				break;
			case 2:
				lp = pop_tope(lp);
				break;
			case 3:
				mostrar(lp);
				break;
			case 4:
				exit(0);
				break;
			default:
				exit(0);
				break;
		}
	}while(a != 0);
}
