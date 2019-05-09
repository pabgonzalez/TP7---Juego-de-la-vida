/* 
 * File:   logico.h
 * Author: Pablo
 *
 * Created on 8 de mayo de 2019, 11:44
 */

#ifndef LOGICO_H
#define	LOGICO_H

#include "constantes.h"
void collapse_worlds(char world1[ROWS][COLS], char world2[ROWS][COLS]);
void update_cell (char world [ROWS] [COLS], int i, int j, char world2[ROWS][COLS]);
void clean (char world [ROWS] [COLS], int i, int j);

#endif	/* LOGICO_H */

