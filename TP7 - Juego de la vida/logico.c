/*******************************************************************************
  @file     +logico.c+
  @brief    +Realiza las tareas lógicas del juego+
  @author   +GRUPO 2+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include "logico.h"

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
static void set_cell_state(char world[ROWS][COLS], int i, int j, int state);
static int get_cell_state(char);

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

//clean recibe la dirección de una matriz, su cantidad de filas y 
//columnas y limpia su marco.
void clean (char world [ROWS] [COLS], int i, int j) {
	int a;	 
	for (a=0; a<j; a++) {
		set_cell_state(world,0,a,DEAD);						//Limpia primera fila.
		set_cell_state(world,i-1,a,DEAD);					//Limpia la última fila.
	}
	for (a=1 ; a<=i-2 ; a++) {
		set_cell_state(world,a,0,DEAD);						//Limpia la primer columna, excepto las celdas que ya se habían limpiado.
		set_cell_state(world,a,j-1,DEAD);					//Limpia la última columna, excepto las celdas que ya se habían limpiado.	
	}
}

//collapse_worlds toma como parámetros dos mundos, y copia el contenido del 
//segundo en el primero.
void collapse_worlds(char world1[ROWS][COLS], char world2[ROWS][COLS]){
        int i, j;
        for(i=1; i<ROWS-1; i++){                                                        //Se recorren las filas.
                for(j=1; j<COLS-1; j++){                                                //Se recorren las columnas.
                        world1[i][j] = world2[i][j];					//Para cada célula pasa el contenido de world2 a world1.	
                }
        }
        return;
}

//update_cell recibe la dirección de la matriz actual, las coordenadas de una 
//célula, revisa el estado de sus células contiguas, y actualiza la matriz de 
//la próxima generación.
void update_cell (char world1 [ROWS] [COLS], int i, int j, char world2[ROWS][COLS]) {
	int x, y, count=0;

	for (x=i-1; x<=i+1; x++) {							//Recorre horizontalmente las células adyacentes.
		for (y=j-1; y<=j+1; y++)						//Recorre verticalmente las células adyacentes.
			count+=get_cell_state(world1 [x][y]);				//Incrementa el contador si la célula está viva.
	}
        
	count-=get_cell_state(world1[i][j]);						//Resta 1 si la propia célula estaba viva, ya que no hay que contarla.

	switch(count) {									//count es la cantidad de células adyacentes vivas.
		case 2: break;								//Si son dos, no hace falta cambiar el estado actual.		
		case 3: 											
			set_cell_state(world2,i,j,ALIVE);				//Si son tres, la célula estará viva en la próxima generación.
			break;	
		default:
			set_cell_state (world2,i,j,DEAD);				//En cualquier otro caso la célula estará muerta en la próxima generación.
			break;
	}
	return;
}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

//set_cell_state toma como parámetros un mundo, una célula y un estado, y setea 
//esa célula en el estado elegido.
static void set_cell_state(char world[ROWS][COLS], int i, int j, int state){
        switch(state){
                case ALIVE: world[i][j] = ALIVE;    
                            break;
                case DEAD:  world[i][j] = DEAD;     
                            break;
                default:    printf("Error in set_cell_state\n"); 
                            break;
        }
        return;
}

//get_cell_state recibe como parámetro el estado de una célula individual, y 
//devuelve un 1 si está viva, o un 0 si está muerta.
static int get_cell_state(char cell){
        if(cell == ALIVE){
                return 1;
        }
        else {
                return 0;
        }
}
