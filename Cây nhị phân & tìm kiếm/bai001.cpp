#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây
struct Node {
    int info;           // Giá trị của nút
    Node* pLeft;       // Con trỏ đến nút con bên trái
    Node* pRight;      // Con trỏ đến nút con bên phải

    // Hàm khởi tạo nút
    Node(int val) : info(val), pLeft(nullptr), pRight(nullptr) {}
};

// Hàm đếm số lượng các nút trong cây
int DemNode(Node* root) {
    if (root == nullptr)  // Nếu nút hiện tại là NULL (cây rỗng)
        return 0;         // Trả về 0
    int a = DemNode(root->pLeft);  // Đệ quy đếm số nút bên trái
    int b = DemNode(root->pRight); // Đệ quy đếm số nút bên phải
    return (a + b + 1);  // Tổng số nút = số nút bên trái + số nút bên phải + 1 (tính nút hiện tại)
}

// Hàm tính tổng các nút trong cây
int TongNode(Node* root) {
    if (root == nullptr)  // Nếu cây rỗng, trả về 0
        return 0;
    int a = TongNode(root->pLeft);  // Đệ quy tính tổng bên trái
    int b = TongNode(root->pRight); // Đệ quy tính tổng bên phải
    return (a + b + root->info);  // Tổng giá trị = tổng bên trái + tổng bên phải + giá trị nút hiện tại
}

// Hàm tính trung bình cộng các nút trong cây
float TrungBinhCong(Node* root) {
    int s = TongNode(root);   // Tính tổng các nút trong cây
    int dem = DemNode(root);  // Đếm số lượng các nút trong cây
    if (dem == 0)  // Nếu không có nút nào, tránh chia cho 0
        return 0;
    return (float)s / dem;  // Trả về trung bình cộng = tổng / số lượng
}

// Hàm đếm số lượng các nút dương trong cây
int DemDuong(Node* root) {
    if (root == nullptr)  // Nếu nút hiện tại là NULL
        return 0;  // Trả về 0
    int a = DemDuong(root->pLeft);  // Đệ quy đếm nút dương bên trái
    int b = DemDuong(root->pRight); // Đệ quy đếm nút dương bên phải
    if (root->info > 0)  // Nếu giá trị nút hiện tại là dương
        return (a + b + 1);  // Trả về tổng nút dương bên trái + bên phải + 1 (tính nút hiện tại)
    return (a + b);  // Nếu nút hiện tại không dương, chỉ tính tổng nút dương con
}

// Hàm tính tổng các nút dương trong cây
int TongDuong(Node* root) {
    if (root == nullptr)  // Nếu cây rỗng, trả về 0
        return 0;
    int a = TongDuong(root->pLeft);  // Đệ quy tính tổng bên trái
    int b = TongDuong(root->pRight); // Đệ quy tính tổng bên phải
    if (root->info > 0)  // Nếu giá trị nút hiện tại là dương
        return (a + b + root->info);  // Trả về tổng giá trị dương của cây
    return (a + b);  // Nếu không phải dương, chỉ tính tổng giá trị dương của các nút con
}

// Hàm tính trung bình cộng các nút dương trong cây
float TrungBinhDuong(Node* root) {
    int s = TongDuong(root);   // Tính tổng các nút dương trong cây
    int dem = DemDuong(root);  // Đếm số lượng các nút dương trong cây
    if (dem == 0)  // Nếu không có nút dương, tránh chia cho 0
        return 0;
    return (float)s / dem;  // Trả về trung bình cộng các nút dương
}

// Hàm đếm số lượng các nút âm trong cây
int DemAm(Node* root) {
    if (root == nullptr)  // Nếu nút hiện tại là NULL
        return 0;  // Trả về 0
    int a = DemAm(root->pLeft);  // Đệ quy đếm nút âm bên trái
    int b = DemAm(root->pRight); // Đệ quy đếm nút âm bên phải
    if (root->info < 0)  // Nếu giá trị nút hiện tại là âm
        return (a + b + 1);  // Trả về tổng nút âm bên trái + bên phải + 1 (tính nút hiện tại)
    return (a + b);  // Nếu nút hiện tại không âm, chỉ tính tổng nút âm con
}

// Hàm tính tổng các nút âm trong cây
int TongAm(Node* root) {
    if (root == nullptr)  // Nếu cây rỗng, trả về 0
        return 0;
    int a = TongAm(root->pLeft);  // Đệ quy tính tổng bên trái
    int b = TongAm(root->pRight); // Đệ quy tính tổng bên phải
    if (root->info < 0)  // Nếu giá trị nút hiện tại là âm
        return (a + b + root->info);  // Trả về tổng giá trị âm của cây
    return (a + b);  // Nếu không phải âm, chỉ tính tổng giá trị âm của các nút con
}

// Hàm tính trung bình cộng các nút âm trong cây
float TrungBinhCongAm(Node* root) {
    int s = TongAm(root);   // Tính tổng các nút âm trong cây
    int dem = DemAm(root);  // Đếm số lượng các nút âm trong cây
    if (dem == 0)  // Nếu không có nút âm, tránh chia cho 0
        return 0;
    return (float)s / dem;  // Trả về trung bình cộng các nút âm
}

// Hàm tính tỉ số R = a / b, với a là tổng các nút dương và b là tổng các nút âm
float TinhTySo(Node* root) {
    int a = TongDuong(root);  // Tính tổng các nút dương trong cây
    int b = TongAm(root);     // Tính tổng các nút âm trong cây
    if (b == 0)  // Nếu tổng các nút âm bằng 0, tránh chia cho 0
        return 0;
    return (float)a / b;  // Trả về tỉ số R = a / b
}

int main() {
    // Khởi tạo một cây nhị phân mẫu
    Node* root = new Node(5);
    root->pLeft = new Node(3);
    root->pRight = new Node(-2);
    root->pLeft->pLeft = new Node(8);
    root->pLeft->pRight = new Node(-4);
    root->pRight->pLeft = new Node(7);

    // Đếm số lượng các nút
    cout << "So luong cac nut trong cay: " << DemNode(root) << endl;

    // Tính tổng các giá trị các nút
    cout << "Tong cac gia tri cac nut trong cay: " << TongNode(root) << endl;

    // Tính trung bình cộng các giá trị các nút
    cout << "Trung binh cong cac gia tri cac nut: " << TrungBinhCong(root) << endl;

    // Đếm số lượng các nút dương
    cout << "So luong cac nut duong trong cay: " << DemDuong(root) << endl;

    // Tính tổng các nút dương
    cout << "Tong cac gia tri cac nut duong trong cay: " << TongDuong(root) << endl;

    // Tính trung bình cộng các nút dương
    cout << "Trung binh cong cac gia tri cac nut duong: " << TrungBinhDuong(root) << endl;

    // Đếm số lượng các nút âm
    cout << "So luong cac nut am trong cay: " << DemAm(root) << endl;

    // Tính tổng các nút âm
    cout << "Tong cac gia tri cac nut am trong cay: " << TongAm(root) << endl;

    // Tính trung bình cộng các nút âm
    cout << "Trung binh cong cac gia tri cac nut am: " << TrungBinhCongAm(root) << endl;

    // Tính tỷ số giữa tổng các nút dương và âm
    cout << "Ti so giua tong cac nut duong va am: " << TinhTySo(root) << endl;

    return 0;
}
