/*******************************************************************************
  @file     +grafico.c+
  @brief    +Realiza las tareas gráficas: impresión de las generaciones.+
  @author   +GRUPO 2+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include "constantes.h"

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
static void print_line();

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

//print_world toma como parámetro un mundo, y lo imprime en pantalla, 
//intercalando cada célula con un '|', y cada fila con una cadena de '-'.
void print_world(char world[ROWS][COLS]){
        int i, j;
        print_line();                               					//Se imprime una cadena de separación.
        for(i=1; i<ROWS-1; i++){                      					//Se recorre cada célula del mundo.
                printf("|");                            				//Se la separa con un '|'.
                for(j=1; j<COLS-1; j++){
                        printf(" %c |", world[i][j]);         				//Se imprime su estado.
                }
                printf("\n");                           				//Siguiente fila.
            print_line();                           
           }
        return;
}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

//print_line imprime una línea de caracteres '-' que ocupa el ancho exacto del mundo.
static void print_line(){
        int i;
        for(i=1; i<(((COLS-2)*4)+1); i++){
                printf("-");                            				//Se imprimen '-' hasta llegar al final del mundo.
        }
        printf("\n");
        return;
}
