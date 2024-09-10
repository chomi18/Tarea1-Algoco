#include <iostream>
#include <fstream>
#include <random>

int main() {
    int filas1 = 1700;
    int columnas1 = 2500;
    int filas2 = 1700;
    int columnas2 = 2500;
    int min = 1;
    int max = 50;

    // Crear un generador de números aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);

    // Abrir el archivo de salida
    std::ofstream archivo_salida("dataset_rectangular3_tras.txt");

    if(archivo_salida.is_open()) {
        // Escribir dimensiones de la primera matriz
        archivo_salida << filas1 << " " << columnas1 << std::endl;

        // Escribir elementos de la primera matriz
        for(int i = 0; i < filas1; i++) {
            for(int j = 0; j < columnas1; j++) {
                archivo_salida << distr(gen);
                if(j < columnas1 - 1) {
                    archivo_salida << " "; // Separar columnas con un espacio
                }
            }
            archivo_salida << std::endl; // Salto de línea para la siguiente fila
        }

        // Escribir dimensiones de la segunda matriz
        archivo_salida << filas2 << " " << columnas2 << std::endl;

        // Escribir elementos de la segunda matriz
        for(int i = 0; i < filas2; i++) {
            for(int j = 0; j < columnas2; j++) {
                archivo_salida << distr(gen);
                if(j < columnas2 - 1) {
                    archivo_salida << " "; // Separar columnas con un espacio
                }
            }
            archivo_salida << std::endl; // Salto de línea para la siguiente fila
        }

        archivo_salida.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
        return 1;
    }

    return 0;
}