#include <iostream>
#include <stdexcept>
using namespace std;

//---------------------------
// Division Function
//---------------------------
double divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw runtime_error("Division by zero is not allowed.");
    }
    return static_cast<double>(numerator) / denominator;
}

//---------------------------
// Array Access Function
//---------------------------
int accessArray(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds.");
    }
    return arr[index];
}

//---------------------------
// Custom Exception
//---------------------------
class CustomException : public exception {
public:
    const char* what() const noexcept override {
        return "Error in nestedFunction";
    }
};

//---------------------------
// Nested Exceptions
//---------------------------
void nestedFunction() {
    throw CustomException();
}

void outerFunction() {
    try {
        nestedFunction();
    }
    catch (const CustomException& e) {
        cout << "Caught exception in outerFunction: " << e.what() << endl;
        throw; // rethrow to main
    }
}

//---------------------------
// MAIN
//---------------------------
int main() {

    // Test nested exceptions
    try {
        outerFunction();
    }
    catch (const exception& e) {
        cout << "Caught rethrown exception in main: " << e.what() << endl;
    }

    // Division test
    int num, den;
    cout << "\nEnter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> den;

    try {
        cout << "Result: " << divide(num, den) << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Array access test
    int size, index;
    cout << "\nEnter array size: ";
    cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = i + 1;

    cout << "Enter index to access: ";
    cin >> index;

    try {
        cout << "Value: " << accessArray(arr, size, index) << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    delete[] arr;
    return 0;
}