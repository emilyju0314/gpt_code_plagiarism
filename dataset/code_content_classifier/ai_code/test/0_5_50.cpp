#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 1;
    sort(a.begin(), a.end());
    
    for(int i = 0; i < n; i++) {
        int val = a[i] - i;
        if(val <= 0) {
            ans = 0;
            break;
        }
        ans = (ans * val) % MOD;
    }

    cout << ans << endl;

    return 0;
}