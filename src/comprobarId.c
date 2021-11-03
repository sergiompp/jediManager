#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "data_read.h"
#include "data_read_L.h"
#include "structJedi.h"
#include "data_read_double.h"


int comprobarId(struct Lista *lista, int *id){
int comprobado = 1;
int idp = 0;
struct Lista *jediImp = lista;
	  do{
	      
	    while(jediImp !=NULL){
		if(jediImp -> jedi.id == *id){ 
		    break;
		}
		jediImp = jediImp -> sig;

	    }
	    
	     if(jediImp != NULL){
		 puts("ID ya existente, dame uno nuevo");
		 idp = data_read();
		 comprobado = comprobarId(lista, &idp);
		 *id = idp;
	     }else{
		 comprobado = 1;
	     }
	   }while(comprobado == 0);
 return comprobado;
}