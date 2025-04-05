#include <iostream>
#include <vector>
using namespace std;

void interchangeSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> testArray = { 39, 8, 5, 1, 3, 6, 9, 12, 4, 7, 10 };

    vector<int> arr1 = testArray;
    interchangeSort(arr1);
    cout << "Interchange Sort: ";
    printArray(arr1);

    vector<int> arr2 = testArray;
    selectionSort(arr2);
    cout << "Selection Sort: ";
    printArray(arr2);

    vector<int> arr3 = testArray;
    insertionSort(arr3);
    cout << "Insertion Sort: ";
    printArray(arr3);

    vector<int> arr4 = testArray;
    bubbleSort(arr4);
    cout << "Bubble Sort: ";
    printArray(arr4);

    return 0;
}