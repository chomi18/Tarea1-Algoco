#include <bits/stdc++.h>
using namespace std;

// Function for Selection sort
void selectionSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) { //Se usa para recorrero toda la lista
        int min_idx = i; //Almacena la posición del menor elemento del resto lista inicializándola en la posición en la que parte
        for (int j = i + 1; j < n; j++) { //Recorre el resto de la lista para revisar si hay un elemento menor
            if (vec[j] < vec[min_idx]) {
                min_idx = j;  //Si hay un elemento menor en la lista almacena su posición
            }
        }

        //Si encontro un elemento menor, hace el cambio
        if (min_idx != i) {
            swap(vec[min_idx], vec[i]);
        }
    }
}

void printArray(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// Driver program
int main()
{   
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

        selectionSort(arr);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        printArray(arr);
        //Termina el temporiazdor
        cout << "Algoritmo 'SelectionSort'" << endl;
        cout << "------------------------------------------------------------------------" << endl; 
        cout << fixed << setprecision(3);
        cout << "El tiempo de ejecución fue de: " << duration.count() << "segundos" << endl;
    }else{
        cout << "No se pudo abrir el archivo para leer." << endl;
    }
    
    return 0;
}

// This is code is contributed by rathbhupendra