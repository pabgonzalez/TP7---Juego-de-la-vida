//TRABAJO PRÁCTICO 7 - JUEGO DE LA VIDA
//GRUPO 2: DE VINCENTI, FIGUEROA, GONZALEZ, MATTALONI VARONA.

#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"


//Prototipos de funciones.


int main() {
	int i,j,gen=0;
	char c;
    char main_world [ROWS][COLS];									//Matriz actual. 
    char over_world [ROWS][COLS] = {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},		//Matriz de la próxima generación.
    								{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    								{' ',' ',' ',' ',' ','X','X','X',' ',' ',' ','X','X','X',' ',' ',' ',' ',' '},
    								{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    								{' ',' ',' ','X',' ',' ',' ',' ','X',' ','X',' ',' ',' ',' ','X',' ',' ',' '},
    								{' ',' ',' ','X',' ',' ',' ',' ','X',' ','X',' ',' ',' ',' ','X',' ',' ',' '},
    								{' ',' ',' ','X',' ',' ',' ',' ','X',' ','X',' ',' ',' ',' ','X',' ',' ',' '},
    								{' ',' ',' ',' ',' ','X','X','X',' ',' ',' ','X','X','X',' ',' ',' ',' ',' '},
    								{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    								{' ',' ',' ',' ',' ','X','X','X',' ',' ',' ','X','X','X',' ',' ',' ',' ',' '},
    								{' ',' ',' ','X',' ',' ',' ',' ','X',' ','X',' ',' ',' ',' ','X',' ',' ',' '},
    								{' ',' ',' ','X',' ',' ',' ',' ','X',' ','X',' ',' ',' ',' ','X',' ',' ',' '},
    								{' ',' ',' ','X',' ',' ',' ',' ','X',' ','X',' ',' ',' ',' ','X',' ',' ',' '},
    								{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    								{' ',' ',' ',' ',' ','X','X','X',' ',' ',' ','X','X','X',' ',' ',' ',' ',' '},
    								{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    								{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    								{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    								{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},};

	clean(main_world,ROWS,COLS);									//Limpia el marco de la matriz actual.
	clean(over_world,ROWS,COLS);									//Limpia el marco de la matriz de la siguiente generación.							
	printf("Presione Enter para ver la primera generación.\n");	
	
		//Mientras se presione enter se hace lo siguiente:
		while((c = getchar())== '\n') {								
    		collapse_worlds(main_world, over_world);				//Se actualiza la matriz actual.

			gen++;													//Se incrementa el número de generaciones.
			printf("Esta es la generación número %d\n" , gen);		

    		print_world(main_world);								//Imprime la disposición actual.
    
			for (i=1 ; i<=ROWS-1 ; i++) {							//Dentro de cada fila, sin incluir el marco. 
				for (j=1 ; j<=COLS-1 ; j++) {						//y para cada célula, sacando las celdas del marco. 
					update_cell(main_world , i , j, over_world);	//Actualiza el estado de la célula en la matriz de la próxima generación.
				}
    		}

    		printf("Presione Enter para ver el siguiente paso en la evolución\n");
		}
	printf("Game over\n");
    return 0;
}








