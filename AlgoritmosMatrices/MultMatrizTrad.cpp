#include <bits/stdc++.h>
using namespace std;

void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int elemento : fila) {
            cout << elemento << " ";
        }
        cout << endl;
    }
}

// Función para multiplicar dos matrices
void multiplicarMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2, int R1, int C1, int R2, int C2, vector<vector<int>>& resultado) {
    if (C1 != R2) {
        cout << "No se pueden multiplicar las matrices: el número de columnas de la primera matriz debe ser igual al número de filas de la segunda." << endl;
        return;
    }

    // Crear la matriz resultado con dimensiones R1 x C2
    resultado.assign(R1, vector<int>(C2, 0));

    // Multiplicar las matrices
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            for (int k = 0; k < C1; k++) {
                resultado[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    ifstream archivo("dataset_cuadratica1.txt");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    int R1, C1, R2, C2;

    // Leer dimensiones de la primera matriz
    archivo >> R1 >> C1;
    vector<vector<int>> mat1(R1, vector<int>(C1));

    // Leer elementos de la primera matriz
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C1; j++) {
            archivo >> mat1[i][j];
        }
    }

    // Leer dimensiones de la segunda matriz
    archivo >> R2 >> C2;
    vector<vector<int>> mat2(R2, vector<int>(C2));

    // Leer elementos de la segunda matriz
    for (int i = 0; i < R2; i++) {
        for (int j = 0; j < C2; j++) {
            archivo >> mat2[i][j];
        }
    }

    archivo.close();
    vector<vector<int>> resultado;
    auto start = chrono::high_resolution_clock::now();
    // Multiplicar las matrices y mostrar el resultado
    multiplicarMatrices(mat1, mat2, R1, C1, R2, C2);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    // Imprimir la matriz resultante
    cout << endl;
    cout << "Multiplicación de matrices'" << endl;
    cout << "------------------------------------------------------------------------" << endl; 
    cout << fixed << setprecision(4);
    cout << "El tiempo de ejecución fue de: " << duration.count() << "segundos" << endl;
    imprimirMatriz(resultado);


    return 0;
}