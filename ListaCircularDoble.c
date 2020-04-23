#include <stdio.h>
#include <stdlib.h>

struct ListaCD{
	int dato;
	struct ListaCD * siguiente;
	struct ListaCD * anterior;
};

struct ListaCD * crear (int dato){
	struct ListaCD * nuevo = (struct ListaCD *)malloc(sizeof(struct ListaCD));
	if(nuevo == NULL){
		return NULL;
	}
	
	nuevo -> dato = dato;
	nuevo -> siguiente = nuevo;
	nuevo -> anterior = nuevo;
	return nuevo;
}

struct ListaCD * insertar (struct ListaCD * lista, int dato){
	if(lista == NULL){
		return NULL;
	}
	
	struct ListaCD * nuevo = crear(dato);
	struct ListaCD * aux = lista;
	struct ListaCD * aux2 = lista;
	
	if(aux -> siguiente == aux2){
		nuevo -> siguiente = aux;
		nuevo -> anterior = aux;
		aux -> siguiente = nuevo;
		aux -> anterior = nuevo;
		return nuevo;
	}else{
		while(aux -> siguiente != aux2){
			printf("2");
			aux = aux -> siguiente;
		}
		aux -> siguiente = nuevo;
		nuevo -> siguiente = lista;
		nuevo -> anterior = aux;
		return nuevo; 
	}
}

void mostrar (struct ListaCD * lista){
	if(lista == NULL){
		printf("No hay nada en la lista\n");
		return NULL;
	}
	
	struct ListaCD * aux = lista;
	struct ListaCD * aux2 = lista;
	do{
		printf("\nEstamos con el numero : %d", aux2 -> dato);
		printf("\nEl anterior a este es : %d", aux2 -> anterior -> dato);
		printf("\nEl siguiente a este es : %d\n", aux2 -> siguiente -> dato);
		aux2 = aux2 -> siguiente;
	}while(aux2 != aux);
	printf("\n");
}

struct ListaC * eliminar (struct ListaCD * lista, int pos){
	if(lista == NULL){
		return NULL;
	}
	
	struct ListaCD * aux = lista;
	struct ListaCD * aux2 = lista;
	int i = 1;
	
	if(pos == 1){
		lista = lista -> siguiente;
		do{
			aux2 -> siguiente;
		}while(aux2 -> siguiente != aux);
		aux -> siguiente -> anterior = aux2;
		aux2 -> siguiente = aux -> siguiente;
		return lista;
	}else{
		do{
			aux2 -> siguiente;
			i++;
		}while(i != pos - 1 );
		aux2 -> siguiente -> anterior = aux2;
		aux2 -> siguiente = aux2 -> siguiente -> siguiente;
	}
}

int main (void){
	
	struct ListaCD * listac = NULL;
	
	int a = 1;
	int b = 0;
	int c = 0;
	int d = 0;
	int i = 0;
	while (a!=0){
		printf("\nQue desea hacer?\n1.- Insertar\n2.- Mostrar\n3.- Eliminar un elemento en cierta posicion\n4.- Salir\n");
		scanf("%d",&b);
		switch (b){
			case 1:
				if(i==0){
					printf("\nIngrese el numero que desea agregar: ");
					scanf("%d",&c);
					listac = crear(c);
					i++;
				}else{
					printf("\nIngrese el numero que desea agregar: ");
					scanf("%d",&c);
					insertar(listac, c);
				}
				break;
			case 2:
				mostrar(listac);
				break;
			case 3:
				printf("\nIngrese la pocision del numero que desea eliminar: ");
				scanf("%d",&d);
				eliminar(listac,d);
				break;
			case 4:
				exit(0);
				break;
		}
	}
	
}
