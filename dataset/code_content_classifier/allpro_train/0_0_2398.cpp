#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    // Calculate the prefix sum
    vector<long long> prefixSum(n);
    prefixSum[0] = a[0];
    for(int i=1; i<n; i++) {
        prefixSum[i] = prefixSum[i-1] + a[i];
    }

    for(int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        long long result;
        if(l == 0) {
            result = prefixSum[r] % MOD;
        } else {
            result = (2 * prefixSum[r] - prefixSum[l-1]) % MOD;
        }

        if(result < 0) {
            result += MOD;
        }

        cout << result << endl;
    }

    return 0;
}