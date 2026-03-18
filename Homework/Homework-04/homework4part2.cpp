#include <iostream>
#include <iomanip>
using namespace std;

// Check if a year is a leap year
bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

// Return number of days in a month
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: return 31;
        case 2: return isLeapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
    }
    return 30;
}

// Zeller’s Congruence to find day of week for any date
// Returns 0=Mon, 1=Tue, ..., 6=Sun
int getStartDay(int year, int month) {
    int d = 1; // first day of the month

    if (month < 3) {
        month += 12;
        year -= 1;
    }

    int K = year % 100;
    int J = year / 100;

    int h = (d + (13*(month + 1))/5 + K + K/4 + J/4 + 5*J) % 7;

    // Convert Zeller output to Monday=0
    return (h + 5) % 7;
}

int main() {
    int year, month;

    cout << "Enter a year: ";
    cin >> year;

    cout << "Enter a month (1-12): ";
    cin >> month;

    string monthNames[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int days = getDaysInMonth(month, year);
    int startDay = getStartDay(year, month);

    cout << "\n-- " << monthNames[month - 1] << " " << year << " --\n";
    cout << setw(6) << "Mon"
         << setw(6) << "Tue"
         << setw(6) << "Wed"
         << setw(6) << "Thu"
         << setw(6) << "Fri"
         << setw(6) << "Sat"
         << setw(6) << "Sun" << endl;

    // Print initial spaces
    for (int i = 0; i < startDay; i++) {
        cout << setw(6) << " ";
    }

    // Print days
    for (int day = 1; day <= days; day++) {
        cout << setw(6) << day;

        if ((startDay + day) % 7 == 0)
            cout << endl;
    }

    cout << endl;

    return 0;
}