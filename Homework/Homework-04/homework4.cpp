#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to create a random map size inside the 20x20 boundary
void createRandomMap(int &minX, int &maxX, int &minY, int &maxY) {
    // Full map is from -10 to +10
    // Random sub-map inside that range
    minX = -10 + (rand() % 6);   // -10 to -5
    maxX =  5 + (rand() % 6);    // 5 to 10
    minY = -10 + (rand() % 6);
    maxY =  5 + (rand() % 6);
}

// Function to check if a point is inside the map
bool isValidLocation(int x, int y, int minX, int maxX, int minY, int maxY) {
    if (x >= minX && x <= maxX && y >= minY && y <= maxY)
        return true;
    else
        return false;
}

int main() {
    srand(time(0));

    string name;
    int x, y;
    int minX, maxX, minY, maxY;

    // Create the random map
    createRandomMap(minX, maxX, minY, maxY);

    // Ask user for info
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your location (x y): ";
    cin >> x >> y;

    // Display map boundaries
    cout << "\nRandom map boundaries:\n";
    cout << "X range: " << minX << " to " << maxX << endl;
    cout << "Y range: " << minY << " to " << maxY << endl;

    // Check if location is valid
    if (isValidLocation(x, y, minX, maxX, minY, maxY)) {
        cout << "\nHello " << name << "! Your location (" << x << ", " << y 
             << ") is inside the map.\n";
    } else {
        cout << "\nHello " << name << ". Your location (" << x << ", " << y 
             << ") is OUTSIDE the map.\n";
    }

    return 0;
}