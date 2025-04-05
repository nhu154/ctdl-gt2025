#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Định nghĩa cấu trúc ngăn xếp
typedef struct {
    int top; // Đỉnh ngăn xếp
    int count; // Số phần tử hiện có trong ngăn xếp
    int size; // Kích thước tối đa của ngăn xếp
    int* arr; // Mảng lưu trữ dữ liệu ngăn xếp
} Stack;

// Hàm khởi tạo ngăn xếp
void Init(Stack& s, int size) {
    s.top = -1; // Đặt top về -1, nghĩa là ngăn xếp rỗng
    s.count = 0; // Ban đầu không có phần tử nào
    s.size = size; // Gán kích thước ngăn xếp
    s.arr = new int[s.size]; // Cấp phát bộ nhớ cho mảng lưu trữ dữ liệu ngăn xếp
}

// Hàm giải phóng bộ nhớ của ngăn xếp
void Delete(Stack& s) {
    s.top = -1; // Xóa đỉnh
    s.count = 0; // Xóa số phần tử
    s.size = 0; // Gán kích thước bằng 0
    delete[] s.arr; // Giải phóng bộ nhớ mảng arr
}

// Hàm kiểm tra ngăn xếp có rỗng không
bool IsEmpty(Stack& s) {
    return s.top == -1; // Nếu top là -1, tức là ngăn xếp rỗng
}

// Hàm kiểm tra ngăn xếp có đầy không
bool IsFull(Stack& s) {
    return s.top == s.size - 1; // Nếu top bằng kích thước tối đa - 1, tức là ngăn xếp đầy
}

// Hàm thêm phần tử vào ngăn xếp
void Push(Stack& s, int x) {
    if (IsFull(s)) { // Nếu ngăn xếp đầy
        cout << "Stack bi tran (stack overflow)" << endl;
        return;
    }
    s.arr[++s.top] = x; // Thêm phần tử vào vị trí top
    s.count++; // Tăng số phần tử
}

// Hàm lấy phần tử ra khỏi ngăn xếp
int Pop(Stack& s) {
    if (IsEmpty(s)) { // Nếu ngăn xếp rỗng
        cout << "Stack rong!" << endl;
        return -1; // Trả về -1 nếu ngăn xếp rỗng
    }
    int x = s.arr[s.top--]; // Lấy phần tử từ đỉnh ngăn xếp và giảm top đi 1
    s.count--; // Giảm số phần tử
    return x;
}

// Hàm xem phần tử trên đỉnh mà không lấy ra
int PeekStack(Stack& s) {
    if (IsEmpty(s)) return -1; // Nếu ngăn xếp rỗng, trả về -1
    return s.arr[s.top]; // Trả về phần tử trên đỉnh ngăn xếp
}

// Hàm xóa tất cả phần tử trong ngăn xếp
void Clear(Stack& s) {
    s.top = -1; // Đặt lại đỉnh ngăn xếp về -1
    s.count = 0; // Đặt lại số phần tử về 0
}

// (b) Đảo ngược một số nguyên
int DaoSo(int so) {
    bool isNegative = so < 0; // Kiểm tra nếu số âm
    if (isNegative) so = -so; // Lấy giá trị tuyệt đối của số

    Stack nganXep; // Khởi tạo ngăn xếp
    Init(nganXep, 10); // Khởi tạo ngăn xếp với kích thước 10 (vì số nguyên tối đa có 10 chữ số)
    while (so > 0) {
        Push(nganXep, so % 10); // Thêm chữ số cuối vào ngăn xếp
        so /= 10; // Bỏ chữ số cuối đi
    }

    int soDao = 0, heSo = 1;
    while (!IsEmpty(nganXep)) {
        soDao += Pop(nganXep) * heSo; // Lấy phần tử từ ngăn xếp và tính giá trị số đảo
        heSo *= 10; // Tăng hệ số theo từng bậc 10
    }
    Delete(nganXep); // Giải phóng bộ nhớ ngăn xếp

    return isNegative ? -soDao : soDao; // Nếu là số âm, trả lại số âm, nếu không trả lại số dương
}

// (c) Kiểm tra xâu đối xứng
bool KiemTraDoiXung(string xau) {
    Stack nganXep; // Khởi tạo ngăn xếp
    Init(nganXep, xau.length()); // Khởi tạo ngăn xếp với kích thước bằng chiều dài xâu
    for (char c : xau) Push(nganXep, c); // Đẩy từng ký tự của xâu vào ngăn xếp
    for (char c : xau) {
        if (c != Pop(nganXep)) { // Kiểm tra xem ký tự đầu tiên và ký tự lấy ra có giống nhau không
            Delete(nganXep); // Giải phóng bộ nhớ ngăn xếp
            return false; // Nếu không giống nhau thì không phải xâu đối xứng
        }
    }
    Delete(nganXep); // Giải phóng bộ nhớ ngăn xếp
    return true; // Nếu kiểm tra xong và không phát hiện sai, thì là xâu đối xứng
}

// (d) Chuyển đổi số thập phân sang nhị phân
string ThapPhanSangNhiPhan(int so) {
    Stack nganXep; // Khởi tạo ngăn xếp
    Init(nganXep, 32); // Khởi tạo ngăn xếp với kích thước 32 (số bit tối đa cho một số nguyên)
    while (so > 0) {
        Push(nganXep, so % 2); // Thêm phần dư của số khi chia cho 2 vào ngăn xếp
        so /= 2; // Chia số cho 2 để lấy phần nguyên
    }
    string nhiPhan = "";
    while (!IsEmpty(nganXep)) {
        nhiPhan += to_string(Pop(nganXep)); // Lấy từng bit từ ngăn xếp và tạo thành chuỗi nhị phân
    }
    Delete(nganXep); // Giải phóng bộ nhớ ngăn xếp
    return nhiPhan; // Trả về chuỗi nhị phân
}

int main() {
    Stack s; // Khởi tạo ngăn xếp
    Init(s, 5); // Khởi tạo ngăn xếp với kích thước 5

    // Ví dụ đảo số
    cout << "Dao so -54321: " << DaoSo(-54321) << endl; // Đảo số âm
    cout << "Dao so 98765: " << DaoSo(98765) << endl; // Đảo số dương
    cout << "Dao so 0: " << DaoSo(0) << endl; // Đảo số 0

    // Ví dụ kiểm tra đối xứng
    cout << "Kiem tra xau 'level' co doi xung: ";
    if (KiemTraDoiXung("level")) cout << "Co" << endl;
    else cout << "Khong" << endl;

    cout << "Kiem tra xau 'world' co doi xung: ";
    if (KiemTraDoiXung("world")) cout << "Co" << endl;
    else cout << "Khong" << endl;

    // Ví dụ chuyển đổi hệ thập phân sang nhị phân
    cout << "So 45 sang nhi phan: " << ThapPhanSangNhiPhan(45) << endl;

    Delete(s); // Giải phóng bộ nhớ ngăn xếp
    return 0;
}
