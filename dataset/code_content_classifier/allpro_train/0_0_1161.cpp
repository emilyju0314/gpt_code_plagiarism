#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isCharacterPresent(string s, char c) {
    for (char ch : s) {
        if (ch == c) {
            return true;
        }
    }
    return false;
}

int main() {
    string s, t;
    cin >> s >> t;

    vector<int> pos;
    for (int i = 0; i < t.length(); i++) {
        for (int j = 0; j < s.length(); j++) {
            if (t[i] == s[j]) {
                pos.push_back(j);
            }
        }
    }

    if (pos.size() < t.length()) {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 0; i < s.length(); i++) {
        if (!isCharacterPresent(pos, i)) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}