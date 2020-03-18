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
		return cola;
	}else if(cola -> atras ==  9 && cola -> frente == 0 || cola -> atras == ((cola ->frente)-1)){
		printf("\nLa cola esta llena, atienda a uno y vuelva a intentarlo");
		return cola;
	}else{
		int posicion = 0;
		posicion =  ((cola -> atras)+1) %  10;
		cola -> cola[posicion] = dato;
		cola -> atras = posicion;
		return cola;
	}
}

struct Cola * atender (struct Cola * cola){
	if (cola==NULL){
		return NULL;
	}
	if(cola -> frente == -1 || cola -> atras == -1){
		//printf("\nNo hay nadie en la cola");
		return cola;
	}
	if(cola -> frente == cola -> atras){
		cola ->  frente = -1;
		cola -> atras = -1;
		return cola;
	}
	if(cola -> frente ==  9){
		cola -> frente = 0;
		return cola;
	}else {
		(cola -> frente)++;
		return cola;
	}
}

struct Cola * mostrar(struct Cola * cola){
	
	if(cola == NULL){
		return NULL;
	}
	if(cola -> frente == -1 || cola -> atras == -1){
		printf("\nNo hay nadie en la cola\n");
		return cola;
	}
	
	int aux1 = cola -> frente;
	int aux2 = cola -> atras;
	int i = 0;
	
	if(aux2<aux1){
		i = aux1;
		do{
			printf("%d, ", cola -> cola[i]);
			i++;
		}while(i != 9);
		aux1 = 0;
		for( i = aux1 ; i = aux2 ; i++){
			printf("%d, ", cola -> cola[i]);
		}
		return cola;
	}else{
		i=aux1;
		do{
			printf("%d, ", cola -> cola[i]);
			i++;
		}while(i<=aux2);
		return cola;
	}
}

struct Cola * crear (struct Cola * cola){
	cola = (struct Cola *) malloc (sizeof(struct Cola));
	if (cola == NULL){
		printf("\n No jalo jaja \n");
		return NULL;
	}
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
		a=0;
		while(a!=4){
			printf("\nQue desea hacer?");
			printf("\n1.- Formar a alguien");
			printf("\n2.- Atender a alguien");
			printf("\n3.- Mostrar la fila");
			printf("\n4.- Salir\n");
			scanf("%d", &a);
			switch(a){
				case 1:
					printf("\nA quien desea formar?\n");
					scanf("%d",&b);
					formar(cola,b);
					mostrar(cola);
					break;
				case 2:
					atender(cola);
					mostrar(cola);
					break;
				case 3:
					mostrar(cola);
					break;
				case 4:
					exit(0);
			}
		}
			
}
