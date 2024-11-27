// Dynamic array.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <iostream>
using namespace std;

// Función para insertar un número en el array manteniendo el orden
void insertarOrdenado(int*& array, int& tamano, int numero) {
    // Crear un nuevo array con espacio adicional (+1)
    int* nuevoArray = new int[tamano + 1];

    // Insertar elementos del array antiguo en el nuevo, manteniendo el orden
    int i = 0, j = 0;
    bool insertado = false; // Bandera para verificar si el número se ha insertado
    while (i < tamano) {
        // Insertar el nuevo número en su posición correcta
        if (!insertado && numero < array[i]) {
            nuevoArray[j++] = numero; // Insertar el número
            insertado = true;
        }
        // Copiar el resto de elementos
        nuevoArray[j++] = array[i++];
    }

    // Si el número es mayor que todos, se inserta al final
    if (!insertado) {
        nuevoArray[j] = numero;
    }

    // Liberar la memoria del array antiguo
    delete[] array;

    // Actualizar el puntero al nuevo array y su tamaño
    array = nuevoArray;
    tamano++;
}

int main() {
    int* array = nullptr; // Puntero al array dinámico
    int tamano = 0;       // Tamaño actual del array
    int numero;

    cout << "Introduce numeros (escribe -1 para terminar): " << endl;
    while (true) {
        cin >> numero;

        // Salir del bucle si el usuario introduce -1
        if (numero == -1) {
            break;
        }

        // Insertar el número en el array manteniendo el orden
        insertarOrdenado(array, tamano, numero);

        // Imprimir el array actualizado
        cout << "Array actual: ";
        for (int i = 0; i < tamano; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // Liberar la memoria al final del programa
    delete[] array;

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
