# Praktikum-Struktur-Data-Assignment
# <h1 align="center">Laporan Praktikum Modul Graph & Tree</h1>
<p align="center">Ratih Ambara Sukma Kurnilia</p>

## Dasar Teori
Graf atau graph adalah struktur data yang digunakan untuk merepresentasikan hubungan antara objek dalam bentuk node dan sambungan antara node tersebut dalam bentuk sisi. Graf terdiri dari simpul dan busur yang secara matematis dinyatakan sebagai :

G = (V, E)

G adalah Graph, V adalah simpul dan E sebagai sisi

Jenis-jenis graph:
1) Graph berarah (directed graph): Urutan simpul mempunyai arti. Misal busur AB adalah e1 sedangkan busur BA adalah e8.
2) Graph tak berarah (undirected graph): Urutan simpul dalam sebuah busur tidak diperhatikan. Misal busur e1 dapat disebut busur AB atau BA.
3) Weight Graph : Graph yang mempunyai nilai pada tiap edgenya.

Tree atau Pohon adalah struktur data yang sangat umum dan kuat yang menyerupai nyata pohon. Terdiri dari satu set node yang terurut dalam grafik yang terhubung, dimana setiap node memiliki paling banyak satu simpul induk, dan nol atau lebih simpul anak dengan urutan tertentu. Struktur data tree digunakan untuk menyimpan data-data hirarki seperti pohon keluarga, skema pertandingan, struktur organisasi.

Operasi pada tree:
1) Create
2) Clear
3) isEmpty
4) Insert
5) Find
6) Update
7) Retrive
8) Delete Sub
9) Characteristic
10) Traverse, terdiri dari 3 metode:Pre-Order (root - kiri - kanan), In-Order (kiri - root - kanan), Post-Order (kiri - kanan - root)
    
## Guided 

### 1. Graph

```C++
#include <iostream>
#include <iomanip> // corrected from <iomanip>
using namespace std;

string simpul[7] = {"Ciamis",
                    "Bandung",
                    "Bekasi",
                    "Tasikmalaya",
                    "Cianjur",
                    "Purwokerto",
                    "Yogyakarta"};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 9, 15, 0},
    {0, 5, 0, 9, 5, 0, 0},
    {0, 0, 0, 2, 4, 0, 8},
    {3, 0, 0, 1, 0, 0, 0},
    {0, 0, 7, 0, 0, 9, 4},
    {0, 0, 0, 0, 8, 0, 0}
};

void tampilGraph() {
    for (int baris =0; baris < 7; baris++) {
        cout << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0)
                cout << " -> " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```

### 2. Tree

```C++
#include <iostream>
using namespace std;

// Sefinisi struktur pohon
struct pohon {
    pohon* kanan;
    char data;
    pohon* kiri;
};

// Deklarasi variabel global
pohon* simpul;
pohon* root;
pohon* saatIni;
pohon* helperA;
pohon* helperB;
pohon* alamat[256];

// Fungsi untuk inisialisasi root
void inisialisasi() {
    root = NULL;
}

// Fungsi untuk membuat simpul baru
void simpulBaru(char dataMasukkan) {
    simpul = new pohon;
    simpul ->data = dataMasukkan;
    simpul ->kanan = NULL;
    simpul ->kiri = NULL;
}

// Fungsi membuat simpul akar
void simpulAkar() {
    if (root == NULL) {
        char dataAnda;
        cout << "Silahkan masukkan data: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Root terbentuk..." << endl;
    } else {
        cout << "Root sudah ada..." << endl;
    }
}

// Fungsi untuk menambah simpul
void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 && j < 256) {
            cout << "Masukkan data kiri: ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni ->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                cout << "Masukkan data kanan: ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    saatIni ->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}

// Fungsi untuk membaca pohon
void bacaPohon() {
    if (root != NULL) {
        int i = 1, n = 1, pencacah = 0;
        cout << endl;
        while (alamat[i] != NULL) {
            saatIni = alamat[i];
            cout << saatIni ->data << " ";
            pencacah++;
            if (pencacah == n) {
                cout << endl;
                pencacah = 0;
                n = n * 2;
            }
            i++;
        }
    
    }
}

// Fungsi utama
int main() {
    inisialisasi();
    simpulAkar();
    tambahSimpul();
    bacaPohon();
    return 0;
}
```

## Unguided 

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    int jumlahSimpul;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    vector<string> simpul_RatihAmbara2311110037(jumlahSimpul);
    cout << "Silakan masukkan nama simpul: " << endl;
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> simpul_RatihAmbara2311110037[i];
    }

    vector<vector<int>> bobot(jumlahSimpul, vector<int>(jumlahSimpul));
    cout << "Silakan masukkan bobot antar simpul:" << endl;
    for (int i = 0; i < jumlahSimpul; ++i) {
        for (int j = 0; j < jumlahSimpul; ++j) {
            cout << simpul_RatihAmbara2311110037[i] << " --> " << simpul[j] << " = ";
            cin >> bobot[i][j];
        }
    }

    cout << "Output:" << endl;
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << simpul_RatihAmbara2311110037[i] << ": ";
        for (int j = 0; j < jumlahSimpul; ++j) {
            if (j > 0) {
                cout << ", ";
            }
            cout << simpul_RatihAmbara2311110037[j] << " = " << bobot[i][j];
        }
        cout << endl;
    }

    cout << "Process returned 0 (0x0) execution time: 11.763. press any key to continue..." << endl;

    return 0;
}
```
#### Output:
![Screenshot 2024-06-06 111246](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/b4f65e76-d72d-457e-b048-9f538cf42765)

### 2.   Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan tampilkan pada pre-order, inorder, dan post order!

```C++
#include <iostream>
using namespace std;

// Definisi struktur pohon
struct Node {
    char data;
    Node* left;
    Node* right;
};

// Fungsi untuk membuat simpul baru
Node* createNode(char data) {
    Node* newNode_RatihAmbara_2311110037 = new Node;
    newNode_RatihAmbara_2311110037->data = data;
    newNode_RatihAmbara_2311110037->left = nullptr;
    newNode_RatihAmbara_2311110037->right = nullptr;
    return newNode_RatihAmbara_2311110037;
}

// Fungsi untuk menambah simpul ke pohon
Node* insertNode(Node* root, char data) {
    if (root == nullptr) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Tampilan pre-order
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Tampilan in-order
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Tampilan post-order
void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;
    char data;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah simpul\n";
        cout << "2. Pre-order traversal\n";
        cout << "3. In-order traversal\n";
        cout << "4. Post-order traversal\n";
        cout << "0. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                root = insertNode(root, data);
                break;
            case 2:
                cout << "Pre-order traversal: ";
                preOrder(root);
                cout << endl;
                break;
            case 3:
                cout << "In-order traversal: ";
                inOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "Post-order traversal: ";
                postOrder(root);
                cout << endl;
                break;
            case 0:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 0);

    return 0;
}
```
#### Output:
![Screenshot 2024-06-06 112537](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/3ea10ae6-d486-4a1a-b832-99d2906d80e2)
![Screenshot 2024-06-06 112749](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/4628d803-e730-4784-be5f-55db15b5cb02)

## Kesimpulan
Graf atau graph adalah struktur data yang digunakan untuk merepresentasikan hubungan antara objek dalam bentuk node dan sambungan antara node tersebut dalam bentuk sisi. Tree atau Pohon adalah struktur data yang sangat umum dan kuat yang menyerupai nyata pohon. 

## Referensi
Sjukani, Moh. 2007. Struktur Data (Algoritma & Struktur Data 2) dengan C, C++. Jakarta : Penerbit Mitra Wacana Media.

[TylerMSFT. (n.d.). Collections (C++/CX). diakses dari https://learn.microsoft.com/en-us/cpp/cppcx/collections-c-cx?view=msvc-170](https://copilot.microsoft.com/?FORM=undexpand&)

