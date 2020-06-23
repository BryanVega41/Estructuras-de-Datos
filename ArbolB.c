#include <stdio.h>
#include <stdlib.h>

struct Nodo{
	int dato;
	struct Nodo * der;
	struct Nodo * izq;
};

struct Nodo * crearNodo(int dato){
	struct Nodo * nuevo = NULL;
	nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
	if(nuevo==NULL) {printf("Nada puede malir sal");return NULL;}
	
	nuevo -> dato = dato;
	nuevo -> der = NULL;
	nuevo -> izq = NULL;
	
	return nuevo;
}

struct Nodo * insertar(struct Nodo * raiz, int dato){
	if(raiz == NULL){
		return crearNodo(dato);
	}else{
		int vraiz = raiz -> dato;
		if(dato < vraiz){
			raiz -> izq = insertar(raiz -> izq , dato);
		}else{
			raiz -> der = insertar(raiz -> der , dato);
		}
	}
	return raiz;
}

void mostrar_pre(struct Nodo * arbol){
	if(arbol == NULL){
		return;
	}
	printf("%d, ", arbol -> dato);
	mostrar_pre(arbol -> izq);
	mostrar_pre(arbol -> der);
}

void mostrar_in(struct Nodo * arbol){
	if(arbol == NULL){
		return;
	}
	mostrar_in(arbol -> izq);
	printf("%d, ", arbol -> dato);
	mostrar_in(arbol -> der);
}

void mostrar_post(struct Nodo * arbol){
	if(arbol == NULL){
		return;
	}
	mostrar_post(arbol -> izq);
	mostrar_post(arbol -> der);
	printf("%d, ", arbol -> dato);
}

void buscar(struct Nodo * arbol, int dato){
	if(arbol == NULL){
		printf("\nEl arbol esta vacio");
	}else if(arbol -> dato == dato){
		printf("\nLlegamos al dato, si esta!");
	}else if(dato < arbol -> dato){
		printf("\n Vamos por la izquierda");
		buscar(arbol -> izq, dato);
	}else if(dato > arbol -> dato){
		printf("\n Vamos por la derecha");
		buscar(arbol -> der,dato);
	}
}

struct Nodo * eliminar(struct Nodo * raiz, int dato){
	struct Nodo * nodo_eliminar = NULL;
	struct Nodo * padre = NULL;
	
	if(raiz == NULL){
		printf("\nEL arbol esta vacio");
		return;
	}
	
	nodo_eliminar = raiz;
	
	while(nodo_eliminar -> dato != dato){
		if(dato < nodo_eliminar -> dato){
			padre = nodo_eliminar;
			nodo_eliminar = nodo_eliminar -> izq;
		} else {
			padre = nodo_eliminar;
			nodo_eliminar = nodo_eliminar -> der;
		}
		
		if(nodo_eliminar == NULL){
			break;
		}
	}
	
	if(nodo_eliminar == NULL){
		return raiz;
		printf("\nEL dato no esta en el arbol");
	}
	
	if(nodo_eliminar -> der == NULL && nodo_eliminar -> izq == NULL){
		if(padre -> dato > nodo_eliminar -> dato){
			padre -> izq = NULL;
		}else{
			padre -> der = NULL;
		}
		free(nodo_eliminar);
		return raiz;
	}
	
	if(nodo_eliminar -> der == NULL){
		if(padre -> izq == nodo_eliminar){
			padre -> izq = nodo_eliminar -> izq;
		}else{
			padre -> der = nodo_eliminar -> izq;
		}
		free(nodo_eliminar);
		return raiz;
	}
	
	if(nodo_eliminar -> izq == NULL){
		if(padre -> izq == nodo_eliminar){
			padre -> izq = nodo_eliminar -> der;
		}else{
			padre -> der = nodo_eliminar -> der;
		}
		free(nodo_eliminar);
		return raiz;
	}
	
	struct Nodo * bajo = NULL;
	struct Nodo * padre_bajo = NULL;
	
	bajo = nodo_eliminar -> der;
	padre_bajo = nodo_eliminar;
	
	while(bajo -> izq != NULL){
		padre_bajo = bajo;
		bajo = bajo -> izq;
	}
	
	nodo_eliminar -> dato = bajo -> dato;
	
	if(padre_bajo -> der == bajo){
		padre_bajo -> der = bajo -> der;
	}else {
		padre_bajo -> izq = bajo -> der;
	}
	free(bajo);
	return raiz;
}

int main (){
	struct Nodo * arbol = NULL;
	int a = NULL;
	int b = NULL;
	int c = NULL;
	int d = NULL;
	int e = NULL;
	
	do{
		printf("\nQue desea hacer con el arbol?");
		printf("\n1.- Insertar nodo");
		printf("\n2.- Mostrar arbol");
		printf("\n3.- Buscar en el arbol");
		printf("\n4.- Eliminar nodo");
		printf("\n5.- Salir\n");
		scanf("%d",&a);
		
		switch(a){
			case 1:
				printf("\nQue numero desea agregar?\n");
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
				if(c == 1){
					mostrar_pre(arbol);
				}else if(c == 2){
					mostrar_in(arbol);
				}else if(c == 3){
					mostrar_post(arbol);
				} 
				break;
			case 3:
				printf("\nQue numero desea saber si se encuentra en el arbol?\n");
				scanf("%d", &d);
				buscar(arbol,d);
				break;
			case 4:
				printf("\nQue nodo desea eliminar?\n");
				scanf("%d", &e);
				eliminar(arbol, e);
				break;
			default:
				exit(0);
				break;
		}
	}while(a!=0);
	return 0;
}
