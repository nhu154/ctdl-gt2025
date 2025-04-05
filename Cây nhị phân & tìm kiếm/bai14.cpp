#include <iostream>
using namespace std;

// Cấu trúc cây nhị phân tìm kiếm
struct NodeTree {
    int info;
    NodeTree* pLeft;
    NodeTree* pRight;
};

typedef NodeTree* TREE;

// Cấu trúc danh sách liên kết đơn
struct NodeList {
    int info;
    NodeList* pNext;
};

typedef NodeList* NODELIST;

// Cấu trúc danh sách
struct List {
    NODELIST pHead;
    NODELIST pTail;
};

// Khởi tạo danh sách
void Init(List& l) {
    l.pHead = l.pTail = NULL;
}

// Tạo node mới cho danh sách liên kết
NODELIST GetNode(int x) {
    NODELIST p = new NodeList;
    if (p == NULL) return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}

// Thêm node vào cuối danh sách
void AddTail(List& l, NODELIST p) {
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

// Hàm duyệt cây theo thứ tự RNL (Right-Node-Left) và thêm vào danh sách
void RNL(TREE Root, List& l) {
    if (Root == NULL) return;
    // Duyệt cây con bên phải trước
    RNL(Root->pRight, l);
    // Thêm node vào danh sách
    NODELIST p = GetNode(Root->info);
    if (p != NULL)
        AddTail(l, p);
    // Duyệt cây con bên trái sau
    RNL(Root->pLeft, l);
}

// Hàm tạo danh sách liên kết từ cây nhị phân
void BuildList(TREE Root, List& l) {
    Init(l);
    RNL(Root, l);
}

// Hàm in danh sách liên kết
void InList(List l) {
    NODELIST p = l.pHead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pNext;
    }
    cout << endl;
}

// Hàm tạo cây nhị phân mẫu
TREE CreateSampleTree() {
    TREE root = new NodeTree{ 10, NULL, NULL };
    root->pLeft = new NodeTree{ 5, NULL, NULL };
    root->pRight = new NodeTree{ 15, NULL, NULL };
    root->pLeft->pLeft = new NodeTree{ 3, NULL, NULL };
    root->pLeft->pRight = new NodeTree{ 7, NULL, NULL };
    root->pRight->pLeft = new NodeTree{ 12, NULL, NULL };
    root->pRight->pRight = new NodeTree{ 18, NULL, NULL };
    return root;
}

int main() {
    // Tạo cây nhị phân mẫu
    TREE root = CreateSampleTree();

    // Tạo danh sách liên kết từ cây nhị phân
    List l;
    BuildList(root, l);

    // In danh sách liên kết
    cout << "Danh sach lien ket theo thu tu giam dan: ";
    InList(l);

    return 0;
}
