#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    // 1. Loop setiap karakter dalam `expr`.
    for (char c : expr) {
        // 2. Jika karakter adalah kurung buka '(', '{', '[', push ke stack.
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // 3. Jika karakter adalah kurung tutup ')', '}', ']'.
        else if (c == ')' || c == '}' || c == ']') {

            if (stackTop == nullptr) {              // a. Jika stack kosong, berarti ada kurung tutup tanpa pasangan buka
                return false;
            }

            char openBracket = pop(stackTop);       // b. Pop dari stack untuk mendapatkan kurung buka yang terakhir
            if ((c == ')' && openBracket != '(') ||
                (c == '}' && openBracket != '{') ||
                (c == ']' && openBracket != '[')) {
                return false;                       // Kurung tidak cocok
            }
        }
    }

    // 4. Setelah loop, jika stack kosong, artinya semua kurung punya pasangan.
    return stackTop == nullptr;     // Jika masih ada sisa, berarti ada kurung buka yang tidak ditutup

}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}