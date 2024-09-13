#include <iostream>


struct Nodo {
	int dato;
	Nodo* siguiente;
};

//  verificar si la lista enlazada está ordenada descendente
bool estaOrdenadaDescendente(Nodo* cabeza) {
	if (cabeza == nullptr || cabeza->siguiente == nullptr) {
		return true; 	}
	
	Nodo* actual = cabeza;
	while (actual->siguiente != nullptr) {
		if (actual->dato < actual->siguiente->dato) {
			return false; 		}
		actual = actual->siguiente; 
	}
	return true;
}

// Funcion para insertar elementos en la lista enlazada
void insertarNodo(Nodo*& cabeza, int valor) {
	Nodo* nuevo = new Nodo();
	nuevo->dato = valor;
	nuevo->siguiente = cabeza;
	cabeza = nuevo;
}

int main() {
	Nodo* lista = nullptr;
	
	// insertar en forma desendente
	insertarNodo(lista, 1);
	insertarNodo(lista, 2);
	insertarNodo(lista, 3);
	insertarNodo(lista, 4);
	insertarNodo(lista, 5);
	
	// Ver si la lista esta ordenada  descendente
	if (estaOrdenadaDescendente(lista)) {
		std::cout << "La lista está ordenada en forma descendente." << std::endl;
	} else {
		std::cout << "La lista no está ordenada en forma descendente." << std::endl;
	}
	
	return 0;
}
