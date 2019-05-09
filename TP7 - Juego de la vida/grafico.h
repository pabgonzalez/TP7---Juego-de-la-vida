/*******************************************************************************
  @file     +grafico.h+
  @brief    +Realiza las tareas gráficas: impresión de las generaciones.+
  @author   +GRUPO 2+
 ******************************************************************************/

#ifndef GRAFICO_H
#define	GRAFICO_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "constantes.h"

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
/**
 * @brief print_world: imprime una matriz (mundo) por pantalla.
 * @param param1 dirección de la matriz.
 * @return nada.
*/
void print_world(char world[ROWS][COLS]);

#endif	/* GRAFICO_H */

