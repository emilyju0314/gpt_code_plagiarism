#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

#define MOD 998244353
#define ll long long

int main() {
    int n;
    cin >> n;
    
    vector<string> strs(n);
    for(int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    
    ll xor_sum = 0;
    for(int mask = 0; mask < (1 << n); mask++) {
        ll result = 0;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                // Calculate the number of common subsequences of all strings
                ll cnt = 1;
                for(int j = 0; j < n; j++) {
                    if(mask & (1 << j)) {
                        cnt = (cnt * (strs[j].size() + 1)) % MOD;
                    }
                }
                result = (result + cnt) % MOD;
            }
        }
        result = (result * __builtin_popcount(mask)) % MOD;
        xor_sum ^= result;
    }
    
    cout << xor_sum << endl;
    
    return 0;
}