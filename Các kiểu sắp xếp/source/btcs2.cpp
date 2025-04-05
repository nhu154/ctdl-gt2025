#include<iostream>
using namespace std;
void quicksort(int a[], int l, int r) {
	int i = l, j = r;
	int x = a[(l + r) / 2];
	while (i <= j) {
		while (a[i] < x) i++;
		while (a[j] > x)j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (i < r) quicksort(a, i, r);
	if (l < j)quicksort(a, l, j);
}

void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
    delete[] L; 
    delete[] R;
}

void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

void insertHeap(int a[], int l, int r) {
    int p = (r - 1) / 2; // Cha của phần tử r
    while (p >= l) {
        if (a[r] <= a[p]) {
            break; // Thoát nếu phần tử r đã đúng vị trí
        }
        swap(a[r], a[p]);
        r = p;
        p = (r - 1) / 2; // Cập nhật cha mới
    }
}

void createHeap(int a[], int n) {
    for (int k = (n + 1) / 2 - 1; k >= 0; k--) {
        insertHeap(a, k, n - 1);
    }
}

void heapSort(int a[], int n) {
    createHeap(a, n); // Xây dựng heap ban đầu
    for (int k = n - 1; k >= 1; k--) {
        swap(a[0], a[k]); // Đưa phần tử lớn nhất về cuối
        insertHeap(a, 0, k - 1); // Điều chỉnh heap với kích thước giảm dần
    }
}


void test() {
	int n = 10;
	int a[] = { 8, 5, 1, 3, 6, 9, 12, 4, 7, 10 };
	cout << "Mang truoc khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
	cout << endl;   
	quicksort(a, 0, n - 1);
	cout << "mang sau khi sap xep: ";
    //mergeSort(a, 0, n - 1);
    //heapSort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
int main() {
	test();
	return 0;
}