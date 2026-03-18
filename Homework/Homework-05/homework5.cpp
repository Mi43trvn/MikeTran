#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int vowel_count = 0;

    cout << "Enter a message: ";
    getline(cin, input);

    // Convert string to char array-like access
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        // Check vowels (uppercase + lowercase)
        if (c == 'a' || c == 'A' ||
            c == 'e' || c == 'E' ||
            c == 'i' || c == 'I' ||
            c == 'o' || c == 'O' ||
            c == 'u' || c == 'U') 
        {
            vowel_count++;
        }
    }

    cout << "Total vowels: " << vowel_count << endl;

    return 0;
}