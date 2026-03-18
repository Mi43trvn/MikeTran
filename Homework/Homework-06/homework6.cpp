#include <iostream>
using namespace std;

int main() {
    int data[]  {1, 3, 6, 7, 9};
    int data1[] {5, 3, 3, 11};

    int sizeData  = sizeof(data)  / sizeof(data[0]);
    int sizeData1 = sizeof(data1) / sizeof(data1[0]);
    int minSize = (sizeData < sizeData1) ? sizeData : sizeData1;

    for (int i = 0; i < minSize; i++) {
        data[i]  ^= data1[i];
        data1[i] ^= data[i];
        data[i]  ^= data1[i];
    }

    cout << "data: ";
    for (int i = 0; i < sizeData; i++)
        cout << data[i] << " ";

    cout << "\ndata1: ";
    for (int i = 0; i < sizeData1; i++)
        cout << data1[i] << " ";

    return 0;
}