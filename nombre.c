#include <stdio.h>
#include <string.h>

int main() {
  /* code */
  char nombre[20], vocales[5], nuevoNombre[20],nombreConsonante[20];
  int i,cantidad=0,x=0, n, a=0;
  vocales[0]='a';
  vocales[1]='e';
  vocales[2]='i';
  vocales[3]='o';
  vocales[4]='u';

  scanf("%s", nombre);
  printf("Tu nombre es : %s\n", nombre );
  printf("Cantidad de caracteres: %c \n",nombre[3]);
  for(i=0; i< strlen(nombre);i++){
    for(n=0;n<strlen(vocales);++n){
      if(nombre[i]==vocales[n]){
        cantidad += 1;
        nuevoNombre[a]=nombre[i];
        a+=1;
        nombre[i]=' ';
      }
    }

  }
  printf("Cantidad de vocales %d\n",cantidad );
  printf("Nombre con solo vocales :%s\n",nombre );
  printf("Nombre con consonantes es :%s \n", nombreConsonante );

}
