#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#endif // INPUT_H_INCLUDED


/** \brief Muestra un menu inicial de opciones para seleccionar
 * \return int La opción seleccionada por el usuario, para luego usar de criterio en un switch
 */
int menu();

/** \brief Muestra un submenu con las opciones de genero para seleccionar
 * \return int La opcion seleccionada por el usuario, para luego usar de criterio en un switch
 */
int subMenuGenero();

/** \brief Valida que la cadena de caracteres ingresada contenga letras únicamente, sin permitir numeros ni simbolos
 * \param cadena[] char La cadena de caracteres a validar
 * \return int 1 si hubo error, 0 si no hubo error
 */
int soloLetras(char cadena[]);

/** \brief Formatea una cadena de caracteres de manera que la(s) inicial(es) sea(n) mayúscula y el resto, minúsculas
 * \param cadena[] char La cadena de caracteres a formatear
 * \return 1 si hubo error, 0 si no hubo error
 */
int inicialMayuscula(char cadena[]);

/** \brief Valida que una cadena de caracteres no supere la cantidad máxima de caracteres permitidos, ni que no ingrese nada
 * \param cadena[] char La cadena de caracteres a validar
 * \param mensaje[] char El mensaje a mostrar como prompt para que el usuario ingrese la cadena de caracteres
 * \param mensajeError[] char El mensaje de error en caso de que la cadena supere el límite de caracteres o no ingrese nada
 * \param min int El mínimo de caracteres a ingresar (al menos 1)
 * \param max int El máximo de caracteres a ingresar (según corresponda)
 * \return 1 si hubo error, 0 si no hubo error
 */
int validarCadena(char cadena[], char mensaje[], char mensajeError[], int min, int max);

/** \brief Valida que un caracter esté dentro de las opciones válidas (generalmente usado para prompts de SI o NO O S/N)
 * \param caracter char* Puntero a caracter del caracter ingresado por el usuario
 * \param mensaje[] char El mensaje a mostrar como prompt para que el usuario ingrese el caracter
 * \param mensajeError[] char El mensaje de error en caso de que el caracter no sea ninguno de los válidos
 * \param caracterValido1 char Una de las opciones válidas de caracter ingresado
 * \param caracterValido2 char Otra de las opciones válidas de caracter ingresado
 * \return 1 si hubo error, 0 si no hubo error
 */
int validarCaracter(char* caracter, char mensaje[], char mensajeError[], char caracterValido1, char caracterValido2);

/** \brief Valida que la cadena de caracteres ingresada contenga números únicamente, sin permitir letras ni símbolos
 * \param numeros[] char La cadena de caracteres a validar
 * \return int 1 si hubo error, 0 si no hubo error
 */
int soloNumeros(char numeros[]);

/** \brief Valida que un número entero esté dentro de un rango específico y que no se ingresen letras o símbolos
 * \param numero int* Puntero a entero del número entero ingresado por el usuario
 * \param mensaje[] char El mensaje a mostrar como prompt para que el usuario ingrese el número entero
 * \param mensajeError[] char El mensaje de error en caso de que el número entero se encuentre fuera del rango válido
 * \param min float El mínimo número entero válido
 * \param max float El máximo número entero válido
 * \return 1 si hubo error, 0 si no hubo error
 */
int validarEntero(int* numero, char mensaje[], char mensajeError[], int min, int max);
