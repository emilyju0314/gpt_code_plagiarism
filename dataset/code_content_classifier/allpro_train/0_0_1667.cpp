#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(2*n);
    for(int i=0; i<2*n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    
    long long ans = 0;
    for(int i=0; i<n; i++) {
        ans = (ans + a[2*i+1] - a[2*i]) % MOD;
    }

    long long result = (ans * n) % MOD;
    if(result < 0) result += MOD;

    cout << result << endl;

    return 0;
}