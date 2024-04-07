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
