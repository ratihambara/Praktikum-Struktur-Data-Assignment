#include <iostream>

int main() {
    int numbers[10];
    std::cout << "Masukkan 10 angka: ";
    for (int i = 0; i < 10; i++) {
        std::cin >> numbers[i];
    }

    std::cout << "Nomor Genap: ";
    for (int i = 0; i < 10; i++) {
        if (numbers[i] % 2 == 0) {
            std::cout << numbers[i] << " ";
        }
    }
    std::cout << "\n";

    std::cout << "Nomor Ganjil: ";
    for (int i = 0; i < 10; i++) {
        if (numbers[i] % 2 != 0) {
            std::cout << numbers[i] << " ";
        }
    }
    std::cout << "\n";

    return 0;
}
