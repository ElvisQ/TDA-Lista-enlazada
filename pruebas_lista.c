#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "testing.h"

/* ******************************************************************
 *                  FUNCION PARA ITERADOR INTERNO
 * *****************************************************************/

bool sumar(void* dato, void* suma) {
	*(int*)suma += *(int*)dato;
	return true;
}


bool imprimir(void* dato, void* corte) {
	if (*(int*)corte == 4) {
		return false;
	}
	printf("%d  ", *(int*)dato);
	(*(int*)corte)++;
	return true;

}
/* *****************************************************************/
static void pruebas_lista_vacia() {
	printf("\nINICIO DE PRUEBAS CON LISTA VACIA\n");

	lista_t* lista = lista_crear();

	print_test("Crear lista", lista != NULL);
	print_test("Lista esta vacia", lista_esta_vacia(lista));
	print_test("Lista ver primero devuelve NULL", lista_ver_primero(lista) == NULL);
	print_test("Lista ver ultimo devuelve NULL", lista_ver_ultimo(lista) == NULL);
	print_test("Largo de la lista es 0", lista_largo(lista) == 0);
	print_test("Lista borrar primero devuelve NULL", lista_borrar_primero(lista) == NULL);

	lista_destruir(lista, NULL);
}

static void pruebas_lista_null() {
	printf("\nINICIO DE PRUEBAS CON NULL\n");

	lista_t* lista = lista_crear();

	print_test("Se puede insertar al primero NULL", lista_insertar_primero(lista, NULL));
	print_test("Lista no esta vacia", !lista_esta_vacia(lista));
	print_test("Largo de la lista es 1", lista_largo(lista) == 1);
	print_test("El primero es NULL", lista_ver_primero(lista) == NULL);
	print_test("El ultimo es NULL", lista_ver_ultimo(lista) == NULL);
	print_test("Se puede insertar al ultimo NULL", lista_insertar_ultimo(lista, NULL));
	print_test("Se puede insertar al primero NULL", lista_insertar_primero(lista, NULL));
	print_test("Se puede insertar al ultimo NULL", lista_insertar_ultimo(lista, NULL));
	print_test("El primero es NULL", lista_ver_primero(lista) == NULL);
	print_test("El ultimo es NULL", lista_ver_ultimo(lista) == NULL);
	print_test("Largo de la lista es 4", lista_largo(lista) == 4);
	print_test("Se borra el primer NULL", lista_borrar_primero(lista) == NULL);

	lista_destruir(lista, NULL);
}

static void pruebas_lista_un_elemento() {
	printf("\nINICIO DE PRUEBAS CON 1 ELEMENTO\n");

	lista_t* lista = lista_crear();
	int elem1 = 1;
	int elem2 = 2;

	print_test("Se puede insertar primero al 1", lista_insertar_primero(lista, &elem1));
	print_test("Largo de la lista es 1", lista_largo(lista) == 1);
	print_test("La lista ya no esta vacia", !lista_esta_vacia(lista));
	print_test("Largo de la lista es 1", lista_largo(lista) == 1);
	print_test("Lista ver primero devuelve 1", lista_ver_primero(lista) == &elem1);
	print_test("Largo es 1", lista_largo(lista) == 1);
	print_test("Lista ver ultimo devuleve 1", lista_ver_ultimo(lista) == &elem1);
	print_test("Lista borrar devuelve 1", lista_borrar_primero(lista) == &elem1);
	print_test("Lista vuelve a estar vacia", lista_esta_vacia(lista));
	print_test("Largo es 0", lista_largo(lista) == 0);

	print_test("Se puede insertar ultimo al 2", lista_insertar_ultimo(lista, &elem2));
	print_test("Largo es 1", lista_largo(lista) == 1);
	print_test("La lista ya no esta vacia", !lista_esta_vacia(lista));
	print_test("Lista ver ultimo devuleve 2", lista_ver_ultimo(lista) == &elem2);
	print_test("Largo 1", lista_largo(lista) == 1);
	print_test("Lista ver primero devuelve 2", lista_ver_primero(lista) == &elem2);
	print_test("Lista borrar devuelve 2", lista_borrar_primero(lista) == &elem2);

	lista_destruir(lista, NULL);
}

static void pruebas_lista_insertar_borrar() {
	printf("\nINICIO DE PRUEBAS DE INSERTAR Y BORRAR\n");

	lista_t* lista = lista_crear();
	int elem1 = 1;
	int elem2 = 2;
	int elem3 = 3;
	int elem4 = 4;
	int elem5 = 5;
	char elemA = 'A';
	char elemB = 'B';

	print_test("Lista insertar primero al 2", lista_insertar_primero(lista, &elem2));
	print_test("Lista insertar primero al 3", lista_insertar_primero(lista, &elem3));
	print_test("Lista ver primero devuelve 3", lista_ver_primero(lista) == &elem3);
	print_test("Lista ver ultimo devuleve 2", lista_ver_ultimo(lista) == &elem2);
	print_test("Largo es 2", lista_largo(lista) == 2);
	print_test("Lista borrar devuelve 3", lista_borrar_primero(lista) == &elem3);
	print_test("La lista no esta vacia", !lista_esta_vacia(lista));
	print_test("Lista borrar devuelve 2", lista_borrar_primero(lista) == &elem2);

	print_test("Lista insertar ultimo al 3", lista_insertar_ultimo(lista, &elem3));
	print_test("Lista insertar ultimo al 4", lista_insertar_ultimo(lista, &elem4));
	print_test("Lista ver primero devuelve 3", lista_ver_primero(lista) == &elem3);
	print_test("Lista ver ultimo devuleve 4", lista_ver_ultimo(lista) == &elem4);
	print_test("Lista borrar devuelve 3", lista_borrar_primero(lista) == &elem3);
	print_test("Lista insertar primero al 3", lista_insertar_primero(lista, &elem3));
	print_test("Lista insertar ultimo al 5", lista_insertar_ultimo(lista, &elem5));
	print_test("Lista insertar primero al 2", lista_insertar_primero(lista, &elem2));
	print_test("Lista insertar primero al 1", lista_insertar_primero(lista, &elem1));
	print_test("Largo es 5", lista_largo(lista) == 5);
	print_test("Lista ver primero devuelve 1", lista_ver_primero(lista) == &elem1);
	print_test("Lista ver ultimo devuleve 5", lista_ver_ultimo(lista) == &elem5);
	print_test("Lista borrar devuelve 1", lista_borrar_primero(lista) == &elem1);
	print_test("Lista insertar ultimo al B", lista_insertar_ultimo(lista, &elemB));
	print_test("Lista insertar primero al A", lista_insertar_primero(lista, &elemA));
	print_test("Lista insertar primero al 1", lista_insertar_primero(lista, &elem1));
	print_test("Lista ver primero devuelve 1", lista_ver_primero(lista) == &elem1);
	print_test("Lista ver ultimo devuleve B", lista_ver_ultimo(lista) == &elemB);
	print_test("Lista borrar devuelve 1", lista_borrar_primero(lista) == &elem1);
	print_test("Lista ver primero devuelve A", lista_ver_primero(lista) == &elemA);

	lista_destruir(lista, NULL);
}

static void pruebas_lista_destruir() {
	printf("\nINICIO DE PRUEBAS DE DESTRUIR\n");
	lista_t* lista = lista_crear();
	char* datos1 = malloc(sizeof(char*));
	int* datos2 = malloc(sizeof(int*));
	printf("\nENLISTAR DATOS\n");
	print_test("La lista esta vacia", lista_esta_vacia(lista));
	print_test("Insertar datos1 en la lista", lista_insertar_primero(lista,datos1));
	print_test("Insertar datos2 en la lista",lista_insertar_primero(lista,datos2));
	print_test("Ver ultimo es datos1",lista_ver_ultimo(lista) == datos1);
	print_test("Ver primero es datos2",lista_ver_primero(lista) == datos2);
	lista_destruir(lista,free);
	print_test("La lista fue destruida junto a sus datos", true);
}

static void pruebas_de_volumen(size_t tam) {
	printf("\nINICIO DE PRUEBAS DE VOLUMEN (%li elementos)\n", tam);

	lista_t* lista = lista_crear();

	bool ok = true;
	size_t i;
	int* vector = malloc(tam * sizeof(int));
	if (vector == NULL) {
		lista_destruir(lista, NULL);
		printf("\nNo se pueden hacer las pruebas con esa cantidad de elementos\n");
		return;
	} 

	for (i = 0; i < tam; i++) {
		ok &= lista_insertar_primero(lista, &vector[i]);
	}

	i--;
	print_test("Se pudieron insertar_primero los elementos", ok);
	print_test("El primero es el correcto", lista_ver_primero(lista) == &vector[i]);
	print_test("El ultimo es el correcto", lista_ver_ultimo(lista) == &vector[0]);
	print_test("El largo es el correcto", lista_largo(lista) == tam);

	ok = true;

	for (i = tam-1; i > 0; i--) {
		ok &= (lista_borrar_primero(lista) == &vector[i]);
	}
	ok &= (lista_borrar_primero(lista) == &vector[i]);
	
	print_test("Se pudieron borrar los elementos", ok);
	print_test("La lista queda vacia", lista_esta_vacia(lista));
	print_test("Largo es 0", lista_largo(lista) == 0);

	for (i = 0; i < tam; i++) {
		ok &= lista_insertar_ultimo(lista, &vector[i]);
	}

	i--;
	print_test("Se pudieron insertar_ultimo los elementos", ok);
	print_test("El primero es el correcto", lista_ver_primero(lista) == &vector[0]);
	print_test("El ultimo es el correcto", lista_ver_ultimo(lista) == &vector[i]);
	print_test("El largo es el correcto", lista_largo(lista) == tam);

	ok = true;

	for (i = 0; i < tam; i++) {
		ok &= (lista_borrar_primero(lista) == &vector[i]);
	}
	
	print_test("Se pudieron borrar los elementos", ok);
	print_test("La lista queda vacia", lista_esta_vacia(lista));
	print_test("Largo es 0", lista_largo(lista) == 0);

	free(vector);
	lista_destruir(lista, NULL);
}

static void pruebas_iterador_interno(void) {
	printf("\nINICIO DE PRUEBAS CON ITERADOR INTERNO\n");
	lista_t* lista = lista_crear();
	int numeros[10] = {4,6,12,16,19,29,36,54,60,79};
	for (int i = 0; i < 10; i++) {
		lista_insertar_ultimo(lista,&numeros[i]);
	}
	print_test("El largo es 10", lista_largo(lista) == 10);
	print_test("El primer elemento es 4", lista_ver_primero(lista) == &numeros[0]);
	print_test("El ultimo elemento es 79", lista_ver_ultimo(lista) == &numeros[9]);
	printf("Itero la lista\n");
	int suma = 0;
	lista_iterar(lista, sumar, &suma);
	print_test("La suma es 315", suma == 315);
	printf("%d",suma);
	printf("\nINICIO DE PRUEBAS CON ITERADOR INTERNO CON CORTE\n");
	int contador = 0;
	lista_iterar(lista,imprimir,&contador);
	
	lista_destruir(lista,NULL);
}

static void pruebas_iter_externo_avanzar_y_ver() {
	printf("\nINICIO DE PRUEBAS CON ITERADOR EXTERNO\n");
	lista_t* lista = lista_crear();
	char letras[5] = {'a','b','c','d','e'};
	for (int i = 0; i < 5; i++) {
		lista_insertar_ultimo(lista, &letras[i]);
	}
	printf("PRUEBA CREAR\n");
	lista_iter_t* iter = lista_iter_crear(lista);
	print_test("El iterador fue creado",iter != NULL);
	printf("\nPRUEBAS DE VER ACTUAL Y AVANZAR\n");
	print_test("El iterador apunta actualmente a 'a'",lista_iter_ver_actual(iter) == &letras[0]);
	print_test("El iterador avanzó", lista_iter_avanzar(iter));
	print_test("El iterador apunta actualmente a 'b'",lista_iter_ver_actual(iter) == &letras[1]);
	print_test("El iterador avanzó", lista_iter_avanzar(iter));
	print_test("El iterador apunta actualmente a 'c'",lista_iter_ver_actual(iter) == &letras[2]);
	print_test("El iterador avanzó", lista_iter_avanzar(iter));
	print_test("El iterador apunta actualmente a 'd'",lista_iter_ver_actual(iter) == &letras[3]);
	print_test("El iterador avanzó", lista_iter_avanzar(iter));
	print_test("El iterador apunta actualmente a 'e'",lista_iter_ver_actual(iter) == &letras[4]);
	print_test("El iterador avanzó", lista_iter_avanzar(iter));
	print_test("El iterador se encuentra en el final de la lista",lista_iter_al_final(iter));
	printf("\nDESTRUIR EL ITERADOR\n");
	lista_iter_destruir(iter);
	print_test("El iterador fue destruido",true);
	lista_destruir(lista, NULL);
	print_test("La lista fue destruida", true);
}

static void pruebas_iter_externo_destruir() {
	printf("\nBORRAR ELEMENTOS DE LA LISTA\n");
	lista_t* lista = lista_crear();
	print_test("La lista fue creada",lista != NULL);
	char elementos[6] = {'a','b','c','d','e','f'};
	
	for (int i = 0; i < 6; i++) {
		lista_insertar_ultimo(lista, &elementos[i]);
	}
	lista_iter_t* iter = lista_iter_crear(lista);
	print_test("El iterador fue creado",iter != NULL);
	print_test("El largo de la lista es 6",lista_largo(lista) == 6);
	print_test("El iterador apunta actualmente a 'a'",lista_iter_ver_actual(iter) == &elementos[0]);

	printf("\nBORRAR PRIMER ELEMENTO\n");
	print_test("Borra el elemento 'a'",lista_iter_borrar(iter) == &elementos[0]);
	print_test("Ahora el actual es 'b'", lista_iter_ver_actual(iter) == &elementos[1]);
	print_test("El primero de la lista pasa a ser b",lista_ver_primero(lista) == &elementos[1]);
	print_test("El largo ahora es 5",lista_largo(lista) == 5);

	printf("\nBORRAR ELEMENTOS MEDIOS\n");
	print_test("Avanzo una posicion",lista_iter_avanzar(iter));
	print_test("Avanzo otra posicion",lista_iter_avanzar(iter));
	print_test("La posicion actual apunta a 'd'", lista_iter_ver_actual(iter) == &elementos[3]);
	print_test("Borrar elemento 'd'",lista_iter_borrar(iter) == &elementos[3] );
	print_test("Ahora el actual es 'e'", lista_iter_ver_actual(iter) == &elementos[4]);
	print_test("El largo de la lista se redujo a 4",lista_largo(lista) == 4);

	printf("\nBORRAR ULTIMO ELEMENTO\n");
	print_test("Avanzo una posicion",lista_iter_avanzar(iter));
	print_test("Ahora el iterador apunta a 'f'",lista_iter_ver_actual(iter) == &elementos[5]);
	print_test("Borrar ultimo elemento", lista_iter_borrar(iter) == &elementos[5]);
	print_test("Ahora el iterador apunta a Null", lista_iter_ver_actual(iter) == NULL);
	print_test("El ultimo de la lista quedo como 'e'", lista_ver_ultimo(lista) == &elementos[4]);
	print_test("El largo de la lista se redujo a 3",lista_largo(lista) == 3);
	
	lista_iter_destruir(iter);
	print_test("El iterador fue destruido",true);
	lista_destruir(lista, NULL);
	print_test("La lista fue destruida", true);

}

static void pruebas_iter_insertar() {
	printf("\nPRUEBAS DE INSERTAR ELEMENTOS CON EL ITERADOR\n");
	lista_t* lista = lista_crear();
	char letras[5] = {'a','b','c','d','e'};
	char letras_a_insertar[3] = {'z','y','x'};
	for (int i = 0; i < 5; i++) {
		lista_insertar_ultimo(lista, &letras[i]);
	}
	lista_iter_t* iter = lista_iter_crear(lista);
	print_test("El iterador fue creado",iter != NULL);
	print_test("El largo es 5", lista_largo(lista) == 5);

	printf("\nPRUEBAS INSERTAR EN PRIMER POSICION\n");
	print_test("El iterador apunta al elemento 'a'",lista_iter_ver_actual(iter) == &letras[0]);
	print_test("Inserto en la primera posicion la letra 'z'", lista_iter_insertar(iter,&letras_a_insertar[0]));
	print_test("Ahora el iterador apunta a 'z'",lista_iter_ver_actual(iter) == &letras_a_insertar[0]);
	print_test("El largo subio a 6", lista_largo(lista) == 6);
	
	printf("\nPRUEBAS INSERTAR EN CUALQUIER POSICION MEDIA\n");
	print_test("Avanzo 1 posicion",lista_iter_avanzar(iter));
	print_test("Avanzo 1 posicion mas",lista_iter_avanzar(iter));
	print_test("El iterador apunta al elemento 'b'",lista_iter_ver_actual(iter) == &letras[1]);
	print_test("Inserto en la posicion la letra 'y'", lista_iter_insertar(iter,&letras_a_insertar[1]));
	print_test("Ahora el iterador apunta a 'y'", lista_iter_ver_actual(iter) == &letras_a_insertar[1]);
	print_test("El largo subio a 7", lista_largo(lista) == 7);

	printf("\nPRUEBAS INSERTAR EN POSICION FINAL\n");
	while (!lista_iter_al_final(iter)) {
		lista_iter_avanzar(iter);
	}
	print_test("El iterador esta en la posicion final de la lista", lista_iter_al_final(iter));
	print_test("El iterador apunta al elemento NULL",lista_iter_ver_actual(iter) == NULL);
	print_test("Inserto en la posicion la letra 'x'", lista_iter_insertar(iter, &letras_a_insertar[2]));
	print_test("Ahora el iterador apunta a 'x'", lista_iter_ver_actual(iter) == &letras_a_insertar[2]);
	print_test("El largo subio a 8", lista_largo(lista) == 8);
	print_test("El ultimo de la lista es x", lista_ver_ultimo(lista) == &letras_a_insertar[2]);
	print_test("El primero de la lista es z", lista_ver_primero(lista) == &letras_a_insertar[0]);
	lista_iter_destruir(iter);
	lista_destruir(lista, NULL);
	print_test("El iterador y la lista se destruyeron", true);
}

void pruebas_lista_estudiante() {

	pruebas_lista_vacia();
	pruebas_lista_null();
	pruebas_lista_un_elemento();
	pruebas_lista_insertar_borrar();
	pruebas_lista_destruir();
	pruebas_de_volumen(10000);
	pruebas_iterador_interno();
	pruebas_iter_externo_avanzar_y_ver();
	pruebas_iter_externo_destruir();
	pruebas_iter_insertar();
}

#ifndef CORRECTOR  

int main(void) {
    pruebas_lista_estudiante();
    return failure_count() > 0;  
}

#endif
