#include <iostream>
#include <algorithm>

using namespace std;

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        return true;
    }
    return false;
}

int main() {
    string finalsDate, birthDate;
    cin >> finalsDate >> birthDate;

    int finalsYear = stoi(finalsDate.substr(6, 2));
    int birthYear = stoi(birthDate.substr(6, 2));

    if (finalsYear - birthYear < 18) {
        sort(birthDate.begin(), birthDate.end());
        if (isLeapYear(2000+finalsYear)) {
            swap(birthDate[0], birthDate[1]);
            swap(birthDate[3], birthDate[4]);
        } 
        if (stoi(birthDate.substr(6, 2)) + 100 <= 2000 + finalsYear) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "YES" << endl;
    }

    return 0;
}