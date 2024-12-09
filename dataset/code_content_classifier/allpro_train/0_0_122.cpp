#include <iostream>
#include <string>

using namespace std;

bool isSubstringMatch(const string& a, const string& sub, int start) {
    for (int i = 0; i < sub.length(); i++) {
        if (a[start + i] != sub[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    string k = a;
    int i = 0;
    
    while (i < k.length()) {
        if (isSubstringMatch(k, b, i)) {
            for (int j = 0; j < b.length(); j++) {
                k[i + j] = b[j];
            }
            i += b.length();
        } else if (isSubstringMatch(k, c, i)) {
            for (int j = 0; j < c.length(); j++) {
                k[i + j] = c[j];
            }
            i += c.length();
        } else {
            i++;
        }
    }

    cout << k << endl;

    return 0;
}