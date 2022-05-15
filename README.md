# TDA-Lista-enlazada

Primitivas de la lista

typedef struct lista lista_t;

lista_t *lista_crear(void);

bool lista_esta_vacia(const lista_t *lista);

bool lista_insertar_primero(lista_t *lista, void *dato);

bool lista_insertar_ultimo(lista_t *lista, void *dato);

void *lista_borrar_primero(lista_t *lista);

void *lista_ver_primero(const lista_t *lista);

void *lista_ver_ultimo(const lista_t* lista);

size_t lista_largo(const lista_t *lista);

void lista_destruir(lista_t *lista, void (*destruir_dato)(void *));

Primitiva del iterador interno

void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra);

Primitivas del iterador externo
typedef struct lista_iter lista_iter_t;

lista_iter_t *lista_iter_crear(lista_t *lista);

bool lista_iter_avanzar(lista_iter_t *iter);

void *lista_iter_ver_actual(const lista_iter_t *iter);

bool lista_iter_al_final(const lista_iter_t *iter);

void lista_iter_destruir(lista_iter_t *iter);

bool lista_iter_insertar(lista_iter_t *iter, void *dato);

void *lista_iter_borrar(lista_iter_t *iter);

Función de pruebas
void pruebas_lista_estudiante(void);

Aclaración: mantener el nombre de la estructura como struct lista para la lista, y struct lista_iter para el iterador, puesto que el corrector automático tiene configurados dichos nombres en el lista.h de la cátedra.

Considerar que todas las primitivas (exceptuando lista_destruir y lista_iterar) deben funcionar en tiempo constante.

Las pruebas deben incluir los casos básicos de TDA similares a los contemplados para la pila y la cola, y adicionalmente debe verificar los siguientes casos del iterador externo:

°Al insertar un elemento en la posición en la que se crea el iterador, efectivamente se inserta al principio.

°Insertar un elemento cuando el iterador está al final efectivamente es equivalente a insertar al final.

°Insertar un elemento en el medio se hace en la posición correcta.

°Al remover el elemento cuando se crea el iterador, cambia el primer elemento de la lista.

°Remover el último elemento con el iterador cambia el último de la lista.

°Verificar que al remover un elemento del medio, este no está.

°Otros casos borde que pueden encontrarse al utilizar el iterador externo. Y los casos con / sin corte del iterador interno.
