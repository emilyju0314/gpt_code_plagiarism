#include <iostream>
#include <vector>
#include <map>

#define MOD 1000000007

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    
    if(k == 1) {
        ans = (long long)n*m*(m+1)/2;
    } else {
        map<int, int> count;
        int sum = 0;

        count[0] = 1;

        for(int i = 0; i < n; i++) {
            sum += a[i];
            sum = (sum % k + k) % k; // to handle negative sums

            if(i >= m*n) {
                sum -= a[i-m*n];
                sum = (sum % k + k) % k; // to handle negative sums
            }

            ans += count[sum];
            count[sum]++;
        }
    }

    cout << ans % MOD << endl;

    return 0;
}