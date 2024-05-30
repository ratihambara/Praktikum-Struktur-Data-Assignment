# Praktikum-Struktur-Data-Assignment
# <h1 align="center">Laporan Praktikum Modul Priority Queue & Heaps</h1>
<p align="center">Ratih Ambara Sukma Kurnilia</p>

## Dasar Teori

Priority Queue adalah jenis queue yang mengatur elemen berdasarkan nilai prioritasnya. Elemen dengan nilai prioritas lebih tinggi umumnya akan diambil sebelum elemen dengan nilai prioritas lebih rendah. Dalam priority queue, setiap elemen memiliki nilai prioritas yang terkait dengannya. Ketika menambahkan elemen ke antrian, elemen tersebut dimasukkan ke dalam posisi berdasarkan nilai prioritasnya.

Heap dalam struktur data adalah struktur berbasis pohon biner (binary tree) dengan aturan tertentu. Heap memiliki beberapa ciri khas yang membedakannya dari pohon binary biasa, yaitu:
1) Complete Binary Tree 
   Setiap levelnya terisi penuh kecuali level paling bawah.
2) Order Property
   Dibagi menjadi 2 jenis yaitu max heap dan min heap.
3) Max-heap
   pada setiap node, nilai orang tua (parent) harus lebih besar atau sama dengan nilai anaknya (children).
4) Min-heap
   pada setiap node, nilai orang tua harus lebih kecil atau sama dengan nilai anaknya.

Heap memiliki kelebihan dalam hal kecepatan operasi. Menambah atau menghapus elemen dalam heap hanya membutuhkan waktu O(log N), sedangkan mencari elemen minimum/maksimum hanya membutuhkan waktu konstan O(1).

## Guided 

```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }

}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);
    
    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "Node with maximum priority : " << extractMax()
<< "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

remove(3);
std::cout << "Priority queue after removing the element : ";
for (int i = 0; i <= heapSize; ++i) {
    std::cout << H[i] << " ";
    }
    return 0;
}
```

## Unguided 

### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user.

```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    int n;
    std::cout << "Masukkan jumlah elemen: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cout << "Masukkan elemen ke-" << (i+1) << ": ";
        std::cin >> x;
        insert(x);
    }
    
    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "Node with maximum priority : " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    int idx, p;
    std::cout << "Masukkan indeks dan prioritas baru: ";
    std::cin >> idx >> p;
    changePriority(idx, p);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Masukkan indeks elemen yang akan dihapus: ";
    std::cin >> idx;
    remove(idx);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
```
#### Output:
![Screenshot 2024-05-21 095545](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/21183d48-af94-4416-9479-03d1a86f6463) 

Kode ini meminta user untuk memasukkan jumlah elemen dan nilai dari setiap elemen yang ingin dimasukkan ke dalam heap. User juga diminta untuk memasukkan indeks dan prioritas baru untuk operasi changePriority, serta indeks elemen yang ingin dihapus untuk operasi remove.

## Kesimpulan
Priority Queue adalah jenis queue yang mengatur elemen berdasarkan nilai prioritasnya. Elemen dengan nilai prioritas lebih tinggi umumnya akan diambil sebelum elemen dengan nilai prioritas lebih rendah. Dalam priority queue, setiap elemen memiliki nilai prioritas yang terkait dengannya. Ketika menambahkan elemen ke antrian, elemen tersebut dimasukkan ke dalam posisi berdasarkan nilai prioritasnya.

Heap dalam struktur data adalah struktur berbasis pohon biner (binary tree) dengan aturan tertentu. Heap memiliki kelebihan dalam hal kecepatan operasi. Menambah atau menghapus elemen dalam heap hanya membutuhkan waktu O(log N), sedangkan mencari elemen minimum/maksimum hanya membutuhkan waktu konstan O(1).

## Referensi
GeeksforGeeks. (2024, Mei 12). Priority Queue - Set 1: Introduction. https://www.geeksforgeeks.org/priority-queue-set-1-introduction/.

Programiz. (n.d.). Heap Data Structure. https://www.programiz.com/dsa/heap-data-structure.

[TylerMSFT. (n.d.). Collections (C++/CX). diakses dari https://learn.microsoft.com/en-us/cpp/cppcx/collections-c-cx?view=msvc-170](https://copilot.microsoft.com/?FORM=undexpand&)

