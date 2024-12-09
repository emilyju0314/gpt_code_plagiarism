#include <iostream>
#include <string>
#define MOD 998244353

using namespace std;

int main() {
    string s;
    cin >> s;
    long long depth = 0, result = 0, openCount = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            openCount++;
        } else if (s[i] == ')') {
            if (openCount > 0) {
                openCount--;
                depth++;
            }
        } else {
            long long dp = openCount + 1;
            result += dp;
            depth += dp;
        }
    }

    result %= MOD;
    cout << result << endl;

    return 0;
}