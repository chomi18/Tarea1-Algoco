#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    // Elegir un pivote aleatorio y moverlo al final del array
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[high]); // Mover el pivote al final

    // Posición del elemento más pequeño
    int i = low - 1;

    // Recorrer el array y mover los elementos menores al pivote a la izquierda
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Mover el pivote a su posición final
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi es la posición de la partición
        int pi = partition(arr, low, high);

        // Llamadas recursivas para ordenar los subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void printArray(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
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
        int n = arr.size();

        auto start = chrono::high_resolution_clock::now();

        quickSort(arr, 0, n - 1);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        printArray(arr);
        cout << "Algoritmo 'QuickSort'" << endl;
        cout << "------------------------------------------------------------------------" << endl; 
        cout << fixed << setprecision(3);
        cout << "El tiempo de ejecución fue de: " << duration.count() << "segundos" << endl;
    }else{
        cout << "No se pudo abrir el archivo." << endl;
    }
    return 0;
}