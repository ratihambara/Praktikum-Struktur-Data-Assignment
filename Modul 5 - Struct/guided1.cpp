#include <iostream>
using namespace std;

struct Buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    int tebal_buku;
    double harga_buku;
}; Buku buku1, buku2;

 int main(){

buku1.judul_buku = "Algoritma Pemrograman";
buku1.pengarang = "Yunus Prademon";
buku1.penerbit = "Gramedia Pustaka Utama";
buku1.tebal_buku = 300;
buku1.harga_buku = 120000;

//Menampilkan data
cout << "Informasi Buku" << endl;
cout << "Judul : " << buku1.judul_buku << endl;
cout << "Pengarang : " << buku1.pengarang << endl;
cout << "Penerbit : " << buku1.penerbit << endl;
cout << "Tebal Halaman : " << buku1.tebal_buku << endl;
cout << "Harga Buku : " << buku1.harga_buku << endl;


buku2.judul_buku = "Kamil Forever";
buku2.pengarang = "Ikhwan Dedianto";
buku2.penerbit = "Gramedia Tangerang";
buku2.tebal_buku = 200;
buku2.harga_buku = 100000;

//Menampilkan data
cout << "Buku Favorit" << endl;
cout << "Judul : " << buku2.judul_buku << endl;
cout << "Pengarang : " << buku2.pengarang << endl;
cout << "Penerbit : " << buku2.penerbit << endl;
cout << "Tebal Halaman : " << buku2.tebal_buku << endl;
cout << "Harga Buku : " << buku2.harga_buku << endl;

return 0;
}
