#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <iomanip>
using namespace std;

void printArray(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main(){
    ifstream archivo("dataset_random1.txt");
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
        printArray(arr);
        //Termina el temporiazdor
        cout << "Algoritmo 'sort' estandar de la biblioteca 'algorithm' de C++" << endl;
        cout << "------------------------------------------------------------------------" << endl; 
        cout << fixed << setprecision(3);
        cout << "El tiempo de ejecución fue de: " << duration.count() << "segundos" << endl;
    }else{
        cout << "No se pudo abrir el archivo para leer." << endl;
    }
}