#include <iostream>
using namespace std;

// Estructura del nodo Empleado
struct Empleado {
	int idEmpleado;
	int horasTrabajadas;
	Empleado *Sig;
};

// Función para sumar las horas trabajadas por empleados con el mismo ID
Empleado* sumarHorasTrabajadas(Empleado* cabeza) {
	Empleado* nuevaCabeza = nullptr; // Nueva lista consolidada
	Empleado* ultimo = nullptr;      // Apuntador al último nodo de la nueva lista
	
	Empleado* actual = cabeza;       // Recorrer la lista original
	while (actual != nullptr) {
		// Buscar si el empleado ya está en la nueva lista
		Empleado* temp = nuevaCabeza;
		while (temp != nullptr && temp->idEmpleado != actual->idEmpleado) {
			temp = temp->Sig;
		}
		
		if (temp == nullptr) {
			// Si no está, crear un nuevo nodo y añadirlo a la nueva lista
			Empleado* nuevoNodo = new Empleado{actual->idEmpleado, actual->horasTrabajadas, nullptr};
			
			if (nuevaCabeza == nullptr) {
				nuevaCabeza = nuevoNodo; // Primer nodo de la nueva lista
			} else {
				ultimo->Sig = nuevoNodo; // Añadir al final
			}
			ultimo = nuevoNodo; // Actualizar el último nodo
			
		} else {
			// Si ya está, sumar las horas trabajadas
			temp->horasTrabajadas += actual->horasTrabajadas;
		}
		
		actual = actual->Sig; // Avanzar al siguiente nodo
	}
	
	return nuevaCabeza; // Retornar la cabeza de la nueva lista
}

// Función para mostrar la lista
void mostrarLista(Empleado* cabeza) {
	Empleado* actual = cabeza;
	while (actual != nullptr) {
		cout << "ID Empleado: " << actual->idEmpleado << ", Horas Trabajadas: " << actual->horasTrabajadas << endl;
		actual = actual->Sig;
	}
}

// Ejemplo de uso
int main() {
	// Crear algunos nodos de ejemplo
	Empleado* e1 = new Empleado{1, 8, nullptr};
	Empleado* e2 = new Empleado{2, 6, nullptr};
	Empleado* e3 = new Empleado{1, 5, nullptr};  // Mismo ID que e1
	Empleado* e4 = new Empleado{3, 7, nullptr};
	
	// Enlazar nodos para formar la lista
	e1->Sig = e2;
	e2->Sig = e3;
	e3->Sig = e4;
	
	// Mostrar lista original
	cout << "Lista original:" << endl;
	mostrarLista(e1);
	
	// Sumar horas y obtener la nueva lista consolidada
	Empleado* listaConsolidada = sumarHorasTrabajadas(e1);
	
	// Mostrar la lista consolidada
	cout << "\nLista consolidada:" << endl;
	mostrarLista(listaConsolidada);
	
	return 0;
}
