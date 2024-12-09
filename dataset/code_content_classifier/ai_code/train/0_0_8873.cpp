#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    long long ans = 0;
    vector<long long> prefix(n, a[0]);
    vector<long long> suffix(n, a[n-1]);

    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] | a[i];
    }

    for(int i=n-2; i>=0; i--){
        suffix[i] = suffix[i+1] | a[i];
    }

    for(int i=0; i<n; i++){
        int k1 = pow(x, k);
        long long cur = a[i];
        cur *= k1;

        if(i > 0){
            cur |= prefix[i-1];
        }
        if(i < n-1){
            cur |= suffix[i+1];
        }

        ans = max(ans, cur);
    }

    cout << ans << endl;

    return 0;
}