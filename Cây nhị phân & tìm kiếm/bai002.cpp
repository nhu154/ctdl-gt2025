#include<iostream>
using namespace std;

struct node {
    int info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
TREE root = NULL;

void Init(TREE& Root) {
    Root = NULL;
}

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL) return NULL;
    p->info = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void Insert(TREE& p, int theKey) {
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

void InOrder(TREE Root) {
    if (Root != NULL) {
        InOrder(Root->pLeft);
        cout << Root->info << " ";
        InOrder(Root->pRight);
    }
}

TREE RotateRight(TREE p) {
    if (p == NULL || p->pLeft == NULL) return p;

    NODE* temp = p->pLeft;
    p->pLeft = p->pRight;
    p->pRight = temp;

    temp = p->pLeft->pLeft;
    p->pLeft->pLeft = p->pLeft->pRight;
    p->pLeft->pRight = temp;

    return p;
}

int main() {
    TREE Root;
    Init(Root);
    int arr[] = { 10, 5, 15, 3, 7, 9, 12, 18, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        Insert(Root, arr[i]);
    }

    cout << "Cay truoc khi xoay: ";
    InOrder(Root);
    cout << endl;

    Root = RotateRight(Root);

    cout << "Cay sau khi xoay: ";
    InOrder(Root);
    cout << endl;

    return 0;
}