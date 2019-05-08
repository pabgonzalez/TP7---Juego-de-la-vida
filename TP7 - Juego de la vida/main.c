//TRABAJO PRÁCTICO 4 - JUEGO DE LA VIDA
//GRUPO 2: DE VINCENTI, FIGUEROA, GONZALEZ, MATTALONI VARONA.

#include <stdio.h>
#include <stdlib.h>

//Declaración de constantes.
#define DEAD  ' '
#define ALIVE 'X'
#define COLS  19
#define ROWS  19

//Prototipos de funciones.
void print_world(char world[ROWS][COLS]);
void print_line();
int get_cell_state(char);
void set_cell_state(char world[ROWS][COLS], int i, int j, int state);
void collapse_worlds(char world1[ROWS][COLS], char world2[ROWS][COLS]);
void update_cell (char world [ROWS] [COLS], int i, int j, char world2[ROWS][COLS]);
void clean (char world [ROWS] [COLS], int i, int j);

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

//Esta función recibe la dirección de una matriz, su cantidad de filas y columnas y limpia su marco.
void clean (char world [ROWS] [COLS], int i, int j) {
	int a;	 
	for (a=0; a<j; a++) {
		set_cell_state(world,0,a,DEAD);								//Limpia primera fila.
		set_cell_state(world,i-1,a,DEAD);							//Limpia la última fila.
	}
	for (a=1 ; a<=i-2 ; a++) {
		set_cell_state(world,a,0,DEAD);								//Limpia la primer columna, excepto las celdas que ya se habían limpiado.
		set_cell_state(world,a,j-1,DEAD);							//Limpia la última columna, excepto las celdas que ya se habían limpiado.	
	}
}

//Esta función toma como parámetros un mundo, una célula y un estado, y setea esa célula en el estado elegido.
void set_cell_state(char world[ROWS][COLS], int i, int j, int state){
    switch(state){
        case ALIVE: world[i][j] = ALIVE;    break;
        case DEAD:  world[i][j] = DEAD;     break;
        default: printf("Error in set_cell_state\n"); break;
    }
    return;
}


//Esta función toma como parámetros dos mundos, y copia el contenido del segundo en el primero.
void collapse_worlds(char world1[ROWS][COLS], char world2[ROWS][COLS]){
    int i, j;
    for(i=1; i<ROWS-1; i++){                                  		//Se recorren las filas.

        for(j=1; j<COLS-1; j++){                            	  	//Se recorren las columnas.
            world1[i][j] = world2[i][j];							//Para cada célula pasa el contenido de world2 a world1.	
        }
    }
    return;
}

//Esta función toma como parámetro un mundo, y lo imprime en pantalla, 
//intercalando cada célula con un '|', y cada fila con una cadena de '-'.
void print_world(char world[ROWS][COLS]){
    int i, j;
    print_line();                               					//Se imprime una cadena de separación.
    for(i=1; i<ROWS-1; i++){                      					//Se recorre cada célula del mundo.
        printf("|");                            					//Se la separa con un '|'.
        for(j=1; j<COLS-1; j++){
            printf(" %c |", world[i][j]);         					//Se imprime su estado.
        }
        printf("\n");                           					//Siguiente fila.
        print_line();                           
    }
    return;
}

//Esta función imprime una línea de caracteres '-' que ocupa el ancho exacto del mundo.
void print_line(){
    int i;
    for(i=1; i<(((COLS-2)*4)+1); i++){
        printf("-");                            					//Se imprimen '-' hasta llegar al final del mundo.
    }
    printf("\n");
    return;
}

//Esta función recibe la dirección de la matriz actual, las coordenadas de una célula, revisa el estado de 
//sus células contiguas, y actualiza la matriz de la próxima generación.
void update_cell (char world1 [ROWS] [COLS], int i, int j, char world2[ROWS][COLS]) {
	int x, y, count=0;

	for (x=i-1; x<=i+1; x++) {										//Recorre horizontalmente las células adyacentes.
		for (y=j-1; y<=j+1; y++)									//Recorre verticalmente las células adyacentes.
			count+=get_cell_state(world1 [x][y]);					//Incrementa el contador si la célula está viva.
	}
	count-=get_cell_state(world1[i][j]);							//Resta 1 si la propia célula estaba viva, ya que no hay que contarla.

	switch(count) {													//count es la cantidad de células adyacentes vivas.
		case 2: break;												//Si son dos, no hace falta cambiar el estado actual.		
		case 3: 											
			set_cell_state(world2,i,j,ALIVE);						//Si son tres, la célula estará viva en la próxima generación.
			break;	
		default:
			set_cell_state (world2,i,j,DEAD);						//En cualquier otro caso la célula estará muerta en la próxima generación.
			break;
	}
	return;
}

//Esta función recibe como parámetro el estado de una célula individual,
//y devuelve un 1 si está viva, o un 0 si está muerta.
int get_cell_state(char cell){
    if(cell == ALIVE){
        return 1;
    }
    else{
        return 0;
    }
}



