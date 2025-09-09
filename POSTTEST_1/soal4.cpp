#include <iostream>
using namespace std;

//tukar dua variabel
void tukar(int** ptr1, int** ptr2) {
    int simpan = **ptr1;
    **ptr1 = **ptr2;
    **ptr2 = simpan;
}

int main() {
    int a, b;
    
    cout << "Masukkan nilai pertama (a): ";
    cin >> a;
    cout << "Masukkan nilai kedua (b): ";
    cin >> b;
    
    cout << "\nSebelum pertukaran:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    
    int* ptrA = &a;
    int* ptrB = &b;
    
    tukar(&ptrA, &ptrB);
    
    cout << "\nSetelah pertukaran:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    
    return 0;
}