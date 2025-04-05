#include <iostream>
using namespace std;

// ??nh ngh?a c?u trúc c?a m?t nút trong cây
struct Node {
    int info;           // Giá tr? c?a nút
    Node* pLeft;       // Con tr? ??n nút con bên trái
    Node* pRight;      // Con tr? ??n nút con bên ph?i

    // Hàm kh?i t?o nút
    Node(int val) : info(val), pLeft(nullptr), pRight(nullptr) {}
};

// Hàm thêm m?t nút vào cây nh? phân tìm ki?m
Node* Insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);  // N?u cây r?ng, t?o nút m?i

    // N?u giá tr? nh? h?n nút g?c, chèn vào cây con bên trái
    if (value < root->info)
        root->pLeft = Insert(root->pLeft, value);
    // N?u giá tr? l?n h?n ho?c b?ng nút g?c, chèn vào cây con bên ph?i
    else
        root->pRight = Insert(root->pRight, value);

    return root;
}

// Hàm tìm ph?n t? nh? nh?t trong cây nh? phân tìm ki?m
Node* NhoNhat(Node* root) {
    if (root == nullptr)
        return nullptr;  // N?u cây r?ng, tr? v? NULL

    Node* lc = root;
    while (lc->pLeft) {  // Duy?t ??n nút trái nh?t
        lc = lc->pLeft;
    }
    return lc;  // Tr? v? nút trái nh?t (ph?n t? nh? nh?t)
}

// Hàm tìm ph?n t? l?n nh?t trong cây nh? phân tìm ki?m
Node* LonNhat(Node* root) {
    if (root == nullptr)
        return nullptr;  // N?u cây r?ng, tr? v? NULL

    Node* lc = root;
    while (lc->pRight) {  // Duy?t ??n nút ph?i nh?t
        lc = lc->pRight;
    }
    return lc;  // Tr? v? nút ph?i nh?t (ph?n t? l?n nh?t)
}

// Hàm in cây theo th? t? duy?t ti?n t? (pre-order)
void PreOrder(Node* root) {
    if (root != nullptr) {
        cout << root->info << " ";  // In giá tr? c?a nút
        PreOrder(root->pLeft);      // Duy?t cây con bên trái
        PreOrder(root->pRight);     // Duy?t cây con bên ph?i
    }
}

int main() {
    Node* root = nullptr;  // Kh?i t?o cây r?ng

    // Thêm các nút vào cây
    root = Insert(root, 10);
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 3);
    root = Insert(root, 9);
    root = Insert(root, 12);
    root = Insert(root, 18);
    root = Insert(root, 7);
    root = Insert(root, 20);

    cout << "Cay nh? phân tìm ki?m (Duy?t ti?n t?): ";
    PreOrder(root);
    cout << endl;

    // Tìm ph?n t? nh? nh?t và l?n nh?t
    Node* smallest = NhoNhat(root);
    Node* largest = LonNhat(root);

    if (smallest != nullptr)
        cout << "Phan tu nho nhat trong cay: " << smallest->info << endl;
    if (largest != nullptr)
        cout << "Phan tu lon nhat trong cay: " << largest->info << endl;

    return 0;
}
