#include<iostream>
#include<fstream>
using namespace std;

struct node {
    float info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
TREE root = NULL;

// Khởi tạo cây nhị phân
void Init(TREE& Root) {
    Root = NULL;
}

// Tạo một node mới với giá trị x
NODE* CreateNode(float x) {
    NODE* p = new NODE;
    if (p == NULL) return NULL;
    p->info = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

// Chèn một phần tử vào cây nhị phân
void Insert(TREE& p, float theKey) {
    if (p == NULL) {
        p = CreateNode(theKey);
    }
    else if (p->info > theKey) {
        Insert(p->pLeft, theKey);
    }
    else if (p->info < theKey) {
        Insert(p->pRight, theKey);
    }
}

// Duyệt cây theo thứ tự LNR (Left-Node-Right)
void InOrder(TREE Root) {
    if (Root != NULL) {
        InOrder(Root->pLeft);
        cout << Root->info << " ";
        InOrder(Root->pRight);
    }
}

// Hàm LNR để ghi các giá trị vào file nhị phân
void LNR(TREE t, FILE* fp) {
    if (t == NULL)
        return;
    LNR(t->pLeft, fp);
    fwrite(&t->info, sizeof(float), 1, fp);
    LNR(t->pRight, fp);
}

// Xuất cây vào file nhị phân
int Xuat(const char* filename, TREE t) {
    FILE* fp;
    fopen_s(&fp, filename, "wb");
    if (fp == NULL)
        return 0;
    LNR(t, fp);
    fclose(fp);
    return 1;
}

// Hàm đọc giá trị từ file nhị phân và in ra màn hình
void DocFile(const char* filename) {
    FILE* fp;
    fopen_s(&fp, filename, "rb");
    if (fp == NULL) {
        cout << "Khong the mo file!" << endl;
        return;
    }
    float value;
    cout << "Cac gia tri trong file: ";
    while (fread(&value, sizeof(float), 1, fp)) {
        cout << value << " ";
    }
    cout << endl;
    fclose(fp);
}

// Hàm tạo lại cây từ các giá trị trong file nhị phân
void TaoCayTuFile(const char* filename, TREE& Root) {
    FILE* fp;
    fopen_s(&fp, filename, "rb");
    if (fp == NULL) {
        cout << "Khong the mo file!" << endl;
        return;
    }
    float value;
    while (fread(&value, sizeof(float), 1, fp)) {
        Insert(Root, value);  // Chèn giá trị vào cây
    }
    fclose(fp);
}

int main() {
    TREE Root;
    Init(Root);

    // Tạo cây nhị phân mẫu
    float arr[] = { 10.5f, 5.2f, 15.8f, 3.1f, 7.4f, 9.6f, 12.3f, 18.9f, 20.0f };
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        Insert(Root, arr[i]);
    }

    // In cây theo thứ tự NLR
    cout << "Cay: ";
    InOrder(Root);
    cout << endl;

    // Xuất cây vào file
    if (Xuat("data.out", Root)) {
        cout << "Da xuat cay vao file data.out thanh cong!" << endl;
    }
    else {
        cout << "Xuat file that bai!" << endl;
    }

    // Đọc và hiển thị nội dung file
    DocFile("data.out");

    // Tạo lại cây từ file
    TREE newRoot;
    Init(newRoot);
    TaoCayTuFile("data.out", newRoot);

    // In cây sau khi tái tạo từ file
    cout << "Cay sau khi tao lai tu file: ";
    InOrder(newRoot);
    cout << endl;

    return 0;
}
