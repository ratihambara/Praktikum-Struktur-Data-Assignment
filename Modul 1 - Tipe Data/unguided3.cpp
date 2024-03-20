#include<iostream>
#include<map>
using namespace std;

int main() {
    // Membuat map baru
    map<string, int> umur;

    // Menambahkan pasangan kunci-nilai ke dalam map
    umur["Ali"] = 20;
    umur["Budi"] = 25;
    umur["Citra"] = 22;

    // Mengakses nilai dalam map menggunakan kunci
    cout << "Umur Ali: " << umur["Ali"] << endl;
    cout << "Umur Budi: " << umur["Budi"] << endl;
    cout << "Umur Citra: " << umur["Citra"] << endl;

    return 0;
}
