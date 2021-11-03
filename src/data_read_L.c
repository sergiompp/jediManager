#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**Función********************************************************************

  Resumen      [Leer cadenas de caracteres]

  Descripción  [opcional]

  Parámetros   [opcional]  

  Efec. Colat. [obligatorio]

  Ver también  [opcional]

******************************************************************************/
// FUNCION char_data_read()

char *data_read_L(){
  char *c = NULL;
  size_t numero_bytes;
  ssize_t bytes_leidos;
  int i;

  numero_bytes = 0 ;
  
  
  bytes_leidos = getline(&c, &numero_bytes, stdin);

  if(bytes_leidos == -1){
      puts("error");
	  free(c);
  }

 for(i = 0; i < strlen(c); i++){
	if(c[i] == '\n'){
		c[i] = '\0';	
	}
 }
  
return c;
  
  
}
