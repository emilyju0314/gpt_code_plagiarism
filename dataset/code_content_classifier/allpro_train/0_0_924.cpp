#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(string& s1, string& s2) {
    int diff = 0;
    pair<int, int> swapped_chars;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            diff++;
            if (diff == 1) {
                swapped_chars.first = i;
            } else if (diff == 2) {
                swapped_chars.second = i;
            } else {
                return false;
            }
        }
    }
    if (diff == 2 && s1[swapped_chars.first] == s2[swapped_chars.second] && s1[swapped_chars.second] == s2[swapped_chars.first]) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int k, n;
    cin >> k >> n;

    vector<string> strings(k);
    for (int i = 0; i < k; i++) {
        cin >> strings[i];
    }

    string s = strings[0];
    bool possible = true;
    for (int i = 1; i < k; i++) {
        if (!check(s, strings[i])) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << -1 << endl;
    } else {
        cout << s << endl;
    }

    return 0;
}