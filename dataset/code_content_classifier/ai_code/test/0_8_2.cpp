#include <iostream>
#include <vector>
#include <map>

#define MOD 1000000007

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    if(k == 1) {
        // If k = 1, all segments are valid
        ans = (1LL * n * m * (m + 1)) / 2;
    } else {
        map<int, int> freq;
        vector<int> prefix_sum(n * m + 1, 0);
        long long sum = 0;

        for(int i=0; i<n * m; i++) {
            sum = (sum + a[i % n]) % k;
            prefix_sum[i + 1] = sum;
            freq[sum]++;
        }

        for(auto it : freq) {
            ans = (ans + 1LL * it.second * (it.second - 1) / 2) % MOD;
        }

        for(int i=0; i<n; i++) {
            map<int, int> freq_diff;
            sum = 0;
            freq[prefix_sum[i]]--;

            for(int j=0; j<m; j++) {
                sum = (sum + a[(i + j) % n]) % k;
                ans = (ans + freq[sum] + freq_diff[(k - sum) % k]) % MOD;
                freq_diff[sum]++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}