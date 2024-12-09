#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    bool hasCommon = false;
    vector<int> count(m, 0);

    for (char c : s) {
        int idx = c - 'a';
        if (count[idx] > 0) {
            hasCommon = true;
        }
        count[idx]++;
    }

    if (!hasCommon) {
        cout << 1 << endl;
        return 0;
    }

    long long ans = 1;
    for (int i = 0; i < n; ++i) {
        ans = ans * (m - count[s[i] - 'a']) % 1000000007;
    }

    for (int i = 0; i < n - 1; ++i) {
        ans = ans * m % 1000000007;
    }

    cout << ans << endl;

    return 0;
}