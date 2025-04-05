#include <iostream>
#include <fstream>

using namespace std;

// Định nghĩa cấu trúc cây nhị phân
struct Node {
    float info;
    Node* pLeft;
    Node* pRight;
};

typedef Node* TREE;

// Hàm duyệt cây theo thứ tự NLR (Node-Left-Right) và ghi ra file
void NLR(TREE t, ofstream& outFile) {
    if (t == NULL) {
        return;
    }

    // Ghi giá trị node hiện tại vào file
    outFile.write(reinterpret_cast<char*>(&t->info), sizeof(float));

    // Duyệt cây con bên trái
    NLR(t->pLeft, outFile);

    // Duyệt cây con bên phải
    NLR(t->pRight, outFile);
}

// Hàm lưu cây nhị phân vào file nhị phân
int Xuat(const char* filename, TREE t) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        return 0;  // Không thể mở file
    }

    NLR(t, outFile);  // Duyệt cây theo NLR và ghi vào file
    outFile.close();  // Đóng file
    return 1;  // Thành công
}

// Hàm đọc dữ liệu từ file và tạo lại cây nhị phân
TREE TaoCay(ifstream& inFile) {
    float value;
    if (!inFile.read(reinterpret_cast<char*>(&value), sizeof(float))) {
        return NULL;  // Nếu không còn dữ liệu thì trả về NULL
    }

    TREE node = new Node;
    node->info = value;
    node->pLeft = TaoCay(inFile);  // Tạo cây con trái
    node->pRight = TaoCay(inFile); // Tạo cây con phải
    return node;
}

// Hàm đọc cây từ file nhị phân
TREE DocCay(const char* filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        return NULL;  // Không thể mở file
    }

    TREE root = TaoCay(inFile);  // Đọc và tạo cây từ file
    inFile.close();
    return root;
}

// Hàm in cây theo thứ tự NLR (Node-Left-Right)
void InCay(TREE t) {
    if (t == NULL) {
        return;
    }

    // In giá trị node hiện tại
    cout << t->info << " ";

    // In cây con bên trái
    InCay(t->pLeft);

    // In cây con bên phải
    InCay(t->pRight);
}

int main() {
    // Tạo cây nhị phân mẫu
    TREE root = new Node{ 10.5, nullptr, nullptr };
    root->pLeft = new Node{ 5.3, nullptr, nullptr };
    root->pRight = new Node{ 15.7, nullptr, nullptr };
    root->pLeft->pLeft = new Node{ 3.1, nullptr, nullptr };
    root->pLeft->pRight = new Node{ 7.8, nullptr, nullptr };

    // Lưu cây vào file
    if (Xuat("tree.dat", root)) {
        cout << "cay duoc luu vao file thanh cong" << endl;
    }
    else {
        cout << "Loi khi luu vao file." << endl;
    }

    // Đọc lại cây từ file
    TREE newTree = DocCay("tree.dat");
    cout << "Cây đã đọc từ file:" << endl;
    InCay(newTree);  // In cây theo thứ tự NLR
    cout << endl;

    // Giải phóng bộ nhớ
    delete root->pLeft->pLeft;
    delete root->pLeft->pRight;
    delete root->pLeft;
    delete root->pRight;
    delete root;

    delete newTree->pLeft->pLeft;
    delete newTree->pLeft->pRight;
    delete newTree->pLeft;
    delete newTree->pRight;
    delete newTree;

    return 0;
}
