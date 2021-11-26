#ifndef EMOVIE_H_INCLUDED
#define EMOVIE_H_INCLUDED

typedef struct
{
    int id_peli;
    char titulo[30];
    char genero[11];
    float rating;
}eMovie;

 /** \brief Inicializa una nueva pelicula
 * \return eMovie* La dirección de memoria de la nueva pelicula creada
 */
eMovie* pelicula_nueva();

/** \brief Asigna valores hardcodeados a una pelicula
 * \param idStr char* Cadena de caracteres del ID de la pelicula
 * \param tituloStr char* Cadena de caracteres del titulo de la pelicula
 * \param generoStr char* Cadena de caracteres del genero de la pelicula
 * \param ratingStr char* Cadena de caracteres del rating de la pelicula
 * \return eMovie* La dirección de memoria de la pelicula hardcodeada
 */
eMovie* pelicula_nuevosParametros(char* idStr, char* tituloStr, char* generoStr, char* ratingStr);

/** \brief Libera la memoria dinámica donde se guardaba una pelicula
 * \return void No retorna nada
 */
void pelicula_eliminar();

/** \brief Asigna el valor del ID a la pelicula
 * \param this eMovie* Puntero a estructura eMovie a la cual se asignará el ID
 * \param id int El valor del ID a asignar
 * \return int 1 si hubo error, 0 si no hubo error
 */
int pelicula_setId(eMovie* this, int id);

/** \brief Busca y obtiene el valor del ID de una pelicula
 * \param this eMovie* Puntero a estructura eMovie de la cual se obtiene el ID
 * \param id int* Puntero a entero del ID de la pelicula
 * \return int 1 si hubo error, 0 si no hubo error
 */
int pelicula_getId(eMovie* this, int* id);

/** \brief Asigna el valor del titulo a la pelicula
 * \param this eMovie* Puntero a estructura eMovie a la cual se asignará el titulo
 * \param titulo char* La cadena de caracteres del titulo a asignar
 * \return int 1 si hubo error, 0 si no hubo error
 */
int pelicula_setTitulo(eMovie* this, char* titulo);

/** \brief Busca y obtiene el valor del titulo de una pelicula
 * \param this eMovie* Puntero a estructura eMovie de la cual se obtiene el titulo
 * \param titulo char* Puntero a char del titulo de la pelicula
 * \return int 1 si hubo error, 0 si no hubo error
 */
int pelicula_getTitulo(eMovie* this, char* titulo);

/** \brief Asigna el valor del genero a la pelicula
 * \param this eMovie* Puntero a estructura eMovie a la cual se asignará el genero
 * \param genero char* La cadena de caracteres del genero a asignar
 * \return int 1 si hubo error, 0 si no hubo error
 */
int pelicula_setGenero(eMovie* this, char* genero);

/** \brief Busca y obtiene el valor del genero de una pelicula
 * \param this eMovie* Puntero a estructura eMovie de la cual se obtiene el genero
 * \param genero char* Puntero a char del genero de la pelicula
 * \return int 1 si hubo error, 0 si no hubo error
 */
int pelicula_getGenero(eMovie* this, char* genero);

/** \brief Asigna el valor del rating a la pelicula
 * \param this eMovie* Puntero a estructura eMovie a la cual se asignará el rating
 * \param id int El valor del rating a asignar
 * \return int 1 si hubo error, 0 si no hubo error
 */
int pelicula_setRating(eMovie* this, float rating);

/** \brief Busca y obtiene el valor del rating de una pelicula
 * \param this eMovie* Puntero a estructura eMovie del cual se obtiene el rating
 * \param id int* Puntero a entero del rating de la pelicula
 * \return int 1 si hubo error, 0 si no hubo error
 */
int pelicula_getRating(eMovie* this, float* rating);

/** \brief Lista una unica pelicula
 * \param this eMovie* La pelicula a listar
 * \return void No retorna nada
 */
void pelicula_mostrarPelicula(eMovie* this);

/** \brief Compara los generos de las peliculas y los ordena segun criterio que elija el usuario, y en caso de mismo genero, se ordena por rating descendente
 * \param pelicula1 void* Puntero a void de la primera pelicula a comparar
 * \param pelicula2 void* Puntero a void de la segunda pelicula a comparar
 * \return int 1 en el caso de que los generos o ratings esten desordenados y haya que swapearlos
 */
int pelicula_ordenarPorGeneroRating(void* pelicula1, void* pelicula2);

/** \brief Asigna ratings random flotantes de 1 decimal entre 1 y 10
 * \param pelicula void* Puntero a void de película que luego se castea
 * \return void* Retorna puntero a void con la pelicula con el rating ya asignado
 */
void* pelicula_asignarRatings(void* pelicula);

/** \brief Asigna generos segun numero random de 1 a 4
 * \param pelicula void* Puntero a void de película que luego se castea
 * \return void* Retorna puntero a void con la pelicula con el genero ya asignado
 */
void* pelicula_asignarGenero(void* pelicula);

/** \brief Filtra las peliculas de genero Drama
 * \param pelicula void* Puntero a void de la pelicula que luego se castea
 * \return int 1 si la pelicula pasa el filtro, 0 si no lo pasa
 */
int pelicula_filtrarDrama(void* pelicula);

/** \brief Filtra las peliculas de genero Comedia
 * \param pelicula void* Puntero a void de la pelicula que luego se castea
 * \return int 1 si la pelicula pasa el filtro, 0 si no lo pasa
 */
int pelicula_filtrarComedia(void* pelicula);

/** \brief Filtra las peliculas de genero Accion
 * \param pelicula void* Puntero a void de la pelicula que luego se castea
 * \return int 1 si la pelicula pasa el filtro, 0 si no lo pasa
 */
int pelicula_filtrarAccion(void* pelicula);

/** \brief Filtra las peliculas de genero Terror
 * \param pelicula void* Puntero a void de la pelicula que luego se castea
 * \return int 1 si la pelicula pasa el filtro, 0 si no lo pasa
 */
int pelicula_filtrarTerror(void* pelicula);

#endif // EMOVIE_H_INCLUDED
