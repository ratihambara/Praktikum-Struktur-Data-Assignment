#include <iostream>
using namespace std;

struct Buku {
    string judul_buku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_buku[5];
    double harga_buku[5];
}; 

Buku buku;

void tampilkanBuku(int index) {
    cout << "Informasi Buku" << endl;
    cout << "Judul : " << buku.judul_buku[index] << endl;
    cout << "Pengarang : " << buku.pengarang[index] << endl;
    cout << "Penerbit : " << buku.penerbit[index] << endl;
    cout << "Tebal Halaman : " << buku.tebal_buku[index] << endl;
    cout << "Harga Buku : " << buku.harga_buku[index] << endl;
}

int main(){
    // Isi data buku
    for (int i = 0; i < 5; i++) {
        buku.judul_buku[i] = "Judul Buku " + to_string(i+1);
        buku.pengarang[i] = "Pengarang " + to_string(i+1);
        buku.penerbit[i] = "Penerbit " + to_string(i+1);
        buku.tebal_buku[i] = 100 + (i * 20);
        buku.harga_buku[i] = 50000 + (i * 10000);
    }

    // Tampilkan data buku
    for (int i = 0; i < 5; i++) {
        tampilkanBuku(i);
    }

    return 0;
}
