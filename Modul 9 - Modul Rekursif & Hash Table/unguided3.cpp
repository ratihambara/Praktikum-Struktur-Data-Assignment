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