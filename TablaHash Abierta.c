#include <stdio.h>
#include <stdlib.h>

struct lista{
	int dato;
	struct lista * siguiente;
};

struct TablaHash{
	struct lista * TH[100];
};

int FunHash (int dato){
		int pos = (dato * dato) % 100;
		return pos; 
}

struct TablaHash * crear(){
	int i = 0;
	struct TablaHash * nueva = NULL;
	nueva = (struct TablaHash *)malloc(sizeof(struct TablaHash));
	if (nueva == NULL){
		return NULL;
	}else{
		do{
			nueva -> TH[i] = NULL;
			i++;
		}while(i<=99);
	}
	return nueva;
}

void Agregar (struct TablaHash * TH,int dato){
	int pos = FunHash(dato);
	struct lista * aux = TH -> TH[pos];
	TH -> TH[pos] = insertarlista(aux,dato);
}

void Mostrar(struct TablaHash * TH){
	int a = 0;
	for( a=0 ; a<=99 ; a++){
		mostrarlista(TH[a]);
	}
} 

void mostrarlista(struct lista * lista){
	struct lista * aux = NULL;
	do{
		aux = lista;
		printf("\n%d",lista->dato);	
		lista = lista->siguiente;
	}while(lista!=NULL);
		printf("\n"); 
}

struct lista* insertarlista(struct lista* lista , int dato){
 	struct lista * nueva = (struct lista *)malloc(sizeof(struct lista));
 	if(nueva == NULL) return NULL;
 	nueva -> dato = dato;
 	nueva -> siguiente = lista;
 	return nueva;
}

int main(void){
	struct TablaHash * TablaH = crear();
	printf("Bienvenido a la tabla hash");
	int a = 0;
	int b = 0;
	do{
		printf("Que desea hacer?");
		printf("1.- Agregar a la tabla");
		printf("2.- Eliminar de la tabla");
		printf("3.- Mostrar la tabla");
		printf("4.- Salir del programa");
		sacnf("%d",&a);
		switch(a){
			case 1:
				printf("Que numero desea agregar?");
				scanf("%d", &b);
				Agregar(TablaH , b);
				break;
			case 2:
				
				break;
			case 3:
				Mostrar(TablaH);
				break;
			case 4:
				exit(0);
				break;
		}
		
	}while(a!=0);
}
