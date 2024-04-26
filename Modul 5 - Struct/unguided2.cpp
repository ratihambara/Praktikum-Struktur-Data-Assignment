#include <iostream>
using namespace std;

struct Buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    int tebal_buku;
    double harga_buku;
}; 

Buku buku[5];

void tampilkanBuku(int index) {
    cout << "Informasi Buku" << endl;
    cout << "Judul : " << buku[index].judul_buku << endl;
    cout << "Pengarang : " << buku[index].pengarang << endl;
    cout << "Penerbit : " << buku[index].penerbit << endl;
    cout << "Tebal Halaman : " << buku[index].tebal_buku << endl;
    cout << "Harga Buku : " << buku[index].harga_buku << endl;
}

int main(){
    // Isi data buku
    for (int i = 0; i < 5; i++) {
        buku[i].judul_buku = "Judul Buku " + to_string(i+1);
        buku[i].pengarang = "Pengarang " + to_string(i+1);
        buku[i].penerbit = "Penerbit " + to_string(i+1);
        buku[i].tebal_buku = 100 + (i * 20);
        buku[i].harga_buku = 50000 + (i * 10000);
    }

    // Tampilkan data buku
    for (int i = 0; i < 5; i++) {
        tampilkanBuku(i);
    }

    return 0;
}
