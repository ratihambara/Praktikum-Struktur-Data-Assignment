#include<iostream>
using namespace std;

// Mendefinisikan struct
struct Mahasiswa {
    string nama;
    int umur;
    double ipk;
};

// Mendefinisikan class
class Mobil {
private:
    string merk;
    int tahun;
public:
    Mobil(string m, int t) {
        merk = m;
        tahun = t;
    }
    void tampilkan() {
        cout << "Merk mobil : " << merk << ", Tahun: " << tahun << endl;
    }
};

int main() {
    // Membuat objek dari struct
    Mahasiswa mhs1;
    mhs1.nama = "Budi";
    mhs1.umur = 20;
    mhs1.ipk = 3.5;
    cout << "Nama: " << mhs1.nama << ", Umur: " << mhs1.umur << ", IPK: " << mhs1.ipk << endl;

    // Membuat objek dari class
    Mobil mobil1("Toyota", 2010);
    mobil1.tampilkan();

    return 0;
}
