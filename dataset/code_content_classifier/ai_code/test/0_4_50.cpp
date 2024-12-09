#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long result = 1;

    for (int i = 0; i < n; i++) {
        int val = a[i] - i;
        if (val <= 0) {
            result = 0;
            break;
        }
        result = (result * val) % MOD;
    }

    cout << result << endl;

    return 0;
}