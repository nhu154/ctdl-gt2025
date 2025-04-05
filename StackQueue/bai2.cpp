#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100 // Số lượng phần tử tối đa trong hàng đợi

// Phần 1: Cài đặt Hàng đợi sử dụng Mảng (QueueInt)
class QueueInt {
private:
    int arr[MAX]; // Mảng để chứa các phần tử
    int front, rear; // Biến lưu chỉ số front và rear

public:
    QueueInt() {
        front = -1; // Khởi tạo front
        rear = -1; // Khởi tạo rear
    }

    bool isEmpty() {
        return front == -1; // Kiểm tra xem hàng đợi có rỗng không
    }

    bool isFull() {
        return rear == MAX - 1; // Kiểm tra xem hàng đợi có đầy không
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Hàng đợi đã đầy!" << endl;
            return;
        }
        if (front == -1) front = 0; // Đặt front khi thêm phần tử đầu tiên
        arr[++rear] = x; // Thêm phần tử vào hàng đợi
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Hàng đợi trống!" << endl;
            return -1;
        }
        int x = arr[front]; // Lấy phần tử đầu tiên
        if (front == rear) {
            front = rear = -1; // Reset lại nếu chỉ còn 1 phần tử
        }
        else {
            front++; // Di chuyển front nếu còn nhiều phần tử
        }
        return x;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Hàng đợi trống!" << endl;
            return -1;
        }
        return arr[front]; // Lấy phần tử đầu tiên mà không xóa
    }

    void clear() {
        front = rear = -1; // Xóa hết các phần tử trong hàng đợi
    }
};

// Phần 2: Cài đặt Hàng đợi sử dụng Danh sách liên kết (LinkedQueueInt)
struct Node {
    int data;
    Node* next;
};

class LinkedQueueInt {
private:
    Node* front;
    Node* rear;

public:
    LinkedQueueInt() {
        front = rear = nullptr; // Khởi tạo front và rear là null
    }

    bool isEmpty() {
        return front == nullptr; // Kiểm tra hàng đợi có trống không
    }

    void enqueue(int x) {
        Node* newNode = new Node(); // Tạo nút mới
        newNode->data = x; // Gán giá trị cho nút mới
        newNode->next = nullptr; // Nút mới không có phần tử kế tiếp
        if (isEmpty()) {
            front = rear = newNode; // Đặt front và rear trỏ đến nút mới
        }
        else {
            rear->next = newNode; // Liên kết nút mới vào cuối danh sách
            rear = newNode; // Đặt lại rear
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Hàng đợi trống!" << endl;
            return -1;
        }
        Node* temp = front; // Lấy phần tử đầu tiên
        int x = front->data; // Lưu giá trị phần tử đầu tiên
        front = front->next; // Di chuyển front sang phần tử kế tiếp
        delete temp; // Xóa phần tử đã lấy
        if (front == nullptr) {
            rear = nullptr; // Nếu không còn phần tử nào, reset lại rear
        }
        return x;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Hàng đợi trống!" << endl;
            return -1;
        }
        return front->data; // Lấy giá trị phần tử đầu tiên mà không xóa
    }

    void clear() {
        while (!isEmpty()) {
            dequeue(); // Xóa hết các phần tử trong hàng đợi
        }
    }
};

// Phần 3: Ứng dụng Hàng đợi để giải bài toán Xếp lịch cặp múa nam/nữ
void dancePairing() {
    queue<string> males, females;

    // Nhập danh sách nam và nữ
    males.push("Nam1");
    males.push("Nam2");
    males.push("Nam3");

    females.push("Nữ1");
    females.push("Nữ2");
    females.push("Nữ3");

    // Ghép các cặp múa
    while (!males.empty() && !females.empty()) {
        string male = males.front();
        string female = females.front();
        males.pop(); // Lấy nam ra khỏi hàng đợi
        females.pop(); // Lấy nữ ra khỏi hàng đợi

        // In ra cặp múa
        cout << "Cặp múa: " << male << " và " << female << endl;
    }
}

// Phần 4: Ứng dụng Hàng đợi để cài thuật toán RadixSort
void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end()); // Tìm giá trị lớn nhất
    int place = 1;

    while (maxVal / place > 0) { // Duyệt qua từng chữ số
        vector<queue<int>> bins(10); // Tạo 10 hàng đợi cho mỗi chữ số từ 0 đến 9

        // Phân loại các phần tử theo chữ số ở vị trí "place"
        for (int num : arr) {
            int digit = (num / place) % 10; // Lấy chữ số tại vị trí "place"
            bins[digit].push(num); // Đưa phần tử vào hàng đợi tương ứng
        }

        // Ghép lại các phần tử từ các hàng đợi
        int index = 0;
        for (auto& bin : bins) {
            while (!bin.empty()) {
                arr[index++] = bin.front(); // Đưa các phần tử từ hàng đợi về lại mảng
                bin.pop();
            }
        }

        place *= 10; // Di chuyển sang chữ số tiếp theo
    }
}

int main() {
    // Phần 1: Cài đặt Hàng đợi sử dụng Mảng
    QueueInt q;
    q.enqueue(10); // Thêm phần tử 10 vào hàng đợi
    q.enqueue(20); // Thêm phần tử 20 vào hàng đợi
    q.enqueue(30); // Thêm phần tử 30 vào hàng đợi
    cout << "Phần tử bị xóa (Mảng): " << q.dequeue() << endl; // Xóa phần tử đầu tiên
    cout << "Phần tử ở đầu hàng đợi (Mảng): " << q.peek() << endl; // Lấy phần tử đầu tiên mà không xóa
    q.clear(); // Xóa hết các phần tử trong hàng đợi

    // Phần 2: Cài đặt Hàng đợi sử dụng Danh sách liên kết
    LinkedQueueInt lq;
    lq.enqueue(40); // Thêm phần tử 40 vào hàng đợi
    lq.enqueue(50); // Thêm phần tử 50 vào hàng đợi
    lq.enqueue(60); // Thêm phần tử 60 vào hàng đợi
    cout << "Phần tử bị xóa (Danh sách liên kết): " << lq.dequeue() << endl; // Xóa phần tử đầu tiên
    cout << "Phần tử ở đầu hàng đợi (Danh sách liên kết): " << lq.peek() << endl; // Lấy phần tử đầu tiên mà không xóa
    lq.clear(); // Xóa hết các phần tử trong hàng đợi

    // Phần 3: Ứng dụng Hàng đợi để giải bài toán Xếp lịch cặp múa nam/nữ
    cout << "\nBài toán cặp múa nam/nữ:\n";
    dancePairing();

    // Phần 4: Ứng dụng Hàng đợi để cài thuật toán RadixSort
    vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 }; // Dãy số cần sắp xếp

    cout << "\nTrước khi sắp xếp: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    radixSort(arr); // Gọi hàm sắp xếp

    cout << "Sau khi sắp xếp: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
