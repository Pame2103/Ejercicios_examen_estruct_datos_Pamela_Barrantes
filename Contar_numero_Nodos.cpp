##include <iostream>

using namespace std;


struct Nodo {
	int dato;
	Nodo* siguiente;
};

//contar el número de nodos
int contarNodos(Nodo* cabeza) {
	int contador = 0;
	Nodo* actual = cabeza;
	
	
	while (actual != nullptr) {
		contador++;
		actual = actual->siguiente;
	}
	
	return contador;
}

int main() {
	
	Nodo* nodo1 = new Nodo();
	Nodo* nodo2 = new Nodo();
	Nodo* nodo3 = new Nodo();
	
	nodo1->dato = 10;
	nodo1->siguiente = nodo2;
	
	nodo2->dato = 20;
	nodo2->siguiente = nodo3;
	
	nodo3->dato = 30;
	nodo3->siguiente = nullptr;

	cout << "Número de nodos en la lista: " << contarNodos(nodo1) << endl;
	
//liberar memoria 
	delete nodo1;
	delete nodo2;
	delete nodo3;
	
	return 0;
}
