#include <iostream>
#include <string>

using namespace std;

int countPossibleIntegers(string s) {
    int count = 0;
    string num = "0123456789";

    // Replace _ with all possible digits
    if (s.find('_') != string::npos) {
        for (char c : num) {
            s[s.find('_')] = c;
            if (stoi(s) % 25 == 0 && s[0] != '0') {
                count++;
            }
        }
    } else {
        if (stoi(s) % 25 == 0 && s[0] != '0') {
            count++;
        }
    }

    // Replace X with all possible digits
    if (s.find('X') != string::npos) {
        for (char c : num) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == 'X') {
                    s[i] = c;
                }
            }
            if (stoi(s) % 25 == 0 && s[0] != '0') {
                count++;
            }
        }
    }

    return count;
}

int main() {
    string s;
    cin >> s;

    cout << countPossibleIntegers(s) << endl;

    return 0;
}