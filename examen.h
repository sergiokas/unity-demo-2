typedef struct nodo_s {
	int d;
	struct nodo_s * sig;
} nodo_t;

// Crea un nodo vacio con el dato.
nodo_t* crear_nodo(int d);

// Devuelve puntero al ultimo nodo de la lista.
nodo_t* ultimo_nodo(nodo_t* H);

// Agrega nodo en una lista. Devuelve nodo agregado.
nodo_t* agregar_nodo(nodo_t** H, int d);

// Cuenta los nodos en una lista.
int contar_nodos(nodo_t* H);