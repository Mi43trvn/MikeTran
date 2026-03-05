#include <iostream>

int main() {
    int data[]  = {1, 3, 6, 7, 9};
    int data1[] = {5, 3, 3, 11};

    int size = 4; // only swap up to the smaller array's size

    for (int i = 0; i < size; i++) {
        int temp = data[i];
        data[i] = data1[i];
        data1[i] = temp;
    }

    // Print results
    std::cout << "data: ";
    for (int x : data) std::cout << x << " ";

    std::cout << "\ndata1: ";
    for (int x : data1) std::cout << x << " ";
}