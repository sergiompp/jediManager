#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "data_read.h"
#include "data_read_L.h"
#include "structJedi.h"
#include "data_read_double.h"
#include "borrarJedi.h"

/**Función********************************************************************

  Resumen      [Importa a archivo binario]

  Descripción  [Importa los jedis almacenados en un archivo binario creado 
  				anteriormente]

  Parámetros   [Lista]  

  Efec. Colat. [Si no importa correctamente el archivo binario, avisa con un 
  				mensaje de error]

  Ver también  [opcional]

******************************************************************************/
//8. FUNCION IMPORTAR

struct Lista *importarJedi(struct Lista *lista){
  //Borramos la lista que teniamos.
 
    while(lista != NULL){
	lista = borrarJedi(lista, lista->jedi.id);
    }
  
  
    int id = 0;
    
    //Importamos el fichero_abierto
    
    printf("Dame el nombre del fichero a importar: \n");
    
    char *ptr_fichero = data_read_L();
	FILE *fichero_abierto = fopen(ptr_fichero, "rb");
    char *nombre = NULL;
    
    struct Lista *aux = NULL;

    if(fichero_abierto == NULL){
        fflush(fichero_abierto);
    	printf("\nFichero mal importado\n");  
        
	}else{
        
	fread(&id,sizeof(int),1,fichero_abierto);
	 
            
        while(!feof(fichero_abierto)){

	    aux = (struct Lista*)calloc(1,sizeof(struct Lista));
	    aux->jedi.ptr_points = (struct points*)calloc(1,sizeof(struct points));
		
	    aux->jedi.id  = id;
               
            fread(&aux->jedi.size_name,sizeof(int),1,fichero_abierto);
            	
            
            nombre = (char*) calloc((aux->jedi.size_name +1),sizeof(char));
            fread(&nombre[0],sizeof(char),aux->jedi.size_name,fichero_abierto);
            aux->jedi.s_full_name = nombre;
            aux->jedi.s_full_name[aux->jedi.size_name] = '\0';
            
            fread(&aux->jedi.ptr_points->hit_points,sizeof(int),1,fichero_abierto);
              
            fread(&aux->jedi.ptr_points->attack_array[1],sizeof(int),1,fichero_abierto);
              
            fread(&aux->jedi.ptr_points->attack_array[0],sizeof(int),1,fichero_abierto);
             
            fread(&aux->jedi.ptr_points->defense_array[1],sizeof(int),1,fichero_abierto);
                
            fread(&aux->jedi.ptr_points->defense_array[0],sizeof(int),1,fichero_abierto);
              
            fread(&aux->jedi.ptr_points->speed_array[1],sizeof(double),1,fichero_abierto);
             

            fread(&aux->jedi.ptr_points->speed_array[0],sizeof(double),1,fichero_abierto);
           	

            fread(&id,sizeof(int),1,fichero_abierto);

            if(lista == NULL){
	
				lista = aux;
				lista -> sig = NULL;
	
			}else{
				aux -> sig = lista;
				lista = aux;
			}
        }
	printf("Archivo importado!. \n");
	fclose(fichero_abierto);  
    
    }

	free(ptr_fichero);   
   
	return lista;
	
}
