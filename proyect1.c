#include <stdio.h>
#include <math.h>
#define MAX 1024
/*struct que contiene las caracteristicas del circulo como id, punto central, radio y escala de grises*/
struct circulo{
	int id;
	int x0, y0;
	int radio;
	int escalaGris;
};
/*crea el struct del rectangulo con sus puntos de comienzo y fin, su id y la escala de Grises*/
struct rectangulo{
	int id;
	int x0, x1;
	int y0, y1;
	int escalaGris;
};
struct linea{
	int id;
	int x0, x1;
	int y0, y1;
	int escalaGris;

};
/*funcion que permite ingresar los valores de la linea*/
struct linea dibujarLinea(int id){
	struct linea li;
	do{
		li.id = id;
		printf("DIBUJAR LINEA\nID de linea %d \n", li.id );
	//	scanf("%d", &li.id);
		printf("Punto A (x,y): " );
		scanf("%d %d",&li.x0, &li.y0 );
		li.x0 = li.x0 - 1;li.y0= li.y0 -1;
		printf("Punto B (x,y): " );
		scanf("%d %d",&li.x1, &li.y1 );
		if(li.x1<li.x0||li.y1<li.y0){
			printf("Punto A no puede ser mayor al punto B\n" );
		}
	}while (li.x1<li.x0||li.y1<li.y0);
	li.x1 = li.x1 - 1;li.y1= li.y1 -1;
 	return li;
}
/*funcion que crea la linea trae los datos de la funcion anterior y setea los valores en la matriz*/
struct linea crearLinea(struct linea li,int matriz[MAX][MAX], int *escala){
	int i, m, b, pendiente;
	li.escalaGris = *escala;
	/*dibuja una linea vertical, si sus columnas son iguales*/
	if(li.y0 == li.y1){
		for(i=li.x0; i<= li.x1;i++){
			/*dibuja una linea vertical*/
			matriz[li.y0][i]=li.escalaGris;
		}
	}else{
		/*dibuja una linea horizontal*/
		if(li.x0 == li.x1){
			for(i=li.y0;i<=li.y1;i++){
				/*dibujar una linea horizontal*/
				matriz[i][li.x0]=li.escalaGris;
			}
		}else{
			/*calcula la distancia entre los puntos*/
			m=(li.y1 - li.y0)/(li.x1 - li.x0);
			b = li.y1 - m * li.x1;
			for(i=li.x0;i<=li.x1;i++){
				/*crea un grado de la pendiente, recorriendo y cambiando los valores que recorre */
				pendiente = m*i + b;
				matriz[pendiente][i]=li.escalaGris;
			}
		}
	}
}
/*funcion donde se piden los datos del recangulo a dibujar*/
struct rectangulo dibujarRectantulo(int matriz[MAX][MAX], int *escala, int id){
	struct rectangulo rect;
	int i, n,j;
	rect.escalaGris = *escala;
	rect.id = id;
	printf("\nDibujar rectangulo\n" );
	printf("Id del rectangulo: %d \n" ,rect.id);
//	scanf("%d",&rect.id );
	do{
		printf("Punto A (x,y): ");
		scanf("%d %d",&rect.x0, &rect.y0 );
		rect.x0 = rect.x0 -1; rect.y0=rect.y0-1;
		printf("Punto B (x,y): " );
		scanf("%d %d",&rect.x1,&rect.y1);
		rect.x1 = rect.x1 -1; rect.y1=rect.y1-1;

	if(rect.x0>=rect.x1||rect.y0>=rect.y1){
			printf("No se puede crear rectangulo, porque el punto A(%d, %d) es mayor que el punto B(%d, %d)\n", rect.x0, rect.y0,rect.x1, rect.y1);
		}
	}while(rect.x0>=rect.x1||rect.y0>=rect.y1);
	/*calcula la distancia entre el punto x0 y0 a x1 y1 cambia los valores por la distancia donde pasa*/
	for(i=rect.x0;i<=rect.x1;i++){
		matriz[i][rect.y0]=rect.escalaGris;
	}
	for(i=rect.y0;i<=rect.y1;i++){
		matriz[rect.x0][i]=rect.escalaGris;
	}
	for(i=rect.x1;i>=rect.x0;i--){
		matriz[i][rect.y1]=rect.escalaGris;
	}
	for(i=rect.y1;i>=rect.y0;i--){
		matriz[rect.x1][i]=rect.escalaGris;
	}
}

/*funcion que dibuja el circulo dentro de la matriz*/
struct circulo dibujarCirculo(int matriz[MAX][MAX], int *escala, int id){
	struct circulo cir;
	cir.escalaGris = *escala;
	cir.id = id;
	printf("\nDibujar circulo\n" );
	printf("Id del Ciculo: %d \n", cir.id);
	//scanf("%d", &cir.id);
	printf("Punto Central X1 Y1 : ");
	scanf("%d", &cir.x0);scanf("%d", &cir.y0);
	cir.x0 = cir.x0 -1; cir.y0=cir.y0-1;
	printf("Radio: ");
	scanf("%d", &cir.radio);

	int xi, yi, xt,yt, punto, i, j;
	/*se crea un punto inicial y final (cuadrado) para ir comparando cada punto de este cuadrado
	y a traves de la formula de la circunferencia saber que punto es igual al radio, una vez que se sabe se
	marca en la matriz*/
	xi = (cir.x0 - cir.radio)-1;
	yi = (cir.y0 -  cir.radio)-1;
	xt =(cir.x0 + cir.radio)+1;
	yt = (cir.y0 + cir.radio)+1;
	if(xi<1){
		xi =1;
	}
	if(yi<1){
			yi=1;
	}
	for(i=xi;i<xt;i++){
		for(j=yi;j<yt;j++){
			//punto = sqrt(pow((i-cir.x0),2)+pow((j-cir.y0),2));
			punto = sqrt(pow((i-cir.x0),2)+pow((j-cir.y0),2));

			if(punto==cir.radio){
				matriz[i][j]=cir.escalaGris;
			}
		}
	}
}

/*Funcion que permite volver a una funcion que esta creada despues de esta
llamada comunmente funcion prototipo, ya que es una referencia de la funcion original*/
void menu(int matriz[MAX][MAX], int *ancho, int *alto, int *escala,int total[2]);

/*Guarda los datos dibujados en un archivo*/
void guardar(int matriz[MAX][MAX], int *ancho, int *alto){
	FILE *archivo;
	int x,y,i;
	/*condicion, si el ancho y alto no supera los 1024 pixeles*/
	if(*ancho <= MAX || *ancho <=MAX){
		archivo = fopen("imagen.bpm", "w");
		fprintf(archivo, "%s\n","P2" );
		fprintf(archivo, "%d ",*ancho );
		fprintf(archivo, "%d\n",*alto );
		fprintf(archivo, "%d\n",255 );
		for(y=0;y<*alto;y++){
			for(x=0;x<*ancho;x++){
				/*condicion para agregar un salto de linea al momento de los 70 caracteres*/
					if(x%17==0){

						fprintf(archivo,"\n");
					}
				/*agrega espacio si la escala de gris es menor a 10*/
					if(matriz[x][y]<10){
							fprintf(archivo, "  %d ",matriz[x][y] );
					}else{
						/*agrega espacio a la matriz si la escala de gris es menor a 100 y mayor a 10*/
						if(matriz[x][y]<100){
							fprintf(archivo, " %d ",matriz[x][y] );
						}else{
							fprintf(archivo, "%d ",matriz[x][y] );
						}
					}
				}
			}

		fclose(archivo);
		printf("\n!Se han guardado los datos con éxito¡ \n" );
		}else{
		printf("\nNO SE PUDO GUARDAR\n" );
	}
}
/*contador de figuras creadas, almacena en un arreglo total, verifica que no hayan mas de 100 figuras*/
int verificar_cantidad(int total[3], int c){
	if (c<0) {
		total[0]=c+total[0];
		if(total[0]<0){
			total[0]=0;
		}
	}else{
	total[0] =  total[0]+ c;
	}
	return total[0];
}
/*funcion que permite llamar a las funciones crear figuras(linea, rectangulo, circulo)*/
void cantidad(int matriz[MAX][MAX],int figura, char tipo[14], int *escala, int total[3]){
	int count,i, n, totalArreglo,inicio;
	/*pregunta la cantidad de figuras que desea dibujar*/
	printf("¿Cantidad de %s a dibujar?\n",tipo );
	scanf("%d",&count );

  /*verifica la cantidad de figuras creadas, se llama a la funcion verificar_cantidad*/
	if(verificar_cantidad(total, count)>100){
		printf("A SUPERADO EL LIMITE TOTAL DE FIGURAS \n");
		/*si se ingreso una cantidad que supero a 100 figuras, esta resta esta cantidad para dejarlo
		como estaba anteriormente y colver a ingresar*/
		int nega = count -(count + count);
		verificar_cantidad(total, nega);
	}else{
		/*variable que permite saber la cantidad de figuras que faltan para dibujar*/
		n=count;
		if(figura==1){
			/*cuenta la cantidad de figuras creadas de este tipo*/
			total[1]=count + total[1];
			totalArreglo = total[1];
			inicio = (totalArreglo - count)+1;
			/*se crea un arreglo de struct linea para almacenar la informacion*/
			struct linea li[count];
			for(i=inicio;i<=totalArreglo;i++){
				printf("\nQuedan %d %s a dibujar\n",n,tipo );
				/*se llama a la funcion crear linea pasando como parametro la funcion dibujar, matriz y la escala de grises*/
				li[i] = crearLinea(dibujarLinea(i), matriz, escala);
				n-=1;
			}
		}else{
			if(figura==2){
				/*cuenta la cantidad de figuras creadas de este tipo*/
				total[2]=count + total[2];
				totalArreglo = total[2];
				inicio = (totalArreglo - count)+1;
				/*se crea un arreglo de struct linea para almacenar la informacion*/
				struct circulo circulo[count];
				for(i=inicio;i<=totalArreglo;i++){
					printf("\nQuedan %d %s a dibujar\n",n,tipo );
					/*se llama a la funcion crear circulo pasando como parametro matriz, la escala de grises y la id*/
					circulo[i]=dibujarCirculo(matriz, escala,i);
					n-=1;
				}
			}else{
				if(figura==3){
					/*cuenta la cantidad de figuras creadas de este tipo*/
					total[3]=count + total[3];
					totalArreglo = total[3];
					inicio = (totalArreglo - count)+1;
					/*se crea un arreglo de struct linea para almacenar la informacion*/
					struct rectangulo rectangulo[count];
					for(i=inicio;i<=totalArreglo;i++){
						printf("\nQuedan %d %s a dibujar\n",n,tipo );
						/*se llama a la funcion crear rectangulo pasando como parametro la matriz, escala de grises y la id de la figura */
						rectangulo[i]=dibujarRectantulo(matriz, escala, i);
						n-=1;
					}
				}
			}
		}
	}
}
/*funcion menuFiguras donde muestra las figuras que se puede crear*/
void menuFiguras(int matriz[MAX][MAX],int *ancho, int *alto, int *escala, int total[3]){
	/*variables que muestran el tipo de figura y despues se pasa al metodo cantidad()*/
	char linea[10]="Linea";
	char circulo[10]="Circulo";
	char rectangulo[14]="Rectangulo";
	int figura;
	do{
		/*menu de opciones donde se desplegan las figuras que se puede crear*/
		printf("\nMENU DE FIGURAS\n");
		printf("\nSeleccione figuras para dibujar\n" );
		printf("[1]. %s \n",linea );
		printf("[2]. %s \n",circulo );
		printf("[3]. %s \n",rectangulo );
		printf("[4]. Volver\n");
		scanf("%d",&figura );
		/*funcion que permite ver los casos a partir de la variable figura que la escribe el usuario*/
		switch (figura) {
			case 1:
				/*si el numero que ingreso el usario es 1, 2, 3 se llama la funcion cantidad, pasando como paramtro
				la matriz, opcion ingresada, el nombre de la figura, escala de grises, el arreglo de totales de figuras */
				cantidad(matriz, figura, linea, escala,total);
				break;
			case 2:
				cantidad(matriz, figura, circulo, escala , total);
				break;
			case 3:
				cantidad(matriz,figura,rectangulo, escala, total);
				break;
			/*en el caso 4 vuelve al menu principal*/
			case 4:
				menu(matriz,ancho, alto, escala, total);
				break;
			}

	}while(figura!=4);
}
/*funcion que permite modificar la escala de grises de la figura*/
int modificarEscala(){
	int escala;
	do {
		printf("Escala de gris que quiere modificar \n(NO PUEDE SUEPERAR A 255)\n: " );
		scanf("%d",&escala );
	} while(escala > 255|| escala < 0);
	printf("Bien ahora la escla de gris de tu figura es %d \n",escala);
	return escala;
}
/*menu principal del programa tiene como parametro la matriz, el ancho, alto, escala de grises, total de figuras*/
void menu(int matriz[MAX][MAX], int *ancho, int *alto, int *escala, int total[3]){
		int option;
		/*desplega el menu de opciones que se puede hacer dentro de la aplicacion*/
		printf("\nMENU PRINCIPAL\nSeleccione una de estas opciones: \n" );
		printf("[1]. Dibujar\n" );
		printf("[2]. Modificar Escala de Grises\n" );
		printf("[3]. Exportar archivo\n" );
		printf("[4]. Salir\n" );
		printf("Elija una opcion: " );
		scanf("%d",&option );
		switch (option) {
			case 1:
			/*si la opcion que escribio el usuario fue 1 se llama al menu de figuras pasando como parametros
			la matriz, ancho, alto, escala de grises  y el total de figuras a crear*/
				menuFiguras(matriz, ancho,alto, escala, total);
				break;;
			case 2:
			/*si la opcion fue 2 cambia el valor del puntero escala, llamando la funcion modificarEscala()
			y despues de cambiar el valor llama recursivamente esta funcion*/
				*escala = modificarEscala();
				menu(matriz,ancho, alto, escala, total);
				break;
			case 3:
			/*llama a la funcion guardar pasando como parametro, la matriz , ancho , alto.
			Despues llama recursivamente a la misma funcion*/
				guardar(matriz, ancho, alto);
				menu(matriz,ancho, alto, escala, total);
				break;
			case 4:
			/*si la opcion fue 4 se sale del programa*/
				printf("Gracias por usar este programa.\n");
				break ;
			}
}
main(){
	/*variables que se pasaran como parametros, algunas no se cambian el valor. Se hace desde aqui,
	ya que este metodo se pasa una sola vez, por ende no se perderan los valores.*/
	int matriz[MAX][MAX];
	int i,j, ancho, escalaGris, alto, escala, total[3];
	/*como es el inicio se debe establecer las dimensiones de la imagen a crear*/
	printf("\nBienvenido al Programa \nComenzaremos a establecer los valores de la imagena a crear \n" );
	do{
		printf("Recomendacion; maximo tamaño a crear es %d de ancho y %d de alto \n",MAX , MAX);
		printf("Ingresar Ancho: " );
		scanf("%d", &ancho);
		printf("Ingresar Alto: ");
		scanf("%d",&alto );
	}while (ancho>MAX||alto>MAX);
	/*se crea la imagen en blanco*/
	for(i=0;i<ancho;i++){
		for(j=0;j<alto;j++){
			matriz[i][j]=255;
		}
	}
	/*se llama a la funcion menu pasando como parametros la matriz creada anteriormente, alto, ancho,
	escala, total. Estas ultimas no tienen valor para que mas adelante se modifique*/
	menu(matriz, &ancho,&alto, &escala, total);
}
