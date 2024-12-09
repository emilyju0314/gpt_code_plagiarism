#include <iostream>
#include <string>
using namespace std;

string findStringWithMinPeriod(string t) {
    int n = t.length();
    string s;

    if (t[0] == '0') {
        s = "0";
    } else {
        s = "1";
    }

    for (int i = 1; i < n; i++) {
        if (t[i] != t[i-1]) {
            s += "1";
        }
        s += "0";
    }

    return s;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string t;
        cin >> t;

        string s = findStringWithMinPeriod(t);
        cout << s << endl;
    }

    return 0;
}