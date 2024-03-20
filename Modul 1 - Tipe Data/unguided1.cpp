#include<iostream>
using namespace std;

// Fungsi untuk menambahkan dua bilangan
int tambah(int a, int b) {
    return a + b;
}

// Fungsi untuk mengalikan dua bilangan
int kali(int a, int b) {
    return a * b;
}

int main() {
    int x = 5;
    int y = 10;

    cout << "Hasil penjumlahan x dan y adalah: " << tambah(x, y) << endl;
    cout << "Hasil perkalian x dan y adalah: " << kali(x, y) << endl;

    return 0;
}
