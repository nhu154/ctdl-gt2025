#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm tính tổng các chữ số của một số
int tong_cac_chu_so(int n) {
    int sum = 0;
    // Vòng lặp để tính tổng các chữ số
    while (n != 0) {
        sum += n % 10;  // Lấy chữ số cuối cùng của n
        n /= 10;         // Loại bỏ chữ số cuối cùng
    }
    return sum;  // Trả về tổng các chữ số
}

// Hàm sắp xếp dãy theo tổng các chữ số của mỗi phần tử
void sap_xep_theo_tong_chu_so(vector<int>& arr) {
    // Sử dụng hàm sort để sắp xếp dãy theo tổng chữ số của các phần tử
    sort(arr.begin(), arr.end(), [](int a, int b) {
        return tong_cac_chu_so(a) < tong_cac_chu_so(b);  // So sánh tổng chữ số của hai phần tử
        });
}

int main() {
    int n;

    // Nhập số lượng phần tử trong dãy
    cout << "Nhập số lượng phần tử trong dãy: ";
    cin >> n;

    vector<int> arr(n);

    // Nhập các phần tử của dãy
    cout << "Nhập " << n << " phần tử của dãy: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];  // Nhập từng phần tử của dãy
    }

    // Gọi hàm sắp xếp theo tổng chữ số
    sap_xep_theo_tong_chu_so(arr);

    // In ra dãy sau khi sắp xếp
    cout << "Dãy sau khi sắp xếp theo tổng chữ số: ";
    for (int num : arr) {
        cout << num << " ";  // In từng phần tử của dãy đã sắp xếp
    }
    cout << endl;

    return 0;  // Kết thúc chương trình
}
