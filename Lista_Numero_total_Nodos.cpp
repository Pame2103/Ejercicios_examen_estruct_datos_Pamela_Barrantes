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

// Funci�n para contar el n�mero de nodos en la lista
int contarNodos(Nodo* cabeza) {
	int contador = 0;         // Inicializar el contador de nodos
	Nodo* actual = cabeza;    // Puntero para recorrer la lista
	
	// Recorrer la lista y contar los nodos
	while (actual != nullptr) {
		contador++;                // Incrementar el contador
		actual = actual->siguiente; // Avanzar al siguiente nodo
	}
	
	return contador; // Devolver el total de nodos
}

int main() {
	Nodo* lista = nullptr; // Crear una lista enlazada vac�a
	
	// Insertar elementos en la lista
	insertarAlFinal(lista, 10);
	insertarAlFinal(lista, 20);
	insertarAlFinal(lista, 30);
	insertarAlFinal(lista, 40);
	
	// Contar y mostrar el n�mero de nodos en la lista
	int totalNodos = contarNodos(lista);
	cout << "La lista contiene " << totalNodos << " nodos." << endl;
	
	return 0;
}
