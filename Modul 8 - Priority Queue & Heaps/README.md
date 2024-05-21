# Praktikum-Struktur-Data-Assignment
# <h1 align="center">Laporan Praktikum Modul Struct</h1>
<p align="center">Ratih Ambara Sukma Kurnilia</p>

## Dasar Teori

Struct merupakan tipe data bentukan yang terdiri dari beberapa tipe data standar maupun tipe data bentukan lainnya yang telah didefinisikan sebelumnya. Keyword yang digunakan untuk membuat sebuah struktur yakni struct(). Terdapat banyak format penulisan struct diantaranya :

1) struct { 
         string namaDepan; 
         string namaBelakang;
         int usia;
         char jenis_kelamin;
   }namaVariabelStrukA, namaVariabelStrukB;
   
2) struct namaTipe{
         string namaDepan;
         string namaTengah;
         string namaBelakang;
   }; struct namaTipe namaVariabelStrukA, namaVariabelStrukB;
   
3) typedef struct {
         string namaDepan;
         string namaTengah;
         string namaBelakang;
   }namaTipe;
   namaTipe namaVariabelStrukA, namaVariabelStrukB;

## Guided 

### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.

```C++
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
```

### 2. Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.
![Screenshot 2024-04-26 110921](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/ad20cd66-d889-49ac-af8a-1206f26c8769)

```C++
#include <iostream>
using namespace std;

struct Hewan{
    string nama_hewan;
    string jenis_kelamin;
    string kembangbiak;
    string pernapasan;
    string tempat_hidup;
    bool karnivora;
}; 
Hewan info_hewan;

struct Hewan_drt{
    Hewan info_hewan;
    int jumlah_kaki;
    bool apakah_menyusui;
    string suara;
};
Hewan_drt hewan1;

struct Hewan_lt{
    Hewan info_hewan;
    string bentuk_sirip;
    string pertahanan_diri;
};
Hewan_lt hewan2;

int main() {
    //Hewan Darat
    hewan1.info_hewan.nama_hewan = "Kucing";
    hewan1.info_hewan.jenis_kelamin = "Jantan";
    hewan1.info_hewan.kembangbiak = "Melahirkan";
    hewan1.info_hewan.pernapasan = "Paru-paru";
    hewan1.info_hewan.tempat_hidup = "Daratan";
    hewan1.info_hewan.karnivora = true;
    hewan1.jumlah_kaki = 4;
    hewan1.apakah_menyusui = true;
    hewan1.suara = "Meow";

    //Hewan Laut
    hewan2.info_hewan.nama_hewan = "Penyu";
    hewan2.info_hewan.jenis_kelamin = "Betina";
    hewan2.info_hewan.kembangbiak = "Bertelur";
    hewan2.info_hewan.pernapasan = "Paru-paru dan insang";
    hewan2.info_hewan.tempat_hidup = "Lautan";
    hewan2.info_hewan.karnivora = false;
    hewan2.bentuk_sirip = "Sirip dan ekor";
    hewan2.pertahanan_diri = "Cangkang yang kuat";

    //Menampilkan data
    cout << "\tHewan Darat" << endl;
    cout << "Nama Hewan : " << hewan1.info_hewan.nama_hewan << endl;
    cout << "Jenis Kelamin : " << hewan1.info_hewan.jenis_kelamin << endl;
    cout << "Kembangbiak : " << hewan1.info_hewan.kembangbiak << endl;
    cout << "Alat Pernapasan : " << hewan1.info_hewan.pernapasan << endl;
    cout << "Tempat Hidup : " << hewan1.info_hewan.tempat_hidup << endl;
    cout << "Apakah Karnivora? " << hewan1.info_hewan.karnivora << endl;
    cout << "Jumlah Kaki : " << hewan1.jumlah_kaki << endl;
    cout << "Apakah Menyusui? " << hewan1.apakah_menyusui << endl;
    cout << "Suara : " << hewan1.suara << endl;

    cout << "\tHewan Laut" << endl;
    cout << "Nama Hewan : " << hewan2.info_hewan.nama_hewan << endl;
    cout << "Jenis Kelamin : " << hewan2.info_hewan.jenis_kelamin << endl;
    cout << "Kembangbiak : " << hewan2.info_hewan.kembangbiak << endl;
    cout << "Alat Pernapasan : " << hewan2.info_hewan.pernapasan << endl;
    cout << "Tempat Hidup : " << hewan2.info_hewan.tempat_hidup << endl;
    cout << "Apakah Karnivora? " << hewan2.info_hewan.karnivora << endl;
    cout << "Bentuk Sirip : " << hewan2.bentuk_sirip << endl;
    cout << "Pertahanan Diri : " << hewan2.pertahanan_diri << endl;

    return 0; 
}
```

## Unguided 

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.

```C++
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
```
#### Output:
![Screenshot 2024-04-26 105533](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/dad85963-58eb-4491-a52f-8a8f8f9dd9fe)

Kode ini mengisi setiap item dalam struct Buku dengan array berukuran 5 dan menampilkan informasi buku tersebut.

### 2.   Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya ?

```C++
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
```
#### Output:
![Screenshot 2024-04-26 105728](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/df6bd4d8-813d-4627-976d-c28002973985)

Kode ini mengubah variabel struct buku1 dan buku2 menjadi array buku berukuran 5. Fungsi tampilkanBuku digunakan untuk menampilkan informasi buku berdasarkan indeks dalam array.

## Kesimpulan
Struct merupakan tipe data bentukan yang terdiri dari beberapa tipe data standar maupun tipe data bentukan lainnya yang telah didefinisikan sebelumnya. Keyword yang digunakan untuk membuat sebuah struktur yakni struct().

## Referensi
Sjukani, Moh. 2007. Struktur Data (Algoritma & Struktur Data 2) dengan C, C++. Jakarta : Penerbit Mitra Wacana Media.

[TylerMSFT. (n.d.). Collections (C++/CX). diakses dari https://learn.microsoft.com/en-us/cpp/cppcx/collections-c-cx?view=msvc-170](https://copilot.microsoft.com/?FORM=undexpand&)

