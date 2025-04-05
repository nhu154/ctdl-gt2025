#include <iostream>
#include <algorithm>

using namespace std;

void sortArray(int* arr, int n) {
    int evenCount = 0, oddCount = 0;
    int* evens = new int[n];
    int* odds = new int[n];

    // Phân loại số chẵn và lẻ (bỏ qua số 0)
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            if (arr[i] % 2 == 0) evens[evenCount++] = arr[i];
            else odds[oddCount++] = arr[i];
        }
    }

    // Sắp xếp
    sort(evens, evens + evenCount);                  // Số chẵn tăng dần
    sort(odds, odds + oddCount, greater<int>());     // Số lẻ giảm dần

    int evenIndex = 0, oddIndex = 0;

    // Ghép lại vào mảng chính
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) continue;  // Giữ nguyên số 0
        if (arr[i] % 2 == 0) arr[i] = evens[evenIndex++];
        else arr[i] = odds[oddIndex++];
    }

    delete[] evens;
    delete[] odds;
}

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    int* arr = new int[n];

    cout << "Nhap phan tu mang: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Mang ban dau: ";
    printArray(arr, n);

    sortArray(arr, n);

    cout << "   Mang sau khi sap xep: ";
    printArray(arr, n);

    delete[] arr;
    return 0;
}