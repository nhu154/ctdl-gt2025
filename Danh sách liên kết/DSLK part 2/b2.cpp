#include <iostream>
#include <cstring>  // Dùng để thao tác với chuỗi
using namespace std;

// Định nghĩa cấu trúc SinhVien
struct SinhVien {
    char hoTen[50];  // Họ tên sinh viên
    char diaChi[70];  // Địa chỉ sinh viên
    char lop[10];  // Lớp sinh viên
    int khoa;  // Khóa sinh viên

    // Hàm nhập thông tin sinh viên
    void nhap(const char* hT, const char* dC, const char* l, int k) {
        strcpy(hoTen, hT);
        strcpy(diaChi, dC);
        strcpy(lop, l);
        khoa = k;
    }

    // Hàm xuất thông tin sinh viên
    void xuat() const {
        cout << "Ho ten: " << hoTen << ", Dia chi: " << diaChi << ", Lop: " << lop << ", Khoa: " << khoa << endl;
    }
};

// Các hàm so sánh hai sinh viên theo từng tiêu chí
bool soSanhHoTen(const SinhVien& sv1, const SinhVien& sv2) {
    return strcmp(sv1.hoTen, sv2.hoTen) < 0;  // So sánh theo họ tên
}

bool soSanhDiaChi(const SinhVien& sv1, const SinhVien& sv2) {
    return strcmp(sv1.diaChi, sv2.diaChi) < 0;  // So sánh theo địa chỉ
}

bool soSanhLop(const SinhVien& sv1, const SinhVien& sv2) {
    return strcmp(sv1.lop, sv2.lop) < 0;  // So sánh theo lớp
}

bool soSanhKhoa(const SinhVien& sv1, const SinhVien& sv2) {
    return sv1.khoa < sv2.khoa;  // So sánh theo khóa
}
// Định nghĩa cấu trúc Node để lưu trữ sinh viên
struct Node {
    SinhVien sv;  // Sinh viên
    Node* next;  // Con trỏ tới phần tử tiếp theo
};

// Lớp ListSV đại diện cho danh sách liên kết các sinh viên
class ListSV {
private:
    Node* head;  // Con trỏ tới phần tử đầu tiên của danh sách

public:
    // Khởi tạo danh sách liên kết
    ListSV() {
        head = NULL;  // Khởi tạo danh sách rỗng
    }

    // Hủy danh sách liên kết
    ~ListSV() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Thêm một sinh viên vào danh sách
    void themSinhVien(const SinhVien& sv) {
        Node* newNode = new Node;
        newNode->sv = sv;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;  // Nếu danh sách rỗng, node mới trở thành phần tử đầu
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;  // Thêm node mới vào cuối danh sách
        }
    }

    // Xóa sinh viên theo tên
    void xoaSinhVienTheoTen(const char* ten) {
        Node* current = head;
        Node* prev = NULL;

        while (current != NULL && strcmp(current->sv.hoTen, ten) != 0) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) return;  // Nếu không tìm thấy sinh viên

        if (prev == NULL) {
            head = current->next;  // Xóa phần tử đầu tiên
        }
        else {
            prev->next = current->next;  // Liên kết lại danh sách sau khi xóa
        }

        delete current;  // Giải phóng bộ nhớ của sinh viên bị xóa
    }

    // Xóa sinh viên theo địa chỉ
    void xoaSinhVienTheoDiaChi(const char* diaChi) {
        Node* current = head;
        Node* prev = NULL;

        while (current != NULL && strcmp(current->sv.diaChi, diaChi) != 0) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) return;  // Nếu không tìm thấy sinh viên

        if (prev == NULL) {
            head = current->next;  // Xóa phần tử đầu tiên
        }
        else {
            prev->next = current->next;  // Liên kết lại danh sách sau khi xóa
        }

        delete current;  // Giải phóng bộ nhớ của sinh viên bị xóa
    }

    // Thêm một danh sách sinh viên vào danh sách hiện tại
    void themDanhSach(ListSV& otherList) {
        Node* current = otherList.head;
        while (current != NULL) {
            themSinhVien(current->sv);  // Thêm từng sinh viên vào danh sách hiện tại
            current = current->next;
        }
    }

    // In danh sách ra màn hình
    void inDanhSach() const {
        Node* current = head;
        while (current != NULL) {
            current->sv.xuat();  // Xuất thông tin sinh viên
            current = current->next;
        }
    }

    // Sắp xếp danh sách theo tiêu chí so sánh sử dụng Selection Sort
    void sapXep(bool (*soSanh)(const SinhVien&, const SinhVien&)) {
        for (Node* i = head; i != NULL; i = i->next) {
            Node* minNode = i;
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (soSanh(j->sv, minNode->sv)) {
                    minNode = j;
                }
            }
            if (minNode != i) {
                // Hoán đổi dữ liệu giữa i và minNode
                SinhVien temp = i->sv;
                i->sv = minNode->sv;
                minNode->sv = temp;
            }
        }
    }
};
int main() {
    ListSV list;

    // Danh sách sinh viên đã được định sẵn
    SinhVien sv1, sv2, sv3, sv4, sv5;
    sv1.nhap("Nguyen Van A", "Hanoi", "IT01", 2015);
    sv2.nhap("Tran Thi B", "Ho Chi Minh", "TT01", 2016);
    sv3.nhap("Le Thi C", "Da Nang", "IT02", 2015);
    sv4.nhap("Nguyen Thi D", "Hue", "TT02", 2017);
    sv5.nhap("Pham Minh E", "Haiphong", "IT03", 2018);

    // Thêm sinh viên vào danh sách
    list.themSinhVien(sv1);
    list.themSinhVien(sv2);
    list.themSinhVien(sv3);
    list.themSinhVien(sv4);
    list.themSinhVien(sv5);

    // In danh sách ra màn hình
    cout << "Danh sach sinh vien:" << endl;
    list.inDanhSach();

    // Xóa sinh viên có tên "Nguyen Van Teo"
    cout << "\nXoa sinh vien co ten 'Nguyen Van Teo':" << endl;
    list.xoaSinhVienTheoTen("Nguyen Van Teo");

    // Xóa sinh viên có địa chỉ "Nguyen Van Cu"
    cout << "\nXoa sinh vien co dia chi 'Nguyen Van Cu':" << endl;
    list.xoaSinhVienTheoDiaChi("Nguyen Van Cu");

    // Thêm sinh viên mới vào danh sách
    SinhVien newSV;
    newSV.nhap("Tran Thi Mo", "25 Hong Bang", "TT0901", 2009);
    list.themSinhVien(newSV);

    // In danh sách ra màn hình
    cout << "\nDanh sach sinh vien sau khi thay doi:" << endl;
    list.inDanhSach();

    return 0;
}