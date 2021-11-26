#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eMovie.h"
#include "parser.h"
#include "Controller.h"

int parser_peliculasDesdeTexto(FILE* pFile, LinkedList* listaPeliculas)
{
    int error=1;

    eMovie* auxMovie;
    char buffer[4][30];

    if(pFile!=NULL && listaPeliculas!=NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        do
        {
            if((fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]))==4)
            {
                auxMovie=pelicula_nuevosParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

				if(auxMovie!=NULL)
				{
					if(ll_add(listaPeliculas, auxMovie))
					{
                        pelicula_eliminar(auxMovie);
						error=1;
						break;
					}
					else
					{
						error=0;
					}
				}
			}
			else
			{
				break;
			}
        }
        while(!feof(pFile));

    }
    return error;
}
