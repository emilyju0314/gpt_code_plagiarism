#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int count = 0;

    // if s ends with 25
    if (s.size() >= 2 && s.substr(s.size()-2) == "25") {
        count++;
    }

    // check if we can get a valid number by replacing _ with any digit
    for (int i = 0; i <= 9; i++) {
        string temp = s;
        for (char &c : temp) {
            if (c == '_') {
                c = i + '0';
            }
        }
        if (temp.size() >= 2 && temp.substr(temp.size()-2) == "25") {
            count++;
        }
    }

    // check if we can get a valid number by replacing X with the same digit
    for (int i = 0; i <= 9; i++) {
        string temp = s;
        for (char &c : temp) {
            if (c == 'X') {
                c = i + '0';
            }
        }
        if (temp.size() >= 2 && temp.substr(temp.size()-2) == "25") {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}