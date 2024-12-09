#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string s, string t) {
    int i = 0, j = 0;
    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            j++;
        }
        i++;
    }
    return j == t.length();
}

bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

int main() {
    string s, t;
    cin >> s >> t;

    if (isAnagram(s, t)) {
        cout << "automaton" << endl;
    } else if (isSubstring(s, t)) {
        cout << "array" << endl;
    } else {
        cout << "need tree" << endl;
    }

    return 0;
}