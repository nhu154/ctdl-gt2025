#include <iostream>

using namespace std;

// Hàm tính mảng nghịch thế
void tinhMangNghichThe(int* A, int* B, int N) {
    for (int i = 0; i < N; i++) {
        int count = 0; // Đếm số phần tử lớn hơn A[i] đứng trước nó
        for (int j = 0; j < i; j++) {
            if (A[j] > A[i]) {
                count++;
            }
        }
        B[A[i] - 1] = count; // Gán giá trị vào mảng B tại vị trí A[i] - 1
    }
}

int main() {
    // Khai báo mảng A (hoán vị của 1 đến N)
    int A[] = { 5, 9, 1, 8, 2, 6, 4, 7, 3 };
    int N = sizeof(A) / sizeof(A[0]); // Số phần tử trong A

    // Cấp phát động mảng B
    int* B = new int[N];

    // Khởi tạo mảng B với giá trị 0
    for (int i = 0; i < N; i++) {
        B[i] = 0;
    }

    // Tính mảng nghịch thế B
    tinhMangNghichThe(A, B, N);

    // In mảng B
    cout << "Mang nghich the B: ";
    for (int i = 0; i < N; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    // Giải phóng bộ nhớ đã cấp phát cho B
    delete[] B;

    return 0;
}
