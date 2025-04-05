#include<iostream>
using namespace std;
void sort(int a[], int n) {
    
    int* temp=new int [n];
    int left = 0;          
    int right = n - 1;      

    // Duyệt qua mảng một lần
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {      
            temp[left] = a[i];
            left++;
        }
        else {                    
            temp[right] = a[i];
            right--;
        }
    }

    // Sao chép lại vào mảng gốc
    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}

void test() {
    int n = 9;
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	sort(a, n);
	cout << "Mang sau khi sap xep la: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
    cout << endl;
}
int main() {
    test();
	return 0;
}

/*1.	Khởi tạo:
•	Hàm nhận một mảng a[] và một số nguyên n (số lượng phần tử trong mảng) làm tham số.
•	Tạo một mảng tạm thời temp có kích thước bằng n để lưu trữ các phần tử đã sắp xếp.
•	Khởi tạo hai biến left và right để theo dõi vị trí chèn các số chẵn và số lẻ trong mảng temp:
•	left bắt đầu từ đầu mảng (chỉ số 0).
•	right bắt đầu từ cuối mảng (chỉ số n - 1).
2.	Duyệt qua mảng:
•	Sử dụng vòng lặp for để duyệt qua tất cả các phần tử của mảng a[].
•	Nếu phần tử hiện tại là số chẵn (a[i] % 2 == 0):
•	Gán phần tử đó vào vị trí left trong mảng temp.
•	Tăng biến left lên 1.
•	Nếu phần tử hiện tại là số lẻ (a[i] % 2 != 0):
•	Gán phần tử đó vào vị trí right trong mảng temp.
•	Giảm biến right xuống 1.
3.	Sao chép lại vào mảng gốc:
•	Sau khi đã sắp xếp các phần tử vào mảng temp, sử dụng vòng lặp for để sao chép lại các phần tử từ temp vào mảng a[].*/