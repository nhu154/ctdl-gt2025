#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    float info;
    Node* pLeft;
    Node* pRight;
};

typedef Node* TREE;

// Hàm duyệt cây theo phương pháp LRN (Left-Right-Node) và ghi ra file
void LRN(TREE t, ofstream& outFile) {
    if (t == NULL) {
        return;
    }

    // Duyệt cây con bên trái
    LRN(t->pLeft, outFile);
    // Duyệt cây con bên phải
    LRN(t->pRight, outFile);
    // Ghi giá trị node hiện tại vào file
    outFile.write(reinterpret_cast<char*>(&t->info), sizeof(float));
}

// Hàm xuất cây ra file nhị phân
int Xuat(const char* filename, TREE t) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        return 0; // Không thể mở file
    }

    LRN(t, outFile); // Gọi hàm duyệt cây theo LRN
    outFile.close(); // Đóng file
    return 1; // Thành công
}

int main() {
    // Tạo một cây nhị phân mẫu
    TREE root = new Node{ 10.5, nullptr, nullptr };
    root->pLeft = new Node{ 20.3, nullptr, nullptr };
    root->pRight = new Node{ 30.7, nullptr, nullptr };
    root->pLeft->pLeft = new Node{ 40.1, nullptr, nullptr };
    root->pLeft->pRight = new Node{ 50.8, nullptr, nullptr };

    // Xuất cây ra file data.out
    if (Xuat("data.out", root)) {
        cout << "cay duoc xuat ra file thanh cong!" << endl;
    }
    else {
        cout << "Lỗi khi xuất cây ra file." << endl;
    }

    // Giải phóng bộ nhớ
    delete root->pLeft->pLeft;
    delete root->pLeft->pRight;
    delete root->pLeft;
    delete root->pRight;
    delete root;

    return 0;
}
