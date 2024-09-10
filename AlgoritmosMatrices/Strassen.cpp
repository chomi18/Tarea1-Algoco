#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Matrix;

// Función auxiliar para sumar matrices
void add(Matrix& C, const Matrix& A, const Matrix& B, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Función auxiliar para restar matrices
void subtract(Matrix& C, const Matrix& A, const Matrix& B, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Multiplicación usando Strassen
void strassenMultiply(Matrix& C, const Matrix& A, const Matrix& B, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;
    Matrix A11(newSize, vector<int>(newSize));
    Matrix A12(newSize, vector<int>(newSize));
    Matrix A21(newSize, vector<int>(newSize));
    Matrix A22(newSize, vector<int>(newSize));

    Matrix B11(newSize, vector<int>(newSize));
    Matrix B12(newSize, vector<int>(newSize));
    Matrix B21(newSize, vector<int>(newSize));
    Matrix B22(newSize, vector<int>(newSize));

    Matrix M1(newSize, vector<int>(newSize));
    Matrix M2(newSize, vector<int>(newSize));
    Matrix M3(newSize, vector<int>(newSize));
    Matrix M4(newSize, vector<int>(newSize));
    Matrix M5(newSize, vector<int>(newSize));
    Matrix M6(newSize, vector<int>(newSize));
    Matrix M7(newSize, vector<int>(newSize));

    Matrix tempA(newSize, vector<int>(newSize));
    Matrix tempB(newSize, vector<int>(newSize));

    // Dividir matrices A y B en submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // M1 = (A11 + A22) * (B11 + B22)
    add(tempA, A11, A22, newSize);
    add(tempB, B11, B22, newSize);
    strassenMultiply(M1, tempA, tempB, newSize);

    // M2 = (A21 + A22) * B11
    add(tempA, A21, A22, newSize);
    strassenMultiply(M2, tempA, B11, newSize);

    // M3 = A11 * (B12 - B22)
    subtract(tempB, B12, B22, newSize);
    strassenMultiply(M3, A11, tempB, newSize);

    // M4 = A22 * (B21 - B11)
    subtract(tempB, B21, B11, newSize);
    strassenMultiply(M4, A22, tempB, newSize);

    // M5 = (A11 + A12) * B22
    add(tempA, A11, A12, newSize);
    strassenMultiply(M5, tempA, B22, newSize);

    // M6 = (A21 - A11) * (B11 + B12)
    subtract(tempA, A21, A11, newSize);
    add(tempB, B11, B12, newSize);
    strassenMultiply(M6, tempA, tempB, newSize);

    // M7 = (A12 - A22) * (B21 + B22)
    subtract(tempA, A12, A22, newSize);
    add(tempB, B21, B22, newSize);
    strassenMultiply(M7, tempA, tempB, newSize);

    // C11 = M1 + M4 - M5 + M7
    add(tempA, M1, M4, newSize);
    subtract(tempB, M7, M5, newSize);
    add(C, tempA, tempB, newSize);

    // C12 = M3 + M5
    add(C, M3, M5, newSize);
    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newSize; j++)
            C[i][j + newSize] = C[i][j];

    // C21 = M2 + M4
    add(C, M2, M4, newSize);
    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newSize; j++)
            C[i + newSize][j] = C[i][j];

    // C22 = M1 - M2 + M3 + M6
    subtract(tempA, M1, M2, newSize);
    add(tempB, M3, M6, newSize);
    add(C, tempA, tempB, newSize);
    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newSize; j++)
            C[i + newSize][j + newSize] = C[i][j];
}

// Lee una matriz desde un archivo
Matrix readMatrixFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error abriendo el archivo: " << filename << endl;
        exit(1);
    }

    int n;
    file >> n;
    Matrix matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            file >> matrix[i][j];

    file.close();
    return matrix;
}

// Imprime una matriz
void printMatrix(const Matrix& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
int main() {
    ifstream archivo("dataset_cuadratica3.txt");
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

    if (C1 != R2) {
        cerr << "El número de columnas de la primera matriz debe ser igual al número de filas de la segunda." << endl;
        return 1;
    }

    Matrix resultado(R1, vector<int>(R1, 0));
    // Medir el tiempo de ejecución
    auto start = chrono::high_resolution_clock::now();

    // Multiplicar matrices usando Strassen
    strassenMultiply(resultado, mat1, mat2, R1);
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    printMatrix(resultado);
    cout << "Multiplicación de matrices'" << endl;
    cout << "------------------------------------------------------------------------" << endl; 
    cout << fixed << setprecision(4);
    cout << "El tiempo de ejecución fue de: " << duration.count() << "segundos" << endl;

    return 0;
}