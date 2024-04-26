#include <algorithm>
#include <iostream>
#include <string>

bool binarySearch(const std::string& str, char x) {
    int l = 0, r = str.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (str[m] == x)
            return true;
        if (str[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return false;
}

int main() {
    std::string kalimat;
    char huruf;

    std::cout << "Masukkan kalimat: ";
    std::getline(std::cin, kalimat);

    std::cout << "Masukkan huruf yang dicari: ";
    std::cin >> huruf;

    std::sort(kalimat.begin(), kalimat.end());

    if(binarySearch(kalimat, huruf))
        std::cout << "Huruf " << huruf << " ditemukan dalam kalimat.\n";
    else
        std::cout << "Huruf " << huruf << " tidak ditemukan dalam kalimat.\n";

    return 0;
}
