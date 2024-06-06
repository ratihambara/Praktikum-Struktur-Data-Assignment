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