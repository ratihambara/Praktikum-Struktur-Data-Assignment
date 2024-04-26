# Praktikum-Struktur-Data-Assignment
# <h1 align="center">Laporan Praktikum Algoritma Searching</h1>
<p align="center">Ratih Ambara Sukma Kurnilia</p>

## Dasar Teori

Searching yaitu proses menemukan suatu nilai tertentu pada kumpulan data. Searching juga merpakan proses pencarian suatu data di dalam sebuah array dengan cara mengecek satu persatu pada setiap index baris atau kolom dengan menggunakan teknik perulangan.
Terdapat 2 metode pada algoritma Searching, yaitu:

1) Sequential Search
   Merupakan salah satu algoritma pencarian data yang biasa digunakan untuk data yang berpola acak atau belum terurut. Konsep Sequential Search yaitu:
   a) Membandingkan setiap elemen pada array satu per satu secara berurut
   
   b) Pencarian dimulai dari indeks pertama hingga indeks terakhir
   
   c) Pencarian akan berhenti apabila data ditemukan
   
   d) Perulangan pada pencarian akan terjadi sebanyak jumlah N elemen pada array

2) Binary Search
   Merupakan algoritma pencarian pada array/ list dengan elemen terurut. Konsep Binary Search:
   a) Data dibagi menjadi dua untuk mendapatkan posisi data tengah.

   b) data yang dicari dibandingkan dengan data yang berada di posisi tengah, apakah lebih besar atau lebih kecil.

   c) Apabila data yang dicari lebih besar dari data tengah, maka data yang dicari berada di sebelah kanan dari data tengah. Selanjutnya dilakukan pembagian data menjadi dua bagian pada bagian kanan dan data tengah akan menjadi posisi awal untuk pembagian tersebut.

   d) Apabila data yang dicari lebih kecil dari data tengah, maka data yang dicari berada di sebelah kiri dari data tengah. Selanjutnya akan dilakukan pembagian data menjadi dua bagian pada bagian kiri dan data tengah akan menjadi posisi akhir untuk pembagian tersebut.

   e) Pencarian akan terus berlanjut seperti proses c dan d hingga data ditemukan.

   f) Apabila data bernilai sama, maka data yang dicari ditemukan dan pencarian dihentikan.

## Guided 

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.

```C++
#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
    // Algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
            break;
        }
    }

    cout << "\t Program Sequential Search Sederhana\n" << endl;
    cout << " Data : {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    if (ketemu) {
        cout << "\n Angka " << cari << " ditemukan pada indeks ke- " << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }

    return 0;
}
```

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search

```C++
#include <iostream>
#include <iomanip>

using namespace std;

int bil_data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for(i = 0; i < 7; i++) {
        min = i;
        for(j = i + 1; j < 7; j++) {
            if(bil_data[j] < bil_data[min]) {
                min = j;
            }
        }
        temp = bil_data[i];
        bil_data[i] = bil_data[min];
        bil_data[min] = temp;
    }
}

void binary_search() {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 6;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(bil_data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(bil_data[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if(b_flag == 1) {
        cout << "\n Data ditemukan pada index ke-" << tengah << endl;
    } else {
        cout << "\n Data tidak ditemukan\n";
    }
}

int main() {
    cout << "\t BINARY SEARCH\n";
    cout << "\n Data : ";
    // tampilkan data awal
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }
    cout << endl;
    cout << "\n Masukkan data yang ingin Anda cari : ";
    cin >> cari;
    cout << "\n Data diurutkan : ";
    // urutkan data dengan selection sort
    selection_sort();
    // tampilkan data setelah diurutkan
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }
    cout << endl;
    binary_search();
    return 0;
}
```

## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include <algorithm>
#include <iostream>
#include <string>

bool binarySearch(const std::string& str, char x) {
    int l = 0, r = str.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (str[m] == x)
            return true;
        if (str[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return false;
}

int main() {
    std::string kalimat;
    char huruf;

    std::cout << "Masukkan kalimat: ";
    std::getline(std::cin, kalimat);

    std::cout << "Masukkan huruf yang dicari: ";
    std::cin >> huruf;

    std::sort(kalimat.begin(), kalimat.end());

    if(binarySearch(kalimat, huruf))
        std::cout << "Huruf " << huruf << " ditemukan dalam kalimat.\n";
    else
        std::cout << "Huruf " << huruf << " tidak ditemukan dalam kalimat.\n";

    return 0;
}
```
#### Output:
![Screenshot 2024-04-26 093954](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/a3a0accf-504d-4776-a925-4e59a74f592d)

Program ini akan meminta user untuk memasukkan kalimat dan huruf yang dicari. Kemudian, program akan mengurutkan huruf-huruf dalam kalimat dan mencari huruf yang dicari menggunakan Binary Search. Jika huruf tersebut ditemukan, program akan mencetak pesan bahwa huruf tersebut ditemukan. Jika tidak, program akan mencetak pesan bahwa huruf tersebut tidak ditemukan.

### 2.  Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
#include <iostream>
#include <string>

int hitungVokal(const std::string& kalimat) {
    int jumlahVokal = 0;
    for (char c : kalimat) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            jumlahVokal++;
        }
    }
    return jumlahVokal;
}

int main() {
    std::string kalimat;
    std::cout << "Masukkan kalimat: ";
    std::getline(std::cin, kalimat);

    int jumlahVokal = hitungVokal(kalimat);
    std::cout << "Jumlah huruf vokal dalam kalimat adalah: " << jumlahVokal << "\n";

    return 0;
}
```
#### Output:
![Screenshot 2024-03-20 090021](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/e0b89c4a-ab3e-4bf9-90e8-5edce35db24f)

Program ini akan meminta user untuk memasukkan kalimat. Kemudian, program akan menghitung jumlah huruf vokal dalam kalimat tersebut dan mencetak jumlahnya. Huruf vokal yang dihitung adalah ‘a’, ‘e’, ‘i’, ‘o’, dan ‘u’, baik dalam bentuk huruf kecil maupun huruf besar.

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search

```C++
#include <iostream>

int sequentialSearch(int data[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size = sizeof(data) / sizeof(data[0]);
    int target = 4;

    int jumlah = sequentialSearch(data, size, target);
    std::cout << "Data : 9, 4, 1, 4, 7, 10, 5, 4, 12, 4 " << "\n";
    std::cout << "Jumlah angka " << target << " dalam data adalah: " << jumlah << "\n";

    return 0;
}
```
#### Output:
![Screenshot 2024-03-20 090102](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/935ed45e-06de-442e-b17d-8ddf840b1ae9)

Program ini akan mencari dan menghitung jumlah angka 4 dalam array data. Jika angka 4 ditemukan, count akan bertambah. Kemudian, program akan mencetak jumlah angka 4 dalam array.

## Kesimpulan
Searching yaitu proses menemukan suatu nilai tertentu pada kumpulan data. Searching juga merpakan proses pencarian suatu data di dalam sebuah array dengan cara mengecek satu persatu pada setiap index baris atau kolom dengan menggunakan teknik perulangan.Terdapat 2 metode pada algoritma Searching, yaitu: Sequential Search dan Binary Search.

## Referensi
Karumanchi, N. (2016). Data Structures and algorithms made easy: Concepts, problems, Interview Questions. CareerMonk Publications.


