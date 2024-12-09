#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    string s;
    cin >> s;

    bool possible = false;
    string result = s;

    for (int i = 0; i < n - p; i++) {
        if (s[i] != s[i + p]) {
            possible = true;
            if (s[i] == '.' && s[i + p] == '.') {
                result[i] = '0';
                result[i + p] = '1';
            } else if (s[i] == '.') {
                result[i] = (s[i + p] == '0') ? '1' : '0';
            } else if (s[i + p] == '.') {
                result[i + p] = (s[i] == '0') ? '1' : '0';
            }
        }
    }

    if (possible) {
        cout << result << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}