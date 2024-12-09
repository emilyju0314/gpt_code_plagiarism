#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s, t;
    cin >> s >> t;

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = ans * 2 + (t[i] - s[i]);
    }

    cout << ans + 1 << endl;

    return 0;
}