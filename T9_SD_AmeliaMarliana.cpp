#include <iostream>
#include <string>

using namespace std;

// Fungsi pembantu buat nampilin data biar gak ngetik loop berkali-kali
void cetakArray(string arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Pake Selection Sort karena logikanya paling gampang diinget
void selectionSortDescending(string arr[], int n) {
	int max_idx;
	string temp;

	for (int i = 0; i < n - 1; i++) {
		// Anggap indeks ke-i adalah yang paling besar dulu
		max_idx = i;

		for (int j = i + 1; j < n; j++) {
			// Karena maunya descending (Z ke A), cari yang secara alfabet lebih besar
			if (arr[j] > arr[max_idx]) {
				max_idx = j;
			}
		}

		// Tukar posisi (Swap)
		temp = arr[max_idx];
		arr[max_idx] = arr[i];
		arr[i] = temp;
	}
}

int main() {
	// Data sesuai soal di modul
	string data[] = {"zebra", "ayam", "sapi", "kambing"};
	int n = sizeof(data) / sizeof(data[0]);

	cout << "Original Array: ";
	cetakArray(data, n);

	// Proses pengurutan
	selectionSortDescending(data, n);

	cout << "Sorted Array (Descending): ";
	cetakArray(data, n);

	return 0;
}
