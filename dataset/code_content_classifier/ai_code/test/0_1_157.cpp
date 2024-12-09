#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 998244353

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> ones;
    long long ans = 1;

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') ones.push_back(i);
    }

    if(k == 0) {
        cout << 1 << endl;
    } else {
        for(int i = 1; i <= k; i++) {
            ans = (ans * (ones.size() - i)) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}