#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// Hàm tạo dãy ngẫu nhiên
void generateArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

// Hàm sao chép mảng
void copyArray(int* source, int* dest, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// Hàm in mảng
void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Bubble Sort
void bubbleSort(int* arr, int n, long long& comp, long long& swapCount) {
    comp = swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapCount++;
            }
        }
    }
}

// Selection Sort
void selectionSort(int* arr, int n, long long& comp, long long& swapCount) {
    comp = swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comp++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swapCount++;
        }
    }
}

// Insertion Sort
void insertionSort(int* arr, int n, long long& comp, long long& swapCount) {
    comp = swapCount = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && (++comp && arr[j] > key)) {
            arr[j + 1] = arr[j];
            j--;
            swapCount++;
        }
        arr[j + 1] = key;
    }
}

// Quick Sort
int partition(int* arr, int low, int high, long long& comp, long long& swapCount) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comp++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swapCount++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swapCount++;
    return i + 1;
}

void quickSort(int* arr, int low, int high, long long& comp, long long& swapCount) {
    if (low < high) {
        int pi = partition(arr, low, high, comp, swapCount);
        quickSort(arr, low, pi - 1, comp, swapCount);
        quickSort(arr, pi + 1, high, comp, swapCount);
    }
}

// Merge Sort
void merge(int* arr, int l, int m, int r, long long& comp, long long& swapCount) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comp++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
            swapCount++;
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int* arr, int l, int r, long long& comp, long long& swapCount) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comp, swapCount);
        mergeSort(arr, m + 1, r, comp, swapCount);
        merge(arr, l, m, r, comp, swapCount);
    }
}

// Heap Sort
void heapify(int* arr, int n, int i, long long& comp, long long& swapCount) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && (++comp && arr[l] > arr[largest])) largest = l;
    if (r < n && (++comp && arr[r] > arr[largest])) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        swapCount++;
        heapify(arr, n, largest, comp, swapCount);
    }
}

void heapSort(int* arr, int n, long long& comp, long long& swapCount) {
    comp = swapCount = 0;
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i, comp, swapCount);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        swapCount++;
        heapify(arr, i, 0, comp, swapCount);
    }
}

// Hàm thực nghiệm
void testSort(void (*sortFunc)(int*, int, long long&, long long&), int* originalArray, int n, const string& name) {
    int* arr = new int[n];
    copyArray(originalArray, arr, n);

    long long comp = 0, swapCount = 0;
    auto start = high_resolution_clock::now();
    sortFunc(arr, n, comp, swapCount);
    auto end = high_resolution_clock::now();

    cout << name << ":\n";
    cout << "- Time (ms): " << duration<double, milli>(end - start).count() << endl;
    cout << "- Comparisons: " << comp << endl;
    cout << "- Swaps: " << swapCount << endl;
    if (n <= 100) {
        cout << "- Sorted Array: ";
        printArray(arr, n);
    }
    cout << "--------------------------------------\n";
    delete[] arr;
}

int main() {
    srand(time(NULL));
    int sizes[] = { 10, 100, 1000, 5000, 10000 };

    for (int s = 0; s < 5; s++) {
        int n = sizes[s];
        int* originalArray = new int[n];
        generateArray(originalArray, n);

        cout << "==============================\n";
        cout << "Array Size: " << n << endl;
        if (n <= 100) printArray(originalArray, n);

        testSort(bubbleSort, originalArray, n, "Bubble Sort");
        testSort(selectionSort, originalArray, n, "Selection Sort");
        testSort(insertionSort, originalArray, n, "Insertion Sort");
        testSort(heapSort, originalArray, n, "Heap Sort");
        testSort([](int* arr, int n, long long& c, long long& s) { mergeSort(arr, 0, n - 1, c, s); }, originalArray, n, "Merge Sort");
        testSort([](int* arr, int n, long long& c, long long& s) { quickSort(arr, 0, n - 1, c, s); }, originalArray, n, "Quick Sort");

        delete[] originalArray;
    }

    return 0;
}