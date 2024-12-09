#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, char> obfuscation;
    char current = 'a';

    for (char c : s) {
        if (obfuscation.find(c) == obfuscation.end()) {
            obfuscation[c] = current++;
        }
    }

    for (char c : s) {
        if (obfuscation[c] != 'a' && c != obfuscation[c]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}