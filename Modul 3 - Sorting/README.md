# Praktikum-Struktur-Data-Assignment
# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Ratih Ambara Sukma Kurnilia</p>

## Dasar Teori

Algoritma sorting adalah algoritma yang digunakan untuk meletakkan kumpulan elemen data dalam urutan tertentu, berdasarkan beberapa kunci tertentu pada tiap-tiap elemen. Algoritma sorting dibagi menjadi dua jenis, yaitu:
1) Ascending
   Adalah pengurutan dari terkecil hingga terbesar 
   Contoh: a, b, c, d, e

2) Descending
   Adalah pengurutan dari terbesar hingga terkecil
   Contoh: e, d, c, b, a

Macam-macam algoritma sorting:
1) Insertion Sort
   Cara mengurutkannya adalah dicek satu persatu mulai dari yang kedua sampai dengan yang terakhir. Apabila ditemukan data yang lebih kecil dari data sebelumnya, maka data tersebut disisipkan pada posisi yang sesuai.
   
2) Bubble Sort
   Cara mengurutkannya adalah membandingkan elemen yang sekarang dengan elemen yang 
berikutnya. Jika elemen sekarang lebih besar dari elemen berikutnya, maka kedua elemen ditukar.

3) Selection Sort
   Cara mengurutkannya adalah dengan membandingkan elemen sekarang dengan elemen yang 
berikutnya sampai terakhir. Jika ditemukan elemen paling kecil, kemudian ditukar dengan elemen sekarang.

## Guided 

### 1. Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort

```C++
#include <iostream>
using namespace std;

// Fungsi untuk mengurutkan array secara ascending menggunakan algoritma bubble sort
void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tmp;

    // Membandingkan dan menukar elemen
    while (not_sorted){
        // Menukar elemen
        not_sorted = false;
        j++;
     
        for (int i = 0; i < length - j; i++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }//end of for loop
    }//end of while loop
}//end of bubble_sort

// Fungsi untuk mencetak isi array
void print_array(double a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99,99};

    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    // Memanggil fungsi bubble_sort_ascending untuk mengurutkan array secara ascending
    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);

    return 0;
}
```

### 2. Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort

```C++
#include <iostream>
using namespace std;

// Fungsi untuk mengurutkan array secara descending menggunakan algoritma insertion sort
void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;

    for (i = 1; i < length; i++) {
        j = i;

        // Membandingkan dan menukar elemen
        while (j > 0 && arr[j - 1] < arr[j]) {
            // Menukar elemen
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }//end of while loop
    }//end of for loop
}

// Fungsi untuk mencetak isi array
void print_array(char a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    // Memanggil fungsi insertion_sort_descending untuk mengurutkan array secara descending
    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);

    return 0;
}
```

## Unguided 

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort! 

```C++
#include <iostream>
using namespace std;

void selectionSort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int pos_min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[pos_min]) {
                pos_min = j;
            }
        }
        if (pos_min != i) {
            swap(arr[i], arr[pos_min]);
        }
    }
}

void printIPS(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    double ips[] = {3.8, 2.9, 3.3, 4.0, 2.4};
    int n = sizeof(ips) / sizeof(ips[0]);

    cout << "IPS sebelum diurutkan: ";
    printIPS(ips, n);

    selectionSort(ips, n);

    cout << "IPS setelah diurutkan (dari terbesar hingga terkecil): ";
    printIPS(ips, n);

    return 0;
}
```
#### Output:
![Screenshot 2024-04-07 120235](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/698a566d-a2f4-431a-8a5d-4e5358f5ffcf)

Program ini menggambarkan algoritma selection sort. Fungsi selectionSort mengurutkan array (arr) dengan mencari elemen terkecil dan menukarnya dengan elemen pertama pada bagian yang belum terurut. Fungsi printArray hanya mencetak isi array yang sudah terurut.
Contoh Hasil Keluaran: Jika menjalankan kode ini dengan array input {3.8, 2.9, 3.3, 4.0, 2.4}, maka hasilnya akan mengurutkan array tersebut secara menaik, menjadi 2.4    2.9    3.3    3.8    4.0

### 2.  Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan nama-nama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!

```C++
#include <iostream>
#include <string>
using namespace std;

void bubbleSort(string names[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (names[j] > names[j + 1]) {
                swap(names[j], names[j + 1]);
            }
        }
    }
}

void printNames(string names[], int n) {
    for (int i = 0; i < n; i++) {
        cout << names[i] << " ";
    }
    cout << endl;
}

int main() {
    const int numWarga = 10;
    string wargaNames[numWarga] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

    cout << "Nama-nama warga sebelum diurutkan: ";
    printNames(wargaNames, numWarga);

    bubbleSort(wargaNames, numWarga);

    cout << "Nama-nama warga setelah diurutkan (berdasarkan alfabet): ";
    printNames(wargaNames, numWarga);

    return 0;
}
```
#### Output:
![Screenshot 2024-04-07 120150](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/dc074ad6-8570-418e-a4c2-e354a031f137)

Program ini mengimplementasikan algoritma bubble sort dalam bahasa C++ dan mengurutkan nama-nama warga berdasarkan alfabet dengan cara membandingkan dan menukar elemen-elemen yang tidak terurut.
Fungsi bubbleSort membandingkan setiap pasangan nama dan menukarnya jika urutannya salah. Fungsi printNames hanya mencetak nama-nama yang sudah terurut.
Contoh Hasil Keluaran: Jika menjalankan kode ini dengan array nama warga yang diberikan, yaitu {siti, situ, sana, ana, ani, caca, cici, dida, dodo, dadi}, maka hasilnya akan mengurutkan nama-nama warga berdasarkan alfabet: ana ani caca cici dadi dida dodo sana siti situ.

### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!
![Screenshot 2024-04-07 123620](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/8419d4a8-7d3b-46dc-9377-618ab6b43c37)

```C++
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Masukkan bilangan bulat n: ";
    cin >> n;

    char karakter[n];
    cout << "Masukkan " << n << " karakter: ";
    for (int i = 0; i < n; ++i) {
        cin >> karakter[i];
    }

    // Mengurutkan karakter secara menaik (ascending)
    sort(karakter, karakter + n);

    cout << "\nUrutan karakter setelah ascending sort: ";
    for (int i = 0; i < n; ++i) {
        cout << karakter[i] << " ";
    }

    // Mengurutkan karakter secara menurun (descending)
    sort(karakter, karakter + n, greater<char>());

    cout << "\nUrutan karakter setelah descending sort: ";
    for (int i = 0; i < n; ++i) {
        cout << karakter[i] << " ";
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-03-20 090102](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/935ed45e-06de-442e-b17d-8ddf840b1ae9)

Program ini menggunakan fungsi sort dari library <algorithm> untuk mengurutkan karakter-karakter. Hasilnya akan dicetak dalam urutan menaik (ascending) dan menurun (descending).

## Kesimpulan
Algoritma sorting adalah algoritma yang digunakan untuk meletakkan kumpulan elemen data dalam urutan tertentu, berdasarkan beberapa kunci tertentu pada tiap-tiap elemen. Pengurutan bisa secara ascending atau descending. Macam-macam algoritma sorting adalah insertion sort, bubble sort, dan selection sort.

## Referensi
Karumanchi, N. (2016). Data Structures and algorithms made easy: Concepts, problems, Interview Questions. CareerMonk Publications.

TylerMSFT. (n.d.). Collections (C++/CX). diakses dari https://learn.microsoft.com/en-us/cpp/cppcx/collections-c-cx?view=msvc-170

