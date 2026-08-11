#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    // First allocate an array of row pointers.
    int **matrix = new int*[m];

    // Then allocate memory for every row.
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n];
    }

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nMatrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Delete every dynamically allocated row first.
    for (int i = 0; i < m; i++) {
        delete[] matrix[i];
    }

    // Finally delete the array of row pointers.
    delete[] matrix;
    matrix = nullptr;

    return 0;
}
