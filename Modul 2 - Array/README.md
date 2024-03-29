# Praktikum-Struktur-Data-Assignment
# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Ratih Ambara Sukma Kurnilia</p>

## Dasar Teori

Array adalah struktur data yang paling dasar. Beberapa jenis array yang akan dipelajari, yaitu:
1) Array Satu Dimensi
   Adalah tipe variabel yang terdiri dari kumpulan data dengan tipe yang sama yang disusun dalam satu baris atau satu dimensi.
   Contoh tipe array satu dimensi adalah bilangan bulat {1, 2, 3, 4, 5} memiliki 5 elemen dan 4 indeks (indeks dimulai dari 0)
   
2) Array Dua Dimensi
   adalah variable yang terdiri dari kumpulan array satu dimensi dengan tipe yang sama yang disusun dalam baris dan kolom. Dalam array dua dimensi, setiap elemen memiliki dua indeks, yaitu indeks baris dan indeks kolom.
   
3) Array Multidimensi
   memiliki kesamaan dengan array satu dimensi dan dua dimensi, namun memiliki kapasitas memori yang lebih besar. Biasa digunakan untuk array yang memiliki lebih dari dua indeks, seperti array 3 dimensi, array 4 dimensi, array 5 dimensi, dan seterusnya.

4) Array Empat Dimensi

5) Array Lima Dimensi

## Guided 

### 1. Program Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr[2] [3] [3];
    // Input elemen
    for (int x =0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x <<"] [" << y <<"] [" << z <<"] = ";
                cin >> arr [x] [y] [z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x <<"] [" << y <<"] [" << z <<"] = " << arr [x] [y] [z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x =0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr [x] [y] [z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```

### 2. Program Mencari Nilai Maksimal Pada Array

```C++
#include <iostream>
using namespace std;

int main() {
    int maks, a, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;

    if(a <= 0) {
        cout << "Panjang array harus lebih besar dari 0." << endl;
        return 1; // Return 1 to indicate error
    }

    int array[a];
    cout << "Masukkan " << a << " angka\n";

    for (int i = 0; i < a; i++) {
        cout << "Array ke-" << (i + 1) << ": ";
        cin >> array[i];
    }

    maks = array[0];
    lokasi = 0;

    for(int i = 1; i < a; i++) {
        if (array[i] > maks) {
            maks = array[i];
            lokasi = i;
        }
    }

    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << (lokasi + 1) << endl;

    return 0; // Return 0 to indicate successful execution
}
```

## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
![Screenshot 2024-03-28 111759](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/aaf11a9e-f0ef-4d68-bcc3-d260cd58af52)

```C++
#include <iostream>

int main() {
    int numbers[10];
    std::cout << "Masukkan 10 angka: ";
    for (int i = 0; i < 10; i++) {
        std::cin >> numbers[i];
    }

    std::cout << "Nomor Genap: ";
    for (int i = 0; i < 10; i++) {
        if (numbers[i] % 2 == 0) {
            std::cout << numbers[i] << " ";
        }
    }
    std::cout << "\n";

    std::cout << "Nomor Ganjil: ";
    for (int i = 0; i < 10; i++) {
        if (numbers[i] % 2 != 0) {
            std::cout << numbers[i] << " ";
        }
    }
    std::cout << "\n";

    return 0;
}
```
#### Output:
![Screenshot 2024-03-28 103359](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/bf60541c-cd08-4881-8cc4-6f3898d22a58)

Program ini meminta pengguna untuk memasukkan 10 angka, dan kemudian langsung memisahkan angka tersebut menjadi angka genap dan ganjil.

### 2.  Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cout << "Masukkan ukuran array (x y z): ";
    cin >> x >> y >> z;

    int ***arr = new int**[x];
    for (int i = 0; i < x; i++) {
        arr[i] = new int*[y];
        for (int j = 0; j < y; j++) {
            arr[i][j] = new int[z];
        }
    }

    // Input elemen
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "Input Array[" << i << "][" << j << "][" << k << "] = ";
                cin >> arr[i][j][k];
            }
        }
        cout << endl;
    }

    // Output Array
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "Data Array[" << i << "][" << j << "][" << k << "] = " << arr[i][j][k] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Delete array
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
```
#### Output:
![Screenshot 2024-03-28 104235](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/6e53ee3b-2b3d-4456-af45-1a5c1c7b1fbe)

Program ini meminta pengguna untuk memasukkan ukuran array tiga dimensi dan elemen-elemennya, lalu mencetak elemen-elemen tersebut.

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
#include <iostream>

int main() {
    int numbers[10];
    int sum = 0;

    std::cout << "Masukkan 10 angka: ";
    for (int i = 0; i < 10; i++) {
        std::cin >> numbers[i];
        sum += numbers[i];
    }

    int max = numbers[0];
    int min = numbers[0];
    for (int i = 1; i < 10; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    double average = static_cast<double>(sum) / 10;

    std::cout << "Nilai Maksimum: " << max << "\n";
    std::cout << "Nilai Minimum: " << min << "\n";
    std::cout << "Nilai Rata-rata: " << average << "\n";

    return 0;
}
```
#### Output:
![Screenshot 2024-03-28 104635](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/df65acec-a379-48b9-b938-e613c8d0b352)

Program ini akan meminta pengguna untuk memasukkan 10 angka. Setelah itu, program akan mencetak nilai maksimum, minimum, dan rata-rata dari angka-angka tersebut.

## Kesimpulan
Array adalah struktur data yang paling dasar. Beberapa jenis array yang akan dipelajari, yaitu: array 1 dimensi, array 2 dimensi, array multidimensi, array 4 dimensi, dan array 5 dimensi.

## Referensi
(1) github.com. https://github.com/behnamasadi/cpp_tutorials/tree/398680095b976321c4ec26b0af4aa476ea7eb925/src%2Farrays.cpp.
