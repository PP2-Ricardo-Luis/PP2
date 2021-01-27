//TERCER PROYECTO PROGRAMADO.
//Ricardo Ramírez Salas y Luis Torres.

//Librerias implementadas.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//------------------------------------STRUCT NIÑOS-----------------------------------

/*Entradas: El nivel de acceso, nombre del niño (a), numero de cedula, correo y otros datos mas.
Salidas: Presenta un nuevo nodo en una lista simple.
Restricciones: Solo presenta un puntero a siguiente */

typedef struct nino
{
	char nombre[30], cedula[30], correo[30], necs[100], residencia[30];
	int dia, mes, anio, edad;
	struct nino* sig_Nino;
} nino;

//Variables generales de primer y ultimo niño
nino* primer_Nino=NULL;
nino* ultimo_Nino=NULL;

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

/*Entradas: Las variables para la creacion de un registro con los niños(as)
Salidas: Un nuevo nodo con los datos del nuevo niño(a)
Restricciones: Esta funcionalidad es solo para los niños(as) */
int nuevoNino(char *cedula, char  *nombre, char *correo,char *necesidades, int dia, int mes, int anio, int edad) //Funcion para insertar
{ 
	nino *nuevo=(nino*) malloc(sizeof(nino));
	
	strcpy(nuevo->nombre, nombre);
	strcpy(nuevo->cedula, cedula);
    strcpy(nuevo->correo, correo);
    strcpy(nuevo->necs, necesidades);
    nuevo->dia=dia;
    nuevo->mes=mes;
    nuevo->anio=anio;  
	nuevo->edad=edad;  
    //--------------------------FALTA RESIDENCIA-------------------	
    //--------------------------FALTA USUARIO DEL SISTEMA (AYUDANTE DE SANTA)

	if(primer_Nino==NULL)	
	{
		primer_Nino=nuevo;
		primer_Nino->sig_Nino=NULL;
		ultimo_Nino=nuevo;
	}
	ultimo_Nino->sig_Nino=nuevo;
	nuevo->sig_Nino=NULL;
	ultimo_Nino=nuevo;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Mostrar todos los niños.
/*Entradas: Todos los datos que presenta el struct de niños.
Salidas: Muestra en pantalla todos los datos de los miembros que se encuentren registrados. 
Restricciones: Solo se mostraran los niños(as) que esten inscritos previamente. */
void mostrar_Ninos()
{
	nino* actual = (nino*) malloc(sizeof(nino));
	actual = primer_Nino;
	
	if(primer_Nino != NULL)
	{
		while(actual != NULL)
		{
		
			printf("\n   ---Informacion del Nino(a)----   \n");
			printf("\n  Nombre completo: %s",actual->nombre);
			printf("\n  Cedula: %s",actual->cedula);  
			printf("\n  Correo electronico: %s",actual->correo);
			printf("\n  Necesidades especiales: %s",actual->necs);
			printf("\n  Residencia: %s",actual->residencia);
			printf("\n  Edad: %i",actual->edad);
			printf("\n  Fecha de nacimiento: %i/%i/%i",actual->dia, actual->mes, actual->anio); 
			actual = actual->sig_Nino;// siguiente puntero en lista
		}
	}
	else
	{
		printf("\n No hay ninos registrados en el programa.\n\n");
	}
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//Modificar los datos de un niño(a)
/*Entradas: Todos los datos que presenta el struct de niños.
Salidas: Se modifican los datos que el usuario necesite. 
Restricciones: Solo se mostraran los miembros que esten inscritos previamente.*/
int modificar_Nino() 
{
	char id[12], nombre[30], elecc[3]="Si";
	int dato=-1, encontrado;
	
	nino* actual = (nino*) malloc(sizeof(nino)); 
	actual = primer_Nino;
	
	printf("Ingrese el numero de identificacion del nino(a) que se requiere modificar los datos, usar formato (X-XXXX-XXXX): "); 
	fflush(stdin);
	scanf("%[^\n]", &id);
	while (strlen(id)!=11)
	{
		printf("Error en el numero de identificacion del nino(a),ingrese el formato solicitado (X-XXXX-XXXX): ");
		fflush(stdin);
		scanf("%[^\n]", &id);
	}
	
	if(primer_Nino!=NULL)
	{
		while(actual!=NULL && encontrado!=1)
		{
			if (strcmp(actual->cedula, id)==0)
			{
				printf("\n   ---Informacion del Nino(a)----   \n");
				printf("\n  1) Nombre completo: %s",actual->nombre);
				printf("\n  2) Cedula: %s",actual->cedula);  
				printf("\n  3) Correo electronico: %s",actual->correo);
				printf("\n  4) Necesidades especiales: %s",actual->necs);
				printf("\n  5) Residencia: %s",actual->residencia);
				printf("\n  6) Edad: %i",actual->edad);
				printf("\n  7) Fecha de nacimiento: %i/%i/%i",actual->dia, actual->mes, actual->anio); 
				encontrado=1;
			}
			else
			{
				actual=actual->sig_Nino;
			}	
		}
	}
	else
	{
		printf("\n El numero de identificacion del niño(a) no se encuentra registrado en el programa.\n\n");
	}
	
	while (strcmp(elecc,"Si")==0 || strcmp(elecc,"si")==0)
	{
		while(dato<1 || dato>7) 
        {
            printf("\nIngrese la opcion del dato que desea modificar: ");
           fflush(stdin);
            scanf("%i", &dato);
        }
		
		if (dato==1)
		{
			printf("Ingrese el nombre completo del nino(a): ");
			fflush(stdin); 
			scanf("%[^\n]",&actual->nombre);
		}
		else if (dato==2)
		{
			printf("Ingrese el numero de identificacion del nino(a) con el formato X-XXXX-XXXX: ");
			fflush(stdin);
			scanf("%[^\n]", &actual->cedula);
			while (strlen(actual->cedula)!=11)
			{
				printf("Error en el numero de identificacion del nino(a),ingrese el formato solicitado (X-XXXX-XXXX): ");
				fflush(stdin);
				scanf("%[^\n]", &actual->cedula);
			}
		}
		else if (dato==3)
		{
			printf("Ingrese el nuevo correo electronico: ");
			scanf("%s",&actual->correo);
		}
		else if (dato==4)
		{
			printf("Ingrese las necesidades particulares del nino(a), si no posee alguna necesidad digite 'No posee': ");
			fflush(stdin);
			scanf("%[^\n]", &actual->necs);
		}
		else if (dato==5)
		{
			printf("Ingrese la residencia del nino(a): ");
			fflush(stdin);
			scanf("%[^\n]", &actual->residencia);
		}
		else if (dato==6)
		{
			actual->edad=-1;
			while(actual->edad < 0 || actual->edad > 99)
	        {
	            printf("Ingrese la edad que tiene el nino(a): ");
	            fflush(stdin);
	            scanf("%i", &actual->edad);
	        }
		}
		else if (dato==7)
		{
			int diaActual, mesActual, anioActual, edad;
			char  diaSTR[3], mesSTR[3], anioSTR[5]; 
			
			time_t tiempo = time(0);
			struct tm *tlocal = localtime(&tiempo);
		
			strftime(mesSTR,3,"%m",tlocal);
			strftime(anioSTR,5,"%Y",tlocal);
			strftime(diaSTR,3,"%d",tlocal);
		
			diaActual=atoi(diaSTR);
			mesActual=atoi(mesSTR);
			anioActual=atoi(anioSTR);
			
			printf("Ingrese el anio de nacimiento del nino(a): "); 
			while(scanf("%i", &actual->anio)!=1) 
            {
            	printf("\n Error, ingrese nuevamente el anio de nacimiento del nino(a): ");
                fflush(stdin);
            }
			while (actual->anio>anioActual || actual->anio<1000) 
			{
				printf("\n Error, ingrese nuevamente el anio del nacimiento del nino(a): ");
				scanf("%i", &actual->anio);
			}
			if (actual->anio==anioActual)
			{
				printf("Ingrese el mes de nacimiento del nino(a): "); 
				while(scanf("%i", &actual->mes)!=1) 
	            {
	            	printf("\nError, ingrese nuevamente el mes de nacimiento del nino(a): ");
	                fflush(stdin);
	            }
				while (actual->mes>mesActual || actual->mes<1)
				{
					printf("\n Error, ingrese nuevamente el mes del nacimiento del nino(a): ");
					scanf("%i", &actual->mes);
				}
				
				printf("Ingrese el dia de nacimiento del nino(a): "); 
				while(scanf("%i", &actual->dia)!=1) 
	            {
	            	printf("\n Error, ingrese nuevamente el dia de nacimiento del nino(a): ");
	                fflush(stdin);
	            }
				while (actual->dia>diaActual || actual->dia<1)
				{
					printf("\n Error, ingrese nuevamente el dia del nacimiento del nino(a): ");
					scanf("%i", &actual->dia);
				}
			}
			else
			{
				printf("\n Ingrese el mes de nacimiento del nino(a): "); 
				while(scanf("%i", &actual->mes)!=1) 
	            {
	            	printf("\n Error, ingrese nuevamente el mes de nacimiento del nino(a): ");
	                fflush(stdin);
	            }
				while (actual->mes>12 || actual->mes<1)
				{
					printf("\n Error, ingrese nuevamente el mes del nacimiento del nino(a): ");
					scanf("%i", &actual->mes);
				}
				
				printf("Ingrese el dia de nacimiento del nino(a): "); 
				while(scanf("%i", &actual->dia)!=1) 
	            {
	            	printf("\n Error, ingrese nuevamente el dia de nacimiento del nino(a): ");
	                fflush(stdin);
	            }
				while (actual->dia>31 || actual->dia<1)
				{
					printf("\nError, ingrese nuevamente el DIA del nacimiento del nino(a): ");
					scanf("%i", &actual->dia);
				}
			}
		}
		printf("\nSi desea modificar otro dato, digite 'Si', digite 'No' en caso contrario: ");
		scanf("%s",&elecc);
		dato=0;
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//Eliminar un niño(a) del programa.
/*Entradas: Todos los datos que presenta el struct de niños.
  Salidas: El niño quedará eliminado del programa.
  Restricciones:  Automaticamente no quedará ningún dato del niño (a) en el programa.*/

void eliminarNino(char *id_nino)
{
	nino* actual=(nino*) malloc(sizeof(nino));
	actual=primer_Nino;
	nino* anterior=(nino*) malloc(sizeof(nino));
	anterior=NULL;
	int encontrado=0;
	
	if(primer_Nino!=NULL)
	{
		while(actual!=NULL && encontrado!=1)
		{
			
			if(strcmp(actual->cedula,id_nino)==0)
			{
	
				if(actual==primer_Nino)
				{
					primer_Nino=primer_Nino->sig_Nino;
				}
				else if(actual==ultimo_Nino)
				{
					anterior->sig_Nino=NULL;
					ultimo_Nino=anterior;
				}
				else
				{
					anterior->sig_Nino=actual->sig_Nino;
				}
				
				printf("\nEl nino (a) quedo eliminado(a) del programa de manera exitosamente");
				encontrado=1;
			}
			anterior=actual;
			actual=actual->sig_Nino;
		}
		if(encontrado==0)
		{
			printf("\nError, el nino(a) no fue encontrado en el programa.\n\n");
		}
		else
		{
			free(anterior);
		}
	}
	else
	{
		printf("\nLa lista se encuentra vacia\n\n");
	}
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

//Menu principal de la estructura de los niños(as)
/*Entradas: No posee entradas.
Salidas: Las diferentes funciones que presenta la estructura.
Restricciones: Solo se pueden realizar las funciones que presente el menu */
int Ninos()
{

	int opc, verificar, dia, mes, anio, diaActual, mesActual, anioActual, edad;
	char  nombre[30], correo[30], cedula[30], temp_cedula[30], neces[100], id_nino[12], diaSTR[3], mesSTR[3], anioSTR[5]; 

	time_t tiempo = time(0);
	struct tm *tlocal = localtime(&tiempo);

	strftime(mesSTR,3,"%m",tlocal);
	strftime(anioSTR,5,"%Y",tlocal);
	strftime(diaSTR,3,"%d",tlocal);

	diaActual=atoi(diaSTR);
	mesActual=atoi(mesSTR);
	anioActual=atoi(anioSTR);
	
	while(opc!=5)
	{
	    printf("\n            ---NINOS (AS)---          ");
		printf("\n       1) Agregar nino(a)              ");
		printf("\n       2) Mostrar ninos(as)            ");
	    printf("\n       3) Modificar datos de nino(a)   ");
		printf("\n       4) Eliminar nino(a)             ");
	    printf("\n       5) Volver al menu principal     ");
	    
		printf("\n\nIngrese el numero de la funcion a revisar:  ");
		fflush(stdin);   
	   	if(scanf("%d",&opc)!=1)
    	{
			printf("Error, la opcion ingresa fue incorrecta. \n"); 
		}
		else
		{ 	 
		
			if(opc==1)
			{
				nino* actual=(nino*) malloc(sizeof(nino));
				actual=primer_Nino;
				
				printf("Ingrese el nombre completo del nino(a): ");
				fflush(stdin); 
				scanf("%[^\n]",&nombre);
	
				
				printf("Ingrese el numero de identificacion del nino(a) con un formato X-XXXX-XXXX: ");
				fflush(stdin);
				scanf("%[^\n]", &temp_cedula);
				while (strlen(temp_cedula)!=11)
				{
					printf("Error en el numero de identificacion del nino(a),ingrese el formato solicitado (X-XXXX-XXXX): ");
					fflush(stdin);
					scanf("%[^\n]", &temp_cedula);
				}
				
				while(actual!=NULL)
				{
					if (strcmp(actual->cedula , temp_cedula)==0)
					{ 
						verificar++;
					}
					actual = actual->sig_Nino;
				}
				
				printf("Ingrese la direccion de correo electronico: ");
				scanf("%s", correo);
				
				printf("Ingrese las necesidades particulares del nino(a), si no posee digite 'No posee': ");
				fflush(stdin);
				scanf("%[^\n]", &neces);
				
				printf("\n Ingrese el numero que corresponde a lo que se le solicita a continuacion\n");
				printf("Digite el anio de nacimiento del nino(a): "); 
				while(scanf("%i", &anio)!=1) 
	            {
	            	printf("\n Error, ingrese nuevamente el anio de nacimiento del nino(a): ");
	                fflush(stdin);
	            }
	           	while (anio>anioActual || anio<1000) 
				{
					printf("\n Error, ingrese nuevamente el anio de nacimiento del nino(a): ");
					scanf("%i", &anio);
				}
	
				if (anio==anioActual)
				{
					printf("Ingrese el mes de nacimiento del nino(a): "); 
					while(scanf("%i", &mes)!=1) 
		            {
		            	printf("\n Error, ingrese nuevamente el mes de nacimiento del nino(a): ");
		                fflush(stdin);
		            }
					while (mes>mesActual || mes<1) 
					{
						printf("\n Error, ingrese nuevamente el mes de nacimiento del nino(a): ");
						scanf("%i", &mes);
					}
					
					printf("Ingrese el dia de nacimiento del nino(a): "); 
					while(scanf("%i", &dia)!=1) 
		            {
		            	printf("\n Error, ingrese nuevamente el dia de nacimiento del nino(a): ");
		                fflush(stdin);
		            }
					while (dia>diaActual || dia<1)
					{
						printf("\n Error, ingrese nuevamente el dia de nacimiento del nino(a): ");
						scanf("%i", &dia);
					}
				}
				else
				{
					printf("Ingrese el mes de nacimiento del nino(a): "); 
					while(scanf("%i", &mes)!=1)
		            {
		            	printf("\n Error, ingrese nuevamente el mes de nacimiento del nino(a): ");
		                fflush(stdin);
		            }
					while (mes>12 || mes<1)
					{
						printf("\n Error, ingrese nuevamente el mes de nacimiento del nino(a): ");
						scanf("%i", &mes);
					}
					
					printf("Ingrese el dia de nacimiento del nino(a): "); 
					while(scanf("%i", &dia)!=1) 
		            {
		            	printf("\n Error, ingrese nuevamente el dia de nacimiento del nino(a): ");
		                fflush(stdin);
		            }
					while (dia>31 || dia<1)
					{
						printf("\n Error, ingrese nuevamente el dia de nacimiento del nino(a): ");
						scanf("%i", &dia);
					}
				}
				
				edad=anioActual-anio-1;
				if(mes<mesActual)
				{
					edad++;
				}
				else if(mes==mesActual && dia<=diaActual)
				{
					edad++;
				}
				                
				if(verificar==0)
				{
					strcpy(cedula, temp_cedula);
					nuevoNino(cedula, nombre, correo, neces, dia, mes, anio, edad);
					printf("\n El niño(a) se ha agregado de manera exitosa.\n");
				}
				else 
				{
					printf("\El niño(a) ya ha sido registrado anteriormente.\n");
				}
			}
			else if(opc==2)
			{
				mostrar_Ninos();
			}
			else if(opc==3)
			{
				modificar_Nino();
			}
			else if(opc==4)
			{
				printf("Ingrese el numero de identificacion del nino(a) a eliminar con formato X-XXXX-XXXX: ");
				fflush(stdin);
				scanf("%[^\n]", &id_nino);
				while (strlen(id_nino)!=11)
				{
					printf("Error en el numero de identificacion del nino(a),ingrese el formato solicitado (X-XXXX-XXXX): ");
					fflush(stdin);
					scanf("%[^\n]", &id_nino);
				}
				eliminarNino(id_nino);
			}
		}
	}
}	


//***********************************************************************************************************************************************************


//------------------------------------STRUCT AYUDANTES-----------------------------------


/*Entradas: El nivel de acceso, nombre del niño (a), numero de cedula, correo y otros datos mas.
Salidas: Presenta un nuevo nodo en una lista simple.
Restricciones: Solo presenta un puntero a siguiente */

typedef struct ayudante
{
	char nombre[30], cedula[30], puesto[30], funcs[100];
	int dia, mes, anio;
	struct ayudante* sig_Ayudante;
} ayudante;

//Variables generales de primer y ultimo ayudante
ayudante* primer_Ayudante=NULL;
ayudante* ultimo_Ayudante=NULL;

//----------------------------------------------------------------------------------------------------------------------------------------------------------

/*Entradas: Las variables para la creacion de un registro con los ayudantes.
Salidas: Un nuevo nodo con los datos del nuevo ayudante
Restricciones: Esta funcionalidad solo es para los ayudantes.  */
int nuevoAyudante(char *cedula, char  *nombre, char *puesto,char *funcs, int dia, int mes, int anio) 
{ 
	ayudante *nuevo=(ayudante*) malloc(sizeof(ayudante));
	
	strcpy(nuevo->nombre, nombre);
	strcpy(nuevo->cedula, cedula);
    strcpy(nuevo->puesto, puesto);
    strcpy(nuevo->funcs, funcs);
    nuevo->dia=dia;
    nuevo->mes=mes;
    nuevo->anio=anio;  
    
	if(primer_Ayudante==NULL)	
	{
		primer_Ayudante=nuevo;
		primer_Ayudante->sig_Ayudante=NULL;
		ultimo_Ayudante=nuevo;
	}
	ultimo_Ayudante->sig_Ayudante=nuevo;
	nuevo->sig_Ayudante=NULL;
	ultimo_Ayudante=nuevo;
}


//----------------------------------------------------------------------------------------------------------------------------------------------------------

//Mostrar toda la informacion de todos los ayudantes de santa
/*Entradas: Todos los datos que presenta el struct de ayudantes
Salidas: Muestra en pantalla todos los datos de los ayudantes que se encuentren registrados. 
Restricciones: Solo se mostraran los niños(as) que esten inscritos previamente. */
void mostrar_Ayudantes()
{
	ayudante* actual=(ayudante*) malloc(sizeof(ayudante)); // crea nodos 
	actual=primer_Ayudante;
	
	if(primer_Ayudante!=NULL)
	{
		while(actual!=NULL)
		{
		
			printf("\n    ---Informacion del Ayudante de Santa---\n");
			printf("\n   Nombre completo: %s",actual->nombre);
			printf("\n   Cedula: %s",actual->cedula);
			printf("\n   Puesto: %s",actual->puesto);
			printf("\n   Funciones: %s",actual->funcs);
			printf("\n   Fecha de inicio de labores: %i/%i/%i", actual->dia, actual->mes, actual->anio);
			actual=actual->sig_Ayudante;
		}
	}
	else
	{
		printf("\n No hay ayudantes registrados en el programa.\n\n");
	}
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

//Modificar los datos de un ayudante.
/*Entradas: Todos los datos que presenta el struct de ayudantes.
Salidas: Se modifican los datos que el usuario necesite. 
Restricciones: Solo se mostraran los miembros que esten inscritos previamente.*/
int modificar_Ayudante() 
{
	char id[12], nombre[30], elecc[3]="Si";
	int dato, encontrado;
	
	ayudante* actual=(ayudante*) malloc(sizeof(ayudante)); 
	actual=primer_Ayudante;
	
	printf("Ingrese el numero de identificacion del ayudante del cual desea modificar sus datos con un formato (X-XXXX-XXXX): "); 
	fflush(stdin);
	scanf("%[^\n]", &id);
	while (strlen(id)!=11)
	{
		printf("Error, ingrese nuevamente el numero de identificacion del ayudante, con el formato solicitado (X-XXXX-XXXX): ");
		fflush(stdin);
		scanf("%[^\n]", &id);
	}
	
	if(primer_Ayudante!=NULL)
	{
		while(actual!=NULL && encontrado!=1)
		{
			if (strcmp(actual->cedula, id)==0)
			{
				printf("\n    ---Informacion del Ayudante de Santa---\n");
				printf("\n   Nombre completo: %s",actual->nombre);
				printf("\n   Cedula: %s",actual->cedula);
				printf("\n   Puesto: %s",actual->puesto);
				printf("\n   Funciones: %s",actual->funcs);
				printf("\n   Fecha de inicio de labores: %i/%i/%i", actual->dia, actual->mes, actual->anio);
				encontrado=1;
			}
			else
			{
				actual=actual->sig_Ayudante;
			}
			
		}
	}
	else
	{
		printf("\Error, el ayudante no esta registrado en el programa.\n\n");
	}
	
	while (strcmp(elecc,"Si")==0 || strcmp(elecc,"si")==0)
	{
		printf("\nIngrese el numero correspondiente al dato que desea modificar: ");
		scanf("%i",&dato);
		
		if (dato==1)
		{
			printf("Ingrese el nombre completo del ayudante: ");
			fflush(stdin); 
			scanf("%[^\n]",&actual->nombre);
		}
		else if (dato==2)
		{
			printf("Ingrese el numero de identificacion del ayudante de santa (formato X-XXXX-XXXX): ");
			fflush(stdin);
			scanf("%[^\n]", &actual->cedula);
			while (strlen(actual->cedula)!=11) 
			{
				printf("Error, ingrese nuevamente el numero de identificacion del ayudante, con el formato solicitado (X-XXXX-XXXX): ");
				fflush(stdin);
				scanf("%[^\n]", &actual->cedula);
			}
		}
		else if (dato==3)
		{
			printf("Ingrese el nuevo puesto: ");
			scanf("%s",&actual->puesto);
		}
		else if (dato==4)
		{
			printf("Describa las funciones que desempeña: ");
			fflush(stdin);
			scanf("%[^\n]", &actual->funcs);
		}
		
		else if (dato==5)
		{
			int diaActual, mesActual, anioActual, edad;
			char  diaSTR[3], mesSTR[3], anioSTR[5]; 
			
			time_t tiempo = time(0);
			struct tm *tlocal = localtime(&tiempo);
		
			strftime(mesSTR,3,"%m",tlocal);
			strftime(anioSTR,5,"%Y",tlocal);
			strftime(diaSTR,3,"%d",tlocal);
		
			diaActual=atoi(diaSTR);
			mesActual=atoi(mesSTR);
			anioActual=atoi(anioSTR);
			
			printf("Ingrese el anio en el que inicio labores con Santa: "); 
			while(scanf("%i", &actual->anio)!=1) 
            {
            	printf("Error, ingrese nuevamente el anio en el que inicio labores con Santa: ");
                fflush(stdin);
            }
			while (actual->anio>anioActual || actual->anio < 1000) 
			{
				printf("Error, ingrese nuevamente el anio en el que inicio labores con Santa: ");
				scanf("%i", &actual->anio);
			}
			if (actual->anio==anioActual)
			{
				printf("Ingrese el mes en el que inicio labores con Santa: ");
				while(scanf("%i", &actual->mes)!=1) 
	            {
	            	printf("Error, ingrese nuevamente el mes en el que inicio labores con Santa: ");
	                fflush(stdin);
	            }
				while (actual->mes>mesActual || actual->mes<1)
				{
					printf("Error, ingrese nuevamente el mes en el que inicio labores con Santa: ");
					scanf("%i", &actual->mes);
				}
				
				printf("Ingrese el dia en el que inicio labores con Santa: ");
				while(scanf("%i", &actual->dia)!=1)
	            {
	            	printf("Error, ingrese nuevamente el dia en el que inicio labores con Santa: ");
	                fflush(stdin);
	            }
				while (actual->dia>diaActual || actual->dia<1)
				{
					printf("Error, ingresa nuevamente el dia en el que inicio labores con Santa: ");
					scanf("%i", &actual->dia);
				}
			}
			else
			{
				printf("Ingrese el mes en el que inicio labores con Santa: "); 
				while(scanf("%i", &actual->mes)!=1) 
	            {
	            	printf("Error, ingrese nuevamente el mes en el que inicio labores con Santa: ");
	                fflush(stdin);
	            }
				while (actual->mes>12 || actual->mes<1)
				{
					printf("Error, ingrese nuevamente el MES en el que inicio labores con Santa: ");
					scanf("%i", &actual->mes);
				}
				
				printf("Ingrese el dia en el que inicio labores con Santa: "); 
				while(scanf("%i", &actual->dia)!=1)
	            {
	            	printf("Error, ingrese nuevamente el dia en el que inicio labores con Santa: ");
	                fflush(stdin);
	            }
				while (actual->dia>31 || actual->dia<1)
				{
					printf("Error, ingrese nuevamente el dia en el que inicio labores con Santa: ");
					scanf("%i", &actual->dia);
				}
			}
		}
		printf("Si desea modificar otro dato, digite 'Si', digite 'No' en caso contrario: ");
		scanf("%s",&elecc);
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

//Eliminar un ayudante
/*Entradas: Todos los datos que presenta el struct de ayudantes.
  Salidas: El ayudante quedará eliminado del programa.
  Restricciones:  Automaticamente no quedará ningún dato del ayudante en el programa.*/
void eliminarAyudante(char *id_ayudante)
{
	ayudante* actual=(ayudante*) malloc(sizeof(ayudante));
	actual=primer_Ayudante;
	ayudante* anterior=(ayudante*) malloc(sizeof(ayudante));
	anterior=NULL;
	int encontrado=0;
	
	if(primer_Ayudante!=NULL)
	{
		while(actual!=NULL && encontrado!=1)
		{
			
			if(strcmp(actual->cedula,id_ayudante)==0)
			{
	
				if(actual==primer_Ayudante)
				{
					primer_Ayudante=primer_Ayudante->sig_Ayudante;
				}
				else if(actual==ultimo_Ayudante)
				{
					anterior->sig_Ayudante=NULL;
					ultimo_Ayudante=anterior;
				}
				else
				{
					anterior->sig_Ayudante=actual->sig_Ayudante;
				}
				
				printf("\nEl ayudante de santa quedo eliminado del programa de manera exitosamente.");
				encontrado=1;
			}
			anterior=actual;
			actual=actual->sig_Ayudante;
		}
		if(encontrado==0)
		{
			printf("\nError, el ayudante no fue encontrado en el programa.\n\n");
		}
		else
		{
			free(anterior);
		}
	}
	else
	{
		printf("\nLa lista se encuentra vacia\n\n");
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------

//Menu principal de la estructura de los ayudantes
/*Entradas: No posee entradas.
Salidas: Las diferentes funciones que presenta la estructura.
Restricciones: Solo se pueden realizar las funciones que presente el menu */
int Ayudantes()
{

	int opc, verificar, dia, mes, anio, diaActual, mesActual, anioActual;
	char  nombre[30], puesto[30], cedula[30], temp_cedula[30], funcs[100], id_ayudante[12], diaSTR[3], mesSTR[3], anioSTR[5]; 
	
	time_t tiempo = time(0);
	struct tm *tlocal = localtime(&tiempo);

	strftime(mesSTR,3,"%m",tlocal);
	strftime(anioSTR,5,"%Y",tlocal);
	strftime(diaSTR,3,"%d",tlocal);

	diaActual=atoi(diaSTR);
	mesActual=atoi(mesSTR);
	anioActual=atoi(anioSTR);
	
	while(opc!=5)
	{
	    
	    printf("\n        ---AYUDANTES DE SANTA---        ");
		printf("\n       1) Agregar ayudante              ");
		printf("\n       2) Mostrar ayudantes             ");
	    printf("\n       3) Modificar datos de ayudante   ");
		printf("\n       4) Eliminar ayudante             ");
	    printf("\n       5) Volver al menu principal      ");

		printf("\n\nIngrese el numero de la funcion a revisar:  ");
	 	fflush(stdin);   
	   	if(scanf("%d",&opc)!=1)
    	{
			printf("Error, la opcion ingresa fue incorrecta. \n"); 
		}
		else
		{    
		
			if(opc==1)
			{
				ayudante* actual=(ayudante*) malloc(sizeof(ayudante));
				actual=primer_Ayudante;
				
				printf("Ingrese el nombre completo del ayudante: ");
				fflush(stdin);
				scanf("%[^\n]",&nombre);
	
				
				printf("Ingrese el numero de identificacion con formato X-XXXX-XXXX: ");
				fflush(stdin);
				scanf("%[^\n]", &temp_cedula);
				while (strlen(temp_cedula)!=11) 
				{
					printf("Error, ingrese nuevamente el numero de identificacion, siguiendo el formato solicitado (X-XXXX-XXXX): ");
					fflush(stdin);
					scanf("%[^\n]", &temp_cedula);
				}
				
				while(actual!=NULL)
				{
					if (strcmp(actual->cedula , temp_cedula)==0)
					{ 
						verificar++;
					}
					actual=actual->sig_Ayudante;
				}
				
				printf("Puesto: ");
				fflush(stdin);
				scanf("%[^\n]", &puesto);
				
				printf("Funciones que desempenia: ");
				fflush(stdin);
				scanf("%[^\n]", &funcs);
				
				printf("Ingrese el numero que corresponde a lo que se le solicita a continuacion\n");
				printf("Ingrese el anio en el que inicio labores con Santa: "); 
				while(scanf("%i", &anio)!=1)
	            {
	            	printf("Error, ingrese nuevamente el dia en el que inicio labores con Santa: ");
	                fflush(stdin);
	            }
				while (anio>anioActual || anio<1000) 
				{
					printf("Error, ingrese nuevamente el anio en el que inicio labores con Santa: ");
					scanf("%i", &anio);
				}
				if (anio==anioActual)
				{
					printf("Ingrese el mes en el que inicio labores con Santa: "); 
					while(scanf("%i", &mes)!=1)
		            {
		            	printf("Error, ingrese nuevamente el mes en el que inicio labores con Santa: ");
		                fflush(stdin);
		            }
					while (mes>mesActual || mes<1)
					{
						printf("Ingrese nuevamente el mes en el que inicio labores con Santa: ");
						scanf("%i", &mes);
					}
					
					printf("Ingrese el dia en el que inicio labores con Santa: "); 
					while(scanf("%i", &dia)!=1)
		            {
		            	printf("Error, ingrese nuevamente el dia en el que inicio labores con Santa: ");
		                fflush(stdin);
		            }
					while (dia>diaActual || dia<1)
					{
						printf("Error, ingrese nuevamente el dia en el que inicio labores con Santa: ");
						scanf("%i", &dia);
					}
				}
				else
				{
					printf("Ingrese el mes en el que inicio labores con Santa: "); 
					while(scanf("%i", &mes)!=1)
		            {
		            	printf("Error, ingrese nuevamente el mes en el que inicio labores con Santa: ");
		                fflush(stdin);
		            }
					while (mes>12 || mes<1)
					{
						printf("Error, ingrese nuevamente el mes en el que inicio labores con Santa: ");
						scanf("%i", &mes);
					}
					
					printf("Ingrese el dia en el que inicio labores con Santa: "); 
					while(scanf("%i", &dia)!=1)
		            {
		            	printf("Error, ingrese nuevamente el dia en el que inicio labores con Santa: ");
		                fflush(stdin);
		            }
					while (dia>31 || dia<1)
					{
						printf("Error, ingrese nuevamente el dia en el que inicio labores con Santa: ");
						scanf("%i", &dia);
					}
				}
				                
				if(verificar==0)
				{
					strcpy(cedula, temp_cedula);
					nuevoAyudante(cedula, nombre, puesto, funcs, dia, mes, anio);
					printf("\nEl ayudante de santa se ha registrado de manera exitosa.\n");
				}
				else 
				{
					printf("\nError, el ayudante de santa ya fue registrado anteriormente\n");
				}
			}
			else if(opc==2)
			{
				mostrar_Ayudantes();
			}
			else if(opc==3)
			{
				modificar_Ayudante();
			}
			else if(opc==4)
			{
				printf("Ingrese el numero de identificacion del ayudante a eliminar (formato X-XXXX-XXXX): ");
				fflush(stdin);
				scanf("%[^\n]", &id_ayudante);
				while (strlen(id_ayudante)!=11)
				{
					printf("Error, ingrese nuevamente el numero de identificacion del ayudante, con el formato solicitado (X-XXXX-XXXX): ");
					fflush(stdin);
					scanf("%[^\n]", &id_ayudante);
				}
				eliminarAyudante(id_ayudante);
			}
		}
	}
}	


//**********************************************************************************************************************************************************


//------------------------------------STRUCT JUGUETES-----------------------------------
/*Entradas: El nombre, la descripcion y la categoria del juguete.
Salidas: Presenta un nuevo nodo en una lista simple.
Restricciones: Solo presenta un puntero a siguiente */

struct juguete
{
    int codigo, min, max, costo, cant; 
    char nombre[30], desc[100], categoria[30];
	struct juguete *hijo_der;
    struct juguete *hijo_izq;
}*root=NULL;
typedef struct juguete jug;

//---------------------------------------------------------------------------------------------------------------------------------------------------------
/*Entradas: Las variables para la creacion de un registro con los juguetes.
Salidas: Un nuevo nodo con los datos del nuevo juguete
Restricciones: Esta funcionalidad solo es para los juguetes  */
struct juguete* nuevoJuguete(int cod, char *nombre, char *desc, char *categoria, int max, int min, int costo)
{
    struct juguete *nuevo;
    nuevo = malloc(sizeof(struct juguete));
    
    nuevo->codigo=cod;
    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo->desc, desc);
	strcpy(nuevo->categoria, categoria);
    nuevo->max=max;
    nuevo->min=min;
    nuevo->costo=costo;
    
    nuevo->hijo_izq = NULL;
    nuevo->hijo_der = NULL;

    return nuevo;
}

struct juguete* insertarJuguete(struct juguete *root, int cod, char *nombre, char *desc, char *categoria, int max, int min, int costo)
{
    if(root==NULL)
    {
    	return nuevoJuguete(cod, nombre, desc, categoria, max, min, costo);
	}   
    else if(cod>root->codigo) 
    {
    	root->hijo_der=insertarJuguete(root->hijo_der, cod, nombre, desc, categoria, max, min, costo);
	}   
    else
    {
    	root->hijo_izq = insertarJuguete(root->hijo_izq,cod, nombre, desc, categoria, max, min, costo);
	}
    return root;
}


//MOSTRAR TODOS LOS JUGUETES//
void mostrarJuguetes(struct juguete *root)
{
    if(root!=NULL) 
    {
        mostrarJuguetes(root->hijo_izq);
        
        printf("\n Juguete-0%d\n", root->codigo);
        printf("\n Nombre: %s\n", root->nombre);
        printf("\n Categoria: %s\n", root->categoria);
        printf("\n Descripcion: %s\n", root->desc);
        printf("\n Rango de edad recomendado: %d-%d\n\n", root->min, root->max);
        
        mostrarJuguetes(root->hijo_der);
    }
}

//MODIFICAR DATOS JUGUETE//
void modificarJug(jug *root, char *juguete) //BUSCAR UN JUGUETE
{
	int dato;
	char elecc[3]="Si";
	
    if (root!=NULL) 
	{ 
        /* If root is not NULL... */

        /* recursively process hijo_izq subtree if present.. */
        if (root->hijo_izq) 
        {
        	modificarJug(root->hijo_izq, juguete);
		}
		
        /* then check the current node.. */
        if (strcmp(root->nombre, juguete)) 
		{
            printf("\n              Juguete-0%d\n", root->codigo                       );
	        printf("\n  1) Nombre: %s\n", root->nombre                                 );
	        printf("\n  2) Categoria: %s\n", root->categoria                           );
	        printf("\n  3) Descripcion: %s\n", root->desc                              );
	        printf("\n  4) Rango de edad recomendado: %d-%d\n", root->min, root->max   );
	        printf("\n  5) Costo total del juguete: $%d\n\n", root->costo              );
	        
	        while (strcmp(elecc,"si")==0 || strcmp(elecc,"Si")==0)
	        {
	        	printf("\n Ingrese el numero correspondiente al dato que desea modificar: ");
				scanf("%i",&dato);
				while(dato<0)
		        {
		            printf("\n Ingrese nuevamente el numero de dato a modificar: ");
		            fflush(stdin);
		            scanf("%i", &dato);
		        }
					
				if (dato==1)
				{
					printf("Ingrese el nuevo nombre del juguete: ");
					fflush(stdin);
					scanf("%[^\n]", &root->nombre);
				}
				else if (dato==2)
				{
					printf("Ingrese la nueva categoria del juguete: ");
					fflush(stdin);
					scanf("%[^\n]", &root->categoria);
				}
				else if (dato==3)
				{
					printf("Ingrese la descripcion del juguete: ");
					fflush(stdin);
					scanf("%[^\n]", &root->desc);
				}
				else if (dato==4)
				{
					printf("La edad maxima recomendada para utilizar el juguete: ");
					scanf("%i", &root->max);
					
					printf("La edad minima recomendada para utilizar el juguete: "); 
					scanf("%i", &root->min);
					while (root->min>root->max)
					{
						printf("Error, ingrese nuevamente la edad minima para utilizar el juguete: ");
						scanf("%i", &root->min);
					}
				}
				else if (dato==5)
				{
					printf("El costo total de fabricacion es: $");
					scanf("%d",&root->costo);
				}
				printf("Si desea modificar otro dato, digite 'Si', digite 'No' en caso contrario: ");
				scanf("%s",&elecc);
			}
        }

        /* then recursively process the hijo_der subtree if present. */
        if (root->hijo_der) 
        {
        	modificarJug(root->hijo_der, juguete);
		}
    } 
	else
	{
		printf("No hay juguetes registrados");
	}
}

//function to find the minimum value in a juguete
struct juguete* find_minimum(struct juguete *root)
{
    if(root == NULL)
    {
    	return NULL;
	}
    else if(root->hijo_izq != NULL) // juguete with minimum value will have no hijo_izq child
    {
    	return find_minimum(root->hijo_izq); // hijo_izq most element will be minimum
	}
    return root;
}
//ELIMINAR JUGUETE//
struct juguete* eliminarJug(struct juguete *root, int cod)
{
    int encontrado=0;

    if(root!=NULL)
    {

                //searching for the item to be deleted
                if(root==NULL)
                    return NULL;
                if (cod>root->codigo)
                    root->hijo_der = eliminarJug(root->hijo_der, cod);
                else if(cod<root->codigo)
                    root->hijo_izq = eliminarJug(root->hijo_izq, cod);
                else
                {
                    //No Children
                    if(root->hijo_izq==NULL && root->hijo_der==NULL)
                    {
                        root=NULL;
                    }

                    //One Child
                    else if(root->hijo_izq==NULL || root->hijo_der==NULL)
                    {
                        struct juguete *temp;
                        if(root->hijo_izq==NULL)
                        {
                            temp = root->hijo_der;
                        }
                        else
                        {
                            temp = root->hijo_izq;
                        }
                        root=NULL;
                    }

                    //Two Children
                    else
                    {
                        struct juguete *temp = find_minimum(root->hijo_der);
                        root->codigo = temp->codigo;
                        root->hijo_der = eliminarJug(root->hijo_der, temp->codigo);
                    }
                    printf("\nEl juguete fue eliminado de manera exitosa");
                    encontrado=1;
                }
                return root;
            }
    else
    {
        printf("\nError, el juguete no fue encontrado en el programa.\n\n");
    }
}
int obtener_cod(jug *root, char *juguete) //BUSCAR UN JUGUETE
{
	int dato;
	
    if (root!=NULL) 
	{ 
        /* If root is not NULL... */

        /* recursively process hijo_izq subtree if present.. */
        if (root->hijo_izq) 
        {
        	obtener_cod(root->hijo_izq, juguete);
		}
		
        /* then check the current node.. */
        if (strstr(root->nombre, juguete)) 
		{
            return (root->codigo);
        }

        /* then recursively process the hijo_der subtree if present. */
        if (root->hijo_der) 
        {
        	obtener_cod(root->hijo_der, juguete);
		}
    } 
	else
	{
		printf("No hay juguetes registrados");
	}
}

void Juguetes(jug *root)
{

	int opc=-1, min=-1, max=-1, costo=-1, cod=-1;
	char nombre[30], categoria[30], desc[100]; 
	
	while(opc!=5)
	{
	    printf("\n            ---JUGUETES---            ");
		printf("\n       1) Agregar juguete             ");
		printf("\n       2) Mostrar juguetes            ");
	    printf("\n       3) Modificar datos de juguete  ");
		printf("\n       4) Eliminar juguete            ");
	    printf("\n       5) Volver al menu principal    ");
	    
		printf("\n\nIngrese el numero de la funcion a revisar:  ");
	   	fflush(stdin);   
	   	if(scanf("%d",&opc)!=1)
    	{
			printf("Error en la opcion ingresada \n"); 
		}
		else
		{  
		    while(opc<0)
	        {
	            printf("\nIngrese nuevamente la opcion de la funcion a revisar: ");
	            fflush(stdin);
	            scanf("%d", &opc);
	        }
	
			if(opc==1)
			{
				printf("Ingrese el codigo: Juguete-0");
				scanf("%i", &cod);
				while(cod<0)
	            {
	                printf("\nError, ingrese nuevamente el codigo: Juguete-0");
	                fflush(stdin);
	                scanf("%i", &cod);
	            }
				
				printf("Ingrese el nombre del juguete: ");
				fflush(stdin); 
				scanf("%[^\n]",&nombre);
				
				printf("Categoria: ");
				fflush(stdin);
				scanf("%[^\n]", &categoria);
				
				printf("Descripcion del juguete: ");
				fflush(stdin);
				scanf("%[^\n]", &desc);
					
				printf("Ingrese el numero que corresponde a lo que se le solicita a continuacion\n");
				printf("Edad maxima recomendada para utilizar el juguete: ");
				scanf("%i", &max); 
				while(max<0)
	            {
	                printf("\nEdad maxima recomendada para utilizar el juguete (numero): ");
	                fflush(stdin);
	                scanf("%i", &max);
	            }
				printf("Edad minima recomendada para utilizar el juguete: ");
				scanf("%i", &min);
				while(min<0)
	            {
	                printf("\nEdad minima recomendada para utilizar el juguete (numero): ");
	                fflush(stdin);
	                scanf("%i", &min);
	            }
				while (min>max)
				{
					printf("Error, ingrese nuevamente la edad minima para utilizar el juguete: ");
					scanf("%i", &min);
					while(min<0)
		            {
		                printf("\nEdad minima recomendada para utilizar el juguete (numero): ");
		                fflush(stdin);
		                scanf("%i", &min);
		            }
				}
				
				printf("Costo total de fabricacion del juguete: $");
				scanf("%i", &costo);
				while(costo<0)
	            {
	                printf("\nError, ingrese nuevamente el costo de fabricacion del juguete: $");
	                fflush(stdin);
	                scanf("%i", &costo);
	            }
				 
				insertarJuguete(root, cod, nombre, desc, categoria, max, min, costo);
				printf("\nEl juguete se registro de manera exitosa\n");
			}
			else if(opc==2)
			{
				mostrarJuguetes(root);
			}
			else if(opc==3)
			{
				printf("Ingrese el nombre del juguete del cual desea modificar sus datos: ");
				fflush(stdin);
				scanf("%[^\n]", &nombre);
				modificarJug(root, nombre);
			}
			else if(opc==4)
			{
				printf("Ingrese el nombre del juguete: ");
				fflush(stdin);
				scanf("%[^\n]", &nombre);
				eliminarJug(root, obtener_cod(root, nombre));
			}
		}
	}
}
//************************************************************************************************************************************************************

/*------------------------------------STRUCT COMPORTAMIENTOS-----------------------------------
Estructura general de los comportamientos 
Entradas: nombrePadre, id_nino, fecha, descripcion; 
Salidas: un nuevo nodo en lista Simple 
Restricciones: Solo tiene puntero a siguiente */
typedef struct comportamientos
{
	char nombrePadre[30], cedu_nino[12], fecha[30], descripcion[100]; 
	int comportamientos_buenos, comportamientos_malos;
	struct comportamientos* sig_compor;
} comportamientos;

//Variables generales de primer y ultimo comportamiento
comportamientos* primer_compor=NULL;
comportamientos* ultimo_compor=NULL;

/*Entradas: variables para la creacion de un registro con los comportamientos 
Salidas: un nuevo nodo con los datos del nuevo comportamiento
Restricciones: solo funciona para comportamientos  */
int nuevoComportamiento(char *nombrePadre, char  *cedu_nino, char *fecha, char *descripcion, int conducta) //Funcion para insertar
{ 
	comportamientos *nuevo=(comportamientos*) malloc(sizeof(comportamientos));
	
	strcpy(nuevo->nombrePadre, nombrePadre);
	strcpy(nuevo->cedu_nino, cedu_nino);
    strcpy(nuevo->fecha, fecha);
    strcpy(nuevo->descripcion, descripcion);
    
	if (conducta == 1)
	{
		nuevo->comportamientos_buenos ++;
	}
	else
	{
		nuevo->comportamientos_malos ++;
	} 
    
	if(primer_compor==NULL)	
	{
		primer_compor=nuevo;
		primer_compor->sig_compor=NULL;
		ultimo_compor=nuevo;
	}
	ultimo_compor->sig_compor=nuevo;
	nuevo->sig_compor=NULL;
	ultimo_compor=nuevo;
}


/*Entradas: menu general de comportamientos
Salidas: todas las opciones de comportamientos
Restricciones: solo datos de comportamientos */
int comportamiento()
{
	//system("color 01");
	int opc, verificar, conducta;
	char  nombrePadre[30], cedu_nino[12], fecha[30], descripcion[100],temp_cedula[30]; 

	nino* actual=(nino*) malloc(sizeof(nino));
	actual=primer_Nino;
	
	printf("Ingrese el nombre del padre o madre del nino: ");
	fflush(stdin); //limpia buffer de espacios y saltos
	scanf("%[^\n]",&nombrePadre);

	
	printf("Ingrese la cedula del nino(a) (formato X-XXXX-XXXX): "); 
	fflush(stdin);
	scanf("%[^\n]", &temp_cedula);
	while (strlen(temp_cedula)!=11) //Comparar la cantidad de caracteres
	{
		printf("Digite nuevamente el id del nino(a), con el formato solicitado (X-XXXX-XXXX): ");
		fflush(stdin);
		scanf("%[^\n]", &temp_cedula);
	}
	while(actual!=NULL)
	{
		if (strcmp(actual->cedula , temp_cedula)==0)
		{ 
			verificar++;
		}
		actual = actual->sig_Nino;
	}
	if(verificar==0)
	{
		printf("\nOh! Parece que este nino(a) no esta registrado en el sistema \n");
	}
	else
	{	
		printf("Ingrese una descripcion del comportamiento del nino(a): ");
		fflush(stdin);
		scanf("%[^\n]", &descripcion);
		
		while (conducta != 1 && conducta != 2)
		{
			printf("Ingrese 1 si el comportamiento a registrar es *BUENO* o 2 si es *MALO*: ");
			fflush(stdin);
			if(scanf("%i", &conducta)!=1)
			{
                printf("\nSolo puede digitar 1 o 2.\n");
            }
		}
		
		if(verificar==1)
		{
			nuevoComportamiento(nombrePadre, cedu_nino, fecha, descripcion, conducta);
			int dia,mes,anio,fecha_F;
		    char diaSTR[3],mesSTR[3],anioSTR[3],fecha_C[30];
		    
		    time_t tiempo = time(0);
			struct tm *tlocal = localtime(&tiempo);
			
			strftime(mesSTR,3,"%m",tlocal);
			strftime(anioSTR,5,"%Y",tlocal);
			strftime(diaSTR,3,"%d",tlocal);
		
			dia=atoi(diaSTR);
			mes=atoi(mesSTR);
			anio=atoi(anioSTR);
			
			snprintf(fecha_C, sizeof fecha_C, "%s/%s/%s", diaSTR, mesSTR, anioSTR);
			printf("\nFecha del registro: %s \n",fecha_C);
			printf("\n**Muy bien! Se ha logrado registrar el comportamiento con exito!**\n");	
		}
	}
	
}


//------------------------------------STRUCT REGISTRO DE CARTAS-----------------------------------
//Estructura general de los ninos 
/*Entradas: Nivel de acceso, nombre, cedula, correo y demas datos de cada miembro
Salidas: un nuevo nodo en lista Simple 
Restricciones: Solo tiene puntero a siguiente */
typedef struct cartas
{
	char nombreNino[30], cedula[30];
	int anio;
	struct cartas* sig_carta;
} cartas;

//Variables generales de primer y ultimo miembro
cartas* primer_carta=NULL;
cartas* ultimo_carta=NULL;

/*Entradas: variables para la creacion de un registro con los miembros 
Salidas: un nuevo nodo con los datos del nuevo miembro
Restricciones: solo funciona para miembros  */
int nuevaCarta(char *cedula, char  *nombreNino, int anio) //Funcion para insertar
{
	cartas *nuevo=(cartas*) malloc(sizeof(cartas));
	
	strcpy(nuevo->nombreNino, nombreNino);
	strcpy(nuevo->cedula, cedula);
    nuevo->anio=anio; 

	if(primer_carta==NULL)	
	{
		primer_carta=nuevo;
		primer_carta->sig_carta=NULL;
		ultimo_carta=nuevo;
	}
	ultimo_carta->sig_carta=nuevo;
	nuevo->sig_carta=NULL;
	ultimo_carta=nuevo;
}

/*Entradas: menu general del miembros 
Salidas: todas las opciones de MIEMBROS
Restricciones: solo datos de miembros */

void buscarJug(jug *root, char *juguete) //BUSCAR UN JUGUETE
{
    if (root!=NULL) 
	{ 
        /* If root is not NULL... */

        /* recursively process hijo_izq subtree if present.. */
        if (root->hijo_izq) 
        {
        	buscarJug(root->hijo_izq, juguete);
		}
		
        /* then check the current node.. */
        if (strstr(root->nombre, juguete)) 
		{
            printf("\n\tJUG-0%d\n", root->codigo); // printing codigo at root
	        printf("\t(1)Nombre: %s\n", root->nombre);
	        printf("\t(2)Categoria: %s\n", root->categoria);
	        printf("\t(3)Descripcion: %s\n", root->desc);
	        printf("\t(4)Rango de edad recomendado: %d-%d\n", root->min, root->max);
        }

        /* then recursively process the hijo_der subtree if present. */
        if (root->hijo_der) 
        {
        	buscarJug(root->hijo_der, juguete);
		}
    } 
	else
	{
		printf("\nNo hay juguetes previamente registrados! :(");
	}
}


typedef struct jpedidos
{
	char cedula[30], list_juguetes[34], list_deseos[34], estado[20];
	int anio;
	struct jpedidos* sig;
} jpedidos;

jpedidos* primer=NULL;
jpedidos* ult=NULL;

int nuevoP(char *cedula,  char *list_juguetes,char *list_deseos, char *estado, int anio)
{
	jpedidos *nuevo=(jpedidos*) malloc(sizeof(jpedidos));
	
	strcpy(nuevo->cedula, cedula);
    strcpy(nuevo->list_juguetes, list_juguetes);
    strcpy(nuevo->list_deseos, list_deseos);
    strcpy(nuevo->estado, estado);
    nuevo->anio = anio;

	if(primer==NULL)	
	{
		primer=nuevo;
		primer->sig=NULL;
		ult=nuevo;
	}
	ult->sig=nuevo;
	nuevo->sig=NULL;
	ult=nuevo;
}

int crear_carta()
{
	int opc, verificar, anio, numJuguetes=0, desicion=0, desicion2=1;
	char  nombre[30], temp_cedula[30], id_nino[12],juguetes[14];

	while(opc!=4)
	{
	    printf("\n       ---Carta para Santa---          ");
		printf("\n       1) Agregar nueva carta          ");
		printf("\n       2) Editar una carta             ");
	    printf("\n       3) Consultar una carta          ");
	    printf("\n       4) Volver al menu principal     ");
	    
		printf("\n\nDigite el numero de la opcion a revisar:  ");
	    scanf("%d",&opc);
	
		if(opc==1)
		{
			nino* actual=(nino*) malloc(sizeof(nino));
			actual=primer_Nino;
				
			printf("Valide la cedula del nino(a) en el sistema (formato X-XXXX-XXXX): ");
			fflush(stdin);
			scanf("%[^\n]", &temp_cedula);
		 	while (strlen(temp_cedula)!=11) //Comparar la cantidad de caracteres
			{
				printf("Digite nuevamente el id del nino(a), con el formato solicitado (X-XXXX-XXXX): ");
				fflush(stdin);
				scanf("%[^\n]", &temp_cedula);	
			}	
			while(actual!=NULL)
			{
				if (strcmp(actual->cedula , temp_cedula)==0)
				{ 
					verificar++;
					strcpy(nombre, actual->nombre); 
				}
				actual = actual->sig_Nino;
			}
			if(verificar==0)
			{
				printf("\nOh! Parece que el nino no se ha registrado previamente\n");
			}
			else
			{
				printf("Ingrese el anio para el que corresponde la carta: ");//***********valir que no permita palabras
				scanf("%d",&anio);
				
				while(desicion2 == 1)
				{		
					printf("Ingrese el nombre del juguete que desea: ");
					fflush(stdin);
					scanf("%[^\n]", &juguetes);
					buscarJug(root, juguetes);
				 	
			    	while (desicion != 1 && desicion != 2)
					{
						printf("\n1- Agregar a la Carta para Santa \n2- Agregar a la lista de deseos \nDigite su opcion:  ");//***********valir que no permita palabras
						scanf("%d",&desicion);
					}
					if (desicion == 1)
					{
						if(numJuguetes <= 10)
						{
							nuevoP(temp_cedula,juguetes," ","Solicitado",anio);
							numJuguetes = numJuguetes+1;
							printf("-Cantidad de juguetes en la carta para Santa -%d- de 10.",numJuguetes);					
						}
						else
						{
							printf("Parece que ya tiene mas de 10 juguetes en la carta.");
						}
					}
					else 
					{
						nuevoP(temp_cedula," ",juguetes," Solicitado",anio);
						printf("\nAgregado a la lista de deseos.");
					}
					
					desicion2 = 0;
					while(desicion2 != 1 && desicion2 != 2)
					{
						printf("\n\nDesea agregar otro juguete: \n -1. Si \n -2. No \nDigite su opcion: ");//***********valir que no permita palabr
						scanf("%d",&desicion2);
					}
					desicion=0;
				}
				nuevaCarta(temp_cedula, nombre, anio);
				numJuguetes=0;	
			}
		}
		
		else if(opc==2)
		{
			modificar_carta();
		}
		else if(opc==3)
		{
			mostrar_carta();
		}
	}
}

//MODIFICAR DATOS 
/*Entradas: datos del struct
Salidas: imprime los datos del miembro en cuestion 
Restricciones: Solo miembros antes inscritos */
int modificar_carta() 
{
	char identificacion[12],juguetes[15];
	int anio,opc,numJuguetes,desicion,verificar=0;
	
	cartas* actual = (cartas*) malloc(sizeof(cartas)); // crea nodos 
	actual = primer_carta;
	
	jpedidos *jugue=(jpedidos*) malloc(sizeof(jpedidos));
	jugue= primer;
	
	if(primer_carta != NULL)
	{	
		printf("Digite la identificacion del nino(a) para editar su respectiva carta (X-XXXX-XXXX): "); 
		fflush(stdin);
		scanf("%[^\n]", &identificacion);
		while (strlen(identificacion)!=11) //Comparar la cantidad de caracteres
		{
			printf("Digite nuevamente el id del nino(a), con el formato solicitado (X-XXXX-XXXX): ");
			fflush(stdin);
			scanf("%[^\n]", &identificacion);	
		}	
		while(actual!=NULL)
		{
			if (strcmp(actual->cedula , identificacion)==0)
			{ 
				verificar++;
			}
			actual = actual->sig_carta;
		}
		if(verificar==0)
		{
			printf("\nOh! Parece que el nino no ha registrado cartas previamente\n");
			return;
		}
		actual = primer_carta;
		while(actual != NULL)
		{
			if( strcmp(identificacion, actual->cedula)==0)
			{
				printf("Ingrese el anio de la carta: ");
				fflush(stdin);   
	   			if(scanf("%d",&anio)!=1)
    			{
					printf("Error en la opcion ingresada \n"); 
				}
				else
				{
					verificar=0;
					actual = primer_carta;
					while(actual!=NULL)
					{
						if (actual->anio == anio)
						{ 
							verificar++;
						}
						actual = actual->sig_carta;
					}
					if(verificar==0)
					{
						printf("\nOh! Parece que el anio no ha registrado cartas previamente\n");
						return;
					}
				
					actual = primer_carta;
					while(actual != NULL)
					{
						if (anio == actual->anio)
						{
							printf("\t\n----Informacion de la Carta----\n");
							printf("\n  -Nombre del nino(a): %s\n  -Cedula: %s\n  -Anio del pedido: %d  ", actual->nombreNino, actual->cedula, actual->anio);
							printf("\n\n  -Juguetes pedidos en la Carta:");
							while(jugue != NULL)
							{
								if(strcmp(identificacion, jugue->cedula)==0)
								{
									if(strcmp(jugue->list_juguetes, " ")!=0){
										printf("\n\t\t ->%s (%s)", jugue->list_juguetes,jugue->estado);
									}
								}
								jugue = jugue->sig;
							}
							jugue = primer;
							printf("\n\n  -Juguetes en la Lista de Deseos:");
							while(jugue != NULL)
							{
								if(strcmp(identificacion, jugue->cedula)==0)
								{
									if(strcmp(jugue->list_deseos, " ")!=0){
										printf("\n\t\t ->%s", jugue->list_deseos);
									}
								}
								jugue = jugue->sig;
							}
						}
						actual = actual->sig_carta;	
					}	
				}
			}
			else actual= actual->sig_carta;  
		}
	}
	else
	{
		printf("\n Parece que no hay ninos con cartas registrados\n\n");
	}
	while (opc != 4) 
	{
		printf("\n                         ---Editar Carta---                            ");
		printf("\n      1) Agregar juguetes a la carta                                   ");
		printf("\n      2) Quitar juguetes de la carta                                   ");
	    printf("\n      3) Pasar un juguete de la lista de deseos a la carta para Santa  ");
	    printf("\n      4) Volver al menu principal                                      ");
	    
		printf("\n\nDigite el numero de la opcion a revisar:  ");
	    scanf("%d",&opc);
	    
		if (opc == 1)
		{
			printf("\nIngrese el nombre del juguete que desea: ");
			fflush(stdin);
			scanf("%[^\n]", &juguetes);
			//buscarJug(root, juguetes); // en la funcion poner si existe o no el juguete
			
			while (desicion != 1 && desicion != 2)
			{
				printf("\n1- Agregar a la Carta para Santa \n-2 Agregar a la lista de deseos \nDigite su opcion:  ");//***********valir que no permita palabras
				scanf("%d",&desicion);
			}
			if (desicion == 1)
			{
				if(numJuguetes <= 10)
				{
					nuevoP(identificacion,juguetes," ","Solicitado",anio);
					numJuguetes = numJuguetes+1;
				//	printf("\n-Cantidad de juguetes en la carta para Santa -%d- de 10.",numJuguetes);	hacer contador	
					printf("\nAgregado a la carta.");			
				}
				else
				{
					printf("Parece que ya tiene mas de 10 juguetes en la carta.");
				}
			}
			else 
			{
				nuevoP(identificacion," ",juguetes,"Solicitado",anio);
				printf("\nAgregado a la lista de deseos.");
			}
			desicion == 0;
		}
		else if (opc == 2)
		{
			printf("Ingrese el nombre del juguete que desea eliminar: ");
			fflush(stdin);
			scanf("%[^\n]", &juguetes);
			
			jugue = primer;
			while(jugue != NULL)
			{
				if(strcmp(juguetes, jugue->list_juguetes)==0)
				{
					free(jugue);
					break;
				}
				jugue = jugue->sig;
			}
			jugue = primer;
			while(jugue != NULL)
			{
				if(strcmp(juguetes, jugue->list_deseos)==0)
				{
					free(jugue);
					break;
				}
				jugue = jugue->sig;
			}
			printf("\n..Juguete eliminado.. ");
		}
		else if (opc == 3)
		{
			printf("Ingrese el nombre del juguete que desea pasar a la Carta: ");
			fflush(stdin);
			scanf("%[^\n]", &juguetes);
			
			jugue = primer;
			while(jugue != NULL)
			{
				if(strcmp(juguetes, jugue->list_deseos)==0)
				{
					free(jugue);
					break;
				}
				jugue = jugue->sig;
			}
			nuevoP(identificacion,juguetes," "," Solicitado",anio);
			printf("Ingresado a la carta para Santa ");
		}
	}
}

//MOSTRAR ************************************************************
/*Entradas: datos del struct
Salidas: imprime los datos del miembro en cuestion 
Restricciones: Solo miembros antes inscritos */

int mostrar_carta()//Imprime 
{
	char identificacion[12];
	int anio;
	
	cartas* actual = (cartas*) malloc(sizeof(cartas)); // crea nodos 
	actual = primer_carta;
	
	jpedidos *jugue=(jpedidos*) malloc(sizeof(jpedidos));
	jugue= primer;
	
	if(primer_carta != NULL)
	{	
		printf("Digite la identificacion del nino(a) para consultar su respectiva carta (X-XXXX-XXXX): "); // valiadar que esta en struct cartas
		fflush(stdin);
		scanf("%[^\n]", &identificacion);
		
		while(actual != NULL)
		{
			if( strcmp(identificacion, actual->cedula)==0)
			{	
				printf("Ingrese el anio de la carta: ");
				fflush(stdin);   
	   			if(scanf("%d",&anio)!=1)
    			{
					printf("Error en la opcion ingresada \n"); 
				}
				else
				{ 
					actual = primer_carta;
					while(actual != NULL)
					{
						if (anio == actual->anio)
						{
							printf("\t\n----Informacion de la Carta----\n");
							printf("\n  -Nombre del nino(a): %s\n  -Cedula: %s\n  -Anio del pedido: %d  ", actual->nombreNino, actual->cedula, actual->anio);
							
							printf("\n\n  -Juguetes pedidos en la Carta:");
							while(jugue != NULL)
							{
								if(strcmp(identificacion, jugue->cedula)==0)
								{
									if(strcmp(jugue->list_juguetes, " ")!=0){
										printf("\n\t\t ->%s (%s)", jugue->list_juguetes,jugue->estado);
									}
								}
								jugue = jugue->sig;
							}
							jugue = primer;
							printf("\n\n  -Juguetes en la Lista de Deseos:");
							while(jugue != NULL)
							{
								if(strcmp(identificacion, jugue->cedula)==0)
								{
									if(strcmp(jugue->list_deseos, " ")!=0){
										printf("\n\t\t ->%s", jugue->list_deseos);
									}
								}
								jugue = jugue->sig;
							}
							return;
						}
						else actual = actual->sig_carta;	
					}
				}
			}
			else actual= actual->sig_carta;  
		}
		printf("Parece que la cedula no ha registrado ninguna carta");
	}
	else
	{
		printf("\nUps! Parece que no hay ninos con cartas registrados\n\n");
	}
}

//------------------------------------STRUCT REGISTRO Procesar cartas para Santa -----------------------------------
//Estructura general de 
/*Entradas: Ni
Salidas: unmple 
Restricciones: S */

typedef struct procesar
{
	char ID_ayudante[30], ID_nino[30];
	int anio;
	struct procesar* sig_prog;
} procesar;

//Variables generales de primer y ultimo miembro
procesar* primer_prog=NULL;
procesar* ultimo_prog=NULL;

int nuevaProcesado(char *ID_ayudante, char  *ID_nino, int anio) //Funcion para insertar
{
	procesar *nuevo=(procesar*) malloc(sizeof(procesar));
	
	strcpy(nuevo->ID_ayudante, ID_ayudante);
	strcpy(nuevo->ID_nino, ID_nino);
    nuevo->anio=anio; 

	if(primer_prog==NULL)	
	{
		primer_prog=nuevo;
		primer_prog->sig_prog=NULL;
		ultimo_prog=nuevo;
	}
	ultimo_prog->sig_prog=nuevo;
	nuevo->sig_prog=NULL;
	ultimo_prog=nuevo;
}

void procesar_cartas()
{
	cartas *actual=(cartas*) malloc(sizeof(cartas)); // crea nodos 
	actual = primer_carta;
	
	jpedidos *jugue=(jpedidos*) malloc(sizeof(jpedidos));
	jugue= primer;
	
	char identificacion[14];
	int verificar=0, anio;	
	
	printf("Ingrese el anio para procesar sus respectivas cartas: ");
	fflush(stdin);   
	if(scanf("%d",&anio)!=1)
	{
		printf("Error en la opcion ingresada \n"); 
	}
	else
	{
		while(actual!=NULL)
		{
			if (actual->anio == anio)
			{
				verificar++;
			}
			actual = actual->sig_carta;
		}
		if(verificar==0)
		{
			printf("\nOh! Parece que el anio no ha registrado cartas previamente\n");
			return;
		}
	}
	
	printf("\t\n----Ninos que han registrado Carta este anio----\n");
	actual = primer_carta;
	while(actual!=NULL)
	{
		if (anio == actual->anio)
		{
			printf("\n  -Nombre del nino(a): %s\n  -Cedula: %s\n  -Anio de la carta: %d  ", actual->nombreNino, actual->cedula, actual->anio);
		}
		actual = actual->sig_carta;
	}
	printf("\n\nIngrese la identificacion del nino que desa procesar su carta: ");//*******validar
	fflush(stdin);
	scanf("%[^\n]", &identificacion);
	
	actual = primer_carta;
	while(actual != NULL)
	{
		if( strcmp(identificacion, actual->cedula)==0)
		{
			printf("\t\n----Informacion de la Carta----\n");
			printf("\n  -Nombre del nino(a): %s\n  -Cedula: %s\n  -Anio del pedido: %d  ", actual->nombreNino, actual->cedula, actual->anio);
			
			printf("\n\n  -Juguetes pedidos en la Carta:");
			while(jugue != NULL)
			{
				if(strcmp(identificacion, jugue->cedula)==0)
				{
					if(strcmp(jugue->list_juguetes, " ")!=0){
						printf("\n\t\t ->%s (%s)", jugue->list_juguetes,jugue->estado);
					}
				}
				jugue = jugue->sig;
			}
			jugue = primer;
			printf("\n\n  -Juguetes en la Lista de Deseos:");
			while(jugue != NULL)
			{
				if(strcmp(identificacion, jugue->cedula)==0)
				{
					if(strcmp(jugue->list_deseos, " ")!=0){
						printf("\n\t\t ->%s", jugue->list_deseos);
					}
				}
				jugue = jugue->sig;
			}
		}
		actual= actual->sig_carta;  
	}
	char id[12];
	int dato, encontrado=0;
	
	ayudante* actual_ayudante=(ayudante*) malloc(sizeof(ayudante)); // crea nodos
	actual_ayudante=primer_Ayudante;
	
	printf("\n\n --Registro para procesar la carta--\n");
	printf("Ingrese su identificacion como ayudante de Santa (X-XXXX-XXXX):");
	fflush(stdin);
	scanf("%[^\n]", &id);
	while (strlen(id)!=11) //Comparar la cantidad de caracteres
	{
		printf("Digite nuevamente el id del ayudante, con el formato solicitado (X-XXXX-XXXX): ");
		fflush(stdin);
		scanf("%[^\n]", &id);
	}	
	if(primer_Ayudante!=NULL)
	{
		while(actual_ayudante!=NULL && encontrado!=1)
		{
			if (strcmp(actual_ayudante->cedula, id)==0)
			{
				encontrado=1;
			}
			else
			{
				actual_ayudante=actual_ayudante->sig_Ayudante;// siguiente puntero en lista	
			}
			
		}
	}
	else
	{
		printf("\nUps! Parece que el ayudante que busca no esta registrado\n\n");
	}
	
	nuevaProcesado(identificacion, id, anio);
	
	jugue= primer;
	while(jugue != NULL)
	{
		if(strcmp(identificacion, jugue->cedula)==0)
		{
			if(jugue->anio == anio)
			{
				strcpy(jugue->estado,"Listo para entregar");
			}
		}
		jugue = jugue->sig;
	}
	printf("\n\n  -Juguetes pedidos en la Carta:");
	jugue = primer;
	while(jugue != NULL)
	{
		if(strcmp(identificacion, jugue->cedula)==0)
		{
			if(strcmp(jugue->list_juguetes, " ")!=0){
				printf("\n\t\t ->%s (%s)", jugue->list_juguetes,jugue->estado);
			}
		}
		jugue = jugue->sig;
	}
	printf("\n\nLa carta se ha procesado y los juguetes Listos para Entregar!\n");
}


//*****************Estadisticas**********************************
// para Estadisticas***


//Principal
int main (void)
{
	int opc;
	struct juguete *root;
    root=nuevoJuguete(10, "Mazo de cartas", "Juego clasico de cartas", "Juegos de mesa", 99, 7, 3);
	
	while (opc!=10)
	{
	    printf("\n                            ---MENU PRINCIPAL---                            ");
		printf("\n 1)  Registro de ninos(as)             -  6)  Carta a Santa                 ");
		printf("\n 2)  Registro de ayudantes de Santa    -  7)  Procesar cartas para Santa    ");
		printf("\n 3)  Registro de juguetes              -  8)  Entregar regalos              ");
		printf("\n 4)  Lugares de domicilio              -  9)  Analisis de datos             ");
		printf("\n 5)  Registro comportamiento de ninos  -  10) Finalizar programa            ");
	    
		printf("\n\nDigite el numero de la funcion a revisar:  ");  
		fflush(stdin);   
	   	if(scanf("%i",&opc)!=1)
    	{
			printf("Error en lo ingresado al programa.\n"); 
		}
		else
		{  
		    if (opc==1)
		    {
		    	Ninos();    	
			}
			else if(opc==2)
			{
				Ayudantes();
			}
			else if(opc==3)
			{
				Juguetes(root);
			}
			else if(opc==4)
			{
				//catalogo de lugares
			}
			else if(opc==5)
			{
				comportamiento();
			}
			else if(opc==6)
			{
				crear_carta();
			}
			else if(opc==7)
			{
				procesar_cartas();
			}
			else if(opc==8)
			{
				//entrega juguetes
		
			}
			else if(opc==9)
			{
			//	aniosP();
			//	cant_compotamientos();
			}
			else if(opc>11||opc<1)
			{
				printf("\n Error en el numero ingresado al programa.\n");
			}
		}
	}
	return 0;
	system("PAUSE");
}





