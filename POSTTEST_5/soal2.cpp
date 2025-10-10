// ## Soal 2

#include <iostream>
using namespace std;
// Struktur Node untuk Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert untuk membangun tree
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

int findMinValue(Node* root) {
    if (root == nullptr) {
        return -1; // Jika tree kosong
    }
    Node* current = root;   // Terus telusuri ke kiri selama masih ada anak kiri
    while (current->left != nullptr) {
        current = current->left; // Telusuri ke kiri
    }
    return current->data; // Node paling kiri adalah nilai terkecil
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl; // Harusnya output: 20
    return 0;
}