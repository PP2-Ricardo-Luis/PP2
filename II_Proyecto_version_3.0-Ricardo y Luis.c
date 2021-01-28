//SEGUNDO PROYECTO PROGRAMADO.
//Ricardo Ramírez Salas y Luis Torres.

//Librerias implementadas.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define Domicilio struct domicilio
#define Ruta struct ruta
#define ListaA struct pila

//------------------------------------STRUCT NIÑOS------------------------------------------------------------------------------------------------------------

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
int nuevoNino(char *cedula, char  *nombre, char *correo,char *necesidades, int dia, int mes, int anio, int edad, char *resi)
{ 
	nino *nuevo=(nino*) malloc(sizeof(nino));
	
	strcpy(nuevo->nombre, nombre);
	strcpy(nuevo->cedula, cedula);
    strcpy(nuevo->correo, correo);
    strcpy(nuevo->residencia, resi);
    strcpy(nuevo->necs, necesidades);
    nuevo->dia=dia;
    nuevo->mes=mes;
    nuevo->anio=anio;
	nuevo->edad=edad;

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
void mostrar_Ninos()//Imprime 
{
	nino* actual = (nino*) malloc(sizeof(nino)); // crea nodos 
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
	
	nino* actual = (nino*) malloc(sizeof(nino)); // crea nodos 
	actual = primer_Nino;
	
	printf("Ingrese el numero de identificacion del nino(a) que se requiere modificar los datos, usar formato (X-XXXX-XXXX): "); 
	fflush(stdin);
	scanf("%[^\n]", &id);
	while (strlen(id)!=11) //Comparar la cantidad de caracteres
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
			fflush(stdin); //limpia buffer de espacios y saltos
			scanf("%[^\n]",&actual->nombre);
		}
		else if (dato==2)
		{
			printf("Ingrese el numero de identificacion del nino(a) con el formato X-XXXX-XXXX: ");
			fflush(stdin);
			scanf("%[^\n]", &actual->cedula);
			while (strlen(actual->cedula)!=11) //Comparar la cantidad de caracteres
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
	char  nombre[30], correo[30], cedula[30], temp_cedula[30], neces[100], id_nino[12], diaSTR[3], mesSTR[3], anioSTR[5], resi[35]; 

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
				
				printf("Ingrese el lugar de residencia del nino(a): ");
				fflush(stdin);
				scanf("%[^\n]", &resi);
				
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
					nuevoNino(cedula, nombre, correo, neces, dia, mes, anio, edad, resi);
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


//------------------------------------STRUCT AYUDANTES------------------------------------------------------------------------------------------------------------


/*Entradas: El nivel de acceso, nombre del niño (a), numero de cedula, correo y otros datos mas.
Salidas: Presenta un nuevo nodo en una lista simple.
Restricciones: Solo presenta un puntero a siguiente */
typedef struct ayudante
{
	char nombre[30], cedula[30], puesto[30], funcs[100];
	int dia, mes, anio, cartasXAyud;
	struct ayudante* sig_Ayudante;
} ayudante;

//Variables generales de primer y ultimo miembro
ayudante* primer_Ayudante=NULL;
ayudante* ultimo_Ayudante=NULL;

//----------------------------------------------------------------------------------------------------------------------------------------------------------

/*Entradas: Las variables para la creacion de un registro con los ayudantes.
Salidas: Un nuevo nodo con los datos del nuevo ayudante
Restricciones: Esta funcionalidad solo es para los ayudantes.  */
int nuevoAyudante(char *cedula, char  *nombre, char *puesto,char *funcs, int dia, int mes, int anio) //Funcion para insertar
{ 
	ayudante *nuevo=(ayudante*) malloc(sizeof(ayudante));
	
	strcpy(nuevo->nombre, nombre);
	strcpy(nuevo->cedula, cedula);
    strcpy(nuevo->puesto, puesto);
    strcpy(nuevo->funcs, funcs);
    nuevo->dia=dia;
    nuevo->mes=mes;
    nuevo->anio=anio;
    nuevo->cartasXAyud=0;
    
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


//Mostrar toda la informacion de todos los ayudantes de santa
/*Entradas: Todos los datos que presenta el struct de ayudantes
Salidas: Muestra en pantalla todos los datos de los ayudantes que se encuentren registrados. 
Restricciones: Solo se mostraran los ayudantes que esten inscritos previamente. */
void mostrar_Ayudantes()//Imprime 
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
		}
	}
	else
	{
		printf("\n No hay ayudantes registrados en el programa.\n\n");
	}
}

///-----------------------------------------------------------------------------------------------------------------------------------------------------------

//Modificar los datos de un ayudante.
/*Entradas: Todos los datos que presenta el struct de ayudantes.
Salidas: Se modifican los datos que el usuario necesite. 
Restricciones: Solo se mostraran los ayudantes que esten inscritos previamente.*/
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
		printf("Desea modificar otro dato, digite 'Si', de lo contrario, digite 'No': ");
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
				
				printf("\nAyudante de Santa eliminado con exito");
				encontrado=1;
			}
			anterior=actual;
			actual=actual->sig_Ayudante;
		}
		if(encontrado==0)
		{
			printf("\nEl ayudante no fue encontrado\n\n");
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

//------------------------------------STRUCT JUGUETES--------------------------------------------------------------------------------------------------------
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


//----------------------------------------------------------------------------------------------------------------------------------------------------------

//Mostrar todos los juguetes.
/*Entradas: Todos los datos que presenta el struct de juguetes
Salidas: Muestra en pantalla todos los datos de los juguetes que se encuentren registrados. 
Restricciones: Solo se mostraran los juguetes que esten inscritos previamente. */
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
        
        mostrarJuguetes(root->hijo_der);// visiting hijo_der child
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

//Modificar los datos de los juguetes.
/*Entradas: Todos los datos que presenta el struct de juguetes.
Salidas: Se modifican los datos que el usuario necesite. 
Restricciones: Solo se mostraran los juguetes que esten inscritos previamente.*/
void modificarJug(jug *root, char *juguete) 
{
	int dato;
	char elecc[3]="Si";
	
    if (root!=NULL) 
	{ 

        if (root->hijo_izq) 
        {
        	modificarJug(root->hijo_izq, juguete);
		}

        if (strcmp(root->nombre, juguete)==0) 
		{
            printf("\n                    ---JUGUETES----          \n"                 );
            printf("\n     Juguete-0%d\n", root->codigo                                );
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

struct juguete* find_minimum(struct juguete *root)
{
    if(root == NULL)
    {
    	return NULL;
	}
    else if(root->hijo_izq != NULL)
    {
    	return find_minimum(root->hijo_izq); 
	}
    return root;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//Eliminar un juguete
/*Entradas: Todos los datos que presenta el struct de juguetes
  Salidas: El juguete quedará eliminado del programa.
  Restricciones:  Automaticamente no quedará ningún dato del juguete en el programa.*/
struct juguete* eliminarJug(struct juguete *root, int cod)
{
    int encontrado=0;

    if(root!=NULL)
    {

        if(root==NULL)
            return NULL;
        if (cod>root->codigo)
            root->hijo_der = eliminarJug(root->hijo_der, cod);
        else if(cod<root->codigo)
            root->hijo_izq = eliminarJug(root->hijo_izq, cod);
        else
        {
         
            if(root->hijo_izq==NULL && root->hijo_der==NULL)
            {
                root=NULL;
            }

       
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

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

//Buscar un juguete.
/*Entradas: Todos los datos que presenta el struct de juguetes
  Salidas: Se mostrara el juguete que el usuario ha realizado la busqueda.
  Restricciones:  Solo se mostraran los juguetes que previamente esten ingresadas al programa.*/
int obtener_cod(jug *root, char *juguete) 
{
	int dato;
	
    if (root!=NULL) 
	{ 

        if (root->hijo_izq) 
        {
        	obtener_cod(root->hijo_izq, juguete);
		}

        if (strstr(root->nombre, juguete)) 
		{
            return (root->codigo);
        }

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
//----------------------------------------------------------------------------------------------------------------------------------------------------------

//Menu principal de la estructura de los juguetes
/*Entradas: Los datos del struct de juguetes.
Salidas: Las diferentes funciones que presenta la estructura.
Restricciones: Solo se pueden realizar las funciones que presente el menu */
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
				fflush(stdin); //limpia buffer de espacios y saltos
				scanf("%[^\n]",&nombre);
				
				printf("Categoria: ");
				fflush(stdin);
				scanf("%[^\n]", &categoria);
				
				printf("Descripcion del juguete: ");
				fflush(stdin);
				scanf("%[^\n]", &desc);
					
				printf(">>Digite el numero que corresponde a lo que se le solicita a continuacion<<\n");
				printf("Edad maxima recomendada para utilizar el juguete: ");
				scanf("%i", &max); 
				while(max<0)
	            {
	                printf("\nEdad maxima recomendada para utilizar el juguete (numero): ");
	                fflush(stdin);
	                scanf("%i", &max);
	            }
			 	printf("\nEdad minima recomendada para utilizar el juguete (numero): ");
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

//----------------------------------------------------------DOMICILIO--------------------------------------------------------------------------------------------------------
//GRAFO CON LISTA DE ADYACENCIA

Domicilio 
{
	char nombre [35];
	int codigo, postal;
	
	Domicilio*siguiente;
	Ruta*adyacencia;
	
	//ANALISIS
	int contador;
	//Algoritmos DJISK
	int visitado, terminado, monto;
	char anterior [35];		
};

Ruta
{
	char origen [35], destino [35], tipo_ruta [35];
	float tiempo;
	int distancia;
	Domicilio*vrt;
	Ruta*siguiente;
};

ListaA
{
	Domicilio* nombre;
	ListaA*siguiente;
};

Domicilio*inicio = NULL;
ListaA*ini=NULL;
ListaA*final=NULL; 

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

//Crear nodo del domicilio.
/*Entradas: No presenta entradas.
  Salidas: Se inserta la ubicacion al sistema.
  Restricciones: No posee restricciones.*/	

int insertarUbicacion (void)
{
	char nombre [35];
	int codigo, postal;
	Domicilio*aux, *aux2, *aux3;
	Domicilio* nuevo = (Domicilio*)malloc(sizeof(Domicilio));
	aux2 = inicio;
	aux = inicio;
	aux3 = inicio;
	
	//DATOS DEL LUGAR PARA CATALOGO
	printf("Codigo de la ubicacion: Ubicacion-0");
	scanf("%d",&codigo);
	
	while(aux2 != NULL)
	{
		if (aux2 -> codigo == codigo)
		{	
			printf("El codigo ya ha sido registrado anteriormente, ingrese  nuevamente: Ubicacion-0");
			scanf("%d",&codigo);
		}
		aux2 = aux2 -> siguiente;
	}
	
	
	printf("Nombre de la ubicacion: ");
	fflush (stdin);
	gets (nombre);
	while(aux3 != NULL)
	{
		if (strcmp(aux3-> nombre, nombre)==0)
		{	
			printf("El lugar ya ha sido registrado anteriormente, ingrese un nombre distinto: ");
			fflush (stdin);
			gets (nombre);
			
		}
		aux3 = aux3 -> siguiente;
	}
		
	printf("Codigo postal: ");
	scanf("%d",&postal);
	
	while(aux != NULL)
	{
		if (aux -> postal == postal)
		{
			
			printf("El codigo ya ha sido registrado previamente, ingrese nuevamente: ");
			scanf("%d",&postal);
		}
		aux = aux -> siguiente;
	}
	
	nuevo -> codigo = codigo;
	nuevo -> postal = postal;
	strcpy(nuevo-> nombre, nombre);
	nuevo -> siguiente = NULL;
	nuevo -> adyacencia = NULL;
	nuevo -> contador = 0;
	nuevo->visitado= nuevo->terminado=0;
    nuevo->monto=-1;
    strcpy(nuevo->anterior, "0");
	
	if (inicio==NULL)
	{
		inicio = nuevo;
	}
	
	else
	{
		aux = inicio;
		while (aux -> siguiente != NULL)
		{
			aux = aux -> siguiente;
		}
		aux -> siguiente = nuevo;
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

//Insertar polo norte.
/*Entradas: El nombre, el codigo postal.
  Salidas: Se agrega al programa
  Restricciones: No posee restricciones.*/	
void insertarPoloNorte (char nombre [35],int codigo,int postal)
{

	Domicilio*aux;
	Domicilio* nuevo = (Domicilio*)malloc(sizeof(Domicilio));
	aux = inicio;
	while(aux != NULL)
	{
		aux = aux -> siguiente;
	}
	nuevo -> codigo = codigo;
	nuevo -> postal = postal;
	strcpy(nuevo-> nombre, nombre);
	nuevo -> siguiente = NULL;
	nuevo -> adyacencia = NULL;
	nuevo -> contador = 0;
	
	//ALGORITMO RECORRIDOS
	nuevo->visitado=nuevo->terminado=0;
    nuevo->monto=-1;
    strcpy(nuevo->anterior, "0");
	
	if (inicio==NULL)
	{
		inicio = nuevo;
	}
	
	else
	{
		aux = inicio;
		while (aux -> siguiente != NULL)
		{
			aux = aux -> siguiente;
		}
		aux -> siguiente = nuevo;
	}
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//Crear conexion de rutas con domicilios.
/*Entradas: Todos los datos del sruct de domicilios
  Salidas: Se agrega la ruta al programa.
  Restricciones: No posee restricciones.*/	

void agregarRuta(Domicilio*aux, Domicilio*aux2, Ruta*nuevo,char ini [35],char fin [35],float distancia, float tiempo, char tipo_ruta [35])
{
	Ruta*a;

	
	if(aux-> adyacencia == NULL)
	{
	
		aux-> adyacencia = nuevo;
		nuevo -> vrt = aux2;
		nuevo -> tiempo = tiempo;
		nuevo -> distancia = distancia;
		strcpy(nuevo->tipo_ruta,tipo_ruta);
		strcpy(nuevo->origen,ini);
		strcpy(nuevo->destino,fin);
	}
	
	else
	{
		a = aux -> adyacencia;
		
		while(a -> siguiente != NULL)
		{
		
			if(strcmp(a->origen,ini)==0 && strcmp(a->destino,fin)==0)
			{
				printf("\nLa ruta ya ha sido registrada previamente");
				return;
			}
			
			a = a -> siguiente;
		}
		
		if(strcmp(a->origen,ini)==0 && strcmp(a->destino,fin)==0)
		{
			printf("\nLa ruta ya ha sido registrada previamente\n");
			return;
		}
		
		nuevo -> vrt = aux2;
		nuevo -> tiempo = tiempo;
		nuevo -> distancia = distancia;
		strcpy(nuevo->tipo_ruta,tipo_ruta);
		strcpy(nuevo->origen,ini);
		strcpy(nuevo->destino,fin);
		a -> siguiente =  nuevo;		
	}
				
}


//----------------------------------------------------------------------------------------------------------------------------------------------------------

//Insertar auxiliar de rutas.
/*Entradas: No posee entradas.
  Salidas: Se inserta  auxiliar de rutas del programa.
  Restricciones: No posee restricciones.*/	

void insertarRuta()
{
	char ini[35], fin[35], tipo_ruta [35];
	float tiempo; 
	int distancia, tipo;
	Ruta*nuevo = (Ruta*)malloc(sizeof(Ruta));
	nuevo -> siguiente = NULL;
	Domicilio *aux2, *aux, *aux3; 
	Ruta * a;
	
	if (inicio==NULL)
	{
		printf("\n\nNo se ha registrado ninguna ubicacion\n");
		return;
	}
	
	printf("Ingrese la ubicacion de origen: ");
	fflush (stdin);
	gets (ini);
	
	printf("Ingrese la ubicacion de destino: ");
	fflush (stdin);
	gets (fin);
	
	aux = inicio;
	aux2 = inicio;

	while(aux2 != NULL)
	{
		if ( strcmp(fin,aux2 ->nombre) == 0)
		{
			break;
		}
		aux2 = aux2 -> siguiente;
	}
				
	if (aux2 == NULL)
	{
		printf("\n\nNo se encontro la ubicacion\n");
		return;
	}
	
	while(aux != NULL)
	{
		if(strcmp(ini,aux ->nombre)== 0)
		{
			printf("Distancia entre ubicaciones (kilometros): ");
			scanf("%d", &distancia);
			
			printf("Tiempo aproximado entre ambos puntos (horas):");
			scanf("%f", &tiempo);
			
			printf("\n Tipo de ruta");
			printf("\n  1) Terrestre.");
			printf("\n  2) Aerea.");
			printf("\n  3) Maritima.");
			printf("\n Ingrese el numero correspondiente al tipo de ruta utilizada para conectar las ubicaciones: ");
			scanf("%d", &tipo);
			
			if(tipo==1)
			{
				strcpy(tipo_ruta, "Terrestre");
			}
			
			else if(tipo==2)
			{
				strcpy(tipo_ruta, "Aerea");
			}
			
			else if(tipo==3)
			{
				strcpy(tipo_ruta, "Maritima");
			}
			
			else
			{
				printf("\nLa opcion digitada es invalida");
				return;
			}
			
			agregarRuta(aux, aux2, nuevo,ini,fin,distancia,tiempo, tipo_ruta);
			printf("\nSe creo una nueva ruta exitosamente");
			return;
		}
		
		aux = aux -> siguiente;
	}
	
	if(aux == NULL)
	{
		printf("\n\nNo se encontro el domicilio en cuestion\n");
	}

}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

//Modificar la ruta auxiliar.
/*Entradas: El inicio, el final, la distancia, el tiempo y el tipo de ruta
  Salidas: Se modifica la ruta del auxiliar
  Restricciones: No posee restricciones.*/	
void modificarRuta(char ini[35],char fin [35], float distancia, float tiempo, char tipo_ruta[35])
{
	int x=0;
	Ruta*nuevo = (Ruta*)malloc(sizeof(Ruta));
	Domicilio *aux2, *aux;
	
	if (inicio==NULL)
	{
		printf("\n\nNo se ha registrado ninguna ubicacion\n");
		return;
	}
	
	aux = inicio;
	aux2 = inicio;
	
	while(aux2 != NULL)
	{
		if ( strcmp(fin,aux2 ->nombre) == 0)
		{
			break;
		}
		aux2 = aux2 -> siguiente;
	}
				
	if (aux2 == NULL)
	{
		printf("\n\nNo se encontro el domicilio \n");
		return;
	}
	
	while(aux != NULL)
	{
		if(strcmp(ini,aux ->nombre)== 0)
		{
			agregarRuta(aux, aux2, nuevo,ini,fin,distancia,tiempo, tipo_ruta);
			printf("\nRuta: %s->%s", aux-> nombre, aux2 -> nombre);
			x =1;
			return;   
		}
		aux = aux -> siguiente;
	}
	
	if(x == 0)
	{
		printf("\n\nNo se encontro el domicilio \n");
	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------------

//Modificar lugar de domicilio
/*Entradas: No posee entradas.
  Salidas:  Se modifica el domicilio
  Restricciones: No posee restricciones.*/	
void modificarDomicilio()
{
	char domicilio [35], nombre[35];
	int i, codigo, postal;
	Domicilio* aux = inicio;

	if (inicio==NULL)
	{
		printf("\n\nNo se ha registrado ningun domicilio\n");
		return;
	}
	
	printf("Ingrese el nombre de la ubicacion a modificar: ");
	fflush (stdin);
	gets (domicilio);
	
	while(aux != NULL)
	{
		if(strcmp(domicilio,aux ->nombre)== 0)
		{
			printf("\n 1) Codigo");
			printf("\n 2) Nombre");
			printf("\n 3) Codigo postal");
			printf("\nIngrese el numero correspondiente al dato a modificar: ");
			scanf("%d", &i);
			
			while (i>3 || i<1)
			{
				printf("\n La opcion ingrese fue incorrecta, intente de nuevo. ");
				scanf("%d", &i);	
			}
			
			if(i == 1)
			{
				Domicilio* aux2 = inicio;
				printf("\nNuevo codigo: ");
				scanf("%d", &codigo);
				
				while(aux2 != NULL)
				{
					if (aux2 -> codigo == codigo)
					{
						printf("\nEse codigo ha sido registrado enteriormente");
						return;
					}
					
					aux2 = aux2 -> siguiente;
				}
				
				aux -> codigo = codigo;
				printf("\n  Se ha modificado los datos de manera exitosa! \n");
				printf("\n  Ubicacion-0%d", aux -> codigo);
				printf("\n  Nombre: %s", aux -> nombre);
				printf("\n  Codigo postal: %d", aux -> postal);
				return;		
			}
			
			if(i==2)
			{
				Domicilio* aux2 = inicio;
				printf("\n Nuevo nombre: ");
				fflush (stdin);
				gets (nombre);
				
				while(aux2 != NULL)
				{
					if (strcmp(aux2 -> nombre, nombre)==0)
					{
						printf("\n Este nombre ya ha sido registrado previamente.");
						return;
					}
					
					aux2 = aux2 -> siguiente;
				}
				
				strcpy(aux->nombre,nombre);
				printf("\n  Se ha modificado los datos de manera exitosa\n");
				printf("\n  Ubicacion-0%d", aux -> codigo);
				printf("\n  Nombre: %s", aux -> nombre);
				printf("\n  Codigo postal: %d", aux -> postal);
				return;				
			}
			
			if(i==3)
			{
				Domicilio* aux2  = inicio;
				printf("\nNuevo codigo postal: ");
				scanf("%d", &postal);
				
				while(aux2 != NULL)
				{
					if (aux2 -> postal == postal)
					{
						printf("\n Ese codigo ha sido registrado enteriormente");
						return;
					}
					
					aux2 = aux2 -> siguiente;
				}
				
				aux -> postal = postal;
				printf("\n  Se ha modificado los datos de manera exitosa\n");
				printf("\n  Ubicacion-0%d", aux -> codigo);
				printf("\n  Nombre: %s", aux -> nombre);
				printf("\n  Codigo postal: %d", aux -> postal);
				return;		
			}		
		}
		
		aux = aux -> siguiente;			
	}	
	
	if (aux == NULL)
	{
		printf("\n\nNo se encontro la ubicacion deseada");
		return;
	}
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------

//Eliminar arista auxiliar
/*Entradas: El inicio y el final
  Salidas: Se elimna la arista auxiliar del programa
  Restricciones: No posee restricciones.*/	
void eliminarAristaAux(char ini [35], char fin[35])
{
	Domicilio * aux, *aux2, *aux3;
	Ruta * q, *r ,*a;
	aux = inicio;
	aux2 = inicio;
	aux3 = inicio;
	int y =0;
	a = aux3 -> adyacencia;
		
	while(a != NULL)
	{
		if(strcmp(a->origen,ini)==0 && strcmp(a->destino,fin)==0)
		{
			y=1;		
		}
		
		a = a -> siguiente;
	}
		
	if(y ==1)
	{	
		while(aux2 != NULL)
		{
			if(strcmp(aux2 -> nombre,fin)==0)
			{
				break;
			}
			else
			{
				aux2 = aux -> siguiente;
			}	
		}
		
		while(aux != NULL)
		{
			if(strcmp(aux -> nombre,ini)==0)
			{
				q = aux -> adyacencia;
				
				while(q!=NULL)
				{
					if(q -> vrt ==aux2)
					{
						if(q== aux -> adyacencia)
						{
							aux -> adyacencia = aux -> adyacencia -> siguiente;
						}
						else
						{
							r -> siguiente = q -> siguiente;
						}
						
						free(q);
						printf("\nRuta: %s->%s se ha eliminado", aux-> nombre, aux2 -> nombre);
						return;	
					}
				}
				
				r = q;
				q = q = q-> siguiente;		
			}
			
			aux = aux -> siguiente;
		}
	} 
	
	else
	{
		printf("\nNo se encontro la ruta deseada");
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------

//Eliminar nodo.
/*Entradas: El domicilio
  Salidas: Se vacia  la arista del programa
  Restricciones: No posee restricciones*/	

void vaciar_aristas(Domicilio*aux)
{
	Ruta * q, *r;
	q = aux -> adyacencia;
	while(q -> siguiente != NULL)
	{
		r=q;
		q = q->siguiente;
		free(r);
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------

//Contador para el domilicio.
/*Entradas: El domicilio
  Salidas: Se realiza un contador del domicilio.
  Restricciones: No tiene restricciones.*/	
void contadorDomicilio (char dom [35],int cant)
{
	Domicilio* aux = inicio;
	while(aux != NULL)
	{
		if (strcmp(dom, aux -> nombre)==0)
		{
			aux -> contador = aux -> contador + cant;
	   }
		aux = aux -> siguiente;
   } 
}
		
		
//---------------------------------------------------------------------------------------------------------------------------------------------------------

//Borrar domilicio.
/*Entradas: No posee entradas
  Salidas: Se borra el domicilio del programa
  Restricciones: Si la ubicacion no existe envia un error.*/	
void borrarDomicilio()
{
	char domicilio [35];
	Domicilio* aux = inicio;
	Domicilio * ant;
	
	if (inicio==NULL)
	{
		printf("\nError, no se ha registrado ningun domicilio\n");
		return;
	}
	
	printf("Ingrese el nombre de la ubicacion a modificar: ");
	fflush (stdin);
	gets (domicilio);
	
	while(aux != NULL)
	{
		if(strcmp(domicilio,aux->nombre)==0)
		{
			if(aux -> adyacencia != NULL)
			{
				vaciar_aristas(aux);
			}
			
			if(aux == inicio)
			{
				inicio = inicio -> siguiente;
				free(aux);
				printf("\nUbicacion eliminada");
				return;	
			}
			
			else
			{
				ant -> siguiente = aux -> siguiente;
				free(aux);
				printf("\nUbicacion eliminada");
				return;	
			}
		}
		
		else
		{
			ant = aux;
			aux = aux -> siguiente;
		}
	}
	
	if(aux == NULL)
	{
		printf("\nNo se encontro la ubicacion deseada");
	}
}

	
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//Eliminar arista auxiliar.
/*Entradas: No posee entradas
  Salidas: Se realizo la eliminacion del auxiliar de la arista.
  Restricciones: No posse restricciones.*/
void eliminarArista()
{
	int x = 0, y = 0;
	char ini [35], fin [35];
	Domicilio * aux, *aux2, *aux3;
	Ruta * q, *r, *a;
	printf("\nIngrese la ubicacion inicial:");
	fflush (stdin);
	gets (ini);
	
	printf("\nIngrese la ubicacion de destino:");
	fflush (stdin);
	gets (fin);
	
	aux = inicio;
	aux2 = inicio;
	aux3 = inicio;
	a = aux3 -> adyacencia;
		
	while(a != NULL)
	{
	
	
		if(strcmp(a->origen,ini)==0 && strcmp(a->destino,fin)==0)
		{
			y=1;	
		}
		
		a = a -> siguiente;
	}
	
	if(y==1)
	{
		while(aux2 != NULL)
		{
			if(strcmp(aux2 -> nombre,fin)==0)
			{
				break;
			}
			else
			{
				aux2 = aux2 -> siguiente;
			}	
		}
		
		while(aux != NULL)
		{
			if(strcmp(aux -> nombre,ini) == 0 && aux2 != NULL)
			{
				q = aux -> adyacencia;
				while(q!=NULL)
				{
					if(q -> vrt ==aux2)
					{
						if(q== aux -> adyacencia)
						{
							aux -> adyacencia = aux -> adyacencia -> siguiente;
						}
						else
						{
							r -> siguiente = q -> siguiente;
						}
						
						free(q);
						x = 1;
						printf("\nRuta: %s->%s ha sido eliminada", aux-> nombre, aux2 -> nombre);
						return;	
					}
				}
				
				r = q;
				q = q = q-> siguiente;		
			}
			
			aux = aux -> siguiente;
		}
	}
		
	if(x==0)
	{
		printf("No se encontro la ruta deseada");
	}
	
	else
	{
		printf("No se encontro la ruta deseada");	
	}	
}


//----------------------------------------------------------------------------------------------------------------------------------------------------------

//Modificar auxiliar.
/*Entradas: El inicio, el final, la distancia, el tiempo y el tipo de ruta.
  Salidas: Se realizo la modificacion del auxiliar
  Restricciones: Solo se realizaran las funciones que se muestran al menu.*/
modificar_ruta_aux(char ini[35], char fin[35], int distancia, float tiempo, char tipo_ruta [35])
{
	int opc;
	while (opc!=6)
	{
		printf("\n  ---MODIFICAR RUTA----\n ");
		printf("\n 1) Punto de origen        ");
		printf("\n 2) Punto de llegada       ");
		printf("\n 3) Tiempo de la ruta      ");
		printf("\n 4) Distancia de la ruta   ");
		printf("\n 5) Tipo de ruta           ");
		printf("\n 6) Finalizar modificacion ");
		printf("\n Ingrese el numero correspondiente al dato que desea modificar: ");
		scanf("%d",&opc);
		
		if (opc==1)
		{
			printf("Escriba el nuevo punto de origen: ");
			fflush (stdin);
			gets (ini);
			break;
		}
		else if (opc==2)
		{
			printf("Escriba el nuevo punto de llegada: ");
			fflush (stdin);
			gets (fin);
			break;
		}
		else if (opc==3)
		{
			printf("Escriba el nuevo tiempo de la ruta:");
			scanf("%f",&tiempo);
			break;	
		}
		else if (opc==4)
		{
			printf("Escriba la nueva distancia:");
			scanf("%d",&distancia);
			break;
		}
		else if (opc==5)
		{
			printf("Escriba el nuevo tipo de ruta:");
			fflush (stdin);
			gets (tipo_ruta);
			break;	
		}
	}	
	modificarRuta(ini,fin,distancia, tiempo,tipo_ruta);	
}

//Modificar Arista.
/*Entradas: No posee entradas
  Salidas: Se realizo la modificacion de la arista
  Restricciones: No posse restricciones.*/
modificarArista()
{
	char ini [35], fin [35], tipo_ruta[35];
	float tiempo;
	int distancia, x=0;
	Domicilio * aux, *aux2;
	Ruta * q, *r;

	printf("\nIngrese la ubicacion de origen: ");
	fflush (stdin);
	gets (ini);
	
	printf("\nIngrese la ubicacion de destino: ");
	fflush (stdin);
	gets (fin);

	aux = inicio;
	aux2 = inicio;

	while(aux2 != NULL)
	{
		if(strcmp(aux2 -> nombre,fin)==0)
		{
			break;
		}
		
		else
		{
			aux2 = aux2 -> siguiente;
		}	
	}

	while(aux != NULL)
	{
	
		if(strcmp(aux -> nombre,ini )==0 && aux2 !=NULL)
		{
			q = aux -> adyacencia;
			while(q!=NULL)
			{
				if(q -> vrt ==aux2)
				{
					if(q== aux -> adyacencia)
					{
						aux -> adyacencia = aux -> adyacencia -> siguiente;
					}
					
					else
					{
						r -> siguiente = q -> siguiente;
					}
					
					x=1;
					tiempo = q -> tiempo;
					distancia = q -> distancia;
					strcpy(q-> tipo_ruta,tipo_ruta);
					free(q);
					
					modificar_ruta_aux(ini, fin, distancia, tiempo, tipo_ruta);		
				}
			}
			
			r = q;
			q = q = q-> siguiente;		
		}
		
		aux = aux -> siguiente;
	}
	
	if(x==0)
	{
		printf("No se encontro la ruta descrita");
	}
}


//Mostrar grafo.
/*Entradas: No presenta entradas.
  Salidas: Se muestra el grafo.
  Restricciones: No presenta restricciones. */
void mostrarGrafo()
{
    Domicilio*aux=inicio;
    Ruta* ar;
    printf("\n\tRutas registradas\n");
    while(aux!=NULL)
	{   
	    printf("%s:",aux->nombre);
        if(aux->adyacencia!=NULL)
		{
            ar=aux->adyacencia;
            while(ar!=NULL)
			{ 
			    printf("->%s",ar->vrt->nombre);
                ar=ar->siguiente;
            }
        }
        
        printf("\n");
        aux=aux->siguiente;
    }
    
    printf("\n");
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//Menu principal de la estructura de los domilicios
/*Entradas: No posee entradas.
Salidas: Las diferentes funciones que presenta la estructura.
Restricciones: Solo se pueden realizar las funciones que presente el menu */
int Domicilios()
{
	
	int opc, domicilios, d;;
	insertarPoloNorte ("Polo Norte", 000, 28850);

	while (opc!=5)
	{
		printf("\n         ---DOMICILIOS---       ");
		printf("\n  1) Agregar domicilios         ");
		printf("\n  2) Gestionar domicilio        ");
	    printf("\n  3) Agregar ruta               ");
	    printf("\n  4) Gestionar ruta             ");
		printf("\n  5) Volver al menu principal   ");
		printf("\n\n Ingrese el numero de la funcion a revisar:  ");
	    fflush(stdin);   
	   	if(scanf("%d",&opc)!=1)
    	{
			printf("Error, la opcion ingresa fue incorrecta. \n"); 
		}
		else
		{  
	    
			if (opc==1)
			{
				printf("Ingrese la cantidad de domicilios a registar: ");
				scanf("%d",&domicilios);
				
				for(d=0; d<domicilios; d++)
				{
					printf("\n\n Ubicacion #%d\n", d+1 );
					insertarUbicacion ();								
				}
			}
			
			else if (opc==2)
			{
				int opc;
				printf("\n 1) Modificar datos domicilio.");
				printf("\n 2) Eliminar domicilio.");
				printf("\n Ingrese el numero correspondiente a la accion que desea realizar: ");
				fflush(stdin);   
	   			if(scanf("%d",&opc)!=1)
		    	{
					printf("Error, la opcion ingresa fue incorrecta. \n"); 
				}
				else
				{  
					if(opc>0 && opc<3)
					{
						if (opc==1)
						{
							modificarDomicilio();
						}
						
						if (opc==2)
						{
							borrarDomicilio();
						}
					}
					
					else
					{
						printf("La opcion digitada es invalida");
						return;
					}	
				}
			}
			
			else if (opc==3)
			{
				insertarRuta();
			}
		
			else if (opc==4)
			{
				int opc;
				mostrarGrafo();
				
				printf("\n 1) Modificar ruta.");
				printf("\n 2) Eliminar ruta.");
				printf("\n  Ingrese el numero correspondiente a la accion que desea realizar: ");
				fflush(stdin);   
	   			if(scanf("%d",&opc)!=1)
		    	{
					printf("Error, la opcion ingresa fue incorrecta. \n"); 
				}
				else
				{  
					if(opc>0 && opc<3)
					{
						if (opc ==1)
						{
							modificarArista();
						}
						if(opc ==2)
						{
							eliminarArista();
						}
					}
					else
					{
						printf("La opcion digitada es invalida");
						return;
					}	
				}
			}
		}
	}
	return 0;
}
//*******************************************************************************************************************************************************************


/*------------------------------------STRUCT COMPORTAMIENTOS--------------------------------------------------------------------------------------------------

Entradas: El nombre del padre, el numero de identificacion del niño(a), fecha y la descripción. 
Salidas: Un nuevo nodo en lista Simple 
Restricciones: Solo presenta un puntero a siguiente */
typedef struct comportamientos
{
	char nombrePadre[30], cedu_nino[12], fecha[30], descripcion[100]; 
	int comportamientos_buenos, comportamientos_malos;
	struct comportamientos* sig_compor;
} comportamientos;

//Variables generales de primer y ultimo comportamiento
comportamientos* primer_compor=NULL;
comportamientos* ultimo_compor=NULL;

//------------------------------------------------------------------------------------------------------------------------------------------------------------

//Insertar comportamiento.
/*Entradas: Las variables para la creacion de un registro con los comportamientos 
Salidas: Un nuevo nodo con los datos del nuevo comportamiento
Restricciones: Esta funcion solo tiene funcionalidad para comportamientos  */
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


//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//Menu principal de la estructura de los comportamientos
/*Entradas: No posee entradas.
Salidas: Las diferentes funciones que presenta la estructura.
Restricciones: Solo se pueden realizar las funciones que presente el menu */
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
	while (strlen(temp_cedula)!=11) 
	{
		printf("Error, ingrese nuevamente el numero de identificacion del nino(a), con el formato solicitado (X-XXXX-XXXX): ");
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
		printf("\nError, el nino(a) no se encuentra registrado en el programa. \n");
	}
	else
	{	
		printf("Ingrese una descripcion del comportamiento del nino(a): ");
		fflush(stdin);
		scanf("%[^\n]", &descripcion);
		
		while (conducta != 1 && conducta != 2)
		{
			printf("Ingrese 1 si el comportamiento a registrar es ---Bueno--- o 2 si es ---Malo---: ");
			fflush(stdin);
			if(scanf("%i", &conducta)!=1)
			{
                printf("\nError en el numero ingresado, intente de nuevo.\n");
            
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
			printf("\nEl comportamiento del nino(a) se ha registrado de manera exitosa.\n");
		}
	}
	
}


//------------------------------------STRUCT REGISTRO DE CARTAS-----------------------------------
/*Entradas: El nombre del niño(a) y el numero de identificacion.
Salidas: Un nuevo nodo en lista Simple 
Restricciones: Solo presenta un puntero a siguiente */
typedef struct cartas
{
	char nombreNino[30], cedula[30];
	int anio;
	struct cartas* sig_carta;
} cartas;

//Variables generales de primer y ultimo carta
cartas* primer_carta=NULL;
cartas* ultimo_carta=NULL;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Insertar cartas.
/*Entradas: Las variables para la creacion de un registro con las cartas 
Salidas: Un nuevo nodo con los datos de la nueva carta
Restricciones: Esta funcion solo tiene funcionalidad para las cartas  */
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

//----------------------------------------------------------------------------------------------------------------------------------------------------------

//Buscar juguete
/*Entradas: Todos los datos que presenta el struct de juguetes
  Salidas: Se mostrara el juguete que el usuario ha realizado la busqueda.
  Restricciones:  Solo se mostraran los juguetes que previamente esten ingresadas al programa.*/

void buscarJug(jug *root, char *juguete) 
{
    if (root!=NULL) 
	{ 
        
        if (root->hijo_izq) 
        {
        	buscarJug(root->hijo_izq, juguete);
		}

        if (strcmp(root->nombre, juguete)==0) 
		{
            printf("\n                    ---JUGUETES----          \n"                 );
            printf("\n     Juguete-0%d\n", root->codigo                                );
	        printf("\n  1) Nombre: %s\n", root->nombre                                 );
	        printf("\n  2) Categoria: %s\n", root->categoria                           );
	        printf("\n  3) Descripcion: %s\n", root->desc                              );
	        printf("\n  4) Rango de edad recomendado: %d-%d\n", root->min, root->max   );
        }

       if (root->hijo_der) 
        {
        	buscarJug(root->hijo_der, juguete);
		}
    } 
	else printf("\nError, el programa no encuentra juguetes registrados.\n");

}

//--------------------------------------------------------STRUCT JUGUETES PEDIDOS----------------------------------------------------------------------------------

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

//---------------------------------------------------------------------------------------------------------------------------------------------------------

//Crear carta.
/*Entradas: Todos los datos que presenta el struct de juguetes
  Salidas: Se crea la carta para enviar a santa.
  Restricciones:  Solo se mostraran las cartas que previamente esten ingresadas al programa.*/
int crear_carta(jug *root)
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
	    
		printf("\n\nIngrese el numero de la funcion a revisar:  ");
	   	fflush(stdin);   
	   	if(scanf("%d",&opc)!=1)
    	{
			printf("Error en la opcion ingresada \n"); 
		}
		else
		{
	
			if(opc==1)
			{
				nino* actual=(nino*) malloc(sizeof(nino));
				actual=primer_Nino;
					
				printf("Valide el numero de identificacion del nino(a) en el programa con (formato X-XXXX-XXXX): ");
				fflush(stdin);
				scanf("%[^\n]", &temp_cedula);
			 	while (strlen(temp_cedula)!=11)
				{
					printf("\n Error, ingrese nuevamente el numero de identificacion del nino(a), con el formato solicitado (X-XXXX-XXXX): ");
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
					printf("\nError, el nino(a) no se encuentra registrado en el programa");
				}
				else
				{
					printf("Ingrese el anio para el que corresponde la carta: ");
					scanf("%d",&anio);
					
					while(desicion2 == 1)
					{		
						printf("Ingrese el nombre del juguete que desea: ");
						fflush(stdin);
						scanf("%[^\n]", &juguetes);
						buscarJug(root,juguetes);
					 	
				    	while (desicion != 1 && desicion != 2 )
						{
							printf("\n 1) Agregar a la Carta para Santa ");
							printf("\n 2) Agregar a la lista de deseos  ");
							printf("\n    Digite su opcion:             ");
							if(scanf("%i",&desicion)!=1)
							{
								printf("\nError, solo puede digitar las opciones presentadas en el menu");
								printf("\nDigite su opcion:  ");
								scanf("%d",&desicion);
							}
						}
						if (desicion == 1)
						{
							if(numJuguetes <= 10)
							{
								nuevoP(temp_cedula,juguetes," ","Solicitado",anio);
								numJuguetes = numJuguetes+1;
								printf(" Cantidad de juguetes en la carta para Santa -%d- de 10.",numJuguetes);					
							}
							else
							{
								printf("Error, ya llego al maximo de juguetes agregados a la carta.");
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
							printf("\n\nDesea agregar otro juguete: ");
							printf("\n -1) Si                       ");
							printf("\n -2) No                       ");
							printf("\nDigite su opcion:             ");
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
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------
//Modificar los datos de la carta
/*Entradas: Todos los datos que presenta el struct de cartas.
Salidas: Se modifican los datos que el usuario necesite. 
Restricciones: Solo se mostraran los juguetes que esten inscritos previamente.*/
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
		printf("Ingrese la identificacion del nino(a) para editar su respectiva carta (X-XXXX-XXXX): "); 
		fflush(stdin);
		scanf("%[^\n]", &identificacion);
		while (strlen(identificacion)!=11) 
		{
			printf("\nError, ingrese nuevamente el numero de identificacion del nino(a), con el formato solicitado (X-XXXX-XXXX): ");
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
			printf("\nError, el nino (a) no ha registrado cartas anteriormente.\n");
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
						printf("\nError, el anio ingresado no presenta cartas registradas.\n");
						return;
					}
				
					actual = primer_carta;
					while(actual != NULL)
					{
						if (anio == actual->anio)
						{
							printf("\n  ---Informacion de la Carta----"              );
							printf("\n  Nombre del nino(a): %s", actual->nombreNino  );
							printf("\n  Cedula: %s", actual->cedula                  );
							printf("\n  Anio del pedido: %d  ", actual->anio         );
							printf("\n  Juguetes pedidos en la Carta:               ");
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
							printf("\n\n  Los juguetes en la Lista de deseos:");
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
		printf("\n Error, no hay ninos(as) con cartas registradas\n\n");
	}
	while (opc != 4) 
	{
		printf("\n                         ---Editar Carta---                            ");
		printf("\n      1) Agregar juguetes a la carta                                   ");
		printf("\n      2) Quitar juguetes de la carta                                   ");
	    printf("\n      3) Pasar un juguete de la lista de deseos a la carta para Santa  ");
	    printf("\n      4) Volver al menu principal                                      ");
	    
		printf("\n\nIngrese el numero de la funcion a revisar:  ");
	   	fflush(stdin);   
	   	if(scanf("%d",&opc)!=1)
    	{
			printf("Error en la opcion ingresada \n"); 
		}
		else
		{
			if (opc == 1)
			{
				printf("\nIngrese el nombre del juguete que desea: ");
				fflush(stdin);
				scanf("%[^\n]", &juguetes);
				
				
				while (desicion != 1 && desicion != 2)
				{
					printf("\n 1) Agregar a la Carta para Santa ");
					printf("\n 2) Agregar a la lista de deseos ");
					printf("\n Digite su opcion:  ");
					scanf("%d",&desicion);
				}
				if (desicion == 1)
				{
					if(numJuguetes <= 10)
					{
						nuevoP(identificacion,juguetes," ","Solicitado",anio);
						numJuguetes = numJuguetes+1;
						printf("\n La cantidad de juguetes en la carta para Santa -%d- de 10.",numJuguetes);
						printf("\nAgregado a la carta.");			
					}
					else
					{
						printf("Error, parece que ya tiene mas de 10 juguetes en la carta.");
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
				printf("\n El juguete fue eliminado ");
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
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

//Mostrar todos las cartas
/*Entradas: Todos los datos que presenta el struct de cartas
Salidas: Muestra en pantalla todos los datos de las cartas que se encuentren registrados. 
Restricciones: Solo se mostraran los juguetes que esten inscritos previamente. */

int mostrar_carta()
{
	char identificacion[12];
	int anio;
	
	cartas* actual = (cartas*) malloc(sizeof(cartas)); // crea nodos 
	actual = primer_carta;
	
	jpedidos *jugue=(jpedidos*) malloc(sizeof(jpedidos));
	jugue= primer;
	
	if(primer_carta != NULL)
	{	
		printf("Ingrese el numero de identificacion del nino(a) para consultar su respectiva carta (X-XXXX-XXXX): "); 
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
							printf("\n  ---Informacion de la Carta----"              );
							printf("\n  Nombre del nino(a): %s", actual->nombreNino  );
							printf("\n  Cedula: %s", actual->cedula                  );
							printf("\n  Anio del pedido: %d  ", actual->anio         );
							printf("\n  Juguetes pedidos en la Carta:               ");
							printf("\n\n  -Juguetes pedidos en la Carta:");
							while(jugue != NULL)
							{
								if(strcmp(identificacion, jugue->cedula)==0)
								{
									if(strcmp(jugue->list_juguetes, " ")!=0){
										printf("\n ->%s (%s)", jugue->list_juguetes,jugue->estado);
									}
								}
								jugue = jugue->sig;
							}
							jugue = primer;
							printf("\n\n  Los juguetes en la lista de deseos:");
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
		printf("Error, parece que el numero de identificaccion no registra cartas en el programa.");
	}
	else
	{
		printf("\nError, no hay ninos(as) con cartas registradas\n\n");
	}
}

//------------------------------------STRUCT REGISTRO PROCESAR CARTAS PARA SANTA ----------------------------------- 
/*Entradas: ID del ayudante y el ID del niño
Salidas: El registro del proceso de cartas para santa
Restricciones: No presenta restricciones */

typedef struct procesar
{
	char ID_ayudante[30], ID_nino[30];
	int anio;
	struct procesar* sig_prog;
} procesar;

//Variables generales de primer y ultimo proceso
procesar* primer_prog=NULL;
procesar* ultimo_prog=NULL;

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

// Insertar procesos
/*Entradas: El ID del ayudante, ID del niño y los años
  Salidas: Se inserta el proceso
  Restricciones: No presenta restricciones*/
int nuevaProcesado(char *ID_ayudante, char  *ID_nino, int anio) 
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
			printf("\nError, en el anio ingresado no hay registro de cartas\n");
			return;
		}
	}
	
	printf("\n----Ninos(as) que han registrado carta este anio----\n");
	actual = primer_carta;
	while(actual!=NULL)
	{
		if (anio == actual->anio)
		{
			printf("\n  Nombre del nino(a): %s", actual->nombreNino);
			printf("\n  Cedula: %s ", actual->cedula);
			printf("\n  Anio de la carta: %d  ",actual->anio);
		}
		actual = actual->sig_carta;
	}
	printf("\n\nIngrese la identificacion del nino que desa procesar su carta: ");
	fflush(stdin);
	scanf("%[^\n]", &identificacion);
	
	actual = primer_carta;
	while(actual != NULL)
	{
		if( strcmp(identificacion, actual->cedula)==0)
		{
			printf("\n----Informacion de la Carta----\n");
			printf("\n  Nombre del nino(a): %s", actual->nombreNino);
			printf("\n  Cedula: %s ", actual->cedula);
			printf("\n  Anio de la carta: %d  ",actual->anio);
			printf("\n\n  Juguetes pedidos en la Carta: ");
			
			printf("\n\n  Los juguetes pedidos en la carta:");
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
			printf("\n\n  Los juguetes en la lista de deseos:");
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
	printf("Ingrese su numero de identificacion como ayudante de Santa (X-XXXX-XXXX):");
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
		while(actual_ayudante!=NULL && encontrado!=1)
		{
			if (strcmp(actual_ayudante->cedula, id)==0)
			{
				encontrado=1;
				actual_ayudante->cartasXAyud++;
			}
			else
			{
				actual_ayudante=actual_ayudante->sig_Ayudante;
			}
		}
	}
	else
	{
		printf("\nError, el ayudante no esta registrado en el programa\n\n");
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
	printf("\n\n  Los juguetes pedidos en la carta:");
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
	printf("\n\nLa carta ha sido procesada y los jueguetes estan listos para entregar\n");
}



//---------------------------------------------------------------------ESTADISTICAS-----------------------------------------------------------------------------


typedef struct estadisticas
{
	char cedula[20];
	int anio, solicitudes;
	struct estadisticas* sig_estadistica;
} estadisticas;

//Variables generales de primer y ultima estadistica
estadisticas* p = NULL;
estadisticas* u = NULL;

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

// Insertar estadisticas
/*Entradas: La cedula y los años
  Salidas: Se inserta la estadistica
  Restricciones: No presenta restricciones*/
int nuevaEstadistica(char *cedula, int anio) 
{
	estadisticas *nuevo=(estadisticas*) malloc(sizeof(estadisticas));
	
	strcpy(nuevo->cedula, cedula);
    nuevo->anio=anio; 
    nuevo->solicitudes=1;

	if(p==NULL)	
	{
		p=nuevo;
		p->sig_estadistica=NULL;
		u=nuevo;
	}
	u->sig_estadistica=nuevo;
	nuevo->sig_estadistica=NULL;
	u=nuevo;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

// La cantidad de comportamientos buenos y malos 
/*Entradas: No posee entradas.
  Salidas: El analisis de los comportamientos
  Restricciones: No presenta restricciones*/
void cant_compotamientos()
{
	int buenos=0,malos=0;
	comportamientos *actual=(comportamientos*) malloc(sizeof(comportamientos));
	actual = primer_compor;
	
	while(actual!=NULL)
	{
		if (actual->comportamientos_buenos == 1)
		{ 
			buenos++;
			
		}
		else
		{
			malos++;
		} 
		actual = actual->sig_compor;
	}
	printf("\n La cantidad de comportamientos buenos: -%i-",buenos);
	printf("\n La cantidad de comportamientos malos: -%i- \n",malos);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

// La cantidad de niños que se les aprobó y rechazó la carta.
/*Entradas: No posee entradas.
  Salidas: El analisis de las cartas aprobadas y las rechazadas.
  Restricciones: No presenta restricciones*/
void aprov_rechazados() 
{
	
	comportamientos *actual=(comportamientos*) malloc(sizeof(comportamientos));
	actual = primer_compor;
	
	estadisticas *actual2=(estadisticas*) malloc(sizeof(estadisticas)); 
	actual2 = p;
	
	int aprov=0, rech=0,malos=0,buenos=0,i=0;
	
	while(actual!=NULL) 
	{
		while (actual2!=NULL)
		{
			if (strcmp(actual->cedu_nino,actual2->cedula)==0)
			{
				if (actual->comportamientos_buenos == 1) 
				{
					buenos++;
					break;
				}
				else
				{
					malos++;
					break;
				}	
			}
			actual2 = actual2->sig_estadistica;
		}
		if (actual2 == NULL)
		{
			nuevaEstadistica(actual->cedu_nino, 0);
			if (actual->comportamientos_buenos == 1) 
			{
				buenos++;
			}
			else
			{
				malos++;
			}
		}
		actual2 = p;
		actual = actual->sig_compor;
	}
	if (malos > 6)
	{
		rech++;
	}
	else aprov++;
	printf("\n Las cartas aprobadas: -%d- ",aprov);
	printf("\n Las cartas rechazadas: -%d- \n",rech);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

// La cantidad de juguetes solicitados por año
/*Entradas: No posee entradas.
  Salidas: El analisis de los juguetes solicitados por año.
  Restricciones: No presenta restricciones*/
int aniosP() 
{
	jpedidos *actual=(jpedidos*) malloc(sizeof(jpedidos));
	actual= primer;
	
	estadisticas *actual2=(estadisticas*) malloc(sizeof(estadisticas)); 
	actual2 = p;
	
	int repetido=0 , cont=0;
	
	printf("\nLos juguetes solicitados por anio\n");
	if(primer!= NULL)
	{
		while(actual != NULL)
		{
			while(actual2!=NULL)
			{
				if(actual->anio == actual2->anio) 
				{
					actual2->solicitudes++;
					break;
				}
				actual2=actual2->sig_estadistica;
			}
			if (actual2 == NULL)
			{
				nuevaEstadistica(" ", actual->anio);
			}
			actual=actual->sig;
			actual2 = p;
		}
		actual2 = p;
		while(actual2!=NULL)
		{
			printf("\n Anio %d: %d\n",actual2->anio, actual2->solicitudes);
			actual2->anio=0; 
			actual2->solicitudes=0;
			actual2=actual2->sig_estadistica;
		}
		
	}
	else
	{
		printf("\n Error,no hay anios registrados.\n");
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------

// Recorrido por inorden.
/*Entradas: Todos los datos del struct de juguetes.
  Salidas: El recorrido de los juguetes
  Restricciones: No presenta restricciones*/
void mJuguetes(struct juguete *root)//recorrido inorden
{
	printf("\n-Juguetes mas pedidos\n");
	
    if(root!=NULL) 
    {
        mJuguetes(root->hijo_izq);
        printf("\tNombre: %s\n", root->nombre);
        
        mJuguetes(root->hijo_der);
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

// La cantidad de cartas procesadas segun ayudante.
/*Entradas: No posee entradas.
  Salidas: El analisis de las cartas por ayudante
  Restricciones: No presenta restricciones*/
void cartas_x_ayudante()
{
	ayudante* actual=(ayudante*) malloc(sizeof(ayudante)); 
	actual=primer_Ayudante;
	
	printf("\n La cantidad de cartas procesadas segun ayudante");
	if(primer_Ayudante!=NULL)
	{
		while(actual!=NULL)
		{
			printf("\n   Nombre: %s", actual->nombre);
			printf("\n   Cartas Procesadas: %i ",actual->cartasXAyud);
			actual=actual->sig_Ayudante;
		}
	}
	else
	{
		printf("\n\Error no hay ayudantes registrados\n\n");
	}
}

//***********************************************************************************************************************************************************
//Menu principal del proyecto.
/*Entradas: No posee entradas.
   Salidas: Las diferentes funcionalidades que presenta el menu
   Restricciones: Solo las funcionalidades mostradas en el programa son las unicas que se podran realizar.*/
int main (void)
{
	int opc;
	struct juguete *root;
    root=nuevoJuguete(1, "Mazo de cartas", "Juego clasico de cartas", "Juegos de mesa", 99, 7, 3);
	
	while (opc!=10)
	{
		printf("\n                             ---MENU PRINCIPAL---                           ");
		printf("\n 1)  Registro de ninos(as)             |  6)  Carta a Santa                 ");
		printf("\n 2)  Registro de ayudantes de Santa    |  7)  Procesar cartas para Santa    ");
		printf("\n 3)  Registro de juguetes              |  8)  Entregar regalos              ");
		printf("\n 4)  Lugares de domicilio              |  9)  Analisis de datos             ");
		printf("\n 5)  Registro comportamiento de ninos  |  10) Finalizar programa            ");
	    
		printf("\n\nIngrese el numero de la funcion a revisar:  ");
		fflush(stdin);   
	   	if(scanf("%i",&opc)!=1)
    	{
			printf("Error, la opcion ingresa fue incorrecta. \n"); 
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
				Domicilios();
			}
			else if(opc==5)
			{
				comportamiento();
			}
			else if(opc==6)
			{
				crear_carta(root);
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
				printf("\n ---ESTADISTICAS--- \n");
				aniosP();
				cant_compotamientos();
				aprov_rechazados();
				mJuguetes(root);
				cartas_x_ayudante();
			}
			else if(opc>11||opc<1)
			{
				printf("\n Error, la ocpion ingresada no existe en el  programa, intente de nuevo.\n");
			}
		}
	}
	return 0;
	system("PAUSE");
}





