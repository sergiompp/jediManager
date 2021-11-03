#include <stdio.h>
#include<stdlib.h>
#include<string.h> 

/**Función********************************************************************

  Resumen      [Crea el struct Jedi]

  Descripción  [Crea la estructura de los Jedi con sus parametros]

  Parámetros   [opcional]  

  Efec. Colat. []

  Ver también  [opcional]

******************************************************************************/
//0. STRUCT JEDI

struct points{
	int hit_points;
	int attack_array[2];
	int defense_array[2];
	double speed_array[2];
	enum level_jedi {T_APPRENTICE, T_MASTER} level_jedi;
};

struct Jedi{

	int id;
	char * s_full_name;
	int size_name;
	struct points *ptr_points;
};

struct Lista{
 struct Jedi jedi;
 struct Lista *sig;
};



