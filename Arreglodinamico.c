#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void){
	
	int *a,*b,x,i,j,k;
	a = (int *) calloc (1,sizeof(int));
	a[0]=1;
	
	printf("\nBienvenido al arreglo dinamico, ingrese el limite del mismo \n");
	scanf("%d",&x);
	
	if(x<=0||x>100000000){
		printf("\nIngrese valores entre 0<x<10^8\n");
		exit(-1);
	}		
	
	b = (int *) calloc (x,sizeof(int));
	
	system("@cls||clear");
	
	for( i = 1 ; i <= x ; i++){
		
		for(j = 0 ; j < i ; j++){
			b[j]=a[j];
			//printf("%d ",b[j]);
		}
		//printf("\nAcabo el primer if\n");
		usleep(250);
		
		free(a);
		a = (int *) calloc (i,sizeof(int));
		j=0;
		
		for(j = 0 ; j < i ; j++){
			a[j]=b[j];
		}
		
		a[i-1]=i;
		//printf("%d",i);
		usleep(250);
		
		for( k = 0 ; k < i ; k++){
			printf("%d ",a[k]);
		}
		printf("\n");
		
	}
}
