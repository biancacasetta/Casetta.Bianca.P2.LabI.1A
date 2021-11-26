#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "input.h"
#include "Controller.h"

int main()
{
    char seguir='s';
    char salir='n';
    int opcion6=0;
    LinkedList* listaPeliculas=ll_newLinkedList();
    LinkedList* listaOrdenada=ll_newLinkedList();

    do
    {
        system("cls");
        switch(menu())
        {
            case 1:
                controller_cargarArchivoTexto(listaPeliculas);
                break;
            case 2:
                if(!ll_isEmpty(listaPeliculas))
                {
                    controller_mostrarPeliculas(listaPeliculas);
                }
                else
                {
                    printf("\nNo puede imprimir la lista de peliculas sn cargar un archivo.\n\n");
                }
                break;
            case 3:
                if(!ll_isEmpty(listaPeliculas))
                {
                    if(controller_validarRatings(listaPeliculas))
                    {
                        controller_asignarRatings(listaPeliculas);
                    }
                    else
                    {
                        printf("\nNo se pueden asignar los ratings a un archivo que ya los tiene asignados.\n\n");
                    }
                }
                else
                {
                    printf("\nNo se pueden asignar ratings sin cargar un archivo.\n\n");
                }
                break;
            case 4:
                if(!ll_isEmpty(listaPeliculas))
                {
                    if(controller_validarGeneros(listaPeliculas))
                    {
                        controller_asignarGeneros(listaPeliculas);
                    }
                    else
                    {
                        printf("\nNo se pueden asignar los generos a un archivo que ya los tiene asignados.\n\n");
                    }
                }
                else
                {
                    printf("\nNo se pueden asignar generos sin cargar un archivo.\n\n");
                }
                break;
            case 5:
                if(!ll_isEmpty(listaPeliculas))
                {
                    if(!controller_validarRatings(listaPeliculas) || !controller_validarGeneros(listaPeliculas))
                    {
                        controller_filtrarGenero(listaPeliculas);
                    }
                    else
                    {
                        printf("\nNo se puede filtrar la lista de peliculas si no se asignaron los ratings o los generos.\n\n");
                    }
                }
                else
                {
                    printf("\nNo se puede filtrar por genero sin cargar un archivo.\n\n");
                }
                break;
            case 6:
                if(!ll_isEmpty(listaPeliculas))
                {
                    if(!controller_validarRatings(listaPeliculas))
                    {
                        listaOrdenada=controller_ordenarPorGeneroRating(listaPeliculas);
                        opcion6=1;
                    }
                    else
                    {
                        printf("\nNo se puede ordenar la lista de peliculas si no se asignaron los ratings.\n\n");
                    }
                }
                else
                {
                    printf("\nNo se puede ordenar la lista de peliculas sin cargar un archivo.\n\n");
                }
                break;
            case 7:
                if(!ll_isEmpty(listaPeliculas))
                {
                    controller_guardarArchivoTexto("pelisGeneroRating.csv", listaOrdenada);
                    printf("pelisGeneroRating.csv\n\n");
                }
                else if(!opcion6)
                {
                    printf("\nNo se pueden guardar las peliculas sin ordenarlas antes en la opción 6.\n\n");
                }
                else
                {
                    printf("\nNo se pueden guardar las peliculas sin cargar un archivo.\n\n");
                }
                break;
            case 8:
                validarCaracter(&salir, "\nConfirmar salida (S/N): ", "Opción inválida. Confirmar salida (S/N): ", 'S', 'N');

                if(salir=='S')
                {
                    ll_deleteLinkedList(listaPeliculas);
                    seguir='n';
                }
                break;
            default:
                printf("Opción inválida. Ingrese una opción del 1 al 8.\n");
                fflush(stdin);
                break;
        }
        system("pause");
    }while(seguir=='s');

    return 0;
}
