#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of arr[]. First subarray is arr[left..mid] Second subarray is arr[mid+1..right]
void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // Create temp vectors
    vector<int> L(n1), R(n2);
    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0;
    int k = left;
    // Merge the temp vectors back into arr[left..right]
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
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// begin is for left index and end is right index, of the sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
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