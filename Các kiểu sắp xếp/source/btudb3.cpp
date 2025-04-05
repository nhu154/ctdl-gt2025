#include <iostream>
using namespace std;


struct Room {
    int roomNumber;    // Số phòng
	char house;     // Nhà
	int capacity;     // Sức chứa 
};

// Hàm hoán đổi 
void swap(Room& a, Room& b) {
    Room temp = a;
    a = b;
    b = temp;
}


void display(Room a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Phong " << a[i].roomNumber << " - Nha " << a[i].house
            << " - Suc chua " << a[i].capacity << endl;
    }
    cout << endl;
}

// Sắp xếp theo khả năng chứa giảm dần
void sortCapacityDesc(Room a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j =i+1 ; j<n; j++) {
            if (a[i].capacity < a[j].capacity) {
                swap(a[i], a[j]);
            }
        }
    }
}

// Sắp xếp theo Nhà tăng dần, cùng Nhà thì theo Số phòng tăng dần
void sortHouseAndRoomAsc(Room a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < n ; j++) {
            if (a[i].house > a[j].house ||
                (a[i].house == a[j].house && a[i].roomNumber > a[j].roomNumber)) {
                swap(a[i], a[j]);
            }
        }
    }
}

// Sắp xếp theo Nhà tăng dần, cùng Nhà thì theo Khả năng chứa giảm dần
void sortHouseAscCapacityDesc(Room a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j =i+1; j < n; j++) {
            if (a[i].house > a[j].house ||
                (a[i].house == a[j].house && a[i].capacity < a[j].capacity)) {
                swap(a[i], a[j]);
            }
        }
    }
}


void test() {
   
    Room sample[] = {
        {101, 'B', 50},  // Phòng 101, Nhà B, Sức chứa 50
        {102, 'A', 100}, // Phòng 102, Nhà A, Sức chứa 100
        {103, 'B', 75},  // Phòng 103, Nhà B, Sức chứa 75
        {104, 'C', 200}, // Phòng 104, Nhà C, Sức chứa 200
        {105, 'A', 30}   // Phòng 105, Nhà A, Sức chứa 30
    };
    int n = 5;

 
    Room* roomsCopy1 = new Room[n];
    Room* roomsCopy2 = new Room[n];
    Room* roomsCopy3 = new Room[n];
    for (int i = 0; i < n; i++) {
        roomsCopy1[i] = roomsCopy2[i] = roomsCopy3[i] = sample[i];
    }

    cout << "Danh sach phong thi ban dau:\n";
    display(sample, n);

    cout << "Danh sach phong thi theo suc chua giam dan:\n";
    sortCapacityDesc(roomsCopy1, n);
    display(roomsCopy1, n);

  
    cout << "Danh sach phong thi theo nha tang dan, so phong tang dan:\n";
    sortHouseAndRoomAsc(roomsCopy2, n);
    display(roomsCopy2, n);

    cout << "Danh sach phong thi theo nha tang dan, suc chua giam dan:\n";
    sortHouseAscCapacityDesc(roomsCopy3, n);
    display(roomsCopy3, n);

	// Xóa con trỏ
    delete[] roomsCopy1;
    delete[] roomsCopy2;
    delete[] roomsCopy3;
}

int main() {
    test();
    return 0;
}