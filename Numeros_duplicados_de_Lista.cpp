#include <iostream>
#include <vector>

void eliminarDuplicados(std::vector<int>& listaNumeros) {
	// Declaraci�n de variables
	int indiceActual;
	int indiceComparacion;
	
	// Bucle para recorrer la lista y eliminar duplicados
	for (indiceActual = 0; indiceActual < listaNumeros.size(); ++indiceActual) {
		for (indiceComparacion = indiceActual + 1; indiceComparacion < listaNumeros.size(); ++indiceComparacion) {
			// Si se encuentra un duplicado, se elimina
			if (listaNumeros[indiceActual] == listaNumeros[indiceComparacion]) {
				listaNumeros.erase(listaNumeros.begin() + indiceComparacion);
				indiceComparacion--; // Ajustar el �ndice para seguir comprobando correctamente
			}
		}
	}
}

int main() {
	// Declaraci�n y inicializaci�n de la lista de n�meros
	std::vector<int> listaNumeros = {1, 2, 2, 3, 4, 4, 5, 5, 6}; 
	
	// Llamada a la funci�n para eliminar duplicados
	eliminarDuplicados(listaNumeros);
	
	// Imprimir la lista sin duplicados
	std::cout << "Lista sin duplicados: ";
	for (int i = 0; i < listaNumeros.size(); i++) {
		std::cout << listaNumeros[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
