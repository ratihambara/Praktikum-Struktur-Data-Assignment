#include <iostream>
#include <string>

int hitungVokal(const std::string& kalimat) {
    int jumlahVokal = 0;
    for (char c : kalimat) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            jumlahVokal++;
        }
    }
    return jumlahVokal;
}

int main() {
    std::string kalimat;
    std::cout << "Masukkan kalimat: ";
    std::getline(std::cin, kalimat);

    int jumlahVokal = hitungVokal(kalimat);
    std::cout << "Jumlah huruf vokal dalam kalimat adalah: " << jumlahVokal << "\n";

    return 0;
}
