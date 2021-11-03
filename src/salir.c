#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_read_L.h"
#include "structJedi.h"


/**Funci�n********************************************************************

  Resumen      [Finalilza el programa]

  Descripci�n  [Si se introduce el valor "1", finaliza el programa o permite continuar
  				el mismo]

  Par�metros   [C�racteres "s/n"]  

  Efec. Colat. [El programa pregunta si se desea salir o no, si se decide que
                si, se borran los datos almacenados temporalmente; sino, vuelve al
				menu principal]

  Ver tambi�n  [opcional]

******************************************************************************/
//1. FUNCION SALIR

char *salir(struct Lista *lista){
    char *ptr = NULL;
    struct Lista *actual = NULL;
do{
    free(ptr);
    puts("¿Esta seguro de que quiere salir el programa? [S/N] \n");
    ptr = data_read_L();
    if((strcmp(ptr,"S") != 0 ) && (strcmp(ptr,"s") != 0 ) && (strcmp(ptr,"N") != 0 ) && (strcmp(ptr,"n") != 0 )){
        puts("El valor introducido es stephen hawkings\n");
    }
}while ((strcmp(ptr,"S") != 0 ) && (strcmp(ptr,"s") != 0 ) && (strcmp(ptr,"N") != 0 ) && (strcmp(ptr,"n") != 0 ));

if(strcmp(ptr,"S")==0 || strcmp(ptr, "s") == 0){

	while(lista != NULL){
        
        actual = lista;
        lista = lista->sig;
        free(actual->jedi.s_full_name);
	free(actual->jedi.ptr_points);
        free(actual);
	}
	
}

return ptr;


    
}
