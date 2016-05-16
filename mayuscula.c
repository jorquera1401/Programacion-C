#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*funcion para transfomrar de minuscula
  a mayuscula */
char cMay(char letra){
  letra = toupper(letra);
  return letra;
}
/*funcion para convertir grados de celsius a farenheit*/
float convertir(char tipo, float temperatura){
    float ntemperatura;
    if(tipo == 'c'){
      ntemperatura = (temperatura-32)*(5.0/9);

    }else{
      if(tipo == 'f'){
        ntemperatura = (temperatura+32)/(5.0*9);
      }
    }
    return ntemperatura;
}
 main() {
   char nombre[10];
   fgets(nombre,10,stdin);

   int i;
   for(i=0;i<strlen(nombre); i++){
     nombre[i]= cMay(nombre[i]);
   }

   printf("%s\n",nombre );
   char tipo; float temperatura;
   printf("que tipo de temperatura quiere cambiar 'c' Celsius o 'f' Farenheit\n" );
   scanf("%s", &tipo);
   printf("Ingrese temperatura en %s° \n",&tipo );
   scanf("%f",&temperatura );
   printf(" %s %.0f° es %.0f° \n",&tipo, temperatura,convertir(tipo,temperatura) );
}
