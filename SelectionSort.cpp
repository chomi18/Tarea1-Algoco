#include <bits/stdc++.h>
using namespace std;

// Function for Selection sort
void selectionSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (vec[j] < vec[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i) {
            swap(vec[min_idx], vec[i]);
        }
    }
}

// Driver program
int main()
{   
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

        selectionSort(arr);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
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