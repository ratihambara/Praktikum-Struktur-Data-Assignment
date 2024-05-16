#include <iostream>
#include <stack>
#include <string>

bool cekPalindrom(const std::string& kalimat) {
    std::stack<char> s;
    for (char c : kalimat) {
        s.push(c);
    }

    for (char c : kalimat) {
        if (c != s.top()) {
            return false;
        }
        s.pop();
    }

    return true;
}

int main() {
    std::string kalimat;
    std::cout << "Masukkan kalimat: ";
    std::cin >> kalimat;

    if (cekPalindrom(kalimat)) {
        std::cout << "Kalimat tersebut adalah palindrom\n";
    } else {
        std::cout << "Kalimat tersebut adalah bukan palindrom\n";
    }

    return 0;
}
