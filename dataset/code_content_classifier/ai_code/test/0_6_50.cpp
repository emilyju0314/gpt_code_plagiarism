#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long ans = 1;
    int prev = 0;
    for(int i = 0; i < n; i++) {
        int curr = min(a[i], a[i] - 1);
        ans = (ans * max(curr - prev, 0)) % MOD;
        prev = curr;
    }
    
    cout << ans << endl;
    
    return 0;
}