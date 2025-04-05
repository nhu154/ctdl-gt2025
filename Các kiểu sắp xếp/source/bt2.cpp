#include <iostream>
using namespace std;
struct SoHang { //Khai bao cau truc so hang
	double heSo;
	int bac;
};
void insertionSort(SoHang dathuc[], int soLuong) { //Thuat toan sap xep chen
	for (int i = 1; i < soLuong; i++) {
		SoHang temp = dathuc[i];
		int j = i - 1;
		while (j >= 0 && dathuc[j].bac > temp.bac) {
			dathuc[j + 1] = dathuc[j];
			j--;
		}
		dathuc[j + 1] = temp;
	}
}
int main() {
	int soLuong;
	cout << "Nhap so luong so hang: "; //Nhap so luong
	cin >> soLuong;
	SoHang* dathuc = new SoHang[soLuong];
	cout << "Nhap cac so hang va bac tuong ung: ";
	for (int i = 0; i < soLuong; i++) { //Nhap so hang va bac
		cout << "Nhap so hang thu " << i + 1 << ": ";
		cin >> dathuc[i].heSo >> dathuc[i].bac;
	}
	insertionSort(dathuc, soLuong); //Sap xep 
	cout << "Day thuc sau khi sap xep: \n";
	for (int i = 0; i < soLuong; i++) {
		cout << dathuc[i].heSo << "x^" << dathuc[i].bac << " ";
	}
	delete[] dathuc;
	cout << endl;
	return 0;
}