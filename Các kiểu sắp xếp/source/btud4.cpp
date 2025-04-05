#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// a. Tìm số nguyên tố lớn nhất trong ma trận
int maxPrimeInMatrix(int matrix[][100], int m, int n) {
    int maxPrime = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime(matrix[i][j]) && matrix[i][j] > maxPrime) {
                maxPrime = matrix[i][j];
            }
        }
    }
    return maxPrime;
}

// b. Tìm các dòng chứa ít nhất một số nguyên tố
void rowsWithPrime(int matrix[][100], int m, int n) {
    cout << "Cac dong co chua so nguyen to: ";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime(matrix[i][j])) {
                cout << i << " ";
                break;
            }
        }
    }
    cout << endl;
}

// c. Tìm các dòng chỉ chứa số nguyên tố
void rowsOnlyPrime(int matrix[][100], int m, int n) {
    cout << "Cac dong chi chua so nguyen to: ";
    for (int i = 0; i < m; i++) {
        bool allPrime = true;
        for (int j = 0; j < n; j++) {
            if (!isPrime(matrix[i][j])) {
                allPrime = false;
                break;
            }
        }
        if (allPrime) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int m, n;
    cout << "Nhap so dong m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    int matrix[100][100]; // Mảng tĩnh có thể lưu tối đa 100x100 phần tử

    // Nhập ma trận
    cout << "Nhap cac phan tu cua ma tran:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // a. Tìm số nguyên tố lớn nhất
    int maxPrime = maxPrimeInMatrix(matrix, m, n);
    cout << "So nguyen to lon nhat: " << (maxPrime != -1 ? to_string(maxPrime) : "Khong co") << endl;

    // b. Tìm các dòng có chứa số nguyên tố
    rowsWithPrime(matrix, m, n);

    // c. Tìm các dòng chỉ chứa số nguyên tố
    rowsOnlyPrime(matrix, m, n);

    return 0;
}