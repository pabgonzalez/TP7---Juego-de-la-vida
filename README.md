# TP7-G2-JUEGO-DE-LA-VIDA
Juego de la vida, modularizado y con buenas prácticas de multiarchivo.

  Para la reconstruccion del TP4 usando los concocimientos adquiridos sobre multiarchivo, se decidió distribuir el programa en
tres partes diferenciables.

  1) grafico.c: este archivo se ocupa de manejar el aspecto de la interfaz visual del Juego de la Vida, es decir, el mapa en si.
              
  2) logico.c: este archivo se encarga de analizar los datos del mapa y decidir que célula debe morir, revivir o permanecer igual en 
               cada evolución.
               
  3) main.c: este archivo integra el juego usando los modulos anteriormente descritos.
  
  Adicionalmente, se añadió un header llamado constantes.h en el cual se definen ciertas constantes utiles para todos los archivos.
