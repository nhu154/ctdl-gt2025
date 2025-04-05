
#include <iostream>
#include <vector>

using namespace std;

// Hàm tính tổng các phần tử trong một dòng
int tong_dong(const vector<int>& row) {
    int sum = 0;
    for (int val : row) {
        sum += val;  // Cộng tất cả các phần tử trong dòng
    }
    return sum;
}

// Hàm tìm dòng có tổng lớn nhất
void tim_dong_co_tong_lon_nhat(const vector<vector<int>>& matrix) {
    int max_sum = -1;  // Khởi tạo tổng lớn nhất ban đầu là -1 (tổng luôn là số dương)
    int row_index = -1;  // Chỉ số của dòng có tổng lớn nhất

    // Duyệt qua từng dòng của ma trận
    for (int i = 0; i < matrix.size(); ++i) {
        int current_sum = tong_dong(matrix[i]);  // Tính tổng của dòng i
        if (current_sum > max_sum) {
            max_sum = current_sum;  // Cập nhật tổng lớn nhất
            row_index = i;  // Cập nhật chỉ số của dòng có tổng lớn nhất
        }
    }

    // In ra dòng có tổng lớn nhất
    cout << "Dòng có tổng lớn nhất là dòng thứ " << row_index + 1 << " với tổng là: " << max_sum << endl;
}

int main() {
    int m, n;

    // Nhập số lượng dòng và cột của ma trận
    cout << "Nhập số lượng dòng m: ";
    cin >> m;
    cout << "Nhập số lượng cột n: ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    // Nhập các phần tử của ma trận
    cout << "Nhập các phần tử của ma trận (m dòng, n cột):" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];  // Nhập từng phần tử
        }
    }

    // Gọi hàm tìm dòng có tổng lớn nhất
    tim_dong_co_tong_lon_nhat(matrix);

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm tính tổng các phần tử trong một dòng
int tong_dong(const vector<int>& row) {
    int sum = 0;
    for (int val : row) {
        sum += val;  // Cộng tất cả các phần tử trong dòng
    }
    return sum;
}

// Hàm sắp xếp các dòng sao cho dòng có tổng các phần tử lớn hơn sẽ nằm phía trên
void sap_xep_theo_tong_dong(vector<vector<int>>& matrix) {
    // Sắp xếp các dòng của ma trận theo tổng các phần tử trong mỗi dòng
    sort(matrix.begin(), matrix.end(), [](const vector<int>& a, const vector<int>& b) {
        return tong_dong(a) > tong_dong(b);  // Sắp xếp theo tổng giảm dần
        });
}

// Hàm in ma trận
void in_ma_tran(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";  // In từng phần tử của dòng
        }
        cout << endl;  // Xuống dòng sau mỗi dòng ma trận
    }
}

int main() {
    int m, n;

    // Nhập số lượng dòng và cột của ma trận
    cout << "Nhập số lượng dòng m: ";
    cin >> m;
    cout << "Nhập số lượng cột n: ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    // Nhập các phần tử của ma trận
    cout << "Nhập các phần tử của ma trận (m dòng, n cột):" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];  // Nhập từng phần tử
        }
    }

    // Sắp xếp ma trận theo tổng các phần tử trong từng dòng
    sap_xep_theo_tong_dong(matrix);

    // In ra ma trận sau khi sắp xếp
    cout << "Ma trận sau khi sắp xếp các dòng theo tổng các phần tử lớn hơn: " << endl;
    in_ma_tran(matrix);

    return 0;
}



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm tính tổng các phần tử trong một dòng
int tong_dong(const vector<int>& row) {
    int sum = 0;
    for (int val : row) {
        sum += val;  // Cộng tất cả các phần tử trong dòng
    }
    return sum;
}

// Hàm sắp xếp các dòng sao cho dòng có tổng các phần tử lớn hơn sẽ nằm phía trên
void sap_xep_theo_tong_dong(vector<vector<int>>& matrix) {
    // Sắp xếp các dòng của ma trận theo tổng các phần tử trong mỗi dòng
    sort(matrix.begin(), matrix.end(), [](const vector<int>& a, const vector<int>& b) {
        return tong_dong(a) > tong_dong(b);  // Sắp xếp theo tổng giảm dần
        });
}

// Hàm in ma trận
void in_ma_tran(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";  // In từng phần tử của dòng
        }
        cout << endl;  // Xuống dòng sau mỗi dòng ma trận
    }
}

int main() {
    int m, n;

    // Nhập số lượng dòng và cột của ma trận
    cout << "Nhập số lượng dòng m: ";
    cin >> m;
    cout << "Nhập số lượng cột n: ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    // Nhập các phần tử của ma trận
    cout << "Nhập các phần tử của ma trận (m dòng, n cột):" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];  // Nhập từng phần tử
        }
    }

    // Sắp xếp ma trận theo tổng các phần tử trong từng dòng
    sap_xep_theo_tong_dong(matrix);

    // In ra ma trận sau khi sắp xếp
    cout << "Ma trận sau khi sắp xếp các dòng theo tổng các phần tử lớn hơn: " << endl;
    in_ma_tran(matrix);

    return 0;
}

