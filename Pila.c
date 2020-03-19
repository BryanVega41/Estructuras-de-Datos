#include <stdio.h>
#include <stdlib.h>

struct Pila{
	int pila[10];
	int tope;
};

struct Pila * crear (struct Pila * pila){
	
	pila = (struct Pila *) malloc (sizeof(struct Pila));
	if (pila == NULL){
		printf("\nNo hay espacio");
		return NULL;
	}
	
	pila -> tope = -1;
	return pila;
}

struct Pila * push (struct Pila * pila, int dato){
	if(pila == NULL){
		return NULL;
	}
	
	if(pila -> tope == 9){
		printf("\nNo hay espacio en la pila");
		return pila;
	}else{
		(pila -> tope)++;
		pila -> pila[(pila -> tope)] = dato;
		return pila;
	}
}

void mostrar (struct Pila * pila){	
	
	if(pila -> tope == -1){
		printf("\nLa pila esta vacia\n");
	}else{
		struct Pila * aux = crear(aux);
		int t = pila -> tope;
		aux -> tope = t;
		int i = 0;
		int j = 0;
		
		for(i = 0 ; i <= pila -> tope ; i++ ){
			aux -> pila [i] = pila -> pila[t];
			t--;
		}
		t = pila -> tope;
		for( j = 0 ; j <= pila -> tope ; j++){
			printf(", %d", aux -> pila[j]);
			pila -> pila[j] = aux -> pila[t];
			t--;
		}
		free(aux);
	}
}

struct Pila * pop (struct Pila * pila){
	if(pila == NULL){
		return NULL;
	}
	
	if(pila -> tope == -1){
		printf("\nNo hay ningun elemento en la pila");
	}else if (pila -> tope == 0){
		pila -> tope = -1;
	}else{
		pila -> tope --;
	}
	return pila;
}

struct Pila * invertir (struct Pila * pila){
	if(pila == NULL){
		return NULL;
	}
	
	struct Pila * aux = crear(aux);
	int t = pila -> tope;
	aux -> tope = t;
	int i = 0;
	
	for(i = 0 ; i <= pila -> tope ; i++ ){
		aux -> pila [i] = pila -> pila[i];
		printf("%d ", aux -> pila[i]);
	}
	return pila;
}

int main (void){
	struct Pila * pila = crear(pila);
	int a = 0;
	int b = 0;
	
	while (a!=5){
		
		printf("\nQue desea hacer?");
		printf("\n1.- Mostrar pila");
		printf("\n2.- Agregar a la pila");
		printf("\n3.- Quitar de la pila");
		printf("\n4.- Invertir pila");
		printf("\n5.- Salir\n");
		scanf("%d",&a);
		
		switch(a){
			case 1:
				mostrar(pila);
				break;
			case 2:
				printf("\nQue elemento desea agregar?\n");
				scanf("%d", &b);
				push(pila,b);
				break;
			case 3:
				pop(pila);
				break;
			case 4:
				invertir(pila);
				break;
		}
		
	}
}
