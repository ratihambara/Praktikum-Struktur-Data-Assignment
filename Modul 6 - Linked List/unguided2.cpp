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
