#include <iostream>
using namespace std;

void selectionSort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int pos_min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[pos_min]) {
                pos_min = j;
            }
        }
        if (pos_min != i) {
            swap(arr[i], arr[pos_min]);
        }
    }
}

void printIPS(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    double ips[] = {3.8, 2.9, 3.3, 4.0, 2.4};
    int n = sizeof(ips) / sizeof(ips[0]);

    cout << "IPS sebelum diurutkan: ";
    printIPS(ips, n);

    selectionSort(ips, n);

    cout << "IPS setelah diurutkan (dari terbesar hingga terkecil): ";
    printIPS(ips, n);

    return 0;
}
