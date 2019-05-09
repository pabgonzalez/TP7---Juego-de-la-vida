/*******************************************************************************
  @file     +logico.h+
  @brief    +Realiza las tareas lógicas del juego+
  @author   +GRUPO 2+
 ******************************************************************************/

#ifndef LOGICO_H
#define	LOGICO_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "constantes.h"

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
/**
 * @brief clean: limpia el marco de la matriz.
 * @param param1 dirección de un mundo (una matriz).
 * @param param2 cantidad de filas de la matriz.
 * @param param3 cantidad de columnas de la matriz.
 * @return nada.
*/
void clean (char world [ROWS] [COLS], int i, int j);

/**
 * @brief collapse_worlds: copia el contenido del mundo2 en el mundo1.
 * @param param1 puntero a una matriz llamada mundo1.
 * @param param2 puntero a una matriz llamada mundo2.
 * @return nada.
*/
void collapse_worlds(char world1[ROWS][COLS], char world2[ROWS][COLS]);

/**
 * @brief update_cell: actualiza el estado de una célula para la generación siguiente. 
 * @param param1 puntero a una matriz llamada mundo1 (la matriz actual).
 * @param param2 coordenada x de una célula.
 * @param param3 coordenada y de una célula.
 * @param param4 puntero a una matriz llamada mundo2 (la matriz de la próxima generación).
 * @return nada.
*/
void update_cell (char world [ROWS] [COLS], int i, int j, char world2[ROWS][COLS]);

#endif	/* LOGICO_H */

