#include <iostream>
#include <fstream>
#include <random>
#include <vector>

using namespace std;

int main() {
    int min = 1;
    int max = 900000;
    int num_datos = 800000;

    // Crear un generador de números aleatorios una vez
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);

    // Abrir el archivo de salida
    ofstream archivo_salida("dataset_random6.txt");

    if(archivo_salida.is_open()){
        const int buffer_size = 1000000; // Tamaño del buffer (1 millón de números)
        vector<int> buffer;
        buffer.reserve(buffer_size);

        for(int i = 0; i < num_datos; i++) {
            buffer.push_back(distr(gen));

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
        cerr << "No se pudo abrir el archivo para escribir." << endl;
        return 1;
    }
    
    return 0;
}