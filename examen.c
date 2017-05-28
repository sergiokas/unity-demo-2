#include "examen.h"
#include "stdlib.h"

int contar_nodos(nodo_t* H) {
	int c;
	for(c=0; H; c++,H=H->sig);
	return c;
}

nodo_t* ultimo_nodo(nodo_t* H) {
	if (!H) return H;
	while(H->sig) {
		H = H->sig;
	}
	return H;
}

nodo_t* crear_nodo(int d) {
	nodo_t * n;
	n = malloc(sizeof(nodo_t));
	n->d = d;
	n->sig = NULL;
	return n;
}

nodo_t* agregar_nodo(nodo_t** H, int d) {
	nodo_t* n;
	nodo_t* u;

	n = crear_nodo(d);
	u = ultimo_nodo(*H);

	if(!u) {
		*H = n;
	}
	else {
		u->sig = n;
	}

	return n;
}

