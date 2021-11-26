#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "eMovie.h"
#include "Controller.h"
#include "parser.h"
#include "input.h"

int controller_cargarArchivoTexto(LinkedList* listaPeliculas)
{
    int error=1;
	FILE* f;
	char path[20];

	if(listaPeliculas!=NULL)
	{
	    ll_clear(listaPeliculas);

	    system("cls");
	    printf("                     CARGA DE ARCHIVO                   \n");
	    printf("--------------------------------------------------------\n\n");
	    printf("Ingrese el nombre del archivo que desea cargar: ");
	    fflush(stdin);
	    gets(path);

		f=fopen(path, "r");

		if(f!=NULL)
		{
			parser_peliculasDesdeTexto(f, listaPeliculas);
			printf("\nCarga de archivo de texto exitosa.\n\n");
			error=0;
		}
		else
        {
            printf("\nNo se pudo cargar el archivo o el archivo no existe.\n\n");
        }
		fclose(f);
	}
    return error;
}

int controller_mostrarPeliculas(LinkedList* listaPeliculas)
{
    int error=1;
    eMovie* pelicula=NULL;
    int len;

    if(listaPeliculas!=NULL)
    {
        system("cls");
        printf("                    LISTA DE PELICULAS                 \n");
        printf("-------------------------------------------------------\n");
        printf(" ID |            TITULO            |  GENERO  | RATING \n");
        printf("-------------------------------------------------------\n");

        len=ll_len(listaPeliculas);

        if(len>0)
        {
            for(int i=0; i<len; i++)
            {
                pelicula=ll_get(listaPeliculas, i);
                pelicula_mostrarPelicula(pelicula);
            }
        }
        printf("\n");
        error=0;
    }

    return error;
}

LinkedList* controller_ordenarPorGeneroRating(LinkedList* listaPeliculas)
{
    LinkedList* auxList;

    if(listaPeliculas!=NULL)
    {
        auxList=ll_clone(listaPeliculas);

        system("cls");
        printf("         ORDENAR PELICULAS POR GENERO Y RATING        \n");
        printf("------------------------------------------------------\n\n");

        ll_sort(auxList, pelicula_ordenarPorGeneroRating, 1);
        system("cls");
        controller_mostrarPeliculas(auxList);
    }

    return auxList;
}

int controller_guardarArchivoTexto(char* path, LinkedList* listaPeliculas)
{
    int error=1;
    FILE* f;
    eMovie* pelicula;
    int id;
	char titulo[30];
	char genero[20];
	float rating;
	int len;

	if(path!=NULL && listaPeliculas!=NULL)
	{
		f=fopen(path, "w");
		pelicula=pelicula_nueva();
		len=ll_len(listaPeliculas);

		fprintf(f, "id_peli,titulo,genero,rating\n");

		for(int i=0; i<len; i++)
		{
			pelicula=ll_get(listaPeliculas, i);

			if(pelicula!=NULL)
			{
				pelicula_getId(pelicula, &id);
				pelicula_getTitulo(pelicula, titulo);
				pelicula_getGenero(pelicula, genero);
				pelicula_getRating(pelicula, &rating);

				fprintf(f, "%d,%s,%s,%.1f\n", id, titulo, genero, rating);
				error=0;
			}
		}
		fclose(f);
		printf("Se ha guardado el archivo de texto con exito bajo el nombre ");
	}

    return error;
}

int controller_asignarRatings(LinkedList* listaPeliculas)
{
    int error=1;

    if(listaPeliculas!=NULL)
    {
        if(ll_map(listaPeliculas, pelicula_asignarRatings)!=NULL)
        {
            printf("\nRatings asignados con exito.\n\n");
        }
        error=0;
    }

    return error;
}

int controller_asignarGeneros(LinkedList* listaPeliculas)
{
    int error=1;

    if(listaPeliculas!=NULL)
    {
        if(ll_map(listaPeliculas, pelicula_asignarGenero)!=NULL)
        {
            printf("\nGeneros asignados con exito.\n\n");
        }
        error=0;
    }

    return error;
}

int controller_validarRatings(LinkedList* listaPeliculas)
{
    int error=0;
	eMovie* auxPelicula;
	int len;
	float rating;

	for(int i=0; i<len; i++)
	{
	    len=ll_len(listaPeliculas);
		auxPelicula=(eMovie*)ll_get(listaPeliculas,i);
		pelicula_getRating(auxPelicula, &rating);

		if(!rating)
		{
			error=1;
			break;
		}
	}
	return error;
}

int controller_validarGeneros(LinkedList* listaPeliculas)
{
    int error=0;
	eMovie* auxPelicula;
	int len;
	char genero[20];

	for(int i=0; i<len; i++)
	{
	    len=ll_len(listaPeliculas);
		auxPelicula=(eMovie*)ll_get(listaPeliculas,i);
		pelicula_getGenero(auxPelicula, genero);

		if(!strcmp(genero, "sin genero"))
		{
			error=1;
			break;
		}
	}
	return error;
}

int controller_filtrarGenero(LinkedList* listaPeliculas)
{
    int error=1;
    LinkedList* listaPorGenero=NULL;

    if(listaPeliculas!=NULL)
    {
        listaPorGenero=ll_newLinkedList();

        if(listaPorGenero!=NULL)
        {
            system("cls");
            printf("         FILTRAR POR GENERO           \n");
            printf("--------------------------------------\n\n");

            switch(subMenuGenero())
            {
                case 1:
                    listaPorGenero=ll_filter(listaPeliculas, pelicula_filtrarDrama);
                    controller_mostrarPeliculas(listaPorGenero);
                    controller_guardarArchivoTexto("pelisDrama.csv", listaPorGenero);
                    printf("pelisDrama.csv\n\n");
                    break;
                case 2:
                    listaPorGenero=ll_filter(listaPeliculas, pelicula_filtrarComedia);
                    controller_mostrarPeliculas(listaPorGenero);
                    controller_guardarArchivoTexto("pelisComedia.csv", listaPorGenero);
                    printf("pelisComedia.csv\n\n");
                    break;
                case 3:
                    listaPorGenero=ll_filter(listaPeliculas, pelicula_filtrarAccion);
                    controller_mostrarPeliculas(listaPorGenero);
                    controller_guardarArchivoTexto("pelisAccion.csv", listaPorGenero);
                    printf("pelisAccion.csv\n\n");
                    break;
                case 4:
                    listaPorGenero=ll_filter(listaPeliculas, pelicula_filtrarTerror);
                    controller_mostrarPeliculas(listaPorGenero);
                    controller_guardarArchivoTexto("pelisTerror.csv", listaPorGenero);
                    printf("pelisTerror.csv\n\n");
                    break;
                case 5:
                    printf("\nFiltrado cancelado.\n\n");
                    break;
                default:
                    printf("Opcion invalida. Vuelva a intentarlo e ingrese una opcion del 1 al 5.");
                    break;
            }
            error=0;
        }
    }
    return error;
}
