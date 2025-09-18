#include <iostream>
#include <string>
using namespace std;

// Struct untuk node inventory
struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
};

// Struct untuk identitas
struct Identitas {
    string nama;
    string nim;
};

// Fungsi ASCII art header
void tampilkanHeader(const string& nama, const string& nim) {
    cout << R"(
   ____   ____      _      __  __           _                  _             
  / ___| |  _ \    / \    |  \/  |   __ _  | |   ___     __ _ | |_   ___  ___
 | |  _  | |_) |  / _ \   | |\/| |  / _` | | |  / _ \   / _` || __| / _ \/ __|
 | |_| | |  __/  / ___ \  | |  | | | (_| | | | | (_) | | (_| || |_ |  __/\__ \
  \____| |_|    /_/   \_\ |_|  |_|  \__,_| |_|  \___/   \__,_| \__| \___||___/
    )" << endl;
    cout << "+=======================================================================+\n";
    cout << "|   GAME INVENTORY MANAGEMENT                                           |\n";
    cout << "|   [ " << nama << " - " << nim << " ]                                  |\n"; 
    cout << "+=======================================================================+\n";
}

// Fungsi tambah item di akhir
void tambahItem(Item*& head, const string& namaItem, const string& tipe, int jumlahAwal) {
    Item* baru = new Item{namaItem, jumlahAwal, tipe, nullptr};
    if (!head) {
        head = baru;
    } else {
        Item* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
    cout << "\n[+] Item berhasil ditambahkan!\n";
}

// Fungsi sisip item di posisi tertentu
void sisipItem(Item*& head, const string& namaItem, const string& tipe, int jumlahAwal, int posisi) {
    Item* baru = new Item{namaItem, jumlahAwal, tipe, nullptr};
    if (posisi <= 1 || !head) {
        baru->next = head;
        head = baru;
    } else {
        Item* temp = head;
        int idx = 1;
        while (temp->next && idx < posisi - 1) {
            temp = temp->next;
            idx++;
        }
        baru->next = temp->next;
        temp->next = baru;
    }
    cout << "\n[+] Item berhasil disisipkan di posisi " << posisi << "!\n";
}

// Fungsi hapus item terakhir
void hapusItemTerakhir(Item*& head) {
    if (!head) {
        cout << "\n[!] Inventory kosong!\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        cout << "\n[-] Item terakhir dihapus!\n";
        return;
    }
    Item* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
    cout << "\n[-] Item terakhir dihapus!\n";
}

// Fungsi gunakan item
void gunakanItem(Item*& head, const string& namaCari) {
    Item* temp = head;
    Item* prev = nullptr;
    while (temp) {
        if (temp->namaItem == namaCari) {
            temp->jumlah--;
            cout << "\n[*] Item '" << namaCari << "' digunakan! Sisa: " << temp->jumlah << endl;
            if (temp->jumlah == 0) {
                if (!prev) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "[!] Item '" << namaCari << "' habis dan dihapus dari inventory.\n";
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "\n[!] Item tidak ditemukan!\n";
}

// Fungsi tampilkan inventory dengan border dan icon
void tampilkanInventory(Item* head) {
    cout << "\n+------------------- INVENTORY -------------------+\n";
    if (!head) {
        cout << "|   (kosong)                                       |\n";
        cout << "+--------------------------------------------------+\n";
        return;
    }
    int idx = 1;
    Item* temp = head;
    while (temp) {
        cout << "| " << idx << ". [";
        if (temp->tipe == "Sword") cout << "/|\\";
        else if (temp->tipe == "Potion") cout << "[P]";
        else cout << "*";
        cout << "] " << temp->namaItem << " | Jumlah: " << temp->jumlah << " | Tipe: " << temp->tipe << endl;
        temp = temp->next;
        idx++;
    }
    cout << "+--------------------------------------------------+\n";
}

int main() {
    Identitas user;
    cout << "Masukkan Nama: ";
    getline(cin, user.nama);
    cout << "Masukkan NIM: ";
    getline(cin, user.nim);

    int jumlahAwal = stoi(user.nim.substr(user.nim.length()-2));
    int posisiSisip = (user.nim[user.nim.length()-1] - '0') + 1;

    Item* inventory = nullptr;
    int pilihan;
    do {
        system("cls"); 
        tampilkanHeader(user.nama, user.nim);
        cout << R"(
    +===================================================+
    | 1. Tambah Item Baru                               |
    | 2. Sisipkan Item                                  |
    | 3. Hapus Item Terakhir                            |
    | 4. Gunakan Item                                   |
    | 5. Tampilkan Inventory                            |
    | 0. Keluar                                         |
    +===================================================+
        )" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            string namaItem, tipe;
            cout << "\nNama Item: "; getline(cin, namaItem);
            cout << "Tipe Item (Sword/Potion/dll): "; getline(cin, tipe);
            tambahItem(inventory, namaItem, tipe, jumlahAwal);
            system("pause");
        } else if (pilihan == 2) {
            string namaItem, tipe;
            cout << "\nNama Item: "; getline(cin, namaItem);
            cout << "Tipe Item (Sword/Potion/dll): "; getline(cin, tipe);
            sisipItem(inventory, namaItem, tipe, jumlahAwal, posisiSisip);
            system("pause");
        } else if (pilihan == 3) {
            hapusItemTerakhir(inventory);
            system("pause");
        } else if (pilihan == 4) {
            string namaCari;
            cout << "\nNama Item yang ingin digunakan: "; getline(cin, namaCari);
            gunakanItem(inventory, namaCari);
            system("pause");
        } else if (pilihan == 5) {
            tampilkanInventory(inventory);
            system("pause");
        } else if (pilihan == 0) {
            cout << "\nTerima kasih telah menggunakan program ini!\n";
        } else {
            cout << "\nPilihan tidak valid!\n";
            system("pause");
        }
    } while (pilihan != 0);

    while (inventory) {
        Item* temp = inventory;
        inventory = inventory->next;
        delete temp;
    }
    return 0;
}