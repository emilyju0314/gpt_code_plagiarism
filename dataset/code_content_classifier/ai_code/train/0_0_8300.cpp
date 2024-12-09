#include <iostream>
using namespace std;

int main() {
    int year, month, day;
    
    while (cin >> year >> month >> day) {
        if (year < 1868 || (year == 1868 && (month < 9 || (month == 9 && day < 8)))) {
            cout << "pre-meiji" << endl;
        } else if (year >= 1868 && year < 1912) {
            cout << "meiji " << year - 1868 + 1 << " " << month << " " << day << endl;
        } else if (year == 1912 && (month < 7 || (month == 7 && day < 30))) {
            cout << "meiji " << year - 1868 << " " << month << " " << day << endl;
        } else if (year >= 1912 && year < 1926) {
            cout << "taisho " << year - 1912 + 1 << " " << month << " " << day << endl;
        } else if (year == 1926 && (month < 12 || (month == 12 && day < 25))) {
            cout << "taisho " << year - 1912 << " " << month << " " << day << endl;
        } else if (year >= 1926 && year < 1989) {
            cout << "showa " << year - 1926 + 1 << " " << month << " " << day << endl;
        } else if (year == 1989 && (month < 1 || (month == 1 && day < 8))) {
            cout << "showa " << year - 1926 << " " << month << " " << day << endl;
        } else {
            cout << "heisei " << year - 1989 + 1 << " " << month << " " << day << endl;
        }
    }
    
    return 0;
}