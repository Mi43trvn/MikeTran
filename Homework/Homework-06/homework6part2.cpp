#include <iostream>
using namespace std;

void findMatches(const int a[], int sizeA, const int b[], int sizeB) {
    cout << "Matching numbers: ";

    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (a[i] == b[j]) {
                cout << a[i] << " ";
            }
        }
    }

    cout << endl;
}

int main() {
    int data[]  {1, 3, 6, 7, 9};
    int data1[] {5, 3, 3, 11};

    int sizeData  = sizeof(data)  / sizeof(data[0]);
    int sizeData1 = sizeof(data1) / sizeof(data1[0]);

    findMatches(data, sizeData, data1, sizeData1);

    return 0;
}