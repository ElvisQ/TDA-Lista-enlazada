#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/
struct lista;
typedef struct lista lista_t;

struct lista_iter;
typedef struct lista_iter lista_iter_t;

/* ******************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/

/* 
 * Crea una lista
 * Post: devuelve una nueva lista vacía
 */
lista_t *lista_crear(void);

/*
 * Devuelve verdadero si la lista no tiene elementos, falso en caso contrario.
 * Pre: la lista fue creada.
 */
bool lista_esta_vacia(const lista_t *lista);

/*
 * Inserta un elemento en la primera posicion de la lista
 * Pre: La lista fue creada.
 * Post: Devuelve True si se logro insertar un elemento en la primera posicion, false en caso contrario.
 */
bool lista_insertar_primero(lista_t *lista, void *dato);

/*
 * Inserta un elemento en la ultima posicion de la lista
 * Pre: La lista fue creada
 * Post: Devuelve True si se logro insertar un elemento en la ultima posicion de la lista, false en caso contrario.
 */
bool lista_insertar_ultimo(lista_t *lista, void *dato);

/*
 * Elimina el primer valor de la lista
 * Pre: La lista fue creada
 * Post: Devuelve el valor eliminado.
 */
void *lista_borrar_primero(lista_t*lista);

/*
 * obtiene el valor del primer elemento de la lista.
 * si la lista tiene elementos, se deveulve el valor del primero.
 * si esta vacia devuelve NULL.
 * Pre: la lista fue creada.
 * Post: se devuelve el primer elemento de la lista, cuando no está vacía.
 */
void *lista_ver_primero(const lista_t *lista);

/*
 * obtiene el valor del ultimo elemento de la lista.
 * si la lista tiene elementos, se devuelve el valor del ultimo.
 * si esta vacia devuelve NULL.
 * Pre: la lista fue creada.
 * Post: se devuelve el ultimo elemento de la lista, cuando no está vacía.
 */
void *lista_ver_ultimo(const lista_t *lista);

/*
 * 
 * Pre: La lista fue creada.
 * Post: Retorna el largo de la lista.
 */
size_t lista_largo(const lista_t *lista);

/*
 * Destruye la lista. Si se recibe la funcion destruir_dato por parámetro,
 * para cada uno de los elementos de la lista llama a destruir_dato.
 * Pre: la lista fue creada. destrur_dato es una funcion capaz de destruir
 *      los datos de a lista, o NULL en caso de que no se la utilice.
 * Post: se eliminan todos los elementos de la lista.
 */
void lista_destruir(lista_t *lista, void (*destruir_dato)(void *));

/* ******************************************************************
 *                    PRIMITIVAS DEL ITERADOR INTERNO
 * *****************************************************************/

/*
 * Itera la lista. La funcion visitar tomara los datos de la lista y un extra.
 * Pre: La lista fue Creada
 * Post: Se ejecutara la funcion pasada a cada uno de los elementos de la lista
 */
void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra);

/* ******************************************************************
 *                    PRIMITIVAS DEL ITERADOR EXTERNO
 * *****************************************************************/

/*
 * Crea un iterador externo
 * Post: Devuelve el Iterador
 */
lista_iter_t *lista_iter_crear(lista_t *lista);

/*
 * Avanza el iterador en la lista
 * Pre: El iterador fue creado
 * Post: Retorna true si logro avanzar, false en caso contrario.
 */
bool lista_iter_avanzar(lista_iter_t *iter);

/*
 * Muestra en donde esta parado el iterador
 * Pre: El iterador fue creado
 * Post: Retorna el valor de la posicion actual
 */
void *lista_iter_ver_actual(const lista_iter_t *iter);

/*
 * Verifica si el iterador esta en el final de la lista
 * Pre: El iterador fue creado.
 * Post: Retorna true si el iterador en el final de lista, false en caso contrario
 */
bool lista_iter_al_final(const lista_iter_t *iter);

/*
 * Destruye el iterador
 * Pre: El iterador fue creado
 * Post:
 */
void lista_iter_destruir(lista_iter_t *iter);

/*
 * Inserta un dato en la lista
 * Pre: El iterador fue creado
 * Post: Retorna true si se logro insertar el elemento en la lista, false en caso contrario.
 */
bool lista_iter_insertar(lista_iter_t *iter, void *dato);

/*
 * Borra el elemento donde apunta el iterador de la lista 
 * Pre: El iterador fue creado
 * Post: Retorna el valor eliminado
 */
void *lista_iter_borrar(lista_iter_t *iter);

/* *****************************************************************
 *                      PRUEBAS UNITARIAS
 * *****************************************************************/

/*
 * Realiza pruebas sobre la implementación realizada.
 */
void pruebas_lista_estudiante(void);

#endif // LISTA_H