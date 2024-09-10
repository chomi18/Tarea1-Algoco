#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <fstream>

int main() {
    int min = 1;
    int max = 900000;
    int num_datos = 800000;

    // Crear un generador de números aleatorios una vez
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);

    // Abrir el archivo de salida
    std::ofstream archivo_salida("dataset_order6.txt");

    if(archivo_salida.is_open()){
        // Generar todos los números aleatorios
        std::vector<int> datos;
        datos.reserve(num_datos);
        
        for(int i = 0; i < num_datos; i++) {
            datos.push_back(distr(gen));
        }

        // Ordena el archivo
        std::sort(datos.begin(), datos.end());

        // Escribir todos los números en el archivo
        const int buffer_size = 1000000; // Tamaño del buffer (1 millón de números)
        std::vector<int> buffer;
        buffer.reserve(buffer_size);

        for(int i = 0; i < num_datos; i++) {
            buffer.push_back(datos[i]);

            // Si el buffer está lleno, escribirlo en el archivo
            if(buffer.size() == buffer_size) {
                for(int num : buffer) {
                    archivo_salida << num << " ";
                }
                buffer.clear(); // Vaciar el buffer
            }
        }

        // Escribir cualquier dato restante en el buffer
        for(int num : buffer) {
            archivo_salida << num << " ";
        }

        archivo_salida.close(); // Cerrar el archivo
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
        return 1;
    }
    
    return 0;
}