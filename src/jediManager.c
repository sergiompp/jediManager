/**CFile***********************************************************************

  Fichero     [obligatorio]

  Resumen     [obligatorio]

  Descripción [opcional]

  Ver también [opcional]

  Autor       [opcional]

  Copyright   [Copyright (c) 2011 Universidad Carlos III de Madrid

  Se concede, sin necesidad de acuerdo por escrito y sin ningún tipo de derechos
  de autor, permiso para utilizar, copiar, modificar y distribuir este programa
  y su documentación para cualquier propósito siempre y cuando esta advertencia
  y los siguientes dos párrafos aparezcan en las copias.

  EN NINGÚN CASO SE RECONOCERÁ A LA UNIVERSIDAD CARLOS III DE MADRID RESPONSABLE
  DIRECTA, INDIRECTA, ESPECIAL, O SUBSIDIARIA DE LOS POSIBLES DAÑOS Y PERJUICIOS
  QUE PUEDAN DERIVARSE DEL USO DE ESTE PROGRAMA Y DE SU DOCUMENTACIÓN, INCLUSO
  EN EL CASO DE QUE LA UNIVERSIDAD CARLOS III DE MADRID HAYA SIDO ADVERTIDA DE
  TALES DAÑOS Y PERJUICIOS.

  LA UNIVERSIDAD CARLOS III DE MADRID ESPECÍFICAMENTE SE DESENTIENDE DE TODO
  TIPO DE GARANTÍAS INCLUYENDO, PERO NO LIMITANDOLAS A, LAS GARANTIAS IMPLÍCITAS
  DE LA COMERCIALIZACIÓN Y ADECUACIÓN PARA CUALQUIER PROPÓSITO EN PARTICULAR. EL
  PROGRAMA SE PROVEE TAL CUAL Y LA UNIVERSIDAD CARLOS III DE MADRID NO TIENE
  OBLIGACIÓN ALGUNA DE OFRECER MANTENIMIENTO, SOPORTE, ACTUALIZACIONES, MEJORAS
  O MODIFICACIONES.]

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "mostrarMenu.h"
#include "data_read.h"
#include "data_read_L.h"
#include "structJedi.h"
#include "salir.h"
#include "insertarJedi.h"
#include "mostrarResumen.h"
#include "mostrarInformacion.h"
#include "borrarJedi.h"
#include "modificarPorId.h"
#include "exportarJedi.h"
#include "importarJedi.h"
#include "ordenarJedi.h"
#include "combateJedi.h"


/*---------------------------------------------------------------------------*/
/* Declaración de structs                                                   */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Declaración de constantes                                                */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* Declaración de tipos                                                      */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* Declaración de variables                                                  */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* Declaración de macros                                                     */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* Prototipos de las funciones estáticas                                     */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* Definición de las funciones                                               */
/*---------------------------------------------------------------------------*/

void autosalvadoJedi(void* data);
/*---------------------------------------------------------------------------*/
/* Definición de las funciones estáticas                                     */
/*---------------------------------------------------------------------------*/
#define SIZEMENU 11
int seguir = 2;
pthread_mutex_t mutex;
pthread_t thread;

int main(int arg_count, char *arg_strings[]) {
    

    struct Lista *lista_jedi = NULL; 
    int c = 0;
    int id_aux = 0;
    int contador = 0;
    int opcion = 0;
    char *yesNo = NULL;
    int comparar = 0;

    int aux = 0;
    
    pthread_mutex_init(&mutex,NULL);
    
    
    
	while(1){
		contador++;
		mostrarMenu(contador);
		opcion = data_read();
		
		;
		switch(opcion){
			case 1:
				yesNo = salir(lista_jedi);
                if(strcmp(yesNo,"S")==0 || strcmp(yesNo, "s") == 0){
                    comparar = 1;
                }
                free(yesNo);
				break;
			case 2:
				lista_jedi = insertarJedi(lista_jedi);
				break;
			case 3:
				mostrarResumen(lista_jedi);
				
				break;
			case 4:
                puts("\nDame el id del Jedi a mostrar: ");
                id_aux = data_read();
				mostrarInformacion(lista_jedi, id_aux);
				break;
			case 5:
                puts("\nDame el id del Jedi a modificar: ");
                id_aux = data_read();
                lista_jedi = modificarPorId(lista_jedi, id_aux);
				break;
			case 6:

				puts("\nDame el id del Jedi a borrar: ");
                id_aux = data_read();
				
				lista_jedi = borrarJedi(lista_jedi, id_aux);
				puts("Jedi Borrado");
				break;
			case 7:
			  
				puts("\nExportando Jedis");
				printf("Dame el nombre del fichero: ");
				char *fichero = data_read_L();
				exportarJedi(lista_jedi, fichero);
				 free(fichero);
				puts("\n Archivo Exportado");
				break;
			case 8:
				puts("\nImportando Jedis");
				lista_jedi = importarJedi(lista_jedi);
				break;
			case 9:
				puts("\nCombate Jedi.\n");
				puts("\nDame el primer ID");
				int id1 = data_read();
                struct Lista *auxilio = lista_jedi;
                while(auxilio !=NULL){
                    if(auxilio->jedi.id == id1){
                        aux = 0;
                        break;
                    } else {
                        aux = 1;
                        auxilio = auxilio->sig;
                    }
                }
                
                if(aux !=0){
                    printf("\n�0�3ID no encontrado!\n\n");
                } else {
                    puts("\nDame el segundo ID");
                    int id2 = data_read();
                    auxilio = lista_jedi;
                    while(auxilio !=NULL){
                        if(auxilio->jedi.id == id2){
                            aux = 0;
                            break;
                        } else {
                            aux = 1;
                            auxilio = auxilio->sig;
                        }
                    }
                    if(aux != 0){
                        printf("\n�0�3ID no encontrado!\n\n");
                    } else {
                        lista_jedi = combateJedi(lista_jedi, id1, id2);
                    }
                } 
				break;
				
			case 10:
				puts("Ordenando por puntos de vida");
				lista_jedi = ordenarJedi(lista_jedi);
				break;
				
			case 11:	
				puts("introduce 1 para activar autosalvado y cualquier otro valor para desactivarlo");
				seguir = data_read();
				
				pthread_create(&thread,NULL,(void*)autosalvadoJedi, (void*)lista_jedi);
				
				if(seguir==1){
				 c =1;
				printf("\nAutosalvado activado\n");
				}else{
				pthread_detach(thread);
				printf("\nAutosalvando desactivado\n");
				}
				break;
						
			
			default:
				printf("\nCar�cter no v�lido. Introducir un n�mero del 1 al 6 o el 12. Del 7 al 11 en proceso de construccion. �Gracias por la paciencia! \n");
			
		}
		
		
		if(comparar == 1){
            //Fin de Programa Visual por Pantalla
			puts("Finalizando programa");
			pthread_mutex_destroy(&mutex); 
			
			
         	sleep(1);
			puts("...");
			sleep(1);
			puts("...");
			sleep(1);
			puts("...");
			puts("\nPrograma Finalizado\n\n");
			
			break;
        }
	}
	
	return 0;
}


void autosalvadoJedi(void* data){		
	struct Lista *lista = (struct Lista*)data;
	
	
	do{
		if (seguir == 1 ) {
			exportarJedi(lista,"salvado");
			pthread_mutex_unlock(&mutex);
			sleep(5);
			pthread_mutex_lock(&mutex);
		}
		
		
	}while(seguir == 1);
	

}
	






