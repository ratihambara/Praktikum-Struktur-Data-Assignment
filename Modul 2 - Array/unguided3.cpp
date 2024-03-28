#include <iostream>

int main() {
    int numbers[10];
    int sum = 0;

    std::cout << "Masukkan 10 angka: ";
    for (int i = 0; i < 10; i++) {
        std::cin >> numbers[i];
        sum += numbers[i];
    }

    int max = numbers[0];
    int min = numbers[0];
    for (int i = 1; i < 10; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    double average = static_cast<double>(sum) / 10;

    std::cout << "Nilai Maksimum: " << max << "\n";
    std::cout << "Nilai Minimum: " << min << "\n";
    std::cout << "Nilai Rata-rata: " << average << "\n";

    return 0;
}
