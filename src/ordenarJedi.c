#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenarJedi.h"
#include "data_read.h"
#include "structJedi.h"


/**Función********************************************************************

  Resumen      [Ordena los jedis por puntos de vida]

  Descripción  [Ordena los jedis almacenados según sus puntos de vida y los 
				muestra de mayor a menor vida]

  Parámetros   [Lista]  

  Efec. Colat. [Si la lista esta vacia, avisa con un mensaje de error]

  Ver también  [opcional]

******************************************************************************/
//10. ORDENAR JEDIS

struct Lista *ordenarJedi(struct Lista *lista){
	struct Lista *actual;
	struct Lista *next;
	
	actual = lista;
	
	if(actual == NULL){
		printf("\nLista vacia!! No se puede ordenar.\n");
	} else {
		while(actual->sig != NULL){
			next = actual->sig;
			
			while(next != NULL){
				if(actual->jedi.ptr_points->hit_points > next->jedi.ptr_points->hit_points){
				
                    // Copiamos en aux todo lo de next
                    
				struct Lista *aux = (struct Lista*)calloc(1,sizeof(struct Lista));
				aux->jedi.ptr_points = (struct points*)calloc(1,sizeof(struct points));
                aux->jedi.id = next->jedi.id;
                aux->jedi.size_name = next->jedi.size_name;
                aux->jedi.s_full_name = next->jedi.s_full_name;
				aux->jedi.ptr_points->hit_points = next->jedi.ptr_points->hit_points;
				aux->jedi.ptr_points->attack_array[0] = next->jedi.ptr_points->attack_array[0];
				aux->jedi.ptr_points->defense_array[0] = next->jedi.ptr_points->defense_array[0];
				aux->jedi.ptr_points->speed_array[0] = next->jedi.ptr_points->speed_array[0];
				aux->jedi.ptr_points->attack_array[1] = next->jedi.ptr_points->attack_array[1];
				aux->jedi.ptr_points->defense_array[1] = next->jedi.ptr_points->defense_array[1];
				aux->jedi.ptr_points->speed_array[1] = next->jedi.ptr_points->speed_array[1];
                
                    // Copiamos en next actual
                
                
                next->jedi.id = actual->jedi.id;
                next->jedi.size_name = actual->jedi.size_name;
                
                next->jedi.s_full_name = actual->jedi.s_full_name;
				next->jedi.ptr_points->hit_points = actual->jedi.ptr_points->hit_points;
				next->jedi.ptr_points->attack_array[0] = actual->jedi.ptr_points->attack_array[0];
				next->jedi.ptr_points->defense_array[0] = actual->jedi.ptr_points->defense_array[0];
				next->jedi.ptr_points->speed_array[0] = actual->jedi.ptr_points->speed_array[0];
				next->jedi.ptr_points->attack_array[1] = actual->jedi.ptr_points->attack_array[1];
				next->jedi.ptr_points->defense_array[1] = actual->jedi.ptr_points->defense_array[1];
				next->jedi.ptr_points->speed_array[1] = actual->jedi.ptr_points->speed_array[1];
                
                    //Copiamos en actual aux
                
                
                actual->jedi.id = aux->jedi.id;
                actual->jedi.size_name = aux->jedi.size_name;
             
                actual->jedi.s_full_name = aux->jedi.s_full_name;
				actual->jedi.ptr_points->hit_points = aux->jedi.ptr_points->hit_points;
				actual->jedi.ptr_points->attack_array[0] = aux->jedi.ptr_points->attack_array[0];
				actual->jedi.ptr_points->defense_array[0] = aux->jedi.ptr_points->defense_array[0];
				actual->jedi.ptr_points->speed_array[0] = aux->jedi.ptr_points->speed_array[0];
				actual->jedi.ptr_points->attack_array[1] = aux->jedi.ptr_points->attack_array[1];
				actual->jedi.ptr_points->defense_array[1] = aux->jedi.ptr_points->defense_array[1];
				actual->jedi.ptr_points->speed_array[1] = aux->jedi.ptr_points->speed_array[1];
                
                free(aux->jedi.ptr_points);
                free(aux);
                
				}
				next = next->sig;
			}
			actual = actual->sig;
		}
	}

	return lista;
}





