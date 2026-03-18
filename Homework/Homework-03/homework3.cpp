#include <iostream>
using namespace std;

// constexpr constant for PI
constexpr double PI = 3.141592653589793;

// constexpr functions for area calculations
constexpr double areaSquare(double length) {
    return length * length;
}

constexpr double areaRectangle(double height, double width) {
    return height * width;
}

constexpr double areaCircle(double radius) {
    return PI * radius * radius;
}

constexpr double areaCylinder(double radius, double height) {
    return 2 * PI * radius * (radius + height);
}

int main() {
    int choice;
    double height, width, length, radius;
    double area;

    cout << "1. Calculate the area of a square.\n";
    cout << "2. Calculate the area of a rectangle.\n";
    cout << "3. Calculate the area of a circle.\n";
    cout << "4. Calculate the area of a cylinder.\n";
    cout << "Please enter your choice (1-4): ";
    cin >> choice;

    switch (choice) {
        case 1: // Square
            cout << "Enter length: ";
            cin >> length;
            area = areaSquare(length);
            cout << "Total area: " << area << endl;
            break;

        case 2: // Rectangle
            cout << "Enter height: ";
            cin >> height;
            cout << "Enter width: ";
            cin >> width;
            area = areaRectangle(height, width);
            cout << "Total area: " << area << endl;
            break;

        case 3: // Circle
            cout << "Enter radius: ";
            cin >> radius;
            area = areaCircle(radius);
            cout << "Total area: " << area << endl;
            break;

        case 4: // Cylinder
            cout << "Enter radius: ";
            cin >> radius;
            cout << "Enter height: ";
            cin >> height;
            area = areaCylinder(radius, height);
            cout << "Total area: " << area << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}