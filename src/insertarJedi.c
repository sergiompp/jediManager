#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "data_read.h"
#include "data_read_L.h"
#include "structJedi.h"
#include "data_read_double.h"
#include "comprobarId.h"

/**Función********************************************************************

  Resumen      [Introduce un Jedi]

  Descripción  [Introduce un nuevo jedi a la lista]

  Parámetros   [Lista donde introducir el jedi]  

  Efec. Colat. [Si los datos introducidos en alguna de sus caracteristicas 
                no es valido, lanza un mensaje de error y pide que se repita]

  Ver también  [opcional]

******************************************************************************/
//2. FUNCION INSERTAR

struct Lista *insertarJedi(struct Lista *lista){
	char *ptr = NULL;
	int id = 0;
	int comprobado=0;
	
	struct Lista *aux = (struct Lista*)malloc(sizeof(struct Lista));
	aux->jedi.ptr_points = (struct points*)malloc(sizeof(struct points));

	puts("Insertando Jedi\n");

	puts("\t Dame el id de Jedi: ");
	id = data_read();
	comprobado = comprobarId(lista, &id);
	if(comprobado != 1){
	puts("algo ha salido mal");
	}
	aux->jedi.id = id;

	puts("\t Dame el nombre del Jedi: ");
	aux->jedi.s_full_name = data_read_L();
	aux->jedi.size_name= strlen(aux->jedi.s_full_name);
	
	puts("\t Dame la vida: "); 
	aux->jedi.ptr_points->hit_points= data_read();
	
	puts("\n");
	
	puts("\t Dame el ataque de aprendiz: ");
	aux->jedi.ptr_points->attack_array[0]= data_read();
	 
	puts("\t Dame la defensa de aprendiz: ");
	aux->jedi.ptr_points->defense_array[0]= data_read();
	
	puts("\t Dame la velocidad de aprendiz: "); 
	aux->jedi.ptr_points->speed_array[0] = data_read_double();
	puts("\n");
	
	puts("\t Dame el ataque de maestro: "); 
	aux->jedi.ptr_points->attack_array[1]= data_read();
	
	puts("\t Dame la defensa de maestro: ");
	aux->jedi.ptr_points->defense_array[1]= data_read();
	
	puts("\t Dame la velocidad de maestro: ");
	aux->jedi.ptr_points->speed_array[1] = data_read_double();
	

	do{
        free(ptr);
    	puts("Â¿Es un maestro? [S/N]");
    	ptr  = data_read_L();
	}while ((strcmp(ptr,"S") != 0 ) && (strcmp(ptr,"s") != 0 ) && (strcmp(ptr,"N") != 0 ) && (strcmp(ptr,"n") != 0 ));
	
	if(strcmp("s", ptr) == 0 || strcmp("S",ptr) == 0){
		aux->jedi.ptr_points->level_jedi = 1;
	}else{
		aux->jedi.ptr_points->level_jedi = 0;
	}
		
	if(lista == NULL){
	
		lista = aux;
		lista -> sig = NULL;
	
	}else{
	
		aux -> sig = lista;
		lista = aux;
		
	}
	free(ptr);
	return lista;
}
