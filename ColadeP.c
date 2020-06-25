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
			printf("%d ", cola -> cola[i]);
			i++;
		}while(i <= 9);
		aux1 = 0;
		do{
			printf("%d ", cola -> cola[i]);
			i++;
		}while(i <= aux2);
		return cola;
	}else{
		i=aux1;
		do{
			printf("%d ", cola -> cola[i]);
			i++;
		}while(i <= aux2);
		printf("\n");
		return cola;
	}
}

struct Cola * crear (struct Cola * cola){
	cola = (struct Cola *) malloc (sizeof(struct Cola));
	if (cola == NULL){
		printf("\nNo hay espacio\n");
		return NULL;
	}
	cola -> frente = -1;
	cola -> atras = -1;
	int i = 0;
	for( i = 0 ; i < 10 ; i++ ){
		cola -> cola[i]=0;
	}
	return cola;
}

struct Cola * orden (struct Cola * C1, struct Cola * C2, struct Cola * C3){
	if (C1 == NULL || C2 == NULL || C3 == NULL){
		printf("\nNo llego nada\n");
		return NULL;
	}
	
	if(C1 -> frente == -1 && C1 -> atras == -1){
		if(C2 -> frente == -1 && C2 -> atras == -1){
			atender(C3);
			mostrar(C3);
			return C3;
		}else{
			atender(C2);
			mostrar(C2);
			return C2;
		}
	}else{
		atender(C1);
		mostrar(C1);
		return C1;
	}
}

int main (void){
	
		struct Cola * C1 = crear(C1);
		struct Cola * C2 = crear(C2);
		struct Cola * C3 = crear(C3);
		
		int a = 0;
		int b = 0;
		int c = 0;
		while(a!=4){
			printf("\nBienvenido al sistema de colas\nLe informamos que este sistema funciona con prioridades, del 1 al 3, siendo la prioridad 1 la mas alta\n");
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
					printf("\nQue prioridad tiene?\n");
					scanf("%d",&c);
					printf("\n");
					if(c == 1){
						formar(C1,b);
						printf("\nCola de prioridad 1 :\n");
						mostrar(C1);
					}
					if(c == 2){
						formar(C2,b);
						printf("\nCola de prioridad 2 :\n");
						mostrar(C2);
					}
					if(c == 3){
						formar(C3,b);
						printf("\nCola de prioridad 3 :\n");
						mostrar(C3);
					}
					break;
				case 2:
					orden(C1,C2,C3);
					break;
				case 3:
					//printf("\nLe recordamos que el cero representa 'vacio'");
					printf("\nQue cola desea mostrar? Le recordamos que estan ordenadas por prioridades\n");
					scanf("%d",&c);
					printf("\n");
					if(c == 1){
						printf("\nCola de prioridad 1 :\n");
						mostrar(C1);
					}
					if(c == 2){
						printf("\nCola de prioridad 2 :\n");
						mostrar(C2);
					}
					if(c == 3){
						printf("\nCola de prioridad 3 :\n");
						mostrar(C3);
					}
					break;
				case 4:
					exit(0);
			}
		}
			
}
