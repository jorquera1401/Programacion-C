#include <stdio.h>

#define MAX_EDAD 25
#define MIN_EDAD 17
#define MAX_PERSONA 100
main(){
	int cantidadEdades,edad,cantidad, frecuencia,i, n;
	int edades[MAX_PERSONA];
	
	printf("CANTIDAD DE EDADES : ");
	scanf("%d", &cantidadEdades);
	
	for(i = 0; i < cantidadEdades; i++){
	do{
		printf("Edad : ");
		scanf("%d", &edades[i]);
	}while(edades[i] < MIN_EDAD || edades[i] > MAX_EDAD);			
	}
	
	frecuencia = 0;
	for(n = 17; n<26; n++){		
		cantidad=0;		
		for(i=0; i<cantidadEdades;i++){
			if(edades[i] == n){
				cantidad ++;}	
		}
		if(frecuencia < cantidad){
			frecuencia = cantidad;	
			edad = n;
		}		
	}
	printf("Moda = %d \nFrecuencia = %d  \n", edad, frecuencia);
}


/* JJ's² Industries® 2016 ¢¢*/
