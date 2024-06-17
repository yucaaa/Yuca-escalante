// METODO DE ORDENAMIENTO QUICK SORT
#include <iostream>
using namespace std;

// Función para realizar la partición del arreglo
int parti(int arreglo[], int bajo, int alto) {
	int pivote = arreglo[alto]; // Selecciona el último elemento como pivote
	int i = (bajo - 1); // Índice del elemento más pequeño
	
	// Recorre desde el primer elemento hasta el penúltimo
	for (int j = bajo; j <= alto - 1; j++) {
		// Si el elemento actual es menor que el pivote
		if (arreglo[j] < pivote) {
			i++; // Incrementa el índice del elemento más pequeño
			swap(arreglo[i], arreglo[j]); // Intercambia arr[i] y arr[j]
		}
	}
	swap(arreglo[i + 1], arreglo[alto]); // Final se coloca el pivote en la posición correcta
	return (i + 1); // Retorna el índice del pivote
}

// Función principal del algoritmo Quick Sort
void quickSort(int arreglo[], int bajo, int alto) {
	if (bajo < alto) {
		int pi = parti(arreglo, bajo, alto); // Obtiene el índice del pivote
		
		// Ordena recursivamente los elementos antes y después de la partición
		quickSort(arreglo, bajo, pi - 1); // Ordena el subarreglo antes del pivote
		quickSort(arreglo, pi + 1, alto); // Ordena el subarreglo después del pivote
	}
}

// Función principal del programa
int main() {
	int n;
	cout << "Ingrese la cantidad de números a ordenar: ";
	cin >> n; // Lee la cantidad de números a ordenar
	int arreglo[100]; // Declara un arreglo de tamaño máximo 100
	
	// Lee los elementos del arreglo ingresados por el usuario
	for (int i = 0; i < n; ++i) {
		cout << "Ingrese el número en la posicion " << i + 1 << ": ";
		cin >> arreglo[i];
	}
	
	// Llama a la función quickSort para ordenar el arreglo
	quickSort(arreglo, 0, n - 1);
	// arreglo = es el nombre del arreglo que se desea ordenar 
	// 0 = es el primer elemento del arreglo
	// n = es la cantidad total de elementos en el arreglo
	// Luego se resta -1 a n para obtener el ultimo elemento del arreglo 
	
	// Imprime el arreglo ordenado
	cout << "El Arreglo ordenado: ";
	for (int i = 0; i < n; ++i) {
		cout << arreglo[i] << " ";
	}
	cout << endl;
	return 0; // Retorna 0 para indicar que el programa finalizó correctamente
}
