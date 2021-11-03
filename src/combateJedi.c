#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "data_read.h"
#include "data_read_L.h"
#include "structJedi.h"
#include "data_read_double.h"
#include <unistd.h>

/**Funci�n********************************************************************

  Resumen      [Realiza el combate entre dos jedi]

  Descripci�n  [Introduce la lista de jedis y selecciona 2 para el combate entre
  				ellos segun una formula. Si alguno de los jedis llega a vida 0 o 
				inferior, no puede seguir el combate]

  Par�metros   [Lista de jedis, identificador 1, identificador 2]  

  Efec. Colat. [Cuando un jedi alcanza vida 0 o inferior, deja la misma en la 
  				lista]

  Ver tambi�n  [opcional]

******************************************************************************/
//9. FUNCION COMBATE

struct Lista *combateJedi(struct Lista *lista, int id1, int id2){
int vivo1 = 1;
int vivo2 = 1;

	if(lista == NULL){
		printf("\n¡Lista vacía! Empezamos mal\n");
	} else {
		struct Lista *jedi1 = NULL;
		jedi1 = lista;
		
        printf("\n\n");
		//Para Jedi 1 con id1

        while(jedi1 -> jedi.id != id1){
            jedi1 = jedi1 -> sig;
        }
			
        if (jedi1 -> jedi.ptr_points->hit_points > 0){
            printf("%s está preparado para la batalla\n\n", jedi1 -> jedi.s_full_name);
            vivo1 = 1;
        } else {
            vivo1 = 0;
            printf("¡%s está fiambre! No puede combatir\n\n", jedi1 -> jedi.s_full_name);
        }
		
		//Para Jedi 2 con id2
		struct Lista *jedi2 = NULL;
		jedi2 = lista;
        
        while(jedi2 -> jedi.id != id2){
            jedi2 = jedi2 -> sig;
        }
        
		if(jedi2 -> jedi.ptr_points->hit_points > 0){
		    printf("%s está preparado para la batalla\n\n", jedi2 -> jedi.s_full_name);
		    vivo2 = 1;
		} else {
		    vivo2 = 0;
		    printf("¡%s está fiambre! No puede combatir\n\n", jedi2 -> jedi.s_full_name);
		
		}
		
		
         if((vivo1 == 1) && (vivo2 == 1)){   
            //Niveles de Jedis
            int levelJedi1 = 0;
            int levelJedi2 = 0;
            
            if(jedi1->jedi.ptr_points->level_jedi == T_MASTER){
                levelJedi1 = T_MASTER;
            }else{
                levelJedi1 = T_APPRENTICE;
            }
            
            if(jedi2->jedi.ptr_points->level_jedi == T_MASTER){
                levelJedi2 = T_MASTER;
            }else{
                levelJedi2 = T_APPRENTICE;
            }
            
            //COMBATE
            int damage1 = 0; 
            int damage2 = 0;
            
            printf("\n\n¡¡QUE COMIENCE LA LUCHA!!\n\n");
            
            while((jedi1 -> jedi.ptr_points -> hit_points > 0) && (jedi2 -> jedi.ptr_points -> hit_points > 0)){
                if((jedi1->jedi.ptr_points->speed_array[levelJedi1]) > jedi2->jedi.ptr_points->speed_array[levelJedi2]){
                //****Daño Producido
                    damage1 = ((jedi1->jedi.ptr_points->speed_array[levelJedi1])/(jedi2->jedi.ptr_points -> speed_array[levelJedi2]))*(((86+rand()%15)*jedi1->jedi.ptr_points->attack_array[levelJedi1])/(jedi2->jedi.ptr_points->defense_array[levelJedi2])/10);
                    printf("%s ataca con un daño de: %d\n", jedi1 -> jedi.s_full_name, damage1);
                    printf("\n");
                    //Actualiza vida
                    jedi2 -> jedi.ptr_points -> hit_points = (jedi2 -> jedi.ptr_points -> hit_points)-damage1;
		if((jedi2 -> jedi.ptr_points -> hit_points < 0)){
		    jedi2-> jedi.ptr_points->hit_points = 0;
		}
                    
                    if(jedi2 -> jedi.ptr_points -> hit_points > 0){
                        damage2 = (jedi2 -> jedi.ptr_points -> speed_array[levelJedi2]/jedi1 -> jedi.ptr_points -> speed_array[levelJedi1])*(((86+rand()%15)*jedi2 -> jedi.ptr_points -> attack_array[levelJedi2])/(jedi1 -> jedi.ptr_points -> defense_array[levelJedi1])/10);
                        printf("%s ataca con un daño de: %d\n", jedi2 -> jedi.s_full_name, damage2);
                        printf("\n");
                        //Actualiza vida
                        jedi1 -> jedi.ptr_points -> hit_points = (jedi1 -> jedi.ptr_points -> hit_points)-damage2;
			 if((jedi1 -> jedi.ptr_points -> hit_points < 0)){
			    jedi1-> jedi.ptr_points->hit_points = 0;
			}
                    }
                }else if((jedi1->jedi.ptr_points->speed_array[levelJedi1]) < (jedi2->jedi.ptr_points->speed_array[levelJedi2])){
                    damage2 = (jedi2 -> jedi.ptr_points -> speed_array[levelJedi2]/jedi1 -> jedi.ptr_points -> speed_array[levelJedi1])*(((86+rand()%15)*jedi2 -> jedi.ptr_points -> attack_array[levelJedi2])/(jedi1 -> jedi.ptr_points -> defense_array[levelJedi1])/10);
                        printf("%s ataca con un daño de: %d\n", jedi2 -> jedi.s_full_name, damage2);
                        printf("\n");
                        //Actualiza vida
                        jedi1 -> jedi.ptr_points -> hit_points = (jedi1 -> jedi.ptr_points -> hit_points)-damage2;
			
			if((jedi1 -> jedi.ptr_points -> hit_points < 0)){
			    jedi1-> jedi.ptr_points->hit_points = 0;
			}
		    
                    if(jedi1 -> jedi.ptr_points -> hit_points > 0){
                    
                        damage1 = ((jedi1->jedi.ptr_points->speed_array[levelJedi1])/(jedi2->jedi.ptr_points -> speed_array[levelJedi2]))*(((86+rand()%15)*jedi1->jedi.ptr_points->attack_array[levelJedi1])/(jedi2->jedi.ptr_points->defense_array[levelJedi2])/10);
                        printf("%s ataca con un daño de: %d\n", jedi1 -> jedi.s_full_name, damage1);
                        printf("\n");
                        //Actualiza vida
                        jedi2 -> jedi.ptr_points -> hit_points = (jedi2 -> jedi.ptr_points -> hit_points)-damage1;
			 
			if((jedi2 -> jedi.ptr_points -> hit_points < 0)){
			    jedi2-> jedi.ptr_points->hit_points = 0;
			}
                    }
                }else {
                    if(rand()%11 > 5){
                    damage2 = (jedi2 -> jedi.ptr_points -> speed_array[levelJedi2]/jedi1 -> jedi.ptr_points -> speed_array[levelJedi1])*(((86+rand()%15)*jedi2 -> jedi.ptr_points -> attack_array[levelJedi2])/(jedi1 -> jedi.ptr_points -> defense_array[levelJedi1])/10);
                        printf("%s ataca con un daño de: %d\n", jedi2 -> jedi.s_full_name, damage2);
                        printf("\n");
                        //Actualiza vida
                        jedi1 -> jedi.ptr_points -> hit_points = (jedi1 -> jedi.ptr_points -> hit_points)-damage2;
			
			if((jedi1 -> jedi.ptr_points -> hit_points < 0)){
			    jedi1-> jedi.ptr_points->hit_points = 0;
			}
                        if(jedi1 -> jedi.ptr_points -> hit_points > 0){
                        
                            damage1 = ((jedi1->jedi.ptr_points->speed_array[levelJedi1])/(jedi2->jedi.ptr_points -> speed_array[levelJedi2]))*(((86+rand()%15)*jedi1->jedi.ptr_points->attack_array[levelJedi1])/(jedi2->jedi.ptr_points->defense_array[levelJedi2])/10);
                            printf("%s ataca con un daño de: %d\n", jedi1 -> jedi.s_full_name, damage1);
                            printf("\n");
                            //Actualiza vida
                            jedi2 -> jedi.ptr_points -> hit_points = (jedi2 -> jedi.ptr_points -> hit_points)-damage1;
			    
			    if((jedi2 -> jedi.ptr_points -> hit_points < 0)){
				jedi2-> jedi.ptr_points->hit_points = 0;
			    }
                        }
                    }else{
                            //****Daño Producido
                        damage1 = ((jedi1->jedi.ptr_points->speed_array[levelJedi1])/(jedi2->jedi.ptr_points -> speed_array[levelJedi2]))*(((86+rand()%15)*jedi1->jedi.ptr_points->attack_array[levelJedi1])/(jedi2->jedi.ptr_points->defense_array[levelJedi2])/10);
                        printf("%s ataca con un daño de: %d\n", jedi1 -> jedi.s_full_name, damage1);
                        printf("\n");
                        //Actualiza vida
                        jedi2 -> jedi.ptr_points -> hit_points = (jedi2 -> jedi.ptr_points -> hit_points)-damage1;
                            if((jedi2 -> jedi.ptr_points -> hit_points < 0)){
				  jedi2-> jedi.ptr_points->hit_points = 0;
				}
                            if(jedi2 -> jedi.ptr_points -> hit_points > 0){
                                damage2 = (jedi2 -> jedi.ptr_points -> speed_array[levelJedi2]/jedi1 -> jedi.ptr_points -> speed_array[levelJedi1])*(((86+rand()%15)*jedi2 -> jedi.ptr_points -> attack_array[levelJedi2])/(jedi1 -> jedi.ptr_points -> defense_array[levelJedi1])/10);
                                printf("%s ataca con un daño de: %d\n", jedi2 -> jedi.s_full_name, damage2);
                                printf("\n");
                                //Actualiza vida
                                jedi1 -> jedi.ptr_points -> hit_points = (jedi1 -> jedi.ptr_points -> hit_points)-damage2;
				
				if((jedi1 -> jedi.ptr_points -> hit_points < 0)){
				  jedi1-> jedi.ptr_points->hit_points = 0;
				}
                            }
                    }
                }
                //****Un poco de suspense....
                sleep(1);
                printf("\t\tLa vida de %s es: %d\n", jedi1 -> jedi.s_full_name, jedi1 -> jedi.ptr_points -> hit_points);
                
                //****Otro poco más....
                sleep(1);
                
                printf("\t\tLa vida de %s es: %d\n", jedi2 -> jedi.s_full_name, jedi2 -> jedi.ptr_points -> hit_points);
                printf("\n");
            }   
            //****Comprobación si puede seguir el combate (vida = 0)
            if((jedi1 -> jedi.ptr_points -> hit_points <= 0)){
               printf("\n\n%s no podra combatir mas\n", jedi1 -> jedi.s_full_name);
               printf("\n\n¡%s gana!", jedi2 -> jedi.s_full_name);
	       if((levelJedi1 == 1) && (levelJedi2 == 0)){
		  jedi1-> jedi.ptr_points->level_jedi = 0;
		  jedi2-> jedi.ptr_points->level_jedi = 1;
	       }
            }
            if((jedi2 -> jedi.ptr_points -> hit_points <= 0)){
               printf("\n\n%s no podra combatir mas\n", jedi2 -> jedi.s_full_name);
               printf("\n\n¡%s gana!", jedi1 -> jedi.s_full_name);
	        if((levelJedi1 == 0) && (levelJedi2 == 1)){
		  jedi1-> jedi.ptr_points->level_jedi = 1;
		  jedi2-> jedi.ptr_points->level_jedi = 0;
	       }
            }
            printf("\n\n");
	
         }else {
             printf("Son Jedis, no zombies\n\n");
         }
    }
	return lista;
    
    
}
