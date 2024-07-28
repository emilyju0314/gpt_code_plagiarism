#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isSmaller(const string& s, int i, int j) {
    int n = s.length();
    for (int k = 0; k < n; ++k) {
        if (s[(i + k) % n] != s[(j + k) % n])
            return s[(i + k) % n] < s[(j + k) % n];
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        int minIndex = 0;
        for (int i = 1; i < n; ++i) {
            if (isSmaller(s, i, minIndex))
                minIndex = i;
        }
        for (int i = 0; i < n; ++i) {
            cout << s[(minIndex + i) % n];
        }
        cout << endl;
    }
    return 0;
}
