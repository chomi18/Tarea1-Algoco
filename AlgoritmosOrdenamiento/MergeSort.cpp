#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of arr[]. First subarray is arr[left..mid] Second subarray is arr[mid+1..right]
void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // Crea vectores temporales
    vector<int> L(n1), R(n2);
    // Copia los datos a los vectores temporales
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0;
    int k = left;
    // Fusiona los arreglos temporales
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copia los elemmentos restantes de la izquieda si es que hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copia los elementos de la derecha si es que quedan
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// Left es la posición inicial y end la posición final
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2; //almacena la posición de la mitad de la lista
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right); //Se llama recursivamente
    merge(arr, left, mid, right); //Fusiona los arreglos ordenandolos
}

void printArray(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// Driver code
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
        int n = arr.size();

        auto start = chrono::high_resolution_clock::now();

        mergeSort(arr, 0, n - 1);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        printArray(arr);
        cout << "Algoritmo 'MergeSort'" << endl;
        cout << "------------------------------------------------------------------------" << endl; 
        cout << fixed << setprecision(3);
        cout << "El tiempo de ejecución fue de: " << duration.count() << "segundos" << endl;
    }else{
        cout << "No se pudo abrir el archivo." << endl;
    }
     
    return 0;
}