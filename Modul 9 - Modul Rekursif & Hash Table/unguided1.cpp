#include <iostream>
using namespace std;

int hitungFactorial(int input) {
    if (input > 1)
        return input * hitungFactorial(input - 1);
    else
        return 1;
}

int main() {
    cout << "## Program C++ Hitung Faktorial ##" << endl;
    cout << "===================================" << endl;
    cout << endl;

    int angka;
    cout << "Input angka: ";
    cin >> angka;

    cout << angka << "! = " << hitungFactorial(angka);
    cout << endl;

    return 0;
}
