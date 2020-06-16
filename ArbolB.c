#include <stdio.h>
#include <stdlib.h>

struct Nodo{
	int dato;
	struct Nodo * der;
	struct Nodo * izq;
};

Nodo * crearNodo(int dato){
	struct Nodo * nuevo = NULL;
	nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
	
	nuevo -> dato = dato;
	nuevo -> der = NULL;
	nuevo -> izq = NULL;
	
	return nuevo;
}

struct Nodo * insertar(struct Nodo * arbol, int dato){
	struct Nodo * raiz = arbol;
	if(arbol == NULL){
		struct Nodo * nuevo = crearNodo(dato);
	}else{
		int raiz = arbol -> dato;
		if(dato<raiz){
			insertar(arbol -> izq, dato);
			
		}else{
			insertar(arbol -> der, dato);
		}
	}
	return raiz;
}

void mostrar_pre(struct Nodo * arbol){
	printf("%d,",arbol->dato);
	mostrar_pre(arbol->izq);
	mostrar_pre(arbol->der);
}

void mostrar_in(struct Nodo * arbol){
	mostrar_pre(arbol->izq);
	printf("%d,",arbol->dato);
	mostrar_pre(arbol->der);
}

void mostrar_post(struct Nodo * arbol){
	mostrar_pre(arbol->izq);
	mostrar_pre(arbol->der);
	printf("%d,",arbol->dato);
}

int main (){
	struct Nodo * arbol = NULL;
	int a = NULL;
	int b = NULL;
	int c = NULL;
	
	do{
		//system("cls");
		printf("\nQue desea hacer con el arbol?");
		printf("\n1.- Insertar nodo");
		printf("\n2.- Mostrar arbol");
		printf("\n3.- Eliminar nodo");
		printf("\n4.- Salir\n");
		scanf("%d",&a);
		
		switch(a){
			case 1:
				printf("\nQue numero desea agregar?");
				scanf("%d",&b);
				arbol = insertar(arbol , b);
				break;
			case 2:
					printf("\nQue forma canonica desea?");
					printf("\n1.- Pre-orden");
					printf("\n2.- In-orden");
					printf("\n3.- Post-orden\n");
					scanf("%d",&c);
					printf("\n");
					if(c=1) mostrar_pre(arbol);
					if(c=2) mostrar_in(arbol);
					if(c=3) mostrar_post(arbol);
				break;
			case 3:
				break;
			case 4:
				exit(0);
				break;
			default:
				exit(0);
				break;
		}
	}while(a!=0);
	return 0;
}
