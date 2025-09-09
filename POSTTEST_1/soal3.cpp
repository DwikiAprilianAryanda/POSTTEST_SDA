#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int SIZE = 5;
    Mahasiswa mhs[SIZE];
    
    cout << "Masukkan data 5 mahasiswa:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "\nMahasiswa " << i + 1 << ":" << endl;
        cout << "Nama: ";
        cin.ignore(1, '\n');
        getline(cin, mhs[i].nama);
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "IPK: ";
        cin >> mhs[i].ipk;
    }
    
    int IPKTertinggi = 0;
    for (int i = 1; i < SIZE; i++) {
        if (mhs[i].ipk > mhs[IPKTertinggi].ipk) {
            IPKTertinggi = i;
        }
    }
    
    cout << "\nMahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama: " << mhs[IPKTertinggi].nama << endl;
    cout << "NIM: " << mhs[IPKTertinggi].nim << endl;
    cout << "IPK: " << mhs[IPKTertinggi].ipk << endl;
    
    return 0;
}