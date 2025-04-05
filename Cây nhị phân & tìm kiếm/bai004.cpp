#include <iostream>
using namespace std;

// ??nh ngh?a c?u tr�c c?a m?t n�t trong c�y
struct Node {
    int info;           // Gi� tr? c?a n�t
    Node* pLeft;       // Con tr? ??n n�t con b�n tr�i
    Node* pRight;      // Con tr? ??n n�t con b�n ph?i

    // H�m kh?i t?o n�t
    Node(int val) : info(val), pLeft(nullptr), pRight(nullptr) {}
};

// H�m th�m m?t n�t v�o c�y nh? ph�n t�m ki?m
Node* Insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);  // N?u c�y r?ng, t?o n�t m?i

    // N?u gi� tr? nh? h?n n�t g?c, ch�n v�o c�y con b�n tr�i
    if (value < root->info)
        root->pLeft = Insert(root->pLeft, value);
    // N?u gi� tr? l?n h?n ho?c b?ng n�t g?c, ch�n v�o c�y con b�n ph?i
    else
        root->pRight = Insert(root->pRight, value);

    return root;
}

// H�m t�m ph?n t? nh? nh?t trong c�y nh? ph�n t�m ki?m
Node* NhoNhat(Node* root) {
    if (root == nullptr)
        return nullptr;  // N?u c�y r?ng, tr? v? NULL

    Node* lc = root;
    while (lc->pLeft) {  // Duy?t ??n n�t tr�i nh?t
        lc = lc->pLeft;
    }
    return lc;  // Tr? v? n�t tr�i nh?t (ph?n t? nh? nh?t)
}

// H�m t�m ph?n t? l?n nh?t trong c�y nh? ph�n t�m ki?m
Node* LonNhat(Node* root) {
    if (root == nullptr)
        return nullptr;  // N?u c�y r?ng, tr? v? NULL

    Node* lc = root;
    while (lc->pRight) {  // Duy?t ??n n�t ph?i nh?t
        lc = lc->pRight;
    }
    return lc;  // Tr? v? n�t ph?i nh?t (ph?n t? l?n nh?t)
}

// H�m in c�y theo th? t? duy?t ti?n t? (pre-order)
void PreOrder(Node* root) {
    if (root != nullptr) {
        cout << root->info << " ";  // In gi� tr? c?a n�t
        PreOrder(root->pLeft);      // Duy?t c�y con b�n tr�i
        PreOrder(root->pRight);     // Duy?t c�y con b�n ph?i
    }
}

int main() {
    Node* root = nullptr;  // Kh?i t?o c�y r?ng

    // Th�m c�c n�t v�o c�y
    root = Insert(root, 10);
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 3);
    root = Insert(root, 9);
    root = Insert(root, 12);
    root = Insert(root, 18);
    root = Insert(root, 7);
    root = Insert(root, 20);

    cout << "Cay nh? ph�n t�m ki?m (Duy?t ti?n t?): ";
    PreOrder(root);
    cout << endl;

    // T�m ph?n t? nh? nh?t v� l?n nh?t
    Node* smallest = NhoNhat(root);
    Node* largest = LonNhat(root);

    if (smallest != nullptr)
        cout << "Phan tu nho nhat trong cay: " << smallest->info << endl;
    if (largest != nullptr)
        cout << "Phan tu lon nhat trong cay: " << largest->info << endl;

    return 0;
}
