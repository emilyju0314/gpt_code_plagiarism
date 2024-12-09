#include <iostream>
#include <string>

using namespace std;

int countPossibleIntegers(string s) {
    int count = 0;
    
    if (s.find("25") != string::npos) {
        count++;
    }

    if (s.size() == 1 && s[0] == '0') {
        count++;
    }

    if (s.size() >= 2 && s[s.size() - 2] == '2' && s[s.size() - 1] == '5') {
        count++;
    }

    if (s.size() >= 3 && s[s.size() - 3] == '0' && s.substr(s.size() - 2) == "25") {
        count++;
    }

    if (s.size() >= 4 && s.substr(s.size() - 4) == "0025") {
        count++;
    }

    if (s.size() >= 5 && s.substr(s.size() - 5) == "00025") {
        count++;
    }

    if (s.find("_00") != string::npos) {
        count += 9;
    }

    if (s.find("_XX") != string::npos) {
        count += 9;
    }

    return count;
}

int main() {
    string s;
    cin >> s;

    cout << countPossibleIntegers(s) << endl;

    return 0;
}