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
