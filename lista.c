#include <stdlib.h>
#include "lista.h"

/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

typedef struct nodo nodo_t;
struct nodo {
	void* dato;
	nodo_t* prox;
};

typedef struct lista lista_t;
struct lista {
	nodo_t* primero;
	nodo_t* ultimo;
	size_t largo;
};

typedef struct lista_iter lista_iter_t;
struct lista_iter {
	nodo_t* actual;
	nodo_t* anterior;
	lista_t* lista_a_iterar;
};

/* ******************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/

lista_t *lista_crear(void) {
	lista_t* lista = malloc(sizeof(lista_t));
	if (lista == NULL) return NULL;
	lista->primero = NULL;
	lista->ultimo = NULL;
	lista->largo = 0;
	return lista;
}

bool lista_esta_vacia(const lista_t *lista) {
	return (lista->largo == 0);
}

nodo_t* crear_nodo (void *valor) {
	nodo_t* nodo = malloc(sizeof(nodo_t));
	if (nodo == NULL) return NULL;
	nodo->dato = valor;
	nodo->prox = NULL;
	return nodo;
}

bool lista_insertar_primero(lista_t *lista, void *dato) {
	nodo_t* nodo = crear_nodo(dato);
	if (nodo == NULL) return false;

	if (lista_esta_vacia(lista)) {
		lista->ultimo = nodo;
	} else {
		nodo->prox = lista->primero;
	}

	lista->primero = nodo;
	lista->largo ++;

	return true;
}

bool lista_insertar_ultimo(lista_t *lista, void *dato) {
	nodo_t* nodo = crear_nodo(dato);
	if (nodo == NULL) return false;

	if (lista_esta_vacia(lista)) {
		lista->primero = nodo;
	} else {
		lista->ultimo->prox = nodo;
	}

	lista->ultimo = nodo;
	lista->largo ++;

	return true;
}

void *lista_borrar_primero(lista_t*lista) {
	if (lista_esta_vacia(lista)) return NULL;

	void* dato = lista->primero->dato;
	nodo_t* primero = lista->primero;
	lista->primero = primero->prox;
	free(primero);
	lista->largo --;
	if(lista_esta_vacia(lista)) {
        lista->ultimo = NULL;
		
	}
	return dato;
}

void *lista_ver_primero(const lista_t *lista) {
	return (lista_esta_vacia(lista))? NULL : lista->primero->dato;
}

void *lista_ver_ultimo(const lista_t *lista) {
	return (lista_esta_vacia(lista))? NULL : lista->ultimo->dato;
}

size_t lista_largo(const lista_t *lista) {
	return lista->largo;
}

void lista_destruir(lista_t *lista, void (*destruir_dato)(void *)) {
	while (!lista_esta_vacia(lista)) {
		void* dato = lista_borrar_primero(lista);
		if (destruir_dato) {
			destruir_dato(dato);
		}
	}
	free(lista);
}

/* ******************************************************************
 *                    PRIMITIVAS DEL ITERADOR INTERNO
 * *****************************************************************/

void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra) {
	nodo_t* i = lista->primero;
	while (i != NULL) {
		if (!visitar(i->dato, extra)) {
			return;
		}
		i = i->prox;
	}
}

 /* ******************************************************************
 *                    PRIMITIVAS DEL ITERADOR EXTERNO
 * *****************************************************************/

lista_iter_t *lista_iter_crear(lista_t *lista) {
	lista_iter_t* iter = malloc(sizeof(lista_iter_t));
	if (iter == NULL) return NULL;
	iter->anterior = NULL;
	iter->actual = lista->primero;
	iter->lista_a_iterar = lista;
	return iter;
}

bool lista_iter_avanzar(lista_iter_t *iter) {
	if (lista_iter_al_final(iter)) return false;
	iter->anterior = iter->actual;
	iter->actual = iter->actual->prox;
	return true;
}

void *lista_iter_ver_actual(const lista_iter_t *iter) {
	return (iter->actual == NULL)? NULL : iter->actual->dato;
}

bool lista_iter_al_final(const lista_iter_t *iter) {
	return (iter->actual == NULL);
}

void lista_iter_destruir(lista_iter_t *iter) {
	free(iter);
}

bool lista_iter_insertar(lista_iter_t *iter, void *dato) {	
	nodo_t* nodo_a_insertar = crear_nodo(dato);
	if (nodo_a_insertar == NULL) return false;

	nodo_a_insertar->prox = iter->actual;
	if (lista_esta_vacia(iter->lista_a_iterar)) {
		iter->lista_a_iterar->ultimo = nodo_a_insertar;
		iter->lista_a_iterar->primero = nodo_a_insertar;
	} else if (iter->anterior == NULL) {
		iter->lista_a_iterar->primero = nodo_a_insertar;
	} else if (lista_iter_al_final(iter)) {
		iter->lista_a_iterar->ultimo = nodo_a_insertar;
		iter->anterior->prox = nodo_a_insertar;
	} else {
		iter->anterior->prox = nodo_a_insertar;
	}
	iter->actual = nodo_a_insertar;
	iter->lista_a_iterar->largo ++;
	return true;
}

void *lista_iter_borrar(lista_iter_t *iter) {
	if(lista_iter_al_final(iter)) return NULL;
    if(iter->anterior == NULL) {
        iter->actual = iter->actual->prox;
        void* prim = lista_borrar_primero(iter->lista_a_iterar);
		return prim;
    }
	nodo_t* nodo_proximo = iter->actual->prox;
	if(nodo_proximo == NULL) {
        iter->lista_a_iterar->ultimo = iter->anterior;
	}

    void* dato = iter->actual->dato;
	free(iter->actual);
    iter->actual = nodo_proximo;
    iter->anterior->prox = nodo_proximo;
    iter->lista_a_iterar->largo--;
	
    return dato;
}
