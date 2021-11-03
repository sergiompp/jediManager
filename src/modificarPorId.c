#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_read_double.h"
#include "data_read.h"
#include "data_read_L.h"
#include "structJedi.h"
#include "comprobarId.h"

/**Función********************************************************************

  Resumen      [Modifica la informacion del jedi]

  Descripción  [Modifica la informacion del Jedi identificado con el id pedido]

  Parámetros   [Lista, identificador]  

  Efec. Colat. []

  Ver también  [opcional]

******************************************************************************/
//5. FUNCION MODIFICAR JEDI

struct Lista *modificarPorId(struct Lista *lista, int id){

struct Lista*aux = lista;
char *ptr=NULL;
int id1 = 0;
int comprobado =0;
	if(aux == NULL){
		printf("\nNo hay Jedi para modificar, la lista esta vacia\n");
        
	} else {
        
		while((aux != NULL)){
            
			if(aux->jedi.id == id){
				
				break;					
			}
		aux = aux->sig;
        }

	    

       
	
            puts("= Informacion completa de Jedi a insertar: \n");

            puts("= id ");
	    
			id1 = data_read();
			if(id1 == aux->jedi.id){
			  aux->jedi.id = id1;
			  
			}else{
			comprobado = comprobarId(lista, &id1);
			if(comprobado != 1){
			puts("algo ha salido mal");
			}
			aux->jedi.id = id1;
			}

            puts("= nombre: ");
            free(aux->jedi.s_full_name);

			aux->jedi.s_full_name = data_read_L();
            
            puts("= vida");
			aux->jedi.ptr_points->hit_points = data_read();

            puts("= ataque de aprendiz: ");
			aux->jedi.ptr_points->attack_array[0] = data_read();

            puts("= defensa de aprendiz: ");
			aux->jedi.ptr_points->defense_array[0] = data_read();

            puts("= velocidad de aprendiz: ");
			aux->jedi.ptr_points->speed_array[0] = data_read_double();

            puts("= ataque de maestro: ");
			aux->jedi.ptr_points->attack_array[1] = data_read();

            puts("= defensa de maestro: ");
			aux->jedi.ptr_points->defense_array[1] = data_read();

            puts("= velocidad de maestro: ");
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

            
	}

free(ptr);
return lista;

}
