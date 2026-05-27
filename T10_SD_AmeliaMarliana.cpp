#include <iostream>
using namespace std;

void sequentialSearchCount(int arr[], int n, int cari) {
	int jumlah = 0;

	for(int i = 0; i < n; i++) {
		if(arr[i] == cari) {
			cout << "Angka " << cari
			     << " ditemukan pada indeks ke-"
			     << i << endl;

			jumlah++;
		}
	}

	if(jumlah > 0) {
		cout << "\nTotal angka " << cari
		     << " muncul sebanyak "
		     << jumlah << " kali" << endl;
	}
	else {
		cout << "Angka tidak ditemukan" << endl;
	}
}

int main() {
	int data[] = {9, 2, 5, 2, 7, 6, 11, 2};

	int ukuran = sizeof(data) / sizeof(data[0]);
	int cari = 2;

	cout << "Isi array : ";

	for(int i = 0; i < ukuran; i++) {
		cout << data[i] << " ";
	}

	cout << "\n\nProses Sequential Search\n\n";

	sequentialSearchCount(data, ukuran, cari);

	return 0;
}
