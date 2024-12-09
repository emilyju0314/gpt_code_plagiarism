#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string l, r;
    cin >> l >> r;

    int n = 0;

    for (int i = 0; i < l.length(); i++) {
        if (l[i] == '7' && r[i] == '4') {
            n += pow(2, l.length() - 1 - i);
        } else if (l[i] == '7' && r[i] == '7') {
            n += pow(2, l.length() - 1 - i);
        }
    }

    long long ans = (long long)n * (n - 1) / 2 % 1000000007;

    cout << ans << endl;

    return 0;
}