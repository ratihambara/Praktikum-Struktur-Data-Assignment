# Praktikum-Struktur-Data-Assignment
# <h1 align="center">Laporan Praktikum Modul Rekursif & Hash Table</h1>
<p align="center">Ratih Ambara Sukma Kurnilia</p>

## Dasar Teori

A. Rekursif merupakan salah satu proses pengulangan fungsi yang memanggil dirinya sendiri. Dalam sebuah fungsi rekursif pemanggilan dapat terjadi berulang kali. Karena ada proses yang berulang-ulang maka harus ada suatu kondisi yang mengakhiri prosesnya.
Jenis-jenis Rekursif:

1) Rekursif Langsung
  Fungsi memanggil dirinya sendiri secara langsung.

2) Rekursif Tidak Langsung
  Fungsi memanggil dirinya sendiri secara tidak langsung atau dari fungsi lain.

Kelebihan Rekursif :
1) Memberikan solusi yang mudah dimengerti
2) Terbukti efektif untuk menangani masalah yang dapat diuraikan menjadi sub masalah serupa
3) Memberikan kode yang lebih kompak dibanding iteratif

Kekurangan Rekursif :
1) Efisiensi ruang menjadi masalah utama
2) Beberapa implementasi rekursif kurang efisien secara waktu
3) Kesulitan dalam pemahaman konsep rekursi 

B. Hash Table adalah struktur data yang mengorganisir data ke dalam pasangan kunci nilai. Hash table biasanya terdiri dari dua komponen utama yaitu array (atau vektor) dan fungsi hash. Array menyimpan data dalam slot-slot yang disebut bucket. Hash table memungkinkan pencarian data dalam waktu yang konstan (O(1)) dalam kasus terbaik. Fungsi hash membuat pemetaan antara kunci dan nilai.
Operasi hash table :
1) Insertion = Memasukkan data baru ke dalam hash table
2) Deletion = Menghapus data dari hash table
3) Searching = Mencari data dalam hash table
4) Update = Memperbarui data dalam hash table
5) Traversal = Memproses semua data yang ada dalam hash table

Keterbatasan tabel hash adalah jika dua angka dimasukkan ke dalam fungsi hash menghasilkan nilai yang sama. Hal ini disebut dengan collision, cara menyelesaikannya :
1) Open Hashing (Chaining) = menyimpan semua item data dengan nilai indeks yang sama ke dalam sebuah linked list.
2) Closed Hashing = Linear Probing (mencari posisi yang kosong di bawah tempat terjadinya collision), Quadratic Probing (penanganannya hampir sama dengan metode linear, hanya lompatannya tidak satu-satu, tetapi quadratic), Double Hashing (terdapat fungsi hash yang kedua untuk menentukan posisinya kembali).

## Guided 

### 1. Rekursif Langsung (Direct Recursion)

```C++
#include <iostream>
using namespace std;

//Code ini berfungsi untuk melakukan hitung mundur
//dari angka yang diinputkan

void countdown(int n)
{
 if (n == 0) {
  cout << "Blastoff!" << endl; // Base case: print "Blastoff!" when n is 0
  return;
 }
 cout << n << " "; // Recursive case: print n and decrement n
 countdown(n - 1);
}

int main() {
 cout << "Rekursif Langsung: ";
 countdown(5); // 5 merupakan input nya
 cout << endl;
 return 0;
} 
```

### 2. Rekursif Tidak Langsung (Indirect Recursion)

```C++
#include <iostream>
using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1); // Panggilan rekursif tidak langsung
    }
} 
void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2); // Panggilan rekursif tidak langsung
    }
}
int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung: ";
    functionA(num);
    return 0;
} 
```

### 3. Hash Table

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;
class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
         int hash_val = 0;
         for (char c : key) {
            hash_val += c;
        }
    return hash_val % TABLE_SIZE; // 4 bisa aja 204,12004, 6 bisa aja
266, 300;
    }
    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
    int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it !=
table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                 table[hash_val].erase(it);
                 return;
            }
        }
    }
string searchByName(string name) {
int hash_val = hashFunc(name);
for (auto node : table[hash_val]) {
    if (node->name == name) {
        return node->phone_number;
    }
}
return "";
}
void print() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << ": ";
            for (auto pair : table[i]) {
            if(pair != nullptr){
                cout << "[" << pair->name << ", " <<
pair->phone_number << "]";
                }           
            }
            cout << endl;
        }
    }
};

int main() {
HashMap employee_map;

employee_map.insert("Mistah", "1234");
employee_map.insert("Pastah", "5678");
employee_map.insert("Ghana", "91011");

cout << "Nomer Hp Mistah : " <<employee_map.searchByName("Mistah") <<
endl;
cout << "Phone Hp Pastah : " <<employee_map.searchByName("Pastah") <<
endl;
cout << "Phone Hp Ghana : " <<employee_map.searchByName("Ghana") <<
endl;

employee_map.remove("Mistah");

cout << "Nomer Hp Mistah setelah dihapus : "
<<employee_map.searchByName("Mistah") << endl << endl;\

cout << "Hash Table : " << endl;
employee_map.print();

return 0;
}
```

## Unguided 

### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!
Contoh Output:
Masukkan bilangan bulat positif: 5
Faktorial dari 5 adalah: 120

```C++
#include <iostream>
using namespace std;

int hitungFactorial(int input) {
    if (input > 1)
        return input * hitungFactorial(input - 1);
    else
        return 1;
}

int main() {
    cout << "## Program C++ Hitung Faktorial ##" << endl;
    cout << "===================================" << endl;
    cout << endl;

    int angka;
    cout << "Input angka: ";
    cin >> angka;

    cout << angka << "! = " << hitungFactorial(angka);
    cout << endl;

    return 0;
}
```
#### Output:
![Screenshot 2024-04-26 105533](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/dad85963-58eb-4491-a52f-8a8f8f9dd9fe)

Kode ini menggunakan fungsi hitungFactorial yang menerima inputan angka dan menghitung faktorialnya secara rekursif. Fungsi ini memanggil dirinya sendiri dengan mengurangi nilai input sebanyak satu setiap kali hingga mencapai angka 1.

### 2.   Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 di atas!

```C++
#include <iostream>
using namespace std;

int hitungFactorial(int input);

int main() {
    cout << "## Program C++ Hitung Faktorial (Indirect Recursion) ##" << endl;
    cout << "======================================================" << endl;
    cout << endl;

    int angka;
    cout << "Input angka: ";
    cin >> angka;

    cout << angka << "! = " << hitungFactorial(angka);
    cout << endl;

    return 0;
}

int hitungFactorial(int input) {
    if (input > 1)
        return input * hitungFactorial(input - 1);
    else
        return 1;
}
```
#### Output:
![Screenshot 2024-04-26 105728](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/df6bd4d8-813d-4627-976d-c28002973985)

Kode ini menggunakan dua fungsi: main dan hitungFactorial. Fungsi hitungFactorial adalah fungsi rekursif yang menghitung faktorial dengan cara memanggil dirinya sendiri hingga mencapai angka 1. Fungsi ini akan mengalikan nilai input dengan hasil faktorial dari input dikurangi 1.

### 3.   Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai.
Dengan ketentuan :
a. Setiap mahasiswa memiliki NIM dan nilai.
b. Program memiliki tampilan pilihan menu berisi poin C.
c. Implementasikan fungsi untuk menambahkan data baru, menghapus data,
mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai
(80 – 90).

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

class HashNode {
public:
    string nim;
    int nilai;

    HashNode(string nim, int nilai) {
        this->nim = nim;
        this->nilai = nilai;
    }
};

class HashTable {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string nim, int nilai) {
        int hash_val = hashFunc(nim);

        for (auto node : table[hash_val]) {
            if (node->nim == nim) {
                node->nilai = nilai;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(nim, nilai));
    }

    void remove(string nim) {
        int hash_val = hashFunc(nim);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->nim == nim) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    int searchByNim(string nim) {
        int hash_val = hashFunc(nim);
        for (auto node : table[hash_val]) {
            if (node->nim == nim) {
                return node->nilai;
            }
        }
        return -1; // not found
    }

    void searchByNilai(int nilaiAwal, int nilaiAkhir) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            for (auto node : table[i]) {
                if (node->nilai >= nilaiAwal && node->nilai <= nilaiAkhir) {
                    cout << "NIM: " << node->nim << ", Nilai: " << node->nilai << endl;
                }
            }
        }
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->nim << ", " << pair->nilai << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable student_table;

    student_table.insert("12345", 80);
    student_table.insert("67890", 90);
    student_table.insert("11111", 85);

    cout << "Nilai 12345: " << student_table.searchByNim("12345") << endl;
    cout << "Nilai 67890: " << student_table.searchByNim("67890") << endl;
    cout << "Nilai 11111: " << student_table.searchByNim("11111") << endl;

    student_table.remove("12345");

    cout << "Nilai 12345 setelah dihapus: " << student_table.searchByNim("12345") << endl << endl;

    cout << "Cari nilai antara 80-90: " << endl;
    student_table.searchByNilai(80, 90);

    cout << "Hash Table: " << endl;
    student_table.print();

    return 0;
}
```
#### Output:

Pada program di atas, kita menggunakan hash table dengan metode separate chaining untuk mengelola data mahasiswa berdasarkan NIM dan nilai. Fungsi insert, remove, dan searchByNilai digunakan untuk menambah, menghapus, dan mencari data berdasarkan NIM.

## Kesimpulan
Rekursif merupakan salah satu proses pengulangan fungsi yang memanggil dirinya sendiri. Dalam sebuah fungsi rekursif pemanggilan dapat terjadi berulang kali. Sedangkan Hash Table adalah struktur data yang mengorganisir data ke dalam pasangan kunci nilai. Hash table biasanya terdiri dari dua komponen utama yaitu array (atau vektor) dan fungsi hash.

## Referensi
Sjukani, Moh. 2007. Struktur Data (Algoritma & Struktur Data 2) dengan C, C++. Jakarta : Penerbit Mitra Wacana Media.

[TylerMSFT. (n.d.). Collections (C++/CX). diakses dari https://learn.microsoft.com/en-us/cpp/cppcx/collections-c-cx?view=msvc-170](https://copilot.microsoft.com/?FORM=undexpand&)

