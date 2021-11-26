#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

int menu()
{
    int opcion;

    printf("        SISTEMA DE PELICULAS     \n");
    printf("---------------------------------\n\n");
    printf("1. Cargar archivo\n");
    printf("2. Imprimir lista\n");
    printf("3. Asignar ratings\n");
    printf("4. Asignar generos\n");
    printf("5. Filtrar por genero\n");
    printf("6. Ordenar peliculas\n");
    printf("7. Guardar peliculas\n");
    printf("8. Salir\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    fflush(stdin);

    return opcion;
}

int subMenuGenero()
{
    int opcion;

    printf("1. Drama\n");
    printf("2. Comedia\n");
    printf("3. Accion\n");
    printf("4. Terror\n");
    printf("5. Cancelar filtro\n\n");
    printf("Seleccione el genero que desea filtrar: ");
    scanf("%d", &opcion);
    fflush(stdin);

    return opcion;
}

int soloLetras(char cadena[])
{
    int error=0;
    int i=0;

    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(!isalpha(cadena[i]) && cadena[i]!=' ')
            {
                error=-1;

                while(error<0)
                {
                    printf("Solo puede ingresar letras. Inténtelo de nuevo: ");
                    fflush(stdin);
                    scanf("%s", cadena);
                    error=0;
                    i=0;
                }
            }
            else
            {
                i++;
            }
        }
    }
    return error;
}

int inicialMayuscula(char cadena[])
{
    int error=-1;
    int i=0;

    strlwr(cadena);
    cadena[0]=toupper(cadena[0]);

    while(cadena[i]!='\0')
    {
        if(cadena[i]==' ')
        {
            cadena[i+1]=toupper(cadena[i+1]);
            error=0;
        }
        i++;
    }
    return error;
}

int validarCadena(char cadena[], char mensaje[], char mensajeError[], int min, int max)
{
    int error=-1;
	char aux[100];

	if(cadena!=NULL && mensaje!=NULL && mensajeError!=NULL && min>0 && max>min)
	{
		printf("%s", mensaje);
		fflush(stdin);
		gets(aux);
		soloLetras(aux);

		while(strlen(aux)<=min|| strlen(aux)>=max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			gets(aux);
			soloLetras(aux);
		}
		inicialMayuscula(aux);

		strcpy(cadena, aux);
		error=0;
	}

	return error;
}

int validarCaracter(char* caracter, char mensaje[], char mensajeError[], char caracterValido1, char caracterValido2)
{
    int error=-1;
    char caracterIngresado;

	if(caracter!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &caracterIngresado);
		caracterIngresado=toupper(caracterIngresado);

		while(caracterIngresado!=caracterValido1 && caracterIngresado!=caracterValido2)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%c", &caracterIngresado);
			caracterIngresado=toupper(caracterIngresado);
		}

        *caracter=caracterIngresado;
		error=0;
	}

	return error;
}

int soloNumeros(char* numeros)
{
	int error=0;

	if(strlen(numeros)>0)
    {
        for(int i=0; i<strlen(numeros); i++)
        {
            if(!isdigit(numeros[i]))
            {
                if(!i && numeros[0]=='-')
                {
                    error=0;
                }
                else
                {
                    error=1;
                }
            }
        }
    }
    else
    {
        error=1;
    }

	return error;
}

int validarEntero(int* numero, char mensaje[], char mensajeError[], int min, int max)
{
    int error=-1;
    char numeroIngresado[20];

	if(numero!=NULL && mensaje!=NULL && mensajeError!=NULL && min<max)
	{
		printf("%s", mensaje);
		gets(numeroIngresado);
		fflush(stdin);

        while(soloNumeros(numeroIngresado) || atoi(numeroIngresado)<=min || atoi(numeroIngresado)>=max)
		{
			printf("%s", mensajeError);
			gets(numeroIngresado);
			fflush(stdin);
		}

        *numero=atoi(numeroIngresado);
		error=0;
	}

	return error;
}
