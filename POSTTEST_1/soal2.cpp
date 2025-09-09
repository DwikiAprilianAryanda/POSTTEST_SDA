#include <iostream>
using namespace std;

int main() {
    const int SIZE = 3;
    int matrix[SIZE][SIZE];
    int DiagonalUtama = 0, DiagonalSekunder = 0;

    cout << "Masukkan elemen matriks 3x3:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Menghitung jumlah
    for (int i = 0; i < SIZE; i++) {
        DiagonalUtama += matrix[i][i];
        DiagonalSekunder += matrix[i][SIZE-1-i];
    }

    cout << "\nMatriks 3x3:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nJumlah diagonal utama: " << DiagonalUtama << endl;
    cout << "Jumlah diagonal sekunder: " << DiagonalSekunder << endl;
    cout << "Total jumlah diagonal: " << DiagonalUtama + DiagonalSekunder << endl;

    return 0;
}