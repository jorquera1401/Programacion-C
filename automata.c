#include <stdio.h>

// Dimension maxima del espacio celular
#define N 100

// Tamano maximo para el nombre del archivo
#define MAX_NOMBRE 30
int verificar(int A[N][N], int fil, int col){
	int count = 0;
	if(A[fil][col+1]==1){
		count +=1;
	}
	if(A[fil][col-1]==1){
		count +=1;
	}
	if(A[fil+1][col]==1){
		count +=1;
	}
	if(A[fil-1][col]==1){
		count +=1;
	}
	if(A[fil+1][col+1]==1){
		count +=1;
	}
	if(A[fil-1][col+1]==1){
		count +=1;
	}
	if(A[fil+1][col-1]==1){
		count +=1;
	}
	if(A[fil-1][col-1]==1){
		count +=1;
	}
	return count;
	
}
int agregar(int A[N][N], int fil, int col){
	int c = verificar(A, fil,col);
	if(c == 2||c==3){
		return 1;
	}else{
		return 0;
	}
}
main() {
   int A[N][N];    // Estado inicial
   int B[N][N];    // Estado final
   int n,i;          // Dimension del espacio celular
   int fil, col;   // Contadores para los ciclos
   char archivo[MAX_NOMBRE];   // Nombre del archivo
   FILE *fh;       // Descriptor de archivo

   // Lee nombre del archivo
   printf("Nombre archivo: ");
   scanf("%s", archivo);

   // Abre archivo y termina si hay error
   fh = fopen(archivo, "r");
   if (fh != NULL) {
      // Lee tamano de la poblacion
      fscanf(fh, "%d", &n);

      // Inicializa filas y columnas que forman el marco
      for (i=0; i<=n+1; i++) {
         A[0][i] = 0;
         A[n+1][i] = 0;
         A[i][0] = 0;
         A[i][n+1] = 0;
      }

      // Lee estado inicial del automata
      for (fil=1; fil<=n; fil++) {
         for (col=1; col<=n; col++) {
            fscanf(fh, "%d", &(A[fil][col]));
         }
      }

      // Imprime estado inicial del automata
      printf("Estado inicial:\n");
      for (fil=1; fil<=n; fil++) {
         for (col=1; col<=n; col++) {
            printf("%d ", A[fil][col]);
         }
         printf("\n");
      }

      // Determina nuevo estado del automata en matriz B
      // Aqui debe ir su solucion
		for(fil=1;fil<=n;fil++){
			for(col=1;col<=n;col++){
				B[fil][col]= agregar(A,fil,col);
			}
			
		}

      // Imprime estado final del automata
      printf("Estado final:\n");
      for (fil=1; fil<=n; fil++) {
         for (col=1; col<=n; col++) {
            printf("%d ", B[fil][col]);
         }
         printf("\n");
      }
   }
}
