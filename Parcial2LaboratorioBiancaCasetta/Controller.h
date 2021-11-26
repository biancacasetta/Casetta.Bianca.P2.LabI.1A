#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "eMovie.h"

/** \brief Carga los datos de las peliculas almacenados en un archivo
 * \param path char* El nombre del archivo a cargar
 * \param listaPeliculas LinkedList* Puntero a estructura LinkedList donde se crea la lista de peliculas
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_cargarArchivoTexto(LinkedList* listaPeliculas);

/** \brief Listar peliculas
 * \param listaPeliculas LinkedList* Puntero a estructura LinkedList de donde se listan peliculas
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_mostrarPeliculas(LinkedList* listaPeliculas);

/** \brief Ordenar peliculas por genero y a su vez por rating
 * \param listaPeliculas LinkedList* Puntero a estructura LinkedList donde se ordenan peliculas
 * \return LinkedList* Puntero a LinkedList con la nueva lista ordenada
 */
LinkedList* controller_ordenarPorGeneroRating(LinkedList* listaPeliculas);

/** \brief Guarda los datos de las peliculas en un archivo
 * \param path char* El nombre del archivo donde se guardarán los datos
 * \param listaPeliculas LinkedList* Puntero a estructura LinkedList donde se crea la lista de peliculas
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_guardarArchivoTexto(char* path, LinkedList* listaPeliculas);

/** \brief Carga valores flotantes random entre 1 y 10 como rating de cada pelicula
 * \param listaPeliculas LinkedList* Puntero a estructura LinkedList con la lista de peliculas
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_asignarRatings(LinkedList* listaPeliculas);

/** \brief Carga valores de cadena de caracteres segun un numero random del 1 al 4 como genero de cada pelicula
 * \param listaPeliculas LinkedList* Puntero a estructura LinkedList con la lista de peliculas
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_asignarGeneros(LinkedList* listaPeliculas);

/** \brief Valida que los ratings cargados en la lista sean distintos a 0.0, o sea que ya esten asignados
 * \param listaPeliculas LinkedList* Puntero a estructura LinkedList con la lista de peliculas
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_validarRatings(LinkedList* listaPeliculas);

/** \brief Valida que los generos cargados en la lista sean distintos a "sin genero", o sea que ya esten asignados
 * \param listaPeliculas LinkedList* Puntero a estructura LinkedList con la lista de peliculas
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_validarGeneros(LinkedList* listaPeliculas);

/** \brief Muestra un menu de generos y le pide al usuario que seleccione un genero a filtrar, y luego genera un archivo de esa lista de peliculas filtradas
 * \param listaPeliculas LinkedList* Puntero a estructura LinkedList con la lista de peliculas
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_filtrarGenero(LinkedList* listaPeliculas);

#endif // CONTROLLER_H_INCLUDED
