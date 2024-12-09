#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i-1]) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != s[i-1] && (i == s.length()-1 || c != s[i+1])) {
                    s[i] = c;
                    break;
                }
            }
        }
    }

    cout << s << endl;

    return 0;
}