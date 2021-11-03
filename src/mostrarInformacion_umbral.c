#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structJedi.h"
#include "data_read.h"

void mostrarInformacion_umbral(struct Lista * lista, int umbral){
    
    struct Lista *aux = lista;
    char *aux_char = NULL;
    
	if(lista == NULL){
        
		printf("\nLista Vacia\n");
        
	}else {
		while(aux != NULL){
        if(aux->jedi.ptr_points->hit_points <= umbral){
            
            puts("Lo sentimos. No hay ningun Jedi con mas de 300 puntos de vida! ");
            aux = aux->sig;
            
        }else{ 
            
            aux_char = (char*)malloc((aux->jedi.size_name + 1) * sizeof(char));
                
            strcpy(aux_char, aux -> jedi.s_full_name );
            aux_char = realloc(aux_char,10);
            printf("\n================================================\n");
            printf("|\tID |\tNomb. |\tVida |\tAta.|\tDef. |");
            printf("\n================================================\n");
            printf("|\t%i |\t%s |\t%d |\t%d |\t%d |", aux->jedi.id, aux_char,aux->jedi.ptr_points->hit_points ,aux-> jedi.ptr_points->attack_array[aux-> jedi.ptr_points->level_jedi],
			aux-> jedi.ptr_points->defense_array[aux-> jedi.ptr_points->level_jedi]);
            printf("\n================================================\n");
                
            aux = aux->sig;
            free(aux_char);
            
            }
            
        }
    }
}
