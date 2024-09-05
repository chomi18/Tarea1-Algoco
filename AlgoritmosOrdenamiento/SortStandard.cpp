#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <iomanip>
using namespace std;

int main(){
    ifstream archivo("dataset_random.txt");
    vector<int> arr;
    if(archivo.is_open()){
        string linea;
        while (getline(archivo, linea)){
            istringstream iss(linea);
            int numero;
            while(iss >> numero){
                arr.push_back(numero);
            }
        }
        archivo.close();
        auto start = chrono::high_resolution_clock::now();

        sort(arr.begin(), arr.end());

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        //Termina el temporiazdor
        cout << "Algoritmo 'sort' estandar de la biblioteca 'algorithm' de C++" << endl;
        cout << "------------------------------------------------------------------------" << endl; 
        cout << fixed << setprecision(3);
        cout << "El tiempo de ejecución fue de: " << duration.count() << "segundos" << endl;
    }else{
        cout << "No se pudo abrir el archivo para leer." << endl;
    }
}