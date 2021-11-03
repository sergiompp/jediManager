#include <stdio.h>
#include<stdlib.h>
#include<string.h> 




void mostrarMenu(int contador){
    printf("=========================================\n");
    printf("[*][2018][SAUCEM APPS][JediManager]======\n");
    printf("=========================================\n");    
    printf("[1] Salir\n");    
    printf("[2] Insertar Jedi\n");
    printf("[3] Mostrar Jedis\n");
    printf("[4] Mostrar Jedi por ID\n");
    printf("[5] Modificar un Jedi por ID\n");
    printf("[6] Borrar Jedi por ID\n");
    printf("[7] Exportar Jedis a fichero binario\n");
    printf("[8] Importar Jedis de fichero binario\n");
    printf("[9] Simulador de combate Jedi\n");
    printf("[10] Ordenar Jedis por puntos de vida\n"); 
    printf("[11] Autosalvado Jedi (5 segundos, si ha habido cambios)\n");
    	printf("\t\t\t#INFO:   %d veces mostrado el menu principal\n", contador);
        
			

    printf("Dame una opcion: \n");
}