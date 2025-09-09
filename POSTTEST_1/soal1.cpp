#include <iostream>
using namespace std;

//membalik urutan array
void BalikArray(int* arr, int size) {
    int* start = arr;       
    int* end = arr + size - 1;
    while (start < end) {
        int simpan = *start;
        *start = *end;
        *end = simpan;
        start++;
        end--;
    }
}

//menampilkan array
void TampilkanArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int SIZE = 7;
    int arr[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        arr[i] = (i + 1) * 3;
    }
    
    cout << "Array sebelum dibalik: ";
    TampilkanArray(arr, SIZE);
    
    BalikArray(arr, SIZE);
    
    cout << "Array setelah dibalik: ";
    TampilkanArray(arr, SIZE);
    
    return 0;
}