#include <iostream>
#include <vector>
using namespace std;

const int mod = 998244353;

int main() {
    int n;
    cin >> n;
    
    vector<int> ans(n);
    for(int k = 1; k <= n; k++) {
        long long res = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i+1; j <= n; j++) {
                res = (res + max(i,j) - min(i,j) + 1) % mod;
            }
        }
        ans[k-1] = res;
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}