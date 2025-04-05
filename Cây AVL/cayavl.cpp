#include <iostream>
#include <algorithm>
using namespace std;

// Định nghĩa cấu trúc nút trong cây AVL
struct Node {
    int key;      // Giá trị của nút
    Node* left;   // Con trỏ tới nút con bên trái
    Node* right;  // Con trỏ tới nút con bên phải
    int height;   // Chiều cao của nút

    // Hàm tạo
    Node(int k) {
        key = k;
        left = right = NULL;
        height = 1;  // Nút lá có chiều cao là 1
    }
};

class AVLTree {
private:
    Node* root;

    // Lấy chiều cao của nút
    int height(Node* N) {
        if (N == NULL)
            return 0;
        return N->height;
    }

    // Lấy giá trị cân bằng của nút
    int getBalance(Node* N) {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }

    // Cập nhật chiều cao của nút
    void updateHeight(Node* N) {
        if (N != NULL)
            N->height = 1 + max(height(N->left), height(N->right));
    }

    // Phép xoay phải
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Thực hiện xoay
        x->right = y;
        y->left = T2;

        // Cập nhật chiều cao
        updateHeight(y);
        updateHeight(x);

        // Trả về nút gốc mới
        return x;
    }

    // Phép xoay trái
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Thực hiện xoay
        y->left = x;
        x->right = T2;

        // Cập nhật chiều cao
        updateHeight(x);
        updateHeight(y);

        // Trả về nút gốc mới
        return y;
    }

    // Thêm nút vào cây
    Node* insert(Node* node, int key) {
        // 1. Thực hiện thêm bình thường như BST
        if (node == NULL)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else  // Không cho phép giá trị trùng lặp
            return node;

        // 2. Cập nhật chiều cao của nút hiện tại
        updateHeight(node);

        // 3. Kiểm tra cân bằng và cân bằng lại cây nếu cần
        int balance = getBalance(node);

        // Trường hợp Left Left
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Trường hợp Right Right
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Trường hợp Left Right
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Trường hợp Right Left
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Trả về nút gốc không thay đổi
        return node;
    }

    // Tìm nút có giá trị nhỏ nhất trong cây con
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    // Xóa nút khỏi cây
    Node* deleteNode(Node* root, int key) {
        // 1. Thực hiện xóa bình thường như BST
        if (root == NULL)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            // Nút có một hoặc không có con
            if ((root->left == NULL) || (root->right == NULL)) {
                Node* temp = root->left ? root->left : root->right;

                // Không có con
                if (temp == NULL) {
                    temp = root;
                    root = NULL;
                }
                // Một con
                else {
                    *root = *temp;  // Sao chép nội dung của con không NULL
                }
                delete temp;
            }
            // Nút có hai con
            else {
                // Tìm nút kế nhiệm (nhỏ nhất ở cây con phải)
                Node* temp = minValueNode(root->right);

                // Sao chép dữ liệu của nút kế nhiệm vào nút hiện tại
                root->key = temp->key;

                // Xóa nút kế nhiệm
                root->right = deleteNode(root->right, temp->key);
            }
        }

        // Nếu cây chỉ có một nút thì trả về
        if (root == NULL)
            return root;

        // 2. Cập nhật chiều cao
        updateHeight(root);

        // 3. Kiểm tra cân bằng và cân bằng lại cây nếu cần
        int balance = getBalance(root);

        // Trường hợp Left Left
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // Trường hợp Left Right
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Trường hợp Right Right
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        // Trường hợp Right Left
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Tìm kiếm một giá trị trong cây
    bool search(Node* root, int key) {
        if (root == NULL)
            return false;

        if (root->key == key)
            return true;

        if (key < root->key)
            return search(root->left, key);
        else
            return search(root->right, key);
    }

    // Duyệt cây theo thứ tự trước (preorder)
    void preOrder(Node* root) {
        if (root != NULL) {
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    // Duyệt cây theo thứ tự giữa (inorder)
    void inOrder(Node* root) {
        if (root != NULL) {
            inOrder(root->left);
            cout << root->key << " ";
            inOrder(root->right);
        }
    }

    // Duyệt cây theo thứ tự sau (postorder)
    void postOrder(Node* root) {
        if (root != NULL) {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->key << " ";
        }
    }

    // Giải phóng bộ nhớ cây
    void freeTree(Node* root) {
        if (root == NULL) return;

        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }

public:
    // Hàm tạo
    AVLTree() {
        root = NULL;
    }

    // Hàm hủy
    ~AVLTree() {
        freeTree(root);
    }

    // Các phương thức giao diện công khai
    void insert(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    bool search(int key) {
        return search(root, key);
    }

    void displayPreOrder() {
        cout << "Duyệt tiền thứ tự: ";
        preOrder(root);
        cout << endl;
    }

    void displayInOrder() {
        cout << "Duyệt trung thứ tự: ";
        inOrder(root);
        cout << endl;
    }

    void displayPostOrder() {
        cout << "Duyệt hậu thứ tự: ";
        postOrder(root);
        cout << endl;
    }
};

// Chương trình chính để kiểm tra
int main() {
    AVLTree tree;

    // Thêm các khóa vào cây
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    // Hiển thị cây theo các thứ tự khác nhau
    tree.displayInOrder();    // Sắp xếp tăng dần
    tree.displayPreOrder();   // Thứ tự trước
    tree.displayPostOrder();  // Thứ tự sau

    // Tìm kiếm
    cout << "Tìm kiếm 25: " << (tree.search(25) ? "Tìm thấy" : "Không tìm thấy") << endl;
    cout << "Tìm kiếm 35: " << (tree.search(35) ? "Tìm thấy" : "Không tìm thấy") << endl;

    // Xóa một số nút
    cout << "Xóa nút 25" << endl;
    tree.remove(25);
    tree.displayInOrder();

    cout << "Xóa nút 40" << endl;
    tree.remove(40);
    tree.displayInOrder();

    return 0;
}