#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    string t(n, '0');

    int last = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            last = i;
        }
    }

    for (int i = 0; i <= last; i++) {
        t[i] = '1';
    }

    cout << t << endl;

    return 0;
}