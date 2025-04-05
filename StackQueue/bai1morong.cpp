#include <iostream>
#include <stack>  // Thư viện stack để sử dụng stack

using namespace std;

// (a) Fibonacci bằng đệ quy
int fibonacciDeQuy(int n) {
    // Điều kiện cơ sở: nếu n <= 1, trả về n (F(0) = 0, F(1) = 1)
    if (n <= 1) return n;
    // Đệ quy tính Fibonacci: F(n) = F(n-1) + F(n-2)
    return fibonacciDeQuy(n - 1) + fibonacciDeQuy(n - 2);
}

// Fibonacci không đệ quy (dùng stack)
int fibonacciStack(int n) {
    // Điều kiện cơ sở: nếu n <= 1, trả về n
    if (n <= 1) return n;
    stack<int> s;  // Khởi tạo một stack để lưu trữ các giá trị cần tính
    s.push(n);     // Đẩy n vào stack
    int a = 0, b = 1;  // Các giá trị Fibonacci ban đầu F(0) = 0 và F(1) = 1
    // Lặp cho đến khi stack rỗng
    while (!s.empty()) {
        int num = s.top(); s.pop();  // Lấy phần tử trên cùng của stack
        // Nếu num == 1, trả về b (F(1))
        if (num == 1) return b;
        // Nếu num == 0, trả về a (F(0))
        if (num == 0) return a;
        // Đẩy hai số Fibonacci tiếp theo vào stack
        s.push(num - 1);
        s.push(num - 2);
    }
    return 0;  // Không bao giờ đến đây nếu n >= 0
}

// (b) Đảo ngược số bằng đệ quy
int daoNguocSoDeQuy(int n, int rev = 0) {
    // Điều kiện dừng: khi n = 0, trả về số đảo ngược rev
    if (n == 0) return rev;
    // Đệ quy: lấy chữ số cuối của n và cộng vào rev sau khi nhân với 10
    return daoNguocSoDeQuy(n / 10, rev * 10 + n % 10);
}

// Đảo ngược số không đệ quy (dùng stack)
int daoNguocSoStack(int n) {
    stack<int> s;  // Khởi tạo stack để lưu trữ các chữ số
    // Lặp lại cho đến khi n bằng 0
    while (n > 0) {
        s.push(n % 10);  // Đẩy chữ số cuối của n vào stack
        n /= 10;  // Cập nhật n bằng cách loại bỏ chữ số cuối
    }
    int reversed = 0, factor = 1;  // Khởi tạo biến đảo ngược và hệ số
    // Lấy các chữ số từ stack và tái tạo số đảo ngược
    while (!s.empty()) {
        reversed += s.top() * factor;  // Nhân chữ số với factor và cộng vào reversed
        s.pop();  // Xóa chữ số đã xử lý
        factor *= 10;  // Cập nhật factor để tính vị trí chữ số tiếp theo
    }
    return reversed;  // Trả về số đã đảo ngược
}

// (c) Tháp Hà Nội bằng đệ quy
void hanoiDeQuy(int n, char from, char to, char aux) {
    // Điều kiện cơ sở: nếu n = 1, di chuyển đĩa từ from đến to
    if (n == 1) {
        cout << "Di chuyển đĩa 1 từ " << from << " đến " << to << endl;
        return;
    }
    // Đệ quy: di chuyển n-1 đĩa từ from đến aux
    hanoiDeQuy(n - 1, from, aux, to);
    // Di chuyển đĩa n từ from đến to
    cout << "Di chuyển đĩa " << n << " từ " << from << " đến " << to << endl;
    // Đệ quy: di chuyển n-1 đĩa từ aux đến to
    hanoiDeQuy(n - 1, aux, to, from);
}

int main() {
    int n = 5;  // Số Fibonacci cần tính
    // Tính số Fibonacci bằng đệ quy
    cout << "Fibonacci (de quy) cua " << n << ": " << fibonacciDeQuy(n) << endl;
    // Tính số Fibonacci bằng stack
    cout << "Fibonacci (stack) cua " << n << ": " << fibonacciStack(n) << endl;

    int num = 1234;  // Số cần đảo ngược
    // Đảo ngược số bằng đệ quy
    cout << "Dao nguoc (de quy) cua " << num << ": " << daoNguocSoDeQuy(num) << endl;
    // Đảo ngược số bằng stack
    cout << "Dao nguoc (stack) cua " << num << ": " << daoNguocSoStack(num) << endl;

    int disks = 3;  // Số đĩa trong bài toán Tháp Hà Nội
    // Giải bài toán Tháp Hà Nội bằng đệ quy
    cout << "Thap Ha Noi (de quy) voi " << disks << " dia:" << endl;
    hanoiDeQuy(disks, 'A', 'C', 'B');

    return 0;  // Kết thúc chương trình
}
