#include <iostream>
#include <vector>
#include <algorithm>   // untuk std::sort

using namespace std;

// Fungsi untuk melakukan pencarian menggunakan Sequential Search
int sequentialSearch(const vector<int>& data, int target) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == target) {
            return i;   // Mengembalikan indeks jika elemen ditemukan
        }
    }
    return -1;  // Mengembalikan -1 jika elemen tidak ditemukan
}

// Fungsi untuk melakukan pencarian menggunakan Binary Search
int binarySearch(const vector<int>& data, int target) {
    int low = 0;
    int high = data.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;   // Mencari elemen tengah
        if (data[mid] == target) {
            return mid;   // Mengembalikan indeks jika elemen ditemukan
        } else if (data[mid] < target) {
            low = mid + 1;   // Pindah ke bagian kanan
        } else {
            high = mid - 1;  // Pindah ke bagian kiri
        }
    }
    return -1;  // Mengembalikan -1 jika elemen tidak ditemukan
}

int main() {
    vector<int> data;
    int n, target, choice;

    // Input data secara dinamis dari pengguna
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    cout << "Masukkan elemen-elemen (dipisahkan dengan spasi): ";
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        data.push_back(temp);  // Menyimpan elemen-elemen yang dimasukkan ke dalam vektor
    }

    cout << "Masukkan elemen yang ingin dicari: ";
    cin >> target;

    // Memilih metode pencarian
    cout << "\nPilih metode pencarian:" << endl;
    cout << "1. Sequential Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "Masukkan pilihan Anda (1/2): ";
    cin >> choice;

    if (choice == 1) {
        // Sequential Search
        int result = sequentialSearch(data, target);
        if (result != -1) {
            cout << "Elemen ditemukan pada indeks ke-" << result << " menggunakan Sequential Search." << endl;
        } else {
            cout << "Elemen tidak ditemukan menggunakan Sequential Search." << endl;
        }
    } else if (choice == 2) {
        // Binary Search (hanya bisa dilakukan jika data terurut)
        sort(data.begin(), data.end());  // Mengurutkan data terlebih dahulu
        cout << "Data setelah diurutkan: ";
        for (int i = 0; i < n; i++) {
            cout << data[i] << " ";
        }
        cout << endl;

        int result = binarySearch(data, target);
        if (result != -1) {
            cout << "Elemen ditemukan pada indeks ke-" << result << " menggunakan Binary Search." << endl;
        } else {
            cout << "Elemen tidak ditemukan menggunakan Binary Search." << endl;
        }
    } else {
        cout << "Pilihan tidak valid! Harap pilih 1 atau 2." << endl;
    }

    return 0;
}