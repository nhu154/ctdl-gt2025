#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm tìm vị trí của k phần tử có giá trị lớn nhất trong dãy
void tim_k_phan_tu_lon_nhat(const vector<int>& arr, int k) {
    // Tạo một bản sao của dãy để tránh thay đổi dãy gốc
    vector<int> arr_copy = arr;
    // Tạo một mảng indices lưu các chỉ số của các phần tử trong dãy
    vector<int> indices(arr.size());

    // Lưu lại các chỉ số
    for (int i = 0; i < arr.size(); ++i) {
        indices[i] = i;
    }

    // Sắp xếp dãy chỉ số theo giá trị giảm dần của các phần tử trong arr_copy
    sort(indices.begin(), indices.end(), [&arr_copy](int i1, int i2) {
        return arr_copy[i1] > arr_copy[i2];  // So sánh các phần tử dựa trên giá trị của arr_copy
        });

    // In ra vị trí của k phần tử có giá trị lớn nhất
    cout << "Vị trí của " << k << " phần tử có giá trị lớn nhất: ";
    for (int i = 0; i < k; ++i) {
        cout << indices[i] << " "; // In ra vị trí các phần tử có giá trị lớn nhất
    }
    cout << endl;
}

int main() {
    int n, k;

    // Nhập số lượng phần tử trong dãy
    cout << "Nhập số lượng phần tử trong dãy: ";
    cin >> n;  // Nhập số phần tử của dãy

    vector<int> arr(n);  // Khởi tạo vector arr có kích thước n

    // Nhập các phần tử của dãy
    cout << "Nhập " << n << " phần tử của dãy: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; // Nhập các phần tử vào vector arr
    }

    // Nhập số lượng phần tử lớn nhất cần tìm
    cout << "Nhập số lượng phần tử lớn nhất cần tìm: ";
    cin >> k;  // Nhập k

    // Gọi hàm tim_k_phan_tu_lon_nhat để tìm và in vị trí của k phần tử lớn nhất
    tim_k_phan_tu_lon_nhat(arr, k);

    return 0;
}