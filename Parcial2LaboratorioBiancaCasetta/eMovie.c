#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "LinkedList.h"
#include "Controller.h"
#include "eMovie.h"
#include "input.h"

eMovie* pelicula_nueva()
{
	eMovie* peliculaNueva;

	peliculaNueva=(eMovie*)malloc(sizeof(eMovie));
	if(peliculaNueva!=NULL)
	{
		peliculaNueva->id_peli=0;
		strcpy(peliculaNueva->titulo," ");
		strcpy(peliculaNueva->genero," ");
		peliculaNueva->rating=0;
	}
	return peliculaNueva;
}

eMovie* pelicula_nuevosParametros(char* idStr, char* tituloStr, char* generoStr, char* ratingStr)
{
    eMovie* peliculaNueva;

	peliculaNueva=pelicula_nueva();

	if(peliculaNueva!=NULL)
	{
		if((pelicula_setId(peliculaNueva, atoi(idStr))
            || pelicula_setTitulo(peliculaNueva, tituloStr)
            || pelicula_setGenero(peliculaNueva, generoStr)
            || pelicula_setRating(peliculaNueva, atoi(ratingStr))))
		{
			pelicula_eliminar(peliculaNueva);
			peliculaNueva=NULL;
		}
	}

	return peliculaNueva;
}

void pelicula_eliminar(eMovie* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

int pelicula_setId(eMovie* this, int id)
{
	int error=1;

	if(this!=NULL && id>0)
	{
		this->id_peli=id;
		error=0;
	}
	return error;
}

int pelicula_getId(eMovie* this, int* id)
{
	int error=1;

	if(this!=NULL && id!=NULL)
	{
		*id=this->id_peli;
		error=0;
	}
	return error;
}

int pelicula_setTitulo(eMovie* this, char* titulo)
{
    int error=1;

	if(this!=NULL && titulo!=NULL)
	{
        if(strlen(titulo)<35 && strlen(titulo)>1)
        {
            strcpy(this->titulo, titulo);
        }
		error=0;
	}
	return error;
}

int pelicula_getTitulo(eMovie* this, char* titulo)
{
    int error=1;
	if(this!=NULL && titulo!=NULL)
	{
		strcpy(titulo, this->titulo);
		error=0;
	}
	return error;
}

int pelicula_setGenero(eMovie* this, char* genero)
{
    int error=1;

	if(this!=NULL && genero!=NULL)
	{
        if(strlen(genero)<11 && strlen(genero)>4)
        {
            strcpy(this->genero, genero);
        }
		error=0;
	}
	return error;
}

int pelicula_getGenero(eMovie* this, char* genero)
{
    int error=1;
	if(this!=NULL && genero!=NULL)
	{
		strcpy(genero, this->genero);
		error=0;
	}
	return error;
}

int pelicula_setRating(eMovie* this, float rating)
{
    int error=1;

	if(this!=NULL && rating>=0 && rating<=10)
	{
		this->rating=rating;
		error=0;
	}
	return error;
}

int pelicula_getRating(eMovie* this, float* rating)
{
    int error=1;

    if(this!=NULL && rating!=NULL)
    {
        *rating=this->rating;
        error=0;
    }
    return error;
}

void pelicula_mostrarPelicula(eMovie* this)
{
    int id;
    char titulo[30];
    char genero[11];
    float rating;

    if(this!=NULL)
    {
        pelicula_getId(this, &id);
        pelicula_getTitulo(this, titulo);
        pelicula_getGenero(this, genero);
        pelicula_getRating(this, &rating);

        printf("%-5d%-31s%-11s%-1.1f\n", id, titulo, genero, rating);
    }
}

void* pelicula_asignarRatings(void* pelicula)
{
    eMovie* auxPelicula=(eMovie*) pelicula;
    float rating;
    int min=10;
    int max=100;

    if(pelicula!=NULL)
    {
        rating=(float)(rand()%(max-min+1)+min)/10;
        pelicula_setRating(auxPelicula, rating);
    }

    return auxPelicula;
}

void* pelicula_asignarGenero(void* pelicula)
{
    eMovie* auxPelicula=(eMovie*) pelicula;
    int numGenero;
    int min=1;
    int max=4;

    if(pelicula!=NULL)
    {
        numGenero=rand()%(max-min+1)+min;

        if(numGenero==1)
        {
            pelicula_setGenero(auxPelicula, "Drama");
        }
        else if(numGenero==2)
        {
            pelicula_setGenero(auxPelicula, "Comedia");
        }
        else if(numGenero==3)
        {
            pelicula_setGenero(auxPelicula, "Accion");
        }
        else if(numGenero==4)
        {
            pelicula_setGenero(auxPelicula, "Terror");
        }
    }

    return auxPelicula;
}

int pelicula_ordenarPorGeneroRating(void* pelicula1, void* pelicula2)
{
    int retorno=0;
	eMovie* aux1=(eMovie*) pelicula1;
	eMovie* aux2=(eMovie*) pelicula2;
	char genero1[20];
	char genero2[20];
	float rating1;
	float rating2;

	if(pelicula1!=NULL && pelicula2!=NULL)
	{
		pelicula_getGenero(aux1, genero1);
		pelicula_getGenero(aux2, genero2);

		pelicula_getRating(aux1, &rating1);
		pelicula_getRating(aux2, &rating2);

		if(strcmp(genero1, genero2)>0 || (!strcmp(genero1, genero2) && rating1<rating2))
        {
			retorno=1;
		}
	}
    return retorno;
}

int pelicula_filtrarDrama(void* pelicula)
{
    int retorno=0;
    eMovie* auxPelicula=(eMovie*) pelicula;
    char genero[20];

    if(pelicula!=NULL)
    {
        pelicula_getGenero(auxPelicula, genero);

        if(!strcmp(genero, "Drama"))
        {
            retorno=1;
        }
    }
    return retorno;
}

int pelicula_filtrarComedia(void* pelicula)
{
    int retorno=0;
    eMovie* auxPelicula=(eMovie*) pelicula;
    char genero[20];

    if(pelicula!=NULL)
    {
        pelicula_getGenero(auxPelicula, genero);

        if(!strcmp(genero, "Comedia"))
        {
            retorno=1;
        }
    }
    return retorno;
}

int pelicula_filtrarAccion(void* pelicula)
{
    int retorno=0;
    eMovie* auxPelicula=(eMovie*) pelicula;
    char genero[20];

    if(pelicula!=NULL)
    {
        pelicula_getGenero(auxPelicula, genero);

        if(!strcmp(genero, "Accion"))
        {
            retorno=1;
        }
    }
    return retorno;
}

int pelicula_filtrarTerror(void* pelicula)
{
    int retorno=0;
    eMovie* auxPelicula=(eMovie*) pelicula;
    char genero[20];

    if(pelicula!=NULL)
    {
        pelicula_getGenero(auxPelicula, genero);

        if(!strcmp(genero, "Terror"))
        {
            retorno=1;
        }
    }
    return retorno;
}
