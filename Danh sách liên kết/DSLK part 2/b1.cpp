#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node, mỗi phần tử của danh sách liên kết
struct Node {
    int data;       // Dữ liệu (số nguyên) của node
    Node* next;     // Con trỏ tới phần tử kế tiếp trong danh sách
};

// Lớp ListInt đại diện cho danh sách liên kết các số nguyên
class ListInt {
private:
    Node* head;  // Con trỏ tới phần tử đầu tiên của danh sách

public:
    // Khởi tạo danh sách liên kết, lúc đầu danh sách trống
    ListInt() {
        head = nullptr;  // Khởi tạo head bằng nullptr (danh sách rỗng)
    }

    // Hủy danh sách liên kết
    ~ListInt() {
        Node* current = head;  // Con trỏ current trỏ đến phần tử đầu tiên
        while (current != nullptr) {
            Node* temp = current;  // Lưu trữ node hiện tại
            current = current->next;  // Di chuyển tới node tiếp theo
            delete temp;  // Giải phóng bộ nhớ của node hiện tại
        }
    }

    // Thêm phần tử vào cuối danh sách
    void add(int value) {
        Node* newNode = new Node;  // Tạo một node mới
        newNode->data = value;     // Gán giá trị cho node mới
        newNode->next = nullptr;   // Đặt con trỏ next của node mới thành nullptr (cuối danh sách)

        // Nếu danh sách rỗng, head trỏ đến node mới
        if (head == nullptr) {
            head = newNode;
        }
        else {
            // Tìm phần tử cuối cùng trong danh sách
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;  // Di chuyển tới node tiếp theo
            }
            temp->next = newNode;  // Gắn node mới vào cuối danh sách
        }
    }

    // Xóa phần tử có giá trị bằng k
    void remove(int k) {
        Node* current = head;  // Con trỏ current trỏ đến phần tử đầu tiên
        Node* prev = nullptr;   // Con trỏ prev để theo dõi node trước current

        // Nếu phần tử đầu tiên có giá trị k
        if (current != nullptr && current->data == k) {
            head = current->next;  // Cập nhật head trỏ tới node tiếp theo
            delete current;  // Giải phóng bộ nhớ của node đầu tiên
            return;
        }

        // Tìm phần tử có giá trị k trong danh sách
        while (current != nullptr && current->data != k) {
            prev = current;          // Lưu node hiện tại vào prev
            current = current->next; // Di chuyển current tới node tiếp theo
        }

        // Nếu không tìm thấy phần tử có giá trị k trong danh sách
        if (current == nullptr) return;

        // Xóa phần tử có giá trị k
        prev->next = current->next;  // Liên kết lại danh sách, bỏ qua node hiện tại
        delete current;  // Giải phóng bộ nhớ của node bị xóa
    }

    // Thêm một danh sách vào danh sách hiện tại
    void addList(ListInt& otherList) {
        Node* current = otherList.head;  // Con trỏ current trỏ đến phần tử đầu của danh sách khác
        while (current != nullptr) {
            add(current->data);  // Thêm từng phần tử từ danh sách khác vào danh sách hiện tại
            current = current->next;  // Di chuyển tới node tiếp theo trong danh sách khác
        }
    }

    // Xuất danh sách ra màn hình
    void print() const {
        Node* current = head;  // Con trỏ current trỏ đến phần tử đầu tiên của danh sách
        while (current != nullptr) {
            cout << current->data << " ";  // In giá trị của node hiện tại
            current = current->next;  // Di chuyển tới node tiếp theo
        }
        cout << endl;  // Xuất dòng mới sau khi in xong danh sách
    }
};

int main() {
    ListInt list1, list2;  // Tạo hai danh sách liên kết list1 và list2
    int value, k;

    // Nhập 10 số nguyên và đưa vào danh sách list1
    cout << "Nhap 10 so nguyen vao danh sach 1: ";
    for (int i = 0; i < 10; ++i) {
        cin >> value;  // Nhập giá trị cho mỗi phần tử
        list1.add(value);  // Thêm giá trị vào danh sách list1
    }

    // In danh sách list1 ra màn hình
    cout << "Danh sach 1: ";
    list1.print();

    // Nhập số k và xóa số k trong danh sách list1
    cout << "Nhap so k de xoa trong danh sach: ";
    cin >> k;
    list1.remove(k);  // Xóa phần tử có giá trị bằng k trong danh sách list1

    // In danh sách list1 sau khi xóa phần tử
    cout << "Danh sach 1 sau khi xoa: ";
    list1.print();

    // Nhập 5 số nguyên vào danh sách list2
    cout << "Nhap 5 so nguyen vao danh sach 2: ";
    for (int i = 0; i < 5; ++i) {
        cin >> value;  // Nhập giá trị cho mỗi phần tử
        list2.add(value);  // Thêm giá trị vào danh sách list2
    }

    // Thêm danh sách list2 vào danh sách list1
    list1.addList(list2);

    // In danh sách list1 sau khi thêm list2
    cout << "Danh sach 1 sau khi them danh sach 2: ";
    list1.print();

    return 0;
}