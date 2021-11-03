#include <stdio.h>
#include <stdlib.h>
#include "structJedi.h"
#include "data_read.h"

/**Función********************************************************************

  Resumen      [Borra el jedi de la lista]

  Descripción  [Borra el jedi con el id introducido]

  Parámetros   [Lista de Jedis, identificador]  

  Efec. Colat. [opcional]

  Ver también  [opcional]

******************************************************************************/
//6. FUNCION BORRAR

struct Lista *borrarJedi(struct Lista *lista, int id){

struct Lista *aux = NULL;
struct Lista *actual = lista;

if(lista == NULL){

printf("\nLa lista esta vacÃ­a\n");

}else{
    
    if(lista->jedi.id == id){
        
        lista = lista -> sig;
        free(actual -> jedi.s_full_name);
		free(actual -> jedi.ptr_points);
        free(actual);
		
	
    }else{
        
        while(actual->sig != NULL){
                
            if(actual->sig->jedi.id == id){
                
            aux  = actual;
            actual = actual->sig;
            aux -> sig = actual ->sig;
            free(actual -> jedi.s_full_name);
			free(actual -> jedi.ptr_points);
            free(actual);
			
            break;
            
            }
                
        actual = actual ->sig;
        
        }
        
       
    
        
    }   

}



return lista;
}
