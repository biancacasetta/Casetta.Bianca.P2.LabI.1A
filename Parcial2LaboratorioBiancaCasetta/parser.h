#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

/** \brief Parsea los datos de las peliculas desde el archivo movies.csv (modo texto).
 * \param pFile FILE* La dirección de memoria del archivo a parsear
 * \param listaPeliculas LinkedList* Puntero a estructura LinkedList donde se crea la lista de peliculas
 * \return int 1 si hubo error, 0 si no hubo error
 */
int parser_peliculasDesdeTexto(FILE* pFile, LinkedList* listaPeliculas);

#endif // PARSER_H_INCLUDED
