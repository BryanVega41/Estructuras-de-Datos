#include <stdio.h>
#include <stdlib.h>

struct ListaC{
	int dato;
	struct ListaC * siguiente;
};

struct ListaC * crear ( int dato){
	struct ListaC * nuevo = (struct ListaC *)malloc(sizeof(struct ListaC));
	if(nuevo == NULL) {
		return NULL;
	}
	nuevo -> dato = dato;
	nuevo -> siguiente = nuevo;
	return nuevo;
} 

struct ListaC * insertar (struct ListaC * listac, int dato){
	if(listac == NULL){
		return NULL;
	}
	
	struct ListaC * nuevo = crear(dato);
	struct ListaC * aux = listac;
	struct ListaC * aux2 = listac;
	
	if(aux -> siguiente == aux2){
		//printf("1");
		//printf("Valor de nuevo %d",nuevo -> dato);
		nuevo-> siguiente = aux;
		aux -> siguiente = nuevo;
		return nuevo;
	}else{
		while(aux -> siguiente != aux2){
			printf("2");
			aux = aux -> siguiente;
		}
		aux -> siguiente = nuevo;
		nuevo -> siguiente = listac;
		return nuevo; 
	}
}

void mostrar (struct ListaC * listac){
	
	struct ListaC * aux = listac;
	struct ListaC * aux2 = listac;
	aux2 = aux2 -> siguiente;
	do{
		printf("%d, ", aux2 -> dato);
		aux2 = aux2 -> siguiente;
	}while(aux2 != aux);
	printf("\n");
}

struct ListaC * eliminar (struct ListaC * listac, int pos){
	if(listac == NULL){
		return NULL;
	}
	
	struct ListaC * aux = listac;
	struct ListaC * aux2 = listac;
	int i = 1;
	
	if(pos == 1){
		listac = listac -> siguiente;
		do{
			aux2 -> siguiente;
		}while(aux2 -> siguiente != aux);
		aux2 -> siguiente = aux -> siguiente;
		return listac;
	}else{
		do{
			aux2 -> siguiente;
			i++;
		}while(i != pos - 1 );
		aux2 -> siguiente = aux2 -> siguiente -> siguiente;
	}
}

int main (void){
	
	//int i = 0;
	struct ListaC * listac = crear(10);
	
	int a = 1;
	int b = 0;
	int c = 0;
	int d = 0;
	while (a!=0){
		printf("\nQue desea hacer?\n1.- Insertar\n2.- Mostrar\n3.- Eliminar un elemento en cierta posicion\n4.- Salir\n");
		scanf("%d",&b);
		switch (b){
			case 1:
				printf("\nIngrese el numero que desea agregar: ");
				scanf("%d",&c);
				insertar(listac, c);
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
