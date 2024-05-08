# Praktikum-Struktur-Data-Assignment
# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Ratih Ambara Sukma Kurnilia</p>

## Dasar Teori

Linked list dibagi menjadi 2 yaitu :

1) Single Linked List
   Merupakan suatu bentuk struktur data yang berisi kumpulan data, biasanya disebut node yang tersusun secara sambung menyambung, sekuensial, dinamis, dan terbatas. Setiap elemen dalam linked list dihubungkan ke elemen lain melalui pointer. Pointer adalah alamat elemen.  Dengan struktur seperti ini, linked list dibentuk dengan cara menunjuk pointer next suatu elemen ke elemen yang mengikutinya. Pointer next pada elemen terakhir merupakan NULL, yang menunjukkan akhir dari suatu list. Elemen pada awal suatu list disebut head dan elemen terakhir dari suatu list disebut tail.


2) Double Linked List
   Merupakan struktur data Linked List yang mirip dengan Single Linked List, namun dengan tambahan satu pointer tambahan pada setiap simpul yaitu pointer prev yang menunjuk ke simpul sebelumnya. Setiap simpul pada Double Linked List memiliki tiga elemen penting, yaitu elemen data (biasanya berupa nilai), pointer next yang menunjuk ke simpul berikutnya, dan pointer prev yang menunjuk ke simpul sebelumnya. Double Linked List memerlukan memori yang lebih besar.


## Guided 

### 1. Latihan Single Linked List

```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    //komponen/member
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}
//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}
//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
        while( nomor < posisi - 1 ){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    insertTengah(7,1);
    tampil();
    return 0;
}
```

### 2. Latihan Double Linked List

```C++
#include <iostream>
using namespace std;

class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```

## Unguided 

### 1. Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:

a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.


b. Hapus data Akechi

c. Tambahkan data berikut diantara John dan Jane : Futaba 18

d. Tambahkan data berikut diawal : Igor 20

e. Ubah data Michael menjadi : Reyn 18

f. Tampilkan seluruh data

```C++
#include <iostream>
#include <string>

struct Node {
    std::string name;
    int age;
    Node* next;
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(NULL) {}

    void insertFront(std::string name, int age) {
        Node* newNode = new Node();
        newNode->name = name;
        newNode->age = age;
        newNode->next = head;
        head = newNode;
    }

    void insertAfter(std::string target, std::string name, int age) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->name == target) {
                Node* newNode = new Node();
                newNode->name = name;
                newNode->age = age;
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
    }

    void deleteNode(std::string target) {
        Node* temp = head;
        Node* prev = NULL;

        if (temp != NULL && temp->name == target) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != NULL && temp->name != target) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;

        prev->next = temp->next;
        delete temp;
    }

    void display() {
        Node* node = head;
        while (node != NULL) {
            std::cout << node->name << " " << node->age << std::endl;
            node = node->next;
        }
    }
};

int main() {
    LinkedList list;

    std::string name;
    int age;

    while (true) {
        std::cout << "1. Tambah data" << std::endl;
        std::cout << "2. Hapus data" << std::endl;
        std::cout << "3. Tambah data setelah data tertentu" << std::endl;
        std::cout << "4. Tampilkan semua data" << std::endl;
        std::cout << "5. Keluar" << std::endl;
        std::cout << "Masukkan pilihan Anda: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Masukkan nama: ";
                std::cin >> name;
                std::cout << "Masukkan usia: ";
                std::cin >> age;
                list.insertFront(name, age);
                break;
            case 2:
                std::cout << "Masukkan nama yang ingin dihapus: ";
                std::cin >> name;
                list.deleteNode(name);
                break;
            case 3:
                std::string target;
                std::cout << "Masukkan nama setelah nama ini data akan ditambahkan: ";
                std::cin >> target;
                std::cout << "Masukkan nama: ";
                std::cin >> name;
                std::cout << "Masukkan usia: ";
                std::cin >> age;
                list.insertAfter(target, name, age);
                break;
            case 4:
                list.display();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Pilihan tidak valid" << std::endl;
                break;
        }
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-05-08 141031](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/fb43b706-609d-4328-84e5-2531c37414b6)
![Screenshot 2024-05-08 141118](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/59a33b5c-6387-402a-967e-eaa82de31d34)
![Screenshot 2024-05-08 141149](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/2d10d344-6022-4ca9-9096-2c469d07056a)
![Screenshot 2024-05-08 141211](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/a93e7940-97fe-473f-bfa6-aa8a32ea553b)
![Screenshot 2024-05-08 141245](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/17539370-15ff-4c9e-9886-08f3c6137f45)
![Screenshot 2024-05-08 141309](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/c437d5a4-84c2-4b57-8058-a0f3dc6c065c)
![Screenshot 2024-05-08 141333](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/b03dff18-b496-4750-b700-e86dab1e74d7)
![Screenshot 2024-05-08 141401](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/0127b6b5-b27e-450d-95ec-2c90c76d120a)
![Screenshot 2024-05-08 141422](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/61aab4b2-9449-4593-add6-3248f0d86f6b)

### 2. Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.

Case:
1. Tambahkan produk Azarine dengan harga 65000 diantara 
Somethinc dan Skintific
2. Hapus produk wardah
3. Update produk Hanasui menjadi Cleora dengan harga 55.000
4. Tampilkan menu seperti dibawah ini

Toko Skincare Purwokerto
1. Tambah Data
2. Hapus Data
3. Update Data
4. Tambah Data Urutan Tertentu
5. Hapus Data Urutan Tertentu
6. Hapus Seluruh Data
7. Tampilkan Data
8. Exit
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah 
ini :


```C++
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    int price;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(string name, int price) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->price = price;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }

    void insertAfter(string target, string name, int price) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->name == target) {
                Node* newNode = new Node;
                newNode->name = name;
                newNode->price = price;
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next != nullptr) {
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }

    void deleteNode(string target) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->name == target) {
                if (temp->prev != nullptr) {
                    temp->prev->next = temp->next;
                }
                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                }
                if (temp == head) {
                    head = temp->next;
                }
                if (temp == tail) {
                    tail = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    bool update(string oldName, string newName, int newPrice) {
        Node* current = head;
        while (current != nullptr) {
            if (current->name == oldName) {
                current->name = newName;
                current->price = newPrice;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << " " << current->price << endl;
            current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList list;
    list.push("Originote", 60000);
    list.push("Somethinc", 150000);
    list.push("Skintific", 100000);
    list.push("Wardah", 50000);
    list.push("Hanasui", 30000);

    while (true) {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        int choice;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string name;
                int price;
                cout << "Masukkan nama produk: ";
                cin >> name;
                cout << "Masukkan harga produk: ";
                cin >> price;
                list.push(name, price);
                break;
            }
            case 2: {
                string name;
                cout << "Masukkan nama produk yang akan dihapus: ";
                cin >> name;
                list.deleteNode(name);
                break;
            }
            case 3: {
                string oldName, newName;
                int newPrice;
                cout << "Masukkan nama produk yang akan diupdate: ";
                cin >> oldName;
                cout << "Masukkan nama produk baru: ";
                cin >> newName;
                cout << "Masukkan harga produk baru: ";
                cin >> newPrice;
                bool updated = list.update(oldName, newName, newPrice);
                if (!updated) {
                    cout << "Produk tidak ditemukan" << endl;
                }
                break;
            }
            case 4: {
                string target, name;
                int price;
                cout << "Masukkan nama produk setelah produk ini akan ditambahkan: ";
                cin >> target;
                cout << "Masukkan nama produk: ";
                cin >> name;
                cout << "Masukkan harga produk: ";
                cin >> price;
                list.insertAfter(target, name, price);
                break;
            }
            case 5: {
                string name;
                cout << "Masukkan nama produk yang akan dihapus: ";
                cin >> name;
                list.deleteNode(name);
                break;
            }
            case 6: {
                list.deleteAll();
                break;
            }
            case 7: {
                list.display();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        }
    }
    return 0;
}
```
#### Output:
![Screenshot 2024-05-08 141929](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/0c3d57a9-5d92-4556-8a16-809a263bc70d)
![Screenshot 2024-05-08 141950](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/f69d337b-df53-4a00-8adc-e7da3e7d5ccb)
![Screenshot 2024-05-08 142008](https://github.com/ratihambara/Praktikum-Struktur-Data-Assignment/assets/161399790/6fa75054-37c8-4dab-998c-b36932f6db12)

## Kesimpulan
Linked List terbagi menjadi 2 yaitu Single Linked List dan Double Linked List, setiap jenis Linked List tersebut memiliki kelebihan dan kekurangannya masing-masing.

## Referensi
Sjukani, Moh. 2007. Struktur Data (Algoritma & Struktur Data 2) dengan C, C++. Jakarta : Penerbit Mitra Wacana Media.

[TylerMSFT. (n.d.). Collections (C++/CX). diakses dari https://learn.microsoft.com/en-us/cpp/cppcx/collections-c-cx?view=msvc-170](https://copilot.microsoft.com/?FORM=undexpand&)

