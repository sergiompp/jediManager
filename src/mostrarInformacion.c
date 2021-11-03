#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structJedi.h"
#include "data_read.h"

/**Función********************************************************************

  Resumen      [Muestra toda la informacion del Jedi]

  Descripción  [Muestra la informacion completa del Jedi solicitado con el 
  				identificador]

  Parámetros   [Lista, identificador]  

  Efec. Colat. [Al introducir el id del jedi a mostrar, si no lo encuentra en la
  				lista, aparece un mensaje de error]

  Ver también  [opcional]

******************************************************************************/
//4. FUNCION MOSTRAR INFORMACION  

void mostrarInformacion(struct Lista *jedi, int id){
	char* maestro= NULL;
    struct Lista*aux = jedi;
	if(aux == NULL){
		printf("\nNo hay Jedi para mostrar, la lista esta vacia\n");
        
	} else {
        
		while(aux != NULL){
			if(aux->jedi.id == id){
				break;
			}
		aux = aux->sig;
        }
        if(aux == NULL){
            puts("El id insertado no corresponde a ningun Jedi. \n");
        }else{
            puts("= Informacion completa de Jedi \n");

			fputs("= id: ", stdout);
			printf("%i\n", aux->jedi.id);

			fputs("= vida: ", stdout);			
			printf("%i\n", aux->jedi.ptr_points->hit_points);
            
			if(aux-> jedi.ptr_points->level_jedi == 1){
				maestro= "Maestro";
			} else {
				maestro= "Aprendiz";
			}
            fputs("= nombre: ", stdout);
			printf("%s, %s\n", aux->jedi.s_full_name,  maestro);

            fputs("= ataque de aprendiz: ", stdout);
			printf("%i\n", aux->jedi.ptr_points->attack_array[0]);

            fputs("= defensa de aprendiz: ", stdout);
			printf("%i\n", aux->jedi.ptr_points->defense_array[0]);

            fputs("= velocidad de aprendiz: ", stdout);
			printf("%f\n", aux->jedi.ptr_points->speed_array[0]);

            fputs("= ataque de maestro: ", stdout);
			printf("%i\n", aux->jedi.ptr_points->attack_array[1]);

            fputs("= defensa de maestro: ", stdout);
			printf("%i\n", aux->jedi.ptr_points->defense_array[1]);

            fputs("= velocidad de maestro: ", stdout);
			printf("%f\n", aux->jedi.ptr_points->speed_array[1]);

        }
		

	}
}
