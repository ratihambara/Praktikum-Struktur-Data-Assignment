#include <iostream>

int sequentialSearch(int data[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size = sizeof(data) / sizeof(data[0]);
    int target = 4;

    int jumlah = sequentialSearch(data, size, target);
    std::cout << "Data : 9, 4, 1, 4, 7, 10, 5, 4, 12, 4 " << "\n";
    std::cout << "Jumlah angka " << target << " dalam data adalah: " << jumlah << "\n";

    return 0;
}
