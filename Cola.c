#include <stdio.h>
#include <stdlib.h>

struct Cola {
	int cola[10];
	int frente;
	int atras;
};

struct Cola * formar (struct Cola * cola, int dato){
	if (cola==NULL){
		return NULL;
	}
	if(cola -> frente == -1 && cola -> atras == -1){
		cola -> cola[0] = dato;
		cola -> frente = (cola -> frente) + 1;
		cola -> atras = (cola -> atras) + 1;
	}else if(cola -> atras == /*(sizeof(cola -> cola)/sizeof(cola -> cola[0]))*/ 10 && cola -> frente == 0 || cola -> atras == ((cola ->frente)-1)){
		printf("\nLa cola esta llena, atienda a uno y vuelva a intentarlo");
	}else{
		int posicion = NULL;
		posicion =  ((cola -> atras) + 1) % /*(sizeof(cola -> cola)/sizeof(cola -> cola[0])*/ 10;
		cola -> cola[posicion] = dato;
		cola -> atras = (cola -> atras) + 1;
	}
	return cola;
}

struct Cola * atender (struct Cola * cola){
	if (cola==NULL){
		return NULL;
	}
	if(cola -> frente == -1 || cola -> atras == -1){
		printf("\nNo hay nadie en la cola");
	}
	if(cola -> frente == /*(sizeof(cola -> cola)/sizeof(cola -> cola[0]))*/ 10){
		cola -> frente = 0;
	}else {
		(cola -> frente)++;
	}
	return cola;
}

struct Cola * mostrar(struct Cola * cola){
	
	if(cola == NULL){
		return NULL;
	}
	if(cola -> frente == -1 || cola -> atras == -1){
		printf("\nNo hay nadie en la fila\n");
		return NULL;
	}
	
	int aux1 = cola -> frente;
	int aux2 = cola -> atras;
	int i = NULL;
	
	printf("\nEn este caso, el cero cuenta como que no hay nadie en esa pocision\n");
	if(aux2<aux1){
		i = aux1;
		do{
			printf("%d, ", cola[i]);
			i++;
		}while(i != /*(sizeof(cola -> cola)/sizeof(cola -> cola[0]))*/ 10);
		aux1 = 0;
		for( i = aux1 ; i = aux2 ; i++){
		printf("%d, ", cola[i]);
		}
	}else{
		for( i = aux1 ; i = aux2 ; i++){
			printf("%d, ", cola[i]);
		}
	}
	return cola;
}

struct Cola * crear (struct Cola * cola){
	cola = (struct Cola *) malloc (sizeof(struct Cola));
	cola -> frente = -1;
	cola -> atras = -1;
	for(int i = 0 ; i < 10 ; i++ ){
		cola -> cola[i]=0;
	}
	return cola;
}

int main (void){
	
		struct Cola * cola = crear(cola);
		int a = NULL;
		int b = NULL;
		a=1;
		while(a!=3){
			printf("\nQue desea hacer?");
			printf("\n1.- Formar a alguien");
			printf("\n2.- Atender a alguien");
			printf("\n3.- Mostrar la fila");
			printf("\n4.- Salir\n");
			scanf("%d", &a);
			switch(a){
				case 1:
					printf("\nA quien desea formar?");
					scanf("%d",&b);
					formar(cola,b);
					break;
				case 2:
					atender(cola);
					break;
				case 3:
					mostrar(cola);
					break;
			}
		}
			
}
