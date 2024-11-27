// Dynamic array.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <iostream>
using namespace std;

// Función para insertar un número en el array manteniendo el orden
void insertarOrdenado(int*& array, int& tamano, int numero) {
    int* nuevoArray = new int[tamano + 1]; // Crear un nuevo array con espacio adicional
    int i = 0, j = 0;
    bool insertado = false;

    while (i < tamano) {
        if (!insertado && numero < array[i]) { // Insertar número en su posición
            nuevoArray[j++] = numero;
            insertado = true;
        }
        nuevoArray[j++] = array[i++]; // Copiar elementos del array antiguo
    }

    if (!insertado) {
        nuevoArray[j] = numero; // Insertar al final si es el mayor
    }

    delete[] array; // Liberar memoria del array antiguo
    array = nuevoArray;
    tamano++;
}

// Función para ordenar un array
void ordenarArray(int*& array, int tamano) {
    int* nuevoArray = new int[tamano]; // Crear un nuevo array
    for (int i = 0; i < tamano; i++) {
        nuevoArray[i] = array[i]; // Copiar elementos del array original
    }

    // Implementar un simple Bubble Sort
    for (int i = 0; i < tamano - 1; i++) {
        for (int j = 0; j < tamano - i - 1; j++) {
            if (nuevoArray[j] > nuevoArray[j + 1]) {
                // Intercambiar elementos si están desordenados
                int temp = nuevoArray[j];
                nuevoArray[j] = nuevoArray[j + 1];
                nuevoArray[j + 1] = temp;
            }
        }
    }

    delete[] array; // Liberar el array original
    array = nuevoArray; // Reemplazar por el nuevo array ordenado
}

int main() {
    int* array = nullptr; // Puntero al array dinámico
    int tamano = 0;       // Tamano actual del array
    int numero;

    cout << "Introduce numeros (escribe -1 para terminar): " << endl;
    while (true) {
        cin >> numero;

        if (numero == -1) { // Salir si el usuario introduce -1
            break;
        }

        insertarOrdenado(array, tamano, numero);

        cout << "Array actual: ";
        for (int i = 0; i < tamano; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // Ordenar el array antes de terminar
    ordenarArray(array, tamano);

    cout << "Array final ordenado: ";
    for (int i = 0; i < tamano; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array; // Liberar memoria al final del programa
    return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
