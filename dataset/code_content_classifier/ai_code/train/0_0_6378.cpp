#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<char> alphabet(26, ' ');

    int index = 0;
    for (int i = 0; i < s.length(); i++) {
        if (index == 26) {
            break;
        }
        if (s[i] <= alphabet[index]) {
            continue;
        }
        while (index < 26 && s[i] > alphabet[index]) {
            alphabet[index++] = s[i];
        }
    }

    if (index == 26) {
        for (char c : alphabet) {
            cout << c;
        }
    } else {
        cout << "-1";
    }

    return 0;
}