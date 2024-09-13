#include <iostream>

using namespace std;

// Definición de un nodo de la lista enlazada
struct Nodo {
	int dato;          // Valor del nodo
	Nodo* siguiente;   // Puntero al siguiente nodo
	
	Nodo(int valor) : dato(valor), siguiente(nullptr) {} // Constructor
};

// Función para insertar un nodo al final de la lista
void insertarAlFinal(Nodo*& cabeza, int valor) {
	Nodo* nuevoNodo = new Nodo(valor); // Crear un nuevo nodo con el valor dado
	
	// Si la lista está vacía, el nuevo nodo es la cabeza
	if (cabeza == nullptr) {
		cabeza = nuevoNodo;
		return;
	}
	
	Nodo* actual = cabeza; // Puntero para recorrer la lista
	while (actual->siguiente != nullptr) {
		actual = actual->siguiente;
	}
	
	actual->siguiente = nuevoNodo; // Insertar el nuevo nodo al final
}

// Función para imprimir los elementos de la lista enlazada
void imprimirLista(Nodo* cabeza) {
	Nodo* actual = cabeza;
	while (actual != nullptr) {
		cout << actual->dato << " -> ";
		actual = actual->siguiente;
	}
	cout << "nullptr" << endl;
}

// Función para intercalar dos listas enlazadas
Nodo* intercalarListas(Nodo* cabeza1, Nodo* cabeza2) {
	Nodo* resultado = nullptr;    // Nueva lista resultante
	Nodo* actual1 = cabeza1;      // Puntero para recorrer la primera lista
	Nodo* actual2 = cabeza2;      // Puntero para recorrer la segunda lista
	Nodo** tail = &resultado;     // Puntero al último nodo de la lista resultante
	
	// Intercalar nodos mientras ambas listas tengan elementos
	while (actual1 != nullptr && actual2 != nullptr) {
		*tail = actual1;            // Añadir nodo de la primera lista
		actual1 = actual1->siguiente; // Avanzar en la primera lista
		tail = &((*tail)->siguiente); // Mover el puntero tail al siguiente nodo
		
		*tail = actual2;            // Añadir nodo de la segunda lista
		actual2 = actual2->siguiente; // Avanzar en la segunda lista
		tail = &((*tail)->siguiente); // Mover el puntero tail al siguiente nodo
	}
	
	// Añadir los nodos restantes de la lista más larga
	if (actual1 != nullptr) {
		*tail = actual1;
	} else if (actual2 != nullptr) {
		*tail = actual2;
	}
	
	return resultado; // Devolver la cabeza de la lista intercalada
}

int main() {
	Nodo* lista1 = nullptr; // Primera lista enlazada
	Nodo* lista2 = nullptr; // Segunda lista enlazada
	
	// Insertar elementos en la primera lista
	insertarAlFinal(lista1, 1);
	insertarAlFinal(lista1, 3);
	insertarAlFinal(lista1, 5);
	
	// Insertar elementos en la segunda lista
	insertarAlFinal(lista2, 2);
	insertarAlFinal(lista2, 4);
	insertarAlFinal(lista2, 6);
	insertarAlFinal(lista2, 8);
	
	// Imprimir las listas originales
	cout << "Lista 1: ";
	imprimirLista(lista1);
	
	cout << "Lista 2: ";
	imprimirLista(lista2);
	
	// Intercalar las listas
	Nodo* listaIntercalada = intercalarListas(lista1, lista2);
	
	// Imprimir la lista intercalada
	cout << "Lista Intercalada: ";
	imprimirLista(listaIntercalada);
	
	return 0;
}
