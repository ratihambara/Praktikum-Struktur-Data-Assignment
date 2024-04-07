#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Masukkan bilangan bulat n: ";
    cin >> n;

    char karakter[n];
    cout << "Masukkan " << n << " karakter: ";
    for (int i = 0; i < n; ++i) {
        cin >> karakter[i];
    }

    // Mengurutkan karakter secara menaik (ascending)
    sort(karakter, karakter + n);

    cout << "\nUrutan karakter setelah ascending sort: ";
    for (int i = 0; i < n; ++i) {
        cout << karakter[i] << " ";
    }

    // Mengurutkan karakter secara menurun (descending)
    sort(karakter, karakter + n, greater<char>());

    cout << "\nUrutan karakter setelah descending sort: ";
    for (int i = 0; i < n; ++i) {
        cout << karakter[i] << " ";
    }

    return 0;
}
