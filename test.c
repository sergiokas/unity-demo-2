#include "examen.h"
#include "unity/unity.h"

void test_lista_vacia(void) {
	nodo_t* H = NULL;
	TEST_ASSERT_NULL(ultimo_nodo(H));
	TEST_ASSERT_EQUAL_INT(contar_nodos(H), 0);
}

void test_crear_nodo(void) {
	nodo_t* n;
	n = crear_nodo(5);
	TEST_ASSERT_NOT_NULL(n);
	TEST_ASSERT_NULL(n->sig);
	TEST_ASSERT_EQUAL(n->d, 5);
}

void test_agregar_nodo(void) {
	nodo_t* H = NULL;
	nodo_t* aux = NULL;

	aux = agregar_nodo(&H, 1);

	// El primer nodo modifica el comienzo de la lista.
	TEST_ASSERT_TRUE(aux==H);
	TEST_ASSERT_EQUAL_INT(contar_nodos(H), 1);

	// El segundo nodo ya no es el comienzo
	aux = agregar_nodo(&H, 33);
	TEST_ASSERT_FALSE(aux==H);
	TEST_ASSERT_EQUAL_INT(contar_nodos(H), 2);
};

void test_contar_nodos(void) {
	nodo_t* H = NULL;

	TEST_ASSERT_EQUAL_INT(contar_nodos(H), 0);
	agregar_nodo(&H, 1);
	TEST_ASSERT_EQUAL_INT(contar_nodos(H), 1);
	agregar_nodo(&H, 14);
	agregar_nodo(&H, 178);
	agregar_nodo(&H, 95);
	agregar_nodo(&H, 67);
	TEST_ASSERT_EQUAL_INT(contar_nodos(H), 5);
	agregar_nodo(&H, 67);
	TEST_ASSERT_EQUAL_INT(contar_nodos(H), 6);
}

void test_ultimo_nodo(void) {
	nodo_t* H = NULL;
	nodo_t* u = NULL;

	agregar_nodo(&H, 1);
	agregar_nodo(&H, 14);
	agregar_nodo(&H, 178);
	agregar_nodo(&H, 95);
	agregar_nodo(&H, 67);
	u = ultimo_nodo(H);

	TEST_ASSERT_NOT_NULL(u);
	TEST_ASSERT_FALSE(u==H);
	TEST_ASSERT_EQUAL_INT(u->d, 67);
	TEST_ASSERT_NULL(u->sig);
};

void test_integracion(void) {
	nodo_t *H = NULL;
	nodo_t *a, *b;
	nodo_t *u = NULL;

	// La lista esta vacia
	u = ultimo_nodo(H);
	TEST_ASSERT_NULL(u);

	// Primer nodo
	agregar_nodo(&H, 11);
	TEST_ASSERT_NOT_NULL(H);
	TEST_ASSERT_EQUAL_INT(contar_nodos(H), 1);
	TEST_ASSERT_EQUAL_INT(H->d, 11);

	// Agrego tros nodos
	agregar_nodo(&H, 22);
	agregar_nodo(&H, 33);
	a = agregar_nodo(&H, 44);
	b = agregar_nodo(&H, 55);
	u = ultimo_nodo(H);

	// Contar desde cualquier posicion
	TEST_ASSERT_EQUAL_INT(contar_nodos(H), 5);
	TEST_ASSERT_EQUAL_INT(contar_nodos(a), 2);
	TEST_ASSERT_EQUAL_INT(contar_nodos(b), 1);
	TEST_ASSERT_EQUAL_INT(contar_nodos(u), 1);

	// Tengo ultimo nodo
	TEST_ASSERT_NOT_NULL(u);

	// El devuelto no es el comienzo
	TEST_ASSERT_FALSE(a==H);
	TEST_ASSERT_FALSE(b==H);

	// El ultimo no es el comienzo
	TEST_ASSERT_FALSE(u==H);

	// Ultimo agregado y ultimo buscado coinciden
	TEST_ASSERT_TRUE(b==u);

	// Los nodos estan bien encadenados
	TEST_ASSERT_TRUE(a->sig==b);
	TEST_ASSERT_FALSE(b->sig==a);

	// El ultimo realmente termina
	TEST_ASSERT_NULL(u->sig);

	// Datos coinciden
	TEST_ASSERT_EQUAL_INT(u->d, 55);
	TEST_ASSERT_EQUAL_INT(a->sig->d, 55);
	TEST_ASSERT_EQUAL_INT(a->d, 44);
};

int main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_lista_vacia);
	RUN_TEST(test_crear_nodo);
	RUN_TEST(test_agregar_nodo);
	RUN_TEST(test_ultimo_nodo);
	RUN_TEST(test_contar_nodos);
	RUN_TEST(test_integracion);
	return UNITY_END();
}

