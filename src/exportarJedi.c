#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "data_read.h"
#include "data_read_L.h"
#include "structJedi.h"
#include "data_read_double.h"
#include <assert.h>

/**Función********************************************************************

  Resumen      [Exporta a un fichero binario]

  Descripción  [Exporta los jedis almacenados en memoria a un archivo binario
		que crea con el nombre que pide al usuario]

  Parámetros   [Lista, fichero a exportar]  

  Efec. Colat. [Si no se crea el fichero, avisa con un mensaje de error]

  Ver también  [opcional]

******************************************************************************/
//7. FUNCION EXPORTAR

void exportarJedi(struct Lista *lista, char * fichero){
	

	FILE *ptr_fichero = fopen(fichero,"wb");
	fflush(ptr_fichero);

	if(ptr_fichero == NULL){
		printf("Error de fichero");
	} else {
		struct Lista *actual = lista;

        while(actual!=NULL){
            assert(fwrite(&actual -> jedi.id, sizeof(int), 1, ptr_fichero) == 1);
			//Escribir primero la longitud del nombre, y luego el nombre
			assert(fwrite(&actual ->jedi.size_name, sizeof(int), 1, ptr_fichero) == 1);
			assert(fwrite(&actual -> jedi.s_full_name[0], sizeof(char),  actual-> jedi.size_name, ptr_fichero) ==  actual-> jedi.size_name);
			assert(fwrite(&actual -> jedi.ptr_points->hit_points, sizeof(int), 1, ptr_fichero) == 1);
			assert(fwrite(&actual -> jedi.ptr_points->attack_array[T_MASTER], sizeof(int), 1, ptr_fichero) == 1);
			assert(fwrite(&actual -> jedi.ptr_points->attack_array[T_APPRENTICE], sizeof(int), 1, ptr_fichero) == 1);
			assert(fwrite(&actual -> jedi.ptr_points->defense_array[T_MASTER], sizeof(int), 1, ptr_fichero) == 1);
			assert(fwrite(&actual -> jedi.ptr_points->defense_array[T_APPRENTICE], sizeof(int), 1, ptr_fichero) == 1);
			assert(fwrite(&actual -> jedi.ptr_points->speed_array[T_MASTER], sizeof(double), 1, ptr_fichero) == 1);
			assert(fwrite(&actual -> jedi.ptr_points->speed_array[T_APPRENTICE], sizeof(double), 1, ptr_fichero) == 1);
        
            actual = actual->sig;
        }
		fflush(ptr_fichero);
		fclose(ptr_fichero);
		
	}
}
