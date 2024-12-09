#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string s, string p) {
    for (int i = 0; i < s.length(); i++) {
        bool found = true;
        for (int j = 0; j < p.length(); j++) {
            if (s[(i+j) % s.length()] != p[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return true;
        }
    }
    return false;
}

int main() {
    string s, p;
    cin >> s >> p;

    if (isSubstring(s, p)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}