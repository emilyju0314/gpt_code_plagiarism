#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        long long ans = 1;
        for(int i = 1; i <= n; i++) {
            ans = (ans * 1LL * (4 * i - 2)) % MOD;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}