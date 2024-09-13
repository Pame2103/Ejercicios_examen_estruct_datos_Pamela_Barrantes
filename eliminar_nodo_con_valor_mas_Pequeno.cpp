#include <iostream>

using namespace std;

// Definici�n de un nodo de la lista enlazada
struct Nodo {
	int dato;          // Valor del nodo
	Nodo* siguiente;   // Puntero al siguiente nodo
	
	Nodo(int valor) : dato(valor), siguiente(nullptr) {} // Constructor del nodo
};

// Funci�n para insertar un nodo al final de la lista
void insertarAlFinal(Nodo*& cabeza, int valor) {
	Nodo* nuevoNodo = new Nodo(valor); // Crear un nuevo nodo con el valor dado
	
	// Si la lista est� vac�a, el nuevo nodo es la cabeza
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

// Funci�n para imprimir los elementos de la lista enlazada
void imprimirLista(Nodo* cabeza) {
	Nodo* actual = cabeza;
	while (actual != nullptr) {
		cout << actual->dato << " -> ";
		actual = actual->siguiente;
	}
	cout << "nullptr" << endl;
}

// Funci�n para eliminar el nodo con el valor m�s peque�o
void eliminarNodoMinimo(Nodo*& cabeza) {
	// Si la lista est� vac�a, no hacer nada
	if (cabeza == nullptr) {
		return;
	}
	
	Nodo* actual = cabeza;       // Puntero para recorrer la lista
	Nodo* nodoMin = cabeza;      // Puntero al nodo con el valor m�nimo
	Nodo* anterior = nullptr;    // Puntero al nodo anterior al nodo actual
	Nodo* anteriorMin = nullptr; // Puntero al nodo anterior al nodo con el valor m�nimo
	
	// Buscar el nodo con el valor m�s peque�o
	while (actual != nullptr) {
		if (actual->dato < nodoMin->dato) {
			nodoMin = actual;        // Actualizar el nodo con el valor m�nimo
			anteriorMin = anterior;  // Actualizar el puntero al nodo anterior al m�nimo
		}
		anterior = actual;
		actual = actual->siguiente;
	}
	
	// Eliminar el nodo con el valor m�nimo
	if (nodoMin == cabeza) {
		cabeza = cabeza->siguiente; // Si el m�nimo es la cabeza, mover la cabeza
	} else {
		anteriorMin->siguiente = nodoMin->siguiente; // Saltar el nodo m�nimo
	}
	
	delete nodoMin; // Liberar la memoria del nodo eliminado
}

int main() {
	Nodo* lista = nullptr; // Crear una lista enlazada vac�a
	
	// Insertar elementos en la lista
	insertarAlFinal(lista, 4);
	insertarAlFinal(lista, 2);
	insertarAlFinal(lista, 7);
	insertarAlFinal(lista, 2);
	insertarAlFinal(lista, 5);
	
	// Imprimir la lista original
	cout << "Lista original: ";
	imprimirLista(lista);
	
	// Eliminar el nodo con el valor m�nimo
	eliminarNodoMinimo(lista);
	
	// Imprimir la lista despu�s de eliminar el nodo m�nimo
	cout << "Lista despu�s de eliminar el nodo con el valor m�nimo: ";
	imprimirLista(lista);
	
	return 0;
}
